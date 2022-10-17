#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
    public:
        Game(Player p1, Player p2, Board b);
        void play_game();
    private:
        Player player1;
        Player player2;
        Board board;
        Player* player;
        int rounds {0};
        int play[2] {};
        void set_player();
        void get_play();
        bool check_end();
};

#endif