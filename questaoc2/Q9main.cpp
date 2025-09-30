#include "Questao9.h"
#include <iostream>

ListaDupla::ListaDupla() {
    head = NULL;
    tail = NULL;
    size = 0;
}

bool ListaDupla::vazia() {
    return size == 0;
}

bool ListaDupla::existe(int valor) {
    Node *atual = head;
    while (atual != NULL) {
        if (atual->data == valor) return true;
        atual = atual->next;
    }
    return false;
}

bool ListaDupla::inserirInicio(int valor) {
    if (existe(valor)) {
        std::cout << "Valor " << valor << " ja existe na lista!\n";
        return false;
    }

    Node *novo = new Node();
    novo->data = valor;
    novo->previous = NULL;
    novo->next = NULL;

    if (vazia()) {
        head = novo;
        tail = novo;
    } else {
        novo->next = head;
        head->previous = novo;
        head = novo;
    }
    size++;
    std::cout << "Valor " << valor << " inserido no inicio!\n";
    return true;
}

void ListaDupla::mostrar() {
    if (vazia()) {
        std::cout << "Lista vazia!\n";
        return;
    }
    
    Node *atual = head;
    std::cout << "Lista: ";
    while (atual != NULL) {
        std::cout << atual->data << " ";
        atual = atual->next;
    }
    std::cout << std::endl;
}

void ListaDupla::menu() {
    int opcao, valor;
    
    do {
        std::cout << "\n=== LISTA DUPLA ===\n";
        std::cout << "1 - Inserir no inicio\n";
        std::cout << "2 - Mostrar lista\n";
        std::cout << "3 - Sair\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;

        switch (opcao) {
        case 1:
            std::cout << "Valor: ";
            std::cin >> valor;
            inserirInicio(valor);
            break;
        case 2:
            mostrar();
            break;
        case 3:
            std::cout << "Programa encerrado!\n";
            break;
        default:
            std::cout << "Opcao invalida!\n";
            break;
        }
    } while (opcao != 3);
}

ListaDupla::~ListaDupla() {
    Node *atual = head;
    while (atual != NULL) {
        Node *proximo = atual->next;
        delete atual;
        atual = proximo;
    }
}

int main() {
    ListaDupla lista;
    lista.menu();
    return 0;
}
