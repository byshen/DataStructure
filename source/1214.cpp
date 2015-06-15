#include <iostream>
#include <fstream>
using namespace std;

int weight[100001] = {0},  Son[100001] = {0}, Brother[100001] = {0}, flag[100001] = {0};
int Q[100001] = {0}, begin = 1, tail = 0;

void enQueue(int x)
{
    ++tail;
    Q[tail] = x;
}

void preOrder(int root)
{
    if (root == 0) return;
    cout << weight[root] << ' ';
    int p;
    p = Son[root];
    while (p!=0)
    {
        preOrder(p);
        p = Brother[p];
    }
}

void postOrder(int root)
{
    if (root == 0) return;
    int p;
    p = Son[root];
    while (p!=0)
    {
        postOrder(p);
        p = Brother[p];
    }
    cout << weight[root] << ' ';
}

void levelOrder(int root)
{
    int de;
    if (root==0) return;
    enQueue(root);
    while (begin <= tail)
    {
        de = Q[begin];
        cout << weight[de] << ' ';
        ++begin;
        de = Son[de];
        while (de!=0)
        {
            enQueue(de);
            de = Brother[de];
        }
    }

}


ifstream fin("1.txt");

int main()
{
    int i,N,root,de,zuo,you,quan;
    fin >> N;
    for (i = 1; i <= N; ++i)
    {
        fin >> zuo>> you >> quan;
        Son[i] = zuo;
        Brother[i] = you;
        weight[i] = quan;
        flag[Brother[i]] = 1;
        flag[Son[i]] = 1;
    }
    for (i = 1; i <= N; ++i)
        {
            if (!flag[i]) {root = i; break;}
        }
    preOrder(root);
    cout << '\n';
    postOrder(root);
    cout << '\n';
    levelOrder(root);
    return 0;
}
