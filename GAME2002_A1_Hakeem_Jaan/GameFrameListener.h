#pragma once
#include "Ogre.h"
#include "Game.h"
#include <OgreApplicationContextBase.h>

class ExampleFrameListener : public Ogre::FrameListener
{
private:
    Ogre::SceneNode* _node;
    Ogre::Vector3 ballTranslate = Ogre::Vector3(1, 0.5, 0);
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
            std::cout << _node->getPosition().x << std::endl;
        }

        if (_node->getName() == "Ball")
        {
            if (_node->getPosition().x > 7 || _node->getPosition().x < -7)
            {
                ballTranslate.x = -ballTranslate.x;
            }

            if (_node->getPosition().y > 6 || _node->getPosition().y < -6)
            {
                ballTranslate.y = -ballTranslate.y;
            }

            _node->translate(10 * ballTranslate * evt.timeSinceLastFrame);

            //_node->_getWorldAABB().intersects();


            //std::cout << Game::Instance().getRenderWindow()->getViewport(0)->getWidth() << std::endl;
            //unsigned int h, w, cd;
            //Game::Instance().getRenderWindow()->getMetrics(w, h, cd);
            ////std::cout << _node->getPosition().x << std::endl;
            //std::cout << "Width is " << w << ", Height is " << h << std::endl;
            //std::cout << evt.timeSinceLastEvent << std::endl;
            
            
        }

        return true;
    }
};