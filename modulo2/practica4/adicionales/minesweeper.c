#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 8
#define COLS 8
#define MINE 'X'
#define QTY 10

typedef struct
{
  bool is_mine;
  bool visible;
  bool marked;
  int nearby_mines;
} cell;

cell **generate_board();
void place_mine(cell **, int, int);
void set_nearby_mines(cell **, int, int);
void show_board(cell **);
bool validate_input(char *, int *, int *, int *);
void uncover_cell(cell **, int, int);
void show_near(cell **, int, int);
void mark_cell(cell **, int, int, int *);
void check_victory(cell **);

void clear();

int main()
{
  cell **board = generate_board();
  printf("Welcome to minesweeper!\n");
  show_board(board);
  bool first_move = false;
  int mode, flags = 0;
  while (true)
  {
    char input[4];
    printf("Enter a cell and mode (F for flag, S for show): ");
    scanf("%s", input);
    clear();
    int row, col;
    if (!validate_input(input, &mode, &row, &col))
    {
      printf("Invalid input\n");
      show_board(board);
      continue;
    }

    if (!first_move)
    {
      place_mine(board, row, col);
      first_move = true;
      mode = 1;
    }
    if (mode == 0)
      mark_cell(board, row, col, &flags);
    else if (mode == 1)
      uncover_cell(board, row, col);
    if (flags == QTY)
      check_victory(board);
    show_board(board);
  }
}

cell **generate_board()
{
  cell **board = (cell **)calloc(ROWS, sizeof(cell *));
  for (int i = 0; i < ROWS; i++)
  {
    board[i] = (cell *)calloc(COLS, sizeof(cell));
  }
  return board;
}

void show_board(cell **board)
{
  printf("-------------------------------------\n");
  printf("|   | A | B | C | D | E | F | G | H |\n");
  printf("-------------------------------------\n");
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS + 1; j++)
    {
      if (j == 0)
      {
        printf("| %d |", i + 1);
      }
      else if (board[i][j - 1].visible)
      {
        if (board[i][j - 1].is_mine)
        {
          printf(" %c |", MINE);
        }
        else if (board[i][j - 1].nearby_mines == 0)
        {
          printf("   |");
        }
        else if (board[i][j - 1].nearby_mines > 0)
        {
          printf(" %d |", board[i][j - 1].nearby_mines);
        }
      }
      else
      {
        if (board[i][j - 1].marked)
        {
          printf(" M |");
        }
        else
        {
          printf(" ? |");
        }
      }
    }
    printf("\n-------------------------------------");
    printf("\n");
  }
}

void place_mine(cell **board, int frow, int fcol)
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      cell curr = {false, false, false, 0};
      board[i][j] = curr;
    }
  }
  srand(time(NULL));
  for (int i = 0; i < QTY; i++)
  {
    int row = rand() % ROWS;
    int col = rand() % COLS;
    if (!board[row][col].is_mine && !(row == frow && col == fcol))
    {
      board[row][col].is_mine = true;
      set_nearby_mines(board, row, col);
    }
    else
    {
      i--;
    }
  }
}

void set_nearby_mines(cell **board, int row, int col)
{
  for (int i = row - 1; i <= row + 1; i++)
  {
    for (int j = col - 1; j <= col + 1; j++)
    {
      if (!(i == row && j == col) && (i >= 0 && i < ROWS) && (j >= 0 && j < COLS))
        board[i][j].nearby_mines++;
    }
  }
}

void uncover_cell(cell **board, int row, int col)
{
  if (board[row][col].is_mine)
  {
    printf("You lost!");
    exit(0);
  }
  else
  {
    board[row][col].visible = true;
    show_near(board, row, col);
  }
}

void show_near(cell **board, int row, int col)
{
  if (board[row][col].is_mine)
    return;

  if (!board[row][col].visible)
    uncover_cell(board, row, col);
  if (board[row][col].nearby_mines > 0)
    return;
  for (int i = row - 1; i <= row + 1; i++)
  {
    for (int j = col - 1; j <= col + 1; j++)
    {
      if (!(i == row && j == col) && (i >= 0 && i < ROWS) && (j >= 0 && j < COLS) && !board[i][j].visible && !board[i][j].marked)
      {
        show_near(board, i, j);
      }
    }
  }
}

bool validate_input(char *input, int *mode, int *row, int *col)
{
  if (input[0] == 'F' || input[0] == 'f')
  {
    if (input[1] >= 'A' && input[1] <= 'H' && input[2] >= '1' && input[2] <= '8')
    {
      *row = input[2] - '1';
      *col = input[1] - 'A';
      *mode = 0;
      return true;
    }
    else if (input[1] >= 'a' && input[1] <= 'h' && input[2] >= '1' && input[2] <= '8')
    {
      *row = input[2] - '1';
      *col = input[1] - 'a';
      *mode = 0;
      return true;
    }
    else if (input[1] >= '1' && input[1] <= '8' && input[2] >= 'A' && input[2] <= 'H')
    {
      *row = input[1] - '1';
      *col = input[2] - 'A';
      *mode = 0;
      return true;
    }
    else if (input[1] >= '1' && input[1] <= '8' && input[2] >= 'a' && input[2] <= 'h')
    {
      *row = input[1] - '1';
      *col = input[2] - 'a';
      *mode = 0;
      return true;
    }
    else
      return false;
  }
  else if (input[0] == 'S' || input[0] == 's')
  {
    if (input[1] >= 'A' && input[1] <= 'H' && input[2] >= '1' && input[2] <= '8')
    {
      *row = input[2] - '1';
      *col = input[1] - 'A';
      *mode = 1;
      return true;
    }
    else if (input[1] >= 'a' && input[1] <= 'h' && input[2] >= '1' && input[2] <= '8')
    {
      *row = input[2] - '1';
      *col = input[1] - 'a';
      *mode = 1;
      return true;
    }
    else if (input[1] >= '1' && input[1] <= '8' && input[2] >= 'A' && input[2] <= 'H')
    {
      *row = input[1] - '1';
      *col = input[2] - 'A';
      *mode = 1;
      return true;
    }
    else if (input[1] >= '1' && input[1] <= '8' && input[2] >= 'a' && input[2] <= 'h')
    {
      *row = input[1] - '1';
      *col = input[2] - 'a';
      *mode = 1;
      return true;
    }
    else
      return false;
  }
  else
  {
    return false;
  }
}

void mark_cell(cell **board, int row, int col, int *flags)
{
  if (board[row][col].marked)
  {
    board[row][col].marked = false;
    (*flags)--;
  }
  else
  {
    board[row][col].marked = true;
    (*flags)++;
  }
}

void check_victory(cell **board)
{
  int flags = QTY;
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (board[i][j].is_mine && board[i][j].marked)
        flags--;
      if (flags == 0)
      {
        printf("You won!");
        exit(0);
      }
    }
  }
}

void clear()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}