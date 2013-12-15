#pragma once
#include "Message.h"

class ChangeGravityMessage : public Message
{
public:
    ChangeGravityMessage(float _newGravity) : Message(ChangeGravity), newGravity(_newGravity){};
    float newGravity;
    virtual ~ChangeGravityMessage(){};
};