#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void Amigo_HangmanGame(){
    printf("\n===== Jogador 1 =====");
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
            Amigo_HangmanGame();
        }else if(strcmp(escolha, "2") == 0){
            Computador_HangmanGame();
        }else{
            printf("\nOpcao Invalida. ");
            system("pause");
        }
    }
    
    return 0;
}