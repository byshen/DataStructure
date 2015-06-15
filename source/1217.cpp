#include <iostream>

using namespace std;

int a[10000],num;

bool find(int num,int n)
{
    int i;
    for (i = 1; i <= n; ++i)
    {
        if (a[i]==num) return true;
    }
    return false;
}

int main()
{
    int n,m,i;
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    cin >> m;
    for (i = 1; i <= m; ++i)
    {
        cin >> num;
        if (find(num,n)) cout << 'Y' << endl;
        else cout << 'N' << endl;
    }
    return 0;
}
