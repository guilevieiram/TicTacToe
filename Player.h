#ifndef PLAYER_H
#define PLAYER_H

class Player{
    public:
        Player() = default;
        Player(char sym);
        char get_symbol();
    private: 
        char symbol{'X'};
};

#endif