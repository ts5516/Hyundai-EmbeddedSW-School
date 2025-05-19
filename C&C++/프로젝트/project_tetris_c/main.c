#define _CRT_SECURE_NO_WARNINGS

#include "core/game.h"

Game game;

int main(void) {
    
    init_game(&game);

    while (!game_over) {
        update_game(&game);
    }

	end_game(&game);

    return 0;
}