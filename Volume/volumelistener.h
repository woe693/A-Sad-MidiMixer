#ifndef VOLUMELISTENER_H
#define VOLUMELISTENER_H

#include <iostream>
#include <string>

#include "Volume/Helper/VolumeIObserver.h"
#include "Volume/volume.h"


class VolumeListener : public VolumeIObserver
{
public:
    VolumeListener(Volume &subject);
    virtual ~VolumeListener()
    {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }
    void Update(const std::string &message_from_subject);
    void RemoveMeFromTheList();
    void PrintInfo();

private:
    std::string message_from_subject_;
    Volume &subject_;
    static int static_number_;
    int number_;
};

#endif // VOLUMELISTENER_H
