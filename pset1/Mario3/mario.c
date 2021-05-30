#include <stdio.h>
#include <cs50.h>

int main(void){
    int height;
    int a = 0;

    do{
      height = get_int("Please determine your height\n");
    } while (height < 1 || height > 8);
    int o = height;
    while(height>a){
        a++;
        for (int i = height; i>a; i--){
            printf(" ");
        }
        for (int i =1; i<=a; i++){
            printf("#");

        }
        printf(" ");
        for(int j = 1; j<= a; j++){
            printf("#");
        }
            printf("\n");




}}
