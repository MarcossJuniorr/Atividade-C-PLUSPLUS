#include <iostream>
using namespace std;

int f1(int n) {
    if (n == 0) 
        return 1;
    else
        return n * f1(n - 1); 
}

int f2(int n) {
    if (n == 0)
        return (1);
    if (n == 1)
        return (1);
    else
        return(f2(n-1) + 2 * f2(n-2));
}

int f3(int n) {
    if (n == 0)
        cout << "zero" << endl;
    else
    {
        cout << n << endl;
        cout << n << endl;
        f3(n-1);
    }
    return 0;
}

void menu() {
    cout << "1. funcao um" << endl;
    cout << "2. funcao dois" << endl;
    cout << "3. funcao tres" << endl;
    cout << "4. sair" << endl;
    cout << "escolha uma opcao: ";
}

int main() {
    int opcao, x;
    
    do {
        menu();
        cin >> opcao;
        
        switch(opcao) {
            case 1:
                cout << "digite o valor de n para f1 : ";
                cin >> x;
                cout << "f1(" << x << ") = " << f1(x) << endl;
                break;
                
            case 2:
                cout << "digite o valor de n para f2: ";
                cin >> x;
                cout << "f2(" << x << ") = " << f2(x) << endl;
                break;
                
            case 3:
                cout << "digite o valor de n para f3: ";
                cin >> x;
                cout << "executando f3(" << x << "):" << endl;
                f3(x);
                break;
                
            case 4:
                cout << "saindo do programa" << endl;
                break;
                
            default:
                cout << "opcao invalida" << endl;
        }
        
    } while (opcao != 4);
    
    return 0;
}
