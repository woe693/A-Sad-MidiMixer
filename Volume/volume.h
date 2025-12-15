#ifndef VOLUME_H
#define VOLUME_H

#include "Volume/Helper/VolumeISubject.h"
#include <iostream>
#include <list>

class Volume : public VolumeISubject {
public:
    virtual ~Volume() {
        std::cout << "Goodbye, I was the Subject.\n";
    }

    /**
   * The subscription management methods.
   */
    void Attach(VolumeIObserver *observer) override ;
    void Detach(VolumeIObserver *observer) override ;
    void Notify() override ;
    void CreateMessage(std::string message = "Empty");
    void HowManyObserver();
    void SomeBusinessLogic();

private:
    std::list<VolumeIObserver *> list_observer_;
    std::string message_;
};

#endif // VOLUME_H
