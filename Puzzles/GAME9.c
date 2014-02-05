# include <stdio.h>
# include <time.h>

char board[3][3]={{'1','2','3'},
		  {'4','5','6'},
		  {'7','8',' '}};

int si=2, sj=2;

void
disp()
{
  int i, j;
  printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t --- --- ---\n");
  for(i=0; i<3; i++)
  {
    printf("\t\t\t\t\t\t\t\t|");
    for(j=0; j<3; j++)
    {
      printf(" %c |", board[i][j]);
    }
    printf("\n\t\t\t\t\t\t\t\t --- --- ---");
    printf("\n");
  }
}

check()
{
  if(board[0][0] == '1' && board[0][1] == '2' && board[0][2] == '3' &&
     board[1][0] == '4' && board[1][1] == '5' && board[1][2] == '6' &&
     board[2][0] == '7' && board[2][1] == '8' )
    return 1;
  return 0;
}

void
move(char a)
{
  if(a=='w' && (si-1) >= 0)
  {
    board[si][sj] = board[si-1][sj];
    board[si-1][sj] = ' ';
    si--;
  }
  else if(a=='s' && (si+1) < 3)
  {
    board[si][sj] = board[si+1][sj];
    board[si+1][sj] = ' ';
    si++;
  }
  else if(a=='a' && (sj-1) >= 0)
  {
    board[si][sj] = board[si][sj-1];
    board[si][sj-1] = ' ';
    sj--;
  }
  else if(a=='d' && (sj+1) < 3)
  {
    board[si][sj] = board[si][sj+1];
    board[si][sj+1] = ' ';
    sj++;
  }
}

void
initiate() //0-w, 1-s, 2-d, 3-a
{
  int i=2, j=2, start, moves = 15;
  while(moves)
  {
      start=rand() % 4;
      if(start==0 && i!=0)
      {
	move('w');
      }
      else if(start==1 && i!=2)
      {
	move('s');
      }
      else if(start==2 && j!=2)
      {
	move('d');
      }
      else if(start==1 && j!=0)
      {
	move('a');
      }
      else
	continue;
      moves--;
  }
}

int
main()
{
  char mov;
  time_t t;
  //clrscr();

  srand((unsigned) time(&t));
  initiate();
  while(1)
  {
    //clrscr();
    system("clear");
    disp();
    if(check())
    {
	printf("\n\n\t\t\t\t\t\t\t\tGame Over");
	break;
    }
    printf("\n\t\t\t\t\tMove the blank tile (w/a/s/d)(e to exit) : ");
    scanf(" %c", &mov);
    while(1)
    {
      if(mov == 'w' ||  mov == 'a' || mov == 's' || mov == 'd' || mov == 'e')
        break;
      printf("\n\t\t\t\t\t\t\t\tIllegal move!!");
      printf("\n\t\t\t\t\tPlay your move(w/a/s/d)(e to exit) : ");
      scanf(" %c", &mov);
    }
    if(mov == 'e')
      break;
    move(mov);
    //getch();
  }
//  getch();
  return 0;
}
