#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    string s;

    cout << "Введите строку:" << endl;
    getline(cin, s, '\n');

    int l = s.length();
    int spaces = 0;

    for (int i = 0; i < l; i++)
    {
        if (s[i] == ' ') spaces++;
    }

    cout << "Количество пробелов: "<< spaces;
}
