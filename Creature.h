#pragma once
#include "Includes.h"

enum class sight_direction {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

class Creature
{
protected:
	Vector2i pos;
	Texture texture;
	Sprite sprite;
	bool alive = true;
	sight_direction glance;

	virtual void sprite_move();
public:
	Creature();
	Creature(int x, int y, String spr_string);
	void move_left();
	void move_right();
	void move_up();
	void move_down();
	void set_pos(int x, int y);
	Vector2i get_pos();
	Sprite& getSprite();
	//virtual ~Creature() {};
};
