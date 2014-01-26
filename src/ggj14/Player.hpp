#ifndef GGJ14_PLAYER_HPP
#define GGJ14_PLAYER_HPP

#include "SFML/Graphics.hpp"
#include "jam-engine/Core/Controller.hpp"
#include "jam-engine/Core/Entity.hpp"

namespace ggj14
{

class Level;

class Player : public je::Entity
{
public:
	Player(Level *level, const sf::Vector2f& pos);

private:
	void draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) const override;

	void onUpdate() override;

	je::Controller input;
	sf::RectangleShape box;
	sf::Vector2f veloc;
	sf::Vector2f prevPos;
};

}

#endif // GGJ14_PLAYER_HPP
