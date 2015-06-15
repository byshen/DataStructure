#include <iostream>

using namespace std;

char ss1[1000001], ss2[1000001];
char result[1000003];
int length;

int strlen(char s[])
{
    int i = 0;
    while (s[i]!='\0') ++i;
    return i;
}

void bigintplus(char s1[], char s2[], int len1, int len2);

int main()
{
    int i;
    cin >> ss1 >> ss2;
    int llen1 = strlen(ss1);
    int llen2 = strlen(ss2);
    if (llen1 >= llen2) bigintplus(ss1,ss2, llen1, llen2);
    else bigintplus(ss2,ss1,llen2, llen1);
    for (i = length-1; i >= 0; --i)
    {
        cout << result[i];
    }
    return 0;
}

void bigintplus(char s1[], char s2[], int len1, int len2)
{
    int jinwei = 0;
    int i = 0;
    while (i<len2)
    {
        ++i;
        if (s1[len1-i]+s2[len2-i] + jinwei-'0'<='9')
        {
            result[i-1] = s1[len1-i]+s2[len2-i] + jinwei-'0';
            jinwei = 0;
            //cout << result[i-1];
        }
        else {result[i-1] = s1[len1-i]+s2[len2-i] + jinwei-'0'-10;
        jinwei = 1;
        //cout << result[i-1];
        }
    }
    while (i<len1)
    {
        ++i;
        if (s1[len1-i] + jinwei<='9')
        {
            result[i-1] = s1[len1-i]+ jinwei;
            jinwei = 0;
            //cout << result[i-1];
        }
        else {result[i-1] = s1[len1-i] + jinwei-10;
        jinwei = 1;
        //cout << result[i-1];
        }
    }
    if (jinwei==1) {result[len1] = '1'; length = len1+1;}
    else {length = len1;}
}
