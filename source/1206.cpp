#include <iostream>

using namespace std;

int BE = 0, IT = 0, IE = 0;
char s[1000];

int strlen(char s[])
{
    int i = 0;
    while (s[i]!='\0')
    ++i;
    return i;
}

int main()
{
    while (cin >> s)
    {
        if(s[0]=='i'&&s[1]=='f'&&strlen(s)==2)
        {
            ++IT;
        }
        else if (s[0]=='b'&&s[1]=='e'&&s[2]=='g'&&s[3]=='i'&&s[4]=='n'&&strlen(s)==5)
        {
            ++BE;
        }
        else if (s[0]=='e'&&s[1]=='n'&&s[2]=='d'&&strlen(s)==3)
        {
            if (BE==0) {cout << "Error!"; return 0;}
            else --BE;

        }
        else if (s[0]=='t'&&s[1]=='h'&&s[2]=='e'&&s[3]=='n'&&strlen(s)==4)
        {
           if (IT==0) {cout << "Error!"; return 0;}
           else {--IT; ++IE;}
        }
        else if (s[0]=='e'&&s[1]=='l'&&s[2]=='s'&&s[3]=='e')
        {
            if (IE==0) {cout << "Error!"; return 0;}
            else --IE;
        }
    }
    if (IT||BE) {cout << "Error!"; return 0;}
    cout << "Match!";
    return 0;
}
