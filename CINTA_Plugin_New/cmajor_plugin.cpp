//
//     ,ad888ba,                              88
//    d8"'    "8b
//   d8            88,dba,,adba,   ,aPP8A.A8  88     The Cmajor Toolkit
//   Y8,           88    88    88  88     88  88
//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd
//     '"Y888Y"'   88    88    88  '"8bbP"Y8  88     https://cmajor.dev
//                                           ,88
//                                        888P"
//
//  The Cmajor project is subject to commercial or open-source licensing.
//  You may use it under the terms of the GPLv3 (see www.gnu.org/licenses), or
//  visit https://cmajor.dev to learn about our commercial licence options.
//
//  CMAJOR IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
//  EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
//  DISCLAIMED.

// Auto-generated Cmajor code for patch 'CINTA'

#include <JuceHeader.h>
#include "cmajor/helpers/cmaj_JUCEPlugin.h"
#include "choc/javascript/choc_javascript_QuickJS.h"



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

namespace performer
{
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
            Array<float, 8> voice_note;
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
            _state.voice_note[std__intrinsics___wrap_8 (freeVoice)] = e.pitch;
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
                    if (_state.voice_active[std__intrinsics___wrap_8 (i)] ? (static_cast<float> (static_cast<int32_t> (_state.voice_note[std__intrinsics___wrap_8 (i)])) == e.pitch) : false)
                    {
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
                                if (_state.voice_active[std__intrinsics___wrap_8 (v)])
                                {
                                    if (_state.voice_amp_phase[std__intrinsics___wrap_8 (v)] == int32_t {0})
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
                                    }
                                }
                                else
                                {
                                    if (_state.voice_amp_phase[std__intrinsics___wrap_8 (v)] == int32_t {3})
                                    {
                                        {
                                            t_1 = std__intrinsics___wrap_8 (v);
                                            _state.voice_amp_level[t_1] = (_state.voice_amp_level[t_1] - (_state.param_amp_sustain / (_state.param_amp_release * _state.sampleRate)));
                                        }
                                        if (_state.voice_amp_level[std__intrinsics___wrap_8 (v)] <= 0.0f)
                                        {
                                            _state.voice_amp_level[std__intrinsics___wrap_8 (v)] = 0.0f;
                                            _state.voice_amp_phase[std__intrinsics___wrap_8 (v)] = int32_t {0};
                                        }
                                    }
                                }
                                ampEnv = _state.voice_amp_level[std__intrinsics___wrap_8 (v)] * (1.0f + ((lfoValue * _state.param_lfo_to_amp) * 0.3f));
                                if (_state.voice_active[std__intrinsics___wrap_8 (v)])
                                {
                                    if (_state.voice_filter_phase[std__intrinsics___wrap_8 (v)] == int32_t {0})
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
                                    }
                                }
                                else
                                {
                                    if (_state.voice_filter_phase[std__intrinsics___wrap_8 (v)] == int32_t {3})
                                    {
                                        {
                                            t_4 = std__intrinsics___wrap_8 (v);
                                            _state.voice_filter_level[t_4] = (_state.voice_filter_level[t_4] - (_state.param_filter_sustain / (_state.param_filter_release * _state.sampleRate)));
                                        }
                                        if (_state.voice_filter_level[std__intrinsics___wrap_8 (v)] <= 0.0f)
                                        {
                                            _state.voice_filter_level[std__intrinsics___wrap_8 (v)] = 0.0f;
                                            _state.voice_filter_phase[std__intrinsics___wrap_8 (v)] = int32_t {0};
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
} // namespace performer



struct CINTA
{
    using PerformerClass = performer::CINTA;
    static constexpr auto filename = "CINTA.cmajorpatch";

    struct File { std::string_view name, content; };

    static constexpr const char* cmaj_api_cmajpatchconnection_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import { EventListenerList } from \"./cmaj-event-listener-list.js\"\n"
        "import * as midi from \"./cmaj-midi-helpers.js\"\n"
        "import PianoKeyboard from \"./cmaj-piano-keyboard.js\"\n"
        "import GenericPatchView from \"./cmaj-generic-patch-view.js\"\n"
        "import * as ParameterControls from \"./cmaj-parameter-controls.js\"\n"
        "\n"
        "//==============================================================================\n"
        "/** This class implements the API and much of the logic for communicating with\n"
        " *  an instance of a patch that is running.\n"
        " */\n"
        "export class PatchConnection  extends EventListenerList\n"
        "{\n"
        "    constructor()\n"
        "    {\n"
        "        super();\n"
        "    }\n"
        "\n"
        "    /** Returns the current Cmajor version */\n"
        "    async getCmajorVersion()\n"
        "    {\n"
        "        const version = await import (\"/cmaj_api/cmaj-version.js\");\n"
        "        return version.getCmajorVersion();\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Status-handling methods:\n"
        "\n"
        "    /** Calling this will trigger an asynchronous callback to any status listeners with the\n"
        "     *  patch's current state. Use addStatusListener() to attach a listener to receive it.\n"
        "     */\n"
        "    requestStatusUpdate()                             { this.sendMessageToServer ({ type: \"req_status\" }); }\n"
        "\n"
        "    /** Attaches a listener function that will be called whenever the patch's status changes.\n"
        "     *  The function will be called with a parameter object containing many properties describing the status,\n"
        "     *  including whether the patch is loaded, any errors, endpoint descriptions, its manifest, etc.\n"
        "     */\n"
        "    addStatusListener (listener)                      { this.addEventListener    (\"status\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with addStatusListener()\n"
        "     */\n"
        "    removeStatusListener (listener)                   { this.removeEventListener (\"status\", listener); }\n"
        "\n"
        "    /** Causes the patch to be reset to its \"just loaded\" state. */\n"
        "    resetToInitialState()                             { this.sendMessageToServer ({ type: \"req_reset\" }); }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Methods for sending data to input endpoints:\n"
        "\n"
        "    /** Sends a value to one of the patch's input endpoints.\n"
        "     *\n"
        "     *  This can be used to send a value to either an 'event' or 'value' type input endpoint.\n"
        "     *  If the endpoint is a 'value' type, then the rampFrames parameter can optionally be used to specify\n"
        "     *  the number of frames over which the current value should ramp to the new target one.\n"
        "     *  The value parameter will be coerced to the type that is expected by the endpoint. So for\n"
        "     *  examples, numbers will be converted to float or integer types, javascript objects and arrays\n"
        "     *  will be converted into more complex types in as good a fashion is possible.\n"
        "     */\n"
        "    sendEventOrValue (endpointID, value, rampFrames, timeoutMillisecs)  { this.sendMessageToServer ({ type: \"send_value\", id: endpointID, value, rampFrames, timeout: timeoutMillisecs }); }\n"
        "\n"
        "    /** Sends a short MIDI message value to a MIDI endpoint.\n"
        "     *  The value must be a number encoded with `(byte0 << 16) | (byte1 << 8) | byte2`.\n"
        "     */\n"
        "    sendMIDIInputEvent (endpointID, shortMIDICode)    { this.sendEventOrValue (endpointID, { message: shortMIDICode }); }\n"
        "\n"
        "    /** Tells the patch that a series of changes that constitute a gesture is about to take place\n"
        "     *  for the given endpoint. Remember to call sendParameterGestureEnd() after they're done!\n"
        "     */\n"
        "    sendParameterGestureStart (endpointID)            { this.sendMessageToServer ({ type: \"send_gesture_start\", id: endpointID }); }\n"
        "\n"
        "    /** Tells the patch that a gesture started by sendParameterGestureStart() has finished.\n"
        "     */\n"
        "    sendParameterGestureEnd (endpointID)              { this.sendMessageToServer ({ type: \"send_gesture_end\", id: endpointID }); }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Stored state control methods:\n"
        "\n"
        "    /** Requests a callback to any stored-state value listeners with the current value of a given key-value pair.\n"
        "     *  To attach a listener to receive these events, use addStoredStateValueListener().\n"
        "     *  @param {string} key\n"
        "     */\n"
        "    requestStoredStateValue (key)                     { this.sendMessageToServer ({ type: \"req_state_value\", key: key }); }\n"
        "\n"
        "    /** Modifies a key-value pair in the patch's stored state.\n"
        "     *  @param {string} key\n"
        "     *  @param {Object | null | undefined} newValue\n"
        "     */\n"
        "    sendStoredStateValue (key, newValue)              { this.sendMessageToServer ({ type: \"send_state_value\", key: key, value: newValue }); }\n"
        "\n"
        "    /** Removes all stored state values in the patch.\n"
        "     */\n"
        "    clearAllStoredStateValues()                       { this.sendMessageToServer ({ type: \"clear_all_state_values\" }); }\n"
        "\n"
        "    /** Attaches a listener function that will be called when any key-value pair in the stored state is changed.\n"
        "     *  The listener function will receive a message parameter with properties 'key' and 'value'.\n"
        "     */\n"
        "    addStoredStateValueListener (listener)            { this.addEventListener    (\"state_key_value\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with addStoredStateValueListener().\n"
        "     */\n"
        "    removeStoredStateValueListener (listener)         { this.removeEventListener (\"state_key_value\", listener); }\n"
        "\n"
        "    /** Applies a complete stored state to the patch.\n"
        "     *  To get the current complete state, use requestFullStoredState().\n"
        "     */\n"
        "    sendFullStoredState (fullState)                   { this.sendMessageToServer ({ type: \"send_full_state\", value: fullState }); }\n"
        "\n"
        "    /** Asynchronously requests the full stored state of the patch.\n"
        "     *  The listener function that is supplied will be called asynchronously with the state as its argument.\n"
        "     */\n"
        "    requestFullStoredState (callback)\n"
        "    {\n"
        "        const replyType = \"fullstate_response_\" + (Math.floor (Math.random() * 100000000)).toString();\n"
        "        this.addSingleUseListener (replyType, callback);\n"
        "        this.sendMessageToServer ({ type: \"req_full_state\", replyType: replyType });\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Listener methods:\n"
        "\n"
        "    /** Attaches a listener function that will receive updates with the events or audio data\n"
        "     *  that is being sent or received by an endpoint.\n"
        "     *\n"
        "     *  If the endpoint is an event or value, the callback will be given an argument which is\n"
        "     *  the new value.\n"
        "     *\n"
        "     *  If the endpoint has the right shape to be treated as \"audio\" then the callback will receive\n"
        "     *  a stream of updates of the min/max range of chunks of data that is flowing through it.\n"
        "     *  There will be one callback per chunk of data, and the size of chunks is specified by\n"
        "     *  the optional granularity parameter.\n"
        "     *\n"
        "     *  @param {string} endpointID\n"
        "     *  @param {number} granularity - if defined, this specifies the number of frames per callback\n"
        "     *  @param {boolean} sendFullAudioData - if false, the listener will receive an argument object containing\n"
        "     *     two properties 'min' and 'max', which are each an array of values, one element per audio\n"
        "     *     channel. This allows you to find the highest and lowest samples in that chunk for each channel.\n"
        "     *     If sendFullAudioData is true, the listener's argument will have a property 'data' which is an\n"
        "     *     array containing one array per channel of raw audio samples data.\n"
        "     */\n"
        "    addEndpointListener (endpointID, listener, granularity, sendFullAudioData)\n"
        "    {\n"
        "        const listenerID = \"event_\" + endpointID + \"_\" + (Math.floor (Math.random() * 100000000)).toString();\n"
        "        listener[\"cmaj_endpointListenerID_\" + endpointID] = listenerID;\n"
        "        this.addEventListener (listenerID, listener);\n"
        "        this.sendMessageToServer ({ type: \"add_endpoint_listener\", endpoint: endpointID, replyType: listenerID,\n"
        "                                    granularity: granularity, fullAudioData: sendFullAudioData });\n"
        "    }\n"
        "\n"
        "    /** Removes a listener that was previously added with addEndpointListener()\n"
        "     *  @param {string} endpointID\n"
        "    */\n"
        "    removeEndpointListener (endpointID, listener)\n"
        "    {\n"
        "        const listenerID = listener[\"cmaj_endpointListenerID_\" + endpointID];\n"
        "        listener[\"cmaj_endpointListenerID_\" + endpointID] = undefined;\n"
        "        this.removeEventListener (listenerID, listener);\n"
        "        this.sendMessageToServer ({ type: \"remove_endpoint_listener\", endpoint: endpointID, replyType: listenerID });\n"
        "    }\n"
        "\n"
        "    /** This will trigger an asynchronous callback to any parameter listeners that are\n"
        "     *  attached, providing them with its up-to-date current value for the given endpoint.\n"
        "     *  Use addAllParameterListener() to attach a listener to receive the result.\n"
        "     *  @param {string} endpointID\n"
        "     */\n"
        "    requestParameterValue (endpointID)                  { this.sendMessageToServer ({ type: \"req_param_value\", id: endpointID }); }\n"
        "\n"
        "    /** Attaches a listener function which will be called whenever the value of a specific parameter changes.\n"
        "     *  The listener function will be called with an argument which is the new value.\n"
        "     *  @param {string} endpointID\n"
        "     */\n"
        "    addParameterListener (endpointID, listener)         { this.addEventListener (\"param_value_\" + endpointID.toString(), listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with addParameterListener()\n"
        "     *  @param {string} endpointID\n"
        "    */\n"
        "    removeParameterListener (endpointID, listener)      { this.removeEventListener (\"param_value_\" + endpointID.toString(), listener); }\n"
        "\n"
        "    /** Attaches a listener function which will be called whenever the value of any parameter changes in the patch.\n"
        "     *  The listener function will be called with an argument object with the fields 'endpointID' and 'value'.\n"
        "     */\n"
        "    addAllParameterListener (listener)                  { this.addEventListener (\"param_value\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with addAllParameterListener()\n"
        "     */\n"
        "    removeAllParameterListener (listener)               { this.removeEventListener (\"param_value\", listener); }\n"
        "\n"
        "    /** This takes a relative path to an asset within the patch bundle, and converts it to a\n"
        "     *  path relative to the root of the browser that is showing the view.\n"
        "     *\n"
        "     *  You need to use this in your view code to translate your asset URLs to a form that\n"
        "     *  can be safely used in your view's HTML DOM (e.g. in its CSS). This is needed because the\n"
        "     *  host's HTTP server (which is delivering your view pages) may have a different '/' root\n"
        "     *  than the root of your patch (e.g. if a single server is serving multiple patch GUIs).\n"
        "     *\n"
        "     *  @param {string} path\n"
        "     */\n"
        "    getResourceAddress (path)                           { return path; }\n"
        "\n"
        "    //==============================================================================\n"
        "    /**\n"
        "     *  This property contains various utility classes and functions from the Cmajor API,\n"
        "     *  for use in your GUI or worker code.\n"
        "     */\n"
        "    utilities = {\n"
        "        /** MIDI utility functions from cmaj-midi-helpers.js */\n"
        "        midi,\n"
        "        /** On-screen keyboard class from cmaj-piano-keyboard.js */\n"
        "        PianoKeyboard,\n"
        "        /** Basic parameter control GUI elements, from cmaj-parameter-controls.js */\n"
        "        ParameterControls,\n"
        "        /** The default view GUI, from cmaj-generic-patch-view.js */\n"
        "        GenericPatchView\n"
        "    };\n"
        "\n"
        "    //==============================================================================\n"
        "    // Private methods follow this point..\n"
        "\n"
        "    /** @private */\n"
        "    deliverMessageFromServer (msg)\n"
        "    {\n"
        "        if (msg.type === \"status\")\n"
        "            this.manifest = msg.message?.manifest;\n"
        "\n"
        "        if (msg.type == \"param_value\")\n"
        "            this.dispatchEvent (\"param_value_\" + msg.message.endpointID, msg.message.value);\n"
        "\n"
        "        this.dispatchEvent (msg.type, msg.message);\n"
        "    }\n"
        "}\n";
    static constexpr const char* CINTA_cmajorpatch =
        "{\n"
        "  \"CmajorVersion\": 1,\n"
        "  \"ID\": \"com.classamusic.cinta\",\n"
        "  \"version\": \"1.0.0\",\n"
        "  \"name\": \"CINTA\",\n"
        "  \"description\": \"Vintage Texture Machine - 1975 Havana Studio Synth\",\n"
        "  \"category\": \"synth\",\n"
        "  \"manufacturer\": \"Classa Music\",\n"
        "  \"isInstrument\": true,\n"
        "  \"source\": \"src/CINTA.cmajor\",\n"
        "  \"view\": {\n"
        "    \"src\": \"ui/index-vintage.html\",\n"
        "    \"width\": 1400,\n"
        "    \"height\": 850,\n"
        "    \"resizable\": false\n"
        "  }\n"
        "}";
    static constexpr const char* cmaj_api_assets_cmajorlogo_svg =
        "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"150 140 1620 670\">\n"
        "  <g>\n"
        "    <path\n"
        "      d=\"M944.511,462.372V587.049H896.558V469.165c0-27.572-13.189-44.757-35.966-44.757-23.577,0-39.958,19.183-39.958,46.755V587.049H773.078V469.165c0-27.572-13.185-44.757-35.962-44.757-22.378,0-39.162,19.581-39.162,46.755V587.049H650.4v-201.4h47.551v28.77c8.39-19.581,28.771-32.766,54.346-32.766,27.572,0,46.353,11.589,56.343,35.166,11.589-23.577,33.57-35.166,65.934-35.166C918.937,381.652,944.511,412.42,944.511,462.372Zm193.422-76.724h47.953v201.4h-47.953V557.876c-6.794,19.581-31.167,33.567-64.335,33.567q-42.558,0-71.928-29.969c-19.183-20.381-28.771-45.155-28.771-75.128s9.588-54.743,28.771-74.726c19.581-20.377,43.556-30.366,71.928-30.366,33.168,0,57.541,13.985,64.335,33.566Zm3.6,100.7c0-17.579-5.993-32.368-17.981-43.953-11.589-11.59-26.374-17.583-43.559-17.583s-31.167,5.993-42.756,17.583c-11.187,11.585-16.783,26.374-16.783,43.953s5.6,32.369,16.783,43.958c11.589,11.589,25.575,17.583,42.756,17.583s31.97-5.994,43.559-17.583C1135.537,518.715,1141.53,503.929,1141.53,486.346Zm84.135,113.49c0,21.177-7.594,29.571-25.575,29.571-2.8,0-7.192-.4-13.185-.8v42.357c4.393.8,11.187,1.2,19.979,1.2,44.355,0,66.734-22.776,66.734-67.932V385.648h-47.953Zm23.978-294.108c-15.987,0-28.774,12.385-28.774,28.372s12.787,28.369,28.774,28.369a28.371,28.371,0,0,0,0-56.741Zm239.674,104.694c21.177,20.381,31.966,45.956,31.966,75.924s-10.789,55.547-31.966,75.928-47.154,30.769-77.926,30.769-56.741-10.392-77.922-30.769-31.966-45.955-31.966-75.928,10.789-55.543,31.966-75.924,47.154-30.768,77.922-30.768S1468.136,390.041,1489.317,410.422Zm-15.585,75.924c0-17.981-5.994-32.766-17.985-44.753-11.988-12.39-26.773-18.383-44.356-18.383-17.981,0-32.766,5.993-44.754,18.383-11.589,11.987-17.583,26.772-17.583,44.753s5.994,32.77,17.583,45.156c11.988,11.987,26.773,17.985,44.754,17.985q26.374,0,44.356-17.985C1467.738,519.116,1473.732,504.331,1473.732,486.346Zm184.122-104.694c-28.373,0-50.349,12.787-59.941,33.964V385.648h-47.551v201.4h47.551v-105.9c0-33.169,21.177-53.948,54.345-53.948a102.566,102.566,0,0,1,19.979,2V382.85A74.364,74.364,0,0,0,1657.854,381.652ZM58"
        "0.777,569.25l33.909,30.087c-40.644,47.027-92.892,70.829-156.173,70.829-58.637,0-108.567-19.737-149.788-59.8C268.082,570.31,247.763,519.8,247.763,460s20.319-109.726,60.962-149.786c41.221-40.059,91.151-60.38,149.788-60.38,62.119,0,113.789,22.643,154.432,68.507l-33.864,30.134c-16.261-19.069-35.272-32.933-56.978-41.783V486.346H496.536V621.1Q546.954,610.231,580.777,569.25Zm-237.74,9.1A150.247,150.247,0,0,0,396.5,614.04V486.346H370.929V319.387a159.623,159.623,0,0,0-27.892,22.829Q297.187,389.16,297.186,460C297.186,507.229,312.47,547.06,343.037,578.354Zm115.476,46.66a187.178,187.178,0,0,0,27.28-1.94V486.346H474.548V295.666c-5.236-.426-10.567-.677-16.035-.677a177.387,177.387,0,0,0-40.029,4.4V486.346H407.239v131.4A175.161,175.161,0,0,0,458.513,625.014Z\"\n"
        "      fill=\"#fff\" />\n"
        "  </g>\n"
        "</svg>\n";
    static constexpr const char* cmaj_api_cmajaudioworklethelper_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import { PatchConnection } from \"./cmaj-patch-connection.js\"\n"
        "\n"
        "//==============================================================================\n"
        "// N.B. code will be serialised to a string, so all `registerWorkletProcessor`s\n"
        "// dependencies must be self contained and not capture things in the outer scope\n"
        "async function serialiseWorkletProcessorFactoryToDataURI (CmajorClass, workletName, hostDescription)\n"
        "{\n"
        "    const serialisedInvocation = `(${registerWorkletProcessor.toString()}) (\"${workletName}\", ${CmajorClass.toString()}, \"${hostDescription}\");`\n"
        "\n"
        "    let reader = new FileReader();\n"
        "    reader.readAsDataURL (new Blob ([serialisedInvocation], { type: \"text/javascript\" }));\n"
        "\n"
        "    return await new Promise (res => { reader.onloadend = () => res (reader.result); });\n"
        "}\n"
        "\n"
        "function registerWorkletProcessor (workletName, CmajorClass, hostDescription)\n"
        "{\n"
        "    function makeConsumeOutputEvents ({ wrapper, eventOutputs, dispatchOutputEvent })\n"
        "    {\n"
        "        const outputEventHandlers = eventOutputs.map (({ endpointID }) =>\n"
        "        {\n"
        "            const readCount = wrapper[`getOutputEventCount_${endpointID}`]?.bind (wrapper);\n"
        "            const reset = wrapper[`resetOutputEventCount_${endpointID}`]?.bind (wrapper);\n"
        "            const readEventAtIndex = wrapper[`getOutputEvent_${endpointID}`]?.bind (wrapper);\n"
        "\n"
        "            return () =>\n"
        "            {\n"
        "                const count = readCount();\n"
        "\n"
        "                for (let i = 0; i < count; ++i)\n"
        "                    dispatchOutputEvent (endpointID, readEventAtIndex (i));\n"
        "\n"
        "                reset();\n"
        "            };\n"
        "        });\n"
        "\n"
        "        return () => outputEventHandlers.forEach ((consume) => consume() );\n"
        "    }\n"
        "\n"
        "    function setInitialParameterValues (parametersMap)\n"
        "    {\n"
        "        for (const { initialise } of Object.values (parametersMap))\n"
        "            initialise();\n"
        "    }\n"
        "\n"
        "    function makeEndpointMap (wrapper, endpoints, initialValueOverrides)\n"
        "    {\n"
        "        const toKey = ({ endpointType, endpointID }) =>\n"
        "        {\n"
        "            switch (endpointType)\n"
        "            {\n"
        "                case \"event\": return `sendInputEvent_${endpointID}`;\n"
        "                case \"value\": return `setInputValue_${endpointID}`;\n"
        "            }\n"
        "\n"
        "            throw \"Unhandled endpoint type\";\n"
        "        };\n"
        "\n"
        "        const lookup = {};\n"
        "\n"
        "        for (const { endpointID, endpointType, annotation, purpose } of endpoints)\n"
        "        {\n"
        "            const key = toKey ({ endpointType, endpointID });\n"
        "            const wrapperUpdate = wrapper[key]?.bind (wrapper);\n"
        "\n"
        "            const snapAndConstrainValue = (value) =>\n"
        "            {\n"
        "                if (annotation.step != null)\n"
        "                    value = Math.round (value / annotation.step) * annotation.step;\n"
        "\n"
        "                if (annotation.min != null && annotation.max != null)\n"
        "                    value = Math.min (Math.max (value, annotation.min), annotation.max);\n"
        "\n"
        "                return value;\n"
        "            };\n"
        "\n"
        "            const update = (value, rampFrames) =>\n"
        "            {\n"
        "                // N.B. value clamping and rampFrames from annotations not currently applied\n"
        "                const entry = lookup[endpointID];\n"
        "                entry.cachedValue = value;\n"
        "                wrapperUpdate (value, rampFrames);\n"
        "            };\n"
        "\n"
        "            if (update)\n"
        "            {\n"
        "                const initialValue = initialValueOverrides[endpointID] ?\? annotation?.init;\n"
        "\n"
        "                lookup[endpointID] = {\n"
        "                    snapAndConstrainValue,\n"
        "                    update,\n"
        "                    initialise: initialValue != null ? () => update (initialValue) : () => {},\n"
        "                    purpose,\n"
        "                    cachedValue: undefined,\n"
        "                };\n"
        "            }\n"
        "        }\n"
        "\n"
        "        return lookup;\n"
        "    }\n"
        "\n"
        "    function makeStreamEndpointHandler ({ wrapper, toEndpoints, wrapperMethodNamePrefix })\n"
        "    {\n"
        "        const endpoints = toEndpoints (wrapper);\n"
        "        if (endpoints.length === 0)\n"
        "            return () => {};\n"
        "\n"
        "        let handlers = [];\n"
        "        let targetChannels = [];\n"
        "        let channelCount = 0;\n"
        "\n"
        "        for (const endpoint of endpoints)\n"
        "        {\n"
        "            const handleFrames = wrapper[`${wrapperMethodNamePrefix}_${endpoint.endpointID}`]?.bind (wrapper);\n"
        "\n"
        "            if (! handleFrames)\n"
        "                return () => {};\n"
        "\n"
        "            handlers.push (handleFrames);\n"
        "            targetChannels.push (channelCount);\n"
        "            channelCount += endpoint.numAudioChannels;\n"
        "        }\n"
        "\n"
        "        return (channels, blockSize) =>\n"
        "        {\n"
        "            for (let i = 0; i < handlers.length; i++)\n"
        "                handlers[i] (channels, blockSize, targetChannels[i]);\n"
        "        }\n"
        "    }\n"
        "\n"
        "    function makeInputStreamEndpointHandler (wrapper)\n"
        "    {\n"
        "        return makeStreamEndpointHandler ({\n"
        "            wrapper,\n"
        "            toEndpoints: wrapper => wrapper.getInputEndpoints().filter (({ purpose }) => purpose === \"audio in\"),\n"
        "            wrapperMethodNamePrefix: \"setInputStreamFrames\",\n"
        "        });\n"
        "    }\n"
        "\n"
        "    function makeOutputStreamEndpointHandler (wrapper)\n"
        "    {\n"
        "        return makeStreamEndpointHandler ({\n"
        "            wrapper,\n"
        "            toEndpoints: wrapper => wrapper.getOutputEndpoints().filter (({ purpose }) => purpose === \"audio out\"),\n"
        "            wrapperMethodNamePrefix: \"getOutputFrames\",\n"
        "        });\n"
        "    }\n"
        "\n"
        "    class WorkletProcessor extends AudioWorkletProcessor\n"
        "    {\n"
        "        static get parameterDescriptors()\n"
        "        {\n"
        "            return [];\n"
        "        }\n"
        "\n"
        "        constructor ({ processorOptions, ...options })\n"
        "        {\n"
        "            super (options);\n"
        "\n"
        "            this.processImpl = undefined;\n"
        "            this.consumeOutputEvents = undefined;\n"
        "\n"
        "            const { sessionID = Date.now() & 0x7fffffff, initialValueOverrides = {} } = processorOptions;\n"
        "\n"
        "            const wrapper = new CmajorClass();\n"
        "\n"
        "            wrapper.initialise (sessionID, sampleRate)\n"
        "                .then (() => this.initialisePatch (wrapper, initialValueOverrides))\n"
        "                .catch (error => { throw new Error (error)});\n"
        "        }\n"
        "\n"
        "        process (inputs, outputs)\n"
        "        {\n"
        "            const input = inputs[0];\n"
        "            const output = outputs[0];\n"
        "\n"
        "            this.processImpl?.(input, output);\n"
        "            this.consumeOutputEvents?.();\n"
        "\n"
        "            return true;\n"
        "        }\n"
        "\n"
        "        sendPatchMessage (payload)\n"
        "        {\n"
        "            this.port.postMessage ({ type: \"patch\", payload });\n"
        "        }\n"
        "\n"
        "        sendParameterValueChanged (endpointID, value)\n"
        "        {\n"
        "            this.sendPatchMessage ({\n"
        "                type: \"param_value\",\n"
        "                message: { endpointID, value }\n"
        "            });\n"
        "        }\n"
        "\n"
        "        initialisePatch (wrapper, initialValueOverrides)\n"
        "        {\n"
        "            try\n"
        "            {\n"
        "                const inputParameters = wrapper.getInputEndpoints().filter (({ purpose }) => purpose === \"parameter\");\n"
        "                const parametersMap = makeEndpointMap (wrapper, inputParameters, initialValueOverrides);\n"
        "\n"
        "                setInitialParameterValues (parametersMap);\n"
        "\n"
        "                const toParameterValuesWithKey = (endpointKey, parametersMap) =>\n"
        "                {\n"
        "                    const toValue = ([endpoint, { cachedValue }]) => ({ [endpointKey]: endpoint, value: cachedValue });\n"
        "                    return Object.entries (parametersMap).map (toValue);\n"
        "                };\n"
        "\n"
        "                const initialValues = toParameterValuesWithKey (\"endpointID\", parametersMap);\n"
        "                const initialState = wrapper.getState();\n"
        "\n"
        "                const resetState = () =>\n"
        "                {\n"
        "                    wrapper.restoreState (initialState);\n"
        "\n"
        "                    // N.B. update cache used for `req_param_value` messages (we don't currently read from the wasm heap)\n"
        "                    setInitialParameterValues (parametersMap);\n"
        "                };\n"
        "\n"
        "                const isNonAudioOrParameterEndpoint = ({ purpose }) => ! [\"audio in\", \"parameter\"].includes (purpose);\n"
        "                const otherInputs = wrapper.getInputEndpoints().filter (isNonAudioOrParameterEndpoint);\n"
        "                const otherInputEndpointsMap = makeEndpointMap (wrapper, otherInputs, initialValueOverrides);\n"
        "\n"
        "                const isEvent = ({ endpointType }) => endpointType === \"event\";\n"
        "                const eventInputs = wrapper.getInputEndpoints().filter (isEvent);\n"
        "                const eventOutputs = wrapper.getOutputEndpoints().filter (isEvent);\n"
        "\n"
        "                const makeEndpointListenerMap = (eventEndpoints) =>\n"
        "                {\n"
        "                    const listeners = {};\n"
        "\n"
        "                    for (const { endpointID } of eventEndpoints)\n"
        "                        listeners[endpointID] = [];\n"
        "\n"
        "                    return listeners;\n"
        "                };\n"
        "\n"
        "                const inputEventListeners = makeEndpointListenerMap (eventInputs);\n"
        "                const outputEventListeners = makeEndpointListenerMap (eventOutputs);\n"
        "\n"
        "                this.consumeOutputEvents = makeConsumeOutputEvents ({\n"
        "                    eventOutputs,\n"
        "                    wrapper,\n"
        "                    dispatchOutputEvent: (endpointID, event) =>\n"
        "                    {\n"
        "                        for (const { replyType } of outputEventListeners[endpointID] ?\? [])\n"
        "                        {\n"
        "                            this.sendPatchMessage ({\n"
        "                                type: replyType,\n"
        "                                message: event.event, // N.B. chucking away frame and typeIndex info for now\n"
        "                            });\n"
        "                        }\n"
        "                    },\n"
        "                });\n"
        "\n"
        "                const blockSize = 128;\n"
        "                const prepareInputFrames = makeInputStreamEndpointHandler (wrapper);\n"
        "                const processOutputFrames = makeOutputStreamEndpointHandler (wrapper);\n"
        "\n"
        "                this.processImpl = (input, output) =>\n"
        "                {\n"
        "                    prepareInputFrames (input, blockSize);\n"
        "                    wrapper.advance (blockSize);\n"
        "                    processOutputFrames (output, blockSize);\n"
        "                };\n"
        "\n"
        "                // N.B. the message port makes things straightforward, but it allocates (when sending + receiving).\n"
        "                // so, we aren't doing ourselves any favours. we probably ought to marshal raw bytes over to the gui in\n"
        "                // a pre-allocated lock-free message queue (using `SharedArrayBuffer` + `Atomic`s) and transform the raw\n"
        "                // messages there.\n"
        "                this.port.addEventListener (\"message\", e =>\n"
        "                {\n"
        "                    if (e.data.type !== \"patch\")\n"
        "                        return;\n"
        "\n"
        "                    const msg = e.data.payload;\n"
        "\n"
        "                    switch (msg.type)\n"
        "                    {\n"
        "                        case \"req_status\":\n"
        "                        {\n"
        "                            this.sendPatchMessage ({\n"
        "                                type: \"status\",\n"
        "                                message: {\n"
        "                                    details: {\n"
        "                                        inputs: wrapper.getInputEndpoints(),\n"
        "                                        outputs: wrapper.getOutputEndpoints(),\n"
        "                                    },\n"
        "                                    sampleRate,\n"
        "                                    host: hostDescription ? hostDescription : \"WebAudio\"\n"
        "                                },\n"
        "                            });\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"req_reset\":\n"
        "                        {\n"
        "                            resetState();\n"
        "                            initialValues.forEach (v => this.sendParameterValueChanged (v.endpointID, v.value));\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"req_param_value\":\n"
        "                        {\n"
        "                            // N.B. keep a local cache here so that we can send the values back when requested.\n"
        "                            // we could instead have accessors into the wasm heap.\n"
        "                            const endpointID = msg.id;\n"
        "                            const parameter = parametersMap[endpointID];\n"
        "                            if (! parameter)\n"
        "                                return;\n"
        "\n"
        "                            const value = parameter.cachedValue;\n"
        "                            this.sendParameterValueChanged (endpointID, value);\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"send_value\":\n"
        "                        {\n"
        "                            const endpointID = msg.id;\n"
        "                            const parameter = parametersMap[endpointID];\n"
        "\n"
        "                            if (parameter)\n"
        "                            {\n"
        "                                const newValue = parameter.snapAndConstrainValue (msg.value);\n"
        "                                parameter.update (newValue, msg.rampFrames);\n"
        "\n"
        "                                this.sendParameterValueChanged (endpointID, newValue);\n"
        "                                return;\n"
        "                            }\n"
        "\n"
        "                            const inputEndpoint = otherInputEndpointsMap[endpointID];\n"
        "\n"
        "                            if (inputEndpoint)\n"
        "                            {\n"
        "                                inputEndpoint.update (msg.value);\n"
        "\n"
        "                                for (const { replyType } of inputEventListeners[endpointID] ?\? [])\n"
        "                                {\n"
        "                                    this.sendPatchMessage ({\n"
        "                                        type: replyType,\n"
        "                                        message: inputEndpoint.cachedValue,\n"
        "                                    });\n"
        "                                }\n"
        "                            }\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"send_gesture_start\": break;\n"
        "                        case \"send_gesture_end\": break;\n"
        "\n"
        "                        case \"req_full_state\":\n"
        "                            this.sendPatchMessage ({\n"
        "                                type: msg?.replyType,\n"
        "                                message: {\n"
        "                                    parameters: toParameterValuesWithKey (\"name\", parametersMap),\n"
        "                                },\n"
        "                            });\n"
        "                            break;\n"
        "\n"
        "                        case \"send_full_state\":\n"
        "                        {\n"
        "                            const { parameters = [] } = e.data.payload?.value || [];\n"
        "\n"
        "                            for (const [endpointID, parameter] of Object.entries (parametersMap))\n"
        "                            {\n"
        "                                const namedNextValue = parameters.find (({ name }) => name === endpointID);\n"
        "\n"
        "                                if (namedNextValue)\n"
        "                                    parameter.update (namedNextValue.value);\n"
        "                                else\n"
        "                                    parameter.initialise();\n"
        "\n"
        "                                this.sendParameterValueChanged (endpointID, parameter.cachedValue);\n"
        "                            }\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"add_endpoint_listener\":\n"
        "                        {\n"
        "                            const insertIfValidEndpoint = (lookup, msg) =>\n"
        "                            {\n"
        "                                const endpointID = msg?.endpoint;\n"
        "                                const listeners = lookup[endpointID]\n"
        "\n"
        "                                if (! listeners)\n"
        "                                    return false;\n"
        "\n"
        "                                return listeners.push ({ replyType: msg?.replyType }) > 0;\n"
        "                            };\n"
        "\n"
        "                            if (! insertIfValidEndpoint (inputEventListeners, msg))\n"
        "                                insertIfValidEndpoint (outputEventListeners, msg)\n"
        "\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"remove_endpoint_listener\":\n"
        "                        {\n"
        "                            const removeIfValidReplyType = (lookup, msg) =>\n"
        "                            {\n"
        "                                const endpointID = msg?.endpoint;\n"
        "                                const listeners = lookup[endpointID];\n"
        "\n"
        "                                if (! listeners)\n"
        "                                    return false;\n"
        "\n"
        "                                const index = listeners.indexOf (msg?.replyType);\n"
        "\n"
        "                                if (index === -1)\n"
        "                                    return false;\n"
        "\n"
        "                                return listeners.splice (index, 1).length === 1;\n"
        "                            };\n"
        "\n"
        "                            if (! removeIfValidReplyType (inputEventListeners, msg))\n"
        "                                removeIfValidReplyType (outputEventListeners, msg)\n"
        "\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        default:\n"
        "                            break;\n"
        "                    }\n"
        "                });\n"
        "\n"
        "                this.port.postMessage ({ type: \"initialised\" });\n"
        "                this.port.start();\n"
        "            }\n"
        "            catch (e)\n"
        "            {\n"
        "                this.port.postMessage (e.toString());\n"
        "            }\n"
        "        }\n"
        "    }\n"
        "\n"
        "    registerProcessor (workletName, WorkletProcessor);\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "async function connectToAudioIn (audioContext, node)\n"
        "{\n"
        "    try\n"
        "    {\n"
        "        const input = await navigator.mediaDevices.getUserMedia ({\n"
        "            audio: {\n"
        "                echoCancellation: false,\n"
        "                noiseSuppression: false,\n"
        "                autoGainControl:  false,\n"
        "        }});\n"
        "\n"
        "        if (! input)\n"
        "            throw new Error();\n"
        "\n"
        "        const source = audioContext.createMediaStreamSource (input);\n"
        "\n"
        "        if (! source)\n"
        "            throw new Error();\n"
        "\n"
        "        source.connect (node);\n"
        "    }\n"
        "    catch (e)\n"
        "    {\n"
        "        console.warn (`Could not open audio input`);\n"
        "    }\n"
        "}\n"
        "\n"
        "async function connectToMIDI (connection, midiEndpointID)\n"
        "{\n"
        "    try\n"
        "    {\n"
        "        if (! navigator.requestMIDIAccess)\n"
        "            throw new Error (\"Web MIDI API not supported.\");\n"
        "\n"
        "        const midiAccess = await navigator.requestMIDIAccess ({ sysex: true, software: true });\n"
        "\n"
        "        for (const input of midiAccess.inputs.values())\n"
        "        {\n"
        "            input.onmidimessage = ({ data }) =>\n"
        "                connection.sendMIDIInputEvent (midiEndpointID, data[2] | (data[1] << 8) | (data[0] << 16));\n"
        "        }\n"
        "    }\n"
        "    catch (e)\n"
        "    {\n"
        "        console.warn (`Could not open MIDI devices: ${e}`);\n"
        "    }\n"
        "}\n"
        "\n"
        "\n"
        "//==============================================================================\n"
        "/**  This class provides a PatchConnection that controls a Cmajor audio worklet\n"
        " *   node.\n"
        " */\n"
        "export class AudioWorkletPatchConnection extends PatchConnection\n"
        "{\n"
        "    constructor (manifest)\n"
        "    {\n"
        "        super();\n"
        "\n"
        "        this.manifest = manifest;\n"
        "        this.cachedState = {};\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /**  Initialises this connection to load and control the given Cmajor class.\n"
        "     *\n"
        "     *   @param {Object} parameters - the parameters to use\n"
        "     *   @param {Object} parameters.CmajorClass - the generated Cmajor class\n"
        "     *   @param {AudioContext} parameters.audioContext - a web audio AudioContext object\n"
        "     *   @param {string} parameters.workletName - the name to give the new worklet that is created\n"
        "     *   @param {string} parameters.hostDescription - a description of the host that is using the patch\n"
        "     *   @param {number} [parameters.sessionID] - an integer to use for the session ID, or undefined to use a default\n"
        "     *   @param {Object} [parameters.initialValueOverrides] - optional initial values for parameter endpoints\n"
        "     *   @param {string} [parameters.rootResourcePath] - optionally, a root to use when resolving resource paths\n"
        "     */\n"
        "    async initialise ({ CmajorClass,\n"
        "                        audioContext,\n"
        "                        workletName,\n"
        "                        hostDescription,\n"
        "                        sessionID,\n"
        "                        initialValueOverrides,\n"
        "                        rootResourcePath })\n"
        "    {\n"
        "        this.audioContext = audioContext;\n"
        "\n"
        "        if (rootResourcePath)\n"
        "        {\n"
        "            this.rootResourcePath = rootResourcePath.toString();\n"
        "\n"
        "            if (! this.rootResourcePath.endsWith (\"/\"))\n"
        "                this.rootResourcePath += \"/\";\n"
        "        }\n"
        "        else\n"
        "        {\n"
        "            const getBaseUrl = (relativeURL) =>\n"
        "            {\n"
        "                const baseURL = relativeURL.href.substring(0, relativeURL.href.lastIndexOf('/'));\n"
        "                return baseURL;\n"
        "            };\n"
        "\n"
        "            this.rootResourcePath = getBaseUrl(new URL('.', import.meta.url));\n"
        "\n"
        "            if (! this.rootResourcePath.endsWith (\"/\"))\n"
        "                this.rootResourcePath += \"/../\";\n"
        "        }\n"
        "\n"
        "        const dataURI = await serialiseWorkletProcessorFactoryToDataURI (CmajorClass, workletName, hostDescription);\n"
        "        await audioContext.audioWorklet.addModule (dataURI);\n"
        "\n"
        "        this.inputEndpoints = CmajorClass.prototype.getInputEndpoints();\n"
        "        this.outputEndpoints = CmajorClass.prototype.getOutputEndpoints();\n"
        "\n"
        "        const audioInputEndpoints  = this.inputEndpoints.filter (({ purpose }) => purpose === \"audio in\");\n"
        "        const audioOutputEndpoints = this.outputEndpoints.filter (({ purpose }) => purpose === \"audio out\");\n"
        "\n"
        "        let inputChannelCount = 0;\n"
        "        let outputChannelCount = 0;\n"
        "\n"
        "        audioInputEndpoints.forEach  ((endpoint) => { inputChannelCount = inputChannelCount + endpoint.numAudioChannels; });\n"
        "        audioOutputEndpoints.forEach ((endpoint) => { outputChannelCount = outputChannelCount + endpoint.numAudioChannels; });\n"
        "\n"
        "        const hasInput = inputChannelCount > 0;\n"
        "        const hasOutput = outputChannelCount > 0;\n"
        "\n"
        "        const node = new AudioWorkletNode (audioContext, workletName, {\n"
        "            numberOfInputs: +hasInput,\n"
        "            numberOfOutputs: +hasOutput,\n"
        "            channelCountMode: \"explicit\",\n"
        "            channelCount: hasInput ? inputChannelCount : undefined,\n"
        "            outputChannelCount: hasOutput ? [outputChannelCount] : [],\n"
        "\n"
        "            processorOptions:\n"
        "            {\n"
        "                sessionID,\n"
        "                initialValueOverrides\n"
        "            }\n"
        "        });\n"
        "\n"
        "        const waitUntilWorkletInitialised = async () =>\n"
        "        {\n"
        "            return new Promise ((resolve) =>\n"
        "            {\n"
        "                const filterForInitialised = (e) =>\n"
        "                {\n"
        "                    if (e.data.type === \"initialised\")\n"
        "                    {\n"
        "                        node.port.removeEventListener (\"message\", filterForInitialised);\n"
        "                        resolve();\n"
        "                    }\n"
        "                };\n"
        "\n"
        "                node.port.addEventListener (\"message\", filterForInitialised);\n"
        "            });\n"
        "        };\n"
        "\n"
        "        node.port.start();\n"
        "\n"
        "        await waitUntilWorkletInitialised();\n"
        "\n"
        "        this.audioNode = node;\n"
        "\n"
        "        node.port.addEventListener (\"message\", e =>\n"
        "        {\n"
        "            if (e.data.type === \"patch\")\n"
        "            {\n"
        "                const msg = e.data.payload;\n"
        "\n"
        "                if (msg?.type === \"status\")\n"
        "                    msg.message = { manifest: this.manifest, ...msg.message };\n"
        "\n"
        "                this.deliverMessageFromServer (msg)\n"
        "            }\n"
        "        });\n"
        "\n"
        "        await this.startPatchWorker();\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /**  Attempts to connect this connection to the default audio and MIDI channels.\n"
        "     *   This must only be called once initialise() has completed successfully.\n"
        "     *\n"
        "     *   @param {AudioContext} audioContext - a web audio AudioContext object\n"
        "     */\n"
        "    async connectDefaultAudioAndMIDI (audioContext)\n"
        "    {\n"
        "        if (! this.audioNode)\n"
        "            throw new Error (\"AudioWorkletPatchConnection.initialise() must have been successfully completed before calling connectDefaultAudioAndMIDI()\");\n"
        "\n"
        "        const getInputWithPurpose = (purpose) =>\n"
        "        {\n"
        "            for (const i of this.inputEndpoints)\n"
        "                if (i.purpose === purpose)\n"
        "                    return i.endpointID;\n"
        "        }\n"
        "\n"
        "        const midiEndpointID = getInputWithPurpose (\"midi in\");\n"
        "\n"
        "        if (midiEndpointID)\n"
        "            connectToMIDI (this, midiEndpointID);\n"
        "\n"
        "        if (getInputWithPurpose (\"audio in\"))\n"
        "            connectToAudioIn (audioContext, this.audioNode);\n"
        "\n"
        "        this.audioNode.connect (audioContext.destination);\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    sendMessageToServer (msg)\n"
        "    {\n"
        "        this.audioNode.port.postMessage ({ type: \"patch\", payload: msg });\n"
        "    }\n"
        "\n"
        "    requestStoredStateValue (key)\n"
        "    {\n"
        "        this.dispatchEvent (\"state_key_value\", { key, value: this.cachedState[key] });\n"
        "    }\n"
        "\n"
        "    sendStoredStateValue (key, newValue)\n"
        "    {\n"
        "        const changed = this.cachedState[key] != newValue;\n"
        "\n"
        "        if (changed)\n"
        "        {\n"
        "            const shouldRemove = newValue == null;\n"
        "            if (shouldRemove)\n"
        "            {\n"
        "                delete this.cachedState[key];\n"
        "                return;\n"
        "            }\n"
        "\n"
        "            this.cachedState[key] = newValue;\n"
        "            // N.B. notifying the client only when updating matches behaviour of the patch player\n"
        "            this.dispatchEvent (\"state_key_value\", { key, value: newValue });\n"
        "        }\n"
        "    }\n"
        "\n"
        "    sendFullStoredState (fullState)\n"
        "    {\n"
        "        const currentStateCleared = (() =>\n"
        "        {\n"
        "            const out = {};\n"
        "            Object.keys (this.cachedState).forEach (k => out[k] = undefined);\n"
        "            return out;\n"
        "        })();\n"
        "\n"
        "        const incomingStateValues = fullState.values ?\? {};\n"
        "        const nextStateValues = { ...currentStateCleared, ...incomingStateValues };\n"
        "\n"
        "        Object.entries (nextStateValues).forEach (([key, value]) => this.sendStoredStateValue (key, value));\n"
        "\n"
        "        // N.B. worklet will handle the `parameters` part\n"
        "        super.sendFullStoredState (fullState);\n"
        "    }\n"
        "\n"
        "    requestFullStoredState (callback)\n"
        "    {\n"
        "        // N.B. the worklet only handles the `parameters` part, so we patch the key-value state in here\n"
        "        super.requestFullStoredState (msg => callback ({ values: { ...this.cachedState }, ...msg }));\n"
        "    }\n"
        "\n"
        "    getResourceAddress (path)\n"
        "    {\n"
        "        return this.rootResourcePath + path;\n"
        "    }\n"
        "\n"
        "    async readResource (path)\n"
        "    {\n"
        "        return fetch (path);\n"
        "    }\n"
        "\n"
        "    async readResourceAsAudioData (path)\n"
        "    {\n"
        "        const response = await this.readResource (path);\n"
        "        const buffer = await this.audioContext.decodeAudioData (await response.arrayBuffer());\n"
        "\n"
        "        let frames = [];\n"
        "\n"
        "        for (let i = 0; i < buffer.length; ++i)\n"
        "            frames.push ([]);\n"
        "\n"
        "        for (let chan = 0; chan < buffer.numberOfChannels; ++chan)\n"
        "        {\n"
        "            const src = buffer.getChannelData (chan);\n"
        "\n"
        "            for (let i = 0; i < buffer.length; ++i)\n"
        "                frames[i].push (src[i]);\n"
        "        }\n"
        "\n"
        "        return { frames, sampleRate: buffer.sampleRate };\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** @private */\n"
        "    async startPatchWorker()\n"
        "    {\n"
        "        if (this.manifest.worker?.length > 0)\n"
        "        {\n"
        "            const module = await import (this.getResourceAddress (this.manifest.worker));\n"
        "            module.default (this);\n"
        "        }\n"
        "    }\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajeventlistenerlist_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "\n"
        "/** This event listener management class allows listeners to be attached and\n"
        " *  removed from named event types.\n"
        " */\n"
        "export class EventListenerList\n"
        "{\n"
        "    constructor()\n"
        "    {\n"
        "        this.listenersPerType = {};\n"
        "    }\n"
        "\n"
        "    /** Adds a listener for a specifc event type.\n"
        "     *  If the listener is already registered, this will simply add it again.\n"
        "     *  Each call to addEventListener() must be paired with a removeventListener()\n"
        "     *  call to remove it.\n"
        "     *\n"
        "     *  @param {string} type\n"
        "     */\n"
        "    addEventListener (type, listener)\n"
        "    {\n"
        "        if (type && listener)\n"
        "        {\n"
        "            const list = this.listenersPerType[type];\n"
        "\n"
        "            if (list)\n"
        "                list.push (listener);\n"
        "            else\n"
        "                this.listenersPerType[type] = [listener];\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** Removes a listener that was previously added for the given event type.\n"
        "     *  @param {string} type\n"
        "     */\n"
        "    removeEventListener (type, listener)\n"
        "    {\n"
        "        if (type && listener)\n"
        "        {\n"
        "            const list = this.listenersPerType[type];\n"
        "\n"
        "            if (list)\n"
        "            {\n"
        "                const i = list.indexOf (listener);\n"
        "\n"
        "                if (i >= 0)\n"
        "                    list.splice (i, 1);\n"
        "            }\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** Attaches a callback function that will be automatically unregistered\n"
        "     *  the first time it is invoked.\n"
        "     *\n"
        "     *  @param {string} type\n"
        "     */\n"
        "    addSingleUseListener (type, listener)\n"
        "    {\n"
        "        const l = message =>\n"
        "        {\n"
        "            this.removeEventListener (type, l);\n"
        "            listener?.(message);\n"
        "        };\n"
        "\n"
        "        this.addEventListener (type, l);\n"
        "    }\n"
        "\n"
        "    /** Synchronously dispatches an event object to all listeners\n"
        "     *  that are registered for the given type.\n"
        "     *\n"
        "     *  @param {string} type\n"
        "     */\n"
        "    dispatchEvent (type, event)\n"
        "    {\n"
        "        const list = this.listenersPerType[type];\n"
        "\n"
        "        if (list)\n"
        "            for (const listener of list)\n"
        "                listener?.(event);\n"
        "    }\n"
        "\n"
        "    /** Returns the number of listeners that are currently registered\n"
        "     *  for the given type of event.\n"
        "     *\n"
        "     *  @param {string} type\n"
        "     */\n"
        "    getNumListenersForType (type)\n"
        "    {\n"
        "        const list = this.listenersPerType[type];\n"
        "        return list ? list.length : 0;\n"
        "    }\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajgenericpatchview_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import * as Controls from \"./cmaj-parameter-controls.js\"\n"
        "\n"
        "//==============================================================================\n"
        "/** A simple, generic view which can control any type of patch */\n"
        "class GenericPatchView extends HTMLElement\n"
        "{\n"
        "    /** Creates a view for a patch.\n"
        "     *  @param {PatchConnection} patchConnection - the connection to the target patch\n"
        "     */\n"
        "    constructor (patchConnection)\n"
        "    {\n"
        "        super();\n"
        "\n"
        "        this.patchConnection = patchConnection;\n"
        "\n"
        "        this.statusListener = status =>\n"
        "        {\n"
        "            this.status = status;\n"
        "            this.createControlElements();\n"
        "        };\n"
        "\n"
        "        this.attachShadow ({ mode: \"open\" });\n"
        "        this.shadowRoot.innerHTML = this.getHTML();\n"
        "\n"
        "        this.titleElement      = this.shadowRoot.querySelector (\"cmaj-generic-patch-title\");\n"
        "        this.parametersElement = this.shadowRoot.querySelector (\"cmaj-generic-patch-parameters\");\n"
        "    }\n"
        "\n"
        "    /** This is picked up by some of our wrapper code to know whether it makes\n"
        "     *  sense to put a title bar/logo above the GUI.\n"
        "     */\n"
        "    hasOwnTitleBar()\n"
        "    {\n"
        "        return true;\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** @private */\n"
        "    connectedCallback()\n"
        "    {\n"
        "        this.patchConnection.addStatusListener (this.statusListener);\n"
        "        this.patchConnection.requestStatusUpdate();\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    disconnectedCallback()\n"
        "    {\n"
        "        this.patchConnection.removeStatusListener (this.statusListener);\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    createControlElements()\n"
        "    {\n"
        "        this.parametersElement.innerHTML = \"\";\n"
        "        this.titleElement.innerText = this.status?.manifest?.name ?\? \"Cmajor\";\n"
        "\n"
        "        if (this.status?.details?.inputs)\n"
        "        {\n"
        "            for (const endpointInfo of this.status.details.inputs)\n"
        "            {\n"
        "                if (! endpointInfo.annotation?.hidden)\n"
        "                {\n"
        "                    const control = Controls.createLabelledControl (this.patchConnection, endpointInfo);\n"
        "\n"
        "                    if (control)\n"
        "                        this.parametersElement.appendChild (control);\n"
        "                }\n"
        "            }\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    getHTML()\n"
        "    {\n"
        "        const baseUrl = import.meta.url;\n"
        "\n"
        "        return `\n"
        "            <style>\n"
        "            * {\n"
        "                box-sizing: border-box;\n"
        "                user-select: none;\n"
        "                -webkit-user-select: none;\n"
        "                -moz-user-select: none;\n"
        "                -ms-user-select: none;\n"
        "                font-family: Avenir, 'Avenir Next LT Pro', Montserrat, Corbel, 'URW Gothic', source-sans-pro, sans-serif;\n"
        "                font-size: 0.9rem;\n"
        "            }\n"
        "\n"
        "            :host {\n"
        "                --header-height: 2.5rem;\n"
        "                --foreground: #ffffff;\n"
        "                --background: #1a1a1a;\n"
        "\n"
        "                display: block;\n"
        "                height: 100%;\n"
        "                background-color: var(--background);\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-main {\n"
        "                background: var(--background);\n"
        "                height: 100%;\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-header {\n"
        "                width: 100%;\n"
        "                height: var(--header-height);\n"
        "                border-bottom: 0.1rem solid var(--foreground);\n"
        "                display: flex;\n"
        "                justify-content: space-between;\n"
        "                align-items: center;\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-title {\n"
        "                color: var(--foreground);\n"
        "                text-overflow: ellipsis;\n"
        "                white-space: nowrap;\n"
        "                overflow: hidden;\n"
        "                cursor: default;\n"
        "                font-size: 140%;\n"
        "                font-weight: bold;\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-logo {\n"
        "                flex: 1;\n"
        "                height: 80%;\n"
        "                margin-left: 0.3rem;\n"
        "                margin-right: 0.3rem;\n"
        "                background-color: var(--foreground);\n"
        "                mask: url(${baseUrl}/../assets/cmajor-logo.svg);\n"
        "                mask-repeat: no-repeat;\n"
        "                -webkit-mask: url(${baseUrl}/../assets/cmajor-logo.svg);\n"
        "                -webkit-mask-repeat: no-repeat;\n"
        "                min-width: 6.25rem;\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-padding {\n"
        "                flex: 1;\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-parameters {\n"
        "                display: flex;\n"
        "                flex-flow: row wrap;\n"
        "                justify-content: center;\n"
        "                height: calc(100% - var(--header-height));\n"
        "                overflow: auto;\n"
        "                padding: 1rem;\n"
        "                text-align: center;\n"
        "            }\n"
        "\n"
        "            ${Controls.getAllCSS()}\n"
        "\n"
        "            </style>\n"
        "\n"
        "            <cmaj-generic-patch-main>\n"
        "              <cmaj-generic-patch-header>\n"
        "                <cmaj-generic-patch-logo></cmaj-generic-patch-logo>\n"
        "                <cmaj-generic-patch-title></cmaj-generic-patch-title>\n"
        "                <cmaj-generic-patch-padding></cmaj-generic-patch-padding>\n"
        "              </cmaj-generic-patch-header>\n"
        "              <cmaj-generic-patch-parameters></cmaj-generic-patch-parameters>\n"
        "            </cmaj-generic-patch-main>`;\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Creates a generic view element which can be used to control any patch.\n"
        " *  @param {PatchConnection} patchConnection - the connection to the target patch\n"
        " */\n"
        "export default function createPatchView (patchConnection)\n"
        "{\n"
        "    const genericPatchViewName = \"cmaj-generic-patch-view\";\n"
        "\n"
        "    if (! window.customElements.get (genericPatchViewName))\n"
        "        window.customElements.define (genericPatchViewName, GenericPatchView);\n"
        "\n"
        "    return new (window.customElements.get (genericPatchViewName)) (patchConnection);\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajmidihelpers_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "\n"
        "export function getByte0 (message)     { return (message >> 16) & 0xff; }\n"
        "export function getByte1 (message)     { return (message >> 8) & 0xff; }\n"
        "export function getByte2 (message)     { return message & 0xff; }\n"
        "\n"
        "function isVoiceMessage (message, type)     { return ((message >> 16) & 0xf0) == type; }\n"
        "function get14BitValue (message)            { return getByte1 (message) | (getByte2 (message) << 7); }\n"
        "\n"
        "export function getChannel0to15 (message)   { return getByte0 (message) & 0x0f; }\n"
        "export function getChannel1to16 (message)   { return getChannel0to15 (message) + 1; }\n"
        "\n"
        "export function getMessageSize (message)\n"
        "{\n"
        "    const mainGroupLengths = (3 << 0) | (3 << 2) | (3 << 4) | (3 << 6)\n"
        "                           | (2 << 8) | (2 << 10) | (3 << 12);\n"
        "\n"
        "    const lastGroupLengths = (1 <<  0) | (2 <<  2) | (3 <<  4) | (2 <<  6)\n"
        "                           | (1 <<  8) | (1 << 10) | (1 << 12) | (1 << 14)\n"
        "                           | (1 << 16) | (1 << 18) | (1 << 20) | (1 << 22)\n"
        "                           | (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30);\n"
        "\n"
        "    const firstByte = getByte0 (message);\n"
        "    const group = (firstByte >> 4) & 7;\n"
        "\n"
        "    return (group != 7 ? (mainGroupLengths >> (2 * group))\n"
        "                       : (lastGroupLengths >> (2 * (firstByte & 15)))) & 3;\n"
        "}\n"
        "\n"
        "export function isNoteOn  (message)                         { return isVoiceMessage (message, 0x90) && getVelocity (message) != 0; }\n"
        "export function isNoteOff (message)                         { return isVoiceMessage (message, 0x80) || (isVoiceMessage (message, 0x90) && getVelocity (message) == 0); }\n"
        "\n"
        "export function getNoteNumber (message)                     { return getByte1 (message); }\n"
        "export function getVelocity (message)                       { return getByte2 (message); }\n"
        "\n"
        "export function isProgramChange (message)                   { return isVoiceMessage (message, 0xc0); }\n"
        "export function getProgramChangeNumber (message)            { return getByte1 (message); }\n"
        "export function isPitchWheel (message)                      { return isVoiceMessage (message, 0xe0); }\n"
        "export function getPitchWheelValue (message)                { return get14BitValue (message); }\n"
        "export function isAftertouch (message)                      { return isVoiceMessage (message, 0xa0); }\n"
        "export function getAfterTouchValue (message)                { return getByte2 (message); }\n"
        "export function isChannelPressure (message)                 { return isVoiceMessage (message, 0xd0); }\n"
        "export function getChannelPressureValue (message)           { return getByte1 (message); }\n"
        "export function isController (message)                      { return isVoiceMessage (message, 0xb0); }\n"
        "export function getControllerNumber (message)               { return getByte1 (message); }\n"
        "export function getControllerValue (message)                { return getByte2 (message); }\n"
        "export function isControllerNumber (message, number)        { return getByte1 (message) == number && isController (message); }\n"
        "export function isAllNotesOff (message)                     { return isControllerNumber (message, 123); }\n"
        "export function isAllSoundOff (message)                     { return isControllerNumber (message, 120); }\n"
        "export function isQuarterFrame (message)                    { return getByte0 (message) == 0xf1; }\n"
        "export function isClock (message)                           { return getByte0 (message) == 0xf8; }\n"
        "export function isStart (message)                           { return getByte0 (message) == 0xfa; }\n"
        "export function isContinue (message)                        { return getByte0 (message) == 0xfb; }\n"
        "export function isStop (message)                            { return getByte0 (message) == 0xfc; }\n"
        "export function isActiveSense (message)                     { return getByte0 (message) == 0xfe; }\n"
        "export function isMetaEvent (message)                       { return getByte0 (message) == 0xff; }\n"
        "export function isSongPositionPointer (message)             { return getByte0 (message) == 0xf2; }\n"
        "export function getSongPositionPointerValue (message)       { return get14BitValue (message); }\n"
        "\n"
        "export function getChromaticScaleIndex (note)               { return (note % 12) & 0xf; }\n"
        "export function getOctaveNumber (note, octaveForMiddleC)    { return ((Math.floor (note / 12) + (octaveForMiddleC ? octaveForMiddleC : 3)) & 0xff) - 5; }\n"
        "export function getNoteName (note)                          { const names = [\"C\", \"C#\", \"D\", \"Eb\", \"E\", \"F\", \"F#\", \"G\", \"G#\", \"A\", \"Bb\", \"B\"]; return names[getChromaticScaleIndex (note)]; }\n"
        "export function getNoteNameWithSharps (note)                { const names = [\"C\", \"C#\", \"D\", \"Eb\", \"E\", \"F\", \"F#\", \"G\", \"G#\", \"A\", \"Bb\", \"B\"]; return names[getChromaticScaleIndex (note)]; }\n"
        "export function getNoteNameWithFlats (note)                 { const names = [\"C\", \"Db\", \"D\", \"Eb\", \"E\", \"F\", \"Gb\", \"G\", \"Ab\", \"A\", \"Bb\", \"B\"]; return names[getChromaticScaleIndex (note)]; }\n"
        "export function getNoteNameWithOctaveNumber (note)          { return getNoteName (note) + getOctaveNumber (note); }\n"
        "export function isNatural (note)                            { const nats = [true, false, true, false, true, true, false, true, false, true, false, true]; return nats[getChromaticScaleIndex (note)]; }\n"
        "export function isAccidental (note)                         { return ! isNatural (note); }\n"
        "\n"
        "export function printHexMIDIData (message)\n"
        "{\n"
        "    const numBytes = getMessageSize (message);\n"
        "\n"
        "    if (numBytes == 0)\n"
        "        return \"[empty]\";\n"
        "\n"
        "    let s = \"\";\n"
        "\n"
        "    for (let i = 0; i < numBytes; ++i)\n"
        "    {\n"
        "        if (i != 0)  s += ' ';\n"
        "\n"
        "        const byte = message >> (16 - 8 * i) & 0xff;\n"
        "        s += \"0123456789abcdef\"[byte >> 4];\n"
        "        s += \"0123456789abcdef\"[byte & 15];\n"
        "    }\n"
        "\n"
        "    return s;\n"
        "}\n"
        "\n"
        "export function getMIDIDescription (message)\n"
        "{\n"
        "    const channelText = \" Channel \" + getChannel1to16 (message);\n"
        "    function getNote (m)   { const s = getNoteNameWithOctaveNumber (getNoteNumber (message)); return s.length < 4 ? s + \" \" : s; };\n"
        "\n"
        "    if (isNoteOn (message))                return \"Note-On:  \"   + getNote (message) + channelText + \"  Velocity \" + getVelocity (message);\n"
        "    if (isNoteOff (message))               return \"Note-Off: \"   + getNote (message) + channelText + \"  Velocity \" + getVelocity (message);\n"
        "    if (isAftertouch (message))            return \"Aftertouch: \" + getNote (message) + channelText +  \": \" + getAfterTouchValue (message);\n"
        "    if (isPitchWheel (message))            return \"Pitch wheel: \" + getPitchWheelValue (message) + ' ' + channelText;\n"
        "    if (isChannelPressure (message))       return \"Channel pressure: \" + getChannelPressureValue (message) + ' ' + channelText;\n"
        "    if (isController (message))            return \"Controller:\" + channelText + \": \" + getControllerName (getControllerNumber (message)) + \" = \" + getControllerValue (message);\n"
        "    if (isProgramChange (message))         return \"Program change: \" + getProgramChangeNumber (message) + ' ' + channelText;\n"
        "    if (isAllNotesOff (message))           return \"All notes off:\" + channelText;\n"
        "    if (isAllSoundOff (message))           return \"All sound off:\" + channelText;\n"
        "    if (isQuarterFrame (message))          return \"Quarter-frame\";\n"
        "    if (isClock (message))                 return \"Clock\";\n"
        "    if (isStart (message))                 return \"Start\";\n"
        "    if (isContinue (message))              return \"Continue\";\n"
        "    if (isStop (message))                  return \"Stop\";\n"
        "    if (isMetaEvent (message))             return \"Meta-event: type \" + getByte1 (message);\n"
        "    if (isSongPositionPointer (message))   return \"Song Position: \" + getSongPositionPointerValue (message);\n"
        "\n"
        "    return printHexMIDIData (message);\n"
        "}\n"
        "\n"
        "export function getControllerName (controllerNumber)\n"
        "{\n"
        "    if (controllerNumber < 128)\n"
        "    {\n"
        "        const controllerNames = [\n"
        "            \"Bank Select\",                  \"Modulation Wheel (coarse)\",      \"Breath controller (coarse)\",       undefined,\n"
        "            \"Foot Pedal (coarse)\",          \"Portamento Time (coarse)\",       \"Data Entry (coarse)\",              \"Volume (coarse)\",\n"
        "            \"Balance (coarse)\",             undefined,                        \"Pan position (coarse)\",            \"Expression (coarse)\",\n"
        "            \"Effect Control 1 (coarse)\",    \"Effect Control 2 (coarse)\",      undefined,                          undefined,\n"
        "            \"General Purpose Slider 1\",     \"General Purpose Slider 2\",       \"General Purpose Slider 3\",         \"General Purpose Slider 4\",\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            \"Bank Select (fine)\",           \"Modulation Wheel (fine)\",        \"Breath controller (fine)\",         undefined,\n"
        "            \"Foot Pedal (fine)\",            \"Portamento Time (fine)\",         \"Data Entry (fine)\",                \"Volume (fine)\",\n"
        "            \"Balance (fine)\",               undefined,                        \"Pan position (fine)\",              \"Expression (fine)\",\n"
        "            \"Effect Control 1 (fine)\",      \"Effect Control 2 (fine)\",        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            \"Hold Pedal\",                   \"Portamento\",                     \"Sustenuto Pedal\",                  \"Soft Pedal\",\n"
        "            \"Legato Pedal\",                 \"Hold 2 Pedal\",                   \"Sound Variation\",                  \"Sound Timbre\",\n"
        "            \"Sound Release Time\",           \"Sound Attack Time\",              \"Sound Brightness\",                 \"Sound Control 6\",\n"
        "            \"Sound Control 7\",              \"Sound Control 8\",                \"Sound Control 9\",                  \"Sound Control 10\",\n"
        "            \"General Purpose Button 1\",     \"General Purpose Button 2\",       \"General Purpose Button 3\",         \"General Purpose Button 4\",\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          \"Reverb Level\",\n"
        "            \"Tremolo Level\",                \"Chorus Level\",                   \"Celeste Level\",                    \"Phaser Level\",\n"
        "            \"Data Button increment\",        \"Data Button decrement\",          \"Non-registered Parameter (fine)\",  \"Non-registered Parameter (coarse)\",\n"
        "            \"Registered Parameter (fine)\",  \"Registered Parameter (coarse)\",  undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            \"All Sound Off\",                \"All Controllers Off\",            \"Local Keyboard\",                   \"All Notes Off\",\n"
        "            \"Omni Mode Off\",                \"Omni Mode On\",                   \"Mono Operation\",                   \"Poly Operation\"\n"
        "        ];\n"
        "\n"
        "        const name = controllerNames[controllerNumber];\n"
        "\n"
        "        if (name)\n"
        "            return name;\n"
        "    }\n"
        "\n"
        "    return controllerNumber.toString();\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajparametercontrols_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import { PatchConnection } from \"./cmaj-patch-connection.js\";\n"
        "\n"
        "\n"
        "//==============================================================================\n"
        "/** A base class for parameter controls, which automatically connects to a\n"
        " *  PatchConnection to monitor a parameter and provides methods to modify it.\n"
        " */\n"
        "export class ParameterControlBase  extends HTMLElement\n"
        "{\n"
        "    constructor()\n"
        "    {\n"
        "        super();\n"
        "\n"
        "        // prevent any clicks from focusing on this element\n"
        "        this.onmousedown = e => e.stopPropagation();\n"
        "    }\n"
        "\n"
        "    /** Attaches the control to a given PatchConnection and endpoint.\n"
        "     *\n"
        "     * @param {PatchConnection} patchConnection - the connection to connect to, or pass\n"
        "     *                                            undefined to disconnect the control.\n"
        "     * @param {Object} endpointInfo - the endpoint details, as provided by a PatchConnection\n"
        "     *                                in its status callback.\n"
        "     */\n"
        "    setEndpoint (patchConnection, endpointInfo)\n"
        "    {\n"
        "        this.detachListener();\n"
        "\n"
        "        this.patchConnection = patchConnection;\n"
        "        this.endpointInfo = endpointInfo;\n"
        "        this.defaultValue = endpointInfo.annotation?.init || endpointInfo.defaultValue || 0;\n"
        "\n"
        "        if (this.isConnected)\n"
        "            this.attachListener();\n"
        "    }\n"
        "\n"
        "    /** Override this method in a child class, and it will be called when the parameter value changes,\n"
        "     *  so you can update the GUI appropriately.\n"
        "     */\n"
        "    valueChanged (newValue) {}\n"
        "\n"
        "    /** Your GUI can call this when it wants to change the parameter value. */\n"
        "    setValue (value)     { this.patchConnection?.sendEventOrValue (this.endpointInfo.endpointID, value); }\n"
        "\n"
        "    /** Call this before your GUI begins a modification gesture.\n"
        "     *  You might for example call this if the user begins a mouse-drag operation.\n"
        "     */\n"
        "    beginGesture()       { this.patchConnection?.sendParameterGestureStart (this.endpointInfo.endpointID); }\n"
        "\n"
        "    /** Call this after your GUI finishes a modification gesture */\n"
        "    endGesture()         { this.patchConnection?.sendParameterGestureEnd (this.endpointInfo.endpointID); }\n"
        "\n"
        "    /** This calls setValue(), but sandwiches it between some start/end gesture calls.\n"
        "     *  You should use this to make sure a DAW correctly records automatiion for individual value changes\n"
        "     *  that are not part of a gesture.\n"
        "     */\n"
        "    setValueAsGesture (value)\n"
        "    {\n"
        "        this.beginGesture();\n"
        "        this.setValue (value);\n"
        "        this.endGesture();\n"
        "    }\n"
        "\n"
        "    /** Resets the parameter to its default value */\n"
        "    resetToDefault()\n"
        "    {\n"
        "        if (this.defaultValue !== null)\n"
        "            this.setValueAsGesture (this.defaultValue);\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** @private */\n"
        "    connectedCallback()\n"
        "    {\n"
        "        this.attachListener();\n"
        "    }\n"
        "\n"
        "    /** @protected */\n"
        "    disconnectedCallback()\n"
        "    {\n"
        "        this.detachListener();\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    detachListener()\n"
        "    {\n"
        "        if (this.listener)\n"
        "        {\n"
        "            this.patchConnection?.removeParameterListener?.(this.listener.endpointID, this.listener);\n"
        "            this.listener = undefined;\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    attachListener()\n"
        "    {\n"
        "        if (this.patchConnection && this.endpointInfo)\n"
        "        {\n"
        "            this.detachListener();\n"
        "\n"
        "            this.listener = newValue => this.valueChanged (newValue);\n"
        "            this.listener.endpointID = this.endpointInfo.endpointID;\n"
        "\n"
        "            this.patchConnection.addParameterListener (this.endpointInfo.endpointID, this.listener);\n"
        "            this.patchConnection.requestParameterValue (this.endpointInfo.endpointID);\n"
        "        }\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** A simple rotary parameter knob control. */\n"
        "export class Knob  extends ParameterControlBase\n"
        "{\n"
        "    constructor (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super();\n"
        "        this.setEndpoint (patchConnection, endpointInfo);\n"
        "    }\n"
        "\n"
        "    setEndpoint (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super.setEndpoint (patchConnection, endpointInfo);\n"
        "\n"
        "        this.innerHTML = \"\";\n"
        "        this.className = \"knob-container\";\n"
        "        const min = endpointInfo?.annotation?.min || 0;\n"
        "        const max = endpointInfo?.annotation?.max || 1;\n"
        "        const mid = endpointInfo?.annotation?.mid || undefined;\n"
        "\n"
        "        const createSvgElement = tag => window.document.createElementNS (\"http://www.w3.org/2000/svg\", tag);\n"
        "\n"
        "        const svg = createSvgElement (\"svg\");\n"
        "        svg.setAttribute (\"viewBox\", \"0 0 100 100\");\n"
        "\n"
        "        const trackBackground = createSvgElement (\"path\");\n"
        "        trackBackground.setAttribute (\"d\", \"M20,76 A 40 40 0 1 1 80 76\");\n"
        "        trackBackground.classList.add (\"knob-path\");\n"
        "        trackBackground.classList.add (\"knob-track-background\");\n"
        "\n"
        "        const maxKnobRotation = 132;\n"
        "        const isBipolar = min + max === 0;\n"
        "        const dashLength = isBipolar ? 251.5 : 184;\n"
        "        const valueOffset = isBipolar ? 0 : 132;\n"
        "        this.getDashOffset = val => dashLength - 184 / (maxKnobRotation * 2) * (val + valueOffset);\n"
        "\n"
        "        this.trackValue = createSvgElement (\"path\");\n"
        "\n"
        "        this.trackValue.setAttribute (\"d\", isBipolar ? \"M50.01,10 A 40 40 0 1 1 50 10\"\n"
        "                                                     : \"M20,76 A 40 40 0 1 1 80 76\");\n"
        "        this.trackValue.setAttribute (\"stroke-dasharray\", dashLength);\n"
        "        this.trackValue.classList.add (\"knob-path\");\n"
        "        this.trackValue.classList.add (\"knob-track-value\");\n"
        "\n"
        "        this.dial = document.createElement (\"div\");\n"
        "        this.dial.className = \"knob-dial\";\n"
        "\n"
        "        const dialTick = document.createElement (\"div\");\n"
        "        dialTick.className = \"knob-dial-tick\";\n"
        "        this.dial.appendChild (dialTick);\n"
        "\n"
        "        svg.appendChild (trackBackground);\n"
        "        svg.appendChild (this.trackValue);\n"
        "\n"
        "        this.appendChild (svg);\n"
        "        this.appendChild (this.dial);\n"
        "\n"
        "        const remap = (source, sourceFrom, sourceTo, targetFrom, targetTo) =>\n"
        "                        (targetFrom + (source - sourceFrom) * (targetTo - targetFrom) / (sourceTo - sourceFrom));\n"
        "\n"
        "        const toValue = (knobRotation) =>\n"
        "        {\n"
        "            if (mid > min && mid < max)\n"
        "            {\n"
        "                const normalisedKnob = remap (knobRotation, -maxKnobRotation, maxKnobRotation, 0, 1);\n"
        "                const range = max - min;\n"
        "                const power = Math.log ((mid - min) / (range)) / Math.log (0.5);\n"
        "\n"
        "                return min + range * Math.pow (normalisedKnob, power);\n"
        "            }\n"
        "            else\n"
        "            {\n"
        "                return remap (knobRotation, -maxKnobRotation, maxKnobRotation, min, max);\n"
        "            }\n"
        "        };\n"
        "\n"
        "        this.toRotation = (value) =>\n"
        "        {\n"
        "            if (mid > min && mid < max)\n"
        "            {\n"
        "                const range = max - min;\n"
        "                const power = Math.log ((mid - min) / (range)) / Math.log (0.5);\n"
        "\n"
        "                const normalisedKnob = Math.pow ((value - min) / range, 1 / power);\n"
        "\n"
        "                return remap (normalisedKnob, 0, 1, -maxKnobRotation, maxKnobRotation);\n"
        "            }\n"
        "            else\n"
        "            {\n"
        "                return remap (value, min, max, -maxKnobRotation, maxKnobRotation);\n"
        "            }\n"
        "        };\n"
        "\n"
        "        this.rotation = this.toRotation (this.defaultValue);\n"
        "        this.setRotation (this.rotation, true);\n"
        "\n"
        "        const onMouseMove = (event) =>\n"
        "        {\n"
        "            event.preventDefault(); // avoid scrolling whilst dragging\n"
        "\n"
        "            const nextRotation = (rotation, delta) =>\n"
        "            {\n"
        "                const clamp = (v, min, max) => Math.min (Math.max (v, min), max);\n"
        "                return clamp (rotation - delta, -maxKnobRotation, maxKnobRotation);\n"
        "            };\n"
        "\n"
        "            const workaroundBrowserIncorrectlyCalculatingMovementY = event.movementY === event.screenY;\n"
        "            const movementY = workaroundBrowserIncorrectlyCalculatingMovementY ? event.screenY - this.previousScreenY\n"
        "                                                                               : event.movementY;\n"
        "            this.previousScreenY = event.screenY;\n"
        "\n"
        "            const speedMultiplier = event.shiftKey ? 0.25 : 1.5;\n"
        "            this.accumulatedRotation = nextRotation (this.accumulatedRotation, movementY * speedMultiplier);\n"
        "            this.setValue (toValue (this.accumulatedRotation));\n"
        "        };\n"
        "\n"
        "        const onMouseUp = (event) =>\n"
        "        {\n"
        "            this.previousScreenY = undefined;\n"
        "            this.accumulatedRotation = undefined;\n"
        "            window.removeEventListener (\"mousemove\", onMouseMove);\n"
        "            window.removeEventListener (\"mouseup\", onMouseUp);\n"
        "            this.endGesture();\n"
        "        };\n"
        "\n"
        "        const onMouseDown = (event) =>\n"
        "        {\n"
        "            this.previousScreenY = event.screenY;\n"
        "            this.accumulatedRotation = this.rotation;\n"
        "            this.beginGesture();\n"
        "            window.addEventListener (\"mousemove\", onMouseMove);\n"
        "            window.addEventListener (\"mouseup\", onMouseUp);\n"
        "            event.preventDefault();\n"
        "        };\n"
        "\n"
        "        const onTouchStart = (event) =>\n"
        "        {\n"
        "            this.previousClientY = event.changedTouches[0].clientY;\n"
        "            this.accumulatedRotation = this.rotation;\n"
        "            this.touchIdentifier = event.changedTouches[0].identifier;\n"
        "            this.beginGesture();\n"
        "            window.addEventListener (\"touchmove\", onTouchMove);\n"
        "            window.addEventListener (\"touchend\", onTouchEnd);\n"
        "            event.preventDefault();\n"
        "        };\n"
        "\n"
        "        const onTouchMove = (event) =>\n"
        "        {\n"
        "            for (const touch of event.changedTouches)\n"
        "            {\n"
        "                if (touch.identifier == this.touchIdentifier)\n"
        "                {\n"
        "                    const nextRotation = (rotation, delta) =>\n"
        "                    {\n"
        "                        const clamp = (v, min, max) => Math.min (Math.max (v, min), max);\n"
        "                        return clamp (rotation - delta, -maxKnobRotation, maxKnobRotation);\n"
        "                    };\n"
        "\n"
        "                    const movementY = touch.clientY - this.previousClientY;\n"
        "                    this.previousClientY = touch.clientY;\n"
        "\n"
        "                    const speedMultiplier = event.shiftKey ? 0.25 : 1.5;\n"
        "                    this.accumulatedRotation = nextRotation (this.accumulatedRotation, movementY * speedMultiplier);\n"
        "                    this.setValue (toValue (this.accumulatedRotation));\n"
        "                }\n"
        "            }\n"
        "        };\n"
        "\n"
        "        const onTouchEnd = (event) =>\n"
        "        {\n"
        "            this.previousClientY = undefined;\n"
        "            this.accumulatedRotation = undefined;\n"
        "            window.removeEventListener (\"touchmove\", onTouchMove);\n"
        "            window.removeEventListener (\"touchend\", onTouchEnd);\n"
        "            this.endGesture();\n"
        "        };\n"
        "\n"
        "        this.addEventListener (\"mousedown\", onMouseDown);\n"
        "        this.addEventListener (\"dblclick\", () => this.resetToDefault());\n"
        "        this.addEventListener ('touchstart', onTouchStart);\n"
        "    }\n"
        "\n"
        "    /** Returns true if this type of control is suitable for the given endpoint info */\n"
        "    static canBeUsedFor (endpointInfo)\n"
        "    {\n"
        "        return endpointInfo.purpose === \"parameter\";\n"
        "    }\n"
        "\n"
        "    /** @override */\n"
        "    valueChanged (newValue)       { this.setRotation (this.toRotation (newValue), false); }\n"
        "\n"
        "    /** Returns a string version of the given value */\n"
        "    getDisplayValue (v)           { return toFloatDisplayValueWithUnit (v, this.endpointInfo); }\n"
        "\n"
        "    /** @private */\n"
        "    setRotation (degrees, force)\n"
        "    {\n"
        "        if (force || this.rotation !== degrees)\n"
        "        {\n"
        "            this.rotation = degrees;\n"
        "            this.trackValue.setAttribute (\"stroke-dashoffset\", this.getDashOffset (this.rotation));\n"
        "            this.dial.style.transform = `translate(-50%,-50%) rotate(${degrees}deg)`;\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    static getCSS()\n"
        "    {\n"
        "        return `\n"
        "        .knob-container {\n"
        "            --knob-track-background-color: var(--background);\n"
        "            --knob-track-value-color: var(--foreground);\n"
        "\n"
        "            --knob-dial-border-color: var(--foreground);\n"
        "            --knob-dial-background-color: var(--background);\n"
        "            --knob-dial-tick-color: var(--foreground);\n"
        "\n"
        "            position: relative;\n"
        "            display: inline-block;\n"
        "            height: 5rem;\n"
        "            width: 5rem;\n"
        "            margin: 0;\n"
        "            padding: 0;\n"
        "        }\n"
        "\n"
        "        .knob-path {\n"
        "            fill: none;\n"
        "            stroke-linecap: round;\n"
        "            stroke-width: 0.15rem;\n"
        "        }\n"
        "\n"
        "        .knob-track-background {\n"
        "            stroke: var(--knob-track-background-color);\n"
        "        }\n"
        "\n"
        "        .knob-track-value {\n"
        "            stroke: var(--knob-track-value-color);\n"
        "        }\n"
        "\n"
        "        .knob-dial {\n"
        "            position: absolute;\n"
        "            text-align: center;\n"
        "            height: 60%;\n"
        "            width: 60%;\n"
        "            top: 50%;\n"
        "            left: 50%;\n"
        "            border: 0.15rem solid var(--knob-dial-border-color);\n"
        "            border-radius: 100%;\n"
        "            box-sizing: border-box;\n"
        "            transform: translate(-50%,-50%);\n"
        "            background-color: var(--knob-dial-background-color);\n"
        "        }\n"
        "\n"
        "        .knob-dial-tick {\n"
        "            position: absolute;\n"
        "            display: inline-block;\n"
        "\n"
        "            height: 1rem;\n"
        "            width: 0.15rem;\n"
        "            background-color: var(--knob-dial-tick-color);\n"
        "        }`;\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** A boolean switch control */\n"
        "export class Switch  extends ParameterControlBase\n"
        "{\n"
        "    constructor (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super();\n"
        "        this.setEndpoint (patchConnection, endpointInfo);\n"
        "    }\n"
        "\n"
        "    setEndpoint (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super.setEndpoint (patchConnection, endpointInfo);\n"
        "\n"
        "        const outer = document.createElement (\"div\");\n"
        "        outer.classList = \"switch-outline\";\n"
        "\n"
        "        const inner = document.createElement (\"div\");\n"
        "        inner.classList = \"switch-thumb\";\n"
        "\n"
        "        this.innerHTML = \"\";\n"
        "        this.currentValue = this.defaultValue > 0.5;\n"
        "        this.valueChanged (this.currentValue);\n"
        "        this.classList.add (\"switch-container\");\n"
        "\n"
        "        outer.appendChild (inner);\n"
        "        this.appendChild (outer);\n"
        "        this.addEventListener (\"click\", () => this.setValueAsGesture (this.currentValue ? 0 : 1.0));\n"
        "    }\n"
        "\n"
        "    /** Returns true if this type of control is suitable for the given endpoint info */\n"
        "    static canBeUsedFor (endpointInfo)\n"
        "    {\n"
        "        return endpointInfo.purpose === \"parameter\"\n"
        "                && endpointInfo.annotation?.boolean;\n"
        "    }\n"
        "\n"
        "    /** @override */\n"
        "    valueChanged (newValue)\n"
        "    {\n"
        "        const b = newValue > 0.5;\n"
        "        this.currentValue = b;\n"
        "        this.classList.remove (! b ? \"switch-on\" : \"switch-off\");\n"
        "        this.classList.add (b ? \"switch-on\" : \"switch-off\");\n"
        "    }\n"
        "\n"
        "    /** Returns a string version of the given value */\n"
        "    getDisplayValue (v)   { return `${v > 0.5 ? \"On\" : \"Off\"}`; }\n"
        "\n"
        "    /** @private */\n"
        "    static getCSS()\n"
        "    {\n"
        "        return `\n"
        "        .switch-container {\n"
        "            --switch-outline-color: var(--foreground);\n"
        "            --switch-thumb-color: var(--foreground);\n"
        "            --switch-on-background-color: var(--background);\n"
        "            --switch-off-background-color: var(--background);\n"
        "\n"
        "            position: relative;\n"
        "            display: flex;\n"
        "            align-items: center;\n"
        "            justify-content: center;\n"
        "            height: 100%;\n"
        "            width: 100%;\n"
        "            margin: 0;\n"
        "            padding: 0;\n"
        "        }\n"
        "\n"
        "        .switch-outline {\n"
        "            position: relative;\n"
        "            display: inline-block;\n"
        "            height: 1.5rem;\n"
        "            width: 2.5rem;\n"
        "            border-radius: 1rem;\n"
        "            border: var(--switch-outline-color) solid 0.15rem;\n"
        "            transition: background-color 0.1s cubic-bezier(0.5, 0, 0.2, 1);\n"
        "        }\n"
        "\n"
        "        .switch-thumb {\n"
        "            position: absolute;\n"
        "            top: 50%;\n"
        "            left: 50%;\n"
        "            transform: translate(-50%,-50%);\n"
        "            height: 0.9rem;\n"
        "            width:  0.9rem;\n"
        "            background-color: var(--switch-thumb-color);\n"
        "            border-radius: 100%;\n"
        "            transition: left 0.1s cubic-bezier(0.5, 0, 0.2, 1);\n"
        "        }\n"
        "\n"
        "        .switch-off .switch-thumb {\n"
        "            left: 25%;\n"
        "            background: none;\n"
        "            border: var(--switch-thumb-color) solid 0.1rem;\n"
        "            height: 0.8rem;\n"
        "            width: 0.8rem;\n"
        "        }\n"
        "        .switch-on .switch-thumb {\n"
        "            left: 75%;\n"
        "        }\n"
        "\n"
        "        .switch-off .switch-outline {\n"
        "            background-color: var(--switch-on-background-color);\n"
        "        }\n"
        "        .switch-on .switch-outline {\n"
        "            background-color: var(--switch-off-background-color);\n"
        "        }`;\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "function toFloatDisplayValueWithUnit (v, endpointInfo)\n"
        "{\n"
        "    return `${v.toFixed (2)} ${endpointInfo.annotation?.unit ?\? \"\"}`;\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** A control that allows an item to be selected from a drop-down list of options */\n"
        "export class Options  extends ParameterControlBase\n"
        "{\n"
        "    constructor (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super();\n"
        "        this.setEndpoint (patchConnection, endpointInfo);\n"
        "    }\n"
        "\n"
        "    setEndpoint (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super.setEndpoint (patchConnection, endpointInfo);\n"
        "\n"
        "        const toValue = (min, step, index) => min + (step * index);\n"
        "        const toStepCount = count => count > 0 ? count - 1 : 1;\n"
        "\n"
        "        const { min, max, options } = (() =>\n"
        "        {\n"
        "            if (Options.hasTextOptions (endpointInfo))\n"
        "            {\n"
        "                const optionList = endpointInfo.annotation.text.split (\"|\");\n"
        "                const stepCount = toStepCount (optionList.length);\n"
        "                let min = 0, max = stepCount, step = 1;\n"
        "\n"
        "                if (endpointInfo.annotation.min != null && endpointInfo.annotation.max != null)\n"
        "                {\n"
        "                    min = endpointInfo.annotation.min;\n"
        "                    max = endpointInfo.annotation.max;\n"
        "                    step = (max - min) / stepCount;\n"
        "                }\n"
        "\n"
        "                const options = optionList.map ((text, index) => ({ value: toValue (min, step, index), text }));\n"
        "\n"
        "                return { min, max, options };\n"
        "            }\n"
        "\n"
        "            if (Options.isExplicitlyDiscrete (endpointInfo))\n"
        "            {\n"
        "                const step = endpointInfo.annotation.step;\n"
        "\n"
        "                const min = endpointInfo.annotation?.min || 0;\n"
        "                const max = endpointInfo.annotation?.max || 1;\n"
        "\n"
        "                const numDiscreteOptions = (((max - min) / step) | 0) + 1;\n"
        "\n"
        "                const options = new Array (numDiscreteOptions);\n"
        "                for (let i = 0; i < numDiscreteOptions; ++i)\n"
        "                {\n"
        "                    const value = toValue (min, step, i);\n"
        "                    options[i] = { value, text: toFloatDisplayValueWithUnit (value, endpointInfo) };\n"
        "                }\n"
        "\n"
        "                return { min, max, options };\n"
        "            }\n"
        "        })();\n"
        "\n"
        "        this.options = options;\n"
        "\n"
        "        const stepCount = toStepCount (this.options.length);\n"
        "        const normalise = value => (value - min) / (max - min);\n"
        "        this.toIndex = value => Math.min (stepCount, normalise (value) * this.options.length) | 0;\n"
        "\n"
        "        this.innerHTML = \"\";\n"
        "\n"
        "        this.select = document.createElement (\"select\");\n"
        "\n"
        "        for (const option of this.options)\n"
        "        {\n"
        "            const optionElement = document.createElement (\"option\");\n"
        "            optionElement.innerText = option.text;\n"
        "            this.select.appendChild (optionElement);\n"
        "        }\n"
        "\n"
        "        this.selectedIndex = this.toIndex (this.defaultValue);\n"
        "\n"
        "        this.select.addEventListener (\"change\", (e) =>\n"
        "        {\n"
        "            const newIndex = e.target.selectedIndex;\n"
        "\n"
        "            // prevent local state change. the caller will update us when the backend actually applies the update\n"
        "            e.target.selectedIndex = this.selectedIndex;\n"
        "\n"
        "            this.setValueAsGesture (this.options[newIndex].value)\n"
        "        });\n"
        "\n"
        "        this.valueChanged (this.selectedIndex);\n"
        "\n"
        "        this.className = \"select-container\";\n"
        "        this.appendChild (this.select);\n"
        "\n"
        "        const icon = document.createElement (\"span\");\n"
        "        icon.className = \"select-icon\";\n"
        "        this.appendChild (icon);\n"
        "    }\n"
        "\n"
        "    /** Returns true if this type of control is suitable for the given endpoint info */\n"
        "    static canBeUsedFor (endpointInfo)\n"
        "    {\n"
        "        return endpointInfo.purpose === \"parameter\"\n"
        "                && (this.hasTextOptions (endpointInfo) || this.isExplicitlyDiscrete (endpointInfo));\n"
        "    }\n"
        "\n"
        "    /** @override */\n"
        "    valueChanged (newValue)\n"
        "    {\n"
        "        const index = this.toIndex (newValue);\n"
        "        this.selectedIndex = index;\n"
        "        this.select.selectedIndex = index;\n"
        "    }\n"
        "\n"
        "    /** Returns a string version of the given value */\n"
        "    getDisplayValue (v)    { return this.options[this.toIndex(v)].text; }\n"
        "\n"
        "    /** @private */\n"
        "    static hasTextOptions (endpointInfo)\n"
        "    {\n"
        "        return endpointInfo.annotation?.text?.split?.(\"|\").length > 1\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    static isExplicitlyDiscrete (endpointInfo)\n"
        "    {\n"
        "        return endpointInfo.annotation?.discrete && endpointInfo.annotation?.step > 0;\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    static getCSS()\n"
        "    {\n"
        "        return `\n"
        "        .select-container {\n"
        "            position: relative;\n"
        "            display: block;\n"
        "            font-size: 0.8rem;\n"
        "            width: 100%;\n"
        "            color: var(--foreground);\n"
        "            border: 0.15rem solid var(--foreground);\n"
        "            border-radius: 0.6rem;\n"
        "            margin: 0;\n"
        "            padding: 0;\n"
        "        }\n"
        "\n"
        "        select {\n"
        "            background: none;\n"
        "            appearance: none;\n"
        "            -webkit-appearance: none;\n"
        "            font-family: inherit;\n"
        "            font-size: 0.8rem;\n"
        "\n"
        "            overflow: hidden;\n"
        "            text-overflow: ellipsis;\n"
        "\n"
        "            padding: 0 1.5rem 0 0.6rem;\n"
        "\n"
        "            outline: none;\n"
        "            color: var(--foreground);\n"
        "            height: 2rem;\n"
        "            box-sizing: border-box;\n"
        "            margin: 0;\n"
        "            border: none;\n"
        "\n"
        "            width: 100%;\n"
        "        }\n"
        "\n"
        "        select option {\n"
        "            background: var(--background);\n"
        "            color: var(--foreground);\n"
        "        }\n"
        "\n"
        "        .select-icon {\n"
        "            position: absolute;\n"
        "            right: 0.3rem;\n"
        "            top: 0.5rem;\n"
        "            pointer-events: none;\n"
        "            background-color: var(--foreground);\n"
        "            width: 1.4em;\n"
        "            height: 1.4em;\n"
        "            mask: url(\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24'%3E%3Cpath d='M17,9.17a1,1,0,0,0-1.41,0L12,12.71,8.46,9.17a1,1,0,0,0-1.41,0,1,1,0,0,0,0,1.42l4.24,4.24a1,1,0,0,0,1.42,0L17,10.59A1,1,0,0,0,17,9.17Z'/%3E%3C/svg%3E\");\n"
        "            mask-repeat: no-repeat;\n"
        "            -webkit-mask: url(\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24'%3E%3Cpath d='M17,9.17a1,1,0,0,0-1.41,0L12,12.71,8.46,9.17a1,1,0,0,0-1.41,0,1,1,0,0,0,0,1.42l4.24,4.24a1,1,0,0,0,1.42,0L17,10.59A1,1,0,0,0,17,9.17Z'/%3E%3C/svg%3E\");\n"
        "            -webkit-mask-repeat: no-repeat;\n"
        "        }`;\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** A control which wraps a child control, adding a label and value display box below it */\n"
        "export class LabelledControlHolder  extends ParameterControlBase\n"
        "{\n"
        "    constructor (patchConnection, endpointInfo, childControl)\n"
        "    {\n"
        "        super();\n"
        "        this.childControl = childControl;\n"
        "        this.setEndpoint (patchConnection, endpointInfo);\n"
        "    }\n"
        "\n"
        "    setEndpoint (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super.setEndpoint (patchConnection, endpointInfo);\n"
        "\n"
        "        this.innerHTML = \"\";\n"
        "        this.className = \"labelled-control\";\n"
        "\n"
        "        const centeredControl = document.createElement (\"div\");\n"
        "        centeredControl.className = \"labelled-control-centered-control\";\n"
        "\n"
        "        centeredControl.appendChild (this.childControl);\n"
        "\n"
        "        const titleValueHoverContainer = document.createElement (\"div\");\n"
        "        titleValueHoverContainer.className = \"labelled-control-label-container\";\n"
        "\n"
        "        const nameText = document.createElement (\"div\");\n"
        "        nameText.classList.add (\"labelled-control-name\");\n"
        "        nameText.innerText = endpointInfo.annotation?.name || endpointInfo.name || endpointInfo.endpointID || \"\";\n"
        "\n"
        "        this.valueText = document.createElement (\"div\");\n"
        "        this.valueText.classList.add (\"labelled-control-value\");\n"
        "\n"
        "        titleValueHoverContainer.appendChild (nameText);\n"
        "        titleValueHoverContainer.appendChild (this.valueText);\n"
        "\n"
        "        this.appendChild (centeredControl);\n"
        "        this.appendChild (titleValueHoverContainer);\n"
        "    }\n"
        "\n"
        "    /** @override */\n"
        "    valueChanged (newValue)\n"
        "    {\n"
        "        this.valueText.innerText = this.childControl?.getDisplayValue (newValue);\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    static getCSS()\n"
        "    {\n"
        "        return `\n"
        "        .labelled-control {\n"
        "            --labelled-control-font-color: var(--foreground);\n"
        "            --labelled-control-font-size: 0.8rem;\n"
        "\n"
        "            position: relative;\n"
        "            display: inline-block;\n"
        "            margin: 0 0.4rem 0.4rem;\n"
        "            vertical-align: top;\n"
        "            text-align: left;\n"
        "            padding: 0;\n"
        "        }\n"
        "\n"
        "        .labelled-control-centered-control {\n"
        "            position: relative;\n"
        "            display: flex;\n"
        "            align-items: center;\n"
        "            justify-content: center;\n"
        "\n"
        "            width: 5.5rem;\n"
        "            height: 5rem;\n"
        "        }\n"
        "\n"
        "        .labelled-control-label-container {\n"
        "            position: relative;\n"
        "            display: block;\n"
        "            max-width: 5.5rem;\n"
        "            margin: -0.4rem auto 0.4rem;\n"
        "            text-align: center;\n"
        "            font-size: var(--labelled-control-font-size);\n"
        "            color: var(--labelled-control-font-color);\n"
        "            cursor: default;\n"
        "        }\n"
        "\n"
        "        .labelled-control-name {\n"
        "            overflow: hidden;\n"
        "            text-overflow: ellipsis;\n"
        "        }\n"
        "\n"
        "        .labelled-control-value {\n"
        "            position: absolute;\n"
        "            top: 0;\n"
        "            left: 0;\n"
        "            right: 0;\n"
        "            overflow: hidden;\n"
        "            text-overflow: ellipsis;\n"
        "            opacity: 0;\n"
        "        }\n"
        "\n"
        "        .labelled-control:hover .labelled-control-name,\n"
        "        .labelled-control:active .labelled-control-name {\n"
        "            opacity: 0;\n"
        "        }\n"
        "        .labelled-control:hover .labelled-control-value,\n"
        "        .labelled-control:active .labelled-control-value {\n"
        "            opacity: 1;\n"
        "        }`;\n"
        "    }\n"
        "}\n"
        "\n"
        "if (! window.customElements.get (\"cmaj-knob-control\"))             window.customElements.define (\"cmaj-knob-control\", Knob);\n"
        "if (! window.customElements.get (\"cmaj-switch-control\"))           window.customElements.define (\"cmaj-switch-control\", Switch);\n"
        "if (! window.customElements.get (\"cmaj-options-control\"))          window.customElements.define (\"cmaj-options-control\", Options);\n"
        "if (! window.customElements.get (\"cmaj-labelled-control-holder\"))  window.customElements.define (\"cmaj-labelled-control-holder\", LabelledControlHolder);\n"
        "\n"
        "\n"
        "//==============================================================================\n"
        "/** Fetches all the CSS for the controls defined in this module */\n"
        "export function getAllCSS()\n"
        "{\n"
        "    return `\n"
        "        ${Options.getCSS()}\n"
        "        ${Knob.getCSS()}\n"
        "        ${Switch.getCSS()}\n"
        "        ${LabelledControlHolder.getCSS()}`;\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Creates a suitable control for the given endpoint.\n"
        " *\n"
        " *  @param {PatchConnection} patchConnection - the connection to connect to\n"
        " *  @param {Object} endpointInfo - the endpoint details, as provided by a PatchConnection\n"
        " *                                 in its status callback.\n"
        "*/\n"
        "export function createControl (patchConnection, endpointInfo)\n"
        "{\n"
        "    if (Switch.canBeUsedFor (endpointInfo))\n"
        "        return new (window.customElements.get (\"cmaj-switch-control\")) (patchConnection, endpointInfo);\n"
        "\n"
        "    if (Options.canBeUsedFor (endpointInfo))\n"
        "        return new (window.customElements.get (\"cmaj-options-control\")) (patchConnection, endpointInfo);\n"
        "\n"
        "    if (Knob.canBeUsedFor (endpointInfo))\n"
        "        return new (window.customElements.get (\"cmaj-knob-control\")) (patchConnection, endpointInfo);\n"
        "\n"
        "    return undefined;\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Creates a suitable labelled control for the given endpoint.\n"
        " *\n"
        " *  @param {PatchConnection} patchConnection - the connection to connect to\n"
        " *  @param {Object} endpointInfo - the endpoint details, as provided by a PatchConnection\n"
        " *                                 in its status callback.\n"
        "*/\n"
        "export function createLabelledControl (patchConnection, endpointInfo)\n"
        "{\n"
        "    const control = createControl (patchConnection, endpointInfo);\n"
        "\n"
        "    if (control)\n"
        "        return new (window.customElements.get (\"cmaj-labelled-control-holder\")) (patchConnection, endpointInfo, control);\n"
        "\n"
        "    return undefined;\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Takes a patch connection and its current status object, and tries to create\n"
        " *  a control for the given endpoint ID.\n"
        " *\n"
        " *  @param {PatchConnection} patchConnection - the connection to connect to\n"
        " *  @param {Object} status - the connection's current status\n"
        " *  @param {string} endpointID - the endpoint you'd like to control\n"
        " */\n"
        "export function createLabelledControlForEndpointID (patchConnection, status, endpointID)\n"
        "{\n"
        "    for (const endpointInfo of status?.details?.inputs)\n"
        "        if (endpointInfo.endpointID == endpointID)\n"
        "            return createLabelledControl (patchConnection, endpointInfo);\n"
        "\n"
        "    return undefined;\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajpatchview_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import { PatchConnection } from \"./cmaj-patch-connection.js\"\n"
        "\n"
        "//==============================================================================\n"
        "/** Returns a list of types of view that can be created for this patch.\n"
        " */\n"
        "export function getAvailableViewTypes (patchConnection)\n"
        "{\n"
        "    if (! patchConnection)\n"
        "        return [];\n"
        "\n"
        "    if (patchConnection.manifest?.view?.src)\n"
        "        return [\"custom\", \"generic\"];\n"
        "\n"
        "    return [\"generic\"];\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Creates and returns a HTMLElement view which can be shown to control this patch.\n"
        " *\n"
        " *  If no preferredType argument is supplied, this will return either a custom patch-specific\n"
        " *  view (if the manifest specifies one), or a generic view if not. The preferredType argument\n"
        " *  can be used to choose one of the types of view returned by getAvailableViewTypes().\n"
        " *\n"
        " *  @param {PatchConnection} patchConnection - the connection to use\n"
        " *  @param {string} preferredType - the name of the type of view to open, e.g. \"generic\"\n"
        " *                                  or the name of one of the views in the manifest\n"
        " *  @returns {HTMLElement} a HTMLElement that can be displayed as the patch GUI\n"
        " */\n"
        "export async function createPatchView (patchConnection, preferredType)\n"
        "{\n"
        "    if (patchConnection?.manifest)\n"
        "    {\n"
        "        let view = patchConnection.manifest.view;\n"
        "\n"
        "        if (view && preferredType === \"generic\")\n"
        "            if (view.src)\n"
        "                view = undefined;\n"
        "\n"
        "        const viewModuleURL = view?.src ? patchConnection.getResourceAddress (view.src) : \"./cmaj-generic-patch-view.js\";\n"
        "        const viewModule = await import (viewModuleURL);\n"
        "        const patchView = await viewModule?.default (patchConnection);\n"
        "\n"
        "        if (patchView)\n"
        "        {\n"
        "            patchView.style.display = \"block\";\n"
        "\n"
        "            if (view?.width > 10)\n"
        "                patchView.style.width = view.width + \"px\";\n"
        "            else\n"
        "                patchView.style.width = undefined;\n"
        "\n"
        "            if (view?.height > 10)\n"
        "                patchView.style.height = view.height + \"px\";\n"
        "            else\n"
        "                patchView.style.height = undefined;\n"
        "\n"
        "            return patchView;\n"
        "        }\n"
        "    }\n"
        "\n"
        "    return undefined;\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** If a patch view declares itself to be scalable, this will attempt to scale it to fit\n"
        " *  into a given parent element.\n"
        " *\n"
        " *  @param {HTMLElement} view - the patch view\n"
        " *  @param {HTMLElement} parentToScale - the patch view's direct parent element, to which\n"
        " *                                       the scale factor will be applied\n"
        " *  @param {HTMLElement} parentContainerToFitTo - an outer parent of the view, whose bounds\n"
        " *                                                the view will be made to fit\n"
        " */\n"
        "export function scalePatchViewToFit (view, parentToScale, parentContainerToFitTo)\n"
        "{\n"
        "    function getClientSize (view)\n"
        "    {\n"
        "        const clientStyle = getComputedStyle (view);\n"
        "\n"
        "        return {\n"
        "            width:  view.clientHeight - parseFloat (clientStyle.paddingTop)  - parseFloat (clientStyle.paddingBottom),\n"
        "            height: view.clientWidth  - parseFloat (clientStyle.paddingLeft) - parseFloat (clientStyle.paddingRight)\n"
        "        };\n"
        "    }\n"
        "\n"
        "    const scaleLimits = view.getScaleFactorLimits?.();\n"
        "\n"
        "    if (scaleLimits && (scaleLimits.minScale || scaleLimits.maxScale) && parentContainerToFitTo)\n"
        "    {\n"
        "        const minScale = scaleLimits.minScale || 0.25;\n"
        "        const maxScale = scaleLimits.maxScale || 5.0;\n"
        "\n"
        "        const targetSize = getClientSize (parentContainerToFitTo);\n"
        "        const clientSize = getClientSize (view);\n"
        "\n"
        "        const scaleW = targetSize.width / clientSize.width;\n"
        "        const scaleH = targetSize.height / clientSize.height;\n"
        "\n"
        "        const scale = Math.min (maxScale, Math.max (minScale, Math.min (scaleW, scaleH)));\n"
        "\n"
        "        parentToScale.style.transform = `scale(${scale})`;\n"
        "    }\n"
        "    else\n"
        "    {\n"
        "        parentToScale.style.transform = \"none\";\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "class PatchViewHolder extends HTMLElement\n"
        "{\n"
        "    constructor (view)\n"
        "    {\n"
        "        super();\n"
        "        this.view = view;\n"
        "        this.style = `display: block; position: relative; width: 100%; height: 100%; overflow: visible; transform-origin: 0% 0%;`;\n"
        "    }\n"
        "\n"
        "    connectedCallback()\n"
        "    {\n"
        "        this.appendChild (this.view);\n"
        "        this.resizeObserver = new ResizeObserver (() => scalePatchViewToFit (this.view, this, this.parentElement));\n"
        "        this.resizeObserver.observe (this.parentElement);\n"
        "        scalePatchViewToFit (this.view, this, this.parentElement);\n"
        "    }\n"
        "\n"
        "    disconnectedCallback()\n"
        "    {\n"
        "        this.resizeObserver = undefined;\n"
        "        this.innerHTML = \"\";\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Creates and returns a HTMLElement view which can be shown to control this patch.\n"
        " *\n"
        " *  Unlike createPatchView(), this will return a holder element that handles scaling\n"
        " *  and resizing, and which follows changes to the size of the parent that you\n"
        " *  append it to.\n"
        " *\n"
        " *  If no preferredType argument is supplied, this will return either a custom patch-specific\n"
        " *  view (if the manifest specifies one), or a generic view if not. The preferredType argument\n"
        " *  can be used to choose one of the types of view returned by getAvailableViewTypes().\n"
        " *\n"
        " *  @param {PatchConnection} patchConnection - the connection to use\n"
        " *  @param {string} preferredType - the name of the type of view to open, e.g. \"generic\"\n"
        " *                                  or the name of one of the views in the manifest\n"
        " *  @returns {HTMLElement} a HTMLElement that can be displayed as the patch GUI\n"
        " */\n"
        "export async function createPatchViewHolder (patchConnection, preferredType)\n"
        "{\n"
        "    const view = await createPatchView (patchConnection, preferredType);\n"
        "\n"
        "    if (view)\n"
        "    {\n"
        "        const patchViewHolderName = \"cmaj-patch-view-holder\";\n"
        "\n"
        "        if (! window.customElements.get (patchViewHolderName)) window.customElements.define (patchViewHolderName, PatchViewHolder);\n"
        "\n"
        "        return new (window.customElements.get (patchViewHolderName)) (view);\n"
        "    }\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajpianokeyboard_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88     The Cmajor Toolkit\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  The Cmajor project is subject to commercial or open-source licensing.\n"
        "//  You may use it under the terms of the GPLv3 (see www.gnu.org/licenses), or\n"
        "//  visit https://cmajor.dev to learn about our commercial licence options.\n"
        "//\n"
        "//  CMAJOR IS PROVIDED \"AS IS\" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER\n"
        "//  EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE\n"
        "//  DISCLAIMED.\n"
        "\n"
        "import * as midi from \"./cmaj-midi-helpers.js\"\n"
        "\n"
        "/**\n"
        " *  An general-purpose on-screen piano keyboard component that allows clicks or\n"
        " *  key-presses to be used to play things.\n"
        " *\n"
        " *  To receive events, you can attach \"note-down\" and \"note-up\" event listeners via\n"
        " *  the standard HTMLElement/EventTarget event system, e.g.\n"
        " *\n"
        " *  myKeyboardElement.addEventListener(\"note-down\", (note) => { ...handle note on... });\n"
        " *  myKeyboardElement.addEventListener(\"note-up\",   (note) => { ...handle note off... });\n"
        " *\n"
        " *  The `note` object will contain a `note` property with the MIDI note number.\n"
        " *  (And obviously you can remove them with removeEventListener)\n"
        " *\n"
        " *  Or, if you're connecting the keyboard to a PatchConnection, you can use the helper\n"
        " *  method attachToPatchConnection() to create and attach some suitable listeners.\n"
        " *\n"
        " */\n"
        "export default class PianoKeyboard extends HTMLElement\n"
        "{\n"
        "    constructor ({ naturalNoteWidth,\n"
        "                   accidentalWidth,\n"
        "                   accidentalPercentageHeight,\n"
        "                   naturalNoteBorder,\n"
        "                   accidentalNoteBorder,\n"
        "                   pressedNoteColour } = {})\n"
        "    {\n"
        "        super();\n"
        "\n"
        "        this.naturalWidth = naturalNoteWidth || 20;\n"
        "        this.accidentalWidth = accidentalWidth || 12;\n"
        "        this.accidentalPercentageHeight = accidentalPercentageHeight || 66;\n"
        "        this.naturalBorder = naturalNoteBorder || \"2px solid #333\";\n"
        "        this.accidentalBorder = accidentalNoteBorder || \"2px solid #333\";\n"
        "        this.pressedColour = pressedNoteColour || \"#8ad\";\n"
        "\n"
        "        this.root = this.attachShadow({ mode: \"open\" });\n"
        "\n"
        "        this.root.addEventListener (\"mousedown\",   (event) => this.handleMouse (event, true, false) );\n"
        "        this.root.addEventListener (\"mouseup\",     (event) => this.handleMouse (event, false, true) );\n"
        "        this.root.addEventListener (\"mousemove\",   (event) => this.handleMouse (event, false, false) );\n"
        "        this.root.addEventListener (\"mouseenter\",  (event) => this.handleMouse (event, false, false) );\n"
        "        this.root.addEventListener (\"mouseout\",    (event) => this.handleMouse (event, false, false) );\n"
        "\n"
        "        this.addEventListener (\"keydown\",  (event) => this.handleKey (event, true));\n"
        "        this.addEventListener (\"keyup\",    (event) => this.handleKey (event, false));\n"
        "        this.addEventListener (\"focusout\", (event) => this.allNotesOff());\n"
        "\n"
        "        this.currentDraggedNote = -1;\n"
        "        this.currentExternalNotesOn = new Set();\n"
        "        this.currentKeyboardNotes = new Set();\n"
        "        this.currentPlayedNotes = new Set();\n"
        "        this.currentDisplayedNotes = new Set();\n"
        "        this.notes = [];\n"
        "        this.modifierKeys = 0;\n"
        "        this.currentTouches = new Map();\n"
        "\n"
        "        this.refreshHTML();\n"
        "\n"
        "        for (let child of this.root.children)\n"
        "        {\n"
        "            child.addEventListener (\"touchstart\", (event) => this.touchStart (event), {passive:false} );\n"
        "            child.addEventListener (\"touchend\",   (event) => this.touchEnd (event) );\n"
        "        }\n"
        "    }\n"
        "\n"
        "    static get observedAttributes()\n"
        "    {\n"
        "        return [\"root-note\", \"note-count\", \"key-map\"];\n"
        "    }\n"
        "\n"
        "    get config()\n"
        "    {\n"
        "        return {\n"
        "            rootNote: parseInt(this.getAttribute(\"root-note\") || \"36\"),\n"
        "            numNotes: parseInt(this.getAttribute(\"note-count\") || \"61\"),\n"
        "            keymap: this.getAttribute(\"key-map\") || \"KeyA KeyW KeyS KeyE KeyD KeyF KeyT KeyG KeyY KeyH KeyU KeyJ KeyK KeyO KeyL KeyP Semicolon\",\n"
        "        };\n"
        "    }\n"
        "\n"
        "    /** This attaches suitable listeners to make this keyboard control the given MIDI\n"
        "     *  endpoint of a PatchConnection object. Use detachPatchConnection() to remove\n"
        "     *  a connection later on.\n"
        "     *\n"
        "     *  @param {PatchConnection} patchConnection\n"
        "     *  @param {string} midiInputEndpointID\n"
        "     */\n"
        "    attachToPatchConnection (patchConnection, midiInputEndpointID)\n"
        "    {\n"
        "        const velocity = 100;\n"
        "\n"
        "        const callbacks = {\n"
        "            noteDown: e => patchConnection.sendMIDIInputEvent (midiInputEndpointID, 0x900000 | (e.detail.note << 8) | velocity),\n"
        "            noteUp:   e => patchConnection.sendMIDIInputEvent (midiInputEndpointID, 0x800000 | (e.detail.note << 8) | velocity),\n"
        "            midiIn:   e => this.handleExternalMIDI (e.message),\n"
        "            midiInputEndpointID\n"
        "        };\n"
        "\n"
        "        if (! this.callbacks)\n"
        "            this.callbacks = new Map();\n"
        "\n"
        "        this.callbacks.set (patchConnection, callbacks);\n"
        "\n"
        "        this.addEventListener (\"note-down\", callbacks.noteDown);\n"
        "        this.addEventListener (\"note-up\",   callbacks.noteUp);\n"
        "        patchConnection.addEndpointListener (midiInputEndpointID, callbacks.midiIn);\n"
        "    }\n"
        "\n"
        "    /** This removes the connection to a PatchConnection object that was previously attached\n"
        "     *  with attachToPatchConnection().\n"
        "     *\n"
        "     *  @param {PatchConnection} patchConnection\n"
        "     */\n"
        "    detachPatchConnection (patchConnection)\n"
        "    {\n"
        "        const callbacks = this.callbacks.get (patchConnection);\n"
        "\n"
        "        if (callbacks)\n"
        "        {\n"
        "            this.removeEventListener (\"note-down\", callbacks.noteDown);\n"
        "            this.removeEventListener (\"note-up\",   callbacks.noteUp);\n"
        "            patchConnection.removeEndpointListener (callbacks.midiInputEndpointID, callbacks.midiIn);\n"
        "        }\n"
        "\n"
        "        this.callbacks[patchConnection] = undefined;\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** Can be overridden to return the color to use for a note index */\n"
        "    getNoteColour (note)    { return undefined; }\n"
        "\n"
        "    /** Can be overridden to return the text label to draw on a note index */\n"
        "    getNoteLabel (note)     { return midi.getChromaticScaleIndex (note) == 0 ? midi.getNoteNameWithOctaveNumber (note) : \"\"; }\n"
        "\n"
        "    /** Clients should call this to deliver a MIDI message, which the keyboard will use to\n"
        "     *  highlight the notes that are currently playing.\n"
        "     */\n"
        "    handleExternalMIDI (message)\n"
        "    {\n"
        "        if (midi.isNoteOn (message))\n"
        "        {\n"
        "            const note = midi.getNoteNumber (message);\n"
        "            this.currentExternalNotesOn.add (note);\n"
        "            this.refreshActiveNoteElements();\n"
        "        }\n"
        "        else if (midi.isNoteOff (message))\n"
        "        {\n"
        "            const note = midi.getNoteNumber (message);\n"
        "            this.currentExternalNotesOn.delete (note);\n"
        "            this.refreshActiveNoteElements();\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** This method will be called when the user plays a note. The default behaviour is\n"
        "     *  to dispath an event, but you could override this if you needed to.\n"
        "    */\n"
        "    sendNoteOn (note)   { this.dispatchEvent (new CustomEvent('note-down', { detail: { note: note }})); }\n"
        "\n"
        "    /** This method will be called when the user releases a note. The default behaviour is\n"
        "     *  to dispath an event, but you could override this if you needed to.\n"
        "    */\n"
        "    sendNoteOff (note)  { this.dispatchEvent (new CustomEvent('note-up',   { detail: { note: note } })); }\n"
        "\n"
        "    /** Clients can call this to force all the notes to turn off, e.g. in a \"panic\". */\n"
        "    allNotesOff()\n"
        "    {\n"
        "        this.setDraggedNote (-1);\n"
        "        this.modifierKeys = 0;\n"
        "\n"
        "        for (let note of this.currentKeyboardNotes.values())\n"
        "            this.removeKeyboardNote (note);\n"
        "\n"
        "        this.currentExternalNotesOn.clear();\n"
        "        this.refreshActiveNoteElements();\n"
        "    }\n"
        "\n"
        "    setDraggedNote (newNote)\n"
        "    {\n"
        "        if (newNote != this.currentDraggedNote)\n"
        "        {\n"
        "            if (this.currentDraggedNote >= 0)\n"
        "                this.sendNoteOff (this.currentDraggedNote);\n"
        "\n"
        "            this.currentDraggedNote = newNote;\n"
        "\n"
        "            if (this.currentDraggedNote >= 0)\n"
        "                this.sendNoteOn (this.currentDraggedNote);\n"
        "\n"
        "            this.refreshActiveNoteElements();\n"
        "        }\n"
        "    }\n"
        "\n"
        "    addKeyboardNote (note)\n"
        "    {\n"
        "        if (! this.currentKeyboardNotes.has (note))\n"
        "        {\n"
        "            this.sendNoteOn (note);\n"
        "            this.currentKeyboardNotes.add (note);\n"
        "            this.refreshActiveNoteElements();\n"
        "        }\n"
        "    }\n"
        "\n"
        "    removeKeyboardNote (note)\n"
        "    {\n"
        "        if (this.currentKeyboardNotes.has (note))\n"
        "        {\n"
        "            this.sendNoteOff (note);\n"
        "            this.currentKeyboardNotes.delete (note);\n"
        "            this.refreshActiveNoteElements();\n"
        "        }\n"
        "    }\n"
        "\n"
        "    isNoteActive (note)\n"
        "    {\n"
        "        return note == this.currentDraggedNote\n"
        "            || this.currentExternalNotesOn.has (note)\n"
        "            || this.currentKeyboardNotes.has (note);\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** @private */\n"
        "    touchEnd (event)\n"
        "    {\n"
        "        for (const touch of event.changedTouches)\n"
        "        {\n"
        "            const note = this.currentTouches.get (touch.identifier);\n"
        "            this.currentTouches.delete (touch.identifier);\n"
        "            this.removeKeyboardNote (note);\n"
        "        }\n"
        "\n"
        "        event.preventDefault();\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    touchStart (event)\n"
        "    {\n"
        "        for (const touch of event.changedTouches)\n"
        "        {\n"
        "            const note = touch.target.id.substring (4);\n"
        "            this.currentTouches.set (touch.identifier, note);\n"
        "            this.addKeyboardNote (note);\n"
        "        }\n"
        "\n"
        "        event.preventDefault();\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    handleMouse (event, isDown, isUp)\n"
        "    {\n"
        "        if (isDown)\n"
        "            this.isDragging = true;\n"
        "\n"
        "        if (this.isDragging)\n"
        "        {\n"
        "            let newActiveNote = -1;\n"
        "\n"
        "            if (event.buttons != 0 && event.type != \"mouseout\")\n"
        "            {\n"
        "                const note = event.target.id.substring (4);\n"
        "\n"
        "                if (note !== undefined)\n"
        "                    newActiveNote = parseInt (note);\n"
        "            }\n"
        "\n"
        "            this.setDraggedNote (newActiveNote);\n"
        "\n"
        "            if (! isDown)\n"
        "                event.preventDefault();\n"
        "        }\n"
        "\n"
        "        if (isUp)\n"
        "            this.isDragging = false;\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    handleKey (event, isDown)\n"
        "    {\n"
        "        if (event.key == \"Meta\" || event.key == \"Alt\" || event.key == \"Control\" || event.key == \"Shift\")\n"
        "        {\n"
        "            this.modifierKeys += isDown ? 1 : -1;\n"
        "            return;\n"
        "        }\n"
        "\n"
        "        if (this.modifierKeys != 0)\n"
        "            return;\n"
        "\n"
        "        const config = this.config;\n"
        "        const index = config.keymap.split (\" \").indexOf (event.code);\n"
        "\n"
        "        if (index >= 0)\n"
        "        {\n"
        "            const note = Math.floor ((config.rootNote + (config.numNotes / 4) + 11) / 12) * 12 + index;\n"
        "\n"
        "            if (isDown)\n"
        "                this.addKeyboardNote (note);\n"
        "            else\n"
        "                this.removeKeyboardNote (note);\n"
        "\n"
        "            event.preventDefault();\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    refreshHTML()\n"
        "    {\n"
        "        this.root.innerHTML = `<style>${this.getCSS()}</style>${this.getNoteElements()}`;\n"
        "\n"
        "        for (let i = 0; i < 128; ++i)\n"
        "        {\n"
        "            const elem = this.shadowRoot.getElementById (`note${i.toString()}`);\n"
        "            this.notes.push ({ note: i, element: elem });\n"
        "        }\n"
        "\n"
        "        this.style.maxWidth = window.getComputedStyle (this).scrollWidth;\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    refreshActiveNoteElements()\n"
        "    {\n"
        "        for (let note of this.notes)\n"
        "        {\n"
        "            if (note.element)\n"
        "            {\n"
        "                if (this.isNoteActive (note.note))\n"
        "                    note.element.classList.add (\"active\");\n"
        "                else\n"
        "                    note.element.classList.remove (\"active\");\n"
        "            }\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    getAccidentalOffset (note)\n"
        "    {\n"
        "        let index = midi.getChromaticScaleIndex (note);\n"
        "\n"
        "        let negativeOffset = -this.accidentalWidth / 16;\n"
        "        let positiveOffset = 3 * this.accidentalWidth / 16;\n"
        "\n"
        "        const accOffset = this.naturalWidth - (this.accidentalWidth / 2);\n"
        "        const offsets = [ 0, negativeOffset, 0, positiveOffset, 0, 0, negativeOffset, 0, 0, 0, positiveOffset, 0 ];\n"
        "\n"
        "        return accOffset + offsets[index];\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    getNoteElements()\n"
        "    {\n"
        "        const config = this.config;\n"
        "        let naturals = \"\", accidentals = \"\";\n"
        "        let x = 0;\n"
        "\n"
        "        for (let i = 0; i < config.numNotes; ++i)\n"
        "        {\n"
        "            const note = config.rootNote + i;\n"
        "            const name = this.getNoteLabel (note);\n"
        "\n"
        "            if (midi.isNatural (note))\n"
        "            {\n"
        "                naturals += `<div class=\"natural-note note\" id=\"note${note}\" style=\" left: ${x + 1}px\"><p>${name}</p></div>`;\n"
        "            }\n"
        "            else\n"
        "            {\n"
        "                let accidentalOffset = this.getAccidentalOffset (note);\n"
        "                accidentals += `<div class=\"accidental-note note\" id=\"note${note}\" style=\"left: ${x + accidentalOffset}px\"></div>`;\n"
        "            }\n"
        "\n"
        "            if (midi.isNatural (note + 1) || i == config.numNotes - 1)\n"
        "                x += this.naturalWidth;\n"
        "        }\n"
        "\n"
        "        this.style.maxWidth = (x + 1) + \"px\";\n"
        "\n"
        "        return `<div tabindex=\"0\" class=\"note-holder\" style=\"width: ${x + 1}px;\">\n"
        "                ${naturals}\n"
        "                ${accidentals}\n"
        "                </div>`;\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    getCSS()\n"
        "    {\n"
        "        let extraColours = \"\";\n"
        "        const config = this.config;\n"
        "\n"
        "        for (let i = 0; i < config.numNotes; ++i)\n"
        "        {\n"
        "            const note = config.rootNote + i;\n"
        "            const colourOverride = this.getNoteColour (note);\n"
        "\n"
        "            if (colourOverride)\n"
        "                extraColours += `#note${note}:not(.active) { background: ${colourOverride}; }`;\n"
        "        }\n"
        "\n"
        "        return `\n"
        "            * {\n"
        "                box-sizing: border-box;\n"
        "                user-select: none;\n"
        "                -webkit-user-select: none;\n"
        "                -moz-user-select: none;\n"
        "                -ms-user-select: none;\n"
        "                margin: 0;\n"
        "                padding: 0;\n"
        "            }\n"
        "\n"
        "            :host {\n"
        "                display: block;\n"
        "                overflow: auto;\n"
        "                position: relative;\n"
        "            }\n"
        "\n"
        "            .natural-note {\n"
        "                position: absolute;\n"
        "                border: ${this.naturalBorder};\n"
        "                background: #fff;\n"
        "                width: ${this.naturalWidth}px;\n"
        "                height: 100%;\n"
        "\n"
        "                display: flex;\n"
        "                align-items: end;\n"
        "                justify-content: center;\n"
        "            }\n"
        "\n"
        "            p {\n"
        "                pointer-events: none;\n"
        "                text-align: center;\n"
        "                font-size: 0.7rem;\n"
        "                color: grey;\n"
        "            }\n"
        "\n"
        "            .accidental-note {\n"
        "                position: absolute;\n"
        "                top: 0;\n"
        "                border: ${this.accidentalBorder};\n"
        "                background: #333;\n"
        "                width: ${this.accidentalWidth}px;\n"
        "                height: ${this.accidentalPercentageHeight}%;\n"
        "            }\n"
        "\n"
        "            .note-holder {\n"
        "                position: relative;\n"
        "                height: 100%;\n"
        "            }\n"
        "\n"
        "            .active {\n"
        "                background: ${this.pressedColour};\n"
        "            }\n"
        "\n"
        "            ${extraColours}\n"
        "            `\n"
        "    }\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajserversession_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import { PatchConnection } from \"./cmaj-patch-connection.js\"\n"
        "import { EventListenerList } from \"./cmaj-event-listener-list.js\"\n"
        "\n"
        "\n"
        "//==============================================================================\n"
        "/*\n"
        " *  This class provides the API and manages the communication protocol between\n"
        " *  a javascript application and a Cmajor session running on some kind of server\n"
        " *  (which may be local or remote).\n"
        " *\n"
        " *  This is an abstract base class: some kind of transport layer will create a\n"
        " *  subclass of ServerSession which a client application can then use to control\n"
        " *  and interact with the server.\n"
        " */\n"
        "export class ServerSession   extends EventListenerList\n"
        "{\n"
        "    /** A server session must be given a unique sessionID.\n"
        "     * @param {string} sessionID - this must be a unique string which is safe for\n"
        "     *                             use as an identifier or filename\n"
        "    */\n"
        "    constructor (sessionID)\n"
        "    {\n"
        "        super();\n"
        "\n"
        "        this.sessionID = sessionID;\n"
        "        this.activePatchConnections = new Set();\n"
        "        this.status = { connected: false, loaded: false };\n"
        "        this.lastServerMessageTime = Date.now();\n"
        "        this.checkForServerTimer = setInterval (() => this.checkServerStillExists(), 2000);\n"
        "    }\n"
        "\n"
        "    /** Call `dispose()` when this session is no longer needed and should be released. */\n"
        "    dispose()\n"
        "    {\n"
        "        if (this.checkForServerTimer)\n"
        "        {\n"
        "            clearInterval (this.checkForServerTimer);\n"
        "            this.checkForServerTimer = undefined;\n"
        "        }\n"
        "\n"
        "        this.status = { connected: false, loaded: false };\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Session status methods:\n"
        "\n"
        "    /** Attaches a listener function which will be called when the session status changes.\n"
        "     *  The listener will be called with an argument object containing lots of properties\n"
        "     *  describing the state, including any errors, loaded patch manifest, etc.\n"
        "     */\n"
        "    addStatusListener (listener)                        { this.addEventListener    (\"session_status\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added by `addStatusListener()`\n"
        "     */\n"
        "    removeStatusListener (listener)                     { this.removeEventListener (\"session_status\", listener); }\n"
        "\n"
        "    /** Asks the server to asynchronously send a status update message with the latest status.\n"
        "     */\n"
        "    requestSessionStatus()                              { this.sendMessageToServer ({ type: \"req_session_status\" }); }\n"
        "\n"
        "    /** Returns the session's last known status object. */\n"
        "    getCurrentStatus()                                  { return this.status; }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Patch loading:\n"
        "\n"
        "    /** Asks the server to load the specified patch into our session.\n"
        "     */\n"
        "    loadPatch (patchFileToLoad)\n"
        "    {\n"
        "        this.currentPatchLocation = patchFileToLoad;\n"
        "        this.sendMessageToServer ({ type: \"load_patch\", file: patchFileToLoad });\n"
        "    }\n"
        "\n"
        "    /** Asynchronously returns a list of patches that it has access to.\n"
        "     *  The return value is an array of manifest objects describing each of the patches.\n"
        "     */\n"
        "    async requestAvailablePatchList()\n"
        "    {\n"
        "        return await this.sendMessageToServerWithReply ({ type: \"req_patchlist\" });\n"
        "    }\n"
        "\n"
        "    /** Creates and returns a new PatchConnection object which can be used to control the\n"
        "     *  patch that this session has loaded.\n"
        "     */\n"
        "    createPatchConnection()\n"
        "    {\n"
        "        class ServerPatchConnection  extends PatchConnection\n"
        "        {\n"
        "            constructor (session)\n"
        "            {\n"
        "                super();\n"
        "                this.session = session;\n"
        "                this.manifest = session.status?.manifest;\n"
        "                this.session.activePatchConnections.add (this);\n"
        "            }\n"
        "\n"
        "            dispose()\n"
        "            {\n"
        "                this.session.activePatchConnections.delete (this);\n"
        "                this.session = undefined;\n"
        "            }\n"
        "\n"
        "            sendMessageToServer (message)\n"
        "            {\n"
        "                this.session?.sendMessageToServer (message);\n"
        "            }\n"
        "\n"
        "            getResourceAddress (path)\n"
        "            {\n"
        "                if (! this.session?.status?.httpRootURL)\n"
        "                    return undefined;\n"
        "\n"
        "                return this.session.status.httpRootURL\n"
        "                        + (path.startsWith (\"/\") ? path.substr (1) : path);\n"
        "            }\n"
        "        }\n"
        "\n"
        "        return new ServerPatchConnection (this);\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Audio input source handling:\n"
        "\n"
        "    /**\n"
        "     *  Sets a custom audio input source for a particular endpoint.\n"
        "     *\n"
        "     *  When a source is changed, a callback is sent to any audio input mode listeners (see\n"
        "     *  `addAudioInputModeListener()`)\n"
        "     *\n"
        "     *  @param {Object} endpointID\n"
        "     *  @param {boolean} shouldMute - if true, the endpoint will be muted\n"
        "     *  @param {Uint8Array | Array} fileDataToPlay - if this is some kind of array containing\n"
        "     *  binary data that can be parsed as an audio file, then it will be sent across for the\n"
        "     *  server to play as a looped input sample.\n"
        "     */\n"
        "    setAudioInputSource (endpointID, shouldMute, fileDataToPlay)\n"
        "    {\n"
        "        const loopFile = \"_audio_source_\" + endpointID;\n"
        "\n"
        "        if (fileDataToPlay)\n"
        "        {\n"
        "            this.registerFile (loopFile,\n"
        "            {\n"
        "               size: fileDataToPlay.byteLength,\n"
        "               read: (start, length) => { return new Blob ([fileDataToPlay.slice (start, start + length)]); }\n"
        "            });\n"
        "\n"
        "            this.sendMessageToServer ({ type: \"set_custom_audio_input\",\n"
        "                                        endpoint: endpointID,\n"
        "                                        file: loopFile });\n"
        "        }\n"
        "        else\n"
        "        {\n"
        "            this.removeFile (loopFile);\n"
        "\n"
        "            this.sendMessageToServer ({ type: \"set_custom_audio_input\",\n"
        "                                        endpoint: endpointID,\n"
        "                                        mute: !! shouldMute });\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** Attaches a listener function to be told when the input source for a particular\n"
        "     *  endpoint is changed by a call to `setAudioInputSource()`.\n"
        "     */\n"
        "    addAudioInputModeListener (endpointID, listener)    { this.addEventListener    (\"audio_input_mode_\" + endpointID, listener); }\n"
        "\n"
        "    /** Removes a listener previously added with `addAudioInputModeListener()` */\n"
        "    removeAudioInputModeListener (endpointID, listener) { this.removeEventListener (\"audio_input_mode_\" + endpointID, listener); }\n"
        "\n"
        "    /** Asks the server to send an update with the latest status to any audio mode listeners that\n"
        "     *  are attached to the given endpoint.\n"
        "     *  @param {string} endpointID\n"
        "     */\n"
        "    requestAudioInputMode (endpointID)                  { this.sendMessageToServer ({ type: \"req_audio_input_mode\", endpoint: endpointID }); }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Audio device methods:\n"
        "\n"
        "    /** Enables or disables audio playback.\n"
        "     *  When playback state changes, a status update is sent to any status listeners.\n"
        "     * @param {boolean} shouldBeActive\n"
        "     */\n"
        "    setAudioPlaybackActive (shouldBeActive)             { this.sendMessageToServer ({ type: \"set_audio_playback_active\", active: shouldBeActive }); }\n"
        "\n"
        "    /** Asks the server to apply a new set of audio device properties.\n"
        "     *  The properties object uses the same format as the object that is passed to the listeners\n"
        "     *  (see `addAudioDevicePropertiesListener()`).\n"
        "     */\n"
        "    setAudioDeviceProperties (newProperties)            { this.sendMessageToServer ({ type: \"set_audio_device_props\", properties: newProperties }); }\n"
        "\n"
        "    /** Attaches a listener function which will be called when the audio device properties are\n"
        "     *  changed.\n"
        "     *\n"
        "     *  You can remove the listener when it's no longer needed with `removeAudioDevicePropertiesListener()`.\n"
        "     *\n"
        "     *  @param listener - this callback will receive an argument object containing all the\n"
        "     *                    details about the device.\n"
        "     */\n"
        "    addAudioDevicePropertiesListener (listener)         { this.addEventListener    (\"audio_device_properties\", listener); }\n"
        "\n"
        "    /** Removes a listener that was added with `addAudioDevicePropertiesListener()` */\n"
        "    removeAudioDevicePropertiesListener (listener)      { this.removeEventListener (\"audio_device_properties\", listener); }\n"
        "\n"
        "    /** Causes an asynchronous callback to any audio device listeners that are registered. */\n"
        "    requestAudioDeviceProperties()                      { this.sendMessageToServer ({ type: \"req_audio_device_props\" }); }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** Asks the server to asynchronously generate some code from the currently loaded patch.\n"
        "     *\n"
        "     *  @param {string} codeType - this must be one of the strings that are listed in the\n"
        "     *                             status's `codeGenTargets` property. For example, \"cpp\"\n"
        "     *                             would request a C++ version of the patch.\n"
        "     *  @param {Object} [extraOptions] - this optionally provides target-specific properties.\n"
        "     *  @returns an object containing the code, errors and other metadata about the patch.\n"
        "     */\n"
        "    async requestGeneratedCode (codeType, extraOptions)\n"
        "    {\n"
        "        return await this.sendMessageToServerWithReply ({ type: \"req_codegen\",\n"
        "                                                          codeType: codeType,\n"
        "                                                          options: extraOptions, });\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // File change monitoring:\n"
        "\n"
        "    /** Attaches a listener to be told when a file change is detected in the currently-loaded\n"
        "     *  patch. The function will be called with an object that gives rough details about the\n"
        "     *  type of change, i.e. whether it's a manifest or asset file, or a cmajor file, but it\n"
        "     *  won't provide any information about exactly which files are involved.\n"
        "     */\n"
        "    addFileChangeListener (listener)                    { this.addEventListener    (\"patch_source_changed\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with `addFileChangeListener()`.\n"
        "     */\n"
        "    removeFileChangeListener (listener)                 { this.removeEventListener (\"patch_source_changed\", listener); }\n"
        "\n"
        "    //==============================================================================\n"
        "    // CPU level monitoring methods:\n"
        "\n"
        "    /** Attaches a listener function which will be sent messages containing CPU info.\n"
        "     *  To remove the listener, call `removeCPUListener()`. To change the rate of these\n"
        "     *  messages, use `setCPULevelUpdateRate()`.\n"
        "     */\n"
        "    addCPUListener (listener)                       { this.addEventListener    (\"cpu_info\", listener); this.updateCPULevelUpdateRate(); }\n"
        "\n"
        "    /** Removes a listener that was previously attached with `addCPUListener()`. */\n"
        "    removeCPUListener (listener)                    { this.removeEventListener (\"cpu_info\", listener); this.updateCPULevelUpdateRate(); }\n"
        "\n"
        "    /** Changes the frequency at which CPU level update messages are sent to listeners. */\n"
        "    setCPULevelUpdateRate (framesPerUpdate)         { this.cpuFramesPerUpdate = framesPerUpdate; this.updateCPULevelUpdateRate(); }\n"
        "\n"
        "    /** Attaches a listener to be told when a file change is detected in the currently-loaded\n"
        "     *  patch. The function will be called with an object that gives rough details about the\n"
        "     *  type of change, i.e. whether it's a manifest or asset file, or a cmajor file, but it\n"
        "     *  won't provide any information about exactly which files are involved.\n"
        "     */\n"
        "    addInfiniteLoopListener (listener)              { this.addEventListener    (\"infinite_loop_detected\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with `addFileChangeListener()`. */\n"
        "    removeInfiniteLoopListener (listener)           { this.removeEventListener (\"infinite_loop_detected\", listener); }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** Registers a virtual file with the server, under the given name.\n"
        "     *\n"
        "     *  @param {string} filename - the full path name of the file\n"
        "     *  @param {Object} contentProvider - this object must have a property called `size` which is a\n"
        "     *            constant size in bytes for the file, and a method `read (offset, size)` which\n"
        "     *            returns an array (or UInt8Array) of bytes for the data in a given chunk of the file.\n"
        "     *            The server may repeatedly call this method at any time until `removeFile()` is\n"
        "     *            called to deregister the file.\n"
        "     */\n"
        "    registerFile (filename, contentProvider)\n"
        "    {\n"
        "        if (! this.files)\n"
        "            this.files = new Map();\n"
        "\n"
        "        this.files.set (filename, contentProvider);\n"
        "\n"
        "        this.sendMessageToServer ({ type: \"register_file\",\n"
        "                                    filename: filename,\n"
        "                                    size: contentProvider.size });\n"
        "    }\n"
        "\n"
        "    /** Removes a file that was previously registered with `registerFile()`. */\n"
        "    removeFile (filename)\n"
        "    {\n"
        "        this.sendMessageToServer ({ type: \"remove_file\",\n"
        "                                    filename: filename });\n"
        "        this.files?.delete (filename);\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Private methods from this point...\n"
        "\n"
        "    /** An implementation subclass must call this when the session first connects\n"
        "     *  @private\n"
        "     */\n"
        "    handleSessionConnection()\n"
        "    {\n"
        "        if (! this.status.connected)\n"
        "        {\n"
        "            this.requestSessionStatus();\n"
        "            this.requestAudioDeviceProperties();\n"
        "\n"
        "            if (this.currentPatchLocation)\n"
        "            {\n"
        "                this.loadPatch (this.currentPatchLocation);\n"
        "                this.currentPatchLocation = undefined;\n"
        "            }\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** An implementation subclass must call this when a message arrives\n"
        "     *  @private\n"
        "     */\n"
        "    handleMessageFromServer (msg)\n"
        "    {\n"
        "        this.lastServerMessageTime = Date.now();\n"
        "        const type = msg.type;\n"
        "        const message = msg.message;\n"
        "\n"
        "        switch (type)\n"
        "        {\n"
        "            case \"cpu_info\":\n"
        "            case \"audio_device_properties\":\n"
        "            case \"patch_source_changed\":\n"
        "            case \"infinite_loop_detected\":\n"
        "                this.dispatchEvent (type, message);\n"
        "                break;\n"
        "\n"
        "            case \"session_status\":\n"
        "                message.connected = true;\n"
        "                this.setNewStatus (message);\n"
        "                break;\n"
        "\n"
        "            case \"req_file_read\":\n"
        "                this.handleFileReadRequest (message);\n"
        "                break;\n"
        "\n"
        "            case \"ping\":\n"
        "                this.sendMessageToServer ({ type: \"ping\" });\n"
        "                break;\n"
        "\n"
        "            default:\n"
        "                if (type.startsWith (\"audio_input_mode_\") || type.startsWith (\"reply_\"))\n"
        "                {\n"
        "                    this.dispatchEvent (type, message);\n"
        "                    break;\n"
        "                }\n"
        "\n"
        "                for (const c of this.activePatchConnections)\n"
        "                    c.deliverMessageFromServer (msg);\n"
        "\n"
        "                break;\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    checkServerStillExists()\n"
        "    {\n"
        "        if (Date.now() > this.lastServerMessageTime + 10000)\n"
        "            this.setNewStatus ({\n"
        "                connected: false,\n"
        "                loaded: false,\n"
        "                status: \"Cannot connect to the Cmajor server\"\n"
        "            });\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    setNewStatus (newStatus)\n"
        "    {\n"
        "        this.status = newStatus;\n"
        "        this.dispatchEvent (\"session_status\", this.status);\n"
        "        this.updateCPULevelUpdateRate();\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    updateCPULevelUpdateRate()\n"
        "    {\n"
        "        const rate = this.getNumListenersForType (\"cpu_info\") > 0 ? (this.cpuFramesPerUpdate || 15000) : 0;\n"
        "        this.sendMessageToServer ({ type: \"set_cpu_info_rate\",\n"
        "                                    framesPerCallback: rate });\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    handleFileReadRequest (request)\n"
        "    {\n"
        "        const contentProvider = this.files?.get (request?.file);\n"
        "\n"
        "        if (contentProvider && request.offset !== null && request.size != 0)\n"
        "        {\n"
        "            const data = contentProvider.read (request.offset, request.size);\n"
        "            const reader = new FileReader();\n"
        "\n"
        "            reader.onloadend = (e) =>\n"
        "            {\n"
        "                const base64 = e.target?.result?.split?.(\",\", 2)[1];\n"
        "\n"
        "                if (base64)\n"
        "                    this.sendMessageToServer ({ type: \"file_content\",\n"
        "                                                file: request.file,\n"
        "                                                data: base64,\n"
        "                                                start: request.offset });\n"
        "            };\n"
        "\n"
        "            reader.readAsDataURL (data);\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    sendMessageToServerWithReply (message)\n"
        "    {\n"
        "        return new Promise ((resolve, reject) =>\n"
        "        {\n"
        "            const replyType = \"reply_\" + message.type + \"_\" + this.createRandomID();\n"
        "            this.addSingleUseListener (replyType, resolve);\n"
        "            this.sendMessageToServer ({ ...message, replyType });\n"
        "        });\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    createRandomID()\n"
        "    {\n"
        "        return (Math.floor (Math.random() * 100000000)).toString();\n"
        "    }\n"
        "}\n";
    static constexpr const char* ui_indexvintage_html =
        "<!DOCTYPE html>\r\n"
        "<html lang=\"en\">\r\n"
        "<head>\r\n"
        "    <meta charset=\"UTF-8\">\r\n"
        "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\r\n"
        "    <title>CINTA - Vintage Texture Machine</title>\r\n"
        "    <link href=\"https://fonts.googleapis.com/css2?family=Playfair+Display:wght@400;700&family=IBM+Plex+Mono:wght@400;500;600&display=swap\" rel=\"stylesheet\">\r\n"
        "    <link rel=\"stylesheet\" href=\"styles-vintage.css\">\r\n"
        "    <link rel=\"stylesheet\" href=\"size-modes.css\">\r\n"
        "</head>\r\n"
        "<body>\r\n"
        "    <div class=\"synth-container size-compact\">\r\n"
        "        \r\n"
        "        <!-- SIZE TOGGLE BUTTON -->\r\n"
        "        <div class=\"size-toggle-container\">\r\n"
        "            <button class=\"size-toggle-btn\" id=\"sizeToggleBtn\">\r\n"
        "                <span id=\"currentSizeLabel\">COMPACT</span>\r\n"
        "            </button>\r\n"
        "            <div class=\"size-dropdown\" id=\"sizeDropdown\">\r\n"
        "                <div class=\"size-option\" data-size=\"full\">\r\n"
        "                    <span>FULL <span class=\"dimensions\">(1400x850)</span></span>\r\n"
        "                    <span class=\"shortcut\">Ctrl+1</span>\r\n"
        "                </div>\r\n"
        "                <div class=\"size-option\" data-size=\"compact\">\r\n"
        "                    <span>COMPACT <span class=\"dimensions\">(900x500)</span></span>\r\n"
        "                    <span class=\"shortcut\">Ctrl+2</span>\r\n"
        "                </div>\r\n"
        "                <div class=\"size-option\" data-size=\"mini\">\r\n"
        "                    <span>MINI <span class=\"dimensions\">(500x340)</span></span>\r\n"
        "                    <span class=\"shortcut\">Ctrl+3</span>\r\n"
        "                </div>\r\n"
        "                <div class=\"size-option\" data-size=\"strip\">\r\n"
        "                    <span>STRIP <span class=\"dimensions\">(380x160)</span></span>\r\n"
        "                    <span class=\"shortcut\">Ctrl+4</span>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "        </div>\r\n"
        "        \r\n"
        "        <!-- SIZE CHANGE INDICATOR -->\r\n"
        "        <div class=\"size-indicator\" id=\"sizeIndicator\"></div>\r\n"
        "        \r\n"
        "        <!-- HEADER WITH VINTAGE BADGE -->\r\n"
        "        <header class=\"header\">\r\n"
        "            <div class=\"logo\">\r\n"
        "                <div class=\"logo-badge\">\r\n"
        "                    <span class=\"logo-text\">CINTA</span>\r\n"
        "                    <span class=\"logo-subtitle\">Vintage Texture Machine \x0c2\x0b7 Havana 1975</span>\r\n"
        "                </div>\r\n"
        "                <div class=\"logo-screws\">\r\n"
        "                    <div class=\"screw\"></div>\r\n"
        "                    <div class=\"screw\"></div>\r\n"
        "                    <div class=\"screw\"></div>\r\n"
        "                    <div class=\"screw\"></div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "            \r\n"
        "            <div class=\"preset-browser\">\r\n"
        "                <button class=\"preset-btn prev\">\x0e2\x097\x080</button>\r\n"
        "                <select id=\"preset-select\">\r\n"
        "                    <option>Init</option>\r\n"
        "                    <option>Reggaeton Bell</option>\r\n"
        "                    <option>Warm Rhodes</option>\r\n"
        "                    <option>Tape Strings</option>\r\n"
        "                    <option>Analog Bass</option>\r\n"
        "                    <option>Bad Bunny Bell</option>\r\n"
        "                    <option>Tainy Atmosphere</option>\r\n"
        "                </select>\r\n"
        "                <button class=\"preset-btn next\">\x0e2\x096\x0b6</button>\r\n"
        "                <button class=\"preset-btn save\">SAVE</button>\r\n"
        "            </div>\r\n"
        "            \r\n"
        "            <div class=\"macro-knobs\">\r\n"
        "                <div class=\"macro-knob\">\r\n"
        "                    <div class=\"knob\" data-param=\"vibe\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                    <label>VIBE</label>\r\n"
        "                </div>\r\n"
        "                <div class=\"macro-knob\">\r\n"
        "                    <div class=\"knob\" data-param=\"warmth\" data-min=\"0\" data-max=\"1\" data-value=\"0.5\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                    <label>WARMTH</label>\r\n"
        "                </div>\r\n"
        "                <div class=\"macro-knob\">\r\n"
        "                    <div class=\"knob\" data-param=\"space\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                    <label>SPACE</label>\r\n"
        "                </div>\r\n"
        "                <div class=\"macro-knob\">\r\n"
        "                    <div class=\"knob\" data-param=\"movement\" data-min=\"0\" data-max=\"1\" data-value=\"0.2\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                    <label>MOVEMENT</label>\r\n"
        "                </div>\r\n"
        "                <div class=\"macro-knob\">\r\n"
        "                    <div class=\"knob\" data-param=\"grit\" data-min=\"0\" data-max=\"1\" data-value=\"0.1\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                    <label>GRIT</label>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "        </header>\r\n"
        "\r\n"
        "        <!-- REEL-TO-REEL TAPE DECK -->\r\n"
        "        <div class=\"tape-deck\" id=\"tape-deck\">\r\n"
        "            <div class=\"reel left-reel\">\r\n"
        "                <div class=\"reel-hub\"></div>\r\n"
        "                <div class=\"reel-spokes\"></div>\r\n"
        "                <div class=\"tape-level\"></div>\r\n"
        "            </div>\r\n"
        "            <div class=\"tape-path\">\r\n"
        "                <div class=\"tape-guide\"></div>\r\n"
        "                <div class=\"tape-head\"></div>\r\n"
        "                <div class=\"tape-guide\"></div>\r\n"
        "            </div>\r\n"
        "            <div class=\"reel right-reel\">\r\n"
        "                <div class=\"reel-hub\"></div>\r\n"
        "                <div class=\"reel-spokes\"></div>\r\n"
        "                <div class=\"tape-level\"></div>\r\n"
        "            </div>\r\n"
        "        </div>\r\n"
        "\r\n"
        "        <!-- ENGINES ROW -->\r\n"
        "        <section class=\"engines-row\">\r\n"
        "            \r\n"
        "            <!-- FM ENGINE -->\r\n"
        "            <div class=\"engine-panel\" id=\"fm-engine\">\r\n"
        "                <div class=\"engine-header\">\r\n"
        "                    <h2>FM ENGINE</h2>\r\n"
        "                    <div style=\"display: flex; gap: 8px; align-items: center;\">\r\n"
        "                        <div class=\"led-indicator on\"></div>\r\n"
        "                        <button class=\"toggle-btn active\" data-param=\"fm_on\">ON</button>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                <div class=\"engine-controls\">\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"fm_ratio\" data-min=\"0.5\" data-max=\"16\" data-value=\"2\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Ratio</label>\r\n"
        "                        <div class=\"nixie-display\">\r\n"
        "                            <div class=\"nixie-digit\">2</div>\r\n"
        "                            <div class=\"nixie-digit\">.</div>\r\n"
        "                            <div class=\"nixie-digit\">0</div>\r\n"
        "                        </div>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"fm_depth\" data-min=\"0\" data-max=\"1\" data-value=\"0.5\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Depth</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"fm_feedback\" data-min=\"0\" data-max=\"1\" data-value=\"0\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Feedback</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"fm_level\" data-min=\"0\" data-max=\"1\" data-value=\"0.7\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Level</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "\r\n"
        "            <!-- TAPE ENGINE -->\r\n"
        "            <div class=\"engine-panel\" id=\"tape-engine\">\r\n"
        "                <div class=\"engine-header\">\r\n"
        "                    <h2>TAPE ENGINE</h2>\r\n"
        "                    <div style=\"display: flex; gap: 8px; align-items: center;\">\r\n"
        "                        <div class=\"led-indicator\"></div>\r\n"
        "                        <button class=\"toggle-btn\" data-param=\"tape_on\">OFF</button>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                <div class=\"engine-controls\">\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <select class=\"sound-select\" data-param=\"tape_sound\">\r\n"
        "                            <option value=\"0\">Strings</option>\r\n"
        "                            <option value=\"1\">Flutes</option>\r\n"
        "                            <option value=\"2\">Choirs</option>\r\n"
        "                            <option value=\"3\">Brass</option>\r\n"
        "                            <option value=\"4\">Keys</option>\r\n"
        "                        </select>\r\n"
        "                        <label>Sound</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"tape_wow\" data-min=\"0\" data-max=\"1\" data-value=\"0.2\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Wow</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"tape_flutter\" data-min=\"0\" data-max=\"1\" data-value=\"0.1\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Flutter</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"tape_level\" data-min=\"0\" data-max=\"1\" data-value=\"0.7\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Level</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "\r\n"
        "            <!-- ANALOG ENGINE -->\r\n"
        "            <div class=\"engine-panel\" id=\"analog-engine\">\r\n"
        "                <div class=\"engine-header\">\r\n"
        "                    <h2>ANALOG ENGINE</h2>\r\n"
        "                    <div style=\"display: flex; gap: 8px; align-items: center;\">\r\n"
        "                        <div class=\"led-indicator\"></div>\r\n"
        "                        <button class=\"toggle-btn\" data-param=\"analog_on\">OFF</button>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                <div class=\"engine-controls\">\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <select class=\"sound-select\" data-param=\"analog_wave\">\r\n"
        "                            <option value=\"0\">Saw</option>\r\n"
        "                            <option value=\"1\">Square</option>\r\n"
        "                            <option value=\"2\">Pulse</option>\r\n"
        "                            <option value=\"3\">Triangle</option>\r\n"
        "                        </select>\r\n"
        "                        <label>Wave</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"analog_detune\" data-min=\"-100\" data-max=\"100\" data-value=\"5\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Detune</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"analog_filter\" data-min=\"20\" data-max=\"20000\" data-value=\"8000\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Filter</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"analog_resonance\" data-min=\"0\" data-max=\"1\" data-value=\"0.2\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Reso</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob\" data-param=\"analog_level\" data-min=\"0\" data-max=\"1\" data-value=\"0.7\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>Level</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "        </section>\r\n"
        "\r\n"
        "        <!-- TEXTURE RACK -->\r\n"
        "        <section class=\"texture-rack\">\r\n"
        "            <h2>TEXTURE RACK</h2>\r\n"
        "            <div class=\"texture-slots\">\r\n"
        "                \r\n"
        "                <div class=\"texture-slot\">\r\n"
        "                    <div class=\"led-indicator\"></div>\r\n"
        "                    <button class=\"toggle-btn small\" data-param=\"tape_age_on\">OFF</button>\r\n"
        "                    <span class=\"texture-name\">TAPE AGE</span>\r\n"
        "                    <div class=\"knob small\" data-param=\"tape_age_amount\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"texture-slot\">\r\n"
        "                    <div class=\"led-indicator\"></div>\r\n"
        "                    <button class=\"toggle-btn small\" data-param=\"vinyl_on\">OFF</button>\r\n"
        "                    <span class=\"texture-name\">VINYL</span>\r\n"
        "                    <div class=\"knob small\" data-param=\"vinyl_amount\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"texture-slot\">\r\n"
        "                    <div class=\"led-indicator\"></div>\r\n"
        "                    <button class=\"toggle-btn small\" data-param=\"tube_on\">OFF</button>\r\n"
        "                    <span class=\"texture-name\">TUBE</span>\r\n"
        "                    <div class=\"knob small\" data-param=\"tube_amount\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"texture-slot\">\r\n"
        "                    <div class=\"led-indicator\"></div>\r\n"
        "                    <button class=\"toggle-btn small\" data-param=\"room_on\">OFF</button>\r\n"
        "                    <span class=\"texture-name\">ROOM</span>\r\n"
        "                    <div class=\"knob small\" data-param=\"room_amount\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"texture-slot\">\r\n"
        "                    <div class=\"led-indicator\"></div>\r\n"
        "                    <button class=\"toggle-btn small\" data-param=\"crush_on\">OFF</button>\r\n"
        "                    <span class=\"texture-name\">CRUSH</span>\r\n"
        "                    <div class=\"knob small\" data-param=\"crush_bits\" data-min=\"4\" data-max=\"16\" data-value=\"12\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "            </div>\r\n"
        "        </section>\r\n"
        "\r\n"
        "        <!-- ARP MACHINE -->\r\n"
        "        <section class=\"arp-machine\">\r\n"
        "            <div class=\"arp-header\">\r\n"
        "                <h2>\x0f0\x09f\x08e\x0b9 ARP MACHINE</h2>\r\n"
        "                <div style=\"display: flex; gap: 8px; align-items: center;\">\r\n"
        "                    <div class=\"led-indicator\"></div>\r\n"
        "                    <button class=\"toggle-btn\" data-param=\"arp_on\">OFF</button>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "            \r\n"
        "            <div class=\"arp-selectors\">\r\n"
        "                <div class=\"selector-group\">\r\n"
        "                    <label>MELODY</label>\r\n"
        "                    <select data-param=\"arp_melody\">\r\n"
        "                        <option value=\"0\">D\x0c3\x0a1kiti Style</option>\r\n"
        "                        <option value=\"1\">Calla\x0c3\x0adta Style</option>\r\n"
        "                        <option value=\"2\">Tusa Style</option>\r\n"
        "                        <option value=\"3\">Yonaguni Style</option>\r\n"
        "                        <option value=\"4\">Moscow Mule</option>\r\n"
        "                        <option value=\"5\">Me Porto Bonito</option>\r\n"
        "                        <option value=\"6\">Dark Bell</option>\r\n"
        "                        <option value=\"7\">Flute Trap</option>\r\n"
        "                        <option value=\"8\">Summer Hit</option>\r\n"
        "                        <option value=\"9\">Radio Ready</option>\r\n"
        "                    </select>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"selector-group\">\r\n"
        "                    <label>RHYTHM</label>\r\n"
        "                    <select data-param=\"arp_rhythm\">\r\n"
        "                        <option value=\"0\">Classic Dembow</option>\r\n"
        "                        <option value=\"1\">Modern Dembow</option>\r\n"
        "                        <option value=\"2\">Half-Time Dembow</option>\r\n"
        "                        <option value=\"3\">Perreo Intenso</option>\r\n"
        "                        <option value=\"4\">Perreo Suave</option>\r\n"
        "                        <option value=\"5\">808 Bounce</option>\r\n"
        "                        <option value=\"6\">Hi-Hat Rolls</option>\r\n"
        "                        <option value=\"7\">Trap Latino</option>\r\n"
        "                        <option value=\"8\">Tresillo</option>\r\n"
        "                        <option value=\"9\">Clave</option>\r\n"
        "                    </select>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"selector-group\">\r\n"
        "                    <label>SCALE</label>\r\n"
        "                    <select data-param=\"arp_scale\">\r\n"
        "                        <option value=\"0\">Reggaeton Minor</option>\r\n"
        "                        <option value=\"1\">Reggaeton Major</option>\r\n"
        "                        <option value=\"2\">Trap Minor</option>\r\n"
        "                        <option value=\"3\">Latin Pop</option>\r\n"
        "                        <option value=\"4\">Sad Boy</option>\r\n"
        "                        <option value=\"5\">Perreo</option>\r\n"
        "                        <option value=\"6\">Romantic</option>\r\n"
        "                        <option value=\"7\">Callejero</option>\r\n"
        "                    </select>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"selector-group key-selector\">\r\n"
        "                    <label>KEY</label>\r\n"
        "                    <div class=\"key-buttons\">\r\n"
        "                        <button class=\"key-btn active\" data-key=\"0\">C</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"1\">C#</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"2\">D</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"3\">D#</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"4\">E</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"5\">F</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"6\">F#</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"7\">G</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"8\">G#</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"9\">A</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"10\">A#</button>\r\n"
        "                        <button class=\"key-btn\" data-key=\"11\">B</button>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "            \r\n"
        "            <div class=\"arp-pattern-display\">\r\n"
        "                <div class=\"pattern-step\"></div>\r\n"
        "                <div class=\"pattern-step active\"></div>\r\n"
        "                <div class=\"pattern-step\"></div>\r\n"
        "                <div class=\"pattern-step active\"></div>\r\n"
        "                <div class=\"pattern-step\"></div>\r\n"
        "                <div class=\"pattern-step\"></div>\r\n"
        "                <div class=\"pattern-step active\"></div>\r\n"
        "                <div class=\"pattern-step\"></div>\r\n"
        "                <div class=\"pattern-step active\"></div>\r\n"
        "                <div class=\"pattern-step\"></div>\r\n"
        "                <div class=\"pattern-step active\"></div>\r\n"
        "                <div class=\"pattern-step\"></div>\r\n"
        "                <div class=\"pattern-step\"></div>\r\n"
        "                <div class=\"pattern-step active\"></div>\r\n"
        "                <div class=\"pattern-step\"></div>\r\n"
        "                <div class=\"pattern-step\"></div>\r\n"
        "            </div>\r\n"
        "            \r\n"
        "            <div class=\"arp-controls\">\r\n"
        "                <button class=\"randomize-btn\" id=\"randomize\">\x0f0\x09f\x08e\x0b2 RANDOMIZE</button>\r\n"
        "                \r\n"
        "                <div class=\"selector-group\">\r\n"
        "                    <label>MODE</label>\r\n"
        "                    <select data-param=\"arp_mode\">\r\n"
        "                        <option value=\"0\">HITMAKER</option>\r\n"
        "                        <option value=\"1\">VIBRAS</option>\r\n"
        "                        <option value=\"2\">EMOCIONES</option>\r\n"
        "                        <option value=\"3\">ALTURA</option>\r\n"
        "                        <option value=\"4\">PERREO</option>\r\n"
        "                        <option value=\"5\">EXPERIMENTAL</option>\r\n"
        "                    </select>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"knob-group\">\r\n"
        "                    <div class=\"knob small\" data-param=\"arp_rate\" data-min=\"0\" data-max=\"8\" data-value=\"3\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                    <label>Rate</label>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"knob-group\">\r\n"
        "                    <div class=\"knob small\" data-param=\"arp_swing\" data-min=\"0\" data-max=\"100\" data-value=\"0\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                    <label>Swing</label>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"knob-group\">\r\n"
        "                    <div class=\"knob small\" data-param=\"arp_gate\" data-min=\"1\" data-max=\"100\" data-value=\"75\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                    <label>Gate</label>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"knob-group\">\r\n"
        "                    <div class=\"knob small\" data-param=\"arp_octaves\" data-min=\"1\" data-max=\"4\" data-value=\"2\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                    <label>Octaves</label>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "            \r\n"
        "            <div class=\"arp-variations\">\r\n"
        "                <button class=\"var-btn\" data-variation=\"octave-up\">\x0e2\x086\x091 OCT</button>\r\n"
        "                <button class=\"var-btn\" data-variation=\"octave-down\">\x0e2\x086\x093 OCT</button>\r\n"
        "                <button class=\"var-btn\" data-variation=\"invert\">INVERT</button>\r\n"
        "                <button class=\"var-btn\" data-variation=\"reverse\">REVERSE</button>\r\n"
        "                <button class=\"var-btn\" data-variation=\"simplify\">SIMPLE</button>\r\n"
        "                <button class=\"var-btn\" data-variation=\"double\">DOUBLE</button>\r\n"
        "                <button class=\"var-btn\" data-variation=\"shift-left\">\x0e2\x097\x084\x0e2\x097\x084</button>\r\n"
        "                <button class=\"var-btn\" data-variation=\"shift-right\">\x0e2\x096\x0ba\x0e2\x096\x0ba</button>\r\n"
        "            </div>\r\n"
        "        </section>\r\n"
        "\r\n"
        "        <!-- BOTTOM CONTROLS -->\r\n"
        "        <section class=\"bottom-controls\">\r\n"
        "            <div class=\"envelope-section\">\r\n"
        "                <h3>ENVELOPE</h3>\r\n"
        "                <div class=\"env-knobs\">\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob small\" data-param=\"amp_attack\" data-min=\"0.001\" data-max=\"5\" data-value=\"0.01\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>A</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob small\" data-param=\"amp_decay\" data-min=\"0.001\" data-max=\"5\" data-value=\"0.2\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>D</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob small\" data-param=\"amp_sustain\" data-min=\"0\" data-max=\"1\" data-value=\"0.7\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>S</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-group\">\r\n"
        "                        <div class=\"knob small\" data-param=\"amp_release\" data-min=\"0.001\" data-max=\"10\" data-value=\"0.3\">\r\n"
        "                            <div class=\"knob-pointer\"></div>\r\n"
        "                        </div>\r\n"
        "                        <label>R</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "            \r\n"
        "            <div class=\"master-section\">\r\n"
        "                <h3>MASTER OUTPUT</h3>\r\n"
        "                \r\n"
        "                <!-- VU METER -->\r\n"
        "                <div class=\"vu-meter\" id=\"vu-meter\" data-level=\"low\">\r\n"
        "                    <div class=\"vu-face\">\r\n"
        "                        <div class=\"vu-scale\">\r\n"
        "                            <span class=\"vu-mark\" style=\"--angle: -45deg\">-20</span>\r\n"
        "                            <span class=\"vu-mark\" style=\"--angle: -30deg\">-10</span>\r\n"
        "                            <span class=\"vu-mark\" style=\"--angle: -15deg\">-7</span>\r\n"
        "                            <span class=\"vu-mark\" style=\"--angle: 0deg\">-5</span>\r\n"
        "                            <span class=\"vu-mark\" style=\"--angle: 15deg\">-3</span>\r\n"
        "                            <span class=\"vu-mark\" style=\"--angle: 30deg\">0</span>\r\n"
        "                            <span class=\"vu-mark red\" style=\"--angle: 40deg\">+1</span>\r\n"
        "                            <span class=\"vu-mark red\" style=\"--angle: 50deg\">+3</span>\r\n"
        "                        </div>\r\n"
        "                        <div class=\"vu-needle\"></div>\r\n"
        "                        <div class=\"vu-pivot\"></div>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"vu-glass\"></div>\r\n"
        "                    <div class=\"vu-label\">VU</div>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"knob-group\">\r\n"
        "                    <div class=\"knob\" data-param=\"master_volume\" data-min=\"0\" data-max=\"1\" data-value=\"0.8\">\r\n"
        "                        <div class=\"knob-pointer\"></div>\r\n"
        "                    </div>\r\n"
        "                    <label>MASTER</label>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "        </section>\r\n"
        "        \r\n"
        "    </div>\r\n"
        "    \r\n"
        "    <script src=\"size-manager.js\"></script>\r\n"
        "    <script src=\"main-vintage.js\"></script>\r\n"
        "</body>\r\n"
        "</html>\r\n";
    static constexpr const char* ui_index_html =
        "<!DOCTYPE html>\r\n"
        "<html lang=\"en\">\r\n"
        "<head>\r\n"
        "    <meta charset=\"UTF-8\">\r\n"
        "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\r\n"
        "    <title>CINTA - Vintage Texture Machine</title>\r\n"
        "    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">\r\n"
        "    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>\r\n"
        "    <link href=\"https://fonts.googleapis.com/css2?family=Playfair+Display:wght@700&family=IBM+Plex+Mono:wght@400;600&display=swap\" rel=\"stylesheet\">\r\n"
        "    <link rel=\"stylesheet\" href=\"styles.css\">\r\n"
        "</head>\r\n"
        "<body>\r\n"
        "    <div class=\"synth-container\">\r\n"
        "        <!-- Header -->\r\n"
        "        <div class=\"header\">\r\n"
        "            <div class=\"header-left\">\r\n"
        "                <h1 class=\"logo\">CINTA</h1>\r\n"
        "                <p class=\"tagline\">Vintage Texture Machine</p>\r\n"
        "            </div>\r\n"
        "            <div class=\"header-center\">\r\n"
        "                <select class=\"preset-selector\">\r\n"
        "                    <option>Classic Dembow</option>\r\n"
        "                    <option>Warm Perreo</option>\r\n"
        "                    <option>Lo-Fi Trap</option>\r\n"
        "                    <option>Tape Dreams</option>\r\n"
        "                    <option>Radio Nostalgia</option>\r\n"
        "                </select>\r\n"
        "                <button class=\"preset-btn\">\x0e2\x097\x080</button>\r\n"
        "                <button class=\"preset-btn\">\x0e2\x096\x0b6</button>\r\n"
        "                <button class=\"preset-btn save-btn\">SAVE</button>\r\n"
        "            </div>\r\n"
        "            <div class=\"header-right quick-controls\">\r\n"
        "                <div class=\"quick-knob\">\r\n"
        "                    <div class=\"knob\" data-param=\"vibe\" data-min=\"0\" data-max=\"1\" data-value=\"0.5\"></div>\r\n"
        "                    <label>VIBE</label>\r\n"
        "                </div>\r\n"
        "                <div class=\"quick-knob\">\r\n"
        "                    <div class=\"knob\" data-param=\"warmth\" data-min=\"0\" data-max=\"1\" data-value=\"0.5\"></div>\r\n"
        "                    <label>WARMTH</label>\r\n"
        "                </div>\r\n"
        "                <div class=\"quick-knob\">\r\n"
        "                    <div class=\"knob\" data-param=\"space\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\"></div>\r\n"
        "                    <label>SPACE</label>\r\n"
        "                </div>\r\n"
        "                <div class=\"quick-knob\">\r\n"
        "                    <div class=\"knob\" data-param=\"movement\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\"></div>\r\n"
        "                    <label>MOVEMENT</label>\r\n"
        "                </div>\r\n"
        "                <div class=\"quick-knob\">\r\n"
        "                    <div class=\"knob\" data-param=\"grit\" data-min=\"0\" data-max=\"1\" data-value=\"0.2\"></div>\r\n"
        "                    <label>GRIT</label>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "        </div>\r\n"
        "\r\n"
        "        <!-- Sound Engines -->\r\n"
        "        <div class=\"engines-section\">\r\n"
        "            <div class=\"engine-panel\">\r\n"
        "                <div class=\"engine-header\">\r\n"
        "                    <h2>FM ENGINE</h2>\r\n"
        "                    <label class=\"toggle-switch\">\r\n"
        "                        <input type=\"checkbox\" data-param=\"fm_on\" checked>\r\n"
        "                        <span class=\"slider\"></span>\r\n"
        "                    </label>\r\n"
        "                </div>\r\n"
        "                <div class=\"engine-controls\">\r\n"
        "                    <div class=\"control-group\">\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"fm_ratio\" data-min=\"0.5\" data-max=\"16\" data-value=\"2\"></div>\r\n"
        "                            <label>Ratio</label>\r\n"
        "                        </div>\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"fm_depth\" data-min=\"0\" data-max=\"1\" data-value=\"0.5\"></div>\r\n"
        "                            <label>Depth</label>\r\n"
        "                        </div>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"control-group\">\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"fm_feedback\" data-min=\"0\" data-max=\"1\" data-value=\"0\"></div>\r\n"
        "                            <label>Feedback</label>\r\n"
        "                        </div>\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"fm_level\" data-min=\"0\" data-max=\"1\" data-value=\"0.7\"></div>\r\n"
        "                            <label>Level</label>\r\n"
        "                        </div>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "\r\n"
        "            <div class=\"engine-panel\">\r\n"
        "                <div class=\"engine-header\">\r\n"
        "                    <h2>TAPE ENGINE</h2>\r\n"
        "                    <label class=\"toggle-switch\">\r\n"
        "                        <input type=\"checkbox\" data-param=\"tape_on\" checked>\r\n"
        "                        <span class=\"slider\"></span>\r\n"
        "                    </label>\r\n"
        "                </div>\r\n"
        "                <div class=\"engine-controls\">\r\n"
        "                    <div class=\"control-group\">\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob discrete\" data-param=\"tape_sound\" data-min=\"0\" data-max=\"4\" data-value=\"0\"></div>\r\n"
        "                            <label>Sound</label>\r\n"
        "                            <span class=\"value-display\">Strings</span>\r\n"
        "                        </div>\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"tape_speed\" data-min=\"0.5\" data-max=\"2\" data-value=\"1\"></div>\r\n"
        "                            <label>Speed</label>\r\n"
        "                        </div>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"control-group\">\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"tape_wow\" data-min=\"0\" data-max=\"1\" data-value=\"0.2\"></div>\r\n"
        "                            <label>Wow</label>\r\n"
        "                        </div>\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"tape_flutter\" data-min=\"0\" data-max=\"1\" data-value=\"0.1\"></div>\r\n"
        "                            <label>Flutter</label>\r\n"
        "                        </div>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "\r\n"
        "            <div class=\"engine-panel\">\r\n"
        "                <div class=\"engine-header\">\r\n"
        "                    <h2>ANALOG ENGINE</h2>\r\n"
        "                    <label class=\"toggle-switch\">\r\n"
        "                        <input type=\"checkbox\" data-param=\"analog_on\" checked>\r\n"
        "                        <span class=\"slider\"></span>\r\n"
        "                    </label>\r\n"
        "                </div>\r\n"
        "                <div class=\"engine-controls\">\r\n"
        "                    <div class=\"control-group\">\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob discrete\" data-param=\"analog_osc1_wave\" data-min=\"0\" data-max=\"3\" data-value=\"0\"></div>\r\n"
        "                            <label>Wave 1</label>\r\n"
        "                        </div>\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob discrete\" data-param=\"analog_osc2_wave\" data-min=\"0\" data-max=\"3\" data-value=\"0\"></div>\r\n"
        "                            <label>Wave 2</label>\r\n"
        "                        </div>\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"analog_osc2_detune\" data-min=\"-100\" data-max=\"100\" data-value=\"0\"></div>\r\n"
        "                            <label>Detune</label>\r\n"
        "                        </div>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"control-group\">\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"analog_pulse_width\" data-min=\"0.1\" data-max=\"0.9\" data-value=\"0.5\"></div>\r\n"
        "                            <label>PW</label>\r\n"
        "                        </div>\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"analog_filter_cutoff\" data-min=\"20\" data-max=\"20000\" data-value=\"2000\"></div>\r\n"
        "                            <label>Filter</label>\r\n"
        "                        </div>\r\n"
        "                        <div class=\"knob-control\">\r\n"
        "                            <div class=\"knob\" data-param=\"analog_filter_resonance\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\"></div>\r\n"
        "                            <label>Reso</label>\r\n"
        "                        </div>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "        </div>\r\n"
        "\r\n"
        "        <!-- Texture Rack -->\r\n"
        "        <div class=\"texture-rack\">\r\n"
        "            <h2 class=\"section-title\">TEXTURE RACK</h2>\r\n"
        "            <div class=\"texture-units\">\r\n"
        "                <div class=\"texture-unit\">\r\n"
        "                    <div class=\"texture-header\">\r\n"
        "                        <h3>TAPE AGE</h3>\r\n"
        "                        <label class=\"toggle-switch small\">\r\n"
        "                            <input type=\"checkbox\" data-param=\"tape_age_on\">\r\n"
        "                            <span class=\"slider\"></span>\r\n"
        "                        </label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"texture-controls\">\r\n"
        "                        <div class=\"knob small\" data-param=\"tape_age_wow_depth\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\"></div>\r\n"
        "                        <label>Wow</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "\r\n"
        "                <div class=\"texture-unit\">\r\n"
        "                    <div class=\"texture-header\">\r\n"
        "                        <h3>VINYL</h3>\r\n"
        "                        <label class=\"toggle-switch small\">\r\n"
        "                            <input type=\"checkbox\" data-param=\"vinyl_on\">\r\n"
        "                            <span class=\"slider\"></span>\r\n"
        "                        </label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"texture-controls\">\r\n"
        "                        <div class=\"knob small\" data-param=\"vinyl_crackle\" data-min=\"0\" data-max=\"1\" data-value=\"0.2\"></div>\r\n"
        "                        <label>Crackle</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "\r\n"
        "                <div class=\"texture-unit\">\r\n"
        "                    <div class=\"texture-header\">\r\n"
        "                        <h3>RADIO</h3>\r\n"
        "                        <label class=\"toggle-switch small\">\r\n"
        "                            <input type=\"checkbox\" data-param=\"radio_on\">\r\n"
        "                            <span class=\"slider\"></span>\r\n"
        "                        </label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"texture-controls\">\r\n"
        "                        <div class=\"knob small\" data-param=\"radio_bandwidth\" data-min=\"0\" data-max=\"1\" data-value=\"0.5\"></div>\r\n"
        "                        <label>Band</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "\r\n"
        "                <div class=\"texture-unit\">\r\n"
        "                    <div class=\"texture-header\">\r\n"
        "                        <h3>ROOM</h3>\r\n"
        "                        <label class=\"toggle-switch small\">\r\n"
        "                            <input type=\"checkbox\" data-param=\"room_on\">\r\n"
        "                            <span class=\"slider\"></span>\r\n"
        "                        </label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"texture-controls\">\r\n"
        "                        <div class=\"knob small\" data-param=\"room_mix\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\"></div>\r\n"
        "                        <label>Mix</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "\r\n"
        "                <div class=\"texture-unit\">\r\n"
        "                    <div class=\"texture-header\">\r\n"
        "                        <h3>TUBE</h3>\r\n"
        "                        <label class=\"toggle-switch small\">\r\n"
        "                            <input type=\"checkbox\" data-param=\"tube_on\">\r\n"
        "                            <span class=\"slider\"></span>\r\n"
        "                        </label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"texture-controls\">\r\n"
        "                        <div class=\"knob small\" data-param=\"tube_drive\" data-min=\"0\" data-max=\"1\" data-value=\"0.3\"></div>\r\n"
        "                        <label>Drive</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "\r\n"
        "                <div class=\"texture-unit\">\r\n"
        "                    <div class=\"texture-header\">\r\n"
        "                        <h3>CRUSH</h3>\r\n"
        "                        <label class=\"toggle-switch small\">\r\n"
        "                            <input type=\"checkbox\" data-param=\"crush_on\">\r\n"
        "                            <span class=\"slider\"></span>\r\n"
        "                        </label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"texture-controls\">\r\n"
        "                        <div class=\"knob small\" data-param=\"crush_bits\" data-min=\"4\" data-max=\"16\" data-value=\"12\"></div>\r\n"
        "                        <label>Bits</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "        </div>\r\n"
        "\r\n"
        "        <!-- Arp Machine -->\r\n"
        "        <div class=\"arp-section\">\r\n"
        "            <div class=\"arp-header\">\r\n"
        "                <h2 class=\"section-title\">\x0f0\x09f\x08e\x0b9 ARP MACHINE</h2>\r\n"
        "                <label class=\"toggle-switch\">\r\n"
        "                    <input type=\"checkbox\" data-param=\"arp_on\">\r\n"
        "                    <span class=\"slider\"></span>\r\n"
        "                </label>\r\n"
        "            </div>\r\n"
        "            <div class=\"arp-controls\">\r\n"
        "                <div class=\"arp-top-row\">\r\n"
        "                    <div class=\"selector-group\">\r\n"
        "                        <label>MELODY</label>\r\n"
        "                        <select data-param=\"arp_melody_type\">\r\n"
        "                            <option value=\"0\">D\x0c3\x0a1kiti Style</option>\r\n"
        "                            <option value=\"1\">Calla\x0c3\x0adta Style</option>\r\n"
        "                            <option value=\"2\">Tusa Style</option>\r\n"
        "                            <option value=\"3\">Yonaguni Style</option>\r\n"
        "                            <option value=\"4\">Moscow Mule</option>\r\n"
        "                            <option value=\"5\">Me Porto Bonito</option>\r\n"
        "                            <option value=\"6\">La Noche de Anoche</option>\r\n"
        "                            <option value=\"7\">Dark Bell</option>\r\n"
        "                            <option value=\"8\">Flute Trap</option>\r\n"
        "                            <option value=\"9\">Hard Bell</option>\r\n"
        "                            <option value=\"10\">Sad Trap</option>\r\n"
        "                            <option value=\"11\">Summer Hit</option>\r\n"
        "                            <option value=\"12\">Dance Hook</option>\r\n"
        "                            <option value=\"13\">Radio Ready</option>\r\n"
        "                        </select>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"selector-group\">\r\n"
        "                        <label>RHYTHM</label>\r\n"
        "                        <select data-param=\"arp_rhythm_type\">\r\n"
        "                            <option value=\"0\">Classic Dembow</option>\r\n"
        "                            <option value=\"1\">Modern Dembow</option>\r\n"
        "                            <option value=\"2\">Half-Time Dembow</option>\r\n"
        "                            <option value=\"3\">Dembow Rom\x0c3\x0a1ntico</option>\r\n"
        "                            <option value=\"4\">Perreo Intenso</option>\r\n"
        "                            <option value=\"5\">Perreo Suave</option>\r\n"
        "                            <option value=\"6\">Flow Calle</option>\r\n"
        "                            <option value=\"7\">808 Bounce</option>\r\n"
        "                            <option value=\"8\">Hi-Hat Rolls</option>\r\n"
        "                            <option value=\"9\">Trap Latino</option>\r\n"
        "                            <option value=\"10\">Tresillo</option>\r\n"
        "                            <option value=\"11\">Clave</option>\r\n"
        "                        </select>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"selector-group\">\r\n"
        "                        <label>SCALE</label>\r\n"
        "                        <select data-param=\"arp_scale\">\r\n"
        "                            <option value=\"0\">Reggaeton Minor</option>\r\n"
        "                            <option value=\"1\">Reggaeton Major</option>\r\n"
        "                            <option value=\"2\">Trap Minor</option>\r\n"
        "                            <option value=\"3\">Latin Pop</option>\r\n"
        "                            <option value=\"4\">Sad Boy</option>\r\n"
        "                            <option value=\"5\">Perreo</option>\r\n"
        "                            <option value=\"6\">Romantic</option>\r\n"
        "                            <option value=\"7\">Callejero</option>\r\n"
        "                        </select>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"selector-group\">\r\n"
        "                        <label>KEY</label>\r\n"
        "                        <select data-param=\"arp_key\">\r\n"
        "                            <option value=\"0\">C</option>\r\n"
        "                            <option value=\"1\">C#</option>\r\n"
        "                            <option value=\"2\">D</option>\r\n"
        "                            <option value=\"3\">D#</option>\r\n"
        "                            <option value=\"4\">E</option>\r\n"
        "                            <option value=\"5\">F</option>\r\n"
        "                            <option value=\"6\">F#</option>\r\n"
        "                            <option value=\"7\">G</option>\r\n"
        "                            <option value=\"8\">G#</option>\r\n"
        "                            <option value=\"9\">A</option>\r\n"
        "                            <option value=\"10\">A#</option>\r\n"
        "                            <option value=\"11\">B</option>\r\n"
        "                        </select>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"arp-pattern-display\">\r\n"
        "                    <div class=\"pattern-step\" data-step=\"0\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"1\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"2\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"3\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"4\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"5\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"6\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"7\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"8\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"9\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"10\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"11\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"12\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"13\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"14\"><span class=\"note-label\"></span></div>\r\n"
        "                    <div class=\"pattern-step\" data-step=\"15\"><span class=\"note-label\"></span></div>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"arp-randomize-section\">\r\n"
        "                    <button class=\"randomize-btn-big\" id=\"randomize-btn\">\x0f0\x09f\x08e\x0b2 RANDOMIZE</button>\r\n"
        "                    <div class=\"selector-group\">\r\n"
        "                        <label>MODE:</label>\r\n"
        "                        <select data-param=\"arp_randomize_mode\" id=\"randomize-mode\">\r\n"
        "                            <option value=\"0\">HITMAKER</option>\r\n"
        "                            <option value=\"1\">VIBRAS</option>\r\n"
        "                            <option value=\"2\">EMOCIONES</option>\r\n"
        "                            <option value=\"3\">ALTURA</option>\r\n"
        "                            <option value=\"4\">PERREO</option>\r\n"
        "                            <option value=\"5\">EXPERIMENTAL</option>\r\n"
        "                        </select>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"complexity-control\">\r\n"
        "                        <label>COMPLEXITY:</label>\r\n"
        "                        <div class=\"complexity-dots\">\r\n"
        "                            <span class=\"dot active\" data-complexity=\"1\"></span>\r\n"
        "                            <span class=\"dot active\" data-complexity=\"2\"></span>\r\n"
        "                            <span class=\"dot active\" data-complexity=\"3\"></span>\r\n"
        "                            <span class=\"dot active\" data-complexity=\"4\"></span>\r\n"
        "                            <span class=\"dot active\" data-complexity=\"5\"></span>\r\n"
        "                            <span class=\"dot\" data-complexity=\"6\"></span>\r\n"
        "                            <span class=\"dot\" data-complexity=\"7\"></span>\r\n"
        "                            <span class=\"dot\" data-complexity=\"8\"></span>\r\n"
        "                            <span class=\"dot\" data-complexity=\"9\"></span>\r\n"
        "                            <span class=\"dot\" data-complexity=\"10\"></span>\r\n"
        "                        </div>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"arp-knobs-row\">\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob discrete\" data-param=\"arp_rate\" data-min=\"0\" data-max=\"8\" data-value=\"3\"></div>\r\n"
        "                        <label>RATE</label>\r\n"
        "                        <span class=\"value-display\">1/8</span>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob\" data-param=\"arp_swing\" data-min=\"0\" data-max=\"100\" data-value=\"0\"></div>\r\n"
        "                        <label>SWING</label>\r\n"
        "                        <span class=\"value-display\">0%</span>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob\" data-param=\"arp_gate\" data-min=\"1\" data-max=\"100\" data-value=\"75\"></div>\r\n"
        "                        <label>GATE</label>\r\n"
        "                        <span class=\"value-display\">75%</span>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob discrete\" data-param=\"arp_octaves\" data-min=\"1\" data-max=\"4\" data-value=\"1\"></div>\r\n"
        "                        <label>OCTAVES</label>\r\n"
        "                        <span class=\"value-display\">1</span>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"selector-group\">\r\n"
        "                        <label>DIRECTION</label>\r\n"
        "                        <select data-param=\"arp_direction\">\r\n"
        "                            <option value=\"0\">Up</option>\r\n"
        "                            <option value=\"1\">Down</option>\r\n"
        "                            <option value=\"2\">Up-Down</option>\r\n"
        "                            <option value=\"3\">Random</option>\r\n"
        "                        </select>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob\" data-param=\"arp_humanize\" data-min=\"0\" data-max=\"1\" data-value=\"0\"></div>\r\n"
        "                        <label>HUMANIZE</label>\r\n"
        "                        <span class=\"value-display\">0%</span>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "                \r\n"
        "                <div class=\"arp-variations\">\r\n"
        "                    <label>VARIATIONS:</label>\r\n"
        "                    <button class=\"variation-btn\" data-variation=\"octave-up\">\x0e2\x086\x091 OCT</button>\r\n"
        "                    <button class=\"variation-btn\" data-variation=\"octave-down\">\x0e2\x086\x093 OCT</button>\r\n"
        "                    <button class=\"variation-btn\" data-variation=\"invert\">INVERT</button>\r\n"
        "                    <button class=\"variation-btn\" data-variation=\"reverse\">REVERSE</button>\r\n"
        "                    <button class=\"variation-btn\" data-variation=\"simplify\">SIMPLE</button>\r\n"
        "                    <button class=\"variation-btn\" data-variation=\"double\">DOUBLE</button>\r\n"
        "                    <button class=\"variation-btn\" data-variation=\"shift-left\">\x0e2\x097\x084\x0e2\x097\x084</button>\r\n"
        "                    <button class=\"variation-btn\" data-variation=\"shift-right\">\x0e2\x096\x0ba\x0e2\x096\x0ba</button>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "        </div>\r\n"
        "\r\n"
        "        <!-- Bottom Controls -->\r\n"
        "        <div class=\"bottom-section\">\r\n"
        "            <div class=\"envelope-section\">\r\n"
        "                <h3>ENVELOPE</h3>\r\n"
        "                <div class=\"env-controls\">\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob\" data-param=\"amp_attack\" data-min=\"0.001\" data-max=\"5\" data-value=\"0.01\"></div>\r\n"
        "                        <label>A</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob\" data-param=\"amp_decay\" data-min=\"0.001\" data-max=\"5\" data-value=\"0.1\"></div>\r\n"
        "                        <label>D</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob\" data-param=\"amp_sustain\" data-min=\"0\" data-max=\"1\" data-value=\"0.7\"></div>\r\n"
        "                        <label>S</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob\" data-param=\"amp_release\" data-min=\"0.001\" data-max=\"10\" data-value=\"0.3\"></div>\r\n"
        "                        <label>R</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "\r\n"
        "            <div class=\"lfo-section\">\r\n"
        "                <h3>LFO</h3>\r\n"
        "                <div class=\"lfo-controls\">\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob\" data-param=\"lfo_rate\" data-min=\"0.01\" data-max=\"20\" data-value=\"2\"></div>\r\n"
        "                        <label>Rate</label>\r\n"
        "                    </div>\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob\" data-param=\"lfo_to_pitch\" data-min=\"0\" data-max=\"1\" data-value=\"0\"></div>\r\n"
        "                        <label>Pitch</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "\r\n"
        "            <div class=\"master-section\">\r\n"
        "                <h3>MASTER</h3>\r\n"
        "                <div class=\"master-controls\">\r\n"
        "                    <div class=\"knob-control\">\r\n"
        "                        <div class=\"knob large\" data-param=\"master_volume\" data-min=\"0\" data-max=\"1\" data-value=\"0.7\"></div>\r\n"
        "                        <label>VOLUME</label>\r\n"
        "                    </div>\r\n"
        "                </div>\r\n"
        "            </div>\r\n"
        "        </div>\r\n"
        "    </div>\r\n"
        "\r\n"
        "    <script src=\"main.js\"></script>\r\n"
        "</body>\r\n"
        "</html>\r\n";
    static constexpr const char* ui_mainvintage_js =
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   CINTA - 1975 HAVANA STUDIO VINTAGE UI - JAVASCRIPT\r\n"
        "   Handles knob interactions, VU meter animation, tape reel animation,\r\n"
        "   LED indicators, and Cmajor patch connection\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        "let patchConnection = null;\r\n"
        "let audioLevel = 0;\r\n"
        "let isPlaying = false;\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// KNOB CLASS - Chicken-Head Style Knobs\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "class Knob {\r\n"
        "    constructor(element) {\r\n"
        "        this.element = element;\r\n"
        "        this.param = element.dataset.param;\r\n"
        "        this.min = parseFloat(element.dataset.min);\r\n"
        "        this.max = parseFloat(element.dataset.max);\r\n"
        "        this.value = parseFloat(element.dataset.value);\r\n"
        "        this.curve = element.dataset.curve || 'linear';\r\n"
        "        \r\n"
        "        this.isDragging = false;\r\n"
        "        this.startY = 0;\r\n"
        "        this.startValue = 0;\r\n"
        "        \r\n"
        "        // Create pointer if it doesn't exist\r\n"
        "        if (!this.element.querySelector('.knob-pointer')) {\r\n"
        "            const pointer = document.createElement('div');\r\n"
        "            pointer.className = 'knob-pointer';\r\n"
        "            this.element.appendChild(pointer);\r\n"
        "        }\r\n"
        "        this.pointer = this.element.querySelector('.knob-pointer');\r\n"
        "        \r\n"
        "        this.element.addEventListener('mousedown', this.onMouseDown.bind(this));\r\n"
        "        document.addEventListener('mousemove', this.onMouseMove.bind(this));\r\n"
        "        document.addEventListener('mouseup', this.onMouseUp.bind(this));\r\n"
        "        \r\n"
        "        this.updateRotation();\r\n"
        "    }\r\n"
        "    \r\n"
        "    onMouseDown(e) {\r\n"
        "        this.isDragging = true;\r\n"
        "        this.startY = e.clientY;\r\n"
        "        this.startValue = this.value;\r\n"
        "        e.preventDefault();\r\n"
        "    }\r\n"
        "    \r\n"
        "    onMouseMove(e) {\r\n"
        "        if (!this.isDragging) return;\r\n"
        "        \r\n"
        "        const delta = (this.startY - e.clientY) * 0.01;\r\n"
        "        const range = this.max - this.min;\r\n"
        "        let newValue = this.startValue + (delta * range);\r\n"
        "        \r\n"
        "        newValue = Math.max(this.min, Math.min(this.max, newValue));\r\n"
        "        \r\n"
        "        this.setValue(newValue);\r\n"
        "    }\r\n"
        "    \r\n"
        "    onMouseUp() {\r\n"
        "        this.isDragging = false;\r\n"
        "    }\r\n"
        "    \r\n"
        "    setValue(value) {\r\n"
        "        this.value = value;\r\n"
        "        this.updateRotation();\r\n"
        "        this.sendToEngine();\r\n"
        "        this.updateNixieDisplay();\r\n"
        "    }\r\n"
        "    \r\n"
        "    updateRotation() {\r\n"
        "        const normalized = (this.value - this.min) / (this.max - this.min);\r\n"
        "        const degrees = -135 + (normalized * 270);\r\n"
        "        if (this.pointer) {\r\n"
        "            this.pointer.style.transform = `translateX(-50%) rotate(${degrees}deg)`;\r\n"
        "        }\r\n"
        "    }\r\n"
        "    \r\n"
        "    sendToEngine() {\r\n"
        "        if (patchConnection) {\r\n"
        "            try {\r\n"
        "                patchConnection.sendParameterValue(this.param, this.value);\r\n"
        "            } catch (error) {\r\n"
        "                console.error(`Failed to send ${this.param}:`, error);\r\n"
        "            }\r\n"
        "        }\r\n"
        "    }\r\n"
        "    \r\n"
        "    updateNixieDisplay() {\r\n"
        "        // Update nixie tube display if present\r\n"
        "        const nixieDisplay = this.element.parentElement.querySelector('.nixie-display');\r\n"
        "        if (nixieDisplay) {\r\n"
        "            const digits = nixieDisplay.querySelectorAll('.nixie-digit');\r\n"
        "            const valueStr = this.value.toFixed(1);\r\n"
        "            const chars = valueStr.split('');\r\n"
        "            \r\n"
        "            digits.forEach((digit, index) => {\r\n"
        "                if (index < chars.length) {\r\n"
        "                    digit.textContent = chars[index];\r\n"
        "                }\r\n"
        "            });\r\n"
        "        }\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// TOGGLE BUTTON CLASS\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "class ToggleButton {\r\n"
        "    constructor(element) {\r\n"
        "        this.element = element;\r\n"
        "        this.param = element.dataset.param;\r\n"
        "        this.isActive = element.classList.contains('active');\r\n"
        "        \r\n"
        "        this.element.addEventListener('click', this.toggle.bind(this));\r\n"
        "        \r\n"
        "        // Update LED indicator\r\n"
        "        this.updateLED();\r\n"
        "    }\r\n"
        "    \r\n"
        "    toggle() {\r\n"
        "        this.isActive = !this.isActive;\r\n"
        "        \r\n"
        "        if (this.isActive) {\r\n"
        "            this.element.classList.add('active');\r\n"
        "            this.element.textContent = 'ON';\r\n"
        "        } else {\r\n"
        "            this.element.classList.remove('active');\r\n"
        "            this.element.textContent = 'OFF';\r\n"
        "        }\r\n"
        "        \r\n"
        "        this.updateLED();\r\n"
        "        this.sendToEngine();\r\n"
        "    }\r\n"
        "    \r\n"
        "    updateLED() {\r\n"
        "        const led = this.element.parentElement.querySelector('.led-indicator');\r\n"
        "        if (led) {\r\n"
        "            if (this.isActive) {\r\n"
        "                led.classList.add('on');\r\n"
        "            } else {\r\n"
        "                led.classList.remove('on');\r\n"
        "            }\r\n"
        "        }\r\n"
        "    }\r\n"
        "    \r\n"
        "    sendToEngine() {\r\n"
        "        if (patchConnection) {\r\n"
        "            try {\r\n"
        "                const value = this.isActive ? 1.0 : 0.0;\r\n"
        "                patchConnection.sendParameterValue(this.param, value);\r\n"
        "            } catch (error) {\r\n"
        "                console.error(`Failed to send ${this.param}:`, error);\r\n"
        "            }\r\n"
        "        }\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// VU METER ANIMATION\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "function updateVUMeter() {\r\n"
        "    const vuMeter = document.getElementById('vu-meter');\r\n"
        "    if (!vuMeter) return;\r\n"
        "    \r\n"
        "    // Simulate audio level (in real implementation, get from audio engine)\r\n"
        "    // Random movement for demo purposes\r\n"
        "    audioLevel += (Math.random() - 0.5) * 0.2;\r\n"
        "    audioLevel = Math.max(0, Math.min(1, audioLevel));\r\n"
        "    \r\n"
        "    // Determine level category\r\n"
        "    let levelCategory = 'low';\r\n"
        "    if (audioLevel > 0.8) levelCategory = 'clip';\r\n"
        "    else if (audioLevel > 0.6) levelCategory = 'high';\r\n"
        "    else if (audioLevel > 0.3) levelCategory = 'mid';\r\n"
        "    \r\n"
        "    vuMeter.setAttribute('data-level', levelCategory);\r\n"
        "    \r\n"
        "    // Continue animation\r\n"
        "    if (isPlaying) {\r\n"
        "        requestAnimationFrame(updateVUMeter);\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// TAPE DECK ANIMATION\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "function startTapeDeck() {\r\n"
        "    const tapeDeck = document.getElementById('tape-deck');\r\n"
        "    if (tapeDeck) {\r\n"
        "        tapeDeck.classList.add('playing');\r\n"
        "    }\r\n"
        "    isPlaying = true;\r\n"
        "    updateVUMeter();\r\n"
        "}\r\n"
        "\r\n"
        "function stopTapeDeck() {\r\n"
        "    const tapeDeck = document.getElementById('tape-deck');\r\n"
        "    if (tapeDeck) {\r\n"
        "        tapeDeck.classList.remove('playing');\r\n"
        "    }\r\n"
        "    isPlaying = false;\r\n"
        "}\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// KEY SELECTOR\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "function initializeKeySelector() {\r\n"
        "    const keyButtons = document.querySelectorAll('.key-btn');\r\n"
        "    \r\n"
        "    keyButtons.forEach(button => {\r\n"
        "        button.addEventListener('click', () => {\r\n"
        "            // Remove active from all\r\n"
        "            keyButtons.forEach(btn => btn.classList.remove('active'));\r\n"
        "            // Add active to clicked\r\n"
        "            button.classList.add('active');\r\n"
        "            \r\n"
        "            // Send to engine\r\n"
        "            if (patchConnection) {\r\n"
        "                try {\r\n"
        "                    const key = parseInt(button.dataset.key);\r\n"
        "                    patchConnection.sendParameterValue('arp_key', key);\r\n"
        "                } catch (error) {\r\n"
        "                    console.error('Failed to send arp_key:', error);\r\n"
        "                }\r\n"
        "            }\r\n"
        "        });\r\n"
        "    });\r\n"
        "}\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// VARIATION BUTTONS\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "function initializeVariationButtons() {\r\n"
        "    const varButtons = document.querySelectorAll('.var-btn');\r\n"
        "    \r\n"
        "    varButtons.forEach(button => {\r\n"
        "        button.addEventListener('click', () => {\r\n"
        "            const variation = button.dataset.variation;\r\n"
        "            console.log('Variation:', variation);\r\n"
        "            \r\n"
        "            // Visual feedback\r\n"
        "            button.style.transform = 'translateY(0)';\r\n"
        "            setTimeout(() => {\r\n"
        "                button.style.transform = '';\r\n"
        "            }, 100);\r\n"
        "            \r\n"
        "            // Send to engine (implement variation logic)\r\n"
        "            if (patchConnection) {\r\n"
        "                try {\r\n"
        "                    patchConnection.sendParameterValue('arp_variation', parseFloat(variation));\r\n"
        "                } catch (error) {\r\n"
        "                    console.error('Failed to send arp_variation:', error);\r\n"
        "                }\r\n"
        "            }\r\n"
        "        });\r\n"
        "    });\r\n"
        "}\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// RANDOMIZE BUTTON\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "function initializeRandomizeButton() {\r\n"
        "    const randomizeBtn = document.getElementById('randomize');\r\n"
        "    \r\n"
        "    if (randomizeBtn) {\r\n"
        "        randomizeBtn.addEventListener('click', () => {\r\n"
        "            console.log('Randomize clicked');\r\n"
        "            \r\n"
        "            // Visual feedback\r\n"
        "            randomizeBtn.style.transform = 'scale(0.95)';\r\n"
        "            setTimeout(() => {\r\n"
        "                randomizeBtn.style.transform = '';\r\n"
        "            }, 100);\r\n"
        "            \r\n"
        "            // Randomize pattern display\r\n"
        "            const steps = document.querySelectorAll('.pattern-step');\r\n"
        "            steps.forEach(step => {\r\n"
        "                if (Math.random() > 0.5) {\r\n"
        "                    step.classList.add('active');\r\n"
        "                } else {\r\n"
        "                    step.classList.remove('active');\r\n"
        "                }\r\n"
        "            });\r\n"
        "            \r\n"
        "            // Send to engine\r\n"
        "            if (patchConnection) {\r\n"
        "                try {\r\n"
        "                    patchConnection.sendParameterValue('arp_randomize', 1.0);\r\n"
        "                } catch (error) {\r\n"
        "                    console.error('Failed to send arp_randomize:', error);\r\n"
        "                }\r\n"
        "            }\r\n"
        "        });\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// PRESET BROWSER\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "function initializePresetBrowser() {\r\n"
        "    const presetSelect = document.getElementById('preset-select');\r\n"
        "    const prevBtn = document.querySelector('.preset-btn.prev');\r\n"
        "    const nextBtn = document.querySelector('.preset-btn.next');\r\n"
        "    const saveBtn = document.querySelector('.preset-btn.save');\r\n"
        "    \r\n"
        "    if (presetSelect) {\r\n"
        "        presetSelect.addEventListener('change', () => {\r\n"
        "            console.log('Preset changed:', presetSelect.value);\r\n"
        "            // Load preset (implement preset loading)\r\n"
        "        });\r\n"
        "    }\r\n"
        "    \r\n"
        "    if (prevBtn) {\r\n"
        "        prevBtn.addEventListener('click', () => {\r\n"
        "            if (presetSelect) {\r\n"
        "                const currentIndex = presetSelect.selectedIndex;\r\n"
        "                if (currentIndex > 0) {\r\n"
        "                    presetSelect.selectedIndex = currentIndex - 1;\r\n"
        "                    presetSelect.dispatchEvent(new Event('change'));\r\n"
        "                }\r\n"
        "            }\r\n"
        "        });\r\n"
        "    }\r\n"
        "    \r\n"
        "    if (nextBtn) {\r\n"
        "        nextBtn.addEventListener('click', () => {\r\n"
        "            if (presetSelect) {\r\n"
        "                const currentIndex = presetSelect.selectedIndex;\r\n"
        "                if (currentIndex < presetSelect.options.length - 1) {\r\n"
        "                    presetSelect.selectedIndex = currentIndex + 1;\r\n"
        "                    presetSelect.dispatchEvent(new Event('change'));\r\n"
        "                }\r\n"
        "            }\r\n"
        "        });\r\n"
        "    }\r\n"
        "    \r\n"
        "    if (saveBtn) {\r\n"
        "        saveBtn.addEventListener('click', () => {\r\n"
        "            console.log('Save preset');\r\n"
        "            // Implement preset saving\r\n"
        "        });\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// MIDI NOTE HANDLING (for tape deck animation)\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "function handleMIDINote(noteOn) {\r\n"
        "    if (noteOn) {\r\n"
        "        startTapeDeck();\r\n"
        "    } else {\r\n"
        "        // Keep playing for a moment after note off\r\n"
        "        setTimeout(() => {\r\n"
        "            const activeNotes = 0; // Check if any notes are still playing\r\n"
        "            if (activeNotes === 0) {\r\n"
        "                stopTapeDeck();\r\n"
        "            }\r\n"
        "        }, 500);\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// INITIALIZATION\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "function initializeUI() {\r\n"
        "    console.log('CINTA Vintage UI: Initializing...');\r\n"
        "    \r\n"
        "    // Initialize all knobs\r\n"
        "    const knobs = document.querySelectorAll('.knob');\r\n"
        "    knobs.forEach(knobElement => new Knob(knobElement));\r\n"
        "    \r\n"
        "    // Initialize all toggle buttons\r\n"
        "    const toggleButtons = document.querySelectorAll('.toggle-btn');\r\n"
        "    toggleButtons.forEach(buttonElement => new ToggleButton(buttonElement));\r\n"
        "    \r\n"
        "    // Initialize selectors\r\n"
        "    const selects = document.querySelectorAll('select[data-param]');\r\n"
        "    selects.forEach(select => {\r\n"
        "        select.addEventListener('change', () => {\r\n"
        "            if (patchConnection) {\r\n"
        "                try {\r\n"
        "                    const value = parseFloat(select.value);\r\n"
        "                    patchConnection.sendParameterValue(select.dataset.param, value);\r\n"
        "                } catch (error) {\r\n"
        "                    console.error(`Failed to send ${select.dataset.param}:`, error);\r\n"
        "                }\r\n"
        "            }\r\n"
        "        });\r\n"
        "    });\r\n"
        "    \r\n"
        "    // Initialize key selector\r\n"
        "    initializeKeySelector();\r\n"
        "    \r\n"
        "    // Initialize variation buttons\r\n"
        "    initializeVariationButtons();\r\n"
        "    \r\n"
        "    // Initialize randomize button\r\n"
        "    initializeRandomizeButton();\r\n"
        "    \r\n"
        "    // Initialize preset browser\r\n"
        "    initializePresetBrowser();\r\n"
        "    \r\n"
        "    console.log('CINTA Vintage UI: Initialized successfully');\r\n"
        "}\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// CMAJOR PATCH CONNECTION\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "window.addEventListener('load', async () => {\r\n"
        "    console.log('CINTA: Window loaded');\r\n"
        "    initializeUI();\r\n"
        "    \r\n"
        "    if (window.cmajor) {\r\n"
        "        console.log('CINTA: Cmajor API detected, connecting...');\r\n"
        "        try {\r\n"
        "            patchConnection = await window.cmajor.createPatchConnection();\r\n"
        "            \r\n"
        "            if (patchConnection) {\r\n"
        "                console.log('\x0e2\x09c\x085 CINTA: Connected to Cmajor patch');\r\n"
        "                \r\n"
        "                // Get available parameters\r\n"
        "                try {\r\n"
        "                    const params = await patchConnection.getParameters();\r\n"
        "                    console.log(`CINTA: Found ${params.length} parameters`);\r\n"
        "                } catch (e) {\r\n"
        "                    console.log('CINTA: Could not get parameter list');\r\n"
        "                }\r\n"
        "                \r\n"
        "                // Send initial values to engine\r\n"
        "                console.log('CINTA: Sending initial parameter values...');\r\n"
        "                const knobs = document.querySelectorAll('.knob');\r\n"
        "                knobs.forEach(knobElement => {\r\n"
        "                    const param = knobElement.dataset.param;\r\n"
        "                    const value = parseFloat(knobElement.dataset.value);\r\n"
        "                    if (param) {\r\n"
        "                        try {\r\n"
        "                            patchConnection.sendParameterValue(param, value);\r\n"
        "                        } catch (e) {\r\n"
        "                            console.warn(`Could not send ${param}`);\r\n"
        "                        }\r\n"
        "                    }\r\n"
        "                });\r\n"
        "                \r\n"
        "                const toggleButtons = document.querySelectorAll('.toggle-btn');\r\n"
        "                toggleButtons.forEach(buttonElement => {\r\n"
        "                    const param = buttonElement.dataset.param;\r\n"
        "                    const isActive = buttonElement.classList.contains('active');\r\n"
        "                    if (param) {\r\n"
        "                        try {\r\n"
        "                            patchConnection.sendParameterValue(param, isActive ? 1.0 : 0.0);\r\n"
        "                        } catch (e) {\r\n"
        "                            console.warn(`Could not send ${param}`);\r\n"
        "                        }\r\n"
        "                    }\r\n"
        "                });\r\n"
        "                \r\n"
        "                const selects = document.querySelectorAll('select[data-param]');\r\n"
        "                selects.forEach(select => {\r\n"
        "                    const param = select.dataset.param;\r\n"
        "                    const value = parseFloat(select.value);\r\n"
        "                    if (param) {\r\n"
        "                        try {\r\n"
        "                            patchConnection.sendParameterValue(param, value);\r\n"
        "                        } catch (e) {\r\n"
        "                            console.warn(`Could not send ${param}`);\r\n"
        "                        }\r\n"
        "                    }\r\n"
        "                });\r\n"
        "                \r\n"
        "                console.log('\x0e2\x09c\x085 CINTA: All initial values sent');\r\n"
        "                \r\n"
        "                // Listen for parameter changes from patch\r\n"
        "                if (patchConnection.addParameterListener) {\r\n"
        "                    patchConnection.addParameterListener((paramID, value) => {\r\n"
        "                        console.log(`Parameter changed: ${paramID} = ${value}`);\r\n"
        "                        // Update UI to reflect parameter change\r\n"
        "                        const knob = document.querySelector(`[data-param=\"${paramID}\"]`);\r\n"
        "                        if (knob && knob.classList.contains('knob')) {\r\n"
        "                            const knobInstance = knob.knobInstance;\r\n"
        "                            if (knobInstance) {\r\n"
        "                                knobInstance.value = value;\r\n"
        "                                knobInstance.updateRotation();\r\n"
        "                                knobInstance.updateNixieDisplay();\r\n"
        "                            }\r\n"
        "                        }\r\n"
        "                    });\r\n"
        "                }\r\n"
        "                \r\n"
        "                // Start animations\r\n"
        "                startTapeDeck();\r\n"
        "            }\r\n"
        "        } catch (error) {\r\n"
        "            console.error('\x0e2\x09d\x08c CINTA: Failed to connect to patch:', error);\r\n"
        "            console.log('CINTA: Falling back to standalone mode');\r\n"
        "            startTapeDeck();\r\n"
        "        }\r\n"
        "    } else {\r\n"
        "        console.log('CINTA: Running in standalone mode (no Cmajor API)');\r\n"
        "        // Start demo animation\r\n"
        "        startTapeDeck();\r\n"
        "    }\r\n"
        "});\r\n"
        "\r\n"
        "window.addEventListener('beforeunload', () => {\r\n"
        "    if (patchConnection) {\r\n"
        "        patchConnection.disconnect();\r\n"
        "    }\r\n"
        "});\r\n"
        "\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "// DEMO MODE - Simulate activity when not connected to Cmajor\r\n"
        "// \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "\r\n"
        "if (!window.cmajor) {\r\n"
        "    // Simulate some activity for demo purposes\r\n"
        "    setInterval(() => {\r\n"
        "        // Random LED flicker\r\n"
        "        const leds = document.querySelectorAll('.led-indicator');\r\n"
        "        if (leds.length > 0 && Math.random() > 0.95) {\r\n"
        "            const randomLed = leds[Math.floor(Math.random() * leds.length)];\r\n"
        "            randomLed.classList.toggle('on');\r\n"
        "        }\r\n"
        "    }, 1000);\r\n"
        "}\r\n";
    static constexpr const char* ui_main_js =
        "let patchConnection = null;\r\n"
        "let currentComplexity = 5;\r\n"
        "\r\n"
        "const tapeSoundNames = ['Strings', 'Flutes', 'Choirs', 'Brass', 'Keys'];\r\n"
        "const waveNames = ['Saw', 'Square', 'Pulse', 'Triangle'];\r\n"
        "const rateNames = ['1/1', '1/2', '1/4', '1/8', '1/16', '1/32', '1/4T', '1/8T', '1/16T'];\r\n"
        "\r\n"
        "const melodyPatterns = [\r\n"
        "    [1, 0, 7, 0, 1, 0, 7, 0, 1, 0, 7, 0, 1, 0, 7, 0],\r\n"
        "    [5, 0, 4, 0, 3, 0, 1, 0, 5, 0, 4, 0, 3, 0, 1, 0],\r\n"
        "    [1, 0, 3, 0, 5, 0, 0, 0, 1, 0, 3, 0, 5, 0, 0, 0],\r\n"
        "    [1, 0, 5, 0, 7, 0, 5, 0, 1, 0, 5, 0, 7, 0, 5, 0],\r\n"
        "    [1, 0, 3, 0, 5, 0, 6, 0, 5, 0, 3, 0, 1, 0, 0, 0],\r\n"
        "    [1, 1, 0, 7, 0, 5, 0, 0, 1, 1, 0, 7, 0, 5, 0, 0],\r\n"
        "    [5, 0, 6, 0, 7, 0, 1, 7, 5, 0, 6, 0, 7, 0, 1, 7],\r\n"
        "    [1, 0, 2, 0, 1, 0, 7, 0, 1, 0, 2, 0, 1, 0, 7, 0],\r\n"
        "    [1, 0, 3, 0, 4, 0, 5, 0, 7, 0, 5, 0, 4, 0, 3, 0],\r\n"
        "    [1, 1, 0, 3, 0, 1, 0, 0, 1, 1, 0, 3, 0, 1, 0, 0],\r\n"
        "    [1, 0, 3, 0, 4, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0],\r\n"
        "    [1, 0, 3, 0, 5, 0, 6, 0, 5, 0, 3, 0, 1, 0, 0, 0],\r\n"
        "    [1, 0, 5, 0, 1, 0, 5, 0, 7, 0, 5, 0, 1, 0, 0, 0],\r\n"
        "    [1, 0, 2, 0, 3, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0]\r\n"
        "];\r\n"
        "\r\n"
        "const rhythmPatterns = [\r\n"
        "    [100, 0, 0, 80, 0, 0, 100, 0, 0, 80, 0, 0, 100, 0, 0, 80],\r\n"
        "    [100, 0, 60, 90, 0, 60, 100, 0, 60, 90, 0, 60, 100, 0, 60, 90],\r\n"
        "    [100, 0, 0, 0, 0, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0],\r\n"
        "    [80, 0, 0, 60, 0, 0, 70, 0, 0, 60, 0, 0, 80, 0, 0, 60],\r\n"
        "    [100, 0, 100, 0, 80, 0, 100, 0, 100, 0, 80, 0, 100, 0, 100, 0],\r\n"
        "    [70, 0, 0, 60, 0, 0, 70, 0, 0, 60, 0, 0, 70, 0, 0, 60],\r\n"
        "    [100, 50, 0, 100, 0, 50, 100, 0, 0, 100, 50, 0, 100, 0, 50, 0],\r\n"
        "    [100, 0, 0, 0, 0, 0, 0, 100, 0, 0, 100, 0, 0, 0, 0, 0],\r\n"
        "    [60, 60, 60, 80, 60, 60, 60, 80, 60, 60, 100, 80, 60, 60, 60, 80],\r\n"
        "    [100, 0, 60, 0, 80, 0, 60, 0, 100, 0, 60, 0, 80, 60, 0, 60],\r\n"
        "    [100, 0, 0, 100, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0],\r\n"
        "    [100, 0, 0, 100, 0, 0, 0, 100, 0, 0, 100, 0, 100, 0, 0, 0]\r\n"
        "];\r\n"
        "\r\n"
        "const scales = [\r\n"
        "    [0, 2, 3, 5, 7, 8, 10],\r\n"
        "    [0, 2, 4, 5, 7, 9, 11],\r\n"
        "    [0, 2, 3, 5, 7, 8, 11],\r\n"
        "    [0, 2, 4, 7, 9],\r\n"
        "    [0, 2, 3, 5, 7, 9, 10],\r\n"
        "    [0, 3, 5, 7, 10],\r\n"
        "    [0, 2, 4, 5, 7, 9, 11],\r\n"
        "    [0, 1, 4, 5, 7, 8, 10]\r\n"
        "];\r\n"
        "\r\n"
        "const noteNames = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'];\r\n"
        "\r\n"
        "let currentMelodyPattern = [...melodyPatterns[0]];\r\n"
        "let currentRhythmPattern = [...rhythmPatterns[0]];\r\n"
        "\r\n"
        "class Knob {\r\n"
        "    constructor(element) {\r\n"
        "        this.element = element;\r\n"
        "        this.param = element.dataset.param;\r\n"
        "        this.min = parseFloat(element.dataset.min);\r\n"
        "        this.max = parseFloat(element.dataset.max);\r\n"
        "        this.value = parseFloat(element.dataset.value);\r\n"
        "        this.isDiscrete = element.classList.contains('discrete');\r\n"
        "        \r\n"
        "        this.isDragging = false;\r\n"
        "        this.startY = 0;\r\n"
        "        this.startValue = 0;\r\n"
        "        \r\n"
        "        this.element.addEventListener('mousedown', this.onMouseDown.bind(this));\r\n"
        "        document.addEventListener('mousemove', this.onMouseMove.bind(this));\r\n"
        "        document.addEventListener('mouseup', this.onMouseUp.bind(this));\r\n"
        "        \r\n"
        "        this.updateRotation();\r\n"
        "    }\r\n"
        "    \r\n"
        "    onMouseDown(e) {\r\n"
        "        this.isDragging = true;\r\n"
        "        this.startY = e.clientY;\r\n"
        "        this.startValue = this.value;\r\n"
        "        e.preventDefault();\r\n"
        "    }\r\n"
        "    \r\n"
        "    onMouseMove(e) {\r\n"
        "        if (!this.isDragging) return;\r\n"
        "        \r\n"
        "        const delta = (this.startY - e.clientY) * 0.01;\r\n"
        "        const range = this.max - this.min;\r\n"
        "        let newValue = this.startValue + (delta * range);\r\n"
        "        \r\n"
        "        newValue = Math.max(this.min, Math.min(this.max, newValue));\r\n"
        "        \r\n"
        "        if (this.isDiscrete) {\r\n"
        "            newValue = Math.round(newValue);\r\n"
        "        }\r\n"
        "        \r\n"
        "        this.setValue(newValue);\r\n"
        "    }\r\n"
        "    \r\n"
        "    onMouseUp() {\r\n"
        "        this.isDragging = false;\r\n"
        "    }\r\n"
        "    \r\n"
        "    setValue(value) {\r\n"
        "        this.value = value;\r\n"
        "        this.updateRotation();\r\n"
        "        this.sendToEngine();\r\n"
        "        this.updateDisplay();\r\n"
        "    }\r\n"
        "    \r\n"
        "    updateRotation() {\r\n"
        "        const normalized = (this.value - this.min) / (this.max - this.min);\r\n"
        "        const degrees = -135 + (normalized * 270);\r\n"
        "        this.element.style.transform = `rotate(${degrees}deg)`;\r\n"
        "    }\r\n"
        "    \r\n"
        "    sendToEngine() {\r\n"
        "        if (patchConnection) {\r\n"
        "            patchConnection.sendEventOrValue(this.param, this.value);\r\n"
        "        }\r\n"
        "    }\r\n"
        "    \r\n"
        "    updateDisplay() {\r\n"
        "        const control = this.element.closest('.knob-control');\r\n"
        "        if (!control) return;\r\n"
        "        \r\n"
        "        const valueDisplay = control.querySelector('.value-display');\r\n"
        "        if (valueDisplay) {\r\n"
        "            if (this.param === 'tape_sound') {\r\n"
        "                valueDisplay.textContent = tapeSoundNames[Math.round(this.value)] || '';\r\n"
        "            } else if (this.param.includes('wave')) {\r\n"
        "                valueDisplay.textContent = waveNames[Math.round(this.value)] || '';\r\n"
        "            } else if (this.param === 'arp_rate') {\r\n"
        "                valueDisplay.textContent = rateNames[Math.round(this.value)] || '';\r\n"
        "            } else if (this.param === 'arp_swing' || this.param === 'arp_gate') {\r\n"
        "                valueDisplay.textContent = Math.round(this.value) + '%';\r\n"
        "            } else if (this.param === 'arp_humanize') {\r\n"
        "                valueDisplay.textContent = Math.round(this.value * 100) + '%';\r\n"
        "            } else if (this.param === 'arp_octaves') {\r\n"
        "                valueDisplay.textContent = Math.round(this.value);\r\n"
        "            }\r\n"
        "        }\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "class Toggle {\r\n"
        "    constructor(element) {\r\n"
        "        this.element = element;\r\n"
        "        this.param = element.dataset.param;\r\n"
        "        this.element.addEventListener('change', this.onChange.bind(this));\r\n"
        "    }\r\n"
        "    \r\n"
        "    onChange() {\r\n"
        "        const value = this.element.checked ? 1 : 0;\r\n"
        "        if (patchConnection) {\r\n"
        "            patchConnection.sendEventOrValue(this.param, value);\r\n"
        "        }\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "class Selector {\r\n"
        "    constructor(element) {\r\n"
        "        this.element = element;\r\n"
        "        this.param = element.dataset.param;\r\n"
        "        this.element.addEventListener('change', this.onChange.bind(this));\r\n"
        "    }\r\n"
        "    \r\n"
        "    onChange() {\r\n"
        "        const value = parseFloat(this.element.value);\r\n"
        "        if (patchConnection) {\r\n"
        "            patchConnection.sendEventOrValue(this.param, value);\r\n"
        "        }\r\n"
        "        \r\n"
        "        if (this.param === 'arp_melody_type') {\r\n"
        "            currentMelodyPattern = [...melodyPatterns[Math.round(value)]];\r\n"
        "            updatePatternDisplay();\r\n"
        "        } else if (this.param === 'arp_rhythm_type') {\r\n"
        "            currentRhythmPattern = [...rhythmPatterns[Math.round(value)]];\r\n"
        "            updatePatternDisplay();\r\n"
        "        } else if (this.param === 'arp_scale' || this.param === 'arp_key') {\r\n"
        "            updatePatternDisplay();\r\n"
        "        }\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "function updatePatternDisplay() {\r\n"
        "    const steps = document.querySelectorAll('.pattern-step');\r\n"
        "    const keySelect = document.querySelector('select[data-param=\"arp_key\"]');\r\n"
        "    const scaleSelect = document.querySelector('select[data-param=\"arp_scale\"]');\r\n"
        "    \r\n"
        "    const key = keySelect ? parseInt(keySelect.value) : 0;\r\n"
        "    const scaleIndex = scaleSelect ? parseInt(scaleSelect.value) : 0;\r\n"
        "    const scale = scales[scaleIndex];\r\n"
        "    \r\n"
        "    steps.forEach((step, index) => {\r\n"
        "        const velocity = currentRhythmPattern[index];\r\n"
        "        const scaleDegree = currentMelodyPattern[index];\r\n"
        "        \r\n"
        "        if (velocity > 0 && scaleDegree > 0) {\r\n"
        "            step.classList.add('active');\r\n"
        "            \r\n"
        "            const degree = (scaleDegree - 1) % scale.length;\r\n"
        "            const octaveOffset = Math.floor((scaleDegree - 1) / scale.length) * 12;\r\n"
        "            const noteOffset = scale[degree] + octaveOffset;\r\n"
        "            const midiNote = (key + 48 + noteOffset) % 12;\r\n"
        "            const noteName = noteNames[midiNote];\r\n"
        "            \r\n"
        "            const noteLabel = step.querySelector('.note-label');\r\n"
        "            if (noteLabel) {\r\n"
        "                noteLabel.textContent = noteName;\r\n"
        "            }\r\n"
        "        } else {\r\n"
        "            step.classList.remove('active');\r\n"
        "            const noteLabel = step.querySelector('.note-label');\r\n"
        "            if (noteLabel) {\r\n"
        "                noteLabel.textContent = '';\r\n"
        "            }\r\n"
        "        }\r\n"
        "    });\r\n"
        "}\r\n"
        "\r\n"
        "function initializeUI() {\r\n"
        "    const knobs = document.querySelectorAll('.knob');\r\n"
        "    knobs.forEach(knobElement => new Knob(knobElement));\r\n"
        "    \r\n"
        "    const toggles = document.querySelectorAll('input[type=\"checkbox\"][data-param]');\r\n"
        "    toggles.forEach(toggleElement => new Toggle(toggleElement));\r\n"
        "    \r\n"
        "    const selectors = document.querySelectorAll('select[data-param]');\r\n"
        "    selectors.forEach(selectorElement => new Selector(selectorElement));\r\n"
        "    \r\n"
        "    const randomizeBtn = document.getElementById('randomize-btn');\r\n"
        "    if (randomizeBtn) {\r\n"
        "        randomizeBtn.addEventListener('click', smartRandomize);\r\n"
        "    }\r\n"
        "    \r\n"
        "    const complexityDots = document.querySelectorAll('.dot');\r\n"
        "    complexityDots.forEach(dot => {\r\n"
        "        dot.addEventListener('click', () => {\r\n"
        "            const complexity = parseInt(dot.dataset.complexity);\r\n"
        "            setComplexity(complexity);\r\n"
        "        });\r\n"
        "    });\r\n"
        "    \r\n"
        "    const variationBtns = document.querySelectorAll('.variation-btn');\r\n"
        "    variationBtns.forEach(btn => {\r\n"
        "        btn.addEventListener('click', () => {\r\n"
        "            const variation = btn.dataset.variation;\r\n"
        "            applyVariation(variation);\r\n"
        "        });\r\n"
        "    });\r\n"
        "    \r\n"
        "    updatePatternDisplay();\r\n"
        "}\r\n"
        "\r\n"
        "function setComplexity(value) {\r\n"
        "    currentComplexity = value;\r\n"
        "    const dots = document.querySelectorAll('.dot');\r\n"
        "    dots.forEach((dot, index) => {\r\n"
        "        if (index < value) {\r\n"
        "            dot.classList.add('active');\r\n"
        "        } else {\r\n"
        "            dot.classList.remove('active');\r\n"
        "        }\r\n"
        "    });\r\n"
        "    \r\n"
        "    if (patchConnection) {\r\n"
        "        patchConnection.sendEventOrValue('arp_complexity', value);\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "function smartRandomize() {\r\n"
        "    const modeSelect = document.getElementById('randomize-mode');\r\n"
        "    const mode = modeSelect ? parseInt(modeSelect.value) : 0;\r\n"
        "    \r\n"
        "    const keySelect = document.querySelector('select[data-param=\"arp_key\"]');\r\n"
        "    const scaleSelect = document.querySelector('select[data-param=\"arp_scale\"]');\r\n"
        "    \r\n"
        "    if (mode === 0) {\r\n"
        "        generateHitmaker();\r\n"
        "    } else if (mode === 1) {\r\n"
        "        generateVibras();\r\n"
        "    } else if (mode === 2) {\r\n"
        "        generateEmociones();\r\n"
        "    } else if (mode === 3) {\r\n"
        "        generateAltura();\r\n"
        "    } else if (mode === 4) {\r\n"
        "        generatePerreo();\r\n"
        "    } else {\r\n"
        "        generateExperimental();\r\n"
        "    }\r\n"
        "    \r\n"
        "    if (keySelect) {\r\n"
        "        const randomKey = Math.floor(Math.random() * 12);\r\n"
        "        keySelect.value = randomKey;\r\n"
        "        keySelect.dispatchEvent(new Event('change'));\r\n"
        "    }\r\n"
        "    \r\n"
        "    updatePatternDisplay();\r\n"
        "}\r\n"
        "\r\n"
        "function generateHitmaker() {\r\n"
        "    const noteCount = Math.min(2 + Math.floor(currentComplexity / 3), 4);\r\n"
        "    const availableNotes = [1, 3, 5];\r\n"
        "    \r\n"
        "    currentMelodyPattern = new Array(16).fill(0);\r\n"
        "    currentRhythmPattern = new Array(16).fill(0);\r\n"
        "    \r\n"
        "    for (let i = 0; i < 16; i += Math.floor(16 / noteCount)) {\r\n"
        "        if (i < 16) {\r\n"
        "            currentMelodyPattern[i] = availableNotes[Math.floor(Math.random() * availableNotes.length)];\r\n"
        "            currentRhythmPattern[i] = 80 + Math.floor(Math.random() * 20);\r\n"
        "        }\r\n"
        "    }\r\n"
        "    \r\n"
        "    const scaleSelect = document.querySelector('select[data-param=\"arp_scale\"]');\r\n"
        "    if (scaleSelect) {\r\n"
        "        scaleSelect.value = Math.random() > 0.5 ? 0 : 1;\r\n"
        "        scaleSelect.dispatchEvent(new Event('change'));\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "function generateVibras() {\r\n"
        "    const noteCount = Math.min(2, 1 + Math.floor(currentComplexity / 5));\r\n"
        "    \r\n"
        "    currentMelodyPattern = new Array(16).fill(0);\r\n"
        "    currentRhythmPattern = new Array(16).fill(0);\r\n"
        "    \r\n"
        "    currentMelodyPattern[0] = 1;\r\n"
        "    currentRhythmPattern[0] = 100;\r\n"
        "    \r\n"
        "    if (noteCount > 1) {\r\n"
        "        currentMelodyPattern[8] = Math.random() > 0.5 ? 5 : 3;\r\n"
        "        currentRhythmPattern[8] = 80;\r\n"
        "    }\r\n"
        "    \r\n"
        "    const scaleSelect = document.querySelector('select[data-param=\"arp_scale\"]');\r\n"
        "    if (scaleSelect) {\r\n"
        "        scaleSelect.value = 0;\r\n"
        "        scaleSelect.dispatchEvent(new Event('change'));\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "function generateEmociones() {\r\n"
        "    const noteCount = Math.min(4 + Math.floor(currentComplexity / 2), 6);\r\n"
        "    const availableNotes = [1, 2, 3, 4, 5, 6, 7];\r\n"
        "    \r\n"
        "    currentMelodyPattern = new Array(16).fill(0);\r\n"
        "    currentRhythmPattern = new Array(16).fill(0);\r\n"
        "    \r\n"
        "    for (let i = 0; i < noteCount; i++) {\r\n"
        "        const pos = Math.floor((i / noteCount) * 16);\r\n"
        "        currentMelodyPattern[pos] = availableNotes[Math.floor(Math.random() * availableNotes.length)];\r\n"
        "        currentRhythmPattern[pos] = 70 + Math.floor(Math.random() * 30);\r\n"
        "    }\r\n"
        "    \r\n"
        "    const scaleSelect = document.querySelector('select[data-param=\"arp_scale\"]');\r\n"
        "    if (scaleSelect) {\r\n"
        "        scaleSelect.value = Math.random() > 0.5 ? 0 : 2;\r\n"
        "        scaleSelect.dispatchEvent(new Event('change'));\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "function generateAltura() {\r\n"
        "    const noteCount = Math.min(3 + Math.floor(currentComplexity / 2), 5);\r\n"
        "    const availableNotes = [1, 3, 5, 6];\r\n"
        "    \r\n"
        "    currentMelodyPattern = new Array(16).fill(0);\r\n"
        "    currentRhythmPattern = new Array(16).fill(0);\r\n"
        "    \r\n"
        "    for (let i = 0; i < noteCount; i++) {\r\n"
        "        const pos = Math.floor((i / noteCount) * 16);\r\n"
        "        currentMelodyPattern[pos] = availableNotes[Math.floor(Math.random() * availableNotes.length)];\r\n"
        "        currentRhythmPattern[pos] = 80 + Math.floor(Math.random() * 20);\r\n"
        "    }\r\n"
        "    \r\n"
        "    const scaleSelect = document.querySelector('select[data-param=\"arp_scale\"]');\r\n"
        "    if (scaleSelect) {\r\n"
        "        scaleSelect.value = 1;\r\n"
        "        scaleSelect.dispatchEvent(new Event('change'));\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "function generatePerreo() {\r\n"
        "    currentMelodyPattern = new Array(16).fill(0);\r\n"
        "    currentRhythmPattern = [...rhythmPatterns[4]];\r\n"
        "    \r\n"
        "    for (let i = 0; i < 16; i++) {\r\n"
        "        if (currentRhythmPattern[i] > 0) {\r\n"
        "            currentMelodyPattern[i] = Math.random() > 0.5 ? 1 : 5;\r\n"
        "        }\r\n"
        "    }\r\n"
        "    \r\n"
        "    const scaleSelect = document.querySelector('select[data-param=\"arp_scale\"]');\r\n"
        "    if (scaleSelect) {\r\n"
        "        scaleSelect.value = 5;\r\n"
        "        scaleSelect.dispatchEvent(new Event('change'));\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "function generateExperimental() {\r\n"
        "    currentMelodyPattern = new Array(16).fill(0);\r\n"
        "    currentRhythmPattern = new Array(16).fill(0);\r\n"
        "    \r\n"
        "    for (let i = 0; i < 16; i++) {\r\n"
        "        if (Math.random() < (currentComplexity / 10)) {\r\n"
        "            currentMelodyPattern[i] = 1 + Math.floor(Math.random() * 7);\r\n"
        "            currentRhythmPattern[i] = 60 + Math.floor(Math.random() * 40);\r\n"
        "        }\r\n"
        "    }\r\n"
        "    \r\n"
        "    const scaleSelect = document.querySelector('select[data-param=\"arp_scale\"]');\r\n"
        "    if (scaleSelect) {\r\n"
        "        scaleSelect.value = Math.floor(Math.random() * 8);\r\n"
        "        scaleSelect.dispatchEvent(new Event('change'));\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "function applyVariation(type) {\r\n"
        "    switch(type) {\r\n"
        "        case 'octave-up':\r\n"
        "            currentMelodyPattern = currentMelodyPattern.map(n => n > 0 ? n + 7 : 0);\r\n"
        "            break;\r\n"
        "        case 'octave-down':\r\n"
        "            currentMelodyPattern = currentMelodyPattern.map(n => n > 7 ? n - 7 : n);\r\n"
        "            break;\r\n"
        "        case 'invert':\r\n"
        "            const max = Math.max(...currentMelodyPattern);\r\n"
        "            currentMelodyPattern = currentMelodyPattern.map(n => n > 0 ? max - n + 1 : 0);\r\n"
        "            break;\r\n"
        "        case 'reverse':\r\n"
        "            currentMelodyPattern.reverse();\r\n"
        "            currentRhythmPattern.reverse();\r\n"
        "            break;\r\n"
        "        case 'simplify':\r\n"
        "            for (let i = 1; i < 16; i += 2) {\r\n"
        "                currentMelodyPattern[i] = 0;\r\n"
        "                currentRhythmPattern[i] = 0;\r\n"
        "            }\r\n"
        "            break;\r\n"
        "        case 'double':\r\n"
        "            const newMelody = [];\r\n"
        "            const newRhythm = [];\r\n"
        "            for (let i = 0; i < 8; i++) {\r\n"
        "                newMelody.push(currentMelodyPattern[i], currentMelodyPattern[i]);\r\n"
        "                newRhythm.push(currentRhythmPattern[i], currentRhythmPattern[i]);\r\n"
        "            }\r\n"
        "            currentMelodyPattern = newMelody;\r\n"
        "            currentRhythmPattern = newRhythm;\r\n"
        "            break;\r\n"
        "        case 'shift-left':\r\n"
        "            currentMelodyPattern.unshift(currentMelodyPattern.pop());\r\n"
        "            currentRhythmPattern.unshift(currentRhythmPattern.pop());\r\n"
        "            break;\r\n"
        "        case 'shift-right':\r\n"
        "            currentMelodyPattern.push(currentMelodyPattern.shift());\r\n"
        "            currentRhythmPattern.push(currentRhythmPattern.shift());\r\n"
        "            break;\r\n"
        "    }\r\n"
        "    \r\n"
        "    updatePatternDisplay();\r\n"
        "}\r\n"
        "\r\n"
        "window.addEventListener('load', async () => {\r\n"
        "    initializeUI();\r\n"
        "    \r\n"
        "    if (window.cmajor) {\r\n"
        "        try {\r\n"
        "            patchConnection = await window.cmajor.createPatchConnection();\r\n"
        "            \r\n"
        "            if (patchConnection) {\r\n"
        "                console.log('CINTA: Connected to patch');\r\n"
        "                \r\n"
        "                const knobs = document.querySelectorAll('.knob');\r\n"
        "                knobs.forEach(knobElement => {\r\n"
        "                    const knob = new Knob(knobElement);\r\n"
        "                    knob.sendToEngine();\r\n"
        "                });\r\n"
        "                \r\n"
        "                const toggles = document.querySelectorAll('input[type=\"checkbox\"][data-param]');\r\n"
        "                toggles.forEach(toggleElement => {\r\n"
        "                    const value = toggleElement.checked ? 1 : 0;\r\n"
        "                    patchConnection.sendEventOrValue(toggleElement.dataset.param, value);\r\n"
        "                });\r\n"
        "                \r\n"
        "                const selectors = document.querySelectorAll('select[data-param]');\r\n"
        "                selectors.forEach(selectorElement => {\r\n"
        "                    const value = parseFloat(selectorElement.value);\r\n"
        "                    patchConnection.sendEventOrValue(selectorElement.dataset.param, value);\r\n"
        "                });\r\n"
        "            }\r\n"
        "        } catch (error) {\r\n"
        "            console.error('CINTA: Failed to connect to patch:', error);\r\n"
        "        }\r\n"
        "    } else {\r\n"
        "        console.log('CINTA: Running in standalone mode (no patch connection)');\r\n"
        "    }\r\n"
        "});\r\n"
        "\r\n"
        "window.addEventListener('beforeunload', () => {\r\n"
        "    if (patchConnection) {\r\n"
        "        patchConnection.disconnect();\r\n"
        "    }\r\n"
        "});\r\n";
    static constexpr const char* ui_sizemanager_js =
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   CINTA UI SIZE MANAGER\r\n"
        "   Handles 4 size modes with keyboard shortcuts and localStorage\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        "class SizeManager {\r\n"
        "    constructor() {\r\n"
        "        this.container = document.querySelector('.synth-container');\r\n"
        "        this.toggleBtn = document.getElementById('sizeToggleBtn');\r\n"
        "        this.dropdown = document.getElementById('sizeDropdown');\r\n"
        "        this.sizeLabel = document.getElementById('currentSizeLabel');\r\n"
        "        this.indicator = document.getElementById('sizeIndicator');\r\n"
        "        this.sizeOptions = document.querySelectorAll('.size-option');\r\n"
        "        \r\n"
        "        this.currentSize = 'compact';\r\n"
        "        this.sizes = {\r\n"
        "            full: { label: 'FULL', width: 1400, height: 850 },\r\n"
        "            compact: { label: 'COMPACT', width: 900, height: 500 },\r\n"
        "            mini: { label: 'MINI', width: 500, height: 340 },\r\n"
        "            strip: { label: 'STRIP', width: 380, height: 160 }\r\n"
        "        };\r\n"
        "        \r\n"
        "        this.init();\r\n"
        "    }\r\n"
        "    \r\n"
        "    init() {\r\n"
        "        // Load saved size preference from localStorage (default to COMPACT)\r\n"
        "        const savedSize = localStorage.getItem('cinta-ui-size');\r\n"
        "        if (savedSize && this.sizes[savedSize]) {\r\n"
        "            this.setSize(savedSize, false);\r\n"
        "        } else {\r\n"
        "            // Set COMPACT as default if no saved preference\r\n"
        "            this.setSize('compact', false);\r\n"
        "        }\r\n"
        "        \r\n"
        "        // Toggle button click\r\n"
        "        this.toggleBtn.addEventListener('click', (e) => {\r\n"
        "            e.stopPropagation();\r\n"
        "            this.toggleDropdown();\r\n"
        "        });\r\n"
        "        \r\n"
        "        // Size option clicks\r\n"
        "        this.sizeOptions.forEach(option => {\r\n"
        "            option.addEventListener('click', () => {\r\n"
        "                const size = option.dataset.size;\r\n"
        "                this.setSize(size);\r\n"
        "                this.closeDropdown();\r\n"
        "            });\r\n"
        "        });\r\n"
        "        \r\n"
        "        // Close dropdown when clicking outside\r\n"
        "        document.addEventListener('click', (e) => {\r\n"
        "            if (!this.dropdown.contains(e.target) && e.target !== this.toggleBtn) {\r\n"
        "                this.closeDropdown();\r\n"
        "            }\r\n"
        "        });\r\n"
        "        \r\n"
        "        // Keyboard shortcuts: Ctrl+1/2/3/4\r\n"
        "        document.addEventListener('keydown', (e) => {\r\n"
        "            if (e.ctrlKey && !e.shiftKey && !e.altKey) {\r\n"
        "                switch(e.key) {\r\n"
        "                    case '1':\r\n"
        "                        e.preventDefault();\r\n"
        "                        this.setSize('full');\r\n"
        "                        break;\r\n"
        "                    case '2':\r\n"
        "                        e.preventDefault();\r\n"
        "                        this.setSize('compact');\r\n"
        "                        break;\r\n"
        "                    case '3':\r\n"
        "                        e.preventDefault();\r\n"
        "                        this.setSize('mini');\r\n"
        "                        break;\r\n"
        "                    case '4':\r\n"
        "                        e.preventDefault();\r\n"
        "                        this.setSize('strip');\r\n"
        "                        break;\r\n"
        "                }\r\n"
        "            }\r\n"
        "        });\r\n"
        "        \r\n"
        "        // Update active state in dropdown\r\n"
        "        this.updateActiveOption();\r\n"
        "    }\r\n"
        "    \r\n"
        "    setSize(size, showIndicator = true) {\r\n"
        "        if (!this.sizes[size] || size === this.currentSize) return;\r\n"
        "        \r\n"
        "        // Remove all size classes\r\n"
        "        Object.keys(this.sizes).forEach(s => {\r\n"
        "            this.container.classList.remove(`size-${s}`);\r\n"
        "        });\r\n"
        "        \r\n"
        "        // Add new size class\r\n"
        "        this.container.classList.add(`size-${size}`);\r\n"
        "        this.currentSize = size;\r\n"
        "        \r\n"
        "        // Update label\r\n"
        "        this.sizeLabel.textContent = this.sizes[size].label;\r\n"
        "        \r\n"
        "        // Save to localStorage\r\n"
        "        localStorage.setItem('cinta-ui-size', size);\r\n"
        "        \r\n"
        "        // Update active option in dropdown\r\n"
        "        this.updateActiveOption();\r\n"
        "        \r\n"
        "        // Show size change indicator\r\n"
        "        if (showIndicator) {\r\n"
        "            this.showSizeIndicator(size);\r\n"
        "        }\r\n"
        "        \r\n"
        "        // Dispatch custom event for other components\r\n"
        "        window.dispatchEvent(new CustomEvent('cinta-size-changed', { \r\n"
        "            detail: { size, dimensions: this.sizes[size] }\r\n"
        "        }));\r\n"
        "    }\r\n"
        "    \r\n"
        "    toggleDropdown() {\r\n"
        "        this.dropdown.classList.toggle('active');\r\n"
        "    }\r\n"
        "    \r\n"
        "    closeDropdown() {\r\n"
        "        this.dropdown.classList.remove('active');\r\n"
        "    }\r\n"
        "    \r\n"
        "    updateActiveOption() {\r\n"
        "        this.sizeOptions.forEach(option => {\r\n"
        "            if (option.dataset.size === this.currentSize) {\r\n"
        "                option.classList.add('active');\r\n"
        "            } else {\r\n"
        "                option.classList.remove('active');\r\n"
        "            }\r\n"
        "        });\r\n"
        "    }\r\n"
        "    \r\n"
        "    showSizeIndicator(size) {\r\n"
        "        const sizeInfo = this.sizes[size];\r\n"
        "        this.indicator.textContent = `${sizeInfo.label} (${sizeInfo.width}\x0c3\x097${sizeInfo.height})`;\r\n"
        "        this.indicator.classList.add('show');\r\n"
        "        \r\n"
        "        setTimeout(() => {\r\n"
        "            this.indicator.classList.remove('show');\r\n"
        "        }, 1500);\r\n"
        "    }\r\n"
        "    \r\n"
        "    // Public API\r\n"
        "    getCurrentSize() {\r\n"
        "        return this.currentSize;\r\n"
        "    }\r\n"
        "    \r\n"
        "    getSizeInfo(size) {\r\n"
        "        return this.sizes[size || this.currentSize];\r\n"
        "    }\r\n"
        "    \r\n"
        "    cycleSize() {\r\n"
        "        const sizeKeys = Object.keys(this.sizes);\r\n"
        "        const currentIndex = sizeKeys.indexOf(this.currentSize);\r\n"
        "        const nextIndex = (currentIndex + 1) % sizeKeys.length;\r\n"
        "        this.setSize(sizeKeys[nextIndex]);\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "// Initialize size manager when DOM is ready\r\n"
        "let sizeManager = null;\r\n"
        "\r\n"
        "document.addEventListener('DOMContentLoaded', () => {\r\n"
        "    sizeManager = new SizeManager();\r\n"
        "    \r\n"
        "    // Make it globally accessible for debugging\r\n"
        "    window.cintaSizeManager = sizeManager;\r\n"
        "    \r\n"
        "    console.log('CINTA Size Manager initialized');\r\n"
        "    console.log('Keyboard shortcuts: Ctrl+1 (FULL), Ctrl+2 (COMPACT), Ctrl+3 (MINI), Ctrl+4 (STRIP)');\r\n"
        "});\r\n"
        "\r\n"
        "// Export for use in other modules\r\n"
        "if (typeof module !== 'undefined' && module.exports) {\r\n"
        "    module.exports = SizeManager;\r\n"
        "}\r\n";
    static constexpr const char* ui_sizemodes_css =
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   CINTA UI SIZE MODES\r\n"
        "   4 responsive layouts with smooth transitions\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SIZE MODE TOGGLE BUTTON\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".size-toggle-container {\r\n"
        "    position: absolute;\r\n"
        "    top: 15px;\r\n"
        "    right: 15px;\r\n"
        "    z-index: 1000;\r\n"
        "}\r\n"
        "\r\n"
        ".size-toggle-btn {\r\n"
        "    background: linear-gradient(135deg, #8b7355 0%, #6b5644 100%);\r\n"
        "    border: 2px solid #5a4a3a;\r\n"
        "    border-radius: 6px;\r\n"
        "    padding: 8px 16px;\r\n"
        "    color: #f5f0e6;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 11px;\r\n"
        "    font-weight: 600;\r\n"
        "    cursor: pointer;\r\n"
        "    box-shadow: \r\n"
        "        0 2px 4px rgba(0,0,0,0.3),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.1);\r\n"
        "    transition: all 0.2s ease;\r\n"
        "    display: flex;\r\n"
        "    align-items: center;\r\n"
        "    gap: 8px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-toggle-btn:hover {\r\n"
        "    background: linear-gradient(135deg, #9b8365 0%, #7b6654 100%);\r\n"
        "    transform: translateY(-1px);\r\n"
        "    box-shadow: \r\n"
        "        0 4px 8px rgba(0,0,0,0.4),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.15);\r\n"
        "}\r\n"
        "\r\n"
        ".size-toggle-btn:active {\r\n"
        "    transform: translateY(0);\r\n"
        "    box-shadow: \r\n"
        "        0 1px 2px rgba(0,0,0,0.3),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".size-toggle-btn::before {\r\n"
        "    content: '\x0e2\x08a\x09e';\r\n"
        "    font-size: 14px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-dropdown {\r\n"
        "    position: absolute;\r\n"
        "    top: 100%;\r\n"
        "    right: 0;\r\n"
        "    margin-top: 8px;\r\n"
        "    background: linear-gradient(135deg, #3a3028 0%, #2a2018 100%);\r\n"
        "    border: 2px solid #5a4a3a;\r\n"
        "    border-radius: 6px;\r\n"
        "    padding: 8px 0;\r\n"
        "    min-width: 200px;\r\n"
        "    box-shadow: \r\n"
        "        0 8px 16px rgba(0,0,0,0.5),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.05);\r\n"
        "    opacity: 0;\r\n"
        "    visibility: hidden;\r\n"
        "    transform: translateY(-10px);\r\n"
        "    transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1);\r\n"
        "}\r\n"
        "\r\n"
        ".size-dropdown.active {\r\n"
        "    opacity: 1;\r\n"
        "    visibility: visible;\r\n"
        "    transform: translateY(0);\r\n"
        "}\r\n"
        "\r\n"
        ".size-option {\r\n"
        "    padding: 10px 16px;\r\n"
        "    color: #f5f0e6;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 11px;\r\n"
        "    cursor: pointer;\r\n"
        "    transition: all 0.2s ease;\r\n"
        "    display: flex;\r\n"
        "    justify-content: space-between;\r\n"
        "    align-items: center;\r\n"
        "}\r\n"
        "\r\n"
        ".size-option:hover {\r\n"
        "    background: rgba(139, 115, 85, 0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".size-option.active {\r\n"
        "    background: rgba(139, 115, 85, 0.5);\r\n"
        "    color: #ffd700;\r\n"
        "}\r\n"
        "\r\n"
        ".size-option .shortcut {\r\n"
        "    font-size: 9px;\r\n"
        "    opacity: 0.6;\r\n"
        "    margin-left: 12px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-option .dimensions {\r\n"
        "    font-size: 9px;\r\n"
        "    opacity: 0.5;\r\n"
        "    margin-left: 8px;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   MODE 1: FULL (1400x850) - Everything visible\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".synth-container.size-full {\r\n"
        "    width: 1400px;\r\n"
        "    height: 850px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-full .engine-section,\r\n"
        ".size-full .texture-section,\r\n"
        ".size-full .arp-section,\r\n"
        ".size-full .envelope-section,\r\n"
        ".size-full .lfo-section,\r\n"
        ".size-full .master-section,\r\n"
        ".size-full .preset-browser {\r\n"
        "    display: block;\r\n"
        "    opacity: 1;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   MODE 2: COMPACT (900x500) - Engines + Macros + Arp pattern\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".synth-container.size-compact {\r\n"
        "    width: 900px;\r\n"
        "    height: 500px;\r\n"
        "    padding: 20px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .header {\r\n"
        "    margin-bottom: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .vintage-badge {\r\n"
        "    transform: scale(0.8);\r\n"
        "    transform-origin: left center;\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .vu-meter {\r\n"
        "    transform: scale(0.7);\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .tape-deck {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        "/* Show only essential sections */\r\n"
        ".size-compact .engine-section {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(3, 1fr);\r\n"
        "    gap: 15px;\r\n"
        "    margin-bottom: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .engine-panel {\r\n"
        "    padding: 12px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .engine-panel h3 {\r\n"
        "    font-size: 11px;\r\n"
        "    margin-bottom: 8px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .knob-group {\r\n"
        "    display: none; /* Hide detailed knobs */\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .engine-toggle {\r\n"
        "    display: block;\r\n"
        "    margin: 8px auto;\r\n"
        "}\r\n"
        "\r\n"
        "/* Show macro controls */\r\n"
        ".size-compact .master-section {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(5, 1fr);\r\n"
        "    gap: 10px;\r\n"
        "    margin-bottom: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .master-section .knob {\r\n"
        "    transform: scale(0.8);\r\n"
        "}\r\n"
        "\r\n"
        "/* Show arp pattern display */\r\n"
        ".size-compact .arp-section {\r\n"
        "    display: block;\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .arp-pattern-display {\r\n"
        "    display: grid;\r\n"
        "}\r\n"
        "\r\n"
        ".size-compact .arp-controls {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(4, 1fr);\r\n"
        "    gap: 8px;\r\n"
        "}\r\n"
        "\r\n"
        "/* Hide detailed sections */\r\n"
        ".size-compact .texture-section,\r\n"
        ".size-compact .envelope-section,\r\n"
        ".size-compact .lfo-section,\r\n"
        ".size-compact .preset-browser {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   MODE 3: MINI (500x300) - Just macros, engine toggles, master\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".synth-container.size-mini {\r\n"
        "    width: 500px;\r\n"
        "    height: 340px;\r\n"
        "    padding: 15px;\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .header {\r\n"
        "    margin-bottom: 12px;\r\n"
        "    flex-shrink: 0;\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .vintage-badge {\r\n"
        "    transform: scale(0.65);\r\n"
        "    transform-origin: left center;\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .vu-meter,\r\n"
        ".size-mini .tape-deck,\r\n"
        ".size-mini .preset-browser {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        "/* Minimal engine section - just toggles */\r\n"
        ".size-mini .engine-section {\r\n"
        "    display: flex;\r\n"
        "    gap: 12px;\r\n"
        "    margin-bottom: 15px;\r\n"
        "    justify-content: center;\r\n"
        "    flex-shrink: 0;\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .engine-panel {\r\n"
        "    padding: 10px 15px;\r\n"
        "    min-width: auto;\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    align-items: center;\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .engine-panel h3 {\r\n"
        "    font-size: 11px;\r\n"
        "    margin-bottom: 8px;\r\n"
        "    white-space: nowrap;\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .knob-group,\r\n"
        ".size-mini .arp-pattern-display,\r\n"
        ".size-mini .arp-controls {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .engine-toggle {\r\n"
        "    display: block;\r\n"
        "    margin: 0 auto;\r\n"
        "    transform: scale(1);\r\n"
        "}\r\n"
        "\r\n"
        "/* Compact master section */\r\n"
        ".size-mini .master-section {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(5, 1fr);\r\n"
        "    gap: 10px;\r\n"
        "    padding: 0;\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .master-section .knob-container {\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    align-items: center;\r\n"
        "    gap: 4px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .master-section .knob {\r\n"
        "    transform: scale(0.75);\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .master-section label {\r\n"
        "    font-size: 9px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-mini .master-section h3 {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        "/* Hide everything else */\r\n"
        ".size-mini .texture-section,\r\n"
        ".size-mini .envelope-section,\r\n"
        ".size-mini .lfo-section,\r\n"
        ".size-mini .arp-section,\r\n"
        ".size-mini .preset-browser {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   MODE 4: STRIP (300x150) - Vibe, Master, Arp toggle, VU meter\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".synth-container.size-strip {\r\n"
        "    width: 380px;\r\n"
        "    height: 160px;\r\n"
        "    padding: 12px;\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    justify-content: space-between;\r\n"
        "}\r\n"
        "\r\n"
        ".size-strip .header {\r\n"
        "    display: flex;\r\n"
        "    justify-content: space-between;\r\n"
        "    align-items: center;\r\n"
        "    margin-bottom: 0;\r\n"
        "    height: auto;\r\n"
        "    flex-shrink: 0;\r\n"
        "}\r\n"
        "\r\n"
        ".size-strip .logo {\r\n"
        "    display: flex;\r\n"
        "    align-items: center;\r\n"
        "}\r\n"
        "\r\n"
        ".size-strip .vintage-badge {\r\n"
        "    transform: scale(0.55);\r\n"
        "    transform-origin: left center;\r\n"
        "}\r\n"
        "\r\n"
        ".size-strip .tape-deck,\r\n"
        ".size-strip .preset-browser {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        "/* Show VU meter in strip mode */\r\n"
        ".size-strip .vu-meter {\r\n"
        "    display: block;\r\n"
        "    transform: scale(0.55);\r\n"
        "    transform-origin: right center;\r\n"
        "    margin-right: -10px;\r\n"
        "}\r\n"
        "\r\n"
        "/* Ultra minimal - just essential controls */\r\n"
        ".size-strip .master-section {\r\n"
        "    display: flex;\r\n"
        "    gap: 15px;\r\n"
        "    align-items: center;\r\n"
        "    justify-content: center;\r\n"
        "    padding: 0;\r\n"
        "    flex-shrink: 0;\r\n"
        "}\r\n"
        "\r\n"
        ".size-strip .master-section h3 {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        ".size-strip .master-section .knob-container {\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    align-items: center;\r\n"
        "    gap: 4px;\r\n"
        "}\r\n"
        "\r\n"
        ".size-strip .master-section .knob {\r\n"
        "    transform: scale(0.7);\r\n"
        "}\r\n"
        "\r\n"
        ".size-strip .master-section label {\r\n"
        "    font-size: 9px;\r\n"
        "    white-space: nowrap;\r\n"
        "}\r\n"
        "\r\n"
        "/* Show only Vibe and Master Volume */\r\n"
        ".size-strip .master-section > *:not(:nth-child(1)):not(:nth-child(6)) {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        "/* Arp toggle */\r\n"
        ".size-strip .arp-section {\r\n"
        "    display: flex;\r\n"
        "    align-items: center;\r\n"
        "    justify-content: center;\r\n"
        "    margin-left: 15px;\r\n"
        "    flex-shrink: 0;\r\n"
        "}\r\n"
        "\r\n"
        ".size-strip .arp-section > *:not(.toggle-button) {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        ".size-strip .arp-section .toggle-button {\r\n"
        "    transform: scale(0.9);\r\n"
        "}\r\n"
        "\r\n"
        "/* Hide everything else */\r\n"
        ".size-strip .engine-section,\r\n"
        ".size-strip .texture-section,\r\n"
        ".size-strip .envelope-section,\r\n"
        ".size-strip .lfo-section,\r\n"
        ".size-strip .preset-browser {\r\n"
        "    display: none;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SMOOTH TRANSITIONS\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".synth-container * {\r\n"
        "    transition: \r\n"
        "        opacity 0.3s ease,\r\n"
        "        transform 0.3s cubic-bezier(0.4, 0, 0.2, 1),\r\n"
        "        width 0.4s cubic-bezier(0.4, 0, 0.2, 1),\r\n"
        "        height 0.4s cubic-bezier(0.4, 0, 0.2, 1);\r\n"
        "}\r\n"
        "\r\n"
        "/* Fade in/out animations */\r\n"
        "@keyframes fadeIn {\r\n"
        "    from {\r\n"
        "        opacity: 0;\r\n"
        "        transform: translateY(-10px);\r\n"
        "    }\r\n"
        "    to {\r\n"
        "        opacity: 1;\r\n"
        "        transform: translateY(0);\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "@keyframes fadeOut {\r\n"
        "    from {\r\n"
        "        opacity: 1;\r\n"
        "        transform: translateY(0);\r\n"
        "    }\r\n"
        "    to {\r\n"
        "        opacity: 0;\r\n"
        "        transform: translateY(-10px);\r\n"
        "    }\r\n"
        "}\r\n"
        "\r\n"
        "/* Size change indicator */\r\n"
        ".size-indicator {\r\n"
        "    position: fixed;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "    transform: translate(-50%, -50%);\r\n"
        "    background: rgba(0, 0, 0, 0.9);\r\n"
        "    color: #ffd700;\r\n"
        "    padding: 20px 40px;\r\n"
        "    border-radius: 8px;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 18px;\r\n"
        "    font-weight: 600;\r\n"
        "    z-index: 10000;\r\n"
        "    pointer-events: none;\r\n"
        "    opacity: 0;\r\n"
        "    transition: opacity 0.3s ease;\r\n"
        "}\r\n"
        "\r\n"
        ".size-indicator.show {\r\n"
        "    opacity: 1;\r\n"
        "}\r\n"
        "\r\n"
        "/* Responsive adjustments for very small screens */\r\n"
        "@media (max-width: 320px) {\r\n"
        "    .synth-container.size-strip {\r\n"
        "        width: 100%;\r\n"
        "        height: 120px;\r\n"
        "    }\r\n"
        "}\r\n";
    static constexpr const char* ui_stylesvintage_css =
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   CINTA - 1975 HAVANA STUDIO VINTAGE UI\r\n"
        "   Authentic vintage hardware aesthetics\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        "* {\r\n"
        "    margin: 0;\r\n"
        "    padding: 0;\r\n"
        "    box-sizing: border-box;\r\n"
        "}\r\n"
        "\r\n"
        "body {\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    background: #0a0a0a;\r\n"
        "    color: #f5f0e6;\r\n"
        "    overflow: auto;\r\n"
        "    user-select: none;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 1: WOOD GRAIN BACKGROUND\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".synth-container {\r\n"
        "    width: 1400px;\r\n"
        "    height: 850px;\r\n"
        "    margin: 20px auto;\r\n"
        "    padding: 30px;\r\n"
        "    position: relative;\r\n"
        "    transition: all 0.4s cubic-bezier(0.4, 0, 0.2, 1);\r\n"
        "    overflow: hidden;\r\n"
        "    \r\n"
        "    /* Realistic wood grain texture */\r\n"
        "    background: \r\n"
        "        /* Wood grain lines */\r\n"
        "        repeating-linear-gradient(\r\n"
        "            90deg,\r\n"
        "            transparent 0px,\r\n"
        "            transparent 2px,\r\n"
        "            rgba(0,0,0,0.03) 2px,\r\n"
        "            rgba(0,0,0,0.03) 4px\r\n"
        "        ),\r\n"
        "        /* Vertical grain variation */\r\n"
        "        repeating-linear-gradient(\r\n"
        "            180deg,\r\n"
        "            transparent 0px,\r\n"
        "            rgba(0,0,0,0.02) 100px,\r\n"
        "            transparent 200px\r\n"
        "        ),\r\n"
        "        /* Wood knots (subtle circles) */\r\n"
        "        radial-gradient(ellipse 40px 80px at 20% 30%, rgba(0,0,0,0.08) 0%, transparent 50%),\r\n"
        "        radial-gradient(ellipse 30px 60px at 70% 60%, rgba(0,0,0,0.06) 0%, transparent 50%),\r\n"
        "        radial-gradient(ellipse 50px 90px at 85% 20%, rgba(0,0,0,0.07) 0%, transparent 50%),\r\n"
        "        /* Base wood gradient */\r\n"
        "        linear-gradient(\r\n"
        "            180deg,\r\n"
        "            #3d2b1f 0%,\r\n"
        "            #2a1f1a 30%,\r\n"
        "            #1f1612 70%,\r\n"
        "            #2a1f1a 100%\r\n"
        "        );\r\n"
        "    \r\n"
        "    /* Subtle vignette */\r\n"
        "    box-shadow:\r\n"
        "        inset 0 0 100px rgba(0,0,0,0.3),\r\n"
        "        inset 0 0 200px rgba(0,0,0,0.1),\r\n"
        "        0 10px 50px rgba(0,0,0,0.8);\r\n"
        "    \r\n"
        "    border-radius: 12px;\r\n"
        "}\r\n"
        "\r\n"
        "/* Noise texture overlay */\r\n"
        ".synth-container::before {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: 0;\r\n"
        "    left: 0;\r\n"
        "    right: 0;\r\n"
        "    bottom: 0;\r\n"
        "    background-image: url(\"data:image/svg+xml,%3Csvg viewBox='0 0 200 200' xmlns='http://www.w3.org/2000/svg'%3E%3Cfilter id='noise'%3E%3CfeTurbulence type='fractalNoise' baseFrequency='0.9' numOctaves='4' stitchTiles='stitch'/%3E%3C/filter%3E%3Crect width='100%25' height='100%25' filter='url(%23noise)'/%3E%3C/svg%3E\");\r\n"
        "    opacity: 0.03;\r\n"
        "    pointer-events: none;\r\n"
        "    border-radius: inherit;\r\n"
        "}\r\n"
        "\r\n"
        "/* Warm ambient lighting from top */\r\n"
        ".synth-container::after {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: -50px;\r\n"
        "    left: 50%;\r\n"
        "    transform: translateX(-50%);\r\n"
        "    width: 80%;\r\n"
        "    height: 100px;\r\n"
        "    background: radial-gradient(\r\n"
        "        ellipse,\r\n"
        "        rgba(255, 180, 100, 0.08) 0%,\r\n"
        "        transparent 70%\r\n"
        "    );\r\n"
        "    pointer-events: none;\r\n"
        "    z-index: 0;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 2: HEADER WITH VINTAGE BADGE\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".header {\r\n"
        "    display: flex;\r\n"
        "    justify-content: space-between;\r\n"
        "    align-items: center;\r\n"
        "    margin-bottom: 25px;\r\n"
        "    padding: 20px 25px;\r\n"
        "    background: rgba(0, 0, 0, 0.4);\r\n"
        "    border-radius: 8px;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.15);\r\n"
        "    position: relative;\r\n"
        "    z-index: 1;\r\n"
        "    box-shadow: \r\n"
        "        0 4px 12px rgba(0,0,0,0.5),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.05);\r\n"
        "}\r\n"
        "\r\n"
        ".logo {\r\n"
        "    position: relative;\r\n"
        "}\r\n"
        "\r\n"
        ".logo-badge {\r\n"
        "    background: linear-gradient(\r\n"
        "        180deg,\r\n"
        "        #c9b896 0%,\r\n"
        "        #a69572 20%,\r\n"
        "        #8b7d5e 50%,\r\n"
        "        #a69572 80%,\r\n"
        "        #c9b896 100%\r\n"
        "    );\r\n"
        "    padding: 15px 40px;\r\n"
        "    border-radius: 6px;\r\n"
        "    position: relative;\r\n"
        "    box-shadow:\r\n"
        "        0 3px 6px rgba(0,0,0,0.4),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.3),\r\n"
        "        inset 0 -1px 0 rgba(0,0,0,0.2);\r\n"
        "}\r\n"
        "\r\n"
        ".logo-text {\r\n"
        "    font-family: 'Playfair Display', serif;\r\n"
        "    font-size: 32px;\r\n"
        "    font-weight: 700;\r\n"
        "    color: #1a1209;\r\n"
        "    text-shadow: \r\n"
        "        0 1px 0 rgba(255,255,255,0.3),\r\n"
        "        0 -1px 0 rgba(0,0,0,0.2);\r\n"
        "    letter-spacing: 8px;\r\n"
        "    display: block;\r\n"
        "}\r\n"
        "\r\n"
        ".logo-subtitle {\r\n"
        "    font-size: 9px;\r\n"
        "    text-transform: uppercase;\r\n"
        "    letter-spacing: 3px;\r\n"
        "    color: #3d2b1f;\r\n"
        "    display: block;\r\n"
        "    margin-top: 4px;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "}\r\n"
        "\r\n"
        "/* Mounting screws */\r\n"
        ".logo-screws {\r\n"
        "    position: absolute;\r\n"
        "    top: 0;\r\n"
        "    left: 0;\r\n"
        "    right: 0;\r\n"
        "    bottom: 0;\r\n"
        "    pointer-events: none;\r\n"
        "}\r\n"
        "\r\n"
        ".screw {\r\n"
        "    width: 12px;\r\n"
        "    height: 12px;\r\n"
        "    background: \r\n"
        "        radial-gradient(circle at 30% 30%, #6a6a6a 0%, #3a3a3a 50%, #2a2a2a 100%);\r\n"
        "    border-radius: 50%;\r\n"
        "    position: absolute;\r\n"
        "    box-shadow:\r\n"
        "        inset 0 1px 2px rgba(255,255,255,0.2),\r\n"
        "        0 1px 2px rgba(0,0,0,0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".screw::before {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "    transform: translate(-50%, -50%) rotate(35deg);\r\n"
        "    width: 7px;\r\n"
        "    height: 1.5px;\r\n"
        "    background: #1a1a1a;\r\n"
        "    box-shadow: 0 0 1px rgba(0,0,0,0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".screw::after {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "    transform: translate(-50%, -50%) rotate(-35deg);\r\n"
        "    width: 7px;\r\n"
        "    height: 1.5px;\r\n"
        "    background: #1a1a1a;\r\n"
        "}\r\n"
        "\r\n"
        ".logo-screws .screw:nth-child(1) { top: 10px; left: 10px; }\r\n"
        ".logo-screws .screw:nth-child(2) { top: 10px; right: 10px; }\r\n"
        ".logo-screws .screw:nth-child(3) { bottom: 10px; left: 10px; }\r\n"
        ".logo-screws .screw:nth-child(4) { bottom: 10px; right: 10px; }\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 3: REALISTIC 3D KNOBS (Chicken-Head Style)\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".knob {\r\n"
        "    width: 60px;\r\n"
        "    height: 60px;\r\n"
        "    position: relative;\r\n"
        "    cursor: grab;\r\n"
        "    margin: 0 auto;\r\n"
        "}\r\n"
        "\r\n"
        ".knob:active {\r\n"
        "    cursor: grabbing;\r\n"
        "}\r\n"
        "\r\n"
        "/* Knob base (metal ring) */\r\n"
        ".knob::before {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "    transform: translate(-50%, -50%);\r\n"
        "    width: 56px;\r\n"
        "    height: 56px;\r\n"
        "    background: \r\n"
        "        radial-gradient(circle at 30% 30%, #4a4a4a 0%, #2a2a2a 50%, #1a1a1a 100%);\r\n"
        "    border-radius: 50%;\r\n"
        "    box-shadow: \r\n"
        "        0 4px 8px rgba(0,0,0,0.5),\r\n"
        "        inset 0 2px 4px rgba(255,255,255,0.1),\r\n"
        "        inset 0 -2px 4px rgba(0,0,0,0.3);\r\n"
        "}\r\n"
        "\r\n"
        "/* Knob cap (the part you grab) */\r\n"
        ".knob::after {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "    transform: translate(-50%, -50%);\r\n"
        "    width: 44px;\r\n"
        "    height: 44px;\r\n"
        "    background: \r\n"
        "        radial-gradient(circle at 35% 35%, #3d3d3d 0%, #1a1a1a 70%);\r\n"
        "    border-radius: 50%;\r\n"
        "    box-shadow:\r\n"
        "        0 2px 4px rgba(0,0,0,0.4),\r\n"
        "        inset 0 1px 2px rgba(255,255,255,0.1);\r\n"
        "}\r\n"
        "\r\n"
        "/* Knob pointer (chicken head style) */\r\n"
        ".knob-pointer {\r\n"
        "    position: absolute;\r\n"
        "    bottom: 50%;\r\n"
        "    left: 50%;\r\n"
        "    width: 8px;\r\n"
        "    height: 20px;\r\n"
        "    background: linear-gradient(180deg, #f5f0e6 0%, #d0cbc0 50%, #a8a39a 100%);\r\n"
        "    border-radius: 2px;\r\n"
        "    transform: translateX(-50%) rotate(0deg);\r\n"
        "    transform-origin: 50% 100%;\r\n"
        "    box-shadow: \r\n"
        "        0 1px 2px rgba(0,0,0,0.3),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.3);\r\n"
        "    transition: transform 0.1s ease-out;\r\n"
        "}\r\n"
        "\r\n"
        "/* Small knobs */\r\n"
        ".knob.small {\r\n"
        "    width: 45px;\r\n"
        "    height: 45px;\r\n"
        "}\r\n"
        "\r\n"
        ".knob.small::before {\r\n"
        "    width: 42px;\r\n"
        "    height: 42px;\r\n"
        "}\r\n"
        "\r\n"
        ".knob.small::after {\r\n"
        "    width: 32px;\r\n"
        "    height: 32px;\r\n"
        "}\r\n"
        "\r\n"
        ".knob.small .knob-pointer {\r\n"
        "    top: 6px;\r\n"
        "    width: 6px;\r\n"
        "    height: 15px;\r\n"
        "    transform-origin: 50% calc(100% + 16px);\r\n"
        "}\r\n"
        "\r\n"
        "/* Knob markings (dots around the knob) */\r\n"
        ".knob-markings {\r\n"
        "    position: absolute;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "    transform: translate(-50%, -50%);\r\n"
        "    width: 70px;\r\n"
        "    height: 70px;\r\n"
        "    pointer-events: none;\r\n"
        "}\r\n"
        "\r\n"
        ".knob-marking {\r\n"
        "    position: absolute;\r\n"
        "    width: 3px;\r\n"
        "    height: 3px;\r\n"
        "    background: rgba(245, 240, 230, 0.4);\r\n"
        "    border-radius: 50%;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 4: VU METERS WITH SWINGING NEEDLES\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".vu-meter {\r\n"
        "    width: 140px;\r\n"
        "    height: 80px;\r\n"
        "    background: linear-gradient(180deg, #1a1a1a 0%, #0a0a0a 100%);\r\n"
        "    border-radius: 8px;\r\n"
        "    position: relative;\r\n"
        "    overflow: hidden;\r\n"
        "    box-shadow: \r\n"
        "        inset 0 2px 10px rgba(0,0,0,0.8),\r\n"
        "        0 2px 4px rgba(0,0,0,0.5);\r\n"
        "    margin: 0 auto;\r\n"
        "}\r\n"
        "\r\n"
        ".vu-face {\r\n"
        "    position: absolute;\r\n"
        "    bottom: 10px;\r\n"
        "    left: 50%;\r\n"
        "    transform: translateX(-50%);\r\n"
        "    width: 110px;\r\n"
        "    height: 55px;\r\n"
        "    background: #f5f0e6;\r\n"
        "    border-radius: 55px 55px 0 0;\r\n"
        "    overflow: hidden;\r\n"
        "}\r\n"
        "\r\n"
        ".vu-scale {\r\n"
        "    position: absolute;\r\n"
        "    bottom: 0;\r\n"
        "    left: 0;\r\n"
        "    right: 0;\r\n"
        "    height: 100%;\r\n"
        "}\r\n"
        "\r\n"
        ".vu-mark {\r\n"
        "    position: absolute;\r\n"
        "    bottom: 5px;\r\n"
        "    left: 50%;\r\n"
        "    font-size: 7px;\r\n"
        "    font-weight: 600;\r\n"
        "    color: #1a1a1a;\r\n"
        "    transform-origin: bottom center;\r\n"
        "    transform: translateX(-50%) rotate(var(--angle));\r\n"
        "}\r\n"
        "\r\n"
        ".vu-mark.red {\r\n"
        "    color: #cc0000;\r\n"
        "}\r\n"
        "\r\n"
        ".vu-needle {\r\n"
        "    position: absolute;\r\n"
        "    bottom: 0;\r\n"
        "    left: 50%;\r\n"
        "    width: 2px;\r\n"
        "    height: 50px;\r\n"
        "    background: linear-gradient(180deg, #ff3b3b 0%, #1a1a1a 20%);\r\n"
        "    transform-origin: bottom center;\r\n"
        "    transform: translateX(-50%) rotate(-30deg);\r\n"
        "    transition: transform 0.15s ease-out;\r\n"
        "    z-index: 2;\r\n"
        "    filter: drop-shadow(0 0 2px rgba(255, 59, 59, 0.5));\r\n"
        "}\r\n"
        "\r\n"
        ".vu-pivot {\r\n"
        "    position: absolute;\r\n"
        "    bottom: -3px;\r\n"
        "    left: 50%;\r\n"
        "    transform: translateX(-50%);\r\n"
        "    width: 10px;\r\n"
        "    height: 10px;\r\n"
        "    background: radial-gradient(circle, #3a3a3a 0%, #1a1a1a 100%);\r\n"
        "    border-radius: 50%;\r\n"
        "    z-index: 3;\r\n"
        "    box-shadow: 0 1px 2px rgba(0,0,0,0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".vu-glass {\r\n"
        "    position: absolute;\r\n"
        "    top: 0;\r\n"
        "    left: 0;\r\n"
        "    right: 0;\r\n"
        "    bottom: 0;\r\n"
        "    background: linear-gradient(\r\n"
        "        180deg,\r\n"
        "        rgba(255,255,255,0.1) 0%,\r\n"
        "        transparent 50%\r\n"
        "    );\r\n"
        "    pointer-events: none;\r\n"
        "}\r\n"
        "\r\n"
        ".vu-label {\r\n"
        "    position: absolute;\r\n"
        "    top: 8px;\r\n"
        "    left: 50%;\r\n"
        "    transform: translateX(-50%);\r\n"
        "    font-size: 10px;\r\n"
        "    font-weight: 600;\r\n"
        "    color: #f5f0e6;\r\n"
        "    letter-spacing: 2px;\r\n"
        "}\r\n"
        "\r\n"
        "/* Needle animation states */\r\n"
        ".vu-meter[data-level=\"low\"] .vu-needle { \r\n"
        "    transform: translateX(-50%) rotate(-35deg); \r\n"
        "}\r\n"
        ".vu-meter[data-level=\"mid\"] .vu-needle { \r\n"
        "    transform: translateX(-50%) rotate(-10deg); \r\n"
        "}\r\n"
        ".vu-meter[data-level=\"high\"] .vu-needle { \r\n"
        "    transform: translateX(-50%) rotate(15deg); \r\n"
        "}\r\n"
        ".vu-meter[data-level=\"clip\"] .vu-needle { \r\n"
        "    transform: translateX(-50%) rotate(35deg); \r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 5: REEL-TO-REEL TAPE DECK\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".tape-deck {\r\n"
        "    display: flex;\r\n"
        "    align-items: center;\r\n"
        "    justify-content: center;\r\n"
        "    gap: 40px;\r\n"
        "    padding: 20px;\r\n"
        "    background: rgba(0,0,0,0.3);\r\n"
        "    border-radius: 8px;\r\n"
        "    margin: 15px 0;\r\n"
        "    box-shadow: inset 0 2px 8px rgba(0,0,0,0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".reel {\r\n"
        "    width: 80px;\r\n"
        "    height: 80px;\r\n"
        "    border-radius: 50%;\r\n"
        "    background: \r\n"
        "        radial-gradient(circle, #2a2a2a 30%, #1a1a1a 100%);\r\n"
        "    position: relative;\r\n"
        "    box-shadow:\r\n"
        "        0 4px 8px rgba(0,0,0,0.5),\r\n"
        "        inset 0 2px 4px rgba(255,255,255,0.05);\r\n"
        "}\r\n"
        "\r\n"
        ".reel-hub {\r\n"
        "    position: absolute;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "    transform: translate(-50%, -50%);\r\n"
        "    width: 25px;\r\n"
        "    height: 25px;\r\n"
        "    background: radial-gradient(circle, #4a4a4a 0%, #2a2a2a 100%);\r\n"
        "    border-radius: 50%;\r\n"
        "    box-shadow: inset 0 2px 4px rgba(0,0,0,0.5);\r\n"
        "    z-index: 3;\r\n"
        "}\r\n"
        "\r\n"
        ".reel-spokes {\r\n"
        "    position: absolute;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "    transform: translate(-50%, -50%);\r\n"
        "    width: 60px;\r\n"
        "    height: 60px;\r\n"
        "    background: \r\n"
        "        repeating-conic-gradient(\r\n"
        "            from 0deg,\r\n"
        "            transparent 0deg 30deg,\r\n"
        "            rgba(255,255,255,0.05) 30deg 60deg\r\n"
        "        );\r\n"
        "    border-radius: 50%;\r\n"
        "}\r\n"
        "\r\n"
        "/* Tape on the reel */\r\n"
        ".tape-level {\r\n"
        "    position: absolute;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "    transform: translate(-50%, -50%);\r\n"
        "    width: 70px;\r\n"
        "    height: 70px;\r\n"
        "    border: 8px solid #3d2b1f;\r\n"
        "    border-radius: 50%;\r\n"
        "    opacity: 0.8;\r\n"
        "    box-shadow: inset 0 0 5px rgba(0,0,0,0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".left-reel .tape-level {\r\n"
        "    width: 75px;\r\n"
        "    height: 75px;\r\n"
        "    border-width: 12px;\r\n"
        "}\r\n"
        "\r\n"
        ".right-reel .tape-level {\r\n"
        "    width: 50px;\r\n"
        "    height: 50px;\r\n"
        "    border-width: 5px;\r\n"
        "}\r\n"
        "\r\n"
        ".tape-path {\r\n"
        "    display: flex;\r\n"
        "    align-items: center;\r\n"
        "    gap: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".tape-guide {\r\n"
        "    width: 8px;\r\n"
        "    height: 30px;\r\n"
        "    background: linear-gradient(90deg, #3a3a3a 0%, #2a2a2a 50%, #3a3a3a 100%);\r\n"
        "    border-radius: 4px;\r\n"
        "    box-shadow: \r\n"
        "        0 2px 4px rgba(0,0,0,0.5),\r\n"
        "        inset 0 1px 2px rgba(255,255,255,0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".tape-head {\r\n"
        "    width: 20px;\r\n"
        "    height: 40px;\r\n"
        "    background: linear-gradient(180deg, #5a5a5a 0%, #3a3a3a 50%, #2a2a2a 100%);\r\n"
        "    border-radius: 4px;\r\n"
        "    box-shadow: \r\n"
        "        0 3px 6px rgba(0,0,0,0.5),\r\n"
        "        inset 0 1px 2px rgba(255,255,255,0.2);\r\n"
        "    position: relative;\r\n"
        "}\r\n"
        "\r\n"
        ".tape-head::after {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: 50%;\r\n"
        "    left: 50%;\r\n"
        "    transform: translate(-50%, -50%);\r\n"
        "    width: 12px;\r\n"
        "    height: 2px;\r\n"
        "    background: #ff9500;\r\n"
        "    box-shadow: 0 0 4px #ff9500;\r\n"
        "}\r\n"
        "\r\n"
        "/* Tape reel animation */\r\n"
        "@keyframes spin {\r\n"
        "    from { transform: translate(-50%, -50%) rotate(0deg); }\r\n"
        "    to { transform: translate(-50%, -50%) rotate(360deg); }\r\n"
        "}\r\n"
        "\r\n"
        ".tape-deck.playing .reel-spokes {\r\n"
        "    animation: spin 2s linear infinite;\r\n"
        "}\r\n"
        "\r\n"
        ".tape-deck.playing .left-reel .reel-spokes {\r\n"
        "    animation-duration: 2.5s;\r\n"
        "}\r\n"
        "\r\n"
        ".tape-deck.playing .right-reel .reel-spokes {\r\n"
        "    animation-duration: 1.8s;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 6: NIXIE TUBE DISPLAYS\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".nixie-display {\r\n"
        "    display: flex;\r\n"
        "    gap: 4px;\r\n"
        "    padding: 10px 14px;\r\n"
        "    background: #0a0a0a;\r\n"
        "    border-radius: 6px;\r\n"
        "    box-shadow: inset 0 2px 8px rgba(0,0,0,0.8);\r\n"
        "    margin: 8px 0;\r\n"
        "}\r\n"
        "\r\n"
        ".nixie-digit {\r\n"
        "    width: 22px;\r\n"
        "    height: 32px;\r\n"
        "    background: \r\n"
        "        radial-gradient(ellipse at center, rgba(255,147,0,0.3) 0%, transparent 70%),\r\n"
        "        #0a0a0a;\r\n"
        "    border-radius: 4px;\r\n"
        "    display: flex;\r\n"
        "    align-items: center;\r\n"
        "    justify-content: center;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 22px;\r\n"
        "    font-weight: 600;\r\n"
        "    color: #ff9300;\r\n"
        "    text-shadow: \r\n"
        "        0 0 5px #ff9300,\r\n"
        "        0 0 10px #ff9300,\r\n"
        "        0 0 20px #ff6600;\r\n"
        "    position: relative;\r\n"
        "}\r\n"
        "\r\n"
        "/* Glass tube effect */\r\n"
        ".nixie-digit::before {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: 0;\r\n"
        "    left: 0;\r\n"
        "    right: 0;\r\n"
        "    bottom: 0;\r\n"
        "    background: linear-gradient(\r\n"
        "        180deg,\r\n"
        "        rgba(255,255,255,0.1) 0%,\r\n"
        "        transparent 30%,\r\n"
        "        transparent 70%,\r\n"
        "        rgba(0,0,0,0.2) 100%\r\n"
        "    );\r\n"
        "    border-radius: 4px;\r\n"
        "    pointer-events: none;\r\n"
        "}\r\n"
        "\r\n"
        "/* Wire mesh behind digits */\r\n"
        ".nixie-digit::after {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: 2px;\r\n"
        "    left: 2px;\r\n"
        "    right: 2px;\r\n"
        "    bottom: 2px;\r\n"
        "    background: \r\n"
        "        repeating-linear-gradient(\r\n"
        "            0deg,\r\n"
        "            transparent 0px,\r\n"
        "            transparent 2px,\r\n"
        "            rgba(255,255,255,0.03) 2px,\r\n"
        "            rgba(255,255,255,0.03) 3px\r\n"
        "        );\r\n"
        "    pointer-events: none;\r\n"
        "    z-index: -1;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 7: LED INDICATORS\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".led-indicator {\r\n"
        "    width: 10px;\r\n"
        "    height: 10px;\r\n"
        "    border-radius: 50%;\r\n"
        "    background: #2a2a2a;\r\n"
        "    box-shadow: inset 0 1px 2px rgba(0,0,0,0.5);\r\n"
        "    transition: all 0.2s;\r\n"
        "}\r\n"
        "\r\n"
        ".led-indicator.on {\r\n"
        "    background: radial-gradient(circle at 30% 30%, #ffcc00 0%, #ff9500 50%, #cc6600 100%);\r\n"
        "    box-shadow:\r\n"
        "        0 0 5px #ff9500,\r\n"
        "        0 0 10px rgba(255, 149, 0, 0.5),\r\n"
        "        0 0 20px rgba(255, 149, 0, 0.3),\r\n"
        "        inset 0 -2px 4px rgba(0,0,0,0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".led-indicator.red.on {\r\n"
        "    background: radial-gradient(circle at 30% 30%, #ff6666 0%, #ff0000 50%, #cc0000 100%);\r\n"
        "    box-shadow:\r\n"
        "        0 0 5px #ff0000,\r\n"
        "        0 0 10px rgba(255, 0, 0, 0.5),\r\n"
        "        0 0 20px rgba(255, 0, 0, 0.3),\r\n"
        "        inset 0 -2px 4px rgba(0,0,0,0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".led-indicator.green.on {\r\n"
        "    background: radial-gradient(circle at 30% 30%, #66ff66 0%, #00ff00 50%, #00cc00 100%);\r\n"
        "    box-shadow:\r\n"
        "        0 0 5px #00ff00,\r\n"
        "        0 0 10px rgba(0, 255, 0, 0.5),\r\n"
        "        0 0 20px rgba(0, 255, 0, 0.3),\r\n"
        "        inset 0 -2px 4px rgba(0,0,0,0.3);\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 8: ENGINE PANELS WITH WEAR & PATINA\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".engine-panel {\r\n"
        "    background: rgba(0, 0, 0, 0.3);\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.15);\r\n"
        "    border-radius: 8px;\r\n"
        "    padding: 20px;\r\n"
        "    position: relative;\r\n"
        "    box-shadow: \r\n"
        "        0 4px 12px rgba(0,0,0,0.4),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.05);\r\n"
        "}\r\n"
        "\r\n"
        "/* Scratched metal effect */\r\n"
        ".engine-panel::before {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: 0;\r\n"
        "    left: 0;\r\n"
        "    right: 0;\r\n"
        "    bottom: 0;\r\n"
        "    background: \r\n"
        "        /* Scratches */\r\n"
        "        linear-gradient(73deg, transparent 30%, rgba(0,0,0,0.02) 30.5%, transparent 31%),\r\n"
        "        linear-gradient(107deg, transparent 45%, rgba(255,255,255,0.02) 45.5%, transparent 46%),\r\n"
        "        linear-gradient(167deg, transparent 60%, rgba(0,0,0,0.015) 60.5%, transparent 61%),\r\n"
        "        linear-gradient(23deg, transparent 70%, rgba(255,255,255,0.015) 70.5%, transparent 71%);\r\n"
        "    pointer-events: none;\r\n"
        "    border-radius: inherit;\r\n"
        "}\r\n"
        "\r\n"
        "/* Dust in corners */\r\n"
        ".engine-panel::after {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    top: 0;\r\n"
        "    left: 0;\r\n"
        "    width: 40px;\r\n"
        "    height: 40px;\r\n"
        "    background: radial-gradient(\r\n"
        "        circle at top left,\r\n"
        "        rgba(139, 119, 101, 0.1) 0%,\r\n"
        "        transparent 70%\r\n"
        "    );\r\n"
        "    pointer-events: none;\r\n"
        "    border-radius: inherit;\r\n"
        "}\r\n"
        "\r\n"
        ".engine-header {\r\n"
        "    display: flex;\r\n"
        "    justify-content: space-between;\r\n"
        "    align-items: center;\r\n"
        "    margin-bottom: 15px;\r\n"
        "    padding-bottom: 10px;\r\n"
        "    border-bottom: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".engine-header h2 {\r\n"
        "    font-size: 14px;\r\n"
        "    letter-spacing: 3px;\r\n"
        "    color: #d4cfc5;\r\n"
        "    text-shadow: 0 1px 0 rgba(0,0,0,0.3);\r\n"
        "    opacity: 0.85;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 9: TOGGLE BUTTONS WITH GLOW\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".toggle-btn {\r\n"
        "    padding: 8px 16px;\r\n"
        "    background: linear-gradient(180deg, #3a3a3a 0%, #2a2a2a 50%, #1a1a1a 100%);\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.2);\r\n"
        "    border-radius: 4px;\r\n"
        "    color: #d4cfc5;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 11px;\r\n"
        "    font-weight: 600;\r\n"
        "    cursor: pointer;\r\n"
        "    transition: all 0.2s;\r\n"
        "    box-shadow:\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.1),\r\n"
        "        inset 0 -1px 0 rgba(0,0,0,0.2),\r\n"
        "        0 2px 4px rgba(0,0,0,0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".toggle-btn:hover {\r\n"
        "    background: linear-gradient(180deg, #4a4a4a 0%, #3a3a3a 50%, #2a2a2a 100%);\r\n"
        "}\r\n"
        "\r\n"
        ".toggle-btn:active {\r\n"
        "    box-shadow: inset 0 2px 4px rgba(0,0,0,0.3);\r\n"
        "    transform: translateY(1px);\r\n"
        "}\r\n"
        "\r\n"
        ".toggle-btn.active {\r\n"
        "    background: linear-gradient(180deg, #ffb347 0%, #ff9500 50%, #cc7000 100%);\r\n"
        "    color: #1a1209;\r\n"
        "    box-shadow:\r\n"
        "        0 0 10px rgba(255, 149, 0, 0.5),\r\n"
        "        0 0 20px rgba(255, 149, 0, 0.3),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.3),\r\n"
        "        inset 0 -1px 0 rgba(0,0,0,0.2);\r\n"
        "    text-shadow: 0 1px 2px rgba(0,0,0,0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".toggle-btn.small {\r\n"
        "    padding: 6px 12px;\r\n"
        "    font-size: 9px;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 10: LABELS & TEXT (Aged/Yellowed)\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".knob-group label,\r\n"
        ".selector-group label {\r\n"
        "    display: block;\r\n"
        "    text-align: center;\r\n"
        "    margin-top: 8px;\r\n"
        "    font-size: 10px;\r\n"
        "    text-transform: uppercase;\r\n"
        "    letter-spacing: 1.5px;\r\n"
        "    color: #d4cfc5;\r\n"
        "    text-shadow: 0 1px 0 rgba(0,0,0,0.3);\r\n"
        "    opacity: 0.85;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 11: PRESET BROWSER\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".preset-browser {\r\n"
        "    display: flex;\r\n"
        "    gap: 10px;\r\n"
        "    align-items: center;\r\n"
        "}\r\n"
        "\r\n"
        "#preset-select {\r\n"
        "    padding: 8px 16px;\r\n"
        "    background: rgba(0,0,0,0.5);\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.2);\r\n"
        "    border-radius: 4px;\r\n"
        "    color: #f5f0e6;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 12px;\r\n"
        "    cursor: pointer;\r\n"
        "    min-width: 200px;\r\n"
        "}\r\n"
        "\r\n"
        ".preset-btn {\r\n"
        "    padding: 8px 14px;\r\n"
        "    background: linear-gradient(180deg, #3a3a3a 0%, #2a2a2a 50%, #1a1a1a 100%);\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.2);\r\n"
        "    border-radius: 4px;\r\n"
        "    color: #d4cfc5;\r\n"
        "    font-size: 14px;\r\n"
        "    cursor: pointer;\r\n"
        "    transition: all 0.2s;\r\n"
        "    box-shadow: 0 2px 4px rgba(0,0,0,0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".preset-btn:hover {\r\n"
        "    background: linear-gradient(180deg, #4a4a4a 0%, #3a3a3a 50%, #2a2a2a 100%);\r\n"
        "}\r\n"
        "\r\n"
        ".preset-btn:active {\r\n"
        "    transform: translateY(1px);\r\n"
        "}\r\n"
        "\r\n"
        ".preset-btn.save {\r\n"
        "    background: linear-gradient(180deg, #ff9500 0%, #cc7000 50%, #994d00 100%);\r\n"
        "    color: #1a1209;\r\n"
        "    font-weight: 600;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 12: LAYOUT SECTIONS\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".macro-knobs {\r\n"
        "    display: flex;\r\n"
        "    gap: 20px;\r\n"
        "}\r\n"
        "\r\n"
        ".macro-knob {\r\n"
        "    text-align: center;\r\n"
        "}\r\n"
        "\r\n"
        ".engines-row {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(3, 1fr);\r\n"
        "    gap: 20px;\r\n"
        "    margin-bottom: 20px;\r\n"
        "}\r\n"
        "\r\n"
        ".engine-controls {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(auto-fit, minmax(80px, 1fr));\r\n"
        "    gap: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".knob-group {\r\n"
        "    text-align: center;\r\n"
        "}\r\n"
        "\r\n"
        ".texture-rack {\r\n"
        "    background: rgba(0, 0, 0, 0.3);\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.15);\r\n"
        "    border-radius: 8px;\r\n"
        "    padding: 20px;\r\n"
        "    margin-bottom: 20px;\r\n"
        "    position: relative;\r\n"
        "}\r\n"
        "\r\n"
        ".texture-rack h2 {\r\n"
        "    font-size: 14px;\r\n"
        "    letter-spacing: 3px;\r\n"
        "    color: #d4cfc5;\r\n"
        "    margin-bottom: 15px;\r\n"
        "    text-shadow: 0 1px 0 rgba(0,0,0,0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".texture-slots {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(5, 1fr);\r\n"
        "    gap: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".texture-slot {\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    align-items: center;\r\n"
        "    gap: 8px;\r\n"
        "    padding: 12px;\r\n"
        "    background: rgba(0,0,0,0.2);\r\n"
        "    border-radius: 6px;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".texture-name {\r\n"
        "    font-size: 9px;\r\n"
        "    letter-spacing: 1px;\r\n"
        "    color: #d4cfc5;\r\n"
        "    opacity: 0.85;\r\n"
        "}\r\n"
        "\r\n"
        ".arp-machine {\r\n"
        "    background: rgba(0, 0, 0, 0.3);\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.15);\r\n"
        "    border-radius: 8px;\r\n"
        "    padding: 20px;\r\n"
        "    margin-bottom: 20px;\r\n"
        "    position: relative;\r\n"
        "}\r\n"
        "\r\n"
        ".arp-header {\r\n"
        "    display: flex;\r\n"
        "    justify-content: space-between;\r\n"
        "    align-items: center;\r\n"
        "    margin-bottom: 15px;\r\n"
        "    padding-bottom: 10px;\r\n"
        "    border-bottom: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".arp-header h2 {\r\n"
        "    font-size: 16px;\r\n"
        "    letter-spacing: 3px;\r\n"
        "    color: #d4cfc5;\r\n"
        "}\r\n"
        "\r\n"
        ".bottom-controls {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: 2fr 1fr;\r\n"
        "    gap: 20px;\r\n"
        "}\r\n"
        "\r\n"
        ".envelope-section,\r\n"
        ".master-section {\r\n"
        "    background: rgba(0, 0, 0, 0.3);\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.15);\r\n"
        "    border-radius: 8px;\r\n"
        "    padding: 20px;\r\n"
        "}\r\n"
        "\r\n"
        ".envelope-section h3,\r\n"
        ".master-section h3 {\r\n"
        "    font-size: 12px;\r\n"
        "    letter-spacing: 2px;\r\n"
        "    color: #d4cfc5;\r\n"
        "    margin-bottom: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".env-knobs {\r\n"
        "    display: flex;\r\n"
        "    gap: 20px;\r\n"
        "    justify-content: center;\r\n"
        "}\r\n"
        "\r\n"
        "/* \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\r\n"
        "   SECTION 13: ARP MACHINE SPECIFIC STYLES\r\n"
        "   \x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090\x0e2\x095\x090 */\r\n"
        "\r\n"
        ".arp-selectors {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(4, 1fr);\r\n"
        "    gap: 15px;\r\n"
        "    margin-bottom: 20px;\r\n"
        "}\r\n"
        "\r\n"
        ".selector-group select {\r\n"
        "    width: 100%;\r\n"
        "    padding: 8px;\r\n"
        "    background: rgba(0,0,0,0.5);\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.2);\r\n"
        "    border-radius: 4px;\r\n"
        "    color: #f5f0e6;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 11px;\r\n"
        "}\r\n"
        "\r\n"
        ".key-buttons {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(12, 1fr);\r\n"
        "    gap: 4px;\r\n"
        "    margin-top: 8px;\r\n"
        "}\r\n"
        "\r\n"
        ".key-btn {\r\n"
        "    padding: 6px 4px;\r\n"
        "    background: linear-gradient(180deg, #3a3a3a 0%, #2a2a2a 100%);\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.2);\r\n"
        "    border-radius: 3px;\r\n"
        "    color: #d4cfc5;\r\n"
        "    font-size: 9px;\r\n"
        "    cursor: pointer;\r\n"
        "    transition: all 0.2s;\r\n"
        "}\r\n"
        "\r\n"
        ".key-btn:hover {\r\n"
        "    background: linear-gradient(180deg, #4a4a4a 0%, #3a3a3a 100%);\r\n"
        "}\r\n"
        "\r\n"
        ".key-btn.active {\r\n"
        "    background: linear-gradient(180deg, #ff9500 0%, #cc7000 100%);\r\n"
        "    color: #1a1209;\r\n"
        "    box-shadow: 0 0 8px rgba(255, 149, 0, 0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".arp-pattern-display {\r\n"
        "    display: flex;\r\n"
        "    gap: 6px;\r\n"
        "    padding: 20px 15px;\r\n"
        "    background: #1a1209;\r\n"
        "    border-radius: 6px;\r\n"
        "    justify-content: center;\r\n"
        "    margin-bottom: 20px;\r\n"
        "    box-shadow: inset 0 2px 8px rgba(0,0,0,0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".pattern-step {\r\n"
        "    width: 24px;\r\n"
        "    height: 60px;\r\n"
        "    background: #3d2b1f;\r\n"
        "    border-radius: 4px;\r\n"
        "    transition: all 0.2s;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "    position: relative;\r\n"
        "}\r\n"
        "\r\n"
        ".pattern-step.active {\r\n"
        "    background: linear-gradient(180deg, #ff9500 0%, #cc7700 100%);\r\n"
        "    box-shadow: \r\n"
        "        0 0 10px rgba(255, 149, 0, 0.5),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.3);\r\n"
        "    border-color: #ff9500;\r\n"
        "}\r\n"
        "\r\n"
        ".pattern-step:nth-child(4n+1) {\r\n"
        "    border-left: 2px solid rgba(245, 240, 230, 0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".arp-controls {\r\n"
        "    display: flex;\r\n"
        "    gap: 20px;\r\n"
        "    align-items: center;\r\n"
        "    justify-content: center;\r\n"
        "    margin-bottom: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".randomize-btn {\r\n"
        "    padding: 12px 30px;\r\n"
        "    background: linear-gradient(180deg, #ff9500 0%, #cc7000 100%);\r\n"
        "    border: none;\r\n"
        "    border-radius: 6px;\r\n"
        "    color: #1a1209;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 14px;\r\n"
        "    font-weight: 700;\r\n"
        "    cursor: pointer;\r\n"
        "    transition: all 0.2s;\r\n"
        "    box-shadow: \r\n"
        "        0 4px 8px rgba(255, 149, 0, 0.3),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".randomize-btn:hover {\r\n"
        "    background: linear-gradient(180deg, #ffaa33 0%, #dd8000 100%);\r\n"
        "    box-shadow: \r\n"
        "        0 6px 12px rgba(255, 149, 0, 0.5),\r\n"
        "        inset 0 1px 0 rgba(255,255,255,0.3);\r\n"
        "    transform: translateY(-2px);\r\n"
        "}\r\n"
        "\r\n"
        ".randomize-btn:active {\r\n"
        "    transform: translateY(0);\r\n"
        "}\r\n"
        "\r\n"
        ".arp-variations {\r\n"
        "    display: flex;\r\n"
        "    gap: 8px;\r\n"
        "    justify-content: center;\r\n"
        "    padding-top: 15px;\r\n"
        "    border-top: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".var-btn {\r\n"
        "    padding: 8px 14px;\r\n"
        "    background: linear-gradient(180deg, #3a3a3a 0%, #2a2a2a 100%);\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.2);\r\n"
        "    border-radius: 4px;\r\n"
        "    color: #d4cfc5;\r\n"
        "    font-size: 10px;\r\n"
        "    font-weight: 600;\r\n"
        "    cursor: pointer;\r\n"
        "    transition: all 0.2s;\r\n"
        "}\r\n"
        "\r\n"
        ".var-btn:hover {\r\n"
        "    background: linear-gradient(180deg, #ff9500 0%, #cc7000 100%);\r\n"
        "    color: #1a1209;\r\n"
        "    transform: translateY(-2px);\r\n"
        "}\r\n"
        "\r\n"
        ".var-btn:active {\r\n"
        "    transform: translateY(0);\r\n"
        "}\r\n";
    static constexpr const char* ui_styles_css =
        "* {\r\n"
        "    margin: 0;\r\n"
        "    padding: 0;\r\n"
        "    box-sizing: border-box;\r\n"
        "}\r\n"
        "\r\n"
        "body {\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    background: #2a1f1a;\r\n"
        "    color: #f5f0e6;\r\n"
        "    overflow: hidden;\r\n"
        "    user-select: none;\r\n"
        "}\r\n"
        "\r\n"
        ".synth-container {\r\n"
        "    width: 1400px;\r\n"
        "    height: 850px;\r\n"
        "    background: linear-gradient(135deg, #2a1f1a 0%, #1a1209 100%);\r\n"
        "    position: relative;\r\n"
        "    padding: 20px;\r\n"
        "    background-image: \r\n"
        "        repeating-linear-gradient(0deg, transparent, transparent 2px, rgba(0,0,0,.03) 2px, rgba(0,0,0,.03) 4px),\r\n"
        "        repeating-linear-gradient(90deg, transparent, transparent 2px, rgba(0,0,0,.03) 2px, rgba(0,0,0,.03) 4px);\r\n"
        "}\r\n"
        "\r\n"
        ".header {\r\n"
        "    display: flex;\r\n"
        "    justify-content: space-between;\r\n"
        "    align-items: center;\r\n"
        "    margin-bottom: 20px;\r\n"
        "    padding: 15px 20px;\r\n"
        "    background: rgba(245, 240, 230, 0.05);\r\n"
        "    border-radius: 8px;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".header-left {\r\n"
        "    flex: 1;\r\n"
        "}\r\n"
        "\r\n"
        ".logo {\r\n"
        "    font-family: 'Playfair Display', serif;\r\n"
        "    font-size: 48px;\r\n"
        "    font-weight: 700;\r\n"
        "    color: #ff9500;\r\n"
        "    text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.5);\r\n"
        "    letter-spacing: 4px;\r\n"
        "    margin: 0;\r\n"
        "}\r\n"
        "\r\n"
        ".tagline {\r\n"
        "    font-size: 11px;\r\n"
        "    text-transform: uppercase;\r\n"
        "    letter-spacing: 2px;\r\n"
        "    color: #f5f0e6;\r\n"
        "    opacity: 0.7;\r\n"
        "    margin-top: 5px;\r\n"
        "}\r\n"
        "\r\n"
        ".header-center {\r\n"
        "    display: flex;\r\n"
        "    gap: 10px;\r\n"
        "    align-items: center;\r\n"
        "}\r\n"
        "\r\n"
        ".preset-selector {\r\n"
        "    background: #3d2b1f;\r\n"
        "    color: #f5f0e6;\r\n"
        "    border: 2px solid #ff9500;\r\n"
        "    padding: 8px 15px;\r\n"
        "    border-radius: 4px;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 13px;\r\n"
        "    cursor: pointer;\r\n"
        "}\r\n"
        "\r\n"
        ".preset-btn {\r\n"
        "    background: #3d2b1f;\r\n"
        "    color: #f5f0e6;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.3);\r\n"
        "    padding: 8px 15px;\r\n"
        "    border-radius: 4px;\r\n"
        "    cursor: pointer;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    transition: all 0.2s;\r\n"
        "}\r\n"
        "\r\n"
        ".preset-btn:hover {\r\n"
        "    background: #ff9500;\r\n"
        "    border-color: #ff9500;\r\n"
        "}\r\n"
        "\r\n"
        ".save-btn {\r\n"
        "    background: #ff9500;\r\n"
        "    border-color: #ff9500;\r\n"
        "    font-weight: 600;\r\n"
        "}\r\n"
        "\r\n"
        ".quick-controls {\r\n"
        "    display: flex;\r\n"
        "    gap: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".quick-knob {\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    align-items: center;\r\n"
        "    gap: 5px;\r\n"
        "}\r\n"
        "\r\n"
        ".quick-knob label {\r\n"
        "    font-size: 9px;\r\n"
        "    text-transform: uppercase;\r\n"
        "    letter-spacing: 1px;\r\n"
        "    color: #ff9500;\r\n"
        "}\r\n"
        "\r\n"
        ".engines-section {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(3, 1fr);\r\n"
        "    gap: 15px;\r\n"
        "    margin-bottom: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".engine-panel {\r\n"
        "    background: #f5f0e6;\r\n"
        "    border-radius: 8px;\r\n"
        "    padding: 15px;\r\n"
        "    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".engine-header {\r\n"
        "    display: flex;\r\n"
        "    justify-content: space-between;\r\n"
        "    align-items: center;\r\n"
        "    margin-bottom: 15px;\r\n"
        "    padding-bottom: 10px;\r\n"
        "    border-bottom: 2px solid #3d2b1f;\r\n"
        "}\r\n"
        "\r\n"
        ".engine-header h2 {\r\n"
        "    font-family: 'Playfair Display', serif;\r\n"
        "    font-size: 18px;\r\n"
        "    color: #1a1209;\r\n"
        "    text-transform: uppercase;\r\n"
        "    letter-spacing: 2px;\r\n"
        "}\r\n"
        "\r\n"
        ".engine-controls {\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    gap: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".control-group {\r\n"
        "    display: flex;\r\n"
        "    gap: 15px;\r\n"
        "    justify-content: space-around;\r\n"
        "}\r\n"
        "\r\n"
        ".knob-control {\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    align-items: center;\r\n"
        "    gap: 5px;\r\n"
        "}\r\n"
        "\r\n"
        ".knob-control label {\r\n"
        "    font-size: 10px;\r\n"
        "    text-transform: uppercase;\r\n"
        "    color: #3d2b1f;\r\n"
        "    font-weight: 600;\r\n"
        "    letter-spacing: 1px;\r\n"
        "}\r\n"
        "\r\n"
        ".value-display {\r\n"
        "    font-size: 9px;\r\n"
        "    color: #ff9500;\r\n"
        "    margin-top: 2px;\r\n"
        "}\r\n"
        "\r\n"
        ".knob {\r\n"
        "    width: 50px;\r\n"
        "    height: 50px;\r\n"
        "    border-radius: 50%;\r\n"
        "    background: linear-gradient(135deg, #3d2b1f 0%, #1a1209 100%);\r\n"
        "    border: 3px solid #3d2b1f;\r\n"
        "    position: relative;\r\n"
        "    cursor: pointer;\r\n"
        "    box-shadow: \r\n"
        "        0 2px 4px rgba(0, 0, 0, 0.3),\r\n"
        "        inset 0 -2px 4px rgba(0, 0, 0, 0.2);\r\n"
        "}\r\n"
        "\r\n"
        ".knob::before {\r\n"
        "    content: '';\r\n"
        "    position: absolute;\r\n"
        "    width: 4px;\r\n"
        "    height: 20px;\r\n"
        "    background: #f5f0e6;\r\n"
        "    top: 5px;\r\n"
        "    left: 50%;\r\n"
        "    transform: translateX(-50%);\r\n"
        "    border-radius: 2px;\r\n"
        "    box-shadow: 0 0 4px rgba(255, 149, 0, 0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".knob.small {\r\n"
        "    width: 40px;\r\n"
        "    height: 40px;\r\n"
        "}\r\n"
        "\r\n"
        ".knob.small::before {\r\n"
        "    height: 15px;\r\n"
        "    top: 4px;\r\n"
        "}\r\n"
        "\r\n"
        ".knob.large {\r\n"
        "    width: 70px;\r\n"
        "    height: 70px;\r\n"
        "}\r\n"
        "\r\n"
        ".knob.large::before {\r\n"
        "    height: 28px;\r\n"
        "    width: 5px;\r\n"
        "    top: 8px;\r\n"
        "}\r\n"
        "\r\n"
        ".toggle-switch {\r\n"
        "    position: relative;\r\n"
        "    display: inline-block;\r\n"
        "    width: 50px;\r\n"
        "    height: 24px;\r\n"
        "}\r\n"
        "\r\n"
        ".toggle-switch input {\r\n"
        "    opacity: 0;\r\n"
        "    width: 0;\r\n"
        "    height: 0;\r\n"
        "}\r\n"
        "\r\n"
        ".slider {\r\n"
        "    position: absolute;\r\n"
        "    cursor: pointer;\r\n"
        "    top: 0;\r\n"
        "    left: 0;\r\n"
        "    right: 0;\r\n"
        "    bottom: 0;\r\n"
        "    background-color: #3d2b1f;\r\n"
        "    transition: 0.3s;\r\n"
        "    border-radius: 24px;\r\n"
        "    border: 2px solid rgba(61, 43, 31, 0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".slider:before {\r\n"
        "    position: absolute;\r\n"
        "    content: \"\";\r\n"
        "    height: 16px;\r\n"
        "    width: 16px;\r\n"
        "    left: 2px;\r\n"
        "    bottom: 2px;\r\n"
        "    background-color: #f5f0e6;\r\n"
        "    transition: 0.3s;\r\n"
        "    border-radius: 50%;\r\n"
        "}\r\n"
        "\r\n"
        "input:checked + .slider {\r\n"
        "    background-color: #ff9500;\r\n"
        "    border-color: #ff9500;\r\n"
        "}\r\n"
        "\r\n"
        "input:checked + .slider:before {\r\n"
        "    transform: translateX(26px);\r\n"
        "}\r\n"
        "\r\n"
        ".toggle-switch.small {\r\n"
        "    width: 40px;\r\n"
        "    height: 20px;\r\n"
        "}\r\n"
        "\r\n"
        ".toggle-switch.small .slider:before {\r\n"
        "    height: 14px;\r\n"
        "    width: 14px;\r\n"
        "    left: 1px;\r\n"
        "    bottom: 1px;\r\n"
        "}\r\n"
        "\r\n"
        ".toggle-switch.small input:checked + .slider:before {\r\n"
        "    transform: translateX(20px);\r\n"
        "}\r\n"
        "\r\n"
        ".texture-rack {\r\n"
        "    background: rgba(245, 240, 230, 0.05);\r\n"
        "    border-radius: 8px;\r\n"
        "    padding: 15px;\r\n"
        "    margin-bottom: 15px;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".section-title {\r\n"
        "    font-family: 'Playfair Display', serif;\r\n"
        "    font-size: 16px;\r\n"
        "    color: #ff9500;\r\n"
        "    text-transform: uppercase;\r\n"
        "    letter-spacing: 3px;\r\n"
        "    margin-bottom: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".texture-units {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(6, 1fr);\r\n"
        "    gap: 10px;\r\n"
        "}\r\n"
        "\r\n"
        ".texture-unit {\r\n"
        "    background: #f5f0e6;\r\n"
        "    border-radius: 6px;\r\n"
        "    padding: 10px;\r\n"
        "    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.2);\r\n"
        "}\r\n"
        "\r\n"
        ".texture-header {\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    align-items: center;\r\n"
        "    gap: 8px;\r\n"
        "    margin-bottom: 10px;\r\n"
        "}\r\n"
        "\r\n"
        ".texture-header h3 {\r\n"
        "    font-size: 11px;\r\n"
        "    color: #1a1209;\r\n"
        "    text-transform: uppercase;\r\n"
        "    letter-spacing: 1px;\r\n"
        "    font-weight: 600;\r\n"
        "}\r\n"
        "\r\n"
        ".texture-controls {\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    align-items: center;\r\n"
        "    gap: 5px;\r\n"
        "}\r\n"
        "\r\n"
        ".texture-controls label {\r\n"
        "    font-size: 9px;\r\n"
        "    color: #3d2b1f;\r\n"
        "    text-transform: uppercase;\r\n"
        "}\r\n"
        "\r\n"
        ".arp-section {\r\n"
        "    background: rgba(245, 240, 230, 0.05);\r\n"
        "    border-radius: 8px;\r\n"
        "    padding: 15px;\r\n"
        "    margin-bottom: 15px;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".arp-header {\r\n"
        "    display: flex;\r\n"
        "    justify-content: space-between;\r\n"
        "    align-items: center;\r\n"
        "    margin-bottom: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".arp-controls {\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    gap: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".arp-top-row {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: repeat(4, 1fr);\r\n"
        "    gap: 15px;\r\n"
        "    margin-bottom: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".selector-group {\r\n"
        "    display: flex;\r\n"
        "    gap: 8px;\r\n"
        "    align-items: center;\r\n"
        "}\r\n"
        "\r\n"
        ".selector-group label {\r\n"
        "    font-size: 11px;\r\n"
        "    text-transform: uppercase;\r\n"
        "    color: #f5f0e6;\r\n"
        "}\r\n"
        "\r\n"
        ".selector-group select {\r\n"
        "    background: #3d2b1f;\r\n"
        "    color: #f5f0e6;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.3);\r\n"
        "    padding: 6px 12px;\r\n"
        "    border-radius: 4px;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 12px;\r\n"
        "    cursor: pointer;\r\n"
        "}\r\n"
        "\r\n"
        ".randomize-btn-big {\r\n"
        "    background: #ff9500;\r\n"
        "    color: #1a1209;\r\n"
        "    border: none;\r\n"
        "    padding: 12px 30px;\r\n"
        "    border-radius: 6px;\r\n"
        "    cursor: pointer;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-weight: 700;\r\n"
        "    font-size: 14px;\r\n"
        "    transition: all 0.2s;\r\n"
        "    box-shadow: 0 4px 8px rgba(255, 149, 0, 0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".randomize-btn-big:hover {\r\n"
        "    background: #ffaa33;\r\n"
        "    transform: scale(1.05);\r\n"
        "    box-shadow: 0 6px 12px rgba(255, 149, 0, 0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".randomize-btn-big:active {\r\n"
        "    transform: scale(0.98);\r\n"
        "}\r\n"
        "\r\n"
        ".arp-pattern-display {\r\n"
        "    display: flex;\r\n"
        "    gap: 6px;\r\n"
        "    padding: 20px 15px;\r\n"
        "    background: #1a1209;\r\n"
        "    border-radius: 6px;\r\n"
        "    justify-content: center;\r\n"
        "    margin-bottom: 15px;\r\n"
        "    position: relative;\r\n"
        "}\r\n"
        "\r\n"
        ".pattern-step {\r\n"
        "    width: 24px;\r\n"
        "    height: 60px;\r\n"
        "    background: #3d2b1f;\r\n"
        "    border-radius: 4px;\r\n"
        "    transition: all 0.2s;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "    position: relative;\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    align-items: center;\r\n"
        "    justify-content: flex-end;\r\n"
        "    padding-bottom: 4px;\r\n"
        "}\r\n"
        "\r\n"
        ".pattern-step.active {\r\n"
        "    background: linear-gradient(180deg, #ff9500 0%, #cc7700 100%);\r\n"
        "    box-shadow: 0 0 10px rgba(255, 149, 0, 0.5);\r\n"
        "    border-color: #ff9500;\r\n"
        "}\r\n"
        "\r\n"
        ".pattern-step:nth-child(4n+1) {\r\n"
        "    border-left: 2px solid rgba(245, 240, 230, 0.3);\r\n"
        "}\r\n"
        "\r\n"
        ".pattern-step .note-label {\r\n"
        "    font-size: 8px;\r\n"
        "    color: #f5f0e6;\r\n"
        "    font-weight: 600;\r\n"
        "    text-shadow: 0 1px 2px rgba(0, 0, 0, 0.5);\r\n"
        "}\r\n"
        "\r\n"
        ".pattern-step.active .note-label {\r\n"
        "    color: #1a1209;\r\n"
        "    text-shadow: none;\r\n"
        "}\r\n"
        "\r\n"
        ".arp-randomize-section {\r\n"
        "    display: flex;\r\n"
        "    gap: 20px;\r\n"
        "    align-items: center;\r\n"
        "    justify-content: center;\r\n"
        "    margin-bottom: 15px;\r\n"
        "    padding: 15px;\r\n"
        "    background: rgba(255, 149, 0, 0.05);\r\n"
        "    border-radius: 6px;\r\n"
        "    border: 1px solid rgba(255, 149, 0, 0.2);\r\n"
        "}\r\n"
        "\r\n"
        ".complexity-control {\r\n"
        "    display: flex;\r\n"
        "    flex-direction: column;\r\n"
        "    gap: 8px;\r\n"
        "    align-items: center;\r\n"
        "}\r\n"
        "\r\n"
        ".complexity-control label {\r\n"
        "    font-size: 10px;\r\n"
        "    text-transform: uppercase;\r\n"
        "    color: #f5f0e6;\r\n"
        "    letter-spacing: 1px;\r\n"
        "}\r\n"
        "\r\n"
        ".complexity-dots {\r\n"
        "    display: flex;\r\n"
        "    gap: 6px;\r\n"
        "}\r\n"
        "\r\n"
        ".dot {\r\n"
        "    width: 12px;\r\n"
        "    height: 12px;\r\n"
        "    border-radius: 50%;\r\n"
        "    background: #3d2b1f;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.2);\r\n"
        "    cursor: pointer;\r\n"
        "    transition: all 0.2s;\r\n"
        "}\r\n"
        "\r\n"
        ".dot.active {\r\n"
        "    background: #ff9500;\r\n"
        "    box-shadow: 0 0 6px rgba(255, 149, 0, 0.6);\r\n"
        "}\r\n"
        "\r\n"
        ".dot:hover {\r\n"
        "    transform: scale(1.2);\r\n"
        "}\r\n"
        "\r\n"
        ".arp-knobs-row {\r\n"
        "    display: flex;\r\n"
        "    gap: 20px;\r\n"
        "    justify-content: center;\r\n"
        "    align-items: flex-end;\r\n"
        "    margin-bottom: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".arp-variations {\r\n"
        "    display: flex;\r\n"
        "    gap: 8px;\r\n"
        "    align-items: center;\r\n"
        "    justify-content: center;\r\n"
        "    padding-top: 15px;\r\n"
        "    border-top: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".arp-variations label {\r\n"
        "    font-size: 10px;\r\n"
        "    text-transform: uppercase;\r\n"
        "    color: #f5f0e6;\r\n"
        "    letter-spacing: 1px;\r\n"
        "    margin-right: 10px;\r\n"
        "}\r\n"
        "\r\n"
        ".variation-btn {\r\n"
        "    background: #3d2b1f;\r\n"
        "    color: #f5f0e6;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.3);\r\n"
        "    padding: 6px 12px;\r\n"
        "    border-radius: 4px;\r\n"
        "    cursor: pointer;\r\n"
        "    font-family: 'IBM Plex Mono', monospace;\r\n"
        "    font-size: 10px;\r\n"
        "    font-weight: 600;\r\n"
        "    transition: all 0.2s;\r\n"
        "}\r\n"
        "\r\n"
        ".variation-btn:hover {\r\n"
        "    background: #ff9500;\r\n"
        "    border-color: #ff9500;\r\n"
        "    color: #1a1209;\r\n"
        "    transform: translateY(-2px);\r\n"
        "}\r\n"
        "\r\n"
        ".variation-btn:active {\r\n"
        "    transform: translateY(0);\r\n"
        "}\r\n"
        "\r\n"
        ".bottom-section {\r\n"
        "    display: grid;\r\n"
        "    grid-template-columns: 2fr 1fr 1fr;\r\n"
        "    gap: 15px;\r\n"
        "}\r\n"
        "\r\n"
        ".envelope-section,\r\n"
        ".lfo-section,\r\n"
        ".master-section {\r\n"
        "    background: rgba(245, 240, 230, 0.05);\r\n"
        "    border-radius: 8px;\r\n"
        "    padding: 15px;\r\n"
        "    border: 1px solid rgba(245, 240, 230, 0.1);\r\n"
        "}\r\n"
        "\r\n"
        ".envelope-section h3,\r\n"
        ".lfo-section h3,\r\n"
        ".master-section h3 {\r\n"
        "    font-size: 12px;\r\n"
        "    text-transform: uppercase;\r\n"
        "    letter-spacing: 2px;\r\n"
        "    color: #ff9500;\r\n"
        "    margin-bottom: 12px;\r\n"
        "}\r\n"
        "\r\n"
        ".env-controls,\r\n"
        ".lfo-controls,\r\n"
        ".master-controls {\r\n"
        "    display: flex;\r\n"
        "    gap: 15px;\r\n"
        "    justify-content: center;\r\n"
        "}\r\n"
        "\r\n"
        "@keyframes pulse {\r\n"
        "    0%, 100% { opacity: 1; }\r\n"
        "    50% { opacity: 0.6; }\r\n"
        "}\r\n"
        "\r\n"
        ".knob:active {\r\n"
        "    transform: scale(0.98);\r\n"
        "}\r\n"
        "\r\n"
        "select:focus,\r\n"
        "button:focus {\r\n"
        "    outline: 2px solid #ff9500;\r\n"
        "    outline-offset: 2px;\r\n"
        "}\r\n";


    static constexpr std::array files =
    {
        File { "cmaj_api/cmaj-patch-connection.js", std::string_view (cmaj_api_cmajpatchconnection_js, 13131) },
        File { "CINTA.cmajorpatch", std::string_view (CINTA_cmajorpatch, 396) },
        File { "cmaj_api/assets/cmajor-logo.svg", std::string_view (cmaj_api_assets_cmajorlogo_svg, 2913) },
        File { "cmaj_api/cmaj-audio-worklet-helper.js", std::string_view (cmaj_api_cmajaudioworklethelper_js, 28203) },
        File { "cmaj_api/cmaj-event-listener-list.js", std::string_view (cmaj_api_cmajeventlistenerlist_js, 3474) },
        File { "cmaj_api/cmaj-generic-patch-view.js", std::string_view (cmaj_api_cmajgenericpatchview_js, 6912) },
        File { "cmaj_api/cmaj-midi-helpers.js", std::string_view (cmaj_api_cmajmidihelpers_js, 13253) },
        File { "cmaj_api/cmaj-parameter-controls.js", std::string_view (cmaj_api_cmajparametercontrols_js, 30756) },
        File { "cmaj_api/cmaj-patch-view.js", std::string_view (cmaj_api_cmajpatchview_js, 7388) },
        File { "cmaj_api/cmaj-piano-keyboard.js", std::string_view (cmaj_api_cmajpianokeyboard_js, 15557) },
        File { "cmaj_api/cmaj-server-session.js", std::string_view (cmaj_api_cmajserversession_js, 18553) },
        File { "ui/index-vintage.html", std::string_view (ui_indexvintage_html, 25887) },
        File { "ui/index.html", std::string_view (ui_index_html, 25670) },
        File { "ui/main-vintage.js", std::string_view (ui_mainvintage_js, 22207) },
        File { "ui/main.js", std::string_view (ui_main_js, 18143) },
        File { "ui/size-manager.js", std::string_view (ui_sizemanager_js, 6314) },
        File { "ui/size-modes.css", std::string_view (ui_sizemodes_css, 12378) },
        File { "ui/styles-vintage.css", std::string_view (ui_stylesvintage_css, 31262) },
        File { "ui/styles.css", std::string_view (ui_styles_css, 12012) }
    };

};



juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new cmaj::plugin::GeneratedPlugin<::CINTA> (std::make_shared<cmaj::Patch>());
}
