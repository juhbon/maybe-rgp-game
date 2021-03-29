#include "Hero.h"


// HERO CLASS REALIZATION

void Hero::sprite_move() {
	sprite.setPosition(pos.x, pos.y);
	//window.draw(sprite);
}

Hero::Hero(int x, int y)
	: alive(true)
{
	pos.x = x;
	pos.y = y;
	glance = sight_direction::NORTH;
	texture.loadFromFile("img/sprite.png");
	Sprite temp_sprite(texture);
	sprite = temp_sprite;
	Hero::sprite_move();
}

void Hero::move_left() {
	if (alive) {
		glance = sight_direction::WEST;
		pos.x -= MOVEMENT_UNIT;
		Hero::sprite_move();
	}
}

void Hero::move_right() {
	if (alive) {
		glance = sight_direction::EAST;
		pos.x += MOVEMENT_UNIT;
		Hero::sprite_move();
	}
}

void Hero::move_up() {
	if (alive) {
		glance = sight_direction::NORTH;
		pos.y -= MOVEMENT_UNIT;
		Hero::sprite_move();
	}
}

void Hero::move_down() {
	if (alive) {
		glance = sight_direction::SOUTH;
		pos.y += MOVEMENT_UNIT;
		Hero::sprite_move();
	}
}

void Hero::set_pos(int x, int y)
{
	if (alive) {
		pos.x = x;
		pos.y = y;
		Hero::sprite_move();
	}
}

Vector2i Hero::get_pos()
{
	return pos;
}

Sprite& Hero::getSprite() {
	return sprite;
}
