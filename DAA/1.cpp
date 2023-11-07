#include <bits/stdc++.h>
using namespace std;

int fib_rec(int n, int &rsteps)
{
    rsteps++;
    if (n <= 1)
        return n;
    return fib_rec(n - 1, rsteps) + fib_rec(n - 2, rsteps);
}

int fib_ite(int n)
{
    cout<<"----------Iterative Fibonacci----------"<<endl;
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout<<"Iterative Steps "<<n<<endl;
    return b;
}

int main()
{
    int n;
    cin >> n;
    int rsteps = 0;
    cout<<"----------Recursive Fibonacci----------"<<endl;
    cout << "Recursive Fibonacci Value " << fib_rec(n, rsteps) << endl;
    cout << "Recursive Steps " << rsteps << endl;
    cout << "Iterative Fibonacci Value " << fib_ite(n) << endl;
}
