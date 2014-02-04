/*user vs user*/

# include <stdio.h>
/*# include <conio.h>*/

char board[9] = {'1','2','3','4','5','6','7','8','9'};


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

void
play_move(int move, char op)
{
  board[move-1] = op;
}

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
  int user1, user2, move=0, flag=' ';
  char c;
  while(1)
  {
/*    clrscr();*/
    system("clear");
    disp();
    c = check(flag, move);
    if((c == 'X' || c == '0') && move > 4 )
    {
      if(c == 'X')
      {
	    printf("\n Player1 WINS!\n");
	    printf("\n Player2 LOSES!\n");
      }
      else
      {
	    printf("\n Player2 WINS\n");
	    printf("\n Player1 LOSES!\n");
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
      if((move+1)%2 == 0)
      {
	    printf("\nPosition for P2 : ");
	    scanf("%d", &user2);
	    while(1)
	    {
	      //continue;
	      if(board[user2-1] == 'X' || board[user2-1] == '0')
	      {
	        printf("\nEnter valid  position : ");
	        scanf("%d", &user2);
	      }
	      else
	        break;
	    }
	    flag = '0';
	    play_move(user2, flag);
	    break;
      }
      else
      {
	    printf("\nPosition for P1 : ");
	    scanf("%d", &user1);
	    while(1)
	    {
	      if(board[user1-1] == 'X' || board[user1-1] == '0' || user1 > 9)
	      {
	        printf("\nEnter valid  position : ");
	        scanf("%d", &user1);
	      }
	      else
	        break;
	    }
	    flag = 'X';
	    play_move(user1, flag);
	    break;
      }
    }
    move++;
  }
/*  getch();*/
  return 0;
}
