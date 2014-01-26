#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Graphics/TexManager.hpp"

#include "ggj14/Level.hpp"

int main()
{

	je::Game game(640, 480, 60);
	game.getTexManager().setPath("resources/img/");
	game.setLevel(new ggj14::Level(&game));
    return game.execute();
}
