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
	,active(0)
	,sprite(level->getGame().getTexManager().get("spikes.png"))
{
	sprite.setPosition(pos);
	this->updateDrawable();
}

bool Spikes::isActive() const
{
	return colour == Colour::White || active > 0;
}

/*		private		*/
void Spikes::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	target.draw(sprite, states);
}

void Spikes::onUpdate()
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

void Spikes::updateDrawable()
{
	sf::Color col = sfColours[colour];
	je::limit(active, 0.f, 255.f);
	if (colour != Colour::White)
		col.a = active;
	sprite.setColor(col);
}

}
