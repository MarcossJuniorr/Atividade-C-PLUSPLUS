#ifndef BIBLIOTECA4_H
#define BIBLIOTECA4_H

#include <iostream>

class lista_recursiva {
private:
    struct node {
        int data;
        node* next;
        node(int value) : data(value), next(NULL) {}
    };
    
    node* head;

    void imprimir_recursivo(node* atual) const {
        if (atual == NULL) {
            return;
        }
        std::cout << atual->data << " ";
        imprimir_recursivo(atual->next);
    }

    bool buscar_recursivo(node* atual, int valor) const {
        if (atual == NULL) {
            return false;
        }
        if (atual->data == valor) {
            return true;
        }
        return buscar_recursivo(atual->next, valor);
    }

    node* excluir_recursivo(node* atual, int valor) {
        if (atual == NULL) {
            return NULL;
        }
        
        if (atual->data == valor) {
            node* temp = atual->next;
            delete atual;
            return temp;
        }
        
        atual->next = excluir_recursivo(atual->next, valor);
        return atual;
    }

    void destruir_recursivo(node* atual) {
        if (atual == NULL) {
            return;
        }
        destruir_recursivo(atual->next);
        delete atual;
    }

    node* inserir_recursivo(node* atual, int valor) {
        if (atual == NULL) {
            return new node(valor);
        }
        atual->next = inserir_recursivo(atual->next, valor);
        return atual;
    }


    int tamanho_recursivo(node* atual) const {
        if (atual == NULL) {
            return 0;
        }
        return 1 + tamanho_recursivo(atual->next);
    }

 
    bool vazia_recursivo(node* atual) const {
        return atual == NULL;
    }

public:
    lista_recursiva() : head(NULL) {}
    
    ~lista_recursiva() {
        destruir_recursivo(head);
    }
    
    void inserir(int valor) {
        head = inserir_recursivo(head, valor);
        std::cout << "elemento " << valor << " inserido com sucesso!" << std::endl;
    }
    
    void imprimir() const {
        if (vazia_recursivo(head)) {
            std::cout << "lista vazia." << std::endl;
            return;
        }
        std::cout << "conteudo da lista: ";
        imprimir_recursivo(head);
        std::cout << std::endl;
    }
    
    void buscar(int valor) const {
        if (buscar_recursivo(head, valor)) {
            std::cout << "elemento " << valor << " encontrado na lista." << std::endl;
        } else {
            std::cout << "elemento " << valor << " nao encontrado na lista." << std::endl;
        }
    }
    
    void excluir(int valor) {
        if (vazia_recursivo(head)) {
            std::cout << "lista vazia. nao e possivel remover." << std::endl;
            return;
        }
        
        if (!buscar_recursivo(head, valor)) {
            std::cout << "elemento " << valor << " nao encontrado na lista." << std::endl;
            return;
        }
        
        head = excluir_recursivo(head, valor);
        std::cout << "elemento " << valor << " removido com sucesso!" << std::endl;
    }
    
    bool esta_vazia() const {
        return vazia_recursivo(head);
    }
    
    int tamanho() const {
        return tamanho_recursivo(head);
    }
};

#endif