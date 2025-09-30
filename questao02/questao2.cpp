#include <iostream>
using namespace std;

int somaPar(int n) {
    if (n <= 0) return 0;  
    
    if (n % 2 == 0)        
    return n + somaPar(n - 2);
    else        
    return somaPar(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << "Soma dos pares ate " << n << " = " << somaPar(n) << endl;
    return 0;
}
