# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int
randomAr(int len, int perm, int **arr1)                      // generates random arrays
{
        srand(time(0));
        int i, j, rnd, *univ;
        univ = (int *)malloc(len * sizeof(int));
        for (i = 0; i < len; i++)
                univ[i] = i+1;
        for (i = 0; i < perm; i++)
        {
                for (j = 0; j < len; j++)
                {
                        rnd = (j == 0) ? 0 : (rand() % (j+1));
                        if (rnd != j)
                                arr1[i][j] = arr1[i][rnd];
                        arr1[i][rnd] = univ[j];
                }
        }
}

void
display( int *arr, int len)                                          // displays a single array
{
        int i;
        for (i = 0; i < len; i++)
                printf("%2d ", arr[i]);
        printf("\n");
}

void
posMat(int len, int *arr, int *pos)                             // determines the positions
{
        int i, j;
        for (i = 0; i < len; i++)
        {
                for(j = 0; j < len; j++)
                {
                        if (i+1 == arr[j])
                                break;
                }
                pos[i] = j+1;
        }
}

void
finalMat(int len, int *sum, int *fin)                           // mapping of sum array into the resultant array
{
        int i, j, k, min;
        k=0;
        while(k < len)
        {
                min = sum[0];
                for(i=0; i < len; i++)
                {
                        if(sum[i] > 0)
                        {
                                min = sum[i];
                                break;
                        }
                }
                for(i=0; i < len; i++)
                {
                        if (sum[i] > 0 && min >= sum[i])
                        {
                                min = sum[i];
                                j=i;
                        }
                }
                sum[j] = -1;
                fin[k] = j+1;
                k++;
                // printf("\n");
                // display(sum, len);
                // printf("\n");
        }
        // printf("\n");
        // display(fin, len);
}

float
dist(int perm, int len, int *pos, int *fin)                     // calculates the dist b/e 2 arrays
{
        int i, a, sum=0;
        for (i = 0; i < len; i++)
        {
                a = pos[i]-fin[i];
                if(a < 0)
                        sum+= a * -1;
                else
                        sum+=a;
        }
        // printf("%2d  ", sum);
        return sum;
}

void
countInd(int len, int perm, int **arr, int **count)        // makes the count matrix
{
        int i, j;
        for (i = 0; i < len; i++)
        {
                for (j = 0; j < perm; j++)
                        count[ arr[j][i]-1 ][i]+=1 ;
                // display(count[i], len);
        }
}