#ifndef SLIDE_LINE
#define SLIDE_LINE

#include <stddef.h>

int slide_line(int *line, size_t size, int direction);
int main(int ac, char **av);

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1


#endif