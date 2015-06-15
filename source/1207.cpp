#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int begin_v = 1, tail_v = 0,begin_c = 1, tail_c = 0;
int Q_v[100001],Q_c[100001];

//ifstream fin("1.txt");
//FILE *fout = fopen("ferry.out","w");

void enQueue_v(int x)
{
    ++tail_v;
    Q_v[tail_v] = x;
}

void enQueue_c(int x)
{
    ++tail_c;
    Q_c[tail_c] = x;
}

int main()
{
    int ship,N,p,q,i,total_c = 0,total_v = 0,num_c = 0,num_v = 0;
    cin >> N;
    for (i = 1; i <= N; ++i)
    {
        cin >> p >> q;
        if (p==0) {enQueue_c(q);}
        else enQueue_v(q);
    }
    int current_time  = 0;
    while (num_c+num_v<N)
    {
        for (ship = 0;  ship < 8&&Q_c[begin_c]<=current_time&&begin_c<=tail_c; ++ship)
        {
            ++num_c;
            total_c += current_time - Q_c[begin_c];
            ++begin_c;
        }

        for (;  ship < 10&&Q_v[begin_v]<=current_time&&begin_v<=tail_v; ++ship)
        {
            ++num_v;
            total_v += current_time - Q_v[begin_v];
            ++begin_v;
        }
        if (ship==10);
        else {while (ship<10&&((begin_c<=tail_c&&Q_c[begin_c]<=current_time)||(begin_v<=tail_v&&Q_v[begin_v]<=current_time)))
        {
            while (ship<10&&((begin_c<=tail_c&&Q_c[begin_c]<=current_time)))
                   {
                       ++ship;
                       ++num_c;
                       total_c += current_time - Q_c[begin_c];
                       ++begin_c;
                   }
            while (ship<10&&((begin_v<=tail_v&&Q_v[begin_v]<=current_time)))
                   {
                       ++ship;
                       ++num_v;
                       total_v += current_time - Q_v[begin_v];
                       ++begin_v;
                   }
        }

        }
        current_time += 10;
    }
    printf("%.3f", double(total_c)/num_c);
    printf(" ");
    printf("%.3f", double(total_v)/num_v);
    return 0;
}

