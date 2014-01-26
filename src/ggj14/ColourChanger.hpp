#ifndef GGJ14_COLOUR_CHANGER_HPP
#define GGJ14_COLOUR_CHANGER_HPP

#include <SFML/Graphics/Color.hpp>

#include "ggj14/Colours.hpp"

namespace ggj14
{

class Level;

class ColourChanger
{
public:
	ColourChanger(Level *level, Colour colour);

	void update();

	bool isActive() const;

	sf::Color getSFColor() const;

private:

	const Level * const level;
	const Colour colour;
	float active;
};

}

#endif
