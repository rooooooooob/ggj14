#include "ggj14/Spikes.hpp"

#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Graphics/TexManager.hpp"
#include "jam-engine/Utility/Math.hpp"

#include "ggj14/Level.hpp"

namespace ggj14
{

const float BLOCK_CHANGE_RATE = 3;

Spikes::Spikes(Level *level, const sf::Vector2f& pos, Colour colour)
	:je::Entity(level, "Spikes", pos, sf::Vector2i(32, 32))
	,level(level)
	,colour(colour)
	,colourChanger(level, colour)
	,sprite(level->getGame().getTexManager().get("spikes.png"))
{
	sprite.setPosition(pos);
}

bool Spikes::isActive() const
{
	return colourChanger.isActive();
}

/*		private		*/
void Spikes::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	target.draw(sprite, states);
}

void Spikes::onUpdate()
{
	colourChanger.update();
	sprite.setColor(colourChanger.getSFColor());
}

}
