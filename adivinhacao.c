#include <stdio.h>

#define CHANCE_NUMBER 3

int main() {
  printf("********************************\n");
  printf("Bem vindo ao jogo da adivinhação\n");
  printf("********************************\n");

  int secretNumber = 42;

  int value;
  int chance = 1;
  int score = 1000;

  while(1) {
    printf("Tetativa %d\n", chance);
    printf("Qual é o número sorteado?\n");

    scanf("%d", &value);
    printf("Seu chute foi %d\n", value);
    
    if(value < 0) {
      printf("O número não pode ser negativo!");
      continue;
    }

    int correct = value == secretNumber;
    int bigger = value > secretNumber;

    if(correct) {
      printf("Parabéns você acertou!!!\n");
      printf("Sua pontuação foi de %d", score);
      break;
    } else if(bigger) {
        printf("É maior que o número secreto\n");

    } else {
        printf("É menor que o número secreto\n");
    }

    chance ++;
    
    int scoreLose = (value - secretNumber) / 2;
    
    score = score - scoreLose;

  }

  printf("Fim de jogo!\n");
  printf("Você acertou em %d tentativas!\n", chance);
  printf("Total de pontos: %d\n", score);
  
  return 0;
}
