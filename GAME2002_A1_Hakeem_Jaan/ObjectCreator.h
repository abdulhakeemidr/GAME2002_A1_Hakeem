#pragma once

#ifndef _OBJECTCREATOR_H__
#define _OBJECTCREATOR_H__

#include "Ogre.h"
#include "Game.h"
#include <vector>

using namespace Ogre;

class ObjectCreator
{
private:
	Ogre::Entity* ObjectEntity = NULL;
	Ogre::SceneNode* ObjSceneNode = NULL;
	// Dynamic array of Vector3
	//Ogre::Vector3 vertex[VertexNum];
	std::vector<Ogre::Vector3> vertices;
	Ogre::String ObjName;
	SceneManager::PrefabType pType;
	Ogre::Vector3 Position;
	Ogre::Vector3 Scale;

	void CreateObjEntity(Ogre::String SceneName)
	{
		ObjectEntity = Game::Instance().getSceneManager()->createEntity(pType);
		ObjSceneNode = Game::Instance().getSceneManager()->getRootSceneNode()->createChildSceneNode(SceneName);
		ObjSceneNode->setPosition(0, -5, 0);
		ObjSceneNode->setScale(Scale);
		ObjSceneNode->attachObject(ObjectEntity);
	}

public:
	ObjectCreator(Ogre::String objectName, Ogre::SceneManager::PrefabType type, const Vector3 &position, const Vector3& scale)
		: ObjName(objectName), pType(type), Position(position)
	{
		Scale = scale;
		CreateObjEntity(objectName);
	}

	SceneNode* getObjectSceneNode()
	{
		return ObjSceneNode;
	}

	Entity* getObjEntity()
	{
		return ObjectEntity;
	}

};

#endif