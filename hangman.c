#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void menu(){
    system("cls");
    printf("\n************** HANGMAN GAME **************");
    printf("\nVoce deseja jogar contra: ");
    printf("\n  [1] Amigo?");
    printf("\n  [2] Computador?");
    printf("\n\n*Digite 'sair' caso deseja encerrar o jogo");
    printf("\n==============================================");
    printf("\nSua escolha eh: ");
}

void jogo(const char *palavra_secreta){
    int tam = strlen(palavra_secreta);
    char resposta[tam + 1];
    for(int i = 0; i < tam; i++){
        resposta[i] = '_';
    }
    resposta[tam] = '\0';

    char chute;
    int acertos = 0;
    bool letra_rept;

    printf("\nA palavra secreta tem %d letras\n", tam);

    while (true){

        for(int i = 0; i < tam; i++){
            printf("%c ", resposta[i]);
        }

        printf("Digite um letra que ache que está na palavra: ");
        scanf(" %c", &chute);

        for(int i = 0; i < tam; i++){
            if(chute == palavra_secreta[i]){
                if(resposta[i] == '_'){
                    resposta[i] = chute;
                }
            }
        }

        if (strcmp(palavra_secreta, resposta) == 0){
            printf("\nParabens!! Voce Acertou a palavra Secreta!");
            printf("\n");
            system("pause");
            break;
        }
    }
    
}
void Computador_HangmanGame(){

}
int main(){ 

    char escolha[5];

    while (1){
        menu();
        scanf(" %s", escolha);

        if(strcmp(escolha, "sair") == 0){
            printf("\n Jogo Encerrado.");
            break;
        }else if(strcmp(escolha, "1") == 0){

            char palavra_secreta[60];
            printf("\n===== Jogador 1 =====");
            printf("\nDigite a Palavra a ser Adivinhada: ");
            scanf(" %s", palavra_secreta);
            jogo(palavra_secreta);

        }else if(strcmp(escolha, "2") == 0){
            Computador_HangmanGame();

        }else{
            printf("\nOpcao Invalida. ");
            system("pause");
        }
    }
    
    return 0;
}