#include <stdio.h>
#define N_TENTATIVAS 5

// tudo que começa com # se chama diretiva
// #define possibilita definir uma constante

int main() {
    // imprime cabeçalho do nosso jogo
    printf("*********************\n");
    printf("* bem vindo ao jogo *\n");
    printf("*********************\n");

    // declarando uma variavel int
    int numeroSecreto = 42;
    int ganhou = 0;
    int tentativasUsuario = 0;
    double pontos = 1000;
    
    for (int i = 1; i <= N_TENTATIVAS; i++) {
        printf("Tentativa %d de %d\n", i, N_TENTATIVAS);
        tentativasUsuario = i;

        int chute;
        scanf("%d", &chute);

        if (chute < 0) {
            i--; // garante que nao vai roubar uma tentativa do for
            printf("Você não pode chutar números negativos\n");
            continue;
        }

        // em "c" os booleanos são 0 e 1; --> 0 false --> 1 true
        int acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;
        int menor = chute < numeroSecreto;
        
        if (acertou) {
            ganhou = 1;
            // i = 4;
            break;
        } 
            
        else if (maior) {
            printf("seu chute foi maior que o numero secreto.\n");
        } 
        
        else if (menor) {
            printf("seu chute foi menor que o numero secreto.\n");
        }

        double pontosPerdidos = (chute - numeroSecreto) / 2.0;
        pontos = pontos - pontosPerdidos;
    }

    if (ganhou) {
        printf("Parabéns, voce acertou!\nTotal tentativa(s)=%d\n", tentativasUsuario);
    } else {
        printf("Poxa, voce perdeu!\nTotal tentativa(s)=%d\n", tentativasUsuario);
    }

    printf("Pontos! %.2f\n", pontos);

    printf("Fim de Jogo!\n");
    
    return 0;
}