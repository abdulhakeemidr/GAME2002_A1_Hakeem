#pragma once
#include "Ogre.h"
#include "Game.h"

class ExampleFrameListener : public Ogre::FrameListener
{
private:
    Ogre::SceneNode* _node;
public:

    ExampleFrameListener(Ogre::SceneNode* node)
    {
        _node = node;
    }

    bool frameStarted(const Ogre::FrameEvent& evt)
    {
        if (_node->getName() == "Player")
        {
            _node->translate(translate * evt.timeSinceLastFrame);
            translate = Ogre::Vector3(0, 0, 0);
        }
        if (_node->getName() == "Ball")
        {
            _node->translate(Ogre::Vector3(1, 0, 0) * evt.timeSinceLastFrame);
        }

        return true;
    }
};