#pragma once

#include <bv/ColorMap.h>
#include <bv/truncate.h>

#include <cstdint>
#include <vector>

namespace bv {

// maps density data to image data. It does so continously, so we don't have to iterate
// the whole density map each time we want to extract the image.
class DensityToImage
{
public:
    DensityToImage(size_t width, size_t height, size_t max_included_value, ColorMap const& colormap)
        : m_colormap(colormap),
          m_width(width),
          m_height(height),
          // initialize with background color
          m_rgb(3 * width * height, 0),
          // calculates the factor so that max_value is the last integer value that mapps to 255.
          m_fact(256.0 / std::log(max_included_value + 1)),
          m_max_included_value(max_included_value)
    {
    }

    void update(size_t pixel_idx, size_t density)
    {
        if (0 == density) {
            m_rgb[pixel_idx * 3] = 0;
            m_rgb[pixel_idx * 3 + 1] = 0;
            m_rgb[pixel_idx * 3 + 2] = 0;
        } else if (density >= m_max_included_value) {
            m_colormap.write_rgb(255, &m_rgb[pixel_idx * 3]);
        } else {
            auto log = std::log(density);
            log *= m_fact;
            auto log_int = static_cast<int>(log);
            uint8_t const* rgb = m_colormap.rgb(log_int);
            std::copy(rgb, rgb + 3, m_rgb.data() + pixel_idx * 3);
            //std::memcpy(m_rgb.data() + pixel_idx * 3, rgb, 3);
            //m_rgb[pixel_idx * 3] = rgb[0];
            //m_rgb[pixel_idx * 3+1] = rgb[1];
            //m_rgb[pixel_idx * 3+2] = rgb[2];
        }
    }

    void rgb(size_t pixel_idx, uint8_t const* rgb_data)
    {
        m_rgb[pixel_idx * 3] = rgb_data[0];
        m_rgb[pixel_idx * 3 + 1] = rgb_data[1];
        m_rgb[pixel_idx * 3 + 2] = rgb_data[2];
    }

    uint8_t* rgb(size_t pixel_idx)
    {
        return m_rgb.data() + (pixel_idx * 3);
    }

    char const* data() const
    {
        return reinterpret_cast<char const*>(m_rgb.data());
    }

    // size in bytes
    size_t size() const
    {
        return m_rgb.size();
    }

private:
    friend std::ostream& operator<<(std::ostream&, DensityToImage const&);

    ColorMap const m_colormap;
    size_t const m_width;
    size_t const m_height;
    std::vector<uint8_t> m_rgb;
    double const m_fact;
    size_t const m_max_included_value;
};

std::ostream& operator<<(std::ostream& os, DensityToImage const& dti)
{
    os.write(reinterpret_cast<const char*>(dti.m_rgb.data()), dti.m_rgb.size());
    return os;
}


} // namespace bv