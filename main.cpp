#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Game.h"

int main(){
    Board board;

    Player player1 ('X');
    Player player2 ('O');
    Game game(player1, player2, board);
    game.play_game();

    return 0;
}