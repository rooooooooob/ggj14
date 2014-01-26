#ifndef GGJ14_COLOURS_HPP
#define GGJ14_COLOURS_HPP

namespace ggj14
{

enum Colour
{
	White = 0,
	Red,
	Green,
	Blue,
	Yellow,
	Purple,
	TotalColours
};

const sf::Color sfColours[999] = {
	sf::Color(255, 255, 255),	//	white
	sf::Color(192, 0, 0),		//	red
	sf::Color(0, 164, 0),		//	green
	sf::Color(0, 0, 192),		//	blue
	sf::Color(192, 192, 0),		//	yellow
	sf::Color(164, 0, 192)		//	purple
};

}

#endif // GGJ14_COLOURS_HPP
