#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	// Moving circle
	circle.setRadius(30);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Yellow);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(2.f);

	// Speed
	speed = 1000.f;

	// Rectangle
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	/*if (input->isKeyDown(sf::Keyboard::Up)) {
		input->setKeyUp(sf::Keyboard::Up);
		moveUp = true;
	}
	*/
}

// Update game objects
void Level::update(float dt)
{
	// Move circle
	if (moveRight) {
		circle.move(speed * dt, 0);
	}
	else {
		circle.move(-speed * dt, 0);
	}

	if (circle.getPosition().x >= window->getSize().x) {
		moveRight = false;
	}
	else if (circle.getPosition().x <= 0) {
		moveRight = true;
	}

	/* Move Rectangle
		if (moveUp) {
			rect.move(0, speed * dt);
		}
		else {
			rect.move(0, -speed * dt);
		}
		*/
	
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
	window->draw(rect);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}