/*
FUNÇÃO DO STATUS DO JOGO:
	1 = PARA O JOGO TERMINA COM RESULTADO
   -1 = PARA O JOGO ESTÁ EM PROGRESSO
	O = EMPATE/FIM DAS JOGADAS
*/
#include <stdio.h>// Inclui biblioteca de entrada e saida de dados.
#include <conio.h>// Inclui biblioteca para pausar o terminal ao fim do programa usando "getch();".

char ponto[10] = { 'o', '1', '2', '3',     // Vetor que informa o local onde o X e o O serão inseridos
                    '4', '5', '6',
                    '7', '8', '9' };

int checkwin();
void quadro();  // Procedimento do quadro do jogo da velha (final)
int main(){
    int jogador = 1, i, jogada;  //Variáveis

    char area;
    do{
        quadro();
        jogador = (jogador % 2) ? 1 : 2;

        printf("JOGADOR %d, FA%cA SUA JOGADA:  ", jogador, 128);
        scanf("%d", &jogada);

        area = (jogador == 1) ? 'X' : 'O';

        if (jogada == 1 && ponto[1] == '1')
            ponto[1] = area;                   // Ponto = X ou O

        else if (jogada == 2 && ponto[2] == '2')
            ponto[2] = area;

        else if (jogada == 3 && ponto[3] == '3')
            ponto[3] = area;

        else if (jogada == 4 && ponto[4] == '4')
            ponto[4] = area;

        else if (jogada == 5 && ponto[5] == '5')
            ponto[5] = area;

        else if (jogada == 6 && ponto[6] == '6')
            ponto[6] = area;

        else if (jogada == 7 && ponto[7] == '7')
            ponto[7] = area;

        else if (jogada == 8 && ponto[8] == '8')
            ponto[8] = area;

        else if (jogada == 9 && ponto[9] == '9')
            ponto[9] = area;

        else{
            printf("MOVIMENTO INV%cLIDO", 181);  // Se jogador digitar (x)<1 ou (x)>10
            jogador--;
            getch();
        }
        i = checkwin();       //volta na linha 22, mas guarda as informações obtidas até agora
        jogador++;
    }
    while (i ==  - 1);
    quadro();

    if (i == 1)
        printf("JOGADOR %d VENCEU", --jogador);
    else
        printf("EMPATE");
    getch();
    return (0);
}
int checkwin(){
    if (ponto[1] == ponto[2] && ponto[2] == ponto[3])
        return (1);

    else if (ponto[4] == ponto[5] && ponto[5] == ponto[6])
        return (1);

    else if (ponto[7] == ponto[8] && ponto[8] == ponto[9])
        return (1);

    else if (ponto[1] == ponto[4] && ponto[4] == ponto[7])
        return (1);

    else if (ponto[2] == ponto[5] && ponto[5] == ponto[8])
        return (1);

    else if (ponto[3] == ponto[6] && ponto[6] == ponto[9])
        return (1);

    else if (ponto[1] == ponto[5] && ponto[5] == ponto[9])
        return (1);

    else if (ponto[3] == ponto[5] && ponto[5] == ponto[7])
        return (1);

    else if (ponto[1] != '1' &&
             ponto[2] != '2' &&
             ponto[3] != '3' &&
             ponto[4] != '4' &&
             ponto[5] != '5' &&
             ponto[6] != '6' &&
             ponto[7] != '7' &&
             ponto[8] != '8' &&
             ponto[9] != '9')

        return (0);
    else
        return  (-1);
}
void quadro(){
    system("cls");
    printf("\n\n\tJOGO DA VELHA\n\n");
    printf("JOGADOR 1 (X)  -  JOGADOR 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", ponto[1], ponto[2], ponto[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", ponto[4], ponto[5], ponto[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", ponto[7], ponto[8], ponto[9]);
    printf("     |     |     \n\n");
}

