#include "termtris.h"

int main()
{

  // initialize
  init();

  // game loop
  while (gameRunning)
  {
    updateInput();
    gameRunning = update();
    render();

    ticks++; // increment ticks

    usleep(16666); // only run 60 times per second
  }

  free(pieces); // free dynamically allocated memory
  endwin();     // end ncurses
  return 0;
}

// initalize everything
void init()
{

  // init ncurses
  initscr();             // start ncurses
  cbreak();              // disable line buffering
  noecho();              // don't show input on screen
  nodelay(stdscr, TRUE); // no delay on inputs
  nocbreak();            // disable line buffering

  // init board
  for (int y = 0; y < HEIGHT; y++)
  {
    for (int x = 0; x < WIDTH; x++)
    {
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
  srand(time(NULL)); // seed random numbers
  int cur = rand() % 7;
  int next = rand() % 7;

  curPiece = pieces[cur];
  nextPiece = pieces[next];

  render();
  usleep(700000); //Add a pause at the beginning of game
}

/*
* Update user inputs, only set input to 1 on keypress don't allow a key to be held down
*/
void updateInput()
{

  // get user inputs {'A','D','N','M','Q','S'}
  char temp[] = {0, 0, 0, 0, 0, 0};

  // reset inital inputs
  for (int i = 0; i < 6; i++)
  {
    input[i][0] = 0;
  }

  // process inputs
  char c;
  while ((c = getch()) != ERR)
  {

    switch (c)
    {
    case 'a':
      temp[0] = 1;
      if (input[0][1] == 0)
      {
        input[0][0] = 1;
      }
      else
      {
        input[0][0] = 0;
      }
      input[0][1] = 1;
      break;
    case 'd':
      temp[1] = 1;
      if (input[1][1] == 0)
      {
        input[1][0] = 1;
      }
      else
      {
        input[1][0] = 0;
      }
      input[1][1] = 1;
      break;
    case 'n':
      temp[2] = 1;
      if (input[2][1] == 0)
      {
        input[2][0] = 1;
      }
      else
      {
        input[2][0] = 0;
      }
      input[2][1] = 1;
      break;
    case 'm':
      temp[3] = 1;
      if (input[3][1] == 0)
      {
        input[3][0] = 1;
      }
      else
      {
        input[3][0] = 0;
      }
      input[3][1] = 1;
      break;
    case 'q':
      temp[4] = 1;
      if (input[4][1] == 0)
      {
        input[4][0] = 1;
      }
      else
      {
        input[4][0] = 0;
      }
      input[4][1] = 1;
      break;
    case 's':
      temp[5] = 1;
      if (input[5][1] == 0)
      {
        input[5][0] = 1;
      }
      else
      {
        input[5][0] = 0;
      }
      input[5][1] = 1;
      break;
    }
  }

  // reset flag to register key up
  for (int i = 0; i < 6; i++)
  {
    if (temp[i] == 0)
    {
      input[i][1] = 0;
    }
  }
}

int update()
{

  if (input[0][0] == 1 || input[1][0] == 1)
  {
    updatePieceColumn();
  }

  if (input[2][0] == 1 || input[3][0] == 1)
  {
    updatePieceRotation();
  }

  if (ticks > 8)
  {
    updatePieceDown();
    ticks = 0;
  }

  // inputs {'A','D','N','M','Q','S'}
  if (input[4][0] == 1)
  {
    return 0;
  }

  return 1;
}

void updatePieceColumn()
{
  char posX, posY, canLeft = 1, canRight = 1;
  for (int i = 0; i < 4; i++)
  {
    posX = pieceRotations[curPiece.index][curPiece.rot][i][0] + curPiece.col;
    posY = pieceRotations[curPiece.index][curPiece.rot][i][1] + curPiece.row;

    if (posX - 1 < 0 || board[posY][posX - 1] == 'X')
    {
      canLeft = 0;
    }
    if (posX + 1 > 9 || board[posY][posX + 1] == 'X')
    {
      canRight = 0;
    }
  }
  if (input[0][0] == 1 && canLeft == 1)
  {
    curPiece.col--;
    input[0][1] = 1;
  }
  if (input[1][0] == 1 && canRight == 1)
  {
    curPiece.col++;
    input[1][1] = 1;
  }
}

void updatePieceRotation()
{
  char posX, posY, rotCCW, rotCW, canRotCCW = 1, canRotCW = 1;

  rotCW = curPiece.rot - 1;
  rotCCW = curPiece.rot + 1;
  if (rotCCW > 3)
  {
    rotCCW = 0;
  }
  if (rotCW < 0)
  {
    rotCW = 3;
  }

  for (int i = 0; i < 4; i++)
  {

    posX = pieceRotations[curPiece.index][rotCCW][i][0] + curPiece.col;
    posY = pieceRotations[curPiece.index][rotCCW][i][1] + curPiece.row;
    if (posX < 0 || posX > 9 || posY < 0 || posY > 19 || board[posY][posX] == 'X')
    {
      canRotCCW = 0;
    }

    posX = pieceRotations[curPiece.index][rotCW][i][0] + curPiece.col;
    posY = pieceRotations[curPiece.index][rotCW][i][1] + curPiece.row;
    if (posX < 0 || posX > 9 || posY < 0 || posY > 19 || board[posY][posX] == 'X')
    {
      canRotCW = 0;
    }
  }

  if (input[2][0] == 1 && canRotCCW == 1)
  {
    curPiece.rot = rotCCW;
    input[2][1] = 1;
  }

  if (input[3][0] == 1 && canRotCW == 1)
  {
    curPiece.rot = rotCW;
    input[3][1] = 1;
  }
}

void updatePieceDown()
{

  char canDrop = 1;
  char posX, posY;
  for (int i = 0; i < 4; i++)
  {
    posX = pieceRotations[curPiece.index][curPiece.rot][i][0] + curPiece.col;
    posY = pieceRotations[curPiece.index][curPiece.rot][i][1] + curPiece.row;
    if (board[posY + 1][posX] == 'X' || posY + 1 > 19)
    {
      if (posY == 0)
      {
        input[4][0] = 1;
      }
      canDrop = 0;
      placePiece();
      break;
    }
  }
  if (canDrop == 1)
  {
    curPiece.row++;
  }
}

void placePiece()
{

  char posX, posY;
  for (int i = 0; i < 4; i++)
  {
    posX = pieceRotations[curPiece.index][curPiece.rot][i][0] + curPiece.col;
    posY = pieceRotations[curPiece.index][curPiece.rot][i][1] + curPiece.row;
    board[posY][posX] = 'X';
  }
  curPiece = nextPiece;
  int next = rand() % 7;
  nextPiece = pieces[next];

  checkForLineClear();
}

// doesn't work for multiple lines
void checkForLineClear()
{

  char canClear;
  for (int y = 19; y >= 0; y--)
  {

    canClear = 1;
    for (int x = 0; x < 10; x++)
    {
      if (board[y][x] != 'X')
      {
        canClear = 0;
      }
    }

    if (canClear == 1)
    {
      clearLine(y);
      y++;
    }
  }
}

void clearLine(int row)
{
  for (int y = row; y >= 1; y--)
  {
    for (int x = 0; x < 10; x++)
    {
      board[y][x] = board[y - 1][x];
    }
  }
  for (int i = 0; i < 10; i++)
  {
    board[0][i] = ' ';
  }
}

void render()
{

  int bStartX, bStartY;

  bStartX = COLS / 2 - 6;
  bStartY = LINES / 2 - 11;

  // draw board
  for (int y = 0; y < HEIGHT; y++)
  {
    for (int x = 0; x < WIDTH; x++)
    {
      mvaddch(bStartY + y, bStartX + x, board[y][x]);
    }
  }

  // draw current Piece
  char posX, posY;
  for (int i = 0; i < 4; i++)
  {
    posX = pieceRotations[curPiece.index][curPiece.rot][i][0] + curPiece.col;
    posY = pieceRotations[curPiece.index][curPiece.rot][i][1] + curPiece.row;
    mvaddch(bStartY + posY, bStartX + posX, 'X');
  }

  // draw border
  for (int y = 0; y < 19; y++)
  {
    mvaddch(bStartY + 1 + y, bStartX - 1, '|');
    mvaddch(bStartY + 1 + y, bStartX + 10, '|');
  }
  for (int x = 0; x < 12; x++)
  {
    mvaddch(bStartY, bStartX - 1 + x, '-');
    mvaddch(bStartY + 20, bStartX - 1 + x, '-');
  }

  int nStartX, nStartY;

  nStartX = COLS / 2 + 7;
  nStartY = LINES / 2 - 1;

  // clear next Piece area
  for (int y = nStartY; y < nStartY + 5; y++)
  {
    for (int x = nStartX; x < nStartX + 5; x++)
    {
      mvaddch(y, x, ' ');
    }
  }

  // next text
  mvprintw(nStartY - 2, nStartX, "next \n");

  // draw next Piece
  for (int i = 0; i < 4; i++)
  {
    posX = pieceRotations[nextPiece.index][0][i][0] - 3;
    posY = pieceRotations[nextPiece.index][0][i][1];
    mvaddch(nStartY + posY, nStartX + posX, 'X');
  }

  // draw next Piece border
  for (int i = 0; i < 3; i++)
  {
    mvaddch(nStartY + i, nStartX - 1, '|');
    mvaddch(nStartY + i, nStartX + 5, '|');
  }
  for (int i = 0; i < 7; i++)
  {
    mvaddch(nStartY - 1, nStartX - 1 + i, '-');
    mvaddch(nStartY + 3, nStartX - 1 + i, '-');
  }

  // print it onto the real screen
  refresh();
}
