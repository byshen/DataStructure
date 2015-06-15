#include <iostream>

using namespace std;

int a[1001],len = 0;
int b[1001];

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void qsort(int s, int t)
{
    if (s >= t) return;
    int i = s, j = t, mid = a[(s+t)>>1];
    while (i <= j)
    {
        while (a[i]<mid) ++i;
        while (a[j]>mid) --j;
        if (i <= j)
        {
            swap(a[i++],a[j--]);
        }
    }
    qsort(s,j);
    qsort(i,t);
}

bool find(int kk, int re[], int cnt)
{
    int i;
    for (i = 1; i <= cnt; ++i)
    {
        if (re[i]==kk) return true;
    }
    return false;
}

void display()
{
    qsort(1,len);
    int i;
    for (i = 1; i <= len; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int N,i,num,j,kk, u = 0,tmp,len_tmp;
    cin >> N;
    char s;
    for (i = 1; i <= N; ++i)
    {
        cin >> s;
        if (s == '+')
        {
            cin >> num;
            for (j = 1; j <= num; ++j)
            {
                cin >> kk;
                if (!find(kk,a,len))
                {
                    ++len;
                    a[len] = kk;
                }
            }
            display();
        }
        if (s == '-')
        {
            len_tmp = len;
            len = 0;
            cin >> num;
            for (j = 1; j <= num; ++j)
            {
                cin >> b[j];
            }
            for (j = 1; j <= len_tmp; ++j)
            {
                if (!find(a[j],b,num))
                {
                    ++len;
                    a[len] = a[j];
                }
            }
            display();
        }
        if (s == '*')
        {
            cin >> num;
            len_tmp = len;
            len = 0;
            for (j = 0; j < num; ++j)
            {
                cin >> tmp;
                if (find(tmp,a,len_tmp))
                {
                    ++len;
                    b[len] = tmp;
                }
            }
            for (j = 1; j <= len; ++j)
                {
                    a[j] = b[j];
                }
            display();
            }
        }


    return 0;
}
