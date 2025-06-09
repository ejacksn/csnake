#include <stdio.h>
#include <ncurses.h>

int main(void) {
    initscr();
    printw("\nThis is a test\n   Press any key to exitl.");
    refresh();
    getch();
    endwin();

}