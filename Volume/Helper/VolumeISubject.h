#ifndef VOLUMEISUBJECT_H
#define VOLUMEISUBJECT_H

#include "Volume/Helper/VolumeIObserver.h"

class VolumeISubject {
public:
    virtual ~VolumeISubject(){};
    virtual void Attach(VolumeIObserver *observer) = 0;
    virtual void Detach(VolumeIObserver *observer) = 0;
    virtual void Notify() = 0;
};

#endif // VOLUMEISUBJECT_H
