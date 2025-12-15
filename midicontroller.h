#ifndef MIDICONTROLLER_H
#define MIDICONTROLLER_H

#include <cstdlib>
#include "RtMidi.h"


class MidiController
{
public:
    MidiController();
private:
    RtMidiIn  *midiin;
    RtMidiOut *midiout;
};

#endif // MIDICONTROLLER_H
