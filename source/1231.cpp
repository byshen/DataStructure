#include <iostream>

using namespace std;

int father[100001] = {0},path1[100001],path2[100001];

bool find(int path2[],int num,int k2)
{
    int i;
    for (i = 0; i < k2; ++i)
    {
        if (path2[i]==num) return true;
    }
    return false;
}

int main()
{
    int N,X,Y,i,a,b,k,k2;
    cin >> N >> X >> Y;
    for (i = 1; i <= N; ++i)
    {
        cin >> a >> b;
        father[a] = i;
        father[b] = i;
    }
    k = 0;
    while (X!=0)
    {
        path1[k] = X;
        X = father[X];
        ++k;
    }
    k2 = 0;
    while (Y!=0)
    {
        path2[k2] = Y;
        Y = father[Y];
        ++k2;
    }
    i = 0;
    while (!find(path2,path1[i],k2))
    {
        ++i;
    }
    cout << path1[i];

}
