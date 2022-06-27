#include "iostream"
#include "string"
#include "cstring"

using namespace std;

bool isPalindrome(string str){
    int counter = 0;        
    int len = str.length(); 
    int iterator = 0; 

    for(iterator = 0; iterator < len / 2; iterator++){ 
        if(str[iterator] == str[len - iterator - 1]) 
            counter++; 
    }

    return (counter == iterator) ? true : false; 
}


char str[1005];
char buffStr[1005];

int main(int argc, char const *argv[])
{
    cin >> str; 

    int len = strlen(str);
    int k = 0;
    bool isPrinted = false;

    for(int i = 0; i < len; i++){
        
        char substr1[1005] = {};
        char substr2[1005] = {};
        k = 0;

        for(int j = 0; j <= i; j++)
            substr1[j] = str[j];
        
        for(int j = i + 1; j <= len ; j++){
            substr2[k] = str[j]; 
            k++;
        }
        
        if(!isPrinted){
            if(isPalindrome(substr1) && isPalindrome(substr2) && (strlen(substr1) != len && strlen(substr2) != len)) {
                isPrinted = true;
                cout << substr1 << " " << substr2 << endl;
            }
        }

    }
    
    if(!isPrinted) 
        cout << "NO" << endl;

    return 0;
}
