# include <stdio.h>

int board[50][50];

int
check(int i, int j, int size)
{
    if(i < 0)
        i=size-1;
    if(j >= size)
        j=0;
    if(board[i][j] > 0)
        return 1;
    return 0;
}

int
find(int ele, int size)
{
    int i, j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(board[i][j] == ele)
                return 1;
        }
    }
    return 0;
}

void
initOdd( int size )
{
    int i=0, j=size/2, count=1;
    board[i][j] = count;
    count++;
    i--;
    j++;
    while(1)
    {
        if(check(i, j, size) == 0)
        {
            if(i < 0)
                i=size-1;
            if(j >= size)
                j=0;
            board[i][j] = count;
            i--;
            j++;
        }
        else
        {
            i+=2;
            j--;
            board[i][j] = count;
            i--;
            j++;
        }
        if(count > size*size-1)
            break;
        count++;
    }
}

void
initEven( int size )
{
    int i, j, count=1, val=size*size-1;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if( i == j || (size-i-1) == j)
                board[i][j] = count;
            count++;
        }
    }
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if( i != j && (size-i-1) != j)
            {
                while(find(val, size) == 1)
                    val--;
                board[i][j] = val;
                val--;
            }
        }
    }
}

int
disp( int size )
{
    int i, j;
    printf("\nThe magic Square is -\n");
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
            printf(" %3d ", board[i][j]);
        printf("\n\n");
    }
}

int
main()
{
    int a;
    printf("Enter the size : ");
    scanf("%d", &a);
    if(a%2 == 0)
        initEven(a);
    else
        initOdd(a);
    disp(a);
    return 0;
}
