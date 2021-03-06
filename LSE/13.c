#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void inserir_ordenado(int data);
void cria_lista_ord();

int main(){
    cria_lista_ord();
    show_content();
}

void cria_lista_ord(){
    int data;

    inicio = (struct node *)NULL;
    scanf("%d", &data);
    while(data >= 0){
        inserir_ordenado(data);
        scanf("%d", &data);
    }
}

void inserir_ordenado(int data){
    struct node *aux, *prev;
    //se a lista tiver vazia
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
    }
    //inserir antes do inicio
    else if(inicio->data > data){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = inicio;
        inicio = aux;
    }
    else{
        aux = inicio;
        while(aux->next != (struct node *)NULL && aux->data <= data){
            prev = aux;
            aux = aux->next;
        }

        //inserir dps de aux (fim)
        if(aux->data <= data){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
        }
        //inserir antes de aux (entre prev e aux)
        else{
            prev->next = (struct node *)malloc(sizeof(struct node));
            prev = prev->next;
            prev->data = data;
            prev->next = aux;
        }
    }
    aux = (struct node *)NULL;
    prev = aux;
}