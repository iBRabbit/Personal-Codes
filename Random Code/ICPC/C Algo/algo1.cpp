#include "stdio.h"
#include "string.h"

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main(int argc, char const *argv[])
{
    char str[105], substr[105];
    char arr_substr[105][105], first_word[128], last_word[128];
    bool is_valid, idx_found;
    int T;
    
    scanf("%s", str); getchar();

    int idx = 0;
    int len = strlen(str);

    scanf("%d", &T); getchar();

    for(int i = 0; i < T; i++){
        scanf("%s",substr); getchar();
        strcpy(arr_substr[i], substr);
    }

    for(int i = 0; i < len; i++){
        if(str[i] == '*'){
            idx = i;
            break;
        }
    }    

    char *token = strtok(str, "*");
    int k = 0;
    while(token != NULL) {
        if(k == 0) strcpy(first_word, token);
        else strcpy(last_word, token);
        token = strtok(NULL, " ");
        k++;
    }

    int first_word_len = strlen(first_word);
    int last_word_len = strlen(last_word);
    // printf("%s %s\n", first_word, last_word);

    if(len == 1){
        for(int i = 0; i < T; i++)
            printf("%s\n", arr_substr[i]);
    }

    else if(idx == len - 1){
        for(int i = 0; i < T; i++){ 
            is_valid = true;
            for(int j = 0; j < idx; j++){
                if(str[j] == arr_substr[i][j]) continue;
                else is_valid = false;
            }

            if(is_valid) 
                printf("%s\n", arr_substr[i]);
            
        }
    }

    else if(idx == 0 && idx < len){
        char buffer[128], substr_buffer[128];
        strcpy(buffer, strrev(str));
        for(int i = 0; i < T; i++){
            is_valid = true;
            strcpy(substr_buffer,  strrev(arr_substr[i]));
            // printf("buffer %s | %s | %s \n", buffer, substr_buffer, arr_substr[i]);
            for(int j = 0; j < len - 1; j++){
                if(buffer[j] == arr_substr[i][j]) continue;
                else is_valid = false;      
            }

            if(is_valid) 
                printf("%s\n", strrev(arr_substr[i]));
        }
    }

    else if(idx > 0 && idx < len - 1){
        bool is_front_valid = true, is_back_valid = true;
        char buffer[128], substr_buffer[128];
        strcpy(buffer, strrev(last_word));
        strrev(last_word);
        // printf("%s\n", last_word);
        // printf("%s\n", first_word);
        for(int i = 0; i < T; i++){ 
            // printf("%s\n", arr_substr[i]);
            is_front_valid = true;

            for(int j = 0; j < first_word_len; j++){
                if(first_word[j] == arr_substr[i][j]) continue;
                else is_front_valid = false;
                // printf("----------->%c %c\n", first_word[j], arr_substr[i][j]);
            }

            is_back_valid = true;
            strcpy(substr_buffer,  strrev(arr_substr[i]));
            strrev(arr_substr[i]);
            // printf("buffer %s | %s | %s \n", buffer, substr_buffer, arr_substr[i]);
            for(int j = 0; j < last_word_len; j++){
                // printf("----------->%c %c\n", last_word[j], arr_substr[i][j]);
                if(buffer[j] == substr_buffer[j]) continue;
                else is_back_valid = false;      
            }

            // printf("%d %d\n",is_front_valid, is_back_valid);

            if(is_back_valid && is_front_valid)
                printf("%s\n", arr_substr[i]);          

        }

    }

    return 0;
}
