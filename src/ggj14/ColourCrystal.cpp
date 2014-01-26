#include "ggj14/ColourCrystal.hpp"

#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Graphics/TexManager.hpp"

#include "ggj14/Level.hpp"

namespace ggj14
{

ColourCrystal::ColourCrystal(Level *level, const sf::Vector2f& pos, Colour colour)
	:je::Entity(level, "ColourCrystal", pos, sf::Vector2i(32, 32))
	,level(level)
	,colour(colour)
	,cooldown(0)
	,sprite(level->getGame().getTexManager().get("colour_crystal.png"))
{
	sprite.setPosition(pos);
	sprite.setColor(sfColours[colour]);
}

void ColourCrystal::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	if (cooldown == 0)
		target.draw(sprite, states);
}

void ColourCrystal::onUpdate()
{
	if (cooldown > 0)
		--cooldown;
	else
	{
		if (level->testCollision(this, "Player"))
		{
			level->setActiveColour(colour);
			cooldown = 360;
		}
	}
}

}
