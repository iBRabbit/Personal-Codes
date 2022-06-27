#include "iostream"
#include "string.h"

using namespace std;

struct Data{
    char username[9999];
    long long int balance;
}data[50000];


void swapStructs(int a, int b){
    struct Data temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

void bubbleStrAsc(int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1 - i; j++){
            if(strcmp(data[j].username, data[j + 1].username) > 0) 
                swapStructs(j, j + 1);
        }
    }
}

long long int getIndexByUsername(char username[], int N){
    for(int i = 0; i < N; i++){
        if(strcmp(username, data[i].username) == 0)
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    
    int N, T;
    
    cin >> N >> T;

    for(int i = 0; i < N; i++)
        cin >> data[i].username >> data[i].balance;

    for(int i = 0; i < T; i++){
        char tmpUsername1[9999], tmpUsername2[9999];
        long long int transferVal, userIdx1, userIdx2;

        cin >> tmpUsername1 >> tmpUsername2 >> transferVal;

        bubbleStrAsc(N);

        if(strcmp(tmpUsername1, tmpUsername2) == 0)
            continue;

        userIdx1 = getIndexByUsername(tmpUsername1, N);
        userIdx2 = getIndexByUsername(tmpUsername2, N);

        if(userIdx1 == -1 || userIdx2 == -1)
            continue;

        if(data[userIdx1].balance < transferVal)
            continue;

        data[userIdx1].balance -= transferVal;
        data[userIdx2].balance += transferVal;
    }

    for(int i = 0; i < N; i++)
        cout << data[i].username << " " <<data[i].balance << endl;
    return 0;
}
