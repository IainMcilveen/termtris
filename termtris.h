// includes
#include <ncurses.h> // includes stdio.h
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

// Define constants
#define WIDTH   10
#define HEIGHT  20

// Define structs
typedef struct{
    int index, rot, row, col;
}Piece;

// Define Variables
int gameRunning = 1;
int ticks = 100;
char board[HEIGHT][WIDTH];
char input[6][2] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};   //{'A','D','N','M','Q','S'} 
char pieceRotations[7][4][4][2] = {
  {
    {{4,0},{5,0},{5,1},{6,0}},
    {{5,-1},{5,0},{5,1},{6,0}},
    {{4,0},{5,0},{5,-1},{6,0}},
    {{4,0},{5,-1},{5,0},{5,1}}
  },
  {
    {{6,1},{4,0},{5,0},{6,0}},
    {{4,1},{4,0},{4,-1},{5,-1}},
    {{4,-1},{4,0},{5,0},{6,0}},
    {{4,1},{5,0},{5,-1},{5,1}}
  },
  {
    {{5,1},{6,1},{4,0},{5,0}},
    {{4,1},{4,0},{5,0},{5,-1}},
    {{5,1},{6,1},{4,0},{5,0}},
    {{4,1},{4,0},{5,0},{5,-1}}
  },
  {
    {{4,1},{5,1},{4,0},{5,0}},
    {{4,1},{5,1},{4,0},{5,0}},
    {{4,1},{5,1},{4,0},{5,0}},
    {{4,1},{5,1},{4,0},{5,0}}
  },
  {
    {{4,1},{5,1},{5,0},{6,0}},
    {{4,-1},{4,0},{5,0},{5,1}},
    {{4,1},{5,1},{5,0},{6,0}},
    {{4,-1},{4,0},{5,0},{5,1}}
  },
  {
    {{4,1},{4,0},{5,0},{6,0}},
    {{4,-1},{4,0},{4,1},{5,1}},
    {{4,1},{5,1},{6,1},{6,0}},
    {{4,-1},{5,-1},{5,0},{5,1}}
  },
  {
    {{3,0},{4,0},{5,0},{6,0}},
    {{5,-2},{5,-1},{5,0},{5,1}},
    {{3,0},{4,0},{5,0},{6,0}},
    {{5,-2},{5,-1},{5,0},{5,1}}
  }
};

// Create pieces
Piece t = {
  .row = 1,
  .col = 0,
  .index = 0,
  .rot = 0
};
Piece j = {
  .row = 1,
  .col = 0,
  .index = 1,
  .rot = 0
};
Piece z = {
  .row = 1,
  .col = 0,
  .index = 2,
  .rot = 0
};
Piece o = {
  .row = 1,
  .col = 0,
  .index = 3,
  .rot = 0
};
Piece s = {
  .row = 1,
  .col = 0,
  .index = 4,
  .rot = 0
};
Piece l = {
  .row = 1,
  .col = 0,
  .index = 5,
  .rot = 0
};
Piece i = {
  .row = 1,
  .col = 0,
  .index = 6,
  .rot = 0
};

Piece* pieces;
Piece nextPiece;
Piece curPiece;

// Define Function
void init();
void updateInput();
int update();
void render();
void updatePieceColumn();
void updatePieceDown();
void updatePieceRotation();
void placePiece();
void checkForLineClear();
void clearLine(char);