#include <iostream>
#include "lista.h"
using namespace std;

int main() {
    no* minha_lista = criar_lista_vazia();
    int opcao, valor;
    
    do {
        mostrar_menu();
        cin >> opcao;
        
        switch(opcao) {
            case 1:
                cout << "digite o valor para inserir: ";
                cin >> valor;
                minha_lista = inserir_elemento(minha_lista, valor);
                cout << "valor " << valor << " inserido!" << endl;
                break;
                
            case 2:
                percorrer_lista(minha_lista);
                break;
                
            case 3:
                cout << "numero de elementos na lista: " << contar_elementos(minha_lista) << endl;
                break;
                
            case 4:
                cout << "saindo do programa..." << endl;
                break;
                
            default:
                cout << "opcao invalida! tente novamente." << endl;
        }
        
    } while (opcao != 4);
    
    return 0;
}
