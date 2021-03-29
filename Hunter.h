#pragma once
#include "Includes.h"
#include "Creature.h"

class Hunter
{
	Vector2i pos;
	int pos_x, pos_y;
	Texture texture;
	Sprite sprite;
	bool alive = true;

	void move_hole(int x, int y);
public:
	Hunter(int x, int y);
	void move_to_hero(Creature& myTarget);
	Sprite& getSprite();
};
