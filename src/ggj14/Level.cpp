#include "ggj14/Level.hpp"

#include "jam-engine/Utility/Random.hpp"

#include "ggj14/Block.hpp"
#include "ggj14/ColourCrystal.hpp"
#include "ggj14/Player.hpp"
#include "ggj14/Spikes.hpp"

namespace ggj14
{

Level::Level(je::Game *game)
	:je::Level(game)
	,activeColour(Colour::White)
{
	this->loadMap("resources/levels/test.tmx");
}

Colour Level::getActiveColour() const
{
	return activeColour;
}

void Level::setActiveColour(Colour colour)
{
	this->activeColour = colour;
}

/*		private			*/
void Level::onUpdate()
{
//	if (je::randomf(1) < 0.05)
//		activeColour = je::choose({Red, Green, Blue, Yellow, Purple});
}

void Level::onDraw(sf::RenderTarget& target) const
{
}

void Level::loadTiles(const std::string& layerName, int tileWidth, int tileHeight, int tilesAcross, int tilesHigh, unsigned int const * const * tiles)
{
	Colour col = Colour::White;
	if (layerName == "White")
		col = Colour::White;
	else if (layerName == "Red")
		col = Colour::Red;
	else if (layerName == "Green")
		col = Colour::Green;
	else if (layerName == "Blue")
		col = Colour::Blue;
	else if (layerName == "Yellow")
		col = Colour::Yellow;
	else if (layerName == "Purple")
		col = Colour::Purple;
	else
		exit(666);

	for (int y = 0; y < tilesHigh; ++y)
	{
		for (int x = 0; x < tilesAcross; ++x)
		{			switch (tiles[x][y])
			{
			case 0:
				break;
			case 1://block
				addEntity(new Block(this, sf::Vector2f(x * 32, y * 32), col));
				break;
			case 2://spikes
				addEntity(new Spikes(this, sf::Vector2f(x * 32, y * 32), col));
				break;
			case 3://destroyable block
				addEntity(new Block(this, sf::Vector2f(x * 32, y * 32), col));
				break;
			case 5:
				addEntity(new ColourCrystal(this, sf::Vector2f(x * 32, y * 32), col));
				break;
			default:
				break;
			}
		}
	}
}

void Level::loadEntities(const std::string& layerName, const std::vector<EntityPrototype>& prototypes)
{
	for (const EntityPrototype& e : prototypes)
	{
		switch (e.id)
		{
		case 17:
			//place door
			break;
		case 18:
			this->addEntity(new Player(this, sf::Vector2f(e.x, e.y)));
			break;
		default:
			exit(1337);
			break;
		}
	}
}

}
