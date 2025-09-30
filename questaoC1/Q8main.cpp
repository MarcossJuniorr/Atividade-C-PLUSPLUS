#include "Questao8.h"
#include <iostream>
using namespace std;

void mostrarMenu() {
    cout << "\n=== LISTA DUPLAMENTE ENCADEADA ===" << endl;
    cout << "1. Inserir elemento em posicao" << endl;
    cout << "2. Imprimir lista" << endl;
    cout << "3. Buscar elemento (recursivo)" << endl;
    cout << "4. Excluir elemento por posicao" << endl;
    cout << "5. Mostrar tamanho" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    ListaDuplamenteEncadeada lista;
    int opcao, valor, posicao;
    
    do {
        mostrarMenu();
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                cout << "Digite o valor: ";
                cin >> valor;
                cout << "Digite a posicao: ";
                cin >> posicao;
                lista.inserirPosicao(valor, posicao);
                break;
                
            case 2:
                lista.imprimir();
                break;
                
            case 3:
                cout << "Digite o valor para buscar: ";
                cin >> valor;
                if (lista.buscarElemento(valor)) {
                    cout << "Valor " << valor << " encontrado na lista!" << endl;
                } else {
                    cout << "Valor " << valor << " nao encontrado na lista!" << endl;
                }
                break;
                
            case 4:
                cout << "Digite a posicao para excluir: ";
                cin >> posicao;
                lista.excluirPosicao(posicao);
                break;
                
            case 5:
                cout << "Tamanho da lista: " << lista.getTamanho() << endl;
                break;
                
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
                
            default:
                cout << "Opcao invalida!" << endl;
        }
        
    } while (opcao != 0);
    
    return 0;
}
