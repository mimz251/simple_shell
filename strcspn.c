#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char str[] = "CODING IS AWESOME!";
    char decline[] = " ,!";

    size_t length = strcspn(str, decline);

    printf("Length of initial segment: %zu\n", length);

    return 0;
}
