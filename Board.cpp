#include <iostream>
#include "Board.h"
using namespace std;

Board::Board(){
    clear();
}
void Board::print(){
    system("clear");
    for(int i=0; i<3; i++){
        cout << endl;
        for(int j=0; j<3; j++){
            if(j!=2) cout << board[i][j] << '|';
            else cout << board[i][j] ;
        }
        if(i!=2)cout << endl << "------";
        else cout << endl;
    }
    cout << endl;
}

bool Board::mark(char c, int x, int y){
    if(!(x>=3 || y>=3 || x<0 || y<0)){
        if(board[x][y] != ' ') return false;
        board[x][y] = c;
        return true;
    }
    return false;
}

void Board::clear(){
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = ' ';
}

bool Board::check_win(char c){
    if(
        check_columns(c) ||
        check_rows(c) ||
        check_diags(c)
    ) return true;
    return false;
}

bool Board::check_column(char c, int column){
    bool all {true};
    for(int i=0; i<3; i++){
        if(board[i][column]!=c) all=false;
    }
    return all;
}

bool Board::check_columns(char c){
    bool any {false};
    for(int j=0; j<3; j++){
        if(check_column(c, j)) any=true;
    }
    return any;
}

bool Board::check_row(char c, int row){
    bool all {true};
    for(int i=0; i<3; i++){
        if(board[row][i]!=c) all=false;
    }
    return all;
}

bool Board::check_rows(char c){
    bool any {false};
    for(int j=0; j<3; j++){
        if(check_row(c, j)) any=true;
    }
    return any;
}

bool Board::check_diags(char c){
    bool all = true;
    for(int i=0; i<3; i++){
        if(board[i][i] != c) all=false;
    }
    if(all) return true;
    all = true;
    for(int i=0; i<3; i++){
        if(board[i][2 - i] != c) all=false;
    }
    return all;
}
