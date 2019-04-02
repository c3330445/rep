	#include <stdio.h>
float Caesar( char c , int key); 
int main()
{
    char c; // numerical value for letter
    int key; // how much c will chift by
    float result; // numerical value of c after it's been shifted
    printf("enter value: "); // value for c (symbol)
    scanf("%c" , &c);
    printf("enter key value: "); // value for key (how much c will shift by)
    scanf("%d" , &key);
    result = Caesar( c , key); 
    printf("%f\n" , result);  
}
float Caesar(char c , int key)
{
    float result;
    c = c - 65;
    key = key + 65;
    result = c + key;
    return result;
}