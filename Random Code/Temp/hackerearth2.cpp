#include "iostream"
#include "stdlib.h"

using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    int testcase = 0; 
    cin >> testcase;

    for(int i = 1; i <= testcase; i++){
        string typeSeat = "";
        int seat = 0;
        
        cin >> seat; 

        bool isUnder = true;

        if(seat % 4 == 0 || seat == 1 || (seat - 1) % 4 == 0) isUnder = true;
        else isUnder = false;

        cout << isUnder << endl;
        printf("Hello World\n");
        
    }

    return 0;
}