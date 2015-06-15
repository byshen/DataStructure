#include <iostream>

using namespace std;

int a(int m, int n);

int main()
{
    int m, n;
    cin >> m >> n;
    cout << a(m,n);
    return 0;
}

int a(int m, int n)
{
    if (m==0) return n+1;
    if (m!=0&&n==0) return a(m-1,1);
    else return a(m-1,a(m,n-1));
}

