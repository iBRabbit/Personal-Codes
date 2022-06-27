#include "stdio.h"

int main()
{

    // CODE //

    printf("Hello World\n");
    printf("Nama saya Budi\n");

    // Tipe Data //

    // Declare Variable //
    int v; // Integer -> Bilangan bulat
    float f; // Float -> Bilangan Desimal
    double d; // Double -> Bilangan Desimal
    char c; // Char -> 'A', 'B', 'C' ,'D'
    char str[] = "Hallo Nama Saya Budi 2312313 ##### 12312031-dfqji2823yd8";
    
    // Set Value
    v = 10;
    f = 5.2; 
    d = 13.9;
    c = 'A'; // "A" tidak 'A'

    // Formatted Output //
    printf("%d \n", v);
    printf("%.2f \n", f);
    printf("%lf \n", d);
    printf("%c \n", c);
    printf("%s\n", str);

    

    return 0;
}