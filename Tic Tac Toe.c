#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*16) Faça um programa para jogar o jogo da velha. Ao final imprima o resultado do jogo e pergunte 
se deseja jogar novamente.*/

int main(){
  int victory, playersWins = 0, cpuWins = 0, moves;
  char board[3][3];
  char option;
  
  printf("Tic Tac Toe\n\n");

  do{
    //inicializando as variáveis
    victory = 0;
    moves = 0;

    //inicializando o tabuleiro
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        board[i][j] = ' ';
    
    //impressão do tabuleiro
    printf("Board\n\n");
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        printf(" %c ", board[i][j]);
        if(j < 2)
          printf("|");
      }
      if(i < 2)   
        printf("\n-----------");

      printf("\n");
    }

    do{
      //entrada das coordenadas pelo usuário
      int xCoord, yCoord;
      do{
        printf("\nYour turn. Insert a x coordinate (from 0 - 2) and a y coordinate (from 0 - 2): ");
        scanf("%d %d", &xCoord, &yCoord);
      }while(xCoord < 0 || xCoord > 2 || yCoord < 0 || yCoord > 2 || board[xCoord][yCoord] != ' ');
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          if(xCoord == i && yCoord == j)
            board[xCoord][yCoord] = 'X';

      moves++;
      printf("%d ", moves);

      //jogada da CPU
      int xCoord_cpu, yCoord_cpu;
      srand(time(NULL));
      do{
        xCoord_cpu = rand() % 3;
        yCoord_cpu = rand() % 3;
      }while(board[xCoord_cpu][yCoord_cpu] != ' ' || board[xCoord_cpu][yCoord_cpu] == 'X');
      board[xCoord_cpu][yCoord_cpu] = 'O';

      moves++;
      printf("%d ", moves);

      //impressão do jogo com a jogada de ambos
      printf("\n");
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          printf(" %c ", board[i][j]);
            if(j < 2)
              printf("|");
        }
        if(i < 2)   
          printf("\n-----------");

        printf("\n");
      }

      //verificação para linha para o jogador
      if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' ||
         board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' ||
         board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){
        victory = 1;
        playersWins++;
        printf("\nPlayer wins\n");
      }

      //verificação para coluna para o jogador
      if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' ||
         board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' ||
         board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
        victory = 1;
        playersWins++;
        printf("\nPlayer wins\n");
      }

      //verificação da diagonnal principal para o jogador
      if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
        victory = 1;
        playersWins++;
        printf("\nPlayer wins\n");
      }

      //verificação da diagonal secundária para o jogador
      if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
        victory = 1;
        playersWins++;
        printf("\nPlayer wins\n");
      }

      //verificação para linha para a CPU
      if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' ||
         board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' ||
         board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
        victory = 1;
        cpuWins++;
        printf("\nCPU wins\n");
      }

      //verificação para coluna para a CPU
      if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' ||
         board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' ||
         board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
        victory = 1;
        cpuWins++;
        printf("\nPlayer wins\n");
      }

      //verificação da diagonnal principal para a CPU
      if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
        victory = 1;
        cpuWins++;
        printf("\nCPU wins\n");
      }

      //verificação da diagonal secundária para a CPU
      if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
        victory = 1;
        cpuWins++;
        printf("\nCPU wins\n");
      }

    }while(victory < 1 && moves < 9);

    if(victory == 0)
      printf("Draw\n");

    printf("\nScore\nPlayer: %d\tCPU: %d\n", playersWins, cpuWins);

    getchar();
    printf("\nWanna play again? (y/n) ");
    scanf("%c", &option);

    printf("\n");
  }while(option == 'y' && option != 'n');

  return 0;
}