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
	Hunter();
	Hunter(int x, int y, String spr_string);

	template <typename T>
	void move_to_hero(T& myTarget)
	{
		if (alive) {
			sprite.rotate(5);
			Vector2i hero_pos = myTarget.get_pos();
			float new_pos_x, new_pos_y;
			if (pos_x != hero_pos.x && pos_y != hero_pos.y)
			{
				int temp_point_x = (hero_pos.x - pos.x);
				int temp_point_y = (hero_pos.y - pos.y);
				float length = sqrt((temp_point_x * temp_point_x) + (temp_point_y * temp_point_y));
				new_pos_x = (temp_point_x / abs(length)) * 5;
				new_pos_y = (temp_point_y / abs(length)) * 5;
				Hunter::move_hole(new_pos_x, new_pos_y);
			}
		}
	}	Sprite& getSprite();
};
