
#include <cstdint>
#include <cmath>
#include <string>
#include <cstring>
#include <array>
#include <stdexcept>

//==============================================================================
/// Auto-generated C++ class for the 'CINTA' processor
///

#if ! (defined (__cplusplus) && (__cplusplus >= 201703L))
 #error "This code requires that your compiler is set to use C++17 or later!"
#endif

struct CINTA
{
    CINTA() = default;
    ~CINTA() = default;

    static constexpr std::string_view name = "CINTA";

    //==============================================================================
    using EndpointHandle = uint32_t;

    enum class EndpointType
    {
        stream,
        event,
        value
    };

    struct EndpointInfo
    {
        uint32_t handle;
        const char* name;
        EndpointType endpointType;
    };

    //==============================================================================
    static constexpr uint32_t numInputEndpoints  = 66;
    static constexpr uint32_t numOutputEndpoints = 1;

    static constexpr uint32_t maxFramesPerBlock  = 512;
    static constexpr uint32_t eventBufferSize    = 32;
    static constexpr uint32_t maxOutputEventSize = 0;
    static constexpr double   latency            = 0.000000;

    enum class EndpointHandles
    {
        noteOn               = 1 ,
        noteOff              = 2 ,
        pitchBend            = 3 ,
        audioOut             = 67,
        vibe                 = 4 ,
        warmth               = 5 ,
        space                = 6 ,
        movement             = 7 ,
        grit                 = 8 ,
        amp_attack           = 9 ,
        amp_decay            = 10,
        amp_sustain          = 11,
        amp_release          = 12,
        filter_attack        = 13,
        filter_decay         = 14,
        filter_sustain       = 15,
        filter_release       = 16,
        lfo_rate             = 17,
        lfo_wave             = 18,
        lfo_to_pitch         = 19,
        lfo_to_filter        = 20,
        lfo_to_amp           = 21,
        master_volume        = 22,
        master_width         = 23,
        master_highcut       = 24,
        voice_mode           = 25,
        voice_glide          = 26,
        fm_ratio             = 27,
        fm_depth             = 28,
        fm_feedback          = 29,
        fm_carrier_wave      = 30,
        fm_mod_wave          = 31,
        fm_level             = 32,
        fm_pan               = 33,
        fm_on                = 34,
        tape_sound           = 35,
        tape_speed           = 36,
        tape_wow             = 37,
        tape_flutter         = 38,
        tape_start           = 39,
        tape_level           = 40,
        tape_pan             = 41,
        tape_on              = 42,
        analog_osc1_wave     = 43,
        analog_osc2_wave     = 44,
        analog_osc_mix       = 45,
        analog_detune        = 46,
        analog_unison        = 47,
        analog_filter_type   = 48,
        analog_filter_cutoff = 49,
        analog_filter_reso   = 50,
        analog_filter_env    = 51,
        analog_level         = 52,
        analog_pan           = 53,
        analog_on            = 54,
        tape_age             = 55,
        vinyl_amount         = 56,
        radio_freq           = 57,
        room_size            = 58,
        tube_drive           = 59,
        crush_bits           = 60,
        arp_on               = 61,
        arp_rate             = 62,
        arp_pattern          = 63,
        arp_octaves          = 64,
        arp_swing            = 65,
        arp_gate             = 66
    };

    static constexpr uint32_t getEndpointHandleForName (std::string_view endpointName)
    {
        if (endpointName == "noteOn")                return static_cast<uint32_t> (EndpointHandles::noteOn);
        if (endpointName == "noteOff")               return static_cast<uint32_t> (EndpointHandles::noteOff);
        if (endpointName == "pitchBend")             return static_cast<uint32_t> (EndpointHandles::pitchBend);
        if (endpointName == "audioOut")              return static_cast<uint32_t> (EndpointHandles::audioOut);
        if (endpointName == "vibe")                  return static_cast<uint32_t> (EndpointHandles::vibe);
        if (endpointName == "warmth")                return static_cast<uint32_t> (EndpointHandles::warmth);
        if (endpointName == "space")                 return static_cast<uint32_t> (EndpointHandles::space);
        if (endpointName == "movement")              return static_cast<uint32_t> (EndpointHandles::movement);
        if (endpointName == "grit")                  return static_cast<uint32_t> (EndpointHandles::grit);
        if (endpointName == "amp_attack")            return static_cast<uint32_t> (EndpointHandles::amp_attack);
        if (endpointName == "amp_decay")             return static_cast<uint32_t> (EndpointHandles::amp_decay);
        if (endpointName == "amp_sustain")           return static_cast<uint32_t> (EndpointHandles::amp_sustain);
        if (endpointName == "amp_release")           return static_cast<uint32_t> (EndpointHandles::amp_release);
        if (endpointName == "filter_attack")         return static_cast<uint32_t> (EndpointHandles::filter_attack);
        if (endpointName == "filter_decay")          return static_cast<uint32_t> (EndpointHandles::filter_decay);
        if (endpointName == "filter_sustain")        return static_cast<uint32_t> (EndpointHandles::filter_sustain);
        if (endpointName == "filter_release")        return static_cast<uint32_t> (EndpointHandles::filter_release);
        if (endpointName == "lfo_rate")              return static_cast<uint32_t> (EndpointHandles::lfo_rate);
        if (endpointName == "lfo_wave")              return static_cast<uint32_t> (EndpointHandles::lfo_wave);
        if (endpointName == "lfo_to_pitch")          return static_cast<uint32_t> (EndpointHandles::lfo_to_pitch);
        if (endpointName == "lfo_to_filter")         return static_cast<uint32_t> (EndpointHandles::lfo_to_filter);
        if (endpointName == "lfo_to_amp")            return static_cast<uint32_t> (EndpointHandles::lfo_to_amp);
        if (endpointName == "master_volume")         return static_cast<uint32_t> (EndpointHandles::master_volume);
        if (endpointName == "master_width")          return static_cast<uint32_t> (EndpointHandles::master_width);
        if (endpointName == "master_highcut")        return static_cast<uint32_t> (EndpointHandles::master_highcut);
        if (endpointName == "voice_mode")            return static_cast<uint32_t> (EndpointHandles::voice_mode);
        if (endpointName == "voice_glide")           return static_cast<uint32_t> (EndpointHandles::voice_glide);
        if (endpointName == "fm_ratio")              return static_cast<uint32_t> (EndpointHandles::fm_ratio);
        if (endpointName == "fm_depth")              return static_cast<uint32_t> (EndpointHandles::fm_depth);
        if (endpointName == "fm_feedback")           return static_cast<uint32_t> (EndpointHandles::fm_feedback);
        if (endpointName == "fm_carrier_wave")       return static_cast<uint32_t> (EndpointHandles::fm_carrier_wave);
        if (endpointName == "fm_mod_wave")           return static_cast<uint32_t> (EndpointHandles::fm_mod_wave);
        if (endpointName == "fm_level")              return static_cast<uint32_t> (EndpointHandles::fm_level);
        if (endpointName == "fm_pan")                return static_cast<uint32_t> (EndpointHandles::fm_pan);
        if (endpointName == "fm_on")                 return static_cast<uint32_t> (EndpointHandles::fm_on);
        if (endpointName == "tape_sound")            return static_cast<uint32_t> (EndpointHandles::tape_sound);
        if (endpointName == "tape_speed")            return static_cast<uint32_t> (EndpointHandles::tape_speed);
        if (endpointName == "tape_wow")              return static_cast<uint32_t> (EndpointHandles::tape_wow);
        if (endpointName == "tape_flutter")          return static_cast<uint32_t> (EndpointHandles::tape_flutter);
        if (endpointName == "tape_start")            return static_cast<uint32_t> (EndpointHandles::tape_start);
        if (endpointName == "tape_level")            return static_cast<uint32_t> (EndpointHandles::tape_level);
        if (endpointName == "tape_pan")              return static_cast<uint32_t> (EndpointHandles::tape_pan);
        if (endpointName == "tape_on")               return static_cast<uint32_t> (EndpointHandles::tape_on);
        if (endpointName == "analog_osc1_wave")      return static_cast<uint32_t> (EndpointHandles::analog_osc1_wave);
        if (endpointName == "analog_osc2_wave")      return static_cast<uint32_t> (EndpointHandles::analog_osc2_wave);
        if (endpointName == "analog_osc_mix")        return static_cast<uint32_t> (EndpointHandles::analog_osc_mix);
        if (endpointName == "analog_detune")         return static_cast<uint32_t> (EndpointHandles::analog_detune);
        if (endpointName == "analog_unison")         return static_cast<uint32_t> (EndpointHandles::analog_unison);
        if (endpointName == "analog_filter_type")    return static_cast<uint32_t> (EndpointHandles::analog_filter_type);
        if (endpointName == "analog_filter_cutoff")  return static_cast<uint32_t> (EndpointHandles::analog_filter_cutoff);
        if (endpointName == "analog_filter_reso")    return static_cast<uint32_t> (EndpointHandles::analog_filter_reso);
        if (endpointName == "analog_filter_env")     return static_cast<uint32_t> (EndpointHandles::analog_filter_env);
        if (endpointName == "analog_level")          return static_cast<uint32_t> (EndpointHandles::analog_level);
        if (endpointName == "analog_pan")            return static_cast<uint32_t> (EndpointHandles::analog_pan);
        if (endpointName == "analog_on")             return static_cast<uint32_t> (EndpointHandles::analog_on);
        if (endpointName == "tape_age")              return static_cast<uint32_t> (EndpointHandles::tape_age);
        if (endpointName == "vinyl_amount")          return static_cast<uint32_t> (EndpointHandles::vinyl_amount);
        if (endpointName == "radio_freq")            return static_cast<uint32_t> (EndpointHandles::radio_freq);
        if (endpointName == "room_size")             return static_cast<uint32_t> (EndpointHandles::room_size);
        if (endpointName == "tube_drive")            return static_cast<uint32_t> (EndpointHandles::tube_drive);
        if (endpointName == "crush_bits")            return static_cast<uint32_t> (EndpointHandles::crush_bits);
        if (endpointName == "arp_on")                return static_cast<uint32_t> (EndpointHandles::arp_on);
        if (endpointName == "arp_rate")              return static_cast<uint32_t> (EndpointHandles::arp_rate);
        if (endpointName == "arp_pattern")           return static_cast<uint32_t> (EndpointHandles::arp_pattern);
        if (endpointName == "arp_octaves")           return static_cast<uint32_t> (EndpointHandles::arp_octaves);
        if (endpointName == "arp_swing")             return static_cast<uint32_t> (EndpointHandles::arp_swing);
        if (endpointName == "arp_gate")              return static_cast<uint32_t> (EndpointHandles::arp_gate);
        return 0;
    }

