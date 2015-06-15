#include <iostream>

using namespace std;

int weight[100001] = {0}, tree[100001] = {0}, Left[100001] = {0}, Right[100001] = {0}, flag[100001] = {0};
int weight2[100001] = {0}, tree2[100001] = {0}, Left2[100001] = {0}, Right2[100001] = {0}, flag2[100001] = {0};
int Q[100001] = {0}, begin = 1, tail = 0;
int Q2[100001] = {0}, begin2 = 1, tail2 = 0;

/*void enQueue(int x)
{
    ++tail;
    Q[tail] = x;
}

void enQueue2(int x)
{
    ++tail2;
    Q2[tail2] = x;
}*/

bool thesame(int root, int root2)
{
    if (weight[root]!=weight2[root2]) return false;
    if (tree[root]==0&&tree[root]==0) return true;
    if (tree[root]==0&&tree[root]!=0) return false;
    if (tree[root]!=0&&tree[root]==0) return false;
    if (tree[root]!=0&&tree[root]!=0) return thesame(Left[root],Left2[root2])&&thesame(Right[root],Right2[root2]);
}

int main()
{
    int i,N,N2,root,de,de2,root2,zuo,you,quan;
    bool flag3 = true;
    cin >> N;
    for (i = 1; i <= N; ++i)
    {
        cin >> zuo>> you >> quan;
        Left[i] = zuo;
        Right[i] = you;
        weight[i] = quan;
        flag[Left[i]] = 1;
        flag[Right[i]] = 1;
        tree[i] = 1;
    }
    cin >> N2;
    for (i = 1; i <= N2; ++i)
    {
        cin >> zuo>> you >> quan;
        Left2[i] = zuo;
        Right2[i] = you;
        weight2[i] = quan;
        flag2[Left2[i]] = 1;
        flag2[Right2[i]] = 1;
        tree2[i] = 1;
    }
    for (i = 1; i <= N; ++i)
        {
            if (!flag[i]) {root = i; break;}
        }
    for (i = 1; i <= N2; ++i)
        {
            if (!flag2[i]) {root2 = i; break;}
        }
    if (thesame(root,root2)) cout << 'Y';
    else cout << 'N';
    return 0;
}
