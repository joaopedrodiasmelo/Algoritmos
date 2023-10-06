#include <stdio.h>
#include <stdlib.h>

void insertionSort(int a[], int n){
    long comps = 0;
    long trocas = 0;
    for(int p = 1; p < n; p++){
        int x = a[p];
        trocas++;
        int i = p-1;
        while(i >= 0 && x < a[i]){
            comps++;
            a[i+1] = a[i];
            trocas++;
            i--;
        }
        if(i>=0){
        comps++;
        }
        a[i+1] = x;
        trocas++;
    }
    printf ("I %d %ld %ld\n", n, trocas,comps);
}

void merge(int vetor[], int comeco, int meio, int fim, long* comps, long* trocas) {

    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] <= vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
        (*comps)++;
        (*trocas)++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        (*trocas)++;
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        (*trocas)++;
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
        (*trocas)++;
    }

    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim, long* comps, long* trocas){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio, comps, trocas);
        mergeSort(vetor, meio+1, fim, comps, trocas);
        merge(vetor, comeco, meio, fim, comps, trocas);
    }
}

int main (){
    int q;
    int n;
    int** vetores;
    int* tamanhovetores;
    long trocas,comps;
    int* vetAux;

    scanf ("%d", &q);
    vetores = (int**)malloc(sizeof(int*)*q);
    tamanhovetores = (int*)malloc(sizeof(int)*q);

    for(int i = 0;i<q;i++){
        scanf("%d", &n);
        vetores[i] = (int*)malloc(sizeof(int)*n);
        tamanhovetores[i] = n;
    }

    for(int i = 0;i<q;i++){
        for(int j = 0;j<tamanhovetores[i];j++){
            scanf("%d", &vetores[i][j]);
        }
    }

    for(int vetorselecionado = 0;vetorselecionado<q;vetorselecionado++){
        vetAux = (int*)malloc(sizeof(int)*tamanhovetores[vetorselecionado]);
        for(int posicaocopia = 0;posicaocopia<tamanhovetores[vetorselecionado];posicaocopia++){
            vetAux[posicaocopia] = vetores[vetorselecionado][posicaocopia];
        }

        insertionSort(vetores[vetorselecionado],tamanhovetores[vetorselecionado]);

        comps = 0;
        trocas = 0;

        mergeSort(vetAux,0,tamanhovetores[vetorselecionado]-1, &comps, &trocas);

        printf("M %d %ld %ld\n", tamanhovetores[vetorselecionado], trocas, comps);

        free(vetAux);
    }

    for(int i = 0;i<q;i++){
        free(vetores[i]);
    }

    free(vetores);
    free(tamanhovetores);
    return 0;
}
