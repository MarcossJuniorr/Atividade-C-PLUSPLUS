#include "Questao10.h"
#include <iostream>
using namespace std;

void mostrarMenu() {
    cout << "\n=== LISTA CIRCULAR DUPLAMENTE ENCADEADA ===" << endl;
    cout << "1. Inserir no inicio" << endl;
    cout << "2. Inserir no fim" << endl;
    cout << "3. Inserir em posicao" << endl;
    cout << "4. Retirar do inicio" << endl;
    cout << "5. Retirar do fim" << endl;
    cout << "6. Retirar por posicao" << endl;
    cout << "7. Imprimir lista" << endl;
    cout << "8. Mostrar tamanho" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    ListaCircularDupla lista;
    int opcao, valor, posicao;
    
    do {
        mostrarMenu();
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                cout << "Digite o valor: ";
                cin >> valor;
                lista.inserirInicio(valor);
                cout << "Valor " << valor << " inserido no inicio!" << endl;
                break;
                
            case 2:
                cout << "Digite o valor: ";
                cin >> valor;
                lista.inserirFim(valor);
                cout << "Valor " << valor << " inserido no fim!" << endl;
                break;
                
            case 3:
                cout << "Digite o valor: ";
                cin >> valor;
                cout << "Digite a posicao: ";
                cin >> posicao;
                lista.inserirPosicao(valor, posicao);
                break;
                
            case 4:
                lista.retirarInicio();
                cout << "Elemento do inicio retirado!" << endl;
                break;
                
            case 5:
                lista.retirarFim();
                cout << "Elemento do fim retirado!" << endl;
                break;
                
            case 6:
                cout << "Digite a posicao: ";
                cin >> posicao;
                lista.retirarPosicao(posicao);
                break;
                
            case 7:
                lista.imprimir();
                break;
                
            case 8:
                cout << "Tamanho: " << lista.getTamanho() << endl;
                break;
                
            case 0:
                cout << "Saindo..." << endl;
                break;
                
            default:
                cout << "Opção invalida!" << endl;
        }
        
    } while (opcao != 0);
    
    return 0;
}
