#include "termtris.h"

int main() {

    // initialize
    init();
    
    // game loop
    while(gameRunning) {
        gameRunning = updateInput();
        update();
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

int updateInput() {

    // get user inputs
    char c;
    while((c = getch()) != ERR){
        if(c == 'q'){
            return 0;
        }
    }

    return 1;
}

void update() {

}

void render() {

    // draw board
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            mvaddch(y,x,board[y][x]);
        }
    }

    refresh();              // print it onto the real screen

    getch();
}