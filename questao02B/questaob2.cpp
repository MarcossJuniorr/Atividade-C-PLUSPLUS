#include <iostream>
using namespace std;

struct No {
    int infor;
    No *prox;
};

struct Pilha {
    No *Topo;
    int tamanho;
};

Pilha minha_pilha;

void inicializar_pilha() {
    minha_pilha.Topo = NULL;
    minha_pilha.tamanho = 0;
}

void inserir_elemento(int valor) {
    No *novo_no = new No;
    novo_no->infor = valor;
    novo_no->prox = minha_pilha.Topo;
    minha_pilha.Topo = novo_no;
    minha_pilha.tamanho++;
    cout << "elemento " << valor << " inserido na pilha" << endl;
}

void excluir_elemento() {
    if (minha_pilha.Topo == NULL) {
        cout << "pilha vazia nao tem elementos para excluir." << endl;
        return;
    }
    
    No *temp = minha_pilha.Topo;
    int valor_removido = temp->infor;
    minha_pilha.Topo = minha_pilha.Topo->prox;
    delete temp;
    minha_pilha.tamanho--;
    cout << "elemento " << valor_removido << " removido da pilha" << endl;
}

void listar_conteudo() {
    if (minha_pilha.Topo == NULL) {
        cout << "pilha vazia" << endl;
        return;
    }
    
    cout << "conteudo da pilha: ";
    No *atual = minha_pilha.Topo;
    while (atual != NULL) {
        cout << atual->infor << " ";
        atual = atual->prox;
    }
    cout << endl;
    cout << "tamanho da pilha: " << minha_pilha.tamanho << endl;
}

void verificar_elemento(int valor) {
    No *atual = minha_pilha.Topo;
    bool encontrado = false;
    int posicao = 1;
    
    while (atual != NULL) {
        if (atual->infor == valor) {
            encontrado = true;
            cout << "elemento " << valor << " encontrado na posicao " << posicao  << endl;
            break;
        }
        atual = atual->prox;
        posicao++;
    }
    
    if (!encontrado) {
        cout << "elemento " << valor << " nao encontrado na pilha" << endl;
    }
}

void mostrar_menu() {
    cout << "1. inserir elemento " << endl;
    cout << "2. excluir elemento " << endl;
    cout << "3. listar conteudo" << endl;
    cout << "4. verificar elemento" << endl;
    cout << "5. sair" << endl;
    cout << "escolha uma opcao: ";
}

int main() {
    inicializar_pilha();
    int opcao, valor;
    
    do {
        mostrar_menu();
        cin >> opcao;
        
        switch(opcao) {
            case 1:
                cout << "digite o valor para inserir: ";
                cin >> valor;
                inserir_elemento(valor);
                break;
                
            case 2:
                excluir_elemento();
                break;
                
            case 3:
                listar_conteudo();
                break;
                
            case 4:
                cout << "digite o valor para verificar: ";
                cin >> valor;
                verificar_elemento(valor);
                break;
                
            case 5:
                cout << "saindo do pograma" << endl;
                break;
                
            default:
                cout << "opcao invalida" << endl;
        }
        
    } while (opcao != 5);
    
    return 0;
}
