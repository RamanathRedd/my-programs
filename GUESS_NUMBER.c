#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void success()
{
    printf("Congratulations!You did it\n");
}
void unsuccess()
{
    printf("You should have gotten it by now\n");
    printf("Better luck next time\n");
}
void print(int n)
{
    printf("Sorry, The number was %d\n",n);
}
int main()
{
    int n,i,lower=1,upper=20,count=1;
    srand(time(NULL));
    n=(rand()%(upper-lower+1))+lower;
    //printf("%d\n",n);
    printf("I am thinking of a number between  1 to 20:\n");
    printf("Can you guess what it is?\t ");
    scanf("%d",&i);
    while(count!=5)
    {
		count++;
        if(i<n)
        {
            printf("Your guess is low. Try again :\t ");
            scanf("%d",&i);
            continue;
        }
        else if(i>n)
        {
            printf("Your guess is high. Try again :\t ");
            scanf("%d",&i);
            continue;
        }
        else if(i==n)
        {
            success();
            return 0;
        }
    }
    if(count==6)
     {
         print(n);
         unsuccess();
     }
}
