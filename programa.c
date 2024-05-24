#include <stdio.h>

#define CHANCE_NUMBER 3

int main() {
  printf("********************************\n");
  printf("Bem vindo ao jogo da adivinhação\n");
  printf("********************************\n");

  int secretNumber = 42;

  int userInput;
  int chance = 1;
  int score = 1000;

  while(1) {
    printf("Tetativa %d", chance);
    printf("Qual é o número sorteado?\n");

    scanf("%d", &userInput);
    printf("Seu chute foi %d\n", userInput);
    
    if(userInput < 0) {
      printf("O número não pode ser negativo!");
      continue;
    }

    int correct = userInput == secretNumber;
    int bigger = userInput > secretNumber;

    if(correct) {
      printf("Parabéns você acertou!!!\n");
      printf("Sua pontuação foi de %d", score)
      break;
    } else if(bigger) {
        printf("Maior que o número secreto\n");

    } else {
        printf("Menor que o número secreto\n");
      }
      
  }

  
  return 0;
}
