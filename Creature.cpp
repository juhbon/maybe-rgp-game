#include "Creature.h"


// Creature CLASS REALIZATION

void Creature::sprite_move() {
	sprite.setPosition(pos.x, pos.y);
	//window.draw(sprite);
}

Creature::Creature() {
	pos.x = MOVEMENT_UNIT;
	pos.y = MOVEMENT_UNIT;
	glance = sight_direction::NORTH;
	texture.loadFromFile("img/sprite.png");
	Sprite temp_sprite(texture);
	sprite = temp_sprite;
	sprite_move();
}

Creature::Creature(int x, int y)
{
	pos.x = x;
	pos.y = y;
	glance = sight_direction::NORTH;
	texture.loadFromFile("img/sprite.png");
	Sprite temp_sprite(texture);
	sprite = temp_sprite;
	Creature::sprite_move();
}

void Creature::move_left() {
	if (alive) {
		glance = sight_direction::WEST;
		pos.x -= MOVEMENT_UNIT;
		Creature::sprite_move();
	}
}

void Creature::move_right() {
	if (alive) {
		glance = sight_direction::EAST;
		pos.x += MOVEMENT_UNIT;
		Creature::sprite_move();
	}
}

void Creature::move_up() {
	if (alive) {
		glance = sight_direction::NORTH;
		pos.y -= MOVEMENT_UNIT;
		Creature::sprite_move();
	}
}

void Creature::move_down() {
	if (alive) {
		glance = sight_direction::SOUTH;
		pos.y += MOVEMENT_UNIT;
		Creature::sprite_move();
	}
}

void Creature::set_pos(int x, int y)
{
	if (alive) {
		pos.x = x;
		pos.y = y;
		Creature::sprite_move();
	}
}

Vector2i Creature::get_pos()
{
	return pos;
}

Sprite& Creature::getSprite() {
	return sprite;
}
