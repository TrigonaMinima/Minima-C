/*
Gives some solutions
backtracking needs to be applied.
*/


# include <stdio.h>

char board[50][50], solni[8], solnj[8];

void
disp(int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(board[i][j] == 'Q')
                printf(" Q ");
            else if(board[i][j] == 'x')
                printf(" x ");
            else
                printf(" 0 ");
        }
        printf("\n");
    }
}

int
cross(int b, int c, int n)
{
    int i, j;
    for(j=0; j<n; j++)
    {
        if(board[b][j] != 'Q')
            board[b][j] = 'x';
    }
    for(j=0; j<n; j++)
    {
        if(board[j][c] != 'Q')
            board[j][c] = 'x';
    }
    for(i=b+1; i<n; i++)
    {
        if( (c+i-b) < n  && board[i][c+i-b] != 'Q' )
            board[i][c+i-b] = 'x';
        if( (c-i+b) >= 0 && board[i][c-i+b] != 'Q' )
            board[i][c-i+b] = 'x';
    }
    for(i=b-1; i>=0; i--)
    {
        if( (c+i-b) < n && board[i][c+i-b] != 'Q' )
            board[i][c+i-b] = 'x';
        if( (c-i+b) >= 0 && board[i][c-i+b] != 'Q' )
            board[i][c-i+b] = 'x';
    }
}

int
func(int k, int n)
{
    int i, j, qcount=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            board[i][j] = ' ';
    }
    board[k][0] = 'Q';
    cross(k, 0, n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(board[i][j] != 'x')
            {
                board[i][j] = 'Q';
                cross(i, j, n);
/*                disp (n);
                printf("\n\n");*/
                qcount++;
            }
        }
    }
    // printf("---------\n");
    if (qcount != n+1)
        return 0;
    disp(n);
    printf("\n");
    return 1;
}

int
main()
{
    int n, i, j, count;
    printf("Enter n (>3) : ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        if(func(i, n))
            count++;
    }
    printf("\nTotal no of positions : %d\n", count);
    return 0;
}
