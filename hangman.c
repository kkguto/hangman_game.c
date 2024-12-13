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
    bool letra_rept;
    int max_tent = 10;
    int num_tent = 0;

    while (true){

        system("cls");
        printf("\nA palavra secreta tem %d letras\n=================================", tam);
        printf("\n\tPalavra: ");
        for(int i = 0; i < tam; i++){
            printf("%c ", resposta[i]);
        }

        printf("\n=======================================");
        printf("\nVoce tem %d tentivas", max_tent - num_tent);
        
        printf("\nDigite uma letra que pode estar na palavra (Digite '1' caso deseja escrevar a palavra): ");
        scanf(" %c", &chute);

        if(chute == '1'){
            char palavra_tentativa[60]; // Variável separada
            printf("\nDigite a palavra completa: ");
            scanf(" %s", palavra_tentativa);

            if(strcmp(palavra_secreta, palavra_tentativa) == 0){
                printf("\nParabens!! Voce acertou a palavra secreta!");
                printf("\n");
                system("pause");
                break;
            } else {
                printf("\nErrou! A palavra secreta era: %s", palavra_secreta);
                printf("\n");
                system("pause");
                break;
            }

        }else{
            
            letra_rept = true;
            for(int i = 0; i < tam; i++){
                if(chute == palavra_secreta[i]){
                    if(resposta[i] == '_'){
                        resposta[i] = chute;
                        letra_rept = false;
                    }
                }
            }
            
            if(letra_rept){
                printf("\nEssa letra nao tem na palavra ou ja foi usada.\n");
                printf("\n");
                system("pause");
            }
        }

        num_tent++;

        if(num_tent == max_tent){
            printf("\nFim de Jogo! Voce atingiu o maximo de tentativas");
            printf("\n");
            system("pause");
            break;
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
            printf("\n========= Jogador 1 =========");
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