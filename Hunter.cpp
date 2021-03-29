#include "Hunter.h"


// Hunter CLASS REALIZATION

void Hunter::Hunter::move_hole(int x, int y)
{
	pos.x += x;
	pos.y += y;
	sprite.setPosition(pos.x, pos.y);
	//window.draw(sprite);
}

Hunter::Hunter(int x, int y)
{
	texture.loadFromFile("img/circle.png");
	Sprite temp_sprite(texture);
	sprite = temp_sprite;
	sprite.setOrigin(75, 65);
	Hunter::move_hole(x, y);
}

void Hunter::move_to_hero(Creature& myTarget)
{
	if(alive){
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
}

Sprite& Hunter::getSprite()
{
	return sprite;
}