#pragma once

#include <array>
#include <exception>
#include <initializer_list>
#include <vector>

namespace bv {

// Maps an uint8_t to a color.
class ColorMap
{
public:
    ColorMap(std::initializer_list<double> rgb_colors)
        : m_rgb(rgb_colors.size())
    {
        if (rgb_colors.size() != m_rgb.size()) {
            throw std::runtime_error("ColorMap: needs 3*256 double values");
        }

        // convert all colors from range [0, 1( to [0, 256(
        auto it = rgb_colors.begin();
        for (size_t i = 0; i < rgb_colors.size(); ++i) {
            if (*it >= 1 || *it < 0) {
                throw std::runtime_error("ColorMap: input outside of range [0, 1(");
            }
            m_rgb[i] = static_cast<uint8_t>(256 * *it++);
        }
    }

    uint8_t const* rgb(int value) const
    {
        return m_rgb.data() + (value * 3);
    }

    void write_rgb(int value, uint8_t* target) const
    {
        int idx = value * 3;
        target[0] = m_rgb[idx];
        target[1] = m_rgb[idx + 1];
        target[2] = m_rgb[idx + 2];
    }

    // More info: https://bids.github.io/colormap/
    // source of this file : https://github.com/BIDS/colormap/blob/master/colormaps.py
    // study shows that viridis is awesome : http: //idl.cs.washington.edu/files/2018-QuantitativeColor-CHI.pdf
    static ColorMap viridis()
    {
        return {
            0.267004, 0.004874, 0.329415,
            0.268510, 0.009605, 0.335427,
            0.269944, 0.014625, 0.341379,
            0.271305, 0.019942, 0.347269,
            0.272594, 0.025563, 0.353093,
            0.273809, 0.031497, 0.358853,
            0.274952, 0.037752, 0.364543,
            0.276022, 0.044167, 0.370164,
            0.277018, 0.050344, 0.375715,
            0.277941, 0.056324, 0.381191,
            0.278791, 0.062145, 0.386592,
            0.279566, 0.067836, 0.391917,
            0.280267, 0.073417, 0.397163,
            0.280894, 0.078907, 0.402329,
            0.281446, 0.084320, 0.407414,
            0.281924, 0.089666, 0.412415,
            0.282327, 0.094955, 0.417331,
            0.282656, 0.100196, 0.422160,
            0.282910, 0.105393, 0.426902,
            0.283091, 0.110553, 0.431554,
            0.283197, 0.115680, 0.436115,
            0.283229, 0.120777, 0.440584,
            0.283187, 0.125848, 0.444960,
            0.283072, 0.130895, 0.449241,
            0.282884, 0.135920, 0.453427,
            0.282623, 0.140926, 0.457517,
            0.282290, 0.145912, 0.461510,
            0.281887, 0.150881, 0.465405,
            0.281412, 0.155834, 0.469201,
            0.280868, 0.160771, 0.472899,
            0.280255, 0.165693, 0.476498,
            0.279574, 0.170599, 0.479997,
            0.278826, 0.175490, 0.483397,
            0.278012, 0.180367, 0.486697,
            0.277134, 0.185228, 0.489898,
            0.276194, 0.190074, 0.493001,
            0.275191, 0.194905, 0.496005,
            0.274128, 0.199721, 0.498911,
            0.273006, 0.204520, 0.501721,
            0.271828, 0.209303, 0.504434,
            0.270595, 0.214069, 0.507052,
            0.269308, 0.218818, 0.509577,
            0.267968, 0.223549, 0.512008,
            0.266580, 0.228262, 0.514349,
            0.265145, 0.232956, 0.516599,
            0.263663, 0.237631, 0.518762,
            0.262138, 0.242286, 0.520837,
            0.260571, 0.246922, 0.522828,
            0.258965, 0.251537, 0.524736,
            0.257322, 0.256130, 0.526563,
            0.255645, 0.260703, 0.528312,
            0.253935, 0.265254, 0.529983,
            0.252194, 0.269783, 0.531579,
            0.250425, 0.274290, 0.533103,
            0.248629, 0.278775, 0.534556,
            0.246811, 0.283237, 0.535941,
            0.244972, 0.287675, 0.537260,
            0.243113, 0.292092, 0.538516,
            0.241237, 0.296485, 0.539709,
            0.239346, 0.300855, 0.540844,
            0.237441, 0.305202, 0.541921,
            0.235526, 0.309527, 0.542944,
            0.233603, 0.313828, 0.543914,
            0.231674, 0.318106, 0.544834,
            0.229739, 0.322361, 0.545706,
            0.227802, 0.326594, 0.546532,
            0.225863, 0.330805, 0.547314,
            0.223925, 0.334994, 0.548053,
            0.221989, 0.339161, 0.548752,
            0.220057, 0.343307, 0.549413,
            0.218130, 0.347432, 0.550038,
            0.216210, 0.351535, 0.550627,
            0.214298, 0.355619, 0.551184,
            0.212395, 0.359683, 0.551710,
            0.210503, 0.363727, 0.552206,
            0.208623, 0.367752, 0.552675,
            0.206756, 0.371758, 0.553117,
            0.204903, 0.375746, 0.553533,
            0.203063, 0.379716, 0.553925,
            0.201239, 0.383670, 0.554294,
            0.199430, 0.387607, 0.554642,
            0.197636, 0.391528, 0.554969,
            0.195860, 0.395433, 0.555276,
            0.194100, 0.399323, 0.555565,
            0.192357, 0.403199, 0.555836,
            0.190631, 0.407061, 0.556089,
            0.188923, 0.410910, 0.556326,
            0.187231, 0.414746, 0.556547,
            0.185556, 0.418570, 0.556753,
            0.183898, 0.422383, 0.556944,
            0.182256, 0.426184, 0.557120,
            0.180629, 0.429975, 0.557282,
            0.179019, 0.433756, 0.557430,
            0.177423, 0.437527, 0.557565,
            0.175841, 0.441290, 0.557685,
            0.174274, 0.445044, 0.557792,
            0.172719, 0.448791, 0.557885,
            0.171176, 0.452530, 0.557965,
            0.169646, 0.456262, 0.558030,
            0.168126, 0.459988, 0.558082,
            0.166617, 0.463708, 0.558119,
            0.165117, 0.467423, 0.558141,
            0.163625, 0.471133, 0.558148,
            0.162142, 0.474838, 0.558140,
            0.160665, 0.478540, 0.558115,
            0.159194, 0.482237, 0.558073,
            0.157729, 0.485932, 0.558013,
            0.156270, 0.489624, 0.557936,
            0.154815, 0.493313, 0.557840,
            0.153364, 0.497000, 0.557724,
            0.151918, 0.500685, 0.557587,
            0.150476, 0.504369, 0.557430,
            0.149039, 0.508051, 0.557250,
            0.147607, 0.511733, 0.557049,
            0.146180, 0.515413, 0.556823,
            0.144759, 0.519093, 0.556572,
            0.143343, 0.522773, 0.556295,
            0.141935, 0.526453, 0.555991,
            0.140536, 0.530132, 0.555659,
            0.139147, 0.533812, 0.555298,
            0.137770, 0.537492, 0.554906,
            0.136408, 0.541173, 0.554483,
            0.135066, 0.544853, 0.554029,
            0.133743, 0.548535, 0.553541,
            0.132444, 0.552216, 0.553018,
            0.131172, 0.555899, 0.552459,
            0.129933, 0.559582, 0.551864,
            0.128729, 0.563265, 0.551229,
            0.127568, 0.566949, 0.550556,
            0.126453, 0.570633, 0.549841,
            0.125394, 0.574318, 0.549086,
            0.124395, 0.578002, 0.548287,
            0.123463, 0.581687, 0.547445,
            0.122606, 0.585371, 0.546557,
            0.121831, 0.589055, 0.545623,
            0.121148, 0.592739, 0.544641,
            0.120565, 0.596422, 0.543611,
            0.120092, 0.600104, 0.542530,
            0.119738, 0.603785, 0.541400,
            0.119512, 0.607464, 0.540218,
            0.119423, 0.611141, 0.538982,
            0.119483, 0.614817, 0.537692,
            0.119699, 0.618490, 0.536347,
            0.120081, 0.622161, 0.534946,
            0.120638, 0.625828, 0.533488,
            0.121380, 0.629492, 0.531973,
            0.122312, 0.633153, 0.530398,
            0.123444, 0.636809, 0.528763,
            0.124780, 0.640461, 0.527068,
            0.126326, 0.644107, 0.525311,
            0.128087, 0.647749, 0.523491,
            0.130067, 0.651384, 0.521608,
            0.132268, 0.655014, 0.519661,
            0.134692, 0.658636, 0.517649,
            0.137339, 0.662252, 0.515571,
            0.140210, 0.665859, 0.513427,
            0.143303, 0.669459, 0.511215,
            0.146616, 0.673050, 0.508936,
            0.150148, 0.676631, 0.506589,
            0.153894, 0.680203, 0.504172,
            0.157851, 0.683765, 0.501686,
            0.162016, 0.687316, 0.499129,
            0.166383, 0.690856, 0.496502,
            0.170948, 0.694384, 0.493803,
            0.175707, 0.697900, 0.491033,
            0.180653, 0.701402, 0.488189,
            0.185783, 0.704891, 0.485273,
            0.191090, 0.708366, 0.482284,
            0.196571, 0.711827, 0.479221,
            0.202219, 0.715272, 0.476084,
            0.208030, 0.718701, 0.472873,
            0.214000, 0.722114, 0.469588,
            0.220124, 0.725509, 0.466226,
            0.226397, 0.728888, 0.462789,
            0.232815, 0.732247, 0.459277,
            0.239374, 0.735588, 0.455688,
            0.246070, 0.738910, 0.452024,
            0.252899, 0.742211, 0.448284,
            0.259857, 0.745492, 0.444467,
            0.266941, 0.748751, 0.440573,
            0.274149, 0.751988, 0.436601,
            0.281477, 0.755203, 0.432552,
            0.288921, 0.758394, 0.428426,
            0.296479, 0.761561, 0.424223,
            0.304148, 0.764704, 0.419943,
            0.311925, 0.767822, 0.415586,
            0.319809, 0.770914, 0.411152,
            0.327796, 0.773980, 0.406640,
            0.335885, 0.777018, 0.402049,
            0.344074, 0.780029, 0.397381,
            0.352360, 0.783011, 0.392636,
            0.360741, 0.785964, 0.387814,
            0.369214, 0.788888, 0.382914,
            0.377779, 0.791781, 0.377939,
            0.386433, 0.794644, 0.372886,
            0.395174, 0.797475, 0.367757,
            0.404001, 0.800275, 0.362552,
            0.412913, 0.803041, 0.357269,
            0.421908, 0.805774, 0.351910,
            0.430983, 0.808473, 0.346476,
            0.440137, 0.811138, 0.340967,
            0.449368, 0.813768, 0.335384,
            0.458674, 0.816363, 0.329727,
            0.468053, 0.818921, 0.323998,
            0.477504, 0.821444, 0.318195,
            0.487026, 0.823929, 0.312321,
            0.496615, 0.826376, 0.306377,
            0.506271, 0.828786, 0.300362,
            0.515992, 0.831158, 0.294279,
            0.525776, 0.833491, 0.288127,
            0.535621, 0.835785, 0.281908,
            0.545524, 0.838039, 0.275626,
            0.555484, 0.840254, 0.269281,
            0.565498, 0.842430, 0.262877,
            0.575563, 0.844566, 0.256415,
            0.585678, 0.846661, 0.249897,
            0.595839, 0.848717, 0.243329,
            0.606045, 0.850733, 0.236712,
            0.616293, 0.852709, 0.230052,
            0.626579, 0.854645, 0.223353,
            0.636902, 0.856542, 0.216620,
            0.647257, 0.858400, 0.209861,
            0.657642, 0.860219, 0.203082,
            0.668054, 0.861999, 0.196293,
            0.678489, 0.863742, 0.189503,
            0.688944, 0.865448, 0.182725,
            0.699415, 0.867117, 0.175971,
            0.709898, 0.868751, 0.169257,
            0.720391, 0.870350, 0.162603,
            0.730889, 0.871916, 0.156029,
            0.741388, 0.873449, 0.149561,
            0.751884, 0.874951, 0.143228,
            0.762373, 0.876424, 0.137064,
            0.772852, 0.877868, 0.131109,
            0.783315, 0.879285, 0.125405,
            0.793760, 0.880678, 0.120005,
            0.804182, 0.882046, 0.114965,
            0.814576, 0.883393, 0.110347,
            0.824940, 0.884720, 0.106217,
            0.835270, 0.886029, 0.102646,
            0.845561, 0.887322, 0.099702,
            0.855810, 0.888601, 0.097452,
            0.866013, 0.889868, 0.095953,
            0.876168, 0.891125, 0.095250,
            0.886271, 0.892374, 0.095374,
            0.896320, 0.893616, 0.096335,
            0.906311, 0.894855, 0.098125,
            0.916242, 0.896091, 0.100717,
            0.926106, 0.897330, 0.104071,
            0.935904, 0.898570, 0.108131,
            0.945636, 0.899815, 0.112838,
            0.955300, 0.901065, 0.118128,
            0.964894, 0.902323, 0.123941,
            0.974417, 0.903590, 0.130215,
            0.983868, 0.904867, 0.136897,
            0.993248, 0.906157, 0.143936};
    }

