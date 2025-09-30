#ifndef QUESTAO8_H
#define QUESTAO8_H

#include <iostream>
using namespace std;

struct No {
    int dado;
    No* anterior;
    No* proximo;
    
    No(int valor) : dado(valor), anterior(NULL), proximo(NULL) {}
};

class ListaDuplamenteEncadeada {
private:
    No* cabeca;
    No* cauda;
    int tamanho;

public:
    ListaDuplamenteEncadeada() : cabeca(NULL), cauda(NULL), tamanho(0) {}
    
    ~ListaDuplamenteEncadeada() {
        while (cabeca != NULL) {
            No* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
        }
    }
    
    void inserirPosicao(int valor, int posicao) {
        if (posicao < 0 || posicao > tamanho) {
            cout << "Posição inválida!" << endl;
            return;
        }
        
        if (posicao == 0) {
            No* novoNo = new No(valor);
            if (vazia()) {
                cabeca = cauda = novoNo;
            } else {
                novoNo->proximo = cabeca;
                cabeca->anterior = novoNo;
                cabeca = novoNo;
            }
        } else if (posicao == tamanho) {
            No* novoNo = new No(valor);
            if (vazia()) {
                cabeca = cauda = novoNo;
            } else {
                cauda->proximo = novoNo;
                novoNo->anterior = cauda;
                cauda = novoNo;
            }
        } else {
            No* novoNo = new No(valor);
            No* atual = cabeca;
            
            for (int i = 0; i < posicao - 1; i++) {
                atual = atual->proximo;
            }
            
            novoNo->proximo = atual->proximo;
            novoNo->anterior = atual;
            atual->proximo->anterior = novoNo;
            atual->proximo = novoNo;
        }
        tamanho++;
        cout << "Valor " << valor << " inserido na posição " << posicao << "!" << endl;
    }
    
    void imprimir() {
        if (vazia()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        
        No* atual = cabeca;
        cout << "Lista: ";
        while (atual != NULL) {
            cout << atual->dado << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }
    
    bool buscarElemento(int valor) {
        return buscarRecursivo(cabeca, valor);
    }
    
    void excluirPosicao(int posicao) {
        if (posicao < 0 || posicao >= tamanho) {
            cout << "Posição inválida!" << endl;
            return;
        }
        
        if (posicao == 0) {
            No* temp = cabeca;
            if (cabeca == cauda) {
                cabeca = cauda = NULL;
            } else {
                cabeca = cabeca->proximo;
                cabeca->anterior = NULL;
            }
            delete temp;
        } else if (posicao == tamanho - 1) {
            No* temp = cauda;
            if (cabeca == cauda) {
                cabeca = cauda = NULL;
            } else {
                cauda = cauda->anterior;
                cauda->proximo = NULL;
            }
            delete temp;
        } else {
            No* atual = cabeca;
            for (int i = 0; i < posicao; i++) {
                atual = atual->proximo;
            }
            atual->anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;
            delete atual;
        }
        tamanho--;
        cout << "Elemento da posição " << posicao << " excluído!" << endl;
    }
    
    bool vazia() {
        return cabeca == NULL;
    }
    
    int getTamanho() {
        return tamanho;
    }

private:
    bool buscarRecursivo(No* atual, int valor) {
        if (atual == NULL) {
            return false; 
        }
        if (atual->dado == valor) {
            return true; 
        }
        return buscarRecursivo(atual->proximo, valor);
    }
};

#endif
