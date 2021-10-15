#pragma once

#ifndef _OBJECTCREATOR_H__
#define _OBJECTCREATOR_H__

#include "Ogre.h"
#include "Game.h"

class ObjectCreator
{
private:
	Ogre::ManualObject* Object = NULL;
	Ogre::String ObjName;
	float Length;
	float Width;
	int VertexNum;
	//Ogre::Vector3 vertex[VertexNum];
	int var[3];
public:
	ObjectCreator(Ogre::String& objectName, float length, float width, int vertexNumber)
		: ObjName(objectName), Length(length), Width(width), VertexNum(vertexNumber)
	{
		CreateObject();
	}

	void CreateObject()
	{
		Object = Game::Instance().getSceneManager()->createManualObject(ObjName);
		Object->setDynamic(false);
		Object->begin("FlatVertexColour", Ogre::RenderOperation::OT_TRIANGLE_LIST);

		for (int i = 0; i < VertexNum; i++)
		{
			Object->position(0, 0, 0);

		}
	}

	void CreateVertices()
	{

	}
};

#endif