    static constexpr EndpointInfo inputEndpoints[] =
    {
        { 1,   "noteOn",                EndpointType::event },
        { 2,   "noteOff",               EndpointType::event },
        { 3,   "pitchBend",             EndpointType::event },
        { 4,   "vibe",                  EndpointType::event },
        { 5,   "warmth",                EndpointType::event },
        { 6,   "space",                 EndpointType::event },
        { 7,   "movement",              EndpointType::event },
        { 8,   "grit",                  EndpointType::event },
        { 9,   "amp_attack",            EndpointType::event },
        { 10,  "amp_decay",             EndpointType::event },
        { 11,  "amp_sustain",           EndpointType::event },
        { 12,  "amp_release",           EndpointType::event },
        { 13,  "filter_attack",         EndpointType::event },
        { 14,  "filter_decay",          EndpointType::event },
        { 15,  "filter_sustain",        EndpointType::event },
        { 16,  "filter_release",        EndpointType::event },
        { 17,  "lfo_rate",              EndpointType::event },
        { 18,  "lfo_wave",              EndpointType::event },
        { 19,  "lfo_to_pitch",          EndpointType::event },
        { 20,  "lfo_to_filter",         EndpointType::event },
        { 21,  "lfo_to_amp",            EndpointType::event },
        { 22,  "master_volume",         EndpointType::event },
        { 23,  "master_width",          EndpointType::event },
        { 24,  "master_highcut",        EndpointType::event },
        { 25,  "voice_mode",            EndpointType::event },
        { 26,  "voice_glide",           EndpointType::event },
        { 27,  "fm_ratio",              EndpointType::event },
        { 28,  "fm_depth",              EndpointType::event },
        { 29,  "fm_feedback",           EndpointType::event },
        { 30,  "fm_carrier_wave",       EndpointType::event },
        { 31,  "fm_mod_wave",           EndpointType::event },
        { 32,  "fm_level",              EndpointType::event },
        { 33,  "fm_pan",                EndpointType::event },
        { 34,  "fm_on",                 EndpointType::event },
        { 35,  "tape_sound",            EndpointType::event },
        { 36,  "tape_speed",            EndpointType::event },
        { 37,  "tape_wow",              EndpointType::event },
        { 38,  "tape_flutter",          EndpointType::event },
        { 39,  "tape_start",            EndpointType::event },
        { 40,  "tape_level",            EndpointType::event },
        { 41,  "tape_pan",              EndpointType::event },
        { 42,  "tape_on",               EndpointType::event },
        { 43,  "analog_osc1_wave",      EndpointType::event },
        { 44,  "analog_osc2_wave",      EndpointType::event },
        { 45,  "analog_osc_mix",        EndpointType::event },
        { 46,  "analog_detune",         EndpointType::event },
        { 47,  "analog_unison",         EndpointType::event },
        { 48,  "analog_filter_type",    EndpointType::event },
        { 49,  "analog_filter_cutoff",  EndpointType::event },
        { 50,  "analog_filter_reso",    EndpointType::event },
        { 51,  "analog_filter_env",     EndpointType::event },
        { 52,  "analog_level",          EndpointType::event },
        { 53,  "analog_pan",            EndpointType::event },
        { 54,  "analog_on",             EndpointType::event },
        { 55,  "tape_age",              EndpointType::event },
        { 56,  "vinyl_amount",          EndpointType::event },
        { 57,  "radio_freq",            EndpointType::event },
        { 58,  "room_size",             EndpointType::event },
        { 59,  "tube_drive",            EndpointType::event },
        { 60,  "crush_bits",            EndpointType::event },
        { 61,  "arp_on",                EndpointType::event },
        { 62,  "arp_rate",              EndpointType::event },
        { 63,  "arp_pattern",           EndpointType::event },
        { 64,  "arp_octaves",           EndpointType::event },
        { 65,  "arp_swing",             EndpointType::event },
        { 66,  "arp_gate",              EndpointType::event }
    };

    static constexpr EndpointInfo outputEndpoints[] =
    {
        { 67,  "audioOut",  EndpointType::stream }
    };

    //==============================================================================
    static constexpr uint32_t numAudioInputChannels  = 0;
    static constexpr uint32_t numAudioOutputChannels = 2;

    static constexpr std::array outputAudioStreams
    {
        outputEndpoints[0]
    };

    static constexpr std::array<EndpointInfo, 0> outputEvents {};

    static constexpr std::array<EndpointInfo, 0> outputMIDIEvents {};

    static constexpr std::array<EndpointInfo, 0> inputAudioStreams {};

    static constexpr std::array inputEvents
    {
        inputEndpoints[0],
        inputEndpoints[1],
        inputEndpoints[2],
        inputEndpoints[3],
        inputEndpoints[4],
        inputEndpoints[5],
        inputEndpoints[6],
        inputEndpoints[7],
        inputEndpoints[8],
        inputEndpoints[9],
        inputEndpoints[10],
        inputEndpoints[11],
        inputEndpoints[12],
        inputEndpoints[13],
        inputEndpoints[14],
        inputEndpoints[15],
        inputEndpoints[16],
        inputEndpoints[17],
        inputEndpoints[18],
        inputEndpoints[19],
        inputEndpoints[20],
        inputEndpoints[21],
        inputEndpoints[22],
        inputEndpoints[23],
        inputEndpoints[24],
        inputEndpoints[25],
        inputEndpoints[26],
        inputEndpoints[27],
        inputEndpoints[28],
        inputEndpoints[29],
        inputEndpoints[30],
        inputEndpoints[31],
        inputEndpoints[32],
        inputEndpoints[33],
        inputEndpoints[34],
        inputEndpoints[35],
        inputEndpoints[36],
        inputEndpoints[37],
        inputEndpoints[38],
        inputEndpoints[39],
        inputEndpoints[40],
        inputEndpoints[41],
        inputEndpoints[42],
        inputEndpoints[43],
        inputEndpoints[44],
        inputEndpoints[45],
        inputEndpoints[46],
        inputEndpoints[47],
        inputEndpoints[48],
        inputEndpoints[49],
        inputEndpoints[50],
        inputEndpoints[51],
        inputEndpoints[52],
        inputEndpoints[53],
        inputEndpoints[54],
        inputEndpoints[55],
        inputEndpoints[56],
        inputEndpoints[57],
        inputEndpoints[58],
        inputEndpoints[59],
        inputEndpoints[60],
        inputEndpoints[61],
        inputEndpoints[62],
        inputEndpoints[63],
        inputEndpoints[64],
        inputEndpoints[65]
    };

    static constexpr std::array<EndpointInfo, 0> inputMIDIEvents {};

    static constexpr std::array<EndpointInfo, 0> inputParameters {};

