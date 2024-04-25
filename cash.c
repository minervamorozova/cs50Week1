#include <stdio.h>
#include <cs50.h>
void change(int cash);
int main(void){
    int n;
    do{
         n = get_int("Change owed: ");
    }
    while (n<=0);
    change(n);
}

void change(int cash){
    int coins = 0;
    while(cash > 0){
        if(cash >= 25){
            cash-=25;
            coins++;
        }else if(cash >= 10){
            cash-=10;
            coins++;
        }else if(cash >= 5){
            cash-=5;
            coins++;
        }else if(cash >= 1){
            cash-=1;
            coins++;
        }
    }
    printf("%i\n",coins);
}
