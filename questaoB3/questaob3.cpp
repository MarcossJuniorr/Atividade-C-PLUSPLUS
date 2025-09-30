#include <iostream>
using namespace std;

struct No {
    int infor;
    No *prox;
};

struct Fila {
    No *inicio;
    No *fim;
    int tamanho;
};

Fila minha_fila;

void inicializar_fila() {
    minha_fila.inicio = NULL;
    minha_fila.fim = NULL;
    minha_fila.tamanho = 0;
}

void inserir_elemento(int valor) {
    No *novo_no = new No;
    novo_no->infor = valor;
    novo_no->prox = NULL;
    
    if (minha_fila.fim == NULL) {
        minha_fila.inicio = novo_no;
        minha_fila.fim = novo_no;
    } else {
        minha_fila.fim->prox = novo_no;
        minha_fila.fim = novo_no;
    }
    
    minha_fila.tamanho++;
    cout << "elemento " << valor << " inserido na fila" << endl;
}

void excluir_elemento() {
    if (minha_fila.inicio == NULL) {
        cout << "nao ha elementos para excluir." << endl;
        return;
    }
    
    No *temp = minha_fila.inicio;
    int valor_removido = temp->infor;
    minha_fila.inicio = minha_fila.inicio->prox;
    
    if (minha_fila.inicio == NULL) {
        minha_fila.fim = NULL;
    }
    
    delete temp;
    minha_fila.tamanho--;
    cout << "elemento " << valor_removido << " removido da fila" << endl;
}

void listar_conteudo() {
    if (minha_fila.inicio == NULL) {
        cout << "fila vazia" << endl;
        return;
    }
    
    cout << "conteudo da fila : ";
    No *atual = minha_fila.inicio;
    while (atual != NULL) {
        cout << atual->infor << " ";
        atual = atual->prox;
    }
    cout << endl;
    cout << "tamanho da fila: " << minha_fila.tamanho << endl;
}

void verificar_elemento(int valor) {
    No *atual = minha_fila.inicio;
    bool encontrado = false;
    int posicao = 1;
    
    while (atual != NULL) {
        if (atual->infor == valor) {
            encontrado = true;
            cout << "elemento " << valor << " encontrado na posicao " << posicao << endl;
            break;
        }
        atual = atual->prox;
        posicao++;
    }
    
    if (!encontrado) {
        cout << "elemento " << valor << " nao encontrado na fila" << endl;
    }
}

void mostrar_menu() {
    cout << "1. inserir elemento" << endl;
    cout << "2. excluir elemento" << endl;
    cout << "3. listar conteudo" << endl;
    cout << "4. verificar elemento" << endl;
    cout << "5. sair" << endl;
    cout << "escolha uma opcao: ";
}

int main() {
    inicializar_fila();
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
                cout << "saindo do programa" << endl;
                break;
                
            default:
                cout << "opcao invalida" << endl;
        }
        
    } while (opcao != 5);
    
    return 0;
}
