#ifndef PILHA_H
#define PILHA_H

struct No {
    int infor;
    No *prox;
};

struct Pilha {
    No *Topo;
    int tamanho;
};

#endif