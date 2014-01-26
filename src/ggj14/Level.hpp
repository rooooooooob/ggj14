#ifndef GGJ14_LEVEL_HPP
#define GGJ14_LEVEL_HPP

#include "jam-engine/Core/Level.hpp"

#include "ggj14/Colours.hpp"

namespace ggj14
{

class Level : public je::Level
{
public:
	Level(je::Game *game);

	Colour getActiveColour() const;

	void setActiveColour(Colour colour);

private:
	void onUpdate() override;

	void onDraw(sf::RenderTarget& target) const override;

	void loadTiles(const std::string& layerName, int tileWidth, int tileHeight, int tilesAcross, int tilesHigh, unsigned int const * const * tiles) override;

	void loadEntities(const std::string& layerName, const std::vector<EntityPrototype>& prototypes) override;


	Colour activeColour;
};

}

#endif // GGJ14_LEVEL_HPP
