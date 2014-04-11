# include "minDis.h"
 
int main()
{
        int i, j, k, l, len, nPerms, max;
        int *univ, **perm, **pos, **count;
        int *averg, *result1, *result2, *result3, *final;
        float avg=0, min;

        printf("\nEnter size of array: ");
        scanf("%d", &len);
        printf("\nEnter number of permutations to take: ");
        scanf("%d", &nPerms);

        // Memory allocation of arrays.
        {       
                        univ = (int *)malloc(len * sizeof(int));
                        averg = (int *)malloc(len * sizeof(int));                       // sum array
                        result1 = (int *)malloc(len * sizeof(int));                     // result by mean
                        result2 = (int *)malloc(len * sizeof(int));                     // result by count
                        result3 = (int *)calloc(len , sizeof(int));                     // result by graph

                        perm = (int **)malloc(nPerms * sizeof(int *));          // string matrix
                        for (i = 0; i < nPerms; i++)
                                perm[i] = (int *)malloc(len * sizeof(int));

                        pos = (int **)malloc(nPerms * sizeof(int *));           // positional matrix
                        for (i = 0; i < nPerms; i++)
                                pos[i] = (int *)malloc(len * sizeof(int));

                        count = (int **)calloc(len, sizeof(int *));                     // count matrix
                        for (i = 0; i < len; i++)
                                count[i] = (int *)calloc(len, sizeof(int));
        }

        // Generation of strings and their positional matrix and displaying them
        {
                        randomAr(len, nPerms, perm);                                // Generating random strings.

                        printf("\n");
                        for (i = 0; i < nPerms; i++)                                    // Display the random strings
                        {
                                printf("Permutation array %d\t: ", i+1);
                                display(perm[i], len);
                        }

                        for (i = 0; i < nPerms; i++)                                    // Determinimg the positional matrix
                                posMat(len, perm[i], pos[i]);

                        // printf("\n");                                                           // Display of positional matrix
                        // for (i = 0; i < nPerms; i++)
                        // {
                        //         printf("Positional array  %d\t: ", i+1);
                        //         display(pos[i], len);
                        // }
        }

        // mean calculation
        {
                        printf("\n");
                        for (j = 0; j < len; j++)                                          // Calculating mean
                        {
                                avg=0;
                                for (i = 0; i < nPerms; i++)
                                       avg+= pos[i][j];
                                averg[j] = avg;
                                // printf("%f - %f\n", avg, avg/nPerms);
                        }
        }

        // printf("The result1ant array (result1) : ");
        finalMat(len, averg, result1);                                  // result1 - result by mean
        // printf("\n");

        // printf("The positional resultlant array : ");
        posMat(len, result1, univ);                                     // Positional array of result1
        // display(univ, len);

        // printf("\n");
        avg=0;
        for (i = 0; i < nPerms; ++i)                                    // Dist from the result1
                avg+=dist(len, nPerms, pos[i], univ);
        avg/= (len*nPerms*len);
        avg*=2;
        // printf("%f", avg);
        min = avg;
        final = result1;

        countInd(len, nPerms, perm, count);                          // Determinimg the count matrix

        // printf("\n");                                                              // Display of count matrix
        // for (i = 0; i < len; i++)
        // {
        //         printf("count array  %d\t: ", i+1);
        //         display(count[i], len);
        // }

        // calculation of result 2 by counting and display it (result2)
        {
                        // printf("\n");
                        for (i = 0; i < len; ++i)                                               // result2 - result by count
                        {
                                max = 0;
                                k=0;
                                for(j=0; j<len; j++)
                                {
                                        if (count[j][i] > 1 && max <= count[j][i])
                                        {
                                                max = count[j][i];
                                                k=j;
                                        }
                                }
                                if(max==1 || max==0)
                                        continue;
                                for(j=0; j<len; j++)
                                {
                                        l=i;
                                        if(max < count[k][j])
                                        {
                                                max = count[k][j];
                                                l=j;
                                        }
                                }
                                // printf("%d-%d-%d\n", max, k+1, l);
                                result2[l] = k+1;
                                for(j=0; j<len; j++)
                                        count[k][j] = -1;
                                // for (j = 0; j < len; j++)
                                //         display(count[j], len);
                                // printf("\n\n");
                        }
                        j=0;
                        for(i=0; i<len; i++)
                        {
                                // printf("%d\n", count[i][0]);
                                if(count[i][0] >= 0)
                                {
                                        while(result2[j] != 0)
                                                j++;
                                        result2[j] = i+1;
                                        // printf("  asdhak  %d\n", result2[j]);
                                }
                        }

                        // printf("\n");
                        // printf("The result1ant array (result2) : ");                              // result2
                        // display(result2, len);
                        // printf("\n");
        }

        posMat(len, result2, univ);                                     // positional array of the result2

        // printf("\n");
        avg=0;
        for (i = 0; i < nPerms; ++i)                                    // Dist from the result2
                avg+=dist(len, nPerms, pos[i], univ);
        avg/= (len*nPerms*len);
        avg*=2;
        // printf("%f", avg);
        if (min > avg)
        {
                min = avg;
                final = result2;
        }

        // calculation of result 3 by graphical method
        {
                        for (j = 0; j < len; j++)
                        {
                                for(l=0; l<len; l++)
                                        count[j][l] = 0;
                        }                
                        countInd(len, nPerms, pos, count);                          // Determinimg the count matrix
                        // printf("\n");                                                              // Display of count matrix
                        // for (j = 0; j < len; j++)
                        // {
                        //         printf("count array  %d\t: ", j+1);
                        //         display(count[j], len);
                        // }
                        for (i = 0; i < len; i++)
                        {
                                avg=0;
                                l=0;
                                k=-1;
                                max=0;
                                for(j=0; j<len; j++)
                                {
                                        if(count[j][i] > 0)
                                        {
                                                avg+=j+1;
                                                l++;
                                        }
                                        if(count[j][i] > 1 && max <= count[j][i])
                                        {
                                               max = count[j][i];
                                               k=j;
                                       }
                                }
                                l=avg/l;
                                if(k<=l && l>0)
                                {
                                        l--;
                                        while(result3[l] != 0)
                                                l--;
                                        result3[l] = i+1;
                                        univ[i] = l;
                                }
                                else if (k>=l && l<len)
                                {
                                        l++;
                                        while(result3[l] != 0)
                                                l++;
                                        result3[l] = i+1;
                                        univ[i] = l;
                                }
                        }
                        k=1;
                        for (i = 0; i < len; i++)
                        {
                                if (result3[i] == 0)
                                {
                                        for (j = 0; j < len; j++)
                                        {
                                                if(k == result3[j])
                                                {
                                                        k++;
                                                        j=0;
                                                }
                                        }
                                        result3[i] = k;
                                        univ[k-1] = i+1;
                                }
                        }
                        // printf("The result1ant array (result3) : ");
                        // display(result3, len);
        }

        // printf("\n");
        avg=0;
        for (i = 0; i < nPerms; ++i)                                    // Dist from the result3
                avg+=dist(len, nPerms, pos[i], univ);
        avg/= (len*nPerms*len);
        avg*=2;
        // printf("%f", avg);
        if (min > avg)
        {
                min = avg;
                final = result3;
        }

        // printf("\n\n");
        j=0;
        while(j<nPerms)                                                      // Dist of the each permutation from other permutations
        {
                        avg=0;
                        for (i = 0; i < nPerms; ++i)
                                avg+=dist(len, nPerms, pos[i], pos[j]);
                        avg/= (len*nPerms*len);
                        avg*=2;
                        // printf("%f", avg);
                        // printf("\n");
                        if (min > avg)
                        {
                                min = avg;
                                final = perm[j];
                        }
                        j++;
        }
        // printf("\n");

        printf("The final array\t: ");                                           //  final result
        display(final, len);
        printf("The final dist\t:  ");                                           //  final result
        printf("%f\n", min);

        return 0;
}