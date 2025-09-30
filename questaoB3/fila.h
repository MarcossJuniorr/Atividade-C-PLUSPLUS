#ifndef FILA_H
#define FILA_H

struct No {
    int infor;
    No *prox;
};

struct Fila {
    No *inicio;
    No *fim;
    int tamanho;
};

#endif