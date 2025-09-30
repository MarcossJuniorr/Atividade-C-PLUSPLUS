#include <iostream>
#include "biblioteca4.h"

void mostrar_menu() {
    std::cout << "\n=== menu lista encadeada recursiva ===" << std::endl;
    std::cout << "1. inserir elemento" << std::endl;
    std::cout << "2. imprimir lista (recursivo)" << std::endl;
    std::cout << "3. buscar elemento (recursivo)" << std::endl;
    std::cout << "4. excluir elemento (recursivo)" << std::endl;
    std::cout << "5. verificar se lista esta vazia" << std::endl;
    std::cout << "6. mostrar tamanho da lista" << std::endl;
    std::cout << "7. sair" << std::endl;
    std::cout << "escolha uma opcao: ";
}

int main() {
    lista_recursiva lista;
    int opcao, valor;
    
    std::cout << "=== sistema de lista encadeada recursiva ===" << std::endl;
    std::cout << "implementacao com funcoes recursivas para:" << std::endl;
    std::cout << "a. imprimir conteudo da lista" << std::endl;
    std::cout << "b. buscar elemento especifico" << std::endl;
    std::cout << "c. excluir elemento da lista" << std::endl;
    
    do {
        mostrar_menu();
        std::cin >> opcao;
        
        switch (opcao) {
            case 1:
                std::cout << "digite o valor a ser inserido: ";
                std::cin >> valor;
                lista.inserir(valor);
                break;
                
            case 2:
                std::cout << "\na. impressao recursiva da lista:" << std::endl;
                lista.imprimir();
                break;
                
            case 3:
                std::cout << "digite o valor a ser buscado: ";
                std::cin >> valor;
                std::cout << "\nb. busca recursiva do elemento:" << std::endl;
                lista.buscar(valor);
                break;
                
            case 4:
                std::cout << "digite o valor a ser excluido: ";
                std::cin >> valor;
                std::cout << "\nc. exclusao recursiva do elemento:" << std::endl;
                lista.excluir(valor);
                break;
                
            case 5:
                if (lista.esta_vazia()) {
                    std::cout << "a lista esta vazia." << std::endl;
                } else {
                    std::cout << "a lista nao esta vazia." << std::endl;
                }
                break;
                
            case 6:
                std::cout << "tamanho da lista: " << lista.tamanho() << " elementos." << std::endl;
                break;
                
            case 7:
                std::cout << "encerrando o programa..." << std::endl;
                break;
                
            default:
                std::cout << "opcao invalida! tente novamente." << std::endl;
                break;
        }
        
        if (opcao != 7) {
            std::cout << "\npressione enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
        
    } while (opcao != 7);
    
    return 0;
}