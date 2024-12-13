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

char *palavras_arquivos(const char *nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "r");

    if(arquivo == NULL){
        printf("\n\tErro ao abrir o arquivo: %s\n", nome_arquivo);
        perror("Motivo");
        system("pause");
        return NULL;
    }

    char palavras[100][60];
    int total_palavras = 0;

    while (fscanf(arquivo, "%s", palavras[total_palavras]) != EOF) {
        total_palavras++;
    }
    fclose(arquivo);
    
    if(total_palavras == 0){
        printf("\n\tO arquivo está vazio.\n");
        return NULL;
    }

    srand(time(NULL));
    
    int indice = rand() % total_palavras;
    char *palavra_escolhida = malloc(strlen(palavras[indice]) + 1);  // Corrigido

    if (palavra_escolhida == NULL) {
        printf("\n\tErro ao alocar memória.\n");
        return NULL;
    }

    strcpy(palavra_escolhida, palavras[indice]);
    
    return palavra_escolhida;  
}


void verifacador_palavra(const char *palavra_secreta, const char *resposta, bool *continuar){

    if(strcmp(palavra_secreta, resposta) == 0){
        printf("\nParabens!! Voce acertou a palavra secreta!");
        printf("\n");
        system("pause");
        *continuar = false;
    } else {
        printf("\nErrou! A palavra secreta era: %s", palavra_secreta);
        printf("\n");
        system("pause");
        *continuar = false;
    }

}

void verificar_letra(char letras_tentadas[], int *index, char chute, char resposta[], const char *palavra_secreta, int tam, int *num_tent){
    bool letra_rept = false;

    for (int i = 0; i < *index; i++) {
        if (letras_tentadas[i] == chute) {
            letra_rept = true;
            break;
        }
    }

    if(letra_rept){
        printf("\nEssa letra já foi tentada. Tente outra.\n");
        system("pause");
        return;
    }

    letras_tentadas[(*index)++] = chute;

    bool acertou = false;
    for(int i = 0; i < tam; i++){
            if(chute == palavra_secreta[i]){
                if(resposta[i] == '_'){
                    resposta[i] = chute;
                    acertou = true;
                }
            }
        }
        if (!acertou) {
            printf("\nEssa letra não está na palavra.\n");
            (*num_tent)++;
            system("pause");
        }
}

void jogo(const char *palavra_secreta){
    int tam = strlen(palavra_secreta);

    char resposta[tam + 1];

    for(int i = 0; i < tam; i++){
        resposta[i] = '_';
    }
    resposta[tam] = '\0';

    char chute;
    char letras_tentadas[26] = {0};

    int max_tent = 10;
    int num_tent = 0;

    bool continuar = true;
    int index = 1;

    while (continuar){

        system("cls");
        printf("\nA palavra secreta tem %d letras\n=================================", tam);
        printf("\n\tPalavra: ");
        for(int i = 0; i < tam; i++){
            printf("%c ", resposta[i]);
        }

        printf("\n=======================================");
        printf("\nVoce tem %d tentivas", max_tent - num_tent);
        printf("\n=======================================");
        printf("\nLetras Tentadas: ");
        
        for(int i = 0; i < index; i++){
            printf("%c ", letras_tentadas[i]);
        }
        
        printf("\n=======================================");
        printf("\nDigite uma letra que pode estar na palavra (Digite '1' caso deseja escrevar a palavra): ");
        scanf(" %c", &chute);

        if(chute == '1'){
            char palavra_tentativa[60];
            printf("\nDigite a palavra completa: ");
            scanf(" %s", palavra_tentativa);

            verifacador_palavra(palavra_secreta, palavra_tentativa, &continuar);

        }else{
            verificar_letra(letras_tentadas, &index, chute, resposta, palavra_secreta, tam, &num_tent);
        }
        
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

void computador_HangmanGame(){
    int escolha;
    while (1){

        system("cls");

        printf("\n Escolha um dos Temas abaixo : ");
        printf("\n==============================");
        printf("\n[1] Animais");
        printf("\n[2] Cores");
        printf("\n[3] Frutas");
        printf("\n[4] Objetos");
        printf("\n[5] Paises");
        printf("\n==============================");
        printf("\nSua escolha eh (Digite 0 se deseja Encerrar): ");
        scanf("%d", &escolha);

        if(escolha == 0){
            break;
        }   
        char *palavra_secreta = NULL;

        switch (escolha){
        case 1:
            palavra_secreta = palavras_arquivos("animais.txt");
            break;
        case 2:
            palavra_secreta = palavras_arquivos("cores.txt");
            break;
        case 3:
            palavra_secreta = palavras_arquivos("frutas.txt");

            break;
        case 4:
            palavra_secreta = palavras_arquivos("objetos.txt");

            break;
        case 5:
            palavra_secreta = palavras_arquivos("paises.txt");
            break;
        default:
            printf("\nOpçao Invalida. ");
            system("pause");
            continue;
        }
        if(palavra_secreta != NULL){
            jogo(palavra_secreta);
            free(palavra_secreta);
        }    
    }
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
            system("cls");
            char palavra_secreta[60];
            printf("\n========= Jogador 1 =========");
            printf("\nDigite a Palavra a ser Adivinhada: ");
            scanf(" %s", palavra_secreta);
            jogo(palavra_secreta);

        }else if(strcmp(escolha, "2") == 0){
            computador_HangmanGame();
        }else{
            printf("\nOpcao Invalida. ");
            system("pause");
        }
    }
    
    return 0;
}