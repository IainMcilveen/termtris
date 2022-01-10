#include <stdio.h>
#include <ncurses.h>
#include "termtris.h"

int main() {

    initscr();              // start ncurses
    printw("Hello World");  // print hello world
    refresh();              // print it onto the real screen
    getch();                // wait for user input
    endwin();               // end ncurses
    
    // game loop
    while(gameRunning) {
        updateInput();
        update();
        render();
        gameRunning = 0;
    }

    return 0;
}

void updateInput() {
    printf("Inputs \n");
}

void update() {
    printf("update \n");
}

void render() {
    printf("Render \n");
}