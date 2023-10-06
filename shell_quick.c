#include <stdio.h>
#include <stdlib.h>

int shell(int v[], int n)
{

    int gap = 1;
    int comparacao = 0, copias = 0;
    int operacoes = 0;

    while (gap <= n)
    {

        gap *= 2;
    }

    gap = gap / 2 - 1;

    while (gap > 0)
    {

        for (int i = gap; i < n; i += gap)
        {

            int x = v[i]; // ira atribuir o valor de x ao elemento do gap
            copias++;

            int j = i - gap;

            while (j >= 0 && v[j] > x)
            {
                comparacao++;

                v[j + gap] = v[j]; // ira copiar o fazer com que o elemento do gap seja o elemento do inicio
                copias++;

                j -= gap; // ira percorrer os vetores com o gap como parametro
            }

            if (j >= 0) // quando o elemento anterior é menos que o do gap
                comparacao++;

            v[j + gap] = x;
            copias++;
        }

        gap /= 2;
    }

    operacoes = comparacao + copias;

    return operacoes;
}

int comparacao_quick, copias_quick, operacao_quick;

void quick(int v[], int f, int l)
{

    if (f >= l)
    {
        return;
    }

    int m = (l + f) / 2;

    int pivot = v[m]; // pivo é o elemento do meio do vetor
    copias_quick++;

    int i = f;

    int j = l;

    while (1)
    {

        while (v[i] < pivot)
        { // ira buscar um elemento maior que o pivot a partir do inicio para a direito do pivo
            comparacao_quick++;
            i++;
        }
        comparacao_quick++;

        while (v[j] > pivot)
        { // ira buscar um elemento menor que o pivot a partir do final para a esquerda do pivot
            comparacao_quick++;
            j--;
        }
        comparacao_quick++; // é a comparação da quebra do while

        if (i >= j)
        { // vetor ordenado e ambos chegaram no pivot

            break;
        }

        int aux = v[i];
        copias_quick++;

        v[i] = v[j];
        copias_quick++;

        v[j] = aux;
        copias_quick++;

        i++;

        j--;
    }

    quick(v, f, j);

    quick(v, j + 1, l);
}

int main()
{
    int num_elementos, shel;
    int *vetor;
    int *vetor_auxiliar;

    scanf("%d", &num_elementos);

    vetor = calloc(num_elementos, sizeof(int));

    for (int a = 0; a < num_elementos; a++)
    { // leitura dos valores do vetor
        scanf("%d", &vetor[a]);
    }

    for (int b = 1; b <= num_elementos; b++)
    { // leitura dos subvetores de vetor;

        vetor_auxiliar = calloc(b, sizeof(int));
        for (int c = 0; c < b; c++)
        { // ira preencher os subvetores
            vetor_auxiliar[c] = vetor[c];
        }
        shel = shell(vetor_auxiliar, b);

        // printf("%d ", shel);

        free(vetor_auxiliar); // libera o subvetor auxiliar para criar no quick
        vetor_auxiliar = NULL;

        vetor_auxiliar = calloc(b, sizeof(int));
        for (int c = 0; c < b; c++)
        { // ira preencher os subvetores
            vetor_auxiliar[c] = vetor[c];
        }
        quick(vetor_auxiliar, 0, b - 1);
        operacao_quick = comparacao_quick + copias_quick;

        // printf("%d ", operacao_quick);
        // printf("\n");

        free(vetor_auxiliar); // libera o subvetor auxiliar para criar ele novamento na próxima repetição
        vetor_auxiliar = NULL;

        comparacao_quick = 0;
        copias_quick = 0;

        if (shel > operacao_quick)
            printf("Q "); // quic realiza menos operacoes
        if (shel < operacao_quick)
            printf("S "); // shel realiza menos operaçoes
        if (shel == operacao_quick)
            printf("- "); // shel e quic realizam o mesmo  numero de operaçoes
    }
}
