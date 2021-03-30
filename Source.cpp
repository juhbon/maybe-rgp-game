#include "Includes.h"
#include "Creature.h"
#include "Hunter.h"
#include "Thief.h"

using namespace std;
using namespace sf;

const int WINDOW_X = MOVEMENT_UNIT*80;
const int WINDOW_Y = MOVEMENT_UNIT*32;

RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), "It's alive!");

Thief myHero; // 32, 32, string("img/sprite.png"));
Hunter myDeleter(400, 400, string("img/circle.png"));

void event_process(RenderWindow& w, Event& ev) 
{
	if (ev.type == Event::Closed)
	{
		w.close();
		cout << "window's closed";
	}
	else if (ev.type == Event::KeyPressed)
	{
		myDeleter.move_to_hero(myHero);
		switch (ev.key.code)
		{
		case Keyboard::Right:
			myHero.move_right();
			break;
		case Keyboard::Left:
			myHero.move_left(); 
			break;
		case Keyboard::Up:
			myHero.move_up();
			break;
		case Keyboard::Down:
			myHero.move_down();
			break;
		}
	}
	else if (ev.type == Event::MouseButtonReleased)
	{
		int x = ev.mouseButton.x - (ev.mouseButton.x % 32);
		int y = ev.mouseButton.y - (ev.mouseButton.y % 32);
		myHero.set_pos(x, y);
		myDeleter.move_to_hero(myHero);
	}
}

int main() {

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event)) 
		{
			event_process(window, event);
		}
		window.clear(Color(0, 0, 0, 255));

		Texture back_texture;
		back_texture.loadFromFile("img/tile.png");
		back_texture.setRepeated(true);
		Sprite back_sprite(back_texture, IntRect(MOVEMENT_UNIT, MOVEMENT_UNIT, WINDOW_X, WINDOW_Y));
		window.draw(back_sprite);

		/*
		ConvexShape conv;
		conv.setPointCount(4);
		conv.setPoint(0, Vector2f(0.f, 0.f));
		conv.setPoint(1, Vector2f(100.f, 35.f));
		conv.setPoint(2, Vector2f(0.f, 70.f));
		conv.setPoint(3, Vector2f(30.f, 35.f));
		conv.setFillColor(Color::Cyan);
		conv.setOutlineThickness(5);
		conv.setOutlineColor(Color::Blue);
		conv.move(15, 15);
		window.draw(conv);

		RectangleShape line_with_thickness(Vector2f(130.f, 5.f));
		line_with_thickness.rotate(45.f); // поворачиваем её на 45 градусов
		line_with_thickness.setFillColor(Color(15, 180, 140)); // устанавливаем цвет линии
		line_with_thickness.move(0, 150); // перемещаем её в нижний ряд справа от прямоугольника
		window.draw(line_with_thickness); // отрисовка линии
		*/

		window.draw(myHero.getSprite());
		window.draw(myDeleter.getSprite());

		window.display();
	}

	return 0;
}