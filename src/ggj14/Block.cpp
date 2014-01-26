#include "ggj14/Block.hpp"

#include "jam-engine/Utility/Math.hpp"

#include "ggj14/Level.hpp"

namespace ggj14
{

const float BLOCK_CHANGE_RATE = 3;

Block::Block(Level *level, const sf::Vector2f& pos, Colour colour)
	:je::Entity(level, "Block", pos, sf::Vector2i(32, 32))
	,level(level)
	,colour(colour)
	,active(0)
	,box(sf::Vector2f(getDimensions().x, getDimensions().y))
{
	box.setPosition(pos);
	this->updateDrawable();
}

bool Block::isActive() const
{
	return colour == Colour::White || active > 0;
}

/*		private		*/
void Block::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	target.draw(box, states);
}

void Block::onUpdate()
{
//	if (isActive())
//		level->testCollision(this, "fuck");
	if (colour != Colour::White)
	{
		if (level->getActiveColour() != colour)
		{
			if (active > 0.f)
			{
				active -= BLOCK_CHANGE_RATE;
				this->updateDrawable();
			}
			else
				active = 0.f;
		}
		else
		{
			if (active < 255.f)
			{
				active += BLOCK_CHANGE_RATE;
				this->updateDrawable();
			}
			else
				active = 255.f;
		}
	}
					this->updateDrawable();
}

void Block::updateDrawable()
{
	sf::Color col = sfColours[colour];
	je::limit(active, 0.f, 255.f);
	if (colour != Colour::White)
		col.a = active;
	box.setFillColor(col);
}

}
