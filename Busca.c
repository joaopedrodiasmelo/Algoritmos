#include <stdio.h>
#include <stdlib.h>

//Rafaela Ferreira Lovatti (13731066)
//João Pedro Dias Melo (13828592)
//João Vitor Martins da Silva (13696641)
//Fernando Mezher Silva Lopes (12725515)

void quick();
int busca();

int main(){

    int N, K, i, aux;

    scanf("%d", &N);
    int *V1 = malloc(sizeof(int)*N);

    for(i=0; i<N; i++){
        scanf("%d", &V1[i]);
    }

    scanf("%d", &K);
    int *V2 = malloc(sizeof(int)*K);
    int *V3 = calloc(sizeof(int), K);

    for(i=0; i<K; i++){
        scanf("%d", &V2[i]);
    }

    quick(V1, 0, N-1);
    
    for (i= 0; i<K; i++){
        aux = V2[i];
        V3[i] = busca(V1, N, aux);
    }

    for(i=0; i<K; i++){
      printf("%d\n", V3[i]);
    }

return 0;
}

void quick(int v[], int f, int l){
    if(f >= l){
        return;
    }

    int m = (l+f)/2;
    int pivot = v[m];
    int i = f;
    int j = l;
    
    while(1) {

        while(v[i] < pivot){
            i++;    
        }

        while(v[j] > pivot){
            j--;
      
        }

        if(i >= j){
            break;
        }

        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    

        i++;
        j--;
    }

    quick(v, f, j);
    quick(v, j+1, l);
}

int busca(int *vetor, int n, int aux){
  int inicio = 0;
  int fim = n-1;

  while(inicio<=fim){
    int meio = (inicio+fim)/2;
    if(vetor[meio] == aux){
      return 1;
    }
    else if(vetor[meio] < aux){
      inicio = meio+1;
    }
    else{
      fim = meio-1;
    }
  }
  return 0;
}