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

bool noTabuleiro(int x, int y, int n_linhas, int n_colunas){
    if(x >= 0 && x < n_linhas){
        if(y >= 0 && y < n_colunas){
            return(true);
        }
    }
    return(false);
}

int **AreaBomba(Bomba b){
    int x_meio = b.x;
    int y_meio = b.y;
    int raio = b.r;
    int **posicoes = malloc(((2*raio+1)**2)*sizeof(int));
    for(int i = x_meio-raio; i <= x_meio+raio; i++){
        for(int j = y_meio-raio; j <= y_meio+raio; j++){
            sprintf(posicoes, "%d%d", i, j);
        }
    }
    return posicoes;
}

void DestroiVetorBombas(Bomba **v){
    if ((*v) != NULL){
        free(*v);
        *v = NULL;
    }
}

void DestroiMatrizInts(int ***m, int nlin){
    if ((*m) != NULL){
        for (int l = 0; l<nlin; l++){
            free((*m)[l]);
        }
        free(*m);
        *m = NULL;
    }
}

int main(){
    int linhas, colunas;
    int n;
    scanf("%dx%d", &linhas, &colunas);
    scanf("%d", n);
    Bomba *bombas = malloc(n*sizeof(Bomba));
    int i = 0;
    while(i < n){
        scanf("%d %d %d", bombas[i].x, bombas[i].y, bombas[i].r);
        i++;
    }
    int x_peca, y_peca;
    scanf("%d %d", x_peca, y_peca);

    for(int i = 0; i < n; i++){
        int **posicoes_proibidas = AreaBomba(bombas[i]);
        for(int j = 0; j < 2*bombas[i].r + 1; j++){
            for(int k = 0; k < 2*bombas[i].r + 1; k++){
                if(noTabuleiro(posicoes_proibidas, linhas, colunas))
            }
        }
        DestroiMatrizInts(&posicoes_proibidas);
    }

    DestroiVetorBombas(&bombas);

    return 0;
}