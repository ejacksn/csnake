//
// Created by ejacksn on 6/10/25.
//

#ifndef SNAKE_H
#define SNAKE_H

typedef enum { //enum to handle direction of travel for each snake segment
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct SnakeNode{ //each snake segment is a node struct
    int x,y; //integers to represent node postition
    Direction dir; //current direction of node
    struct SnakeNode* next;

} SnakeNode;

SnakeNode* create_snake(int y, int x, Direction dir); //importing file must have function to create snake head

void update_snake(SnakeNode* head, Direction dir); //importing file needs fucntion to change direction of head and following nodes accordingly



void lengthen_snake(SnakeNode* head); //implement funciton to grow snake
void free_snake(SnakeNode* head);


#endif //SNAKE_H
