#include "stdio.h"

int main(int argc, char const *argv[])
{
    int testcase = 0;
    scanf("%d",&testcase); getchar();

    for(int i = 0; i < testcase; i++){
        int groups = 0;
        scanf("%d",&groups); getchar();

        // 1 | 3 | 2 4
        // 1 | 3 2 | 4
        // 1 3 | 2 | 4

        // 1 3 2 4 5
        // 1 | 3  | 2 4 5
        // 1 | 3 2 | 4 5
        // 1 | 3 2 4 | 5
        // 1 3 | 2 4 | 5
        // 1 3 2 | 4 | 5

        // 1 | 3  | 2  |4 5
        // 1 | 3 | 2 | 4 

    }

    return 0;
}
