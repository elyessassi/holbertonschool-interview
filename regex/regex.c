#include "regex.h"

/**
 * 
 * 
 */

int regex_match(char const *str, char const *pattern){

    if (pattern == NULL || str == NULL)
        return(0);
    
    if (*pattern == '\0' && *str == '\0')
        return(1);   

    if (*pattern == '\0' || *str == '\0'){
        return(0);
    }

    if (*pattern == '*')
        return(0);

    while (*str != '\0'){
        if (*pattern == '\0')
            return(0);

        if (*str == *pattern || *pattern == '.')
        {
            if (*(pattern + 1) != '*'){
                str = str + 1;
                pattern = pattern + 1;
            }
            else{
                while((*str == *pattern || *pattern == '.') && *str != '\0' && *str != *(pattern + 2)){
                    str = str + 1;
                }
                pattern = pattern + 2;
            }
        }
        else{
            if (*(pattern + 1) == '*')
                pattern = pattern + 2;
            else
                return(0);
        }
            
    }
    if (*pattern != '*' && *pattern != '\0')
        return(0);
    else
        return(1);
}   