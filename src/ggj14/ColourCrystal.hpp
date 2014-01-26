#ifndef GGJ14_COLOUR_CRYSTAL_HPP
#define GGJ14_COLOUR_CRYSTAL_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "jam-engine/Core/Entity.hpp"

#include "ggj14/Colours.hpp"

namespace ggj14
{

class Level;

class ColourCrystal : public je::Entity
{
public:
	ColourCrystal(Level *level, const sf::Vector2f& pos, Colour colour);

private:
	void draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) const override;

	void onUpdate() override;

	Level *level;
	Colour colour;
	int cooldown;
	sf::Sprite sprite;
};

}

#endif
