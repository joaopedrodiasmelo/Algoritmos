#include <stdio.h>
#include <stdlib.h>

//Rafaela Ferreira Lovatti (13731066)
//João Pedro Dias Melo (13828592)
//João Vitor Martins da Silva (13696641)
//Fernando Mezher Silva Lopes (12725515)

void insere(); 
int busca(); 

int main(){

    int M, N, D, B, e, i;

    scanf("%d", &M);
    int *hash = calloc(sizeof(int), M);
	for(i=0; i<M; i++){
		hash[i] = -1;
	}

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &e);
        insere(hash, e, M);
    } 

    scanf("%d", &D);
    
    for(i=0; i<D; i++){
		int k;
		
		scanf("%d", &e);
		k = busca(hash, e, M);
		
		if(k != -1)
			hash[k] = -1;
	}

    scanf("%d", &B);
    for(i=0; i<B; i++){
		scanf("%d", &e);
		
		if(i < B-1)
			printf("%d ", busca(hash, e, M));
		else
			printf("%d", busca(hash, e, M));
	}

return 0;
}

void insere(int *hash, int e, int M){
    int k;

    for(int i = 0; i < M; i++){
		k = (e + i) % M;
		
		if(hash[k] == -1){
			hash[k] = e;
			break;
		}
		
		if(hash[k] == e){ 
			break;
		}
	}
}


int busca(int *hash, int e, int M){
int k;
	
	for(int i=0; i<M; i++){
		k = (e + i) % M;
		
		if(hash[k] == e){
			hash[k] = e;
			return k;
		}
	}
	
	return -1;
}