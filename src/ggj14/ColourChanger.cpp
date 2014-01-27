#include "ggj14/ColourChanger.hpp"

#include "jam-engine/Utility/Math.hpp"

#include "ggj14/Level.hpp"

namespace ggj14
{

const float COLOUR_CHANGE_RATE = 2;

ColourChanger::ColourChanger(Level *level, Colour colour)
	:level(level)
	,colour(colour)
	,active(0)
{
}

void ColourChanger::update()
{
	if (colour != Colour::White)
	{
		if (level->getActiveColour() != colour)
		{
			if (active > 0.f)
				active -= COLOUR_CHANGE_RATE;
			else
				active = 0.f;
		}
		else
		{
			if (active < 255.f)
				active += COLOUR_CHANGE_RATE;
			else
				active = 255.f;
		}
	}
	je::limit(active, 0.f, 255.f);
}

bool ColourChanger::isActive() const
{
	return colour == Colour::White || active > 0.3f;
}

sf::Color ColourChanger::getSFColor() const
{
	sf::Color col = sfColours[colour];
	if (colour != Colour::White)
		col.a = active;
	return col;
}

}
