#ifndef GGJ14_SPIKES_HPP
#define GGJ14_SPIKES_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "jam-engine/Core/Entity.hpp"

#include "ggj14/Colours.hpp"
#include "ggj14/ColourChanger.hpp"

namespace ggj14
{

class Level;

class Spikes : public je::Entity
{
public:
	Spikes(Level *level, const sf::Vector2f& pos, Colour colour);

	bool isActive() const;

private:
	void draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) const override;

	void onUpdate() override;


	Level *level;
	Colour colour;
	ColourChanger colourChanger;
	sf::Sprite sprite;

};

}

#endif // GGJ14_SPIKES_HPP
