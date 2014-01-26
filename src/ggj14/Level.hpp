#ifndef GGJ14_LEVEL_HPP
#define GGJ14_LEVEL_HPP

#include "jam-engine/Core/Level.hpp"

#include "ggj14/Colours.hpp"

namespace ggj14
{

class Level : public je::Level
{
public:
	Level(je::Game *game, int width, int height);

	Colour getActiveColour() const;

private:
	void onUpdate() override;

	void onDraw(sf::RenderTarget& target) const override;

	sf::RectangleShape box;
	Colour activeColour;
};

}

#endif // GGJ14_LEVEL_HPP
