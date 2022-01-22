#include "termtris.h"

int main() {

  // initialize
  init();
  
  // game loop
  while(gameRunning) {
    updateInput();
    gameRunning = update();
    render();

    sleep(1/60);          // only run 60 times per second
  }

  free(pieces);           // free dynamically allocated memory
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

  // allocate pieces array and add pieces
  pieces = malloc(sizeof(Piece) * 7);
  pieces[0] = t;
  pieces[1] = j;
  pieces[2] = z;
  pieces[3] = o;
  pieces[4] = s;
  pieces[5] = l;
  pieces[6] = i;


  // randomly set cur and next piece
  srand(time(NULL));  // seed random numbers
  int cur = rand() % 7;
  int next = rand() % 7;
  curPiece.col = pieces[cur].col;
  curPiece.row = pieces[cur].row;
  curPiece.rots = pieces[cur].rots;

}

/*
* Update user inputs, only set input to 1 on keypress don't allow a key to be held down
*/
void updateInput() {

  // get user inputs {'A','D','N','M','Q','S'}
  char temp[] = {0,0,0,0,0,0};

  // process inputs
  char c;
  while((c = getch()) != ERR) {
  
    switch(c) {
      case 'a':
        temp[0] = 1;
        if(input[0][1] == 0){
          input[0][0] = 1;
        } else {
          input[0][0] = 0;
        }
        input[0][1] = 1;
        break;
      case 'd':
        temp[1] = 1;
        if(input[1][1] == 0){
          input[1][0] = 1;
        } else {
          input[1][0] = 0;
        }
        input[1][1] = 1;
        break;
      case 'n':
        temp[2] = 1;
        if(input[2][1] == 0){
          input[2][0] = 1;
        } else {
          input[2][0] = 0;
        }
        input[2][1] = 1;
        break;
      case 'm':
        temp[3] = 1;
        if(input[3][1] == 0){
          input[3][0] = 1;
        } else {
          input[3][0] = 0;
        }
        input[3][1] = 1;
        break;
      case 'q':
        temp[4] = 1;
        if(input[4][1] == 0){
          input[4][0] = 1;
        } else {
          input[4][0] = 0;
        }
        input[4][1] = 1;
        break;
      case 's':
        temp[5] = 1;
        if(input[5][1] == 0){
          input[5][0] = 1;
        } else {
          input[5][0] = 0;
        }
        input[5][1] = 1;
        break;
    }

  }

  // reset flag to register key up
  for(int i = 0; i < 6; i++){
    if(temp[i] == 0){
      input[i][1] = 0;
    }
  }

}

int update() {

  //inputs {'A','D','N','M','Q','S'}
  if(input[4][0] == 1) {
    return 0;
  }

  if((input[0][0] == 1 && input[0][1] == 1) || (input[1][0] == 1 && input[1][1] == 1)){
    updatePieceColumn();
  }


  return 1;
}

void updatePieceColumn() {

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