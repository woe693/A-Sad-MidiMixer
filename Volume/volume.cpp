#include "volume.h"

void Volume::Attach(VolumeIObserver *observer)
{
    list_observer_.push_back(observer);
}

void Volume::Detach(VolumeIObserver *observer)
{
    list_observer_.remove(observer);
}

void Volume::Notify()
{
    std::list<VolumeIObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end())
    {
        (*iterator)->Update(message_);
        ++iterator;
    }
}

void Volume::CreateMessage(std::string message)
{
    this->message_ = message;
    Notify();
}

void Volume::HowManyObserver()
{
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
}

void Volume::SomeBusinessLogic()
{
    this->message_ = "change message message";
    Notify();
    std::cout << "I'm about to do some thing important\n";
}
