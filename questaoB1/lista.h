#ifndef LISTA_H
#define LISTA_H

struct no {
    int info;
    no* proximo;
};

no* criar_lista_vazia();
no* inserir_elemento(no* lista, int valor);
void percorrer_lista(no* lista);
int contar_elementos(no* lista);
void mostrar_menu();

#endif