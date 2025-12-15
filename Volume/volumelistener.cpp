#include "volumelistener.h"


int VolumeListener::static_number_ = 0;

VolumeListener::VolumeListener(Volume &subject):
    subject_(subject)
{
    this->subject_.Attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++VolumeListener::static_number_ << "\".\n";
    this->number_ = VolumeListener::static_number_;
};

void VolumeListener::Update(const std::string &message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void VolumeListener::RemoveMeFromTheList()
{
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}

void VolumeListener::PrintInfo()
{
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
}
