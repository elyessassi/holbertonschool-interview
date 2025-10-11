#include "holberton.h"

int main(int argc, char *argv[]){
    int size1, size2;
    char *num1, *num2, *res_str;
    int mult;
    int result = 0;
    int i, j, mult_cpt = 0;
    // mult is 1 then 10 then 100 ...

    if (argc != 3){
        _putchar('E'),
        _putchar('r'),
        _putchar('r'),
        _putchar('o'),
        _putchar('r'),
        exit(98);
    }
    num1 = argv[1];
    num2 = argv[2];

    size1 = mystrlen(num1);
    size2 = mystrlen(num2);
    // removing the \0

    for (i = size2 - 1; i >= 0; i--){
        mult = power(10, mult_cpt);
        for (j = size1 - 1; j >= 0; j--){
            result = result + ((*(num1 + j) - '0') * (*(num2 + i) - '0') * mult);
            mult = mult * 10;
        }
        mult_cpt = mult_cpt + 1;
    }
    res_str = turn_to_str(result, num_length(result));
    print_string(res_str);


}

int mystrlen(char *mystring){
    int length = 0;

    while (*mystring != '\0'){
        length = length + 1;
        mystring = mystring + 1;
    }
    return(length);
}

int power(int n, int x){
    int i, res = 1;

    if (x == 0)
        return(1);
    else if(x > 0){
        for (i = 0; i < x; i++){
            res = res * n;
        }
    }
    return(res);
}

int num_length(int num){
    int length = 0;

    while (num != 0){
        length = length + 1;
        num = num / 10;
    }
    return(length);
}

char *turn_to_str(int num, int size_num){
    char *temp = malloc(sizeof(char) * (size_num + 1));
    int i;
    *(temp + size_num) = '\0';
    temp = temp + (size_num - 1);

    for(i = 0; i < size_num; i++){
        *temp = (num % 10) + '0';
        temp = temp - 1;
        num = num / 10;
    }
    return(temp + 1);
}

void print_string(char *str){
    while (*str != '\0'){
        _putchar(*str);
        str = str + 1;
    }
}
