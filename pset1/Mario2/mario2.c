#include <stdio.h>
#include <cs50.h>

int main(void){
    int height;

    do{
      height = get_int("Please determine your height\n");
    } while (height < 1 || height > 8);
    int o = height;
    for (int i =1; i<=height; i++){
        while (o > 0){
                printf(" ");
                o--;
            }
        for(int j = 1; j<= height; j++){



            if (i>=j){
            printf("#");
            }
        }
        printf("\n");
        o = height;
    }




}