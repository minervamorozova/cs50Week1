#include <stdio.h>
#include <cs50.h>
void card(long long int number);
long long int get_digit(long long int number, int position);
long long int power(long long int base, int power);

int main(void){
    long long int n;
    do{
         n = get_long("Number: ");
    }
    while (n<=0);
    card(n);
}

void card(long long int number){
    int position = 1;
    long long int buffer = 0;
    long long int buffer2 = 0;
    long long int base = power(10,position);
    while(number % base != number){
        long long int aux = 0;
        aux = get_digit(number, position);
        if(position % 2 == 0){
            aux *= 2;
            if(aux > 9){
                aux = aux % 10 ;
                aux++;
            }
            buffer += aux;
        }else{
            buffer2 += aux;

        }
        base = power(10,position);
        position++;
    }
    buffer += buffer2;
    position --;
    
    if(buffer % 10 == 0){
        long long int first = get_digit(number, position);
        long long int second = get_digit(number, position - 1);

        if(first == 4 && (position == 13 || position == 16)){
            printf("VISA\n");
        }else if(first == 3 && (second == 4 || second == 7) && (position == 15)){
            printf("AMEX\n");
        }else if(first == 5 && (second == 1 || second == 2 || second == 3 || second == 4 || second == 5) && (position == 16)){
            printf("MASTERCARD\n");
        }else{
            printf("INVALID\n");
        }
    }else{
        printf("INVALID\n");
    }
}

long long int get_digit(long long int number, int position){
    long long int buffer = 0;
    long long int aux = 0;
    buffer = number % power(10, position);
    if(buffer % power(10, position - 1) != 0 || buffer % power(10, position - 1) == 0){
        aux = (buffer - buffer % power(10, position - 1))/power(10, position - 1);
    }else{
        aux = buffer;
    }
    return aux;
}

long long int power(long long int base, int power){
    long long int buffer = 1;
    while(power > 0){
        buffer *= base;
        power--;
    }
    return buffer;
}
