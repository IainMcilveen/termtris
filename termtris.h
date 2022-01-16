// includes
#include <ncurses.h> // includes stdio.h
#include <stdlib.h>
#include <time.h>

// Define constants
#define WIDTH   10
#define HEIGHT  20

// Define structs
typedef struct{
    char rots[4][4][2];
    int row, col;
}Piece;

// Define Variables
int gameRunning = 1;
char board[HEIGHT][WIDTH];
char input[] = {' ',' ',' ',' ',' ',' '};   //{'A','D','N','M','Q','S'} 

// Create pieces
Piece t = {
    .row = -1,
    .col = 0,
    .rots = {
        {{4,0},{5,0},{5,1},{6,0}},
        {{5,-1},{5,0},{5,1},{6,0}},
        {{4,0},{5,0},{5,-1},{6,0}},
        {{4,0},{5,-1},{5,0},{5,1}}
    }
};
Piece j = {
    .row = -1,
    .col = 0,
    .rots = {
        {{6,1},{4,0},{5,0},{6,0}},
        {{4,1},{4,0},{4,-1},{5,-1}},
        {{4,-1},{4,0},{5,0},{6,0}},
        {{4,1},{5,0},{5,-1},{5,1}}
    }
};
Piece z = {
    .row = -1,
    .col = 0,
    .rots = {
        {{5,1},{6,1},{4,0},{5,0}},
        {{4,1},{4,0},{5,0},{5,-1}},
        {{5,1},{6,1},{4,0},{5,0}},
        {{4,1},{4,0},{5,0},{5,-1}}
    }
};
Piece o = {
    .row = -1,
    .col = 0,
    .rots = {
        {{4,1},{5,1},{4,0},{5,0}},
        {{4,1},{5,1},{4,0},{5,0}},
        {{4,1},{5,1},{4,0},{5,0}},
        {{4,1},{5,1},{4,0},{5,0}}
    }
};
Piece s = {
    .row = -1,
    .col = 0,
    .rots = {
        {{4,1},{5,1},{5,0},{6,0}},
        {{4,-1},{4,0},{5,0},{5,1}},
        {{4,1},{5,1},{5,0},{6,0}},
        {{4,-1},{4,0},{5,0},{5,1}}
    }
};
Piece l = {
    .row = -1,
    .col = 0,
    .rots = {
        {{4,1},{4,0},{5,0},{6,0}},
        {{4,-1},{4,0},{4,1},{5,1}},
        {{4,1},{5,1},{6,1},{6,0}},
        {{4,-1},{5,-1},{5,0},{5,1}}
    }
};
Piece i = {
    .row = -1,
    .col = 0,
    .rots = {
        {{3,0},{4,0},{5,0},{6,0}},
        {{5,-2},{5,-1},{5,0},{5,1}},
        {{3,0},{4,0},{5,0},{6,0}},
        {{5,-2},{5,-1},{5,0},{5,1}}
    }
};

Piece* pieces;
Piece nextPiece;
Piece curPiece;

// Define Function
void init();
void updateInput();
int update();
void render();