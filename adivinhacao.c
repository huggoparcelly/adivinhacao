#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  printf("********************************\n");
  printf("Bem vindo ao jogo da adivinhação\n");
  printf("********************************\n");

  int secounds = time(0);
  srand(secounds);
  int secretNumber = rand() % 100;

  int value;
  int chance = 1;
  double score = 1000;

  int correct = 0;

  int level;

  printf("Qual nível de dificuldade?\n");
  printf("(1) Fácil (2) Médio (3) Difícil\n\n");
  printf("Escolha: ");
  scanf("%d", &level);

  int chanceNumber;
  switch (level) {
    case 1:
      chanceNumber = 20;
      break;
    case 2:
      chanceNumber = 15;
    default:
      chanceNumber = 5;
      break;
  }

  for (int i = 1; i <= chanceNumber; i++)
  {
    printf("Tetativa %d\n", chance);
    printf("Qual é o número sorteado?\n");

    scanf("%d", &value);
    printf("Seu chute foi %d\n", value);

    if (value < 0)
    {
      printf("O número não pode ser negativo!");
      continue;
    }

    int correct = value == secretNumber;
    int bigger = value > secretNumber;

    if (correct)
    {
      break;
    }
    else if (bigger)
    {
      printf("É maior que o número secreto\n");
    }
    else
    {
      printf("É menor que o número secreto\n");
    }

    chance++;

    double scoreLose = (value - secretNumber) / (double)2;

    if (scoreLose < 0)
    {
      scoreLose = scoreLose * -1;
    }

    score = score - scoreLose;
  }

  if (correct)
  {
    printf("Parabéns você acertou!!!\n");
    printf("Sua pontuação foi de %f", score);
  }
  else
  {
    printf("Você perdeu\n");
  }

  printf("Fim de jogo!\n");
  printf("Você acertou em %d tentativas!\n", chance);
  printf("Total de pontos: %.2f\n", score);

  return 0;
}
