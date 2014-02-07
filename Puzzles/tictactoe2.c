/*user vs computer*/
/*Can't handle special moves*/

# include <stdio.h>
# include <stdlib.h>
/*# include <conio.h>*/

char board[9] = {'1','2','3','4','5','6','7','8','9'};


/*Check for the win*/
char
check(char op, int mov)
{
  int i;
  if((board[0] == op && board[1] == op && board[2] == op ) ||
     (board[3] == op && board[4] == op && board[5] == op ) ||
     (board[6] == op && board[7] == op && board[8] == op ) ||

     (board[0] == op && board[3] == op && board[6] == op ) ||
     (board[1] == op && board[4] == op && board[7] == op ) ||
     (board[2] == op && board[5] == op && board[8] == op ) ||

     (board[0] == op && board[4] == op && board[8] == op ) ||
     (board[6] == op && board[4] == op && board[2] == op ))
       return op;
    else
      return 'A';
}


/*Plays the move*/
void
play_move(int move, char op)
{
  board[move-1] = op;
}


/*Move played by the computer (AI part)*/

int
chkchk(char f, char a[3])
{
  int i;
  if( a[0] == f && a[1] == f && (a[2] != 'X' && a[2] != '0'))
    return a[2]-48;
  else if ( a[0] == f && a[2] == f && (a[1] != 'X' && a[1] != '0'))
    return a[1]-48;
  else if ( a[1] == f && a[2] == f && (a[0] != 'X' && a[0] != '0'))
    return a[0]-48;
  else
    return -1;
}


int
comp_move(char a, char b)
{

  char flag = a, d[3];
  int j=0, c;
/*  attack*/
  for(j=0; j<3; j++)
  {
    d[0] = board[j*3];
    d[1] = board[j*3+1];
    d[2] = board[j*3+2];
    if((c = chkchk(flag, d)) >= 0)
      return c;
  }
  for(j=0; j<3; j++)
  {
    d[0] = board[j];
    d[1] = board[j+3];
    d[2] = board[j+6];
    if((c = chkchk(flag, d)) >= 0)
      return c;
  }
  for(j=0; j<2; j++)
  {
    d[0] = board[j*2];
    d[1] = board[4];
    d[2] = board[j*(-2)+8];
    if((c = chkchk(flag, d)) >= 0)
      return c;
  }

/*defence  */
  flag = b;
  for(j=0; j<3; j++)
  {
    d[0] = board[j*3];
    d[1] = board[j*3+1];
    d[2] = board[j*3+2];
    if((c = chkchk(flag, d)) >= 0)
      return c;
  }
  for(j=0; j<3; j++)
  {
    d[0] = board[j];
    d[1] = board[j+3];
    d[2] = board[j+6];
    if((c = chkchk(flag, d)) >= 0)
      return c;
  }
  for(j=0; j<2; j++)
  {
    d[0] = board[j*2];
    d[1] = board[4];
    d[2] = board[j*(-2)+8];
    if((c = chkchk(flag, d)) >= 0)
      return c;
  }
/*random move */
  while(1)
  {
    c = rand()%5;
    switch(c)
    {
      case 1 :
              c = 2;
              break; 
      case 2 :
              c = 6;
              break;
      case 3 :
              c = 8;
              break;
      case 4 :
              c = 4;
              break;
    }
    if(board[c] != 'X' && board[c] != '0')
      break;
  }
  return c+1;
}


/*Asks for the user's position.*/
int
askPos()
{
  int pos;
	printf("\nYour move : ");
	scanf("%d", &pos);
	while(1)
	{
	  if(board[pos-1] == 'X' || board[pos-1] == '0' || pos > 9)
	  {
	    printf("\nEnter valid  position : ");
	    scanf("%d", &pos);
	  }
	  else
	    break;
	}
	return pos;
}


/*Displays the grid.*/
void
disp()
{
  int i, j;
  printf("\t\t\t\t\t\t\t\t\t --- --- --- \n\t\t\t\t\t\t\t\t\t");
  for(i=1; i<=9; i++)
  {
    if(i%3 != 0)
    {
      printf("| %c ", board[i-1]);
    }
    else
     printf("| %c |\n\t\t\t\t\t\t\t\t\t --- --- --- \n\t\t\t\t\t\t\t\t\t", board[i-1]);
  }
}


int
main()
{
  srand(0);
  int comp, move=0, flag=' ';
  char c, ch;
  printf("\nDo you wan't to play first ? (y/n)\n");
  scanf(" %c", &ch);
  while(1)
  {
    system("clear");
    disp();
    c = check(flag, move);
    if((c == 'X' || c == '0') && move > 4 )
    {
      if(c == 'X')
      {
	    printf("\n Computer WINS!\n");
	    printf("\n You LOST!\n");
      }
      else
      {
	    printf("\n You WON!\n");
	    printf("\n Computer LOSES!\n");
      }
      break;
    }
    if(move == 9)
    {
      printf("\n DRAW!\n");
      break;
    }
    while(move+1)
    {
      if(ch == 'n')
      {
        if((move+1)%2 == 0)
        {
	        flag = '0';
	        play_move(askPos(), flag);
	        break;
        }
        else
        {
	        flag = 'X';
	        comp = comp_move('X', '0');
	        printf("\nComputer played at : %d\n", comp);
	        play_move(comp, flag);
	        break;
        }
      }
      else
      {
        if((move+1)%2 == 0)
        {
	        flag = 'X';
	        comp = comp_move('X', '0');
	        printf("\nComputer played at : %d\n", comp);
	        play_move(comp, flag);
	        break;
        }
        else
        {
	        flag = '0';
	        play_move(askPos(), flag);
	        break;
        }
      }

    }
    move++;
  }
/*  getch();*/
  return 0;
}
