#include <iostream>
#include <fstream>

using namespace std;

int a[501],b[501],c[501],d[501];
int result[2000001][2] = {0};

int main()
{
    int N,i,j,cnt = 0;
    cin >> N;
    for (i = 1; i <= N; ++i)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            if (a[i]+b[j]>=0) ++result[a[i]+b[j]][0];
            else ++result[-a[i]-b[j]][1];
        }
    }

    for (i = 1; i <= N; ++i)
        {
            for (j = 1; j <= N; ++j)
        {
            if (c[i]+d[j]<=0) cnt += result[-c[i]-d[j]][0];
            else cnt += result[c[i]+d[j]][1];
        }
        }
    cout << cnt;
    return 0;
}
