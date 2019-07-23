//Ulisses Genguini - 2019

#include<stdio.h>
#include <stdlib.h>

void imprimeVetor (int *v){
    for (int i = 0; i< 10; i++){
        printf("-%d\n", v[i]);
    }
}

void troca(int *v1, int *v2){
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

void Heapify(int *Arv, int i, int n){
    int left = 2*(i+1)-1;
    int right = 2*(i+1);
    int maior;

    if ((left <= n) && (Arv[left] > Arv[i])){
        maior = left;
    }else{
        maior = i;
    }

    if ((right <= n) && (Arv[right] > Arv[maior])){
        maior = right;
    }

    if (maior != i){
        troca(&(Arv[i]), &(Arv[maior]));
        Heapify(Arv, maior, n);
    }
}

void criarHeap(int *Arv, int n){
    for(int i = (n / 2); i >= 0; i--){
        Heapify(Arv, i, n);
    }
}


void Heapsort(int *Arv, int n){
    criarHeap(Arv, n);
    for (int i = n-1; i > 0; i--){
        troca(&(Arv[0]), &(Arv[i]));
        Heapify(Arv, 0, i-1);

    }
}

int main(){
    int vetor[10];
    for(int i = 0; i<10; i++){
        vetor[i] = i;
    }
    Heapsort(vetor, 10);
    imprimeVetor(vetor);
}
