#include <iostream>
#include "lista.h"
using namespace std;

no* criar_lista_vazia() {
    return NULL;
}

no* inserir_elemento(no* lista, int valor) {
    no* novo_no = new no;
    novo_no->info = valor;
    novo_no->proximo = lista;
    return novo_no;
}

void percorrer_lista(no* lista) {
    no* atual = lista;
    if (atual == NULL) {
        cout << "lista vazia!" << endl;
        return;
    }
    
    cout << "elementos da lista: ";
    while (atual != NULL) {
        cout << atual->info << " ";
        atual = atual->proximo;
    }
    cout << endl;
}

int contar_elementos(no* lista) {
    int contador = 0;
    no* atual = lista;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

void mostrar_menu() {
    cout << "\n=== MENU LISTA ENCADEADA ===" << endl;
    cout << "1. inserir elemento" << endl;
    cout << "2. percorrer lista" << endl;
    cout << "3. contar elementos" << endl;
    cout << "4. sair" << endl;
    cout << "escolha uma opcao: ";
}