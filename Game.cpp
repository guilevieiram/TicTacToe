#include <iostream>
#include "Game.h"
using namespace std;

Game::Game(Player p1, Player p2, Board b){
    player1 = p1;
    player2 = p2;
    board = b;
    player = &player1;
}

void Game::play_game(){
    bool valid_play;
    while (true){
        board.print();
        if(check_end()) break;
        set_player();
        do{
            get_play();
            valid_play = board.mark(player->get_symbol(), play[0], play[1]);
            if(!valid_play) cout << "Enter a valid play!" << endl;
        } while(!valid_play);
        rounds++;
    }
}
 
void Game::set_player(){
    if(rounds%2 == 0) player = &player1;
    else player = &player2;
}
 
void Game::get_play(){
    int p = 0;
    cout << "Enter play for player " << player->get_symbol() << ": (xy) ";
    cin >> p;
    if(p > 0){
        play[0] = (p/10 - 1);
        play[1] = (p%10 - 1);
        if(play[0]>3) play[0] = 2;
        if(play[1]>3) play[1] = 2;
    }
}
 
bool Game::check_end(){
    if(board.check_win(player -> get_symbol())){
        cout << "Player "<< player -> get_symbol() << " wins!" << endl;
        return true;
    }
    if(rounds >= 9){
        cout << "Its a tie!" << endl;
        return true;
    }
    return false;
}