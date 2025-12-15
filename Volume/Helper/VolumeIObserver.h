#ifndef VOLUMEIOBSERVER_H
#define VOLUMEIOBSERVER_H

#include <string>

class VolumeIObserver {
public:
    virtual ~VolumeIObserver(){};
    virtual void Update(const std::string &message_from_subject) = 0;
};

#endif // VOLUMEIOBSERVER_H
