#ifndef NANOKONTROL2_H
#define NANOKONTROL2_H

#include <cstdlib>
#include "RtMidi.h"
#include <memory>
#include <thread>


// slide1 = 0
//     S = slide1 + 1
//     M = slide1 + 1
//     R = slide1 + 1
//     Knob = slide1 + 8

// slide2 = 1
// slide3 = 2
// slide4 = 3
// slide5 = 4
// slide6 = 5
// slide7 = 6
// slide8 = 7
// TrackLeft = 58
// TrackRight = 59

class NanoKontrol2
{
public:
    NanoKontrol2();
    NanoKontrol2(int MidiInputID, int MidiOutputID);
    // ~NanoKontrol2();
private:


    std::string MixerName = "nanoKONTROL2";

    std::unique_ptr<RtMidiIn>  midiin;
    std::unique_ptr<RtMidiOut> midiout;
    int miniinPort{};
    int minioutPort{};
    std::string portName;
    std::thread mixerMessageThread;
    void cb();
    static volatile sig_atomic_t done;


    static void finish(int);
    static void mycallback( double deltatime, std::vector< unsigned char > *message, void *userData );

};

#endif // NANOKONTROL2_H