    static ColorMap magma()
    {
        return {
            0.001462, 0.000466, 0.013866,
            0.002258, 0.001295, 0.018331,
            0.003279, 0.002305, 0.023708,
            0.004512, 0.003490, 0.029965,
            0.005950, 0.004843, 0.037130,
            0.007588, 0.006356, 0.044973,
            0.009426, 0.008022, 0.052844,
            0.011465, 0.009828, 0.060750,
            0.013708, 0.011771, 0.068667,
            0.016156, 0.013840, 0.076603,
            0.018815, 0.016026, 0.084584,
            0.021692, 0.018320, 0.092610,
            0.024792, 0.020715, 0.100676,
            0.028123, 0.023201, 0.108787,
            0.031696, 0.025765, 0.116965,
            0.035520, 0.028397, 0.125209,
            0.039608, 0.031090, 0.133515,
            0.043830, 0.033830, 0.141886,
            0.048062, 0.036607, 0.150327,
            0.052320, 0.039407, 0.158841,
            0.056615, 0.042160, 0.167446,
            0.060949, 0.044794, 0.176129,
            0.065330, 0.047318, 0.184892,
            0.069764, 0.049726, 0.193735,
            0.074257, 0.052017, 0.202660,
            0.078815, 0.054184, 0.211667,
            0.083446, 0.056225, 0.220755,
            0.088155, 0.058133, 0.229922,
            0.092949, 0.059904, 0.239164,
            0.097833, 0.061531, 0.248477,
            0.102815, 0.063010, 0.257854,
            0.107899, 0.064335, 0.267289,
            0.113094, 0.065492, 0.276784,
            0.118405, 0.066479, 0.286321,
            0.123833, 0.067295, 0.295879,
            0.129380, 0.067935, 0.305443,
            0.135053, 0.068391, 0.315000,
            0.140858, 0.068654, 0.324538,
            0.146785, 0.068738, 0.334011,
            0.152839, 0.068637, 0.343404,
            0.159018, 0.068354, 0.352688,
            0.165308, 0.067911, 0.361816,
            0.171713, 0.067305, 0.370771,
            0.178212, 0.066576, 0.379497,
            0.184801, 0.065732, 0.387973,
            0.191460, 0.064818, 0.396152,
            0.198177, 0.063862, 0.404009,
            0.204935, 0.062907, 0.411514,
            0.211718, 0.061992, 0.418647,
            0.218512, 0.061158, 0.425392,
            0.225302, 0.060445, 0.431742,
            0.232077, 0.059889, 0.437695,
            0.238826, 0.059517, 0.443256,
            0.245543, 0.059352, 0.448436,
            0.252220, 0.059415, 0.453248,
            0.258857, 0.059706, 0.457710,
            0.265447, 0.060237, 0.461840,
            0.271994, 0.060994, 0.465660,
            0.278493, 0.061978, 0.469190,
            0.284951, 0.063168, 0.472451,
            0.291366, 0.064553, 0.475462,
            0.297740, 0.066117, 0.478243,
            0.304081, 0.067835, 0.480812,
            0.310382, 0.069702, 0.483186,
            0.316654, 0.071690, 0.485380,
            0.322899, 0.073782, 0.487408,
            0.329114, 0.075972, 0.489287,
            0.335308, 0.078236, 0.491024,
            0.341482, 0.080564, 0.492631,
            0.347636, 0.082946, 0.494121,
            0.353773, 0.085373, 0.495501,
            0.359898, 0.087831, 0.496778,
            0.366012, 0.090314, 0.497960,
            0.372116, 0.092816, 0.499053,
            0.378211, 0.095332, 0.500067,
            0.384299, 0.097855, 0.501002,
            0.390384, 0.100379, 0.501864,
            0.396467, 0.102902, 0.502658,
            0.402548, 0.105420, 0.503386,
            0.408629, 0.107930, 0.504052,
            0.414709, 0.110431, 0.504662,
            0.420791, 0.112920, 0.505215,
            0.426877, 0.115395, 0.505714,
            0.432967, 0.117855, 0.506160,
            0.439062, 0.120298, 0.506555,
            0.445163, 0.122724, 0.506901,
            0.451271, 0.125132, 0.507198,
            0.457386, 0.127522, 0.507448,
            0.463508, 0.129893, 0.507652,
            0.469640, 0.132245, 0.507809,
            0.475780, 0.134577, 0.507921,
            0.481929, 0.136891, 0.507989,
            0.488088, 0.139186, 0.508011,
            0.494258, 0.141462, 0.507988,
            0.500438, 0.143719, 0.507920,
            0.506629, 0.145958, 0.507806,
            0.512831, 0.148179, 0.507648,
            0.519045, 0.150383, 0.507443,
            0.525270, 0.152569, 0.507192,
            0.531507, 0.154739, 0.506895,
            0.537755, 0.156894, 0.506551,
            0.544015, 0.159033, 0.506159,
            0.550287, 0.161158, 0.505719,
            0.556571, 0.163269, 0.505230,
            0.562866, 0.165368, 0.504692,
            0.569172, 0.167454, 0.504105,
            0.575490, 0.169530, 0.503466,
            0.581819, 0.171596, 0.502777,
            0.588158, 0.173652, 0.502035,
            0.594508, 0.175701, 0.501241,
            0.600868, 0.177743, 0.500394,
            0.607238, 0.179779, 0.499492,
            0.613617, 0.181811, 0.498536,
            0.620005, 0.183840, 0.497524,
            0.626401, 0.185867, 0.496456,
            0.632805, 0.187893, 0.495332,
            0.639216, 0.189921, 0.494150,
            0.645633, 0.191952, 0.492910,
            0.652056, 0.193986, 0.491611,
            0.658483, 0.196027, 0.490253,
            0.664915, 0.198075, 0.488836,
            0.671349, 0.200133, 0.487358,
            0.677786, 0.202203, 0.485819,
            0.684224, 0.204286, 0.484219,
            0.690661, 0.206384, 0.482558,
            0.697098, 0.208501, 0.480835,
            0.703532, 0.210638, 0.479049,
            0.709962, 0.212797, 0.477201,
            0.716387, 0.214982, 0.475290,
            0.722805, 0.217194, 0.473316,
            0.729216, 0.219437, 0.471279,
            0.735616, 0.221713, 0.469180,
            0.742004, 0.224025, 0.467018,
            0.748378, 0.226377, 0.464794,
            0.754737, 0.228772, 0.462509,
            0.761077, 0.231214, 0.460162,
            0.767398, 0.233705, 0.457755,
            0.773695, 0.236249, 0.455289,
            0.779968, 0.238851, 0.452765,
            0.786212, 0.241514, 0.450184,
            0.792427, 0.244242, 0.447543,
            0.798608, 0.247040, 0.444848,
            0.804752, 0.249911, 0.442102,
            0.810855, 0.252861, 0.439305,
            0.816914, 0.255895, 0.436461,
            0.822926, 0.259016, 0.433573,
            0.828886, 0.262229, 0.430644,
            0.834791, 0.265540, 0.427671,
            0.840636, 0.268953, 0.424666,
            0.846416, 0.272473, 0.421631,
            0.852126, 0.276106, 0.418573,
            0.857763, 0.279857, 0.415496,
            0.863320, 0.283729, 0.412403,
            0.868793, 0.287728, 0.409303,
            0.874176, 0.291859, 0.406205,
            0.879464, 0.296125, 0.403118,
            0.884651, 0.300530, 0.400047,
            0.889731, 0.305079, 0.397002,
            0.894700, 0.309773, 0.393995,
            0.899552, 0.314616, 0.391037,
            0.904281, 0.319610, 0.388137,
            0.908884, 0.324755, 0.385308,
            0.913354, 0.330052, 0.382563,
            0.917689, 0.335500, 0.379915,
            0.921884, 0.341098, 0.377376,
            0.925937, 0.346844, 0.374959,
            0.929845, 0.352734, 0.372677,
            0.933606, 0.358764, 0.370541,
            0.937221, 0.364929, 0.368567,
            0.940687, 0.371224, 0.366762,
            0.944006, 0.377643, 0.365136,
            0.947180, 0.384178, 0.363701,
            0.950210, 0.390820, 0.362468,
            0.953099, 0.397563, 0.361438,
            0.955849, 0.404400, 0.360619,
            0.958464, 0.411324, 0.360014,
            0.960949, 0.418323, 0.359630,
            0.963310, 0.425390, 0.359469,
            0.965549, 0.432519, 0.359529,
            0.967671, 0.439703, 0.359810,
            0.969680, 0.446936, 0.360311,
            0.971582, 0.454210, 0.361030,
            0.973381, 0.461520, 0.361965,
            0.975082, 0.468861, 0.363111,
            0.976690, 0.476226, 0.364466,
            0.978210, 0.483612, 0.366025,
            0.979645, 0.491014, 0.367783,
            0.981000, 0.498428, 0.369734,
            0.982279, 0.505851, 0.371874,
            0.983485, 0.513280, 0.374198,
            0.984622, 0.520713, 0.376698,
            0.985693, 0.528148, 0.379371,
            0.986700, 0.535582, 0.382210,
            0.987646, 0.543015, 0.385210,
            0.988533, 0.550446, 0.388365,
            0.989363, 0.557873, 0.391671,
            0.990138, 0.565296, 0.395122,
            0.990871, 0.572706, 0.398714,
            0.991558, 0.580107, 0.402441,
            0.992196, 0.587502, 0.406299,
            0.992785, 0.594891, 0.410283,
            0.993326, 0.602275, 0.414390,
            0.993834, 0.609644, 0.418613,
            0.994309, 0.616999, 0.422950,
            0.994738, 0.624350, 0.427397,
            0.995122, 0.631696, 0.431951,
            0.995480, 0.639027, 0.436607,
            0.995810, 0.646344, 0.441361,
            0.996096, 0.653659, 0.446213,
            0.996341, 0.660969, 0.451160,
            0.996580, 0.668256, 0.456192,
            0.996775, 0.675541, 0.461314,
            0.996925, 0.682828, 0.466526,
            0.997077, 0.690088, 0.471811,
            0.997186, 0.697349, 0.477182,
            0.997254, 0.704611, 0.482635,
            0.997325, 0.711848, 0.488154,
            0.997351, 0.719089, 0.493755,
            0.997351, 0.726324, 0.499428,
            0.997341, 0.733545, 0.505167,
            0.997285, 0.740772, 0.510983,
            0.997228, 0.747981, 0.516859,
            0.997138, 0.755190, 0.522806,
            0.997019, 0.762398, 0.528821,
            0.996898, 0.769591, 0.534892,
            0.996727, 0.776795, 0.541039,
            0.996571, 0.783977, 0.547233,
            0.996369, 0.791167, 0.553499,
            0.996162, 0.798348, 0.559820,
            0.995932, 0.805527, 0.566202,
            0.995680, 0.812706, 0.572645,
            0.995424, 0.819875, 0.579140,
            0.995131, 0.827052, 0.585701,
            0.994851, 0.834213, 0.592307,
            0.994524, 0.841387, 0.598983,
            0.994222, 0.848540, 0.605696,
            0.993866, 0.855711, 0.612482,
            0.993545, 0.862859, 0.619299,
            0.993170, 0.870024, 0.626189,
            0.992831, 0.877168, 0.633109,
            0.992440, 0.884330, 0.640099,
            0.992089, 0.891470, 0.647116,
            0.991688, 0.898627, 0.654202,
            0.991332, 0.905763, 0.661309,
            0.990930, 0.912915, 0.668481,
            0.990570, 0.920049, 0.675675,
            0.990175, 0.927196, 0.682926,
            0.989815, 0.934329, 0.690198,
            0.989434, 0.941470, 0.697519,
            0.989077, 0.948604, 0.704863,
            0.988717, 0.955742, 0.712242,
            0.988367, 0.962878, 0.719649,
            0.988033, 0.970012, 0.727077,
            0.987691, 0.977154, 0.734536,
            0.987387, 0.984288, 0.742002,
            0.987053, 0.991438, 0.749504};
    }

