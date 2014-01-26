#include "ggj14/Level.hpp"

#include "jam-engine/Utility/Random.hpp"

#include "ggj14/Player.hpp"
#include "ggj14/Block.hpp"

namespace ggj14
{

Level::Level(je::Game *game, int width, int height)
	:je::Level(game, width, height)
	,activeColour(Colour::White)
{
	this->addEntity(new Player(this, sf::Vector2f(320, 240)));
	box.setPosition(4, 4);
	box.setSize(sf::Vector2f(getWidth() - 8, getHeight() - 8));
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineColor(sf::Color::White);
	box.setOutlineThickness(4);

	for (int x = 0; x < 640; x += 32)
		for (int y = 0; y < 480; y += 32)
			if (je::randomf(1) < 0.2)
				addEntity(new Block(this, sf::Vector2f(x, y), je::choose({Blue, Yellow, Purple, White, Red, Green})));
}

Colour Level::getActiveColour() const
{
	return activeColour;
}

/*		private			*/
void Level::onUpdate()
{
	if (je::randomf(1) < 0.05)
		activeColour = je::choose({White, Red, Green, Blue, Yellow, Purple});
}

void Level::onDraw(sf::RenderTarget& target) const
{
	target.draw(box);
}

}