    static constexpr const char* programDetailsJSON =
            "{\n"
            "  \"mainProcessor\": \"CINTA\",\n"
            "  \"inputs\": [\n"
            "    {\n"
            "      \"endpointID\": \"noteOn\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"object\",\n"
            "        \"class\": \"NoteOn\",\n"
            "        \"members\": {\n"
            "          \"channel\": {\n"
            "            \"type\": \"int32\"\n"
            "          },\n"
            "          \"pitch\": {\n"
            "            \"type\": \"float32\"\n"
            "          },\n"
            "          \"velocity\": {\n"
            "            \"type\": \"float32\"\n"
            "          }\n"
            "        }\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"noteOff\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"object\",\n"
            "        \"class\": \"NoteOff\",\n"
            "        \"members\": {\n"
            "          \"channel\": {\n"
            "            \"type\": \"int32\"\n"
            "          },\n"
            "          \"pitch\": {\n"
            "            \"type\": \"float32\"\n"
            "          },\n"
            "          \"velocity\": {\n"
            "            \"type\": \"float32\"\n"
            "          }\n"
            "        }\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"pitchBend\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"object\",\n"
            "        \"class\": \"PitchBend\",\n"
            "        \"members\": {\n"
            "          \"channel\": {\n"
            "            \"type\": \"int32\"\n"
            "          },\n"
            "          \"bendSemitones\": {\n"
            "            \"type\": \"float32\"\n"
            "          }\n"
            "        }\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"vibe\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"warmth\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"space\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"movement\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"grit\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"amp_attack\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"amp_decay\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"amp_sustain\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"amp_release\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"filter_attack\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"filter_decay\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"filter_sustain\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"filter_release\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"lfo_rate\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"lfo_wave\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"lfo_to_pitch\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"lfo_to_filter\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"lfo_to_amp\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"master_volume\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"master_width\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"master_highcut\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"voice_mode\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"voice_glide\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"fm_ratio\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"fm_depth\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"fm_feedback\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"fm_carrier_wave\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"fm_mod_wave\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"fm_level\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"fm_pan\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"fm_on\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"tape_sound\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"tape_speed\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"tape_wow\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"tape_flutter\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"tape_start\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"tape_level\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"tape_pan\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"tape_on\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_osc1_wave\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_osc2_wave\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_osc_mix\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_detune\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_unison\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_filter_type\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_filter_cutoff\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_filter_reso\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_filter_env\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_level\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_pan\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"analog_on\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"tape_age\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"vinyl_amount\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"radio_freq\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"room_size\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"tube_drive\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"crush_bits\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"arp_on\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"arp_rate\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"arp_pattern\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"arp_octaves\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"arp_swing\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    },\n"
            "    {\n"
            "      \"endpointID\": \"arp_gate\",\n"
            "      \"endpointType\": \"event\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"float32\"\n"
            "      }\n"
            "    }\n"
            "  ],\n"
            "  \"outputs\": [\n"
            "    {\n"
            "      \"endpointID\": \"audioOut\",\n"
            "      \"endpointType\": \"stream\",\n"
            "      \"dataType\": {\n"
            "        \"type\": \"vector\",\n"
            "        \"element\": {\n"
            "          \"type\": \"float32\"\n"
            "        },\n"
            "        \"size\": 2\n"
            "      },\n"
            "      \"purpose\": \"audio out\",\n"
            "      \"numAudioChannels\": 2\n"
            "    }\n"
            "  ]\n"
            "}";

    //==============================================================================
    struct intrinsics;

    using SizeType = int32_t;
    using IndexType = int32_t;
    using StringHandle = uint32_t;

    struct Null
    {
        template <typename AnyType> operator AnyType() const    { return {}; }
        Null operator[] (IndexType) const                       { return {}; }
    };

    //==============================================================================
    template <typename ElementType, SizeType numElements>
    struct Array
    {
        Array() = default;
        Array (Null) {}
        Array (const Array&) = default;

        template <typename ElementOrList>
        Array (const ElementOrList& value) noexcept
        {
            if constexpr (std::is_convertible<ElementOrList, ElementType>::value)
            {
                for (IndexType i = 0; i < numElements; ++i)
                    this->elements[i] = static_cast<ElementType> (value);
            }
            else
            {
                for (IndexType i = 0; i < numElements; ++i)
                    this->elements[i] = static_cast<ElementType> (value[i]);
            }
        }

        template <typename... Others>
        Array (ElementType e0, ElementType e1, Others... others) noexcept
        {
            this->elements[0] = static_cast<ElementType> (e0);
            this->elements[1] = static_cast<ElementType> (e1);

            if constexpr (numElements > 2)
            {
                const ElementType initialisers[] = { static_cast<ElementType> (others)... };

                for (size_t i = 0; i < sizeof...(others); ++i)
                    this->elements[i + 2] = initialisers[i];
            }
        }

        Array (const ElementType* rawArray, size_t) noexcept
        {
            for (IndexType i = 0; i < numElements; ++i)
                this->elements[i] = rawArray[i];
        }

        Array& operator= (const Array&) noexcept = default;
        Array& operator= (Null) noexcept                 { this->clear(); return *this; }

        template <typename ElementOrList>
        Array& operator= (const ElementOrList& value) noexcept
        {
            if constexpr (std::is_convertible<ElementOrList, ElementType>::value)
            {
                for (IndexType i = 0; i < numElements; ++i)
                    this->elements[i] = static_cast<ElementType> (value);
            }
            else
            {
                for (IndexType i = 0; i < numElements; ++i)
                    this->elements[i] = static_cast<ElementType> (value[i]);
            }
        }

        static constexpr SizeType size()                                    { return numElements; }

        const ElementType& operator[] (IndexType index) const noexcept      { return this->elements[index]; }
        ElementType& operator[] (IndexType index) noexcept                  { return this->elements[index]; }

        void clear() noexcept
        {
            for (auto& element : elements)
                element = ElementType();
        }

        void clear (SizeType numElementsToClear) noexcept
        {
            for (SizeType i = 0; i < numElementsToClear; ++i)
                elements[i] = ElementType();
        }

        ElementType elements[numElements] = {};
    };

    //==============================================================================
    template <typename ElementType, SizeType numElements>
    struct Vector  : public Array<ElementType, numElements>
    {
        Vector() = default;
        Vector (Null) {}

        template <typename ElementOrList>
        Vector (const ElementOrList& value) noexcept  : Array<ElementType, numElements> (value) {}

        template <typename... Others>
        Vector (ElementType e0, ElementType e1, Others... others) noexcept  : Array<ElementType, numElements> (e0, e1, others...) {}

        Vector (const ElementType* rawArray, size_t) noexcept  : Array<ElementType, numElements> (rawArray, size_t()) {}

        template <typename ElementOrList>
        Vector& operator= (const ElementOrList& value) noexcept { return Array<ElementType, numElements>::operator= (value); }

        Vector& operator= (Null) noexcept { this->clear(); return *this; }

        operator ElementType() const noexcept
        {
            static_assert (numElements == 1);
            return this->elements[0];
        }

        constexpr auto operator!() const noexcept     { return performUnaryOp ([] (ElementType n) { return ! n; }); }
        constexpr auto operator~() const noexcept     { return performUnaryOp ([] (ElementType n) { return ~n; }); }
        constexpr auto operator-() const noexcept     { return performUnaryOp ([] (ElementType n) { return -n; }); }

        constexpr auto operator+ (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a + b; }); }
        constexpr auto operator- (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a - b; }); }
        constexpr auto operator* (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a * b; }); }
        constexpr auto operator/ (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a / b; }); }
        constexpr auto operator% (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return intrinsics::modulo (a, b); }); }
        constexpr auto operator& (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a & b; }); }
        constexpr auto operator| (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a | b; }); }
        constexpr auto operator<< (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a << b; }); }
        constexpr auto operator>> (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a >> b; }); }

        constexpr auto operator== (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a == b; }); }
        constexpr auto operator!= (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a != b; }); }
        constexpr auto operator<  (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a < b; }); }
        constexpr auto operator<= (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a <= b; }); }
        constexpr auto operator>  (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a > b; }); }
        constexpr auto operator>= (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a >= b; }); }

        template <typename Functor>
        constexpr Vector performUnaryOp (Functor&& f) const noexcept
        {
            Vector result;

            for (IndexType i = 0; i < numElements; ++i)
                result.elements[i] = f (this->elements[i]);

            return result;
        }

        template <typename Functor>
        constexpr Vector performBinaryOp (const Vector& rhs, Functor&& f) const noexcept
        {
            Vector result;

            for (IndexType i = 0; i < numElements; ++i)
                result.elements[i] = f (this->elements[i], rhs.elements[i]);

            return result;
        }

        template <typename Functor>
        constexpr Vector<bool, numElements> performComparison (const Vector& rhs, Functor&& f) const noexcept
        {
            Vector<bool, numElements> result;

            for (IndexType i = 0; i < numElements; ++i)
                result.elements[i] = f (this->elements[i], rhs.elements[i]);

            return result;
        }
    };

    //==============================================================================
    template <typename ElementType>
    struct Slice
    {
        Slice() = default;
        Slice (Null) {}
        Slice (ElementType* e, SizeType size) : elements (e), numElements (size) {}
        Slice (const Slice&) = default;
        Slice& operator= (const Slice&) = default;
        template <typename ArrayType> Slice (const ArrayType& a) : elements (const_cast<ArrayType&> (a).elements), numElements (a.size()) {}
        template <typename ArrayType> Slice (const ArrayType& a, SizeType offset, SizeType size) : elements (const_cast<ArrayType&> (a).elements + offset), numElements (size) {}

        constexpr SizeType size() const                                     { return numElements; }
        ElementType operator[] (IndexType index) const noexcept             { return numElements == 0 ? ElementType() : elements[index]; }
        ElementType& operator[] (IndexType index) noexcept                  { return numElements == 0 ? emptyValue : elements[index]; }

        Slice slice (IndexType start, IndexType end) noexcept
        {
            if (numElements == 0) return {};
            if (start >= numElements) return {};

            return { elements + start, std::min (static_cast<SizeType> (end - start), numElements - start) };
        }

        const Slice slice (IndexType start, IndexType end) const noexcept
        {
            if (numElements == 0) return {};
            if (start >= numElements) return {};

            return { elements + start, std::min (static_cast<SizeType> (end - start), numElements - start) };
        }

        ElementType* elements = nullptr;
        SizeType numElements = 0;

        static inline ElementType emptyValue {};
    };

    //==============================================================================
    #if __clang__
     #pragma clang diagnostic push
     #pragma clang diagnostic ignored "-Wunused-variable"
     #pragma clang diagnostic ignored "-Wunused-parameter"
     #pragma clang diagnostic ignored "-Wunused-label"
     #pragma clang diagnostic ignored "-Wtautological-compare"

     #if __clang_major__ >= 14
      #pragma clang diagnostic ignored "-Wunused-but-set-variable"
     #endif

     #if __clang_major__ >= 17
      #pragma clang diagnostic ignored "-Wnan-infinity-disabled"
     #endif

    #elif __GNUC__
     #pragma GCC diagnostic push
     #pragma GCC diagnostic ignored "-Wunused-variable"
     #pragma GCC diagnostic ignored "-Wunused-parameter"
     #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
     #pragma GCC diagnostic ignored "-Wunused-label"
    #else
     #pragma warning (push, 0)
     #pragma warning (disable: 4702)
     #pragma warning (disable: 4706)
    #endif

    //==============================================================================
    struct _CINTA_State
    {
        float param_vibe = {};
        float param_warmth = {};
        float param_space = {};
        float param_movement = {};
        float param_grit = {};
        float param_amp_attack = {};
        float param_amp_decay = {};
        float param_amp_sustain = {};
        float param_amp_release = {};
        float param_filter_attack = {};
        float param_filter_decay = {};
        float param_filter_sustain = {};
        float param_filter_release = {};
        float param_lfo_rate = {};
        float param_lfo_wave = {};
        float param_lfo_to_pitch = {};
        float param_lfo_to_filter = {};
        float param_lfo_to_amp = {};
        float param_master_volume = {};
        float param_master_width = {};
        float param_master_highcut = {};
        float param_voice_mode = {};
        float param_voice_glide = {};
        float param_fm_ratio = {};
        float param_fm_depth = {};
        float param_fm_feedback = {};
        float param_fm_carrier_wave = {};
        float param_fm_mod_wave = {};
        float param_fm_level = {};
        float param_fm_pan = {};
        float param_fm_on = {};
        float param_tape_sound = {};
        float param_tape_speed = {};
        float param_tape_wow = {};
        float param_tape_flutter = {};
        float param_tape_start = {};
        float param_tape_level = {};
        float param_tape_pan = {};
        float param_tape_on = {};
        float param_analog_osc1_wave = {};
        float param_analog_osc2_wave = {};
        float param_analog_osc_mix = {};
        float param_analog_detune = {};
        float param_analog_unison = {};
        float param_analog_filter_type = {};
        float param_analog_filter_cutoff = {};
        float param_analog_filter_reso = {};
        float param_analog_filter_env = {};
        float param_analog_level = {};
        float param_analog_pan = {};
        float param_analog_on = {};
        float param_tape_age = {};
        float param_vinyl_amount = {};
        float param_radio_freq = {};
        float param_room_size = {};
        float param_tube_drive = {};
        float param_crush_bits = {};
        float param_arp_on = {};
        float param_arp_rate = {};
        float param_arp_pattern = {};
        float param_arp_octaves = {};
        float param_arp_swing = {};
        float param_arp_gate = {};
        Array<bool, 8> voice_active;
        Array<int32_t, 8> voice_note;
        Array<float, 8> voice_velocity;
        Array<float, 8> voice_freq;
        Array<int32_t, 8> voice_amp_phase;
        Array<int32_t, 8> voice_filter_phase;
        Array<float, 8> voice_amp_level;
        Array<float, 8> voice_filter_level;
        Array<float, 8> voice_fm_phase;
        Array<float, 8> voice_fm_mod_phase;
        Array<float, 8> voice_fm_feedback_val;
        Array<float, 8> voice_tape_phase;
        Array<float, 8> voice_tape_phase2;
        Array<float, 8> voice_tape_wow_phase;
        Array<float, 8> voice_analog_phase1;
        Array<float, 8> voice_analog_phase2;
        Array<float, 8> voice_filter_z1;
        float pitch_bend = {};
        float lfo_phase = {};
        int32_t _sessionID = {};
        double _frequency = {};
        float sampleRate = {};
        int32_t _resumeIndex = {};
    };

    struct CINTA_State
    {
        int32_t _currentFrame = {};
        _CINTA_State _state;
    };

    struct std_notes_NoteOn
    {
        int32_t channel = {};
        float pitch = {};
        float velocity = {};
    };

    struct std_notes_NoteOff
    {
        int32_t channel = {};
        float pitch = {};
        float velocity = {};
    };

    struct std_notes_PitchBend
    {
        int32_t channel = {};
        float bendSemitones = {};
    };

    struct CINTA_IO
    {
        Array<Vector<float, 2>, 512> audioOut;
    };

    struct _CINTA_IO
    {
        Vector<float, 2> audioOut;
    };

    using std_notes_T = float;
    using std_intrinsics_T = float;
    using std_intrinsics_T_0 = float;
    using std_intrinsics_T_1 = float;

    //==============================================================================
    double getMaxFrequency() const
    {
        return 192000.0;
    }

    void initialise (int32_t sessionID, double frequency)
    {
        if (frequency > getMaxFrequency()) throw std::runtime_error ("frequency out of range");
        initSessionID = sessionID;
        initFrequency = frequency;
        reset();
    }

    void reset()
    {
        std::memset (reinterpret_cast<char*> (&cmajState), 0, sizeof (cmajState));
        int32_t processorID = 0;
        _initialise (cmajState, processorID, initSessionID, initFrequency);
    }

    void advance (int32_t frames)
    {
        cmajIO.audioOut.clear (static_cast<SizeType> (frames));
        _advance (cmajState, cmajIO, frames);
    }

    void copyOutputValue (EndpointHandle endpointHandle, void* dest)
    {
        (void) endpointHandle; (void) dest;

        throw std::runtime_error ("Unknown value endpointHandle:" + std::to_string (endpointHandle));
    }

    void copyOutputFrames (EndpointHandle endpointHandle, void* dest, uint32_t numFramesToCopy)
    {
        if (endpointHandle == 67) { std::memcpy (reinterpret_cast<char*> (dest), std::addressof (cmajIO.audioOut), 8 * numFramesToCopy); std::memset (reinterpret_cast<char*> (std::addressof (cmajIO.audioOut)), 0, 8 * numFramesToCopy); return; }
        throw std::runtime_error ("Unknown stream endpointHandle:" + std::to_string (endpointHandle));
    }

    uint32_t getNumOutputEvents (EndpointHandle endpointHandle)
    {
        (void) endpointHandle;

        throw std::runtime_error ("Unknown event endpointHandle:" + std::to_string (endpointHandle));
        return {};
    }

    void resetOutputEventCount (EndpointHandle endpointHandle)
    {
        (void) endpointHandle;
    }

    uint32_t getOutputEventType (EndpointHandle endpointHandle, uint32_t index)
    {
        (void) endpointHandle; (void) index;

        throw std::runtime_error ("Unknown event endpointHandle:" + std::to_string (endpointHandle));
        return {};
    }

    static uint32_t getOutputEventDataSize (EndpointHandle endpointHandle, uint32_t typeIndex)
    {
        (void) endpointHandle; (void) typeIndex;

        throw std::runtime_error ("Unknown event endpointHandle:" + std::to_string (endpointHandle));
        return 0;
    }

    uint32_t readOutputEvent (EndpointHandle endpointHandle, uint32_t index, unsigned char* dest)
    {

        (void) endpointHandle; (void) index; (void) dest;

        throw std::runtime_error ("Unknown event endpointHandle:" + std::to_string (endpointHandle));
        return {};
    }

    void addEvent_noteOn (const std_notes_NoteOn& event)
    {
        _sendEvent_noteOn (cmajState, event);
    }

    void addEvent_noteOff (const std_notes_NoteOff& event)
    {
        _sendEvent_noteOff (cmajState, event);
    }

    void addEvent_pitchBend (const std_notes_PitchBend& event)
    {
        _sendEvent_pitchBend (cmajState, event);
    }

    void addEvent_vibe (float event)
    {
        _sendEvent_vibe (cmajState, event);
    }

    void addEvent_warmth (float event)
    {
        _sendEvent_warmth (cmajState, event);
    }

    void addEvent_space (float event)
    {
        _sendEvent_space (cmajState, event);
    }

    void addEvent_movement (float event)
    {
        _sendEvent_movement (cmajState, event);
    }

    void addEvent_grit (float event)
    {
        _sendEvent_grit (cmajState, event);
    }

    void addEvent_amp_attack (float event)
    {
        _sendEvent_amp_attack (cmajState, event);
    }

    void addEvent_amp_decay (float event)
    {
        _sendEvent_amp_decay (cmajState, event);
    }

    void addEvent_amp_sustain (float event)
    {
        _sendEvent_amp_sustain (cmajState, event);
    }

    void addEvent_amp_release (float event)
    {
        _sendEvent_amp_release (cmajState, event);
    }

    void addEvent_filter_attack (float event)
    {
        _sendEvent_filter_attack (cmajState, event);
    }

    void addEvent_filter_decay (float event)
    {
        _sendEvent_filter_decay (cmajState, event);
    }

    void addEvent_filter_sustain (float event)
    {
        _sendEvent_filter_sustain (cmajState, event);
    }

    void addEvent_filter_release (float event)
    {
        _sendEvent_filter_release (cmajState, event);
    }

    void addEvent_lfo_rate (float event)
    {
        _sendEvent_lfo_rate (cmajState, event);
    }

    void addEvent_lfo_wave (float event)
    {
        _sendEvent_lfo_wave (cmajState, event);
    }

    void addEvent_lfo_to_pitch (float event)
    {
        _sendEvent_lfo_to_pitch (cmajState, event);
    }

    void addEvent_lfo_to_filter (float event)
    {
        _sendEvent_lfo_to_filter (cmajState, event);
    }

    void addEvent_lfo_to_amp (float event)
    {
        _sendEvent_lfo_to_amp (cmajState, event);
    }

    void addEvent_master_volume (float event)
    {
        _sendEvent_master_volume (cmajState, event);
    }

    void addEvent_master_width (float event)
    {
        _sendEvent_master_width (cmajState, event);
    }

    void addEvent_master_highcut (float event)
    {
        _sendEvent_master_highcut (cmajState, event);
    }

    void addEvent_voice_mode (float event)
    {
        _sendEvent_voice_mode (cmajState, event);
    }

    void addEvent_voice_glide (float event)
    {
        _sendEvent_voice_glide (cmajState, event);
    }

    void addEvent_fm_ratio (float event)
    {
        _sendEvent_fm_ratio (cmajState, event);
    }

    void addEvent_fm_depth (float event)
    {
        _sendEvent_fm_depth (cmajState, event);
    }

    void addEvent_fm_feedback (float event)
    {
        _sendEvent_fm_feedback (cmajState, event);
    }

    void addEvent_fm_carrier_wave (float event)
    {
        _sendEvent_fm_carrier_wave (cmajState, event);
    }

    void addEvent_fm_mod_wave (float event)
    {
        _sendEvent_fm_mod_wave (cmajState, event);
    }

    void addEvent_fm_level (float event)
    {
        _sendEvent_fm_level (cmajState, event);
    }

    void addEvent_fm_pan (float event)
    {
        _sendEvent_fm_pan (cmajState, event);
    }

    void addEvent_fm_on (float event)
    {
        _sendEvent_fm_on (cmajState, event);
    }

    void addEvent_tape_sound (float event)
    {
        _sendEvent_tape_sound (cmajState, event);
    }

    void addEvent_tape_speed (float event)
    {
        _sendEvent_tape_speed (cmajState, event);
    }

    void addEvent_tape_wow (float event)
    {
        _sendEvent_tape_wow (cmajState, event);
    }

    void addEvent_tape_flutter (float event)
    {
        _sendEvent_tape_flutter (cmajState, event);
    }

    void addEvent_tape_start (float event)
    {
        _sendEvent_tape_start (cmajState, event);
    }

    void addEvent_tape_level (float event)
    {
        _sendEvent_tape_level (cmajState, event);
    }

    void addEvent_tape_pan (float event)
    {
        _sendEvent_tape_pan (cmajState, event);
    }

    void addEvent_tape_on (float event)
    {
        _sendEvent_tape_on (cmajState, event);
    }

    void addEvent_analog_osc1_wave (float event)
    {
        _sendEvent_analog_osc1_wave (cmajState, event);
    }

    void addEvent_analog_osc2_wave (float event)
    {
        _sendEvent_analog_osc2_wave (cmajState, event);
    }

    void addEvent_analog_osc_mix (float event)
    {
        _sendEvent_analog_osc_mix (cmajState, event);
    }

    void addEvent_analog_detune (float event)
    {
        _sendEvent_analog_detune (cmajState, event);
    }

    void addEvent_analog_unison (float event)
    {
        _sendEvent_analog_unison (cmajState, event);
    }

    void addEvent_analog_filter_type (float event)
    {
        _sendEvent_analog_filter_type (cmajState, event);
    }

    void addEvent_analog_filter_cutoff (float event)
    {
        _sendEvent_analog_filter_cutoff (cmajState, event);
    }

    void addEvent_analog_filter_reso (float event)
    {
        _sendEvent_analog_filter_reso (cmajState, event);
    }

    void addEvent_analog_filter_env (float event)
    {
        _sendEvent_analog_filter_env (cmajState, event);
    }

    void addEvent_analog_level (float event)
    {
        _sendEvent_analog_level (cmajState, event);
    }

    void addEvent_analog_pan (float event)
    {
        _sendEvent_analog_pan (cmajState, event);
    }

    void addEvent_analog_on (float event)
    {
        _sendEvent_analog_on (cmajState, event);
    }

    void addEvent_tape_age (float event)
    {
        _sendEvent_tape_age (cmajState, event);
    }

    void addEvent_vinyl_amount (float event)
    {
        _sendEvent_vinyl_amount (cmajState, event);
    }

    void addEvent_radio_freq (float event)
    {
        _sendEvent_radio_freq (cmajState, event);
    }

    void addEvent_room_size (float event)
    {
        _sendEvent_room_size (cmajState, event);
    }

    void addEvent_tube_drive (float event)
    {
        _sendEvent_tube_drive (cmajState, event);
    }

    void addEvent_crush_bits (float event)
    {
        _sendEvent_crush_bits (cmajState, event);
    }

    void addEvent_arp_on (float event)
    {
        _sendEvent_arp_on (cmajState, event);
    }

    void addEvent_arp_rate (float event)
    {
        _sendEvent_arp_rate (cmajState, event);
    }

    void addEvent_arp_pattern (float event)
    {
        _sendEvent_arp_pattern (cmajState, event);
    }

    void addEvent_arp_octaves (float event)
    {
        _sendEvent_arp_octaves (cmajState, event);
    }

    void addEvent_arp_swing (float event)
    {
        _sendEvent_arp_swing (cmajState, event);
    }

    void addEvent_arp_gate (float event)
    {
        _sendEvent_arp_gate (cmajState, event);
    }

    void addEvent (EndpointHandle endpointHandle, uint32_t typeIndex, const unsigned char* eventData)
    {
        (void) endpointHandle; (void) typeIndex; (void) eventData;

        if (endpointHandle == 1)
        {
            std_notes_NoteOn value;
            memcpy (&value.channel, eventData, 4);
            eventData += 4;
            memcpy (&value.pitch, eventData, 4);
            eventData += 4;
            memcpy (&value.velocity, eventData, 4);
            eventData += 4;
            return addEvent_noteOn (value);
        }

        if (endpointHandle == 2)
        {
            std_notes_NoteOff value;
            memcpy (&value.channel, eventData, 4);
            eventData += 4;
            memcpy (&value.pitch, eventData, 4);
            eventData += 4;
            memcpy (&value.velocity, eventData, 4);
            eventData += 4;
            return addEvent_noteOff (value);
        }

        if (endpointHandle == 3)
        {
            std_notes_PitchBend value;
            memcpy (&value.channel, eventData, 4);
            eventData += 4;
            memcpy (&value.bendSemitones, eventData, 4);
            eventData += 4;
            return addEvent_pitchBend (value);
        }

        if (endpointHandle == 4)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_vibe (value);
        }

        if (endpointHandle == 5)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_warmth (value);
        }

        if (endpointHandle == 6)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_space (value);
        }

        if (endpointHandle == 7)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_movement (value);
        }

        if (endpointHandle == 8)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_grit (value);
        }

        if (endpointHandle == 9)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_amp_attack (value);
        }

        if (endpointHandle == 10)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_amp_decay (value);
        }

        if (endpointHandle == 11)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_amp_sustain (value);
        }

        if (endpointHandle == 12)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_amp_release (value);
        }

        if (endpointHandle == 13)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_filter_attack (value);
        }

        if (endpointHandle == 14)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_filter_decay (value);
        }

        if (endpointHandle == 15)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_filter_sustain (value);
        }

        if (endpointHandle == 16)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_filter_release (value);
        }

        if (endpointHandle == 17)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_lfo_rate (value);
        }

        if (endpointHandle == 18)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_lfo_wave (value);
        }

        if (endpointHandle == 19)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_lfo_to_pitch (value);
        }

        if (endpointHandle == 20)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_lfo_to_filter (value);
        }

        if (endpointHandle == 21)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_lfo_to_amp (value);
        }

        if (endpointHandle == 22)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_master_volume (value);
        }

        if (endpointHandle == 23)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_master_width (value);
        }

        if (endpointHandle == 24)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_master_highcut (value);
        }

        if (endpointHandle == 25)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_voice_mode (value);
        }

        if (endpointHandle == 26)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_voice_glide (value);
        }

        if (endpointHandle == 27)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_fm_ratio (value);
        }

        if (endpointHandle == 28)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_fm_depth (value);
        }

        if (endpointHandle == 29)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_fm_feedback (value);
        }

        if (endpointHandle == 30)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_fm_carrier_wave (value);
        }

        if (endpointHandle == 31)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_fm_mod_wave (value);
        }

        if (endpointHandle == 32)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_fm_level (value);
        }

        if (endpointHandle == 33)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_fm_pan (value);
        }

        if (endpointHandle == 34)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_fm_on (value);
        }

        if (endpointHandle == 35)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_tape_sound (value);
        }

        if (endpointHandle == 36)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_tape_speed (value);
        }

        if (endpointHandle == 37)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_tape_wow (value);
        }

        if (endpointHandle == 38)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_tape_flutter (value);
        }

        if (endpointHandle == 39)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_tape_start (value);
        }

        if (endpointHandle == 40)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_tape_level (value);
        }

        if (endpointHandle == 41)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_tape_pan (value);
        }

        if (endpointHandle == 42)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_tape_on (value);
        }

        if (endpointHandle == 43)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_osc1_wave (value);
        }

        if (endpointHandle == 44)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_osc2_wave (value);
        }

        if (endpointHandle == 45)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_osc_mix (value);
        }

        if (endpointHandle == 46)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_detune (value);
        }

        if (endpointHandle == 47)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_unison (value);
        }

        if (endpointHandle == 48)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_filter_type (value);
        }

        if (endpointHandle == 49)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_filter_cutoff (value);
        }

        if (endpointHandle == 50)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_filter_reso (value);
        }

        if (endpointHandle == 51)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_filter_env (value);
        }

        if (endpointHandle == 52)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_level (value);
        }

        if (endpointHandle == 53)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_pan (value);
        }

        if (endpointHandle == 54)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_analog_on (value);
        }

        if (endpointHandle == 55)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_tape_age (value);
        }

        if (endpointHandle == 56)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_vinyl_amount (value);
        }

        if (endpointHandle == 57)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_radio_freq (value);
        }

        if (endpointHandle == 58)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_room_size (value);
        }

        if (endpointHandle == 59)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_tube_drive (value);
        }

        if (endpointHandle == 60)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_crush_bits (value);
        }

        if (endpointHandle == 61)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_arp_on (value);
        }

        if (endpointHandle == 62)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_arp_rate (value);
        }

        if (endpointHandle == 63)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_arp_pattern (value);
        }

        if (endpointHandle == 64)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_arp_octaves (value);
        }

        if (endpointHandle == 65)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_arp_swing (value);
        }

        if (endpointHandle == 66)
        {
            float value;
            memcpy (&value, eventData, 4);
            eventData += 4;
            return addEvent_arp_gate (value);
        }
    }

    void setValue (EndpointHandle endpointHandle, const void* value, int32_t frames)
    {
        (void) endpointHandle; (void) value; (void) frames;
    }

    void setInputFrames (EndpointHandle endpointHandle, const void* frameData, uint32_t numFrames, uint32_t numTrailingFramesToClear)
    {
        (void) endpointHandle; (void) frameData; (void) numFrames; (void) numTrailingFramesToClear;
    }

    //==============================================================================
    // Rendering state values
    int32_t initSessionID;
    double initFrequency;
    CINTA_State cmajState = {};
    CINTA_IO cmajIO = {};

    //==============================================================================
    void _sendEvent_noteOn (CINTA_State& _state, std_notes_NoteOn value) noexcept
    {
        _CINTA__noteOn (_state._state, value);
    }

    void _CINTA__noteOn (_CINTA_State& _state, std_notes_NoteOn e) noexcept
    {
        int32_t  freeVoice;
        int32_t  i;

        freeVoice = int32_t {-1};
        {
            i = int32_t {0};
            for (;;)
            {
                if  (! (i < int32_t {8}))
                {
                    break;
                }
                if (! _state.voice_active[std__intrinsics___wrap_8 (i)])
                {
                    freeVoice = i;
                    break;
                }
                {
                    ++i;
                }
            }
        }
        if (freeVoice < int32_t {0})
        {
            freeVoice = int32_t {0};
        }
        _state.voice_active[std__intrinsics___wrap_8 (freeVoice)] = true;
        _state.voice_note[std__intrinsics___wrap_8 (freeVoice)] = static_cast<int32_t> (e.pitch);
        _state.voice_velocity[std__intrinsics___wrap_8 (freeVoice)] = e.velocity;
        _state.voice_freq[std__intrinsics___wrap_8 (freeVoice)] = std__notes__noteToFrequency (e.pitch);
        _state.voice_amp_phase[std__intrinsics___wrap_8 (freeVoice)] = int32_t {0};
        _state.voice_amp_level[std__intrinsics___wrap_8 (freeVoice)] = 0.0f;
        _state.voice_filter_phase[std__intrinsics___wrap_8 (freeVoice)] = int32_t {0};
        _state.voice_filter_level[std__intrinsics___wrap_8 (freeVoice)] = 0.0f;
    }

    int32_t std__intrinsics___wrap_8 (int32_t n) noexcept
    {
        return n & int32_t {7};
    }

    float std__notes__noteToFrequency (float midiNoteNumber) noexcept
    {
        return 440.0f * intrinsics::pow (2.0f, 0.083333336f * (midiNoteNumber - static_cast<float> (int32_t {69})));
    }

    float std__intrinsics__pow (float a, float b) noexcept
    {
        {
            return 0.0f;
        }
    }

    void _sendEvent_noteOff (CINTA_State& _state, std_notes_NoteOff value) noexcept
    {
        _CINTA__noteOff (_state._state, value);
    }

    void _CINTA__noteOff (_CINTA_State& _state, std_notes_NoteOff e) noexcept
    {
        int32_t  i;

        {
            i = int32_t {0};
            for (;;)
            {
                if  (! (i < int32_t {8}))
                {
                    break;
                }
                if (_state.voice_active[std__intrinsics___wrap_8 (i)] ? (_state.voice_note[std__intrinsics___wrap_8 (i)] == static_cast<int32_t> (e.pitch)) : false)
                {
                    _state.voice_active[std__intrinsics___wrap_8 (i)] = false;
                    _state.voice_amp_phase[std__intrinsics___wrap_8 (i)] = int32_t {3};
                    _state.voice_filter_phase[std__intrinsics___wrap_8 (i)] = int32_t {3};
                }
                {
                    ++i;
                }
            }
        }
    }

    void _sendEvent_pitchBend (CINTA_State& _state, std_notes_PitchBend value) noexcept
    {
        _CINTA__pitchBend (_state._state, value);
    }

    void _CINTA__pitchBend (_CINTA_State& _state, std_notes_PitchBend e) noexcept
    {
        _state.pitch_bend = e.bendSemitones;
    }

    void _sendEvent_vibe (CINTA_State& _state, float value) noexcept
    {
        _CINTA__vibe (_state._state, value);
    }

    void _CINTA__vibe (_CINTA_State& _state, float v) noexcept
    {
        _state.param_vibe = v;
    }

    void _sendEvent_warmth (CINTA_State& _state, float value) noexcept
    {
        _CINTA__warmth (_state._state, value);
    }

    void _CINTA__warmth (_CINTA_State& _state, float v) noexcept
    {
        _state.param_warmth = v;
    }

    void _sendEvent_space (CINTA_State& _state, float value) noexcept
    {
        _CINTA__space (_state._state, value);
    }

    void _CINTA__space (_CINTA_State& _state, float v) noexcept
    {
        _state.param_space = v;
    }

    void _sendEvent_movement (CINTA_State& _state, float value) noexcept
    {
        _CINTA__movement (_state._state, value);
    }

    void _CINTA__movement (_CINTA_State& _state, float v) noexcept
    {
        _state.param_movement = v;
    }

    void _sendEvent_grit (CINTA_State& _state, float value) noexcept
    {
        _CINTA__grit (_state._state, value);
    }

    void _CINTA__grit (_CINTA_State& _state, float v) noexcept
    {
        _state.param_grit = v;
    }

    void _sendEvent_amp_attack (CINTA_State& _state, float value) noexcept
    {
        _CINTA__amp_attack (_state._state, value);
    }

    void _CINTA__amp_attack (_CINTA_State& _state, float v) noexcept
    {
        _state.param_amp_attack = v;
    }

    void _sendEvent_amp_decay (CINTA_State& _state, float value) noexcept
    {
        _CINTA__amp_decay (_state._state, value);
    }

    void _CINTA__amp_decay (_CINTA_State& _state, float v) noexcept
    {
        _state.param_amp_decay = v;
    }

    void _sendEvent_amp_sustain (CINTA_State& _state, float value) noexcept
    {
        _CINTA__amp_sustain (_state._state, value);
    }

    void _CINTA__amp_sustain (_CINTA_State& _state, float v) noexcept
    {
        _state.param_amp_sustain = v;
    }

    void _sendEvent_amp_release (CINTA_State& _state, float value) noexcept
    {
        _CINTA__amp_release (_state._state, value);
    }

    void _CINTA__amp_release (_CINTA_State& _state, float v) noexcept
    {
        _state.param_amp_release = v;
    }

    void _sendEvent_filter_attack (CINTA_State& _state, float value) noexcept
    {
        _CINTA__filter_attack (_state._state, value);
    }

    void _CINTA__filter_attack (_CINTA_State& _state, float v) noexcept
    {
        _state.param_filter_attack = v;
    }

    void _sendEvent_filter_decay (CINTA_State& _state, float value) noexcept
    {
        _CINTA__filter_decay (_state._state, value);
    }

    void _CINTA__filter_decay (_CINTA_State& _state, float v) noexcept
    {
        _state.param_filter_decay = v;
    }

    void _sendEvent_filter_sustain (CINTA_State& _state, float value) noexcept
    {
        _CINTA__filter_sustain (_state._state, value);
    }

    void _CINTA__filter_sustain (_CINTA_State& _state, float v) noexcept
    {
        _state.param_filter_sustain = v;
    }

    void _sendEvent_filter_release (CINTA_State& _state, float value) noexcept
    {
        _CINTA__filter_release (_state._state, value);
    }

    void _CINTA__filter_release (_CINTA_State& _state, float v) noexcept
    {
        _state.param_filter_release = v;
    }

    void _sendEvent_lfo_rate (CINTA_State& _state, float value) noexcept
    {
        _CINTA__lfo_rate (_state._state, value);
    }

    void _CINTA__lfo_rate (_CINTA_State& _state, float v) noexcept
    {
        _state.param_lfo_rate = v;
    }

    void _sendEvent_lfo_wave (CINTA_State& _state, float value) noexcept
    {
        _CINTA__lfo_wave (_state._state, value);
    }

    void _CINTA__lfo_wave (_CINTA_State& _state, float v) noexcept
    {
        _state.param_lfo_wave = v;
    }

    void _sendEvent_lfo_to_pitch (CINTA_State& _state, float value) noexcept
    {
        _CINTA__lfo_to_pitch (_state._state, value);
    }

    void _CINTA__lfo_to_pitch (_CINTA_State& _state, float v) noexcept
    {
        _state.param_lfo_to_pitch = v;
    }

    void _sendEvent_lfo_to_filter (CINTA_State& _state, float value) noexcept
    {
        _CINTA__lfo_to_filter (_state._state, value);
    }

    void _CINTA__lfo_to_filter (_CINTA_State& _state, float v) noexcept
    {
        _state.param_lfo_to_filter = v;
    }

    void _sendEvent_lfo_to_amp (CINTA_State& _state, float value) noexcept
    {
        _CINTA__lfo_to_amp (_state._state, value);
    }

    void _CINTA__lfo_to_amp (_CINTA_State& _state, float v) noexcept
    {
        _state.param_lfo_to_amp = v;
    }

    void _sendEvent_master_volume (CINTA_State& _state, float value) noexcept
    {
        _CINTA__master_volume (_state._state, value);
    }

    void _CINTA__master_volume (_CINTA_State& _state, float v) noexcept
    {
        _state.param_master_volume = v;
    }

    void _sendEvent_master_width (CINTA_State& _state, float value) noexcept
    {
        _CINTA__master_width (_state._state, value);
    }

    void _CINTA__master_width (_CINTA_State& _state, float v) noexcept
    {
        _state.param_master_width = v;
    }

    void _sendEvent_master_highcut (CINTA_State& _state, float value) noexcept
    {
        _CINTA__master_highcut (_state._state, value);
    }

    void _CINTA__master_highcut (_CINTA_State& _state, float v) noexcept
    {
        _state.param_master_highcut = v;
    }

    void _sendEvent_voice_mode (CINTA_State& _state, float value) noexcept
    {
        _CINTA__voice_mode (_state._state, value);
    }

    void _CINTA__voice_mode (_CINTA_State& _state, float v) noexcept
    {
        _state.param_voice_mode = v;
    }

    void _sendEvent_voice_glide (CINTA_State& _state, float value) noexcept
    {
        _CINTA__voice_glide (_state._state, value);
    }

    void _CINTA__voice_glide (_CINTA_State& _state, float v) noexcept
    {
        _state.param_voice_glide = v;
    }

    void _sendEvent_fm_ratio (CINTA_State& _state, float value) noexcept
    {
        _CINTA__fm_ratio (_state._state, value);
    }

    void _CINTA__fm_ratio (_CINTA_State& _state, float v) noexcept
    {
        _state.param_fm_ratio = v;
    }

    void _sendEvent_fm_depth (CINTA_State& _state, float value) noexcept
    {
        _CINTA__fm_depth (_state._state, value);
    }

    void _CINTA__fm_depth (_CINTA_State& _state, float v) noexcept
    {
        _state.param_fm_depth = v;
    }

    void _sendEvent_fm_feedback (CINTA_State& _state, float value) noexcept
    {
        _CINTA__fm_feedback (_state._state, value);
    }

    void _CINTA__fm_feedback (_CINTA_State& _state, float v) noexcept
    {
        _state.param_fm_feedback = v;
    }

    void _sendEvent_fm_carrier_wave (CINTA_State& _state, float value) noexcept
    {
        _CINTA__fm_carrier_wave (_state._state, value);
    }

    void _CINTA__fm_carrier_wave (_CINTA_State& _state, float v) noexcept
    {
        _state.param_fm_carrier_wave = v;
    }

    void _sendEvent_fm_mod_wave (CINTA_State& _state, float value) noexcept
    {
        _CINTA__fm_mod_wave (_state._state, value);
    }

    void _CINTA__fm_mod_wave (_CINTA_State& _state, float v) noexcept
    {
        _state.param_fm_mod_wave = v;
    }

    void _sendEvent_fm_level (CINTA_State& _state, float value) noexcept
    {
        _CINTA__fm_level (_state._state, value);
    }

    void _CINTA__fm_level (_CINTA_State& _state, float v) noexcept
    {
        _state.param_fm_level = v;
    }

    void _sendEvent_fm_pan (CINTA_State& _state, float value) noexcept
    {
        _CINTA__fm_pan (_state._state, value);
    }

    void _CINTA__fm_pan (_CINTA_State& _state, float v) noexcept
    {
        _state.param_fm_pan = v;
    }

    void _sendEvent_fm_on (CINTA_State& _state, float value) noexcept
    {
        _CINTA__fm_on (_state._state, value);
    }

    void _CINTA__fm_on (_CINTA_State& _state, float v) noexcept
    {
        _state.param_fm_on = v;
    }

    void _sendEvent_tape_sound (CINTA_State& _state, float value) noexcept
    {
        _CINTA__tape_sound (_state._state, value);
    }

    void _CINTA__tape_sound (_CINTA_State& _state, float v) noexcept
    {
        _state.param_tape_sound = v;
    }

    void _sendEvent_tape_speed (CINTA_State& _state, float value) noexcept
    {
        _CINTA__tape_speed (_state._state, value);
    }

    void _CINTA__tape_speed (_CINTA_State& _state, float v) noexcept
    {
        _state.param_tape_speed = v;
    }

    void _sendEvent_tape_wow (CINTA_State& _state, float value) noexcept
    {
        _CINTA__tape_wow (_state._state, value);
    }

    void _CINTA__tape_wow (_CINTA_State& _state, float v) noexcept
    {
        _state.param_tape_wow = v;
    }

    void _sendEvent_tape_flutter (CINTA_State& _state, float value) noexcept
    {
        _CINTA__tape_flutter (_state._state, value);
    }

    void _CINTA__tape_flutter (_CINTA_State& _state, float v) noexcept
    {
        _state.param_tape_flutter = v;
    }

    void _sendEvent_tape_start (CINTA_State& _state, float value) noexcept
    {
        _CINTA__tape_start (_state._state, value);
    }

    void _CINTA__tape_start (_CINTA_State& _state, float v) noexcept
    {
        _state.param_tape_start = v;
    }

    void _sendEvent_tape_level (CINTA_State& _state, float value) noexcept
    {
        _CINTA__tape_level (_state._state, value);
    }

    void _CINTA__tape_level (_CINTA_State& _state, float v) noexcept
    {
        _state.param_tape_level = v;
    }

    void _sendEvent_tape_pan (CINTA_State& _state, float value) noexcept
    {
        _CINTA__tape_pan (_state._state, value);
    }

    void _CINTA__tape_pan (_CINTA_State& _state, float v) noexcept
    {
        _state.param_tape_pan = v;
    }

    void _sendEvent_tape_on (CINTA_State& _state, float value) noexcept
    {
        _CINTA__tape_on (_state._state, value);
    }

    void _CINTA__tape_on (_CINTA_State& _state, float v) noexcept
    {
        _state.param_tape_on = v;
    }

    void _sendEvent_analog_osc1_wave (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_osc1_wave (_state._state, value);
    }

    void _CINTA__analog_osc1_wave (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_osc1_wave = v;
    }

    void _sendEvent_analog_osc2_wave (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_osc2_wave (_state._state, value);
    }

    void _CINTA__analog_osc2_wave (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_osc2_wave = v;
    }

    void _sendEvent_analog_osc_mix (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_osc_mix (_state._state, value);
    }

    void _CINTA__analog_osc_mix (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_osc_mix = v;
    }

    void _sendEvent_analog_detune (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_detune (_state._state, value);
    }

    void _CINTA__analog_detune (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_detune = v;
    }

    void _sendEvent_analog_unison (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_unison (_state._state, value);
    }

    void _CINTA__analog_unison (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_unison = v;
    }

    void _sendEvent_analog_filter_type (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_filter_type (_state._state, value);
    }

    void _CINTA__analog_filter_type (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_filter_type = v;
    }

    void _sendEvent_analog_filter_cutoff (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_filter_cutoff (_state._state, value);
    }

    void _CINTA__analog_filter_cutoff (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_filter_cutoff = v;
    }

    void _sendEvent_analog_filter_reso (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_filter_reso (_state._state, value);
    }

    void _CINTA__analog_filter_reso (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_filter_reso = v;
    }

    void _sendEvent_analog_filter_env (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_filter_env (_state._state, value);
    }

    void _CINTA__analog_filter_env (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_filter_env = v;
    }

    void _sendEvent_analog_level (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_level (_state._state, value);
    }

    void _CINTA__analog_level (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_level = v;
    }

    void _sendEvent_analog_pan (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_pan (_state._state, value);
    }

    void _CINTA__analog_pan (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_pan = v;
    }

    void _sendEvent_analog_on (CINTA_State& _state, float value) noexcept
    {
        _CINTA__analog_on (_state._state, value);
    }

    void _CINTA__analog_on (_CINTA_State& _state, float v) noexcept
    {
        _state.param_analog_on = v;
    }

    void _sendEvent_tape_age (CINTA_State& _state, float value) noexcept
    {
        _CINTA__tape_age (_state._state, value);
    }

    void _CINTA__tape_age (_CINTA_State& _state, float v) noexcept
    {
        _state.param_tape_age = v;
    }

    void _sendEvent_vinyl_amount (CINTA_State& _state, float value) noexcept
    {
        _CINTA__vinyl_amount (_state._state, value);
    }

    void _CINTA__vinyl_amount (_CINTA_State& _state, float v) noexcept
    {
        _state.param_vinyl_amount = v;
    }

    void _sendEvent_radio_freq (CINTA_State& _state, float value) noexcept
    {
        _CINTA__radio_freq (_state._state, value);
    }

    void _CINTA__radio_freq (_CINTA_State& _state, float v) noexcept
    {
        _state.param_radio_freq = v;
    }

    void _sendEvent_room_size (CINTA_State& _state, float value) noexcept
    {
        _CINTA__room_size (_state._state, value);
    }

    void _CINTA__room_size (_CINTA_State& _state, float v) noexcept
    {
        _state.param_room_size = v;
    }

    void _sendEvent_tube_drive (CINTA_State& _state, float value) noexcept
    {
        _CINTA__tube_drive (_state._state, value);
    }

    void _CINTA__tube_drive (_CINTA_State& _state, float v) noexcept
    {
        _state.param_tube_drive = v;
    }

    void _sendEvent_crush_bits (CINTA_State& _state, float value) noexcept
    {
        _CINTA__crush_bits (_state._state, value);
    }

    void _CINTA__crush_bits (_CINTA_State& _state, float v) noexcept
    {
        _state.param_crush_bits = v;
    }

    void _sendEvent_arp_on (CINTA_State& _state, float value) noexcept
    {
        _CINTA__arp_on (_state._state, value);
    }

    void _CINTA__arp_on (_CINTA_State& _state, float v) noexcept
    {
        _state.param_arp_on = v;
    }

    void _sendEvent_arp_rate (CINTA_State& _state, float value) noexcept
    {
        _CINTA__arp_rate (_state._state, value);
    }

    void _CINTA__arp_rate (_CINTA_State& _state, float v) noexcept
    {
        _state.param_arp_rate = v;
    }

    void _sendEvent_arp_pattern (CINTA_State& _state, float value) noexcept
    {
        _CINTA__arp_pattern (_state._state, value);
    }

    void _CINTA__arp_pattern (_CINTA_State& _state, float v) noexcept
    {
        _state.param_arp_pattern = v;
    }

    void _sendEvent_arp_octaves (CINTA_State& _state, float value) noexcept
    {
        _CINTA__arp_octaves (_state._state, value);
    }

    void _CINTA__arp_octaves (_CINTA_State& _state, float v) noexcept
    {
        _state.param_arp_octaves = v;
    }

    void _sendEvent_arp_swing (CINTA_State& _state, float value) noexcept
    {
        _CINTA__arp_swing (_state._state, value);
    }

    void _CINTA__arp_swing (_CINTA_State& _state, float v) noexcept
    {
        _state.param_arp_swing = v;
    }

    void _sendEvent_arp_gate (CINTA_State& _state, float value) noexcept
    {
        _CINTA__arp_gate (_state._state, value);
    }

    void _CINTA__arp_gate (_CINTA_State& _state, float v) noexcept
    {
        _state.param_arp_gate = v;
    }

    void _initialise (CINTA_State& _state, int32_t& processorID, int32_t sessionID, double frequency) noexcept
    {
        _CINTA___initialise (_state._state, processorID, sessionID, frequency);
    }

    void _CINTA___initialise (_CINTA_State& _state, int32_t& processorID, int32_t sessionID, double frequency) noexcept
    {
        g__sessionID = sessionID;
        g__frequency = frequency;
        _state.param_vibe = 0.5f;
        _state.param_warmth = 0.5f;
        _state.param_space = 0.3f;
        _state.param_movement = 0.4f;
        _state.param_grit = 0.2f;
        _state.param_amp_attack = 0.01f;
        _state.param_amp_decay = 0.1f;
        _state.param_amp_sustain = 0.7f;
        _state.param_amp_release = 0.3f;
        _state.param_filter_attack = 0.01f;
        _state.param_filter_decay = 0.2f;
        _state.param_filter_sustain = 0.5f;
        _state.param_filter_release = 0.4f;
        _state.param_lfo_rate = 2.0f;
        _state.param_lfo_wave = 0.0f;
        _state.param_lfo_to_pitch = 0.0f;
        _state.param_lfo_to_filter = 0.0f;
        _state.param_lfo_to_amp = 0.0f;
        _state.param_master_volume = 0.8f;
        _state.param_master_width = 0.5f;
        _state.param_master_highcut = 1.0f;
        _state.param_voice_mode = 0.0f;
        _state.param_voice_glide = 0.0f;
        _state.param_fm_ratio = 2.0f;
        _state.param_fm_depth = 0.5f;
        _state.param_fm_feedback = 0.0f;
        _state.param_fm_carrier_wave = 0.0f;
        _state.param_fm_mod_wave = 0.0f;
        _state.param_fm_level = 0.8f;
        _state.param_fm_pan = 0.5f;
        _state.param_fm_on = 1.0f;
        _state.param_tape_sound = 0.0f;
        _state.param_tape_speed = 1.0f;
        _state.param_tape_wow = 0.3f;
        _state.param_tape_flutter = 0.2f;
        _state.param_tape_start = 0.0f;
        _state.param_tape_level = 0.8f;
        _state.param_tape_pan = 0.5f;
        _state.param_tape_on = 0.0f;
        _state.param_analog_osc1_wave = 0.0f;
        _state.param_analog_osc2_wave = 1.0f;
        _state.param_analog_osc_mix = 0.5f;
        _state.param_analog_detune = 0.1f;
        _state.param_analog_unison = 1.0f;
        _state.param_analog_filter_type = 0.0f;
        _state.param_analog_filter_cutoff = 0.8f;
        _state.param_analog_filter_reso = 0.3f;
        _state.param_analog_filter_env = 0.5f;
        _state.param_analog_level = 0.8f;
        _state.param_analog_pan = 0.5f;
        _state.param_analog_on = 0.0f;
        _state.param_tape_age = 0.3f;
        _state.param_vinyl_amount = 0.2f;
        _state.param_radio_freq = 0.5f;
        _state.param_room_size = 0.4f;
        _state.param_tube_drive = 0.3f;
        _state.param_crush_bits = 16.0f;
        _state.param_arp_on = 0.0f;
        _state.param_arp_rate = 4.0f;
        _state.param_arp_pattern = 0.0f;
        _state.param_arp_octaves = 1.0f;
        _state.param_arp_swing = 0.0f;
        _state.param_arp_gate = 0.8f;
        _state.pitch_bend = 0.0f;
        _state.lfo_phase = 0.0f;
    }

    void _advance (CINTA_State& _state, CINTA_IO& _io, int32_t _frames) noexcept
    {
        _CINTA_IO  ioCopy;

        for (;;)
        {
            if (_state._currentFrame == _frames)
            {
                break;
            }
            ioCopy = _CINTA_IO {};
            _CINTA__main (_state._state, ioCopy);
            _io.audioOut[_state._currentFrame] = ioCopy.audioOut;
            ++_state._currentFrame;
        }
        _state._currentFrame = int32_t {0};
    }

    void _CINTA__main (_CINTA_State& _state, _CINTA_IO& _io) noexcept
    {
        float  lfoInc;
        float  lfoValue;
        float  mixL;
        float  mixR;
        int32_t  v;
        float  noteFreq;
        float  velocity;
        int32_t  t;
        int32_t  t_0;
        int32_t  t_1;
        float  ampEnv;
        int32_t  t_2;
        int32_t  t_3;
        int32_t  t_4;
        float  filterEnv;
        float  voiceSignal;
        float  phaseInc;
        float  modPhaseInc;
        float  modulator;
        float  carrier;
        int32_t  t_5;
        int32_t  t_6;
        int32_t  t_7;
        int32_t  t_8;
        float  wowMod;
        float  flutterMod;
        float  modFreq;
        float  phaseInc_0;
        float  phase2Inc;
        float  harmonic1;
        float  harmonic2;
        float  tapeSignal;
        int32_t  t_9;
        int32_t  t_10;
        int32_t  t_11;
        int32_t  t_12;
        int32_t  t_13;
        int32_t  t_14;
        float  detune;
        float  freq1;
        float  freq2;
        float  phaseInc1;
        float  phaseInc2;
        float  osc1;
        float  osc2;
        float  analogSignal;
        int32_t  t_15;
        int32_t  t_16;
        int32_t  t_17;
        int32_t  t_18;
        float  cutoffMod;
        float  cutoff;
        float  filterCoeff;
        float  panPos;
        float  panL;
        float  panR;
        float  finalL;
        float  finalR;
        Vector<float, 2>  _temp;

        switch (_state._resumeIndex)
        {
            case 1: goto _branch0_0;
            default: break;
        }

        _state.sampleRate = static_cast<float> (1.0 * g__frequency);
        _branch0_0:
        {
            for (;;)
            {
                lfoInc = _state.param_lfo_rate / _state.sampleRate;
                lfoValue = intrinsics::sin (_state.lfo_phase * g_twoPi);
                _state.lfo_phase = (_state.lfo_phase + lfoInc);
                if (_state.lfo_phase >= 1.0f)
                {
                    _state.lfo_phase = (_state.lfo_phase - 1.0f);
                }
                mixL = 0.0f;
                mixR = 0.0f;
                {
                    v = int32_t {0};
                    for (;;)
                    {
                        {
                            if  (! (v < int32_t {8}))
                            {
                                break;
                            }
                            if ((! _state.voice_active[std__intrinsics___wrap_8 (v)]) ? (_state.voice_amp_level[std__intrinsics___wrap_8 (v)] <= 0.0f) : false)
                            {
                                goto _break_0;
                            }
                            noteFreq = _state.voice_freq[std__intrinsics___wrap_8 (v)] * intrinsics::pow (2.0f, (_state.pitch_bend + (lfoValue * _state.param_lfo_to_pitch)) / 12.0f);
                            velocity = _state.voice_velocity[std__intrinsics___wrap_8 (v)];
                            if (_state.voice_amp_phase[std__intrinsics___wrap_8 (v)] == int32_t {0})
                            {
                                if (_state.voice_active[std__intrinsics___wrap_8 (v)])
                                {
                                    {
                                        t = std__intrinsics___wrap_8 (v);
                                        _state.voice_amp_level[t] = (_state.voice_amp_level[t] + (1.0f / (_state.param_amp_attack * _state.sampleRate)));
                                    }
                                    if (_state.voice_amp_level[std__intrinsics___wrap_8 (v)] >= 1.0f)
                                    {
                                        _state.voice_amp_level[std__intrinsics___wrap_8 (v)] = 1.0f;
                                        _state.voice_amp_phase[std__intrinsics___wrap_8 (v)] = int32_t {1};
                                    }
                                }
                            }
                            else
                            {
                                if (_state.voice_amp_phase[std__intrinsics___wrap_8 (v)] == int32_t {1})
                                {
                                    {
                                        t_0 = std__intrinsics___wrap_8 (v);
                                        _state.voice_amp_level[t_0] = (_state.voice_amp_level[t_0] - ((1.0f - _state.param_amp_sustain) / (_state.param_amp_decay * _state.sampleRate)));
                                    }
                                    if (_state.voice_amp_level[std__intrinsics___wrap_8 (v)] <= _state.param_amp_sustain)
                                    {
                                        _state.voice_amp_level[std__intrinsics___wrap_8 (v)] = _state.param_amp_sustain;
                                        _state.voice_amp_phase[std__intrinsics___wrap_8 (v)] = int32_t {2};
                                    }
                                }
                                else
                                {
                                    if (_state.voice_amp_phase[std__intrinsics___wrap_8 (v)] == int32_t {2})
                                    {
                                        _state.voice_amp_level[std__intrinsics___wrap_8 (v)] = _state.param_amp_sustain;
                                    }
                                    else
                                    {
                                        if (_state.voice_amp_phase[std__intrinsics___wrap_8 (v)] == int32_t {3})
                                        {
                                            {
                                                t_1 = std__intrinsics___wrap_8 (v);
                                                _state.voice_amp_level[t_1] = (_state.voice_amp_level[t_1] - (10.0f / (_state.param_amp_release * _state.sampleRate)));
                                            }
                                            if (_state.voice_amp_level[std__intrinsics___wrap_8 (v)] <= 0.0f)
                                            {
                                                _state.voice_amp_level[std__intrinsics___wrap_8 (v)] = 0.0f;
                                                _state.voice_amp_phase[std__intrinsics___wrap_8 (v)] = int32_t {0};
                                                _state.voice_active[std__intrinsics___wrap_8 (v)] = false;
                                            }
                                        }
                                    }
                                }
                            }
                            ampEnv = _state.voice_amp_level[std__intrinsics___wrap_8 (v)] * (1.0f + ((lfoValue * _state.param_lfo_to_amp) * 0.3f));
                            if (_state.voice_filter_phase[std__intrinsics___wrap_8 (v)] == int32_t {0})
                            {
                                if (_state.voice_active[std__intrinsics___wrap_8 (v)])
                                {
                                    {
                                        t_2 = std__intrinsics___wrap_8 (v);
                                        _state.voice_filter_level[t_2] = (_state.voice_filter_level[t_2] + (1.0f / (_state.param_filter_attack * _state.sampleRate)));
                                    }
                                    if (_state.voice_filter_level[std__intrinsics___wrap_8 (v)] >= 1.0f)
                                    {
                                        _state.voice_filter_level[std__intrinsics___wrap_8 (v)] = 1.0f;
                                        _state.voice_filter_phase[std__intrinsics___wrap_8 (v)] = int32_t {1};
                                    }
                                }
                            }
                            else
                            {
                                if (_state.voice_filter_phase[std__intrinsics___wrap_8 (v)] == int32_t {1})
                                {
                                    {
                                        t_3 = std__intrinsics___wrap_8 (v);
                                        _state.voice_filter_level[t_3] = (_state.voice_filter_level[t_3] - ((1.0f - _state.param_filter_sustain) / (_state.param_filter_decay * _state.sampleRate)));
                                    }
                                    if (_state.voice_filter_level[std__intrinsics___wrap_8 (v)] <= _state.param_filter_sustain)
                                    {
                                        _state.voice_filter_level[std__intrinsics___wrap_8 (v)] = _state.param_filter_sustain;
                                        _state.voice_filter_phase[std__intrinsics___wrap_8 (v)] = int32_t {2};
                                    }
                                }
                                else
                                {
                                    if (_state.voice_filter_phase[std__intrinsics___wrap_8 (v)] == int32_t {2})
                                    {
                                        _state.voice_filter_level[std__intrinsics___wrap_8 (v)] = _state.param_filter_sustain;
                                    }
                                    else
                                    {
                                        if (_state.voice_filter_phase[std__intrinsics___wrap_8 (v)] == int32_t {3})
                                        {
                                            {
                                                t_4 = std__intrinsics___wrap_8 (v);
                                                _state.voice_filter_level[t_4] = (_state.voice_filter_level[t_4] - (10.0f / (_state.param_filter_release * _state.sampleRate)));
                                            }
                                            if (_state.voice_filter_level[std__intrinsics___wrap_8 (v)] <= 0.0f)
                                            {
                                                _state.voice_filter_level[std__intrinsics___wrap_8 (v)] = 0.0f;
                                                _state.voice_filter_phase[std__intrinsics___wrap_8 (v)] = int32_t {0};
                                            }
                                        }
                                    }
                                }
                            }
                            filterEnv = _state.voice_filter_level[std__intrinsics___wrap_8 (v)];
                            voiceSignal = 0.0f;
                            if (_state.param_fm_on > 0.5f)
                            {
                                phaseInc = noteFreq / _state.sampleRate;
                                modPhaseInc = (noteFreq * _state.param_fm_ratio) / _state.sampleRate;
                                modulator = (intrinsics::sin (_state.voice_fm_mod_phase[std__intrinsics___wrap_8 (v)] * g_twoPi) * _state.param_fm_depth) + _state.voice_fm_feedback_val[std__intrinsics___wrap_8 (v)];
                                carrier = intrinsics::sin ((_state.voice_fm_phase[std__intrinsics___wrap_8 (v)] + modulator) * g_twoPi);
                                _state.voice_fm_feedback_val[std__intrinsics___wrap_8 (v)] = (carrier * _state.param_fm_feedback);
                                voiceSignal = (voiceSignal + ((carrier * _state.param_fm_level) * 0.3f));
                                {
                                    t_5 = std__intrinsics___wrap_8 (v);
                                    _state.voice_fm_phase[t_5] = (_state.voice_fm_phase[t_5] + phaseInc);
                                }
                                {
                                    t_6 = std__intrinsics___wrap_8 (v);
                                    _state.voice_fm_mod_phase[t_6] = (_state.voice_fm_mod_phase[t_6] + modPhaseInc);
                                }
                                if (_state.voice_fm_phase[std__intrinsics___wrap_8 (v)] >= 1.0f)
                                {
                                    {
                                        t_7 = std__intrinsics___wrap_8 (v);
                                        _state.voice_fm_phase[t_7] = (_state.voice_fm_phase[t_7] - 1.0f);
                                    }
                                }
                                if (_state.voice_fm_mod_phase[std__intrinsics___wrap_8 (v)] >= 1.0f)
                                {
                                    {
                                        t_8 = std__intrinsics___wrap_8 (v);
                                        _state.voice_fm_mod_phase[t_8] = (_state.voice_fm_mod_phase[t_8] - 1.0f);
                                    }
                                }
                            }
                            if (_state.param_tape_on > 0.5f)
                            {
                                wowMod = (intrinsics::sin (_state.voice_tape_wow_phase[std__intrinsics___wrap_8 (v)] * g_twoPi) * _state.param_tape_wow) * 0.01f;
                                flutterMod = (intrinsics::sin ((_state.voice_tape_phase2[std__intrinsics___wrap_8 (v)] * g_twoPi) * 10.0f) * _state.param_tape_flutter) * 0.005f;
                                modFreq = noteFreq * ((1.0f + wowMod) + flutterMod);
                                phaseInc_0 = modFreq / _state.sampleRate;
                                phase2Inc = (modFreq * 2.0f) / _state.sampleRate;
                                harmonic1 = intrinsics::sin (_state.voice_tape_phase[std__intrinsics___wrap_8 (v)] * g_twoPi);
                                harmonic2 = intrinsics::sin (_state.voice_tape_phase2[std__intrinsics___wrap_8 (v)] * g_twoPi) * 0.3f;
                                tapeSignal = (harmonic1 + harmonic2) * 0.7f;
                                voiceSignal = (voiceSignal + ((tapeSignal * _state.param_tape_level) * 0.3f));
                                {
                                    t_9 = std__intrinsics___wrap_8 (v);
                                    _state.voice_tape_phase[t_9] = (_state.voice_tape_phase[t_9] + phaseInc_0);
                                }
                                {
                                    t_10 = std__intrinsics___wrap_8 (v);
                                    _state.voice_tape_phase2[t_10] = (_state.voice_tape_phase2[t_10] + phase2Inc);
                                }
                                {
                                    t_11 = std__intrinsics___wrap_8 (v);
                                    _state.voice_tape_wow_phase[t_11] = (_state.voice_tape_wow_phase[t_11] + (0.5f / _state.sampleRate));
                                }
                                if (_state.voice_tape_phase[std__intrinsics___wrap_8 (v)] >= 1.0f)
                                {
                                    {
                                        t_12 = std__intrinsics___wrap_8 (v);
                                        _state.voice_tape_phase[t_12] = (_state.voice_tape_phase[t_12] - 1.0f);
                                    }
                                }
                                if (_state.voice_tape_phase2[std__intrinsics___wrap_8 (v)] >= 1.0f)
                                {
                                    {
                                        t_13 = std__intrinsics___wrap_8 (v);
                                        _state.voice_tape_phase2[t_13] = (_state.voice_tape_phase2[t_13] - 1.0f);
                                    }
                                }
                                if (_state.voice_tape_wow_phase[std__intrinsics___wrap_8 (v)] >= 1.0f)
                                {
                                    {
                                        t_14 = std__intrinsics___wrap_8 (v);
                                        _state.voice_tape_wow_phase[t_14] = (_state.voice_tape_wow_phase[t_14] - 1.0f);
                                    }
                                }
                            }
                            if (_state.param_analog_on > 0.5f)
                            {
                                detune = _state.param_analog_detune * 0.01f;
                                freq1 = noteFreq * (1.0f - detune);
                                freq2 = noteFreq * (1.0f + detune);
                                phaseInc1 = freq1 / _state.sampleRate;
                                phaseInc2 = freq2 / _state.sampleRate;
                                osc1 = intrinsics::sin (_state.voice_analog_phase1[std__intrinsics___wrap_8 (v)] * g_twoPi);
                                osc2 = intrinsics::sin (_state.voice_analog_phase2[std__intrinsics___wrap_8 (v)] * g_twoPi);
                                analogSignal = (osc1 * (1.0f - _state.param_analog_osc_mix)) + (osc2 * _state.param_analog_osc_mix);
                                voiceSignal = (voiceSignal + ((analogSignal * _state.param_analog_level) * 0.3f));
                                {
                                    t_15 = std__intrinsics___wrap_8 (v);
                                    _state.voice_analog_phase1[t_15] = (_state.voice_analog_phase1[t_15] + phaseInc1);
                                }
                                {
                                    t_16 = std__intrinsics___wrap_8 (v);
                                    _state.voice_analog_phase2[t_16] = (_state.voice_analog_phase2[t_16] + phaseInc2);
                                }
                                if (_state.voice_analog_phase1[std__intrinsics___wrap_8 (v)] >= 1.0f)
                                {
                                    {
                                        t_17 = std__intrinsics___wrap_8 (v);
                                        _state.voice_analog_phase1[t_17] = (_state.voice_analog_phase1[t_17] - 1.0f);
                                    }
                                }
                                if (_state.voice_analog_phase2[std__intrinsics___wrap_8 (v)] >= 1.0f)
                                {
                                    {
                                        t_18 = std__intrinsics___wrap_8 (v);
                                        _state.voice_analog_phase2[t_18] = (_state.voice_analog_phase2[t_18] - 1.0f);
                                    }
                                }
                            }
                            voiceSignal = (voiceSignal * (ampEnv * velocity));
                            cutoffMod = (_state.param_analog_filter_cutoff + ((filterEnv * _state.param_analog_filter_env) * 0.5f)) + ((lfoValue * _state.param_lfo_to_filter) * 0.3f);
                            cutoff = intrinsics::clamp (cutoffMod, 0.0f, 1.0f);
                            filterCoeff = cutoff * 0.99f;
                            _state.voice_filter_z1[std__intrinsics___wrap_8 (v)] = ((_state.voice_filter_z1[std__intrinsics___wrap_8 (v)] * filterCoeff) + (voiceSignal * (1.0f - filterCoeff)));
                            voiceSignal = _state.voice_filter_z1[std__intrinsics___wrap_8 (v)];
                            panPos = 0.5f;
                            panL = 0.70710677f;
                            panR = 0.70710677f;
                            mixL = (mixL + (voiceSignal * panL));
                            mixR = (mixR + (voiceSignal * panR));
                        }
                        _break_0: {}
                        {
                            ++v;
                        }
                    }
                }
                finalL = (mixL * _state.param_master_volume) * 0.5f;
                finalR = (mixR * _state.param_master_volume) * 0.5f;
                _temp[int32_t {0}] = finalL;
                _temp[int32_t {1}] = finalR;
                _io.audioOut = (_io.audioOut + _temp);
                _state._resumeIndex = int32_t {1};
                return;
            }
        }
    }

    float std__intrinsics__sin (float n) noexcept
    {
        {
            return 0.0f;
        }
    }

    float std__intrinsics__clamp (float value, float minimum, float maximum) noexcept
    {
        return (value > maximum) ? maximum : ((value < minimum) ? minimum : value);
    }

    //==============================================================================
    const char* getStringForHandle (uint32_t handle, size_t& stringLength)
    {
        (void) handle; (void) stringLength;
        return "";
    }

    //==============================================================================
    int32_t g__sessionID {};
    double g__frequency {};
    static constexpr float g_twoPi { 6.2831855f };

    //==============================================================================
    struct intrinsics
    {
        template <typename T> static T modulo (T a, T b)
        {
            if constexpr (std::is_floating_point<T>::value)
                return std::fmod (a, b);
            else
                return a % b;
        }

        template <typename T> static T addModulo2Pi (T a, T b)
        {
            constexpr auto twoPi = static_cast<T> (3.141592653589793238 * 2);
            auto n = a + b;
            return n >= twoPi ? std::remainder (n, twoPi) : n;
        }

        template <typename T> static T abs           (T a)              { return std::abs (a); }
        template <typename T> static T min           (T a, T b)         { return std::min (a, b); }
        template <typename T> static T max           (T a, T b)         { return std::max (a, b); }
        template <typename T> static T clamp         (T a, T b, T c)    { return a < b ? b : (a > c ? c : a); }
        template <typename T> static T wrap          (T a, T b)         { if (b == 0) return 0; auto n = modulo (a, b); if (n < 0) n += b; return n; }
        template <typename T> static T fmod          (T a, T b)         { return b != 0 ? std::fmod (a, b) : 0; }
        template <typename T> static T remainder     (T a, T b)         { return b != 0 ? std::remainder (a, b) : 0; }
        template <typename T> static T floor         (T a)              { return std::floor (a); }
        template <typename T> static T ceil          (T a)              { return std::ceil (a); }
        template <typename T> static T rint          (T a)              { return std::rint (a); }
        template <typename T> static T sqrt          (T a)              { return std::sqrt (a); }
        template <typename T> static T pow           (T a, T b)         { return std::pow (a, b); }
        template <typename T> static T exp           (T a)              { return std::exp (a); }
        template <typename T> static T log           (T a)              { return std::log (a); }
        template <typename T> static T log10         (T a)              { return std::log10 (a); }
        template <typename T> static T sin           (T a)              { return std::sin (a); }
        template <typename T> static T cos           (T a)              { return std::cos (a); }
        template <typename T> static T tan           (T a)              { return std::tan (a); }
        template <typename T> static T sinh          (T a)              { return std::sinh (a); }
        template <typename T> static T cosh          (T a)              { return std::cosh (a); }
        template <typename T> static T tanh          (T a)              { return std::tanh (a); }
        template <typename T> static T asinh         (T a)              { return std::asinh (a); }
        template <typename T> static T acosh         (T a)              { return std::acosh (a); }
        template <typename T> static T atanh         (T a)              { return std::atanh (a); }
        template <typename T> static T asin          (T a)              { return std::asin (a); }
        template <typename T> static T acos          (T a)              { return std::acos (a); }
        template <typename T> static T atan          (T a)              { return std::atan (a); }
        template <typename T> static T atan2         (T a, T b)         { return std::atan2 (a, b); }
        template <typename T> static T isnan         (T a)              { return std::isnan (a) ? 1 : 0; }
        template <typename T> static T isinf         (T a)              { return std::isinf (a) ? 1 : 0; }
        template <typename T> static T select        (bool c, T a, T b) { return c ? a : b; }

        static int32_t reinterpretFloatToInt (float   a)                { int32_t i; memcpy (std::addressof(i), std::addressof(a), sizeof(i)); return i; }
        static int64_t reinterpretFloatToInt (double  a)                { int64_t i; memcpy (std::addressof(i), std::addressof(a), sizeof(i)); return i; }
        static float   reinterpretIntToFloat (int32_t a)                { float   f; memcpy (std::addressof(f), std::addressof(a), sizeof(f)); return f; }
        static double  reinterpretIntToFloat (int64_t a)                { double  f; memcpy (std::addressof(f), std::addressof(a), sizeof(f)); return f; }

        static int32_t rightShiftUnsigned (int32_t a, int32_t b)        { return static_cast<int32_t> (static_cast<uint32_t> (a) >> b); }
        static int64_t rightShiftUnsigned (int64_t a, int64_t b)        { return static_cast<int64_t> (static_cast<uint64_t> (a) >> b); }

        struct VectorOps
        {
            template <typename Vec> static Vec abs     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::abs (x); }); }
            template <typename Vec> static Vec min     (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::min (x, y); }); }
            template <typename Vec> static Vec max     (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::max (x, y); }); }
            template <typename Vec> static Vec sqrt    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::sqrt (x); }); }
            template <typename Vec> static Vec log     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::log (x); }); }
            template <typename Vec> static Vec log10   (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::log10 (x); }); }
            template <typename Vec> static Vec sin     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::sin (x); }); }
            template <typename Vec> static Vec cos     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::cos (x); }); }
            template <typename Vec> static Vec tan     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::tan (x); }); }
            template <typename Vec> static Vec sinh    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::sinh (x); }); }
            template <typename Vec> static Vec cosh    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::cosh (x); }); }
            template <typename Vec> static Vec tanh    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::tanh (x); }); }
            template <typename Vec> static Vec asinh   (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::asinh (x); }); }
            template <typename Vec> static Vec acosh   (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::acosh (x); }); }
            template <typename Vec> static Vec atanh   (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::atanh (x); }); }
            template <typename Vec> static Vec asin    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::asin (x); }); }
            template <typename Vec> static Vec acos    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::acos (x); }); }
            template <typename Vec> static Vec atan    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::atan (x); }); }
            template <typename Vec> static Vec atan2   (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::atan2 (x, y); }); }
            template <typename Vec> static Vec pow     (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::pow (x, y); }); }
            template <typename Vec> static Vec exp     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::exp (x); }); }

            template <typename Vec> static Vec rightShiftUnsigned (Vec a, Vec b) { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::rightShiftUnsigned (x, y); }); }
        };
    };

    static constexpr float  _inf32  =  std::numeric_limits<float>::infinity();
    static constexpr double _inf64  =  std::numeric_limits<double>::infinity();
    static constexpr float  _ninf32 = -std::numeric_limits<float>::infinity();
    static constexpr double _ninf64 = -std::numeric_limits<double>::infinity();
    static constexpr float  _nan32  =  std::numeric_limits<float>::quiet_NaN();
    static constexpr double _nan64  =  std::numeric_limits<double>::quiet_NaN();

    //==============================================================================
    #if __clang__
     #pragma clang diagnostic pop
    #elif __GNUC__
     #pragma GCC diagnostic pop
    #else
     #pragma warning (pop)
    #endif
};

