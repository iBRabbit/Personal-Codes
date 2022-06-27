#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 3

using namespace std;

char arr[MAX][MAX] = {{}};
bool isOver = false;

void clearArray(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            arr[i][j] = '-';
    }
}

void printArray(){
    cout << "  1 2 3" << endl;
    for(int i = 0; i < MAX; i++){
        cout << i + 1 << " ";
        for(int j = 0; j < MAX; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void check(){
    int pointX = 0;
    int pointO = 0;
    
    string checker = "";
    char temp;
    bool isFull = true;

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(arr[i][j] == '-') isFull = false; 
        }
    }

    for(int i = 0 ; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            string s(1,arr[i][j]);
            checker.append(s);
        }


        if(checker.compare("XXX") == 0){
            cout << "X WIN!" << endl;
            isOver = true;
            return;
        } else if(checker.compare("OOO") == 0){
            cout << "O WIN!" << endl;
            isOver = true;
            return;
        }
        checker = "";
    }
    
    checker = "";
    for(int i = 0; i < MAX; i++){

        for(int j = 0; j < MAX; j++){
            string s(1,arr[i][j]);
            checker.append(s);
        }

        if(checker.compare("XXX") == 0){
            cout << "X WIN!" << endl;
            isOver = true;
            return;
        } else if(checker.compare("OOO") == 0){
            cout << "O WIN!" << endl;
            isOver = true;
            return;
        }
        checker = "";
    }

    if(arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X'){
        cout << "X WIN!" << endl;
        isOver = true;
        return;
    } else if(arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O'){
        cout << "O WIN!" << endl;
        isOver = true;    
        return;
    }

    if(arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X'){
        cout << "X WIN!" << endl;
        isOver = true;
        return;
    } else if(arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O'){
        cout << "O WIN!" << endl;
        isOver = true;
        return;
    }


    if(isFull == true){
        cout << "Draw!" << endl;
        isOver = true;
        return;
    }

}

int main(int argc, char const *argv[])
{
    system("cls");
   
    int turner = 0;

    clearArray();
    

    do{
        system("cls");
        printArray();
        char playerTurn = 'X';
        int coordX, coordY;

        if(turner % 2 == 0) playerTurn = 'X';
        else playerTurn = 'O';

        cout << "Giliran pemain " << playerTurn << " Untuk Jalan." << endl;
        cout << "=================================================" << endl;

        do{

            cout << "Enter X Coordinate : ";
            cin >> coordX;
            cout << "Enter Y Coordinate : ";
            cin >> coordY;

            if(arr[coordY - 1][coordX - 1] != '-') cout << "Tempat sudah terisi!" << endl;
            if(coordX > 3 || coordY > 3 || coordX < 0 || coordY < 0) cout << "Input nilai 0 <= x,y <= 3!" << endl;

        } while(arr[coordY - 1][coordX - 1] != '-' || coordX > 3 || coordY > 3 || coordX < 0 || coordY < 0);


        arr[coordY - 1][coordX - 1] = playerTurn;
        system("cls");
        printArray();
        check();
        
        turner++;   
    } while (!isOver);


    return 0;
}
