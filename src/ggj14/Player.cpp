#include "ggj14/Player.hpp"
#include "jam-engine/Utility/Assert.hpp"
#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Core/GamepadPredefs.hpp"
#include "jam-engine/Utility/Math.hpp"

#include "ggj14/Level.hpp"
#include "ggj14/Block.hpp"

namespace ggj14
{

Player::Player(Level *level, const sf::Vector2f& pos)
	:je::Entity(level, "Player", pos, sf::Vector2i(32, 32))
	,level(level)
	,input(level->getGame().getInput())
	,veloc(0, 0)
	,prevPos(pos)
{
	box.setSize(sf::Vector2f(32, 32));
	box.setFillColor(sf::Color::Green);
	box.setOutlineColor(sf::Color::White);
	box.setOutlineThickness(3);

	input.setKeybinds("jump", {
		je::Controller::Bind(sf::Keyboard::W),
		je::Controller::Bind(sf::Keyboard::Up),
		je::Controller::Bind(sf::Joystick::Axis::Y, true),
		je::Controller::Bind(je::Binds::X360::A)
	});
	input.setKeybinds("right", {
		je::Controller::Bind(sf::Keyboard::D),
		je::Controller::Bind(sf::Keyboard::Right),
		je::Controller::Bind(sf::Joystick::Axis::X),
		je::Controller::Bind(je::Binds::X360::DPadRight)
	});
	input.setKeybinds("left", {
		je::Controller::Bind(sf::Keyboard::A),
		je::Controller::Bind(sf::Keyboard::Left),
		je::Controller::Bind(sf::Joystick::Axis::X, true),
		je::Controller::Bind(je::Binds::X360::DPadLeft)
	});
}

void Player::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	target.draw(box);
}

void Player::onUpdate()
{
	int newY = level->rayCastManually(this, "Block", [](Entity *e)->bool{return((Block*)e)->isActive();}, sf::Vector2f(0, veloc.y)).y;
	if (newY == prevPos.y)
	{
		veloc.y = 0;
		if (input.isActionPressed("jump"))
		{
			veloc.y = -9;
		}
	}
	else
	{
		veloc.y += 0.3;
	}

	if (input.isActionHeld("right"))
		veloc.x += 0.5;
	else if (input.isActionHeld("left"))
		veloc.x -= 0.5;
	else if (newY == prevPos.y)
	{
		if (veloc.x > 0.5)
			veloc.x -= 0.5;
		else if (veloc.x < -0.5)
			veloc.x += 0.5;
		else
			veloc.x = 0;
	}
	je::limit(veloc.x, -4.f, 4.f);


	pos.y -= 1;
	int newX = level->rayCastManually(this, "Block", [](Entity *e)->bool{return((Block*)e)->isActive();}, sf::Vector2f(veloc.x, 0)).x;
	if (pos.x == newX)
		veloc.x = 0;
	pos.x = newX;
	pos.y = newY;
	level->setCameraPosition(pos);

	prevPos = pos;

	box.setFillColor(sfColours[level->getActiveColour()]);

	//	update drawables
	box.setPosition(pos);
}

}
