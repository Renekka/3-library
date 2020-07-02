#include <iostream>
#include <locale>  
#include "class.h"

using namespace std;
int main()
{
    setlocale(0, "");

    DATA R;
    system("title Inform");
    bool menushka = true;
    R.files();
    int number;
    R.Menu();
    cin >> number;
    system("cls");
    while (menushka)
    {
        system("cls");
        switch (number)
        {
        case 0:
            R.REGION();
            cin.get();
            system("cls");
            R.Menu();
            cin >> number;
            break;
        case 1:
            R.Time();
            cin.get();
            system("cls");
            R.Menu();
            cin >> number;
            break;
        case 2:
            R.Space();
            cin.get();
            system("cls");
            R.Menu();
            cin >> number;
            break;
        case 3:
            R.Local_time();
            cin.get();
            system("cls");
            R.Menu();
            cin >> number;
            break;
        case 4:
            menushka = false;
            break;
        }
    }
    cin.get();
    return 0;
}
