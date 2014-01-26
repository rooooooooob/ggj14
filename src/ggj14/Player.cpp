#include "ggj14/Player.hpp"
#include <iostream>
#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Core/GamepadPredefs.hpp"
#include "jam-engine/Utility/Math.hpp"

#include "ggj14/Level.hpp"

namespace ggj14
{

Player::Player(Level *level, const sf::Vector2f& pos)
	:je::Entity(level, "Player", pos, sf::Vector2i(32, 32))
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
	if (input.isActionHeld("right"))
		veloc.x += 0.5;
	if (input.isActionHeld("left"))
		veloc.x -= 0.5;
	je::limit(veloc.x, -4.f, 4.f);

	if (pos.y + getDimensions().y + 4 >= level->getHeight())
	{
		veloc.y = 0;
		if (input.isActionPressed("jump"))
		{
			veloc.y = -9;
		}
		pos.y = prevPos.y;
	}
	else
	{
		veloc.y += 0.3;
	}

	pos += veloc;

	level->setCameraPosition(pos);

	prevPos = pos;

	//	update drawables
	box.setPosition(pos);
}

}
