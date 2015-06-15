#include <iostream>

using namespace std;

int weight[100001] = {0}, Left[100001] = {0}, Right[100001] = {0}, flag[100001] = {0};
int Q[100001] = {0}, begin = 1, tail = 0;

void enQueue(int x)
{
    ++tail;
    Q[tail] = x;
}

int main()
{
    int i,N,root,de,zuo,you,quan;
    cin >> N;
    for (i = 1; i <= N; ++i)
    {
        cin >> zuo>> you >> quan;
        Left[i] = zuo;
        Right[i] = you;
        weight[i] = quan;
        flag[Left[i]] = 1;
        flag[Right[i]] = 1;
    }
    for (i = 1; i <= N; ++i)
        {
            if (!flag[i]) {root = i; break;}
        }
    enQueue(root);
    while (begin <= tail)
    {
        de = Q[begin];
        ++begin;
        if (Left[de]!=0) enQueue(Left[de]);
        if (Right[de]!=0) enQueue(Right[de]);
        cout << weight[de] << ' ';
    }
    return 0;
}
