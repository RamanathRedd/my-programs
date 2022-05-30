#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main()
{
    int n,cn=0,cc=0,i,j;
    char name[20];
    void print(int i,int j,int cn,int cc,char name[20]);
    printf("Enter your name: ");
    scanf("%s",name);
    j=strlen(name);
    printf("Let's start our game Mr/Mrs %s\n",name);
    printf("===== ===== === ==== ====== ");
    for(i=0;i<j;i++)
     printf("=");
    printf("\n");
    do
    {
        printf("1.Paper\n");
        printf("2.Rock\n");
        printf("3.Scissors\n");
        printf("4.Exit\n");
        srand(time(NULL));
        n=rand()%9;
        printf("Enter your choice: ");
        scanf("%d",&i);
        if(i>5)
        {
            printf("You entered Incorrect choice\n");
            printf("Please,Check the menu which is given below.\n");
        }
        else 
        {
           switch(i)
           {
               case 1:if(n==0 || n==3 || n==6)
                      {
                         print(i,j,cn,cc,name); 
                      }
                      else if(n==1 || n==4 || n==7)
                      {
                          cn++;
                          print(i,j,cn,cc,name); 
                      }
                      else if(n==2 || n==5 || n==8)
                      {
                          cc++;
                          print(i,j,cn,cc,name); 
                      }
                      break;
                case 2:if(n==0 || n==3 || n==6)
                      {
                         cn++; 
                         print(i,j,cn,cc,name); 
                      }
                      else if(n==1 || n==4 || n==7)
                      {
                          print(i,j,cn,cc,name); 
                      }
                      else if(n==2 || n==5 || n==8)
                      {
                          cc++;
                          print(i,j,cn,cc,name); 
                      }
                      break;
                case 3:if(n==0 || n==3 || n==6)
                      {
                         cc++;
                         print(i,j,cn,cc,name); 
                      }
                      else if(n==1 || n==4 || n==7)
                      {
                          cn++;
                          print(i,j,cn,cc,name); 
                      }
                      else if(n==2 || n==5 || n==8)
                      {
                          print(i,j,cn,cc,name); 
                      }
                      break;
                case 4:printf("End of the game\n");
                       printf("Thanks for plaing Mr/Mrs %s\n",name);
                       printf("Your scores are:\n");
                       print(i,j,cn,cc,name);
                       printf("The match result is: ");
                       if(cn>cc)
                         printf("You won the game\n");
                       else if(cn<cc)
                         printf("Sorry,You loose the game\n");
                       else
                         printf("Matchdraw\n");
                       return 0;
                         
           }
        }
    }while(1);
}
void print(int i,int j,int cn,int cc,char name[20])
{
   printf("%s\t\t Computer\n",name); 
   for(i=0;i<j;i++)
      printf("=");
   printf("\t\t ========\n");
   printf("%d\t\t\t    %d\n",cn,cc);
}
