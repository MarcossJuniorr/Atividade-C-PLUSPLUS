#include <iostream>
using namespace std;


int produto(int a, int b) {
    if (b == 1)
        return a;
    else 
        return produto(a, b - 1) + a;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << a << " * " << b << " = " << produto(a, b) << endl;

    return 0;
}
