// Tree - array implementation

# include <stdio.h>
# include <math.h>

char tree[50];
int count=0;

void
insert(char ele)
{
        int i=0;
        printf("%d\n", count);
        if (count>1)
                i=count/2;

        while(tree[i-1] == ' ' && count > 1)
        {
                tree[count-1] = ' ';
                count++;
                i=count/2;
        }
        tree[count-1] = ele;

}

void
disp()
{
        int i;
        for(i=0; i<count; i++)
                printf("%c-", tree[i]);
        // printf("\n");
}

int
main()
{
        char ele;
        while(1)
        {
                printf("\nEnter the element : ");
                // scanf("%s", &ele);
                ele = getchar();
                getchar();
                fflush(stdout);
                fflush(stdin);
                if(ele == '\n')
                        ele = ' ';
                else if(ele == '1')
                        break;
                count++;
                insert(ele);
                disp();
                // printf("Enter the element -");
        }
        disp(count);
        return 0;
}