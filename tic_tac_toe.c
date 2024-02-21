#include <stdio.h>

int winCondition(char *arr) {
  int gameOver = 0;

  if (arr[4] != ' ') {
    if ((arr[0] == arr[4] && arr[4] == arr[8]) ||
        (arr[2] == arr[4] && arr[4] == arr[6]) ||
        (arr[1] == arr[4] && arr[4] == arr[7]) ||
        (arr[3] == arr[4] && arr[4] == arr[5])) {
      gameOver = 1;
    }
  } else if (arr[0] != ' ') {
    if ((arr[0] == arr[1] && arr[1] == arr[2]) ||
        (arr[0] == arr[3] && arr[6] == arr[2])) {
      gameOver = 1;
    }
  } else if (arr[8] != ' ') {
    if ((arr[2] == arr[5] && arr[5] == arr[8]) ||
        (arr[6] == arr[7] && arr[7] == arr[8])) {
      gameOver = 1;
    }
  }

  return gameOver;
}

void displayGrid(char *arr) {

  for (int _ = 0; _ <= 100; ++_) {
    puts("\n");
  }

  puts("TIC TAC TOE GAME\n");
  puts("================\n");

  for (int i = 0; i < 9; ++i) {
    printf(" %c ", arr[i] != ' ' ? arr[i] : (char)(i + 49));
    if (i % 3 == 2)
      printf("\n");
  }
}

int main() {

  char grid[9];

  for (int i = 0; i < 9; ++i) {
    grid[i] = ' ';
  }

  int curCell;
  int errMsg = 0;
  int winner = 0;

  for (int i = 0; i < 9; ++i) {
    displayGrid(grid);
    if (errMsg) {
      puts("Invalid cell number try again ");
      errMsg = 0;
    }
    printf("Player %d enter the cell number: ", (i % 2) + 1);

    scanf("%d", &curCell);
    --curCell;

    if (curCell < 0 || curCell > 8 || grid[curCell] != ' ') {
      errMsg = 1;
      --i;
      continue;
    } else {
      grid[curCell] = i % 2 ? 'X' : 'O';
    };

    if (winCondition(grid)) {
      winner = (i % 2) + 1;
      break;
    }
  }

  displayGrid(grid);
  if (winner) {
    printf("Player %d is the winner", winner);
  } else {
    puts("It is a tie");
  }
  return 0;
}
