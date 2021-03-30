#include "Thief.h"

void Thief::sprite_move() {
	conv_thief.setRotation(90 * int(glance));
	conv_thief.setPosition(pos.x, pos.y);
}

Thief::Thief() {
	//ConvShape conv_thief;
	conv_thief.setPointCount(4);
	conv_thief.setPoint(0, Vector2f(0.f, 32.f));
	conv_thief.setPoint(1, Vector2f(16.f, 0.f));
	conv_thief.setPoint(2, Vector2f(0.f, 70.f));
	conv_thief.setPoint(3, Vector2f(16.f, 32.f));
	conv_thief.setFillColor(Color::Cyan);
	conv_thief.setOutlineThickness(5);
	conv_thief.setOutlineColor(Color::Blue);
	conv_thief.setOrigin(16, 16);
	sprite_move();
	//w.draw(conv_thief);
}

Thief::Thief(int x, int y, String spr_string): Creature(x+16, y+16, spr_string) {
	//Creature(x, y, spr_string);
	conv_thief.setPointCount(4);
	conv_thief.setPoint(0, Vector2f(0.f, 32.f));
	conv_thief.setPoint(1, Vector2f(16.f, 0.f));
	conv_thief.setPoint(2, Vector2f(32.f, 32.f));
	conv_thief.setPoint(3, Vector2f(16.f, 21.f));
	conv_thief.setFillColor(Color::Cyan);
	conv_thief.setOutlineThickness(2);
	conv_thief.setOutlineColor(Color::Blue);
	conv_thief.setOrigin(16, 16);
	sprite_move();
}

void Thief::jump()
{
	Vector2i direction = this->get_pos();
    // TODO: Add your implementation code here.
}


void Thief::hack()
{
    // TODO: Add your implementation code here.
}

ConvexShape Thief::getSprite() {
	return conv_thief;
}
