#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _bomba{
    int x, y, r;
} Bomba;

Bomba CriaBomba(int x, int y, int r){
    Bomba b;
    b.x = x;
    b.y = y;
    b.r = r;
    return b;
}

int noTabuleiro(int x, int y, int n_linhas, int n_colunas){
    return(x >= 0 && x <= n_linhas && y >= 0 && y <= n_colunas);
}

void DestroiVetorBombas(Bomba **v){
    if ((*v) != NULL){
        free(*v);
        *v = NULL;
    }
}

int main(){
    int linhas, colunas;
    int n;
    scanf("%dx%d", &linhas, &colunas);
    scanf("%d", &n);
    if(n==0){
        printf("Seguro\n");
        return(0);
    }
    Bomba *bombas = malloc(n*sizeof(Bomba));
    int i = 0;
    while(i < n){
        scanf("%d %d %d", &(bombas[i].x), &(bombas[i].y), &(bombas[i].r));
        if(!noTabuleiro(bombas[i].x, bombas[i].y, linhas, colunas)){
            printf("-1\n");
            exit(0);
        }
        i++;
    }
    int x_peca, y_peca;
    scanf("%d %d", &x_peca, &y_peca);
    if(!noTabuleiro(x_peca, y_peca, linhas, colunas)){
        printf("-1\n");
        exit(0);
    }

    int dano = 0;
    for(int i = 0; i < n; i++){ //Em cada bomba
        for(int j = bombas[i].x-bombas[i].r; j < bombas[i].x+bombas[i].r + 1; j++){
            for(int k = bombas[i].y-bombas[i].r; k < bombas[i].y+bombas[i].r + 1; k++){
                if(noTabuleiro(j, k, linhas, colunas)){
                    if(j == x_peca && k == y_peca){
                        dano += 1;
                    }
                }
            }
        }
    }

    DestroiVetorBombas(&bombas);
    if(dano==0){
        printf("Seguro\n");
    }else{
        printf("Perigoso\n");
    }

    return 0;
}
