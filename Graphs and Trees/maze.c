/*Takes in the m and n of a maze and creates it adjacency matrix and then places some walls in the maze.
Then finds a path from one node to other using DFS.*/

# include <stdio.h>

#define s 20
int size = s;
static int maze[s][s];

todo: find the path
int DFS()
{
    return 0;
}

int vert_edge(int j, int m)
{
    int i;
    for(i=0; i < m; i++)
    {
        if(maze[j+i][j+i-m] == 1)
            printf(" |     ");
        else
            printf("       ");
    }
}

int path_disp(int m, int n)
{
    int i, j;
    for(i = 1; i <= size; i++)
    {
        printf("%2d", i);
        if(i % m == 0)
        {
            printf("\n");
            vert_edge(i, m);
            printf("\n");
        }
        else if(maze[i-1][i+1-1] == 1)
            printf(" ----");
        else
            printf("     ");
    }
    printf("\n");
}

int disp(int m, int n)
{
    int i, j;
    printf("\n");
    for(i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
}

int maze_generate(int m, int n)
{
    int i=0, j=0, a, b, c, d;
    for(i = 0; i < size; i++)
    {
        a = i + 1;
        b = i - 1;
        c = i + m;
        d = i - m;
        // printf("%d- ", i);
        if(a < size && a % m != 0)
        {
            maze[i][a] = 1;
            // printf("%d(a) ", a);
        }
        if(b >= 0 && (b+1) % m != 0)
        {
            maze[i][b] = 1;
            // printf("%d(b) ", b);
        }
        if(c < size)
        {
            maze[i][c] = 1;
            // printf("%d(c) ", c);
        }
        if(d >= 0)
        {
            maze[i][d] = 1;
            // printf("%d(d) ", d);
        }
    }
    todo: random walls
}

int main()
{
    int m, n, i, j;
    printf("Enter m : ");
    scanf("%d", &m);
    printf("Enter n : ");
    scanf("%d", &n);
    size = m * n;

    maze_generate(m, n);
    disp(m, n);
    printf("\n");

    path_disp(m, n);

    return 0;
}