#include "Hunter.h"

// Hunter CLASS REALIZATION

void Hunter::Hunter::move_hole(int x, int y)
{
	pos.x += x;
	pos.y += y;
	sprite.setPosition(pos.x, pos.y);
	//window.draw(sprite);
}

Hunter::Hunter()
{
	texture.loadFromFile("img/circle.png");
	Sprite temp_sprite(texture);
	sprite = temp_sprite;
	sprite.setOrigin(75, 65);
	Hunter::move_hole(320, 320);
}

Hunter::Hunter(int x, int y, String spr_string)
{
	texture.loadFromFile(spr_string);
	Sprite temp_sprite(texture);
	sprite = temp_sprite;
	sprite.setOrigin(75, 65);
	Hunter::move_hole(x, y);
}


Sprite& Hunter::getSprite()
{
	return sprite;
}