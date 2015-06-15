//更好的方法是每次只找出最小元素
//删除最小元素直接把那个数组元素置为一个很大的数
//插入直接插入

#include <iostream>
#include <fstream>
using namespace std;

char s[10];

int num[100000];

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void qsort(int s, int t)
{
    if (s >= t) return;
    int i = s, j = t, mid = num[(s+t)>>1];
    while (i <= j)
    {
        while (num[i]<mid) ++i;
        while (num[j]>mid) --j;
        if (i <= j)
        {
            swap(num[i++],num[j--]);
        }
    }
    qsort(s,j);
    qsort(i,t);
}

ifstream fin("1.txt");

int main()
{
    int i,N,number,cnt = 1,begin = 1;
    cin >> N;
    for (i = 1; i <= N; ++i)
    {
        cin >> s;
        if (s[0]=='i')
        {
            cin >> number;
            num[cnt] = number;
            ++cnt;
        }
        if (s[0]=='d')
        {
            qsort(begin,cnt-1);
            ++begin;
        }
        if (s[0]=='m')
        {
            qsort(begin,cnt-1);
            cout << num[begin] << endl;
        }
    }
}
