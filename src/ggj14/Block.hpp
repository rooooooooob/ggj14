#ifndef GGJ14_BLOCK_HPP
#define GGJ14_BLOCK_HPP

#include <SFML/Graphics/RectangleShape.hpp>

#include "jam-engine/Core/Entity.hpp"

#include "ggj14/Colours.hpp"
#include "ggj14/ColourChanger.hpp"

namespace ggj14
{

class Level;

class Block : public je::Entity
{
public:
	Block(Level *level, const sf::Vector2f& pos, Colour colour);

	bool isActive() const;

private:
	void draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) const override;

	void onUpdate() override;

	void updateDrawable();


	Level *level;
	Colour colour;
	ColourChanger colourChanger;
	sf::RectangleShape box;
};

}

#endif // GGJ14_BLOCK_HPP
