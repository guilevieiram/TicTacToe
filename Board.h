#ifndef BOARD_H
#define BOARD_H

class Board{
    public:
        Board();
        void print();
        bool mark(char c, int x, int y);
        void clear();
        bool check_win(char c);

    private:
        char board [3][3] {};
        bool check_column(char c, int column);
        bool check_columns(char c);
        bool check_row(char c, int row);
        bool check_rows(char c);
        bool check_diags(char c);
};

#endif