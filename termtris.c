#include "termtris.h"

int main() {

    // initialize
    init();
    
    // game loop
    while(gameRunning) {
        updateInput();
        gameRunning = update();
        render();
    }

    endwin();               // end ncurses
    return 0;
}

// initalize everything
void init() {
    
    // init ncurses
    initscr();              // start ncurses
    cbreak();               // disable line buffering
    noecho();               // don't show input on screen
    nodelay(stdscr, TRUE);  // no delay on inputs
    nocbreak();             // disable line buffering

    // init board
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            board[y][x] = ' ';
        }
    }

    

    // temp
    board[0][0] = 'x';
    board[19][9] = 'x';
    board[19][0] = 'x';
    board[0][9] = 'x';

}

void updateInput() {

    // get user inputs {'A','D','N','M','Q','S'}
    char c;
    while((c = getch()) != ERR) {
        switch(c) {
            case 'a':
                input[0] = 1;
            case 'd':
                input[1] = 1;
            case 'n':
                input[2] = 1;
            case 'm':
                input[3] = 1;
            case 'q':
                input[4] = 1;
            case 's':
                input[5] = 1;
        }
    }
}

int update() {
    return 1;
}

void render() {

    // draw board
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            mvaddch(y,x,board[y][x]);
        }
    }

    // print it onto the real screen
    refresh();   
}