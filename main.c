#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#include "snake.h"
#include <time.h>

#define ROWS 11
#define COLS 25

/* BOARD FUNCTIONS*/

typedef struct {
    int x_pos;
    int y_pos;


} Apple;

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

/*SNAKE FUNCTIONS*/

SnakeNode* create_snake(int y, int x, Direction dir) {

    SnakeNode* snake = malloc(sizeof(SnakeNode));
    //set struct fields
    snake->y=y;
    snake->x=x;
    snake->dir=dir;
    snake->next=NULL;
    return snake;
}

void update_snake(SnakeNode* head, Direction dir){

    //get prior location and direction of snake head
    int prev_x = head->x;
    int prev_y = head->y;
    Direction prev_dir = head->dir;




    switch(dir) {//swich to modify position  bsed on
        case UP:
            head->y--;
            break;
        case DOWN:
            head->y++;
            break;
        case LEFT:
            head->x--;
            break;
        case RIGHT:
            head->x++;
            break;
    }

    head->dir=dir; //set direction of head so we can use it for following body segments






    if (head->next) {

        SnakeNode* current=head->next;







        while (current) {
            //tempt variables so we dont lose components of current node
            int temp_y = current->y;
            int temp_x = current->x;
            Direction temp_dir = current->dir;

            current->y = prev_y;
            current->x = prev_x;
            current->dir=prev_dir;


            prev_x=temp_x;
            prev_y=temp_y;
            prev_dir=temp_dir;
            current=current->next;
        }
    }



}

void mark_snake(char board[ROWS][COLS], SnakeNode* head) { //modify board memory to have current snake in it
    SnakeNode* current = head; //pointer to iterate through snake
    while (current!=NULL) {
        board[current->y][current->x] = '0';
        current = current->next; //move pointer
    }
}

SnakeNode* get_tail(SnakeNode* head) {
    SnakeNode* current = head;
    while (current->next!=NULL) {
        current = current->next;
    }
    return current;
}

void lengthen_snake(SnakeNode* head, int* score) {
    SnakeNode* tail = get_tail(head);
    int modify_x = 0;
    int modify_y = 0;
    switch (tail->dir) { //find
        case UP: modify_y++; break;
        case DOWN: modify_y--; break;
        case LEFT: modify_x++; break;
        case RIGHT: modify_x--; break;
    }
    SnakeNode* new_segment = malloc(sizeof(SnakeNode));
    tail->next = new_segment;
    new_segment->y = tail->y+modify_y;
    new_segment->x = tail->x+modify_x;
    new_segment->dir = tail->dir;
    new_segment->next=NULL;
    (*score)++;


}

Apple create_apple(char board[ROWS][COLS]) {
    Apple apple;
    do { //if the apple spawns on an occupied tile move it
        apple.x_pos=rand()%COLS; //random x pos for apple
        apple.y_pos=rand()%ROWS; //random y pos
    } while (board[apple.y_pos][apple.x_pos]!=' ');

    return apple;
}


int main(void) {
    srand(time(NULL));// set the randomness
    char board[ROWS][COLS];   //board is 2D array
    SnakeNode* snake = create_snake(ROWS/2, COLS/2, LEFT);
    int score = 0;
    int* score_pointer=&score;

    Apple apple = create_apple(board);




    initscr();
    keypad(stdscr, TRUE);   // Enable reading arrow keys


    int running = 1;
    Direction snake_dir = RIGHT;

    while (running) {

        //HANDLE INPUTS
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                snake_dir=UP; break;
            case KEY_DOWN:
                snake_dir=DOWN; break;
            case KEY_LEFT:
                snake_dir=LEFT; break;
            case KEY_RIGHT:
                snake_dir=RIGHT; break;
            case 'q':
                running = 0;break;
            case 'g':
                lengthen_snake(snake, &score); break;

        }

        create_board(board);
        update_snake(snake, snake_dir);
        mark_snake(board, snake);
        board[apple.y_pos][apple.x_pos]='@';
        draw_board(board);

        if (snake->y ==ROWS-1 || snake->y==0 ||snake->x ==COLS-1 || snake->x==0) {
            break;
        }

        if (snake->y == apple.y_pos && snake->x== apple.x_pos ) {
            lengthen_snake(snake, &score);
            apple = create_apple(board);
        }

        napms(100);
        refresh();





    }

    endwin();
    printf("Score: %d\n", score);



return 0;

}