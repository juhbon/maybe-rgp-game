#pragma once
#include "Creature.h"

class Thief :
    public Creature
{
    ConvexShape conv_thief;
public:
    Thief();
    Thief(int x, int y, String spr_string);
    void sprite_move();
    void set_pos(int x, int y);
    void jump();
    void hack();
    ConvexShape getSprite();
};

