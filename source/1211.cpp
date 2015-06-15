#include <iostream>

using namespace std;

int weight[100001] = {0}, tree[100001] = {0}, Left[100001] = {0}, Right[100001] = {0}, flag[100001] = {0};
int Q[100001] = {0}, begin = 1, tail = 0;

void enQueue(int x)
{
    ++tail;
    Q[tail] = x;
}

int main()
{
    int i,N,root,de,zuo,you,count = 0,heh;
    cin >> N;
    for (i = 1; i <= N; ++i)
    {
        cin >> zuo>> you;
        Left[i] = zuo;
        Right[i] = you;
        flag[Left[i]] = 1;
        flag[Right[i]] = 1;
        tree[i] = 1;
    }
    for (i = 1; i <= N; ++i)
        {
            if (!flag[i]) {root = i; break;}
        }
    enQueue(root);
    while (begin <= tail)
    {
        ++count;
        de = Q[begin];
        ++begin;
        if (tree[Left[de]]==1)
        {
            heh = count * 2;
            enQueue(Left[de]);
        }
        if (tree[Right[de]]==1)
        {
            heh = count * 2 + 1;
            enQueue(Right[de]);
        }
    }
    if (heh == count) cout << 'Y';
    else cout << 'N';
    return 0;
}
