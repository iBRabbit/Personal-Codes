#include "stdio.h"
#include "string.h"

#define MAX_SIZE 99999

struct lift_data{
    int last_pos;
    int direction;
    int first_pos;
}arr[MAX_SIZE];

int main(int argc, char const *argv[])
{
    int N, M, T;

    scanf("%d %d", &N, &M); getchar();
    int arr2[N + 1];
    bool bol,bal;
    for(int i = 0; i < N; i++){
        int first_pos = 0;
        char direction[2];
        scanf("%d %s", &first_pos, direction); getchar();
        arr[i].first_pos = arr[i].last_pos = first_pos;
        if(strcmp(direction, "U") == 0) arr[i].direction = 1;
        else arr[i].direction = -1;
        arr2[i] = first_pos;
    }

    for(int i = 0; i < M * 5; i++){

//        printf("Detik ke - %d\n", i);
        bol = true;
        bal = true;
        for(int j = 0; j < N; j++){

            if((arr[j].last_pos == 1 && arr[j].direction == -1) || (arr[j].last_pos == M && arr[j].direction == 1))
                arr[j].direction *= -1;

            arr[j].last_pos += arr[j].direction;
            if(bol && arr[j].last_pos != arr2[j]) bol = false;
            if(bal && arr[0].last_pos != arr[j].last_pos) bal = false;
            
//            printf("%d %c\n", arr[j].last_pos, 'A' + j);
        }
        if(bal){
            printf("YES\n");
            return 0;
        }
        if(bol){
            printf("NO\n");
            return 0;
        }
    }

    return 0;
}