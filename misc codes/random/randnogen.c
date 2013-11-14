#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 100

int
main(int argc, char *argv[])
{
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    int n = atoi(argv[1]);

    if (argc == 3)
        srand((unsigned int) atoi(argv[2]));
    else
        srand((unsigned int) time(NULL));

    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", rand() % LIMIT);

    printf("\n\nhence over \n\n");
    return 0;
}
