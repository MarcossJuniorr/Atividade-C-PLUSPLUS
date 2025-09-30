#ifndef QUESTAO10_H
#define QUESTAO10_H

#include <iostream>
using namespace std;

struct No {
    int dado;
    No* anterior;
    No* proximo;
    
    No(int valor) : dado(valor), anterior(NULL), proximo(NULL) {}
};

class ListaCircularDupla {
private:
    No* cabeca;
    int tamanho;

public:
    ListaCircularDupla() : cabeca(NULL), tamanho(0) {}
    
    ~ListaCircularDupla() {
        while (!vazia()) {
            retirarInicio();
        }
    }

    
    void inserirInicio(int valor) {
        No* novoNo = new No(valor);
        
        if (vazia()) {
            novoNo->proximo = novoNo;
            novoNo->anterior = novoNo;
            cabeca = novoNo;
        } else {
            No* cauda = cabeca->anterior;
            
            novoNo->proximo = cabeca;
            novoNo->anterior = cauda;
            
            cauda->proximo = novoNo;
            cabeca->anterior = novoNo;
            
            cabeca = novoNo;
        }
        tamanho++;
    }
    
    void inserirFim(int valor) {
        No* novoNo = new No(valor);
        
        if (vazia()) {
            novoNo->proximo = novoNo;
            novoNo->anterior = novoNo;
            cabeca = novoNo;
        } else {
            No* cauda = cabeca->anterior;
            
            novoNo->proximo = cabeca;
            novoNo->anterior = cauda;
            
            cauda->proximo = novoNo;
            cabeca->anterior = novoNo;
        }
        tamanho++;
    }
    
    void inserirPosicao(int valor, int posicao) {
        if (posicao < 0 || posicao > tamanho) {
            cout << "Posição inválida!" << endl;
            return;
        }
        
        if (posicao == 0) {
            inserirInicio(valor);
        } else if (posicao == tamanho) {
            inserirFim(valor);
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
            
            tamanho++;
        }
    }

    
    void retirarInicio() {
        if (vazia()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        
        No* temp = cabeca;
        
        if (tamanho == 1) {
            cabeca = NULL;
        } else {
            No* cauda = cabeca->anterior;
            
            cabeca = cabeca->proximo;
            cabeca->anterior = cauda;
            cauda->proximo = cabeca;
        }
        
        delete temp;
        tamanho--;
    }
    
    void retirarFim() {
        if (vazia()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        
        if (tamanho == 1) {
            retirarInicio();
            return;
        }
        
        No* cauda = cabeca->anterior;
        No* novaCauda = cauda->anterior;
        
        novaCauda->proximo = cabeca;
        cabeca->anterior = novaCauda;
        
        delete cauda;
        tamanho--;
    }
    
    void retirarPosicao(int posicao) {
        if (posicao < 0 || posicao >= tamanho) {
            cout << "Posição inválida!" << endl;
            return;
        }
        
        if (posicao == 0) {
            retirarInicio();
        } else if (posicao == tamanho - 1) {
            retirarFim();
        } else {
            No* atual = cabeca;
            
            for (int i = 0; i < posicao; i++) {
                atual = atual->proximo;
            }
            
            atual->anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;
            
            delete atual;
            tamanho--;
        }
    }

    void imprimir() {
        if (vazia()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        
        No* atual = cabeca;
        cout << "Lista: ";
        
        do {
            cout << atual->dado << " ";
            atual = atual->proximo;
        } while (atual != cabeca);
        
        cout << endl;
    }
    
    bool vazia() {
        return cabeca == NULL;
    }
    
    int getTamanho() {
        return tamanho;
    }
};

#endif
