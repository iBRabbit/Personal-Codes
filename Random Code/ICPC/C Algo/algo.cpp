#include "stdio.h"
#include "string.h"
#include "stdlib.h"

bool isPalindrome(char str[]){
    int counter = 0;        // 1
    int len = strlen(str); // 1
    int iterator = 0; // 1

    for(iterator = 0; iterator < len / 2; iterator++){ // (len / 2) + 1
        if(str[iterator] == str[len - iterator - 1]) // len / 2
            counter++;  // len / 2
    }

    return (counter == iterator) ? true : false; // 1

    // --------------------------------- time 
    // 1 + 1 + 1 + (len / 2) + (len / 2) + 1 // 
    // 4 + len
    // Misal len = n maka time complexitynya adalah O(n).
}

int main(int argc, char const *argv[])
{
    system("cls");
    char str[] = "xxx";
    printf("%d\n", isPalindrome(str));
    return 0;


    
}
