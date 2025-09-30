#include <iostream>
using namespace std;

/*
int f1(int n) {
    if (n == 0) 
        return 1;
    else
        return n * f1(n - 1); 
}*/

/* int f2(int n) {
if (n == 0)
 return (1);
if (n == 1)
 return (1);
else
 return(f2(n-1)+ 2 * f2(n-2));
} */

int f3(int n) {
if (n == 0)
 cout << "Zero" << endl;
else
{
 cout<< n << endl;
 cout << n << endl;
 f3(n-1);
}
}



int main() {
int x;
    cin >> x;

   // cout << "f1(" << x << ") = "  << f1(x) << endl;// 
  // cout << "f2(" << x << ") = " << f2(x) << endl;//
    f3(x);

    return 0;
} 