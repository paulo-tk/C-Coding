#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** Movimentos(char* posicao){
    char** matriz = malloc(8*sizeof(char*));
    for(int i = 0; i<8; i++){
        matriz[i] = malloc(4*sizeof(char));
    }
    //x = position[0] - 'a';
    //y = position[1] - '1';
    //int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    //int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
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

int main(){
    int n;
    scanf("%d", &n);
    char **cavalos = malloc(8*sizeof(char*));
    for(int i = 0; i<8; i++){
        cavalos[i] = malloc(4*sizeof(char));
    }

    int index = 0;
    while(index < n){
        scanf(" %[^\n]", cavalos[index]);
        index += 1;
    }
    int verdade = 0;
    //for(int i = 0; i<8; i++){
    //    printf("%s\n", Movimentos(cavalos[0])[i]);
    //    printf("%lu\n", strlen(Movimentos(cavalos[0])[i]));
    //}

    for(int i = 0; i < n; i++){
        char **moves = Movimentos(cavalos[i]);
        for(int j = i; j < n; j++){
            for(int k = 0; k < 8; k++){
                if(moves[k][0] == cavalos[j][0] && moves[k][2]==cavalos[j][2]){
                    verdade += 1;
                }
            }
        }
        DestroiMatrizChar(&moves, 8);
    }
    if(verdade==0){
        printf("Paz no reino!\n");
    } else{
        printf("Os cavalos estao em guerra!\n");
    }
    DestroiMatrizChar(&cavalos, 8);
    return 0;
}
