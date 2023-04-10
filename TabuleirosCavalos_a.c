#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in_board(int x, int y) {
    return x >= 65 && x < 73 && y >= 49 && y < 57;
}

void DestroiVetorChar(char **v){
    if ((*v) != NULL){
        free(*v);
        *v = NULL;
    }
}

void DestroiMatrizChar(char ***m, int nlin){
    if ((*m) != NULL){
        for (int l = 0; l<nlin; l++){
            free((*m)[l]);
        }
        free(*m);
        *m = NULL;
    }
}

char** Movimentos(char* posicao){
    char** matriz = malloc(8*sizeof(char*));
    for(int i = 0; i<8; i++){
        matriz[i] = malloc(4*sizeof(char));
    }
    sprintf(matriz[0], "%c %c", posicao[0]-1, posicao[2]+2);//posicao[0]+1, posicao[2]+2);
    sprintf(matriz[1], "%c %c", posicao[0]+1, posicao[2]+2);//posicao[0]+2, posicao[2]+1);
    sprintf(matriz[2], "%c %c", posicao[0]+2, posicao[2]+1);//posicao[0]-1, posicao[2]+2);
    sprintf(matriz[3], "%c %c", posicao[0]+2, posicao[2]-1);//posicao[0]-2, posicao[2]+1);
    sprintf(matriz[4], "%c %c", posicao[0]+1, posicao[2]-2);//posicao[0]-1, posicao[2]-2);
    sprintf(matriz[5], "%c %c", posicao[0]-1, posicao[2]-2);//posicao[0]-2, posicao[2]-1);
    sprintf(matriz[6], "%c %c", posicao[0]-2, posicao[2]-1);//posicao[0]+1, posicao[2]-2);
    sprintf(matriz[7], "%c %c", posicao[0]-2, posicao[2]+1);//posicao[0]+2, posicao[2]-1);
    return matriz;
    
}

int main(){
    char *posic = malloc(4*sizeof(char));

    scanf(" %[^\n]", posic);
    char **moves = Movimentos(posic);
    
    for(int i = 0; i < 8; i++){
        if(in_board(moves[i][0], moves[i][2])){
            printf("%s\n", moves[i]);
        }
    }
    DestroiVetorChar(&posic);
    DestroiMatrizChar(&moves, 8);
    return 0;
}