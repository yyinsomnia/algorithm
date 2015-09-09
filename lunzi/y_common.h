#include <stdio.h>
#include <stdlib.h>

#define y_error(str)        y_fatal_error(str)
#define y_fatal_error(str)   fprintf(stderr, "%s\n", str), exit(1)

typedef int YElementType;