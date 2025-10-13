#include "holberton.h"

int main(int argc, char *argv[]){
    int size1, size2;
    char *num1, *num2;
    char *result, *start, *end;
    int i, j, mult_cpt = 1, res_len;
    int product;
    char first_digit, second_digit, digit1, digit2;
    char *temp;
    // mult is 1 then 10 then 100 ...
    if (argc != 3){
        printf("Error\n");
        exit(98);
    }
    num1 = argv[1];
    num2 = argv[2];
    if (*num2 == '0' || *num1 == 0){
        printf("0\n");
    }
    

    if (checkIfNum(*num1) == 0 || checkIfNum(*num2) == 0){
        printf("Error\n");
        exit(98);
    }
        

    size1 = mystrlen(num1);
    size2 = mystrlen(num2);
    // creating array with the size of the product
    if (((*num1 - '0') * (*num2 - '0')) >= 10)
    {
        res_len = (size1 + size2);
        result = malloc(sizeof(char) * res_len + 1);
    }

    else
    {
        res_len = (size1 + size2 - 1);
        result = malloc(sizeof(char) * res_len + 1);
    }

    start = result;
    num2 = num2 + size2 - 1;
    if (checkIfNum(*num2) == 0){
        printf("Error\n");
        exit(98);
    }
    
    // going to the last index and replacing result with zeros
    temp = result;
    for (i = 0; i < res_len; i++){
        *temp = '0';
        temp = temp + 1;
    }
    *temp = '\0';
    //this points to the last digit (right) of result
    end = result + res_len;
    // main logic
    for (i = 0; i < size2; i++){
        num1 = num1 + size1 - 1;
        if (checkIfNum(*num1) == 0){
            printf("Error\n");
            exit(98);
        }
        result = end - mult_cpt;
        for (j = 0; j < size1; j++){
            product = (*num1 - '0') * (*num2 - '0');
            if (product > 9){
                first_digit =  (product % 10) + '0';
                second_digit =  (product / 10) + '0';
            }
            else{
                first_digit = product + '0';
                second_digit = '0';
            }
            if (((*result - '0') + (first_digit - '0')) >= 10){
                digit1 = (((*result - '0') + (first_digit - '0')) % 10) + '0';
                digit2 = (((*result - '0') + (first_digit - '0')) / 10) + '0';
                *result = digit1;
                *(result - 1) = (*(result - 1) - '0') + (digit2 - '0') + '0';

            }
            else
                *result = (*result - '0') + (first_digit - '0') + '0';

            if (result != start){
                *(result - 1) = (*(result - 1) - '0') + (second_digit - '0') + '0';
                result = result - 1;
            }
            if (j < size1 - 1)
                num1 = num1 - 1;
        }

        if (checkIfNum(*num2) == 0){
            printf("Error\n");
            exit(98);
        }
        num2 = num2 - 1;
        
        mult_cpt += 1;
    }
    print_string(result);
    free(result);
}

int mystrlen(char *mystring){
    int length = 0;

    while (*mystring != '\0'){
        length = length + 1;
        mystring = mystring + 1;
    }
    return(length);
}


void print_string(char *str){
    while (*str != '\0'){
        _putchar(*str);
        str = str + 1;
    }
    _putchar('\n');
}

int checkIfNum(char chr){
    if (chr < 48 || chr > 57)
        return (0);
    return (1);
}

