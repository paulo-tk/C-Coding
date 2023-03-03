#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int lesmas[100];
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		scanf("%d", &lesmas[i]);
	}
	
	int duracao;
	int lim;
	
	scanf("%d", &duracao);
	
	if (duracao == 1) lim = 100;
	else if (duracao == 2) lim = 20;
	else if (duracao == 3) lim = 10;
	
	int maxima = 0;
	for (int i = 0; i <n; i++){
		if(lesmas[i] > maxima and lesmas[i] <= lim){
			maxima = lesmas[i];
		}
	}
	
	printf("%d\n", maxima);
	
	
	return 0;
}
