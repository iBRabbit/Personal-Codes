#include "stdio.h"
#include "string.h"

void cal(char *pat, int M, int *f){
    int len = 0;
    f[0] = 0;
    int i = 1;
    while(i < M){
        printf("pat[i : %d] == pat[len : %d]\n", i, len);
        if(pat[i] == pat[len]){
            len++;
            f[i] = len;
            printf("i : %d f[%d] = %d\n", i, i, len);
            i++;
        }else{
            if (len != 0){
                len = f[len - 1];
                printf("if : %d\n", len);
            } else{
                f[i] = 0;
                printf("f[%d] : 0\n", i);
                i++;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    int f[100];
    cal("ABABABAB", strlen("ABABABAB"), f);
    printf("%d\n",f[5]);
    return 0;
}
