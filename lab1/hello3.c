#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char name[100];
    int rand_num;
    int i;
 
    srand(time(0));
    rand_num = rand() % 10;
    printf("Enter your name: ");
    scanf("%99s", name);
    if ( rand_num % 2 == 0){
        for( i = 0; i < rand_num; i++ ){
             printf("Hello, %s!\n", name);
        }
    }
    else{    
        for( i = 0; i < rand_num; i++ ){
            printf("Hi there, %s!\n", name);
        }
    }
    return(0);
}
