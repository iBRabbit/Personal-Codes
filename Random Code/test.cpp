#include "stdio.h"
#include "string.h"
#include "ctype.h"

int GetLastNameIndex(char name[]) {
    int len = strlen(name);

    for(int i = 0; i < len; i++) 
        if(name[i] == '_') return i + 1;

    return -1;
}

bool IsNotAlphabetic(char name[]) {

    bool result = false;

    if((name[0] >= 'a' && name[0] <= 'z') || (name[0] >= 'A' && name[0] <= 'Z')) {
        printf("exit 1\n");
        result = false;
    } else result = true;
        
    if(!result) {
        if((name[GetLastNameIndex(name)] >= 'a' && name[GetLastNameIndex(name)] <= 'z') || name[GetLastNameIndex(name)] >= 'A' && name[GetLastNameIndex(name)] <= 'Z')
            result = false;
        else result = true;
        printf("masuk\n");
    }


    return result;
}

bool IsNameCapsProper(char str[]) {
    bool result = false;
    int lastNameIdx;

    if(str[0] >= 'A' && str[0] <= 'Z') {
        lastNameIdx = GetLastNameIndex(str);
        if(str[lastNameIdx] >= 'A' && str[lastNameIdx] <= 'Z')
            result = true;
    } 

    return result;
}

char *FixNameCaps(char str[]) {
    int lastNameIdx = GetLastNameIndex(str);
    str[0] = toupper(str[0]);
    str[lastNameIdx] = toupper(str[lastNameIdx]);
    return str;
}

int main(int argc, char const *argv[])
{
    
    char str[128];
    scanf("%s",str); getchar();

    printf("%d\n", IsNameCapsProper(str));
    printf("%s\n", FixNameCaps(str));
    printf("%d\n", IsNotAlphabetic(str));
    return 0;
}
