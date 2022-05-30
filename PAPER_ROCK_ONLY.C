#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    //unsigned int n;
    int ch=4,n,m,count=0,i=1;
    printf("Enter to Ramanath Paper Rock game\n");
    printf("===== == ======== ===== ==== ====\n");
    do
    {
        ram:printf("1.Paper\n");
        printf("2.Rock\n");
        printf("3.Exit\n");
        srand(time(NULL));
        n=rand()%3;
        m=rand()%6;
        n=(n+m)%8;
        //printf("%d",n);    
        if(i==1){i=0;
         printf("Let's start the game\n");}
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if(ch==3)
        {
            printf("End of the game\n");
            printf("Your score is: %d",count);
            return 0;
        }
        if(ch>3)
        {
            printf("Sorry you entered Incorrect option\n");
            printf("Here we have options from 1 to 3 only\n");
            goto ram;
        }
        if(n==0 || n==3 || n==6 || n==7)
        {
            if(ch==1)
            {
             count++;
             printf("Correct\n");
		    }
            else
            {
				//printf("%d\n",n);
             printf("Sorry,it's Paper\n");}
        }
        else
        {
            if(ch==2)
            {
            count++;
            printf("Correct\n");
            }
            else{//printf("%d*\n",n);
             printf("Sorry,it's Rock\n");}
        }
    }while(1);
    return 0;
    }
