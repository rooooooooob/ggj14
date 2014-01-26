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
	,colourChanger(level, colour)
	,box(sf::Vector2f(getDimensions().x, getDimensions().y))
{
	box.setPosition(pos);
}

bool Block::isActive() const
{
	return colourChanger.isActive();
}

/*		private		*/
void Block::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	target.draw(box, states);
}

void Block::onUpdate()
{
	colourChanger.update();
	box.setFillColor(colourChanger.getSFColor());
}

}
