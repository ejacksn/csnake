#include <stdio.h>
#include <ncurses.h>

#define ROWS 11
#define COLS 25

void create_board(char board[ROWS][COLS]){
    int x,y =  0;
    for (y=0; y<ROWS; y++){

        for (x=0; x<COLS; x++){

            if (x==0 || x==COLS-1 || y==0 || y==ROWS-1){
                board[y][x] = 'X';
            }
            else{
                board[y][x] = ' ';
            }
}

    }


}

void draw_board(char board[ROWS][COLS]){
    int x,y;
    for (y=0; y<ROWS; y++){

        for (x=0; x<COLS; x++){

            mvaddch(y,x,board[y][x]);
}

    }


}


int main(void) {

    char board[ROWS][COLS];   //board is 2D array



    initscr();
    create_board(board);
    draw_board(board);
    refresh();
    getch();
    endwin();

return 0;

}