#pragma once

enum MessageType
{
    None,
    Quit,
    Collision,
    ChangeState,
    DebugDrawGameObject,
    DebugDrawAllObjects,
    ToggleDebugDraw,
    WorldSizeChange,
    ChangeGravity
};

class Message
{
public:
    Message(MessageType id) : type(id){};
    MessageType type;
    virtual ~Message(){};
};

