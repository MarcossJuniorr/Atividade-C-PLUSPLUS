#ifndef QUESTAO9_H
#define QUESTAO9_H

#include <iostream>

class ListaDupla {
private:
    struct Node {
        int data;
        Node *next;
        Node *previous;
    };
    
    Node *head;
    Node *tail;
    int size;
    
    bool vazia();
    bool existe(int valor);

public:
    ListaDupla();
    ~ListaDupla();
    bool inserirInicio(int valor);
    void mostrar();
    void menu();
};

#endif
