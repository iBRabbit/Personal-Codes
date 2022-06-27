#include "iostream"
#include "stdlib.h"
using namespace std;

string generateID(){
    string id = "";
    int tempInt = rand();
    id = "EMP-" + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
    return id;
}

int arr[15] = {};

void printRandoms(int lower, int upper,int count) { 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % (upper - lower + 1)) + lower; 
        // arr[i] = num; 
        cout << num << endl; 
    } 
} 

int main(int argc, char const *argv[])
{
    system("cls");
    system("cls");

    // printRandoms(0,2,15);
    // for(int i = 0; i < 15; i++){
    //     // cout << arr[i] << endl;
    //     if(arr[i] == 0) cout << "Pagi " << endl;
    //     else if(arr[i] == 1) cout << "Siang " << endl;
    //     else if(arr[i] == 2) cout << "Malam" << endl; 

    // }

    // for(int i = 0; i < 15; i++){
        
    //     if(arr[i] == 0) cout << "06.00 - 12.00 " << endl;
    //     else if(arr[i] == 1) cout << "12.00 - 18.00" << endl;
    //     else if(arr[i] == 2) cout << "18.00 - 00.00" << endl; 
    // }

    printRandoms(1000000, 100000000, 15);

    return 0;
}


