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
	Ogre::ManualObject* Object = NULL;
	// Dynamic array of Vector3
	//Ogre::Vector3 vertex[VertexNum];
	std::vector<Ogre::Vector3> vertices;
	Ogre::String ObjName;
	float Height;
	float Width;
	int VertexNum;
public:
	ObjectCreator(Ogre::String objectName, float height, float width, int vertexNumber = 4)
		: ObjName(objectName), Height(height), Width(width), VertexNum(vertexNumber)
	{
		CreateVertices();
		CreateObject();
	}

	ManualObject* getObject()
	{
		return Object;
	}

	void CreateObject()
	{
		Object = Game::Instance().getSceneManager()->createManualObject(ObjName);
		Object->setDynamic(false);
		Object->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

		for (int i = 0; i < VertexNum; i++)
		{
			Object->position(vertices[i]);
		}

		Object->triangle(0, 1, 2);
		Object->triangle(0, 2, 3);

		Object->end();
	}

	void CreateVertices()
	{
		Ogre::Vector3 widthVec(Width, 0, 0);
		Ogre::Vector3 heightVec(0, Height, 0);

		vertices.push_back(Vector3::ZERO); // bottom left

		vertices.push_back(widthVec); // bottom right
		
		
		vertices.push_back(heightVec + widthVec); // top left
		
		vertices.push_back(heightVec); // top right
	}
};

#endif