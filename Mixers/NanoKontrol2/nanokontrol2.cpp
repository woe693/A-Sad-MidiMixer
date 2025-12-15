#include "nanokontrol2.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <bits/stdc++.h>


NanoKontrol2::NanoKontrol2(int MidiInputID, int MidiOutputID)
    : minioutPort{MidiOutputID}, miniinPort{MidiInputID}
{
    std::cout << "beep";

    try {
        midiin = std::make_unique<RtMidiIn>();
        midiout = std::make_unique<RtMidiOut>();
    }
    catch ( RtMidiError &error ) {
        error.printMessage();
        exit( EXIT_FAILURE );
    }

    std::cout << "Input ports: " << midiin->getPortCount() << "\n";
    std::cout << "Output ports: " << midiout->getPortCount() << "\n";


    // Use the IDs you passed in:
    midiin->openPort(miniinPort);
    // midiout->openPort(minioutPort);
    midiin->setCallback( &mycallback );

}



void NanoKontrol2::mycallback( double deltatime, std::vector< unsigned char > *message, void *userData )
{
    unsigned int nBytes = message->size();
    for ( unsigned int i=0; i<nBytes; i++ )
        std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
    if ( nBytes > 0 )
        std::cout << "stamp = " << deltatime << std::endl;
}
