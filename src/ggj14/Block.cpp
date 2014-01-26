#include "ggj14/Block.hpp"

#include "ggj14/Level.hpp"
#include <iostream>
namespace ggj14
{

const float BLOCK_CHANGE_RATE = 0.025;

Block::Block(Level *level, const sf::Vector2f& pos, Colour colour)
	:je::Entity(level, "Block", pos, sf::Vector2i(32, 32))
	,level(level)
	,colour(colour)
	,active(0)
	,box(sf::Vector2f(getDimensions().x, getDimensions().y))
{
	box.setPosition(pos);
	this->updateDrawable();
	std::cout << colour;
}

bool Block::isActive() const
{
	return active > 0;
}

/*		private		*/
void Block::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	target.draw(box, states);
}

void Block::onUpdate()
{
	if (level->getActiveColour() != colour)
	{
		if (active > 0)
		{
			active -= BLOCK_CHANGE_RATE;
			this->updateDrawable();
		}
		else
			active = 0;
	}
	else
	{
		if (active < 1)
		{
			active += BLOCK_CHANGE_RATE;
			this->updateDrawable();
		}
		else
			active = 1;
	}
}

void Block::updateDrawable()
{
	sf::Color col = sfColours[colour];
	col.a = 255.f * active;
	box.setFillColor(col);
}

}
