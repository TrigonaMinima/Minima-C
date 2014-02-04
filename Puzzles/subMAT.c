# include <stdio.h>
/*# include <conio.h>*/
# include <stdlib.h>
# include <time.h>

void
initialize( int arr[50][50], int s )
{
  int i, j;
  for(i=0; i<s; i++)
  {
    for(j=0; j<s; j++)
      arr[i][j] = rand()%2;
  }
}

void
disp(int d[50][50], int s)
{
  int i, j;
  for(i=0; i<s; i++)
  {
    for(j=0; j<s; j++)
    {
      if(d[i][j] == -1)
	    printf("* ");
      else
	    printf("%d ", d[i][j]);
    }
    printf("\n");
  }
}

int
find(int sArr[50][50], int ss, int mArr[50][50], int s)
{
  int i, j, k, l, count = 0 ;
  for(i=0; i<s-ss+1; i++)
  {
    for(j=0; j<s-ss+1; j++)
    {
      if(sArr[0][0] == mArr[i][j])
      {
	    if(subFind(i, j, mArr, sArr, ss))
	      count +=1;
      }
    }
  }
  return count;
}

int
subFind(int i, int j, int a[50][50], int b[50][50], int ss)
{
  int k, l;
  for(k=0; k<ss; k++)
  {
    for(l=0; l<ss; l++)
    {
      if(b[k][l] != a[i+k][j+l])
	    return 0;
    }
  }
  for(k=0; k<ss; k++)
  {
    for(l=0; l<ss; l++)
      a[i+k][j+l] = -1;
  }
  return 1;
}


int
main()
{
  int size, ssize, i, j;
  int a[50][50], b[50][50];
  time_t t;
  srand((unsigned) time(&t));
  system("clear");
/*  clrscr();*/
  printf("Enter the size of main array : ");
  scanf("%d", &size);
  initialize(a, size);
  disp(a, size);
  printf("Enter the size of sub matrix (<%d) : ", size);
  scanf("%d", &ssize);
  printf("enter the elements - \n");
  for(i=0; i<ssize; i++)
  {
    for(j=0; j<ssize; j++)
      scanf("%d", &b[i][j]);
  }
  disp(b, ssize);
  if(find(b, ssize, a, size))
  {
/*    printf("Subarray found !!\n");*/
    disp(a, size);
  }
  else
    printf("Subarray not found !!");
/*  getch();*/
  return 0;

}
