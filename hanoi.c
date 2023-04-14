#include <stdio.h>

void transfere(char fonte, char destino){
  printf("transfere de %c para %c", fonte, destino);
}

void hanoi(int n_discos, char fonte, char destino, char aux){
  if (n_discos == 1){
    transfere(fonte, destino);
    return;
  hanoi(n_discos - 1, fonte, aux, destino);
  transfere(fonte, destino);
    hanoi(n_discos-1, aux, destino, fonte);
    
 int main(){
   int n;
   scanf("%d", n);
   hanoi(n, 'A', 'B', 'C');
   return(0);
   
 }
