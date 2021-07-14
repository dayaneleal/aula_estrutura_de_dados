#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimirvetor(int*bancas, int tam);
void mergeSort(int*V, int inicio, int fim);
void merge(int*V, int inicio, int meio, int fim);

int main(void) {
  setlocale(LC_ALL, "Portuguese");
/*Vetor com 8 posições representando as bancas e a quantidade de vendas diária de cada uma dela.*/
  int bancas[] = {2,0,0,2,2,1,7,5};
  int tam = sizeof(bancas)/sizeof(int);
  printf("Vetor preenchido: \n");
  imprimirvetor(bancas, tam);

  mergeSort(bancas, 0, tam-1);
  printf("Vetor de vendas ordenado: \n");
  imprimirvetor(bancas, tam);
}

//Função para imprimir o vetor preenchido
void imprimirvetor(int*bancas, int tam)
{
  int i;
  for(i = 0; i < tam; i++){
    printf("| %i | ", bancas[i]);
  }
  printf("\n");
}

//Função para subdividir o vetor em dois e aplicar a recursividade
void mergeSort(int*V, int inicio, int fim) {
  int meio;
  if(inicio < fim) {
    meio = (inicio + fim)/2;
    mergeSort(V, inicio, meio);
    mergeSort(V,meio+1, fim);
    merge(V, inicio, meio, fim);
  }
}

//Junção das partes em um vetor ordenado
void merge(int*V, int inicio, int meio, int fim){
  int *temp, p1, p2, tamanho, i, j, k;
  int fim1 = 0, fim2 = 0;
  tamanho = fim - inicio + 1;
  p1 = inicio;
  p2 = meio + 1;
  temp = (int*)malloc(tamanho*sizeof(int));

  if(temp == NULL){
    exit(1);
  }else{
    for(i=0; i < tamanho; i++){
      if(!fim1 && !fim2){
        if(V[p1] < V[p2]){
          temp[i] = V[p1++];
        }else{
          temp[i] = V[p2++];
        }

        if(p1 > meio){
          fim1 = 1;
        }

        if(p2>fim){
          fim2 = 1;
        }
      }else{
        if(!fim1){
          temp[i] = V[p1++];
        }else{
          temp[i] = V[p2++];
        }
      }
    }

    for(j=0, k=inicio; j<tamanho; j++, k++){
      V[k] = temp[j];
    }     
  free(temp);
  }
}


