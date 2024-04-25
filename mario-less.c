#include <stdio.h>
#include <cs50.h>
void print_row(int spaces, int bricks);
int main(void){
    int n;
    do{
         n = get_int("Height: ");
    }
    while (n<1);

    for(int i = 1; i <= n; i++){
        print_row(n-i, i);
    }
}

void print_row(int spaces, int bricks){
    while(spaces > 0){
        printf(" ");
        spaces--;
    }

    for(int j = 1; j <= bricks; j++){
        printf("#");
    }
    printf("\n");
}