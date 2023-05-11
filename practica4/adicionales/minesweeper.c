#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8
#define MINE 'X'
#define QTY 5

typedef struct
{
  bool is_mine;
  bool visible;
  bool marked;
  int nearby_mines;
} cell;

cell **generate_board();
void place_mine(cell **);
void set_nearby_mines(cell **, int, int);
void show_board(cell **);
bool validate_input(char *, int *, int *);
void uncover_cell(cell **, int, int);
void show_near(cell **, int, int);
void mark_cell();
void check_victory();

int main()
{
  cell **board = generate_board();
  printf("Welcome to minesweeper!\n");
  show_board(board);
  bool first_move = false;
  while (true)
  {
    char input[3];
    printf("Enter a cell: ");
    scanf("%s", input);
    int row, col;
    if (!validate_input(input, &row, &col))
    {
      printf("Invalid input\n");
      continue;
    }
    if (!first_move)
    {
      place_mine(board);
      first_move = true;
    }
    uncover_cell(board, row, col);
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

void place_mine(cell **board)
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      cell curr = {false, false, false, 0};
      board[i][j] = curr;
    }
  }

  for (int i = 0; i < QTY; i++)
  {
    int row = rand() % ROWS;
    int col = rand() % COLS;
    if (!board[row][col].is_mine)
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

bool validate_input(char *input, int *row, int *col)
{
  if (((input[0] < 'A' || input[0] > 'H') && (input[1] < '1' || input[1] > '8')) && ((input[0] < '1' || input[0] > '8') && (input[1] < 'A' || input[1] > 'H')) && (input[0] < 'a' || input[0] > 'h') && (input[1] < 'a' || input[1] > 'h'))
    return false;

  if (input[0] >= 'A' && input[0] <= 'H')
  {
    *col = input[0] - 'A';
    *row = input[1] - '1';
  }
  else if (input[0] >= 'a' && input[0] <= 'h')
  {
    *col = input[0] - 'a';
    *row = input[1] - '1';
  }
  else if (input[1] >= 'A' && input[1] <= 'H')
  {
    *col = input[1] - 'A';
    *row = input[0] - '1';
  }
  else
  {
    *col = input[1] - 'a';
    *row = input[0] - '1';
  }
  printf("%d %d\n", *row, *col);
  return true;
}