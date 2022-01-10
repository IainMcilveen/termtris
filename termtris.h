// includes
#include <ncurses.h> // includes stdio.h

// define constants
#define WIDTH   10
#define HEIGHT  20

// Define Variables
int gameRunning = 1;
char board[HEIGHT][WIDTH];
char input[] = {' ',' ',' ',' ',' ',' '};   //{'A','D','N','M','Q','S'} S will be unused for now

// Define Function
void init();
int updateInput();
void update();
void render();