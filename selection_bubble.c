

#include <stdio.h>
#include <string.h>

void selecao(int vetor[], int tamanho_vetor);
void bolha(int vetor[], int tamanho_vetor);

int main(){
    int tamanho;
    char metodo[10];

    //recebe o metodo de ordenacao e o tamanho do vetor
    scanf("%s", metodo);
    scanf("%d", &tamanho);

    //recebe os elementos do vetor
    int vetor[tamanho];
    for(int i=0; i<tamanho; i++)
        scanf("%d", &vetor[i]);

    //ordena o vetor de acordo com o metodo escolhido
    if(strcmp(metodo, "selecao") == 0)
        selecao(vetor, tamanho);
    else if(strcmp(metodo, "bolha") == 0)
        bolha(vetor, tamanho);

    //imprime o vetor ordenado
    for(int i=0; i<tamanho; i++){
        printf("%d ", vetor[i]);
    }


    return 0;
}

void selecao(int vetor[], int tamanho_vetor){

    for(int posicao = 0; posicao<tamanho_vetor-1; posicao++){
        int indicedomenor = posicao;
        for(int i = posicao + 1; i<tamanho_vetor; i++){ //percorre o vetor n vezes ate achar o menor de todos
            printf("C %d %d\n", indicedomenor, i);
            if(vetor[i]<vetor[indicedomenor]){ //se posicao atual eh menor que o atual menor valor
                indicedomenor = i;

            }
        } //depois de percorrer faz o swap entre eles
        if(posicao != indicedomenor){
            printf("T %d %d\n", posicao, indicedomenor);
            int swap = vetor[indicedomenor];
            vetor[indicedomenor] = vetor[posicao];
            vetor[posicao] = swap;
        }
    }
}

void bolha(int vetor[], int tamanho_vetor){
    int naotrocou;

    for(int ultimaposicao = tamanho_vetor-1; ultimaposicao > 0; ultimaposicao = naotrocou-1){ //marca a ultima posicao ate onde n esta ordenado
        int trocou = 0;
        naotrocou = 0; // marca a ultima posicao que houve uma troca, isto eh, o computador entende que tudo que ta na frente disso ta ordenado
        for(int i=0; i<ultimaposicao; i++){ //i vai ate up-1 pq na comparacao vai ate i+1(igual a ultimaposicao)
            printf("C %d %d\n", i, i+1);
            if(vetor[i]>vetor[i+1]){
                printf("T %d %d\n", i, i+1);
                int swap = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = swap;
                trocou = 1;
                naotrocou = i+1;
            }
        }
        if(!trocou)
            break;
    }
}
