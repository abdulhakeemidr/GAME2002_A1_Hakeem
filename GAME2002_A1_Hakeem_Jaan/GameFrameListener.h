#pragma once
#include "Ogre.h"
#include "Game.h"
#include <OgreApplicationContextBase.h>

class ExampleFrameListener : public Ogre::FrameListener
{
private:
    Ogre::SceneNode* _node;
    Ogre::Vector3 ballTranslate = Ogre::Vector3(1, 0, 0);
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
            
            _node->translate(ballTranslate * evt.timeSinceLastFrame);
            float Height = Game::Instance().getRenderWindow()->getHeight() / 2;
            float Width = Game::Instance().getRenderWindow()->getWidth() / 2;
            //std::cout << Game::Instance().getRenderWindow()->getWidth() << std::endl;
            std::cout << _node->getPosition().x << std::endl;

            if (_node->getPosition().x > Width)
            {
                ballTranslate = ballTranslate * -1;
            }
        }

        return true;
    }
};