    // colorspacious from https://stackoverflow.com/a/50860105/48181
    static ColorMap spacious()
    {
        return {
            0.91510904, 0.55114749, 0.67037311,
            0.91696411, 0.55081563, 0.66264366,
            0.91870995, 0.55055664, 0.65485881,
            0.92034498, 0.55037149, 0.64702356,
            0.92186763, 0.55026107, 0.63914306,
            0.92327636, 0.55022625, 0.63122259,
            0.9245696, 0.55026781, 0.62326754,
            0.92574582, 0.5503865, 0.6152834,
            0.92680349, 0.55058299, 0.6072758,
            0.92774112, 0.55085789, 0.59925045,
            0.9285572, 0.55121174, 0.59121319,
            0.92925027, 0.551645, 0.58316992,
            0.92981889, 0.55215808, 0.57512667,
            0.93026165, 0.55275127, 0.56708953,
            0.93057716, 0.5534248, 0.55906469,
            0.93076407, 0.55417883, 0.55105838,
            0.93082107, 0.55501339, 0.54307696,
            0.93074689, 0.55592845, 0.53512681,
            0.9305403, 0.55692387, 0.52721438,
            0.93020012, 0.55799943, 0.51934621,
            0.92972523, 0.55915477, 0.51152885,
            0.92911454, 0.56038948, 0.50376893,
            0.92836703, 0.56170301, 0.49607312,
            0.92748175, 0.56309471, 0.48844813,
            0.9264578, 0.56456383, 0.48090073,
            0.92529434, 0.56610951, 0.47343769,
            0.92399062, 0.56773078, 0.46606586,
            0.92254595, 0.56942656, 0.45879209,
            0.92095971, 0.57119566, 0.4516233,
            0.91923137, 0.5730368, 0.44456642,
            0.91736048, 0.57494856, 0.4376284,
            0.91534665, 0.57692945, 0.43081625,
            0.91318962, 0.57897785, 0.42413698,
            0.91088917, 0.58109205, 0.41759765,
            0.90844521, 0.58327024, 0.41120533,
            0.90585771, 0.58551053, 0.40496711,
            0.90312676, 0.5878109, 0.3988901,
            0.90025252, 0.59016928, 0.39298143,
            0.89723527, 0.5925835, 0.38724821,
            0.89407538, 0.59505131, 0.38169756,
            0.89077331, 0.59757038, 0.37633658,
            0.88732963, 0.60013832, 0.37117234,
            0.88374501, 0.60275266, 0.36621186,
            0.88002022, 0.6054109, 0.36146209,
            0.87615612, 0.60811044, 0.35692989,
            0.87215369, 0.61084868, 0.352622,
            0.86801401, 0.61362295, 0.34854502,
            0.86373824, 0.61643054, 0.34470535,
            0.85932766, 0.61926872, 0.3411092,
            0.85478365, 0.62213474, 0.3377625,
            0.85010767, 0.6250258, 0.33467091,
            0.84530131, 0.62793914, 0.3318397,
            0.84036623, 0.63087193, 0.32927381,
            0.8353042, 0.63382139, 0.32697771,
            0.83011708, 0.63678472, 0.32495541,
            0.82480682, 0.63975913, 0.32321038,
            0.81937548, 0.64274185, 0.32174556,
            0.81382519, 0.64573011, 0.32056327,
            0.80815818, 0.6487212, 0.31966522,
            0.80237677, 0.65171241, 0.31905244,
            0.79648336, 0.65470106, 0.31872531,
            0.79048044, 0.65768455, 0.31868352,
            0.78437059, 0.66066026, 0.31892606,
            0.77815645, 0.66362567, 0.31945124,
            0.77184076, 0.66657827, 0.32025669,
            0.76542634, 0.66951562, 0.3213394,
            0.75891609, 0.67243534, 0.32269572,
            0.75231298, 0.67533509, 0.32432138,
            0.74562004, 0.6782126, 0.32621159,
            0.73884042, 0.68106567, 0.32836102,
            0.73197731, 0.68389214, 0.33076388,
            0.72503398, 0.68668995, 0.33341395,
            0.7180138, 0.68945708, 0.33630465,
            0.71092018, 0.69219158, 0.33942908,
            0.70375663, 0.69489159, 0.34278007,
            0.69652673, 0.69755529, 0.34635023,
            0.68923414, 0.70018097, 0.35013201,
            0.6818826, 0.70276695, 0.35411772,
            0.67447591, 0.70531165, 0.3582996,
            0.667018, 0.70781354, 0.36266984,
            0.65951284, 0.71027119, 0.36722061,
            0.65196451, 0.71268322, 0.37194411,
            0.64437719, 0.71504832, 0.37683259,
            0.63675512, 0.71736525, 0.38187838,
            0.62910269, 0.71963286, 0.38707389,
            0.62142435, 0.72185004, 0.39241165,
            0.61372469, 0.72401576, 0.39788432,
            0.60600841, 0.72612907, 0.40348469,
            0.59828032, 0.72818906, 0.40920573,
            0.59054536, 0.73019489, 0.41504052,
            0.58280863, 0.73214581, 0.42098233,
            0.57507535, 0.7340411, 0.42702461,
            0.5673509, 0.7358801, 0.43316094,
            0.55964082, 0.73766224, 0.43938511,
            0.55195081, 0.73938697, 0.44569104,
            0.54428677, 0.74105381, 0.45207286,
            0.53665478, 0.74266235, 0.45852483,
            0.52906111, 0.74421221, 0.4650414,
            0.52151225, 0.74570306, 0.47161718,
            0.5140149, 0.74713464, 0.47824691,
            0.506576, 0.74850672, 0.48492552,
            0.49920271, 0.74981912, 0.49164808,
            0.49190247, 0.75107171, 0.4984098,
            0.48468293, 0.75226438, 0.50520604,
            0.47755205, 0.7533971, 0.51203229,
            0.47051802, 0.75446984, 0.5188842,
            0.46358932, 0.75548263, 0.52575752,
            0.45677469, 0.75643553, 0.53264815,
            0.45008317, 0.75732863, 0.5395521,
            0.44352403, 0.75816207, 0.54646551,
            0.43710682, 0.758936, 0.55338462,
            0.43084133, 0.7596506, 0.56030581,
            0.42473758, 0.76030611, 0.56722555,
            0.41880579, 0.76090275, 0.5741404,
            0.41305637, 0.76144081, 0.58104704,
            0.40749984, 0.76192057, 0.58794226,
            0.40214685, 0.76234235, 0.59482292,
            0.39700806, 0.7627065, 0.60168598,
            0.39209414, 0.76301337, 0.6085285,
            0.38741566, 0.76326334, 0.6153476,
            0.38298304, 0.76345681, 0.62214052,
            0.37880647, 0.7635942, 0.62890454,
            0.37489579, 0.76367593, 0.63563704,
            0.37126045, 0.76370246, 0.64233547,
            0.36790936, 0.76367425, 0.64899736,
            0.36485083, 0.76359176, 0.6556203,
            0.36209245, 0.76345549, 0.66220193,
            0.359641, 0.76326594, 0.66873999,
            0.35750235, 0.76302361, 0.67523226,
            0.35568141, 0.76272903, 0.68167659,
            0.35418202, 0.76238272, 0.68807086,
            0.3530069, 0.76198523, 0.69441305,
            0.35215761, 0.7615371, 0.70070115,
            0.35163454, 0.76103888, 0.70693324,
            0.35143685, 0.76049114, 0.71310742,
            0.35156253, 0.75989444, 0.71922184,
            0.35200839, 0.75924936, 0.72527472,
            0.3527701, 0.75855647, 0.73126429,
            0.3538423, 0.75781637, 0.73718884,
            0.3552186, 0.75702964, 0.7430467,
            0.35689171, 0.75619688, 0.74883624,
            0.35885353, 0.75531868, 0.75455584,
            0.36109522, 0.75439565, 0.76020396,
            0.36360734, 0.75342839, 0.76577905,
            0.36637995, 0.75241752, 0.77127961,
            0.3694027, 0.75136364, 0.77670417,
            0.37266493, 0.75026738, 0.7820513,
            0.37615579, 0.74912934, 0.78731957,
            0.37986429, 0.74795017, 0.79250759,
            0.38377944, 0.74673047, 0.797614,
            0.38789026, 0.74547088, 0.80263746,
            0.3921859, 0.74417203, 0.80757663,
            0.39665568, 0.74283455, 0.81243022,
            0.40128912, 0.74145908, 0.81719695,
            0.406076, 0.74004626, 0.82187554,
            0.41100641, 0.73859673, 0.82646476,
            0.41607073, 0.73711114, 0.83096336,
            0.4212597, 0.73559013, 0.83537014,
            0.42656439, 0.73403435, 0.83968388,
            0.43197625, 0.73244447, 0.8439034,
            0.43748708, 0.73082114, 0.84802751,
            0.44308905, 0.72916502, 0.85205505,
            0.44877471, 0.72747678, 0.85598486,
            0.45453694, 0.72575709, 0.85981579,
            0.46036897, 0.72400662, 0.8635467,
            0.4662644, 0.72222606, 0.86717646,
            0.47221713, 0.72041608, 0.87070395,
            0.47822138, 0.71857738, 0.87412804,
            0.4842717, 0.71671065, 0.87744763,
            0.4903629, 0.71481659, 0.88066162,
            0.49649009, 0.71289591, 0.8837689,
            0.50264864, 0.71094931, 0.88676838,
            0.50883417, 0.70897752, 0.88965898,
            0.51504253, 0.70698127, 0.89243961,
            0.52126981, 0.70496128, 0.8951092,
            0.52751231, 0.70291829, 0.89766666,
            0.53376652, 0.70085306, 0.90011093,
            0.54002912, 0.69876633, 0.90244095,
            0.54629699, 0.69665888, 0.90465565,
            0.55256715, 0.69453147, 0.90675397,
            0.55883679, 0.69238489, 0.90873487,
            0.56510323, 0.69021993, 0.9105973,
            0.57136396, 0.68803739, 0.91234022,
            0.57761655, 0.68583808, 0.91396258,
            0.58385872, 0.68362282, 0.91546336,
            0.59008831, 0.68139246, 0.91684154,
            0.59630323, 0.67914782, 0.9180961,
            0.60250152, 0.67688977, 0.91922603,
            0.60868128, 0.67461918, 0.92023033,
            0.61484071, 0.67233692, 0.921108,
            0.62097809, 0.67004388, 0.92185807,
            0.62709176, 0.66774097, 0.92247957,
            0.63318012, 0.66542911, 0.92297153,
            0.63924166, 0.66310923, 0.92333301,
            0.64527488, 0.66078227, 0.92356308,
            0.65127837, 0.65844919, 0.92366082,
            0.65725076, 0.65611096, 0.92362532,
            0.66319071, 0.65376857, 0.92345572,
            0.66909691, 0.65142302, 0.92315115,
            0.67496813, 0.64907533, 0.92271076,
            0.68080311, 0.64672651, 0.92213374,
            0.68660068, 0.64437763, 0.92141929,
            0.69235965, 0.64202973, 0.92056665,
            0.69807888, 0.6396839, 0.91957507,
            0.70375724, 0.63734122, 0.91844386,
            0.70939361, 0.63500279, 0.91717232,
            0.7149869, 0.63266974, 0.91575983,
            0.72053602, 0.63034321, 0.91420578,
            0.72603991, 0.62802433, 0.9125096,
            0.7314975, 0.62571429, 0.91067077,
            0.73690773, 0.62341425, 0.9086888,
            0.74226956, 0.62112542, 0.90656328,
            0.74758193, 0.61884899, 0.90429382,
            0.75284381, 0.6165862, 0.90188009,
            0.75805413, 0.61433829, 0.89932181,
            0.76321187, 0.6121065, 0.89661877,
            0.76831596, 0.6098921, 0.89377082,
            0.77336536, 0.60769637, 0.89077786,
            0.77835901, 0.6055206, 0.88763988,
            0.78329583, 0.6033661, 0.88435693,
            0.78817477, 0.60123418, 0.88092913,
            0.79299473, 0.59912616, 0.87735668,
            0.79775462, 0.59704339, 0.87363986,
            0.80245335, 0.59498722, 0.86977904,
            0.8070898, 0.592959, 0.86577468,
            0.81166284, 0.5909601, 0.86162732,
            0.81617134, 0.5889919, 0.8573376,
            0.82061414, 0.58705579, 0.85290625,
            0.82499007, 0.58515315, 0.84833413,
            0.82929796, 0.58328538, 0.84362217,
            0.83353661, 0.58145389, 0.83877142,
            0.8377048, 0.57966009, 0.83378306,
            0.8418013, 0.57790538, 0.82865836,
            0.84582486, 0.57619119, 0.82339871,
            0.84977422, 0.57451892, 0.81800565,
            0.85364809, 0.57289, 0.8124808,
            0.85744519, 0.57130585, 0.80682595,
            0.86116418, 0.56976788, 0.80104298,
            0.86480373, 0.56827749, 0.79513394,
            0.86836249, 0.56683612, 0.789101,
            0.87183909, 0.56544515, 0.78294645,
            0.87523214, 0.56410599, 0.77667274,
            0.87854024, 0.56282002, 0.77028247,
            0.88176195, 0.56158863, 0.76377835,
            0.88489584, 0.56041319, 0.75716326,
            0.88794045, 0.55929505, 0.75044023,
            0.89089432, 0.55823556, 0.74361241,
            0.89375596, 0.55723605, 0.73668312,
            0.89652387, 0.55629781, 0.72965583,
            0.89919653, 0.55542215, 0.72253414,
            0.90177242, 0.55461033, 0.71532181,
            0.90425, 0.55386358, 0.70802274,
            0.90662774, 0.55318313, 0.70064098,
            0.90890408, 0.55257016, 0.69318073,
            0.91107745, 0.55202582, 0.68564633,
            0.91314629, 0.55155124, 0.67804225};
    }

private:
    //std::array<uint8_t, 3 * 256> m_rgb;
    std::vector<uint8_t> m_rgb;
};

} // namespace bv