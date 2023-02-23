#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRIES_EASY 20
#define TRIES_MEDIUM 10
#define TRIES_HARD 5

// tudo que começa com # se chama diretiva
// #define possibilita definir uma constante

int main() {
    // imprime cabeçalho do nosso jogo
    printf("*********************\n");
    printf("* bem vindo ao jogo *\n");
    printf("*********************\n");

    printf("* Escolha um nivel de difículdade: 1 fácil - 2 médio - 3 difícil *\n");
    int level;
    printf("level: ");
    scanf("%d", &level);
    printf("\n");

    int tries;
    switch (tries) {
    case 1:
        tries = TRIES_EASY;
        break;
    case 2:
        tries = TRIES_MEDIUM;
        break;
    case 3:
        tries = TRIES_HARD;
        break;   
    default:
        tries = TRIES_EASY;
        break;
    }


    int s = time(0);
    srand(s);
    int randomNumber = rand();

    // declarando uma variavel int
    int secretNumber = randomNumber % 100;
    int winner = 0;
    int userTries = 0;
    double score = 1000;

    
   
    for (int i = 1; i <= tries; i++) {
        printf("Tentativa %d de %d\n", i, tries);
        userTries = i;

        int userGuess;
        scanf("%d", &userGuess);

        if (userGuess < 0) {
            i--; // garante que nao vai roubar uma tentativa do for
            printf("Você não pode chutar números negativos\n");
            continue;
        }

        // em "c" os booleanos são 0 e 1; --> 0 false --> 1 true
        int acertou = (userGuess == secretNumber);
        int maior = userGuess > secretNumber;
        int menor = userGuess < secretNumber;
        
        if (acertou) {
            winner = 1;
            // i = 4;
            break;
        } else if (maior) {
            printf("seu chute foi maior que o numero secreto.\n");
        } else if (menor) {
            printf("seu chute foi menor que o numero secreto.\n");
        }

        double pontosPerdidos = abs(userGuess);
        score = score - pontosPerdidos;
    }

    if (winner) {
        printf("Parabéns, voce acertou!\nTotal tentativa(s)=%d\n", userTries);
    } else {
        printf("Poxa, voce perdeu!\nTotal tentativa(s)=%d\n", userTries);
        printf("O numero secreto era %d\n", secretNumber);
    }

    printf("Pontos! %.2f\n", score);
    printf("Fim de Jogo!\n");
    
    return 0;
}