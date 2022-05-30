/*ATM MACHINE AND IT'S SOME SMALL FUNCTIONS*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
  int a[4]={1,2,3,4},mo[10]={9,3,9,1,2,3,3,9,6,9},u[10],b[4],ch,i,amt=50000,dep,with,num,lower=1000,upper=9999,uo[4],o[4],N2K,N5,N2,N1;
  void pin(int a[4],int b[4],int i);/*CHECKING THE PIN IS CORRECT OR NOT IF NOT REQUEST TO ENTER AGAIN*/
  void display_rec(int amt);/*TO PRINT ACO,ACOLDER AND AMOUNT PRESENT IN THE ACCOUNT AS IT AS AN RECIEPT*/
  void display_notes(int N2K,int N5,int N2,int N1);/*IT IS USED TO DISPLAY THE NO.OF NOTES DISPENSED FROM THE ATM MACHINE*/
  time_t t;/*FOR RANDOM NUMBER TO CREATE A VARIABLE ACCORDING TO TIME IN SECONDS*/
  time(&t);/*FOR RANDOM NUMBER TO ASSIGN THE VARAIBLE ADDRESS*/
  printf("\t   WELCOME TO RAMANATH ATM SERVICE\n");
  printf("\t   ======= == ======== === =======\n");
  printf("%s",ctime(&t));
  printf("Insert your card\n");
  do
  {
    ant:printf("1.Withdraw\n");
    printf("2.Deposit\n");
    printf("3.Balance Enquiry\n");
    printf("4.Pin Change\n");
    printf("5.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:pin(a,b,i);
               ram:printf("Enter how much amount to withdrawL: ");
               scanf("%d",&with);
               num=with;
               if(amt-with<=0)/*CHECKING AMOUNT ENTERED IS MORE THAN THE AMOUNT IN THE ACCOUNT*/
               {
                   printf("You doesn't have that much of money in your account\n");
                   printf("So please re-enter the withdrawal money\n");
                   goto ram;
               }
               else
               {
				  N2K=0;N5=0;N2=0;N1=0;
				  while(with>=100)/*IT IS USED WHETHER THE USER ENTERED THE AMOUNT IS IN PROPER MANNER OR IN IMPROPER MANNER???*/
				  {
					if(with>=2000)
					{
						i=with/2000;
						N2K=i;
						with=with%2000;	
					}
					if(with>=500)
					{
						i=with/500;
						N5=i;
						with=with%500;
					}
					if(with>=200)
					{
						i=with/200;
						N2=i;
						with=with%200;
					}
					if(with>=100)
					{
						i=with/100;
						N1=i;
						with=with%100;
					}

				  }
				   if(with!=0)/*IF THE USER ENTERED THE AMOUNT IS IN IMPROPER MANNER*/
				   {
					   printf("Sorry in this ATM there are 2000,500,200,100 Notes only\n");
					   printf("So please Re-");
					   N2K=0;N5=0;N2=0;N1=0;
					   goto ram;
				   }
				   with=num;
				   display_notes(N2K,N5,N2,N1);						
                   printf("You want receipt\n");
                   printf("6.yes\n");
                   printf("7.No\n");
                   printf("Enter your choice: ");
                   scanf("%d",&ch);
                   amt=amt-with;
                   if(ch==6)
                    display_rec(amt);                   
                   printf("Your amount in your account is:%d\n",amt);
                   printf("Take your cash\n");
                   break;
               }
        case 2:pin(a,b,i);
               printf("### Deposit 2000,500,200,100 Notes only ###\n");
               bee:printf("Deposit your money; ");
               scanf("%d",&dep);
               num=dep;          
				  while(dep>=100)/*IT IS USED WHETHER THE USER DEPOSITED AMOUNT/NOTES IS IN PROPER MANNER OR IN IMPROPER MANNER???*/       
				  {
					if(dep>=2000)
						dep=dep%2000;						
					if(dep>=500)
						dep=dep%500;					
					if(dep>=200)
						dep=dep%200;					
					if(dep>=100)
						dep=dep%100;
					}					
				   if(dep!=0)/*IF THE USER DEPOSITED THE AMOUNT IS IN IMPROPER MANNER*/
				   {
					   printf("Sorry ATM in this we will accept 2000,500,200,100 Notes only\n");
					   printf("So please Re-");
					   goto bee;
				   }
				  
			   dep=num;
               amt=amt+dep;
               printf("You want receipt\n");
               printf("6.yes\n");
               printf("7.No\n");
               printf("Enter your choice: ");
               scanf("%d",&ch);
               if(ch==6)
                  display_rec(amt); 
               printf("The amount in your account:%d\n",amt);
               break;
        /*THE BELOW CASE WILL ASK WHETHER TO REQUIRE A RECEIPT OR NOT IF NOT DISPLAY PRESENT AMOUNT IN ACCOUNT ONLY IF YES DISPALY RECIEPT THROUGH IDPLAY_REC FUNCTION AND ITS PRESENT AMOUNT IN THE ACCOUNT*/
        case 3:pin(a,b,i);
               printf("You want receipt\n");
               printf("6.yes\n");
               printf("7.No\n");
               printf("Enter your choice: ");
               scanf("%d",&ch);
               if(ch==6)
                  display_rec(amt);
               printf("The amount in your account is:%d\n",amt);
               break;
        case 4:pin(a,b,i);
               ramu:printf("Enter mobile number(with spaces): ");
               for(i=0;i<10;i++)
                      scanf("%d",&u[i]);
               for(i=0;i<10;i++) 
                 if(mo[i]!=u[i])/*IF MOBILE NUMBER IS INCORRECT */
                 {
                     printf("Please Re-: ");
                     goto ramu;
                 }
               ramanath:srand(time(NULL));
                 num=(rand()%(upper-lower+1))+lower;/*IT IS USED TO CREATE RANDOM NUMBER FROM LOWER TO UPPER*/
                 printf("%d\n",num);
                 i=3;
                 while(num>0)
                 {
					 o[i]=num%10;
					 i--;
					 num=num/10;
				 }
                 printf("Enter your OTP upto 4 digits(with spaces): ");
                 for(i=0;i<4;i++)
                   scanf("%d",&uo[i]);
                 for(i=0;i<4;i++)
                   if(uo[i]!=o[i])
                   {
                       printf("Enterd OTP is Incorrect\n");
                       printf("So please ");
                       goto ramanath;
                   }
                  kalyani:printf("Enter new pin: ");
                  for(i=0;i<4;i++)
                    scanf("%d",&b[i]);
                  printf("Conform pin: ");
                  for(i=0;i<4;i++)
                    scanf("%d",&a[i]);
                  for(i=0;i<4;i++)
                    if(a[i]!=b[i])
                    {
						printf("INCORRECT PIN\n");
						printf("Please Re-");
						goto kalyani;
					}
                  
                 break;
          /*THE BELOW CASE IS USED TO TELL TO THE USER THAT ENTERED CHOICE IS INCORRECT AND REQUEST TO THE USER TO ENTER THE CORRECT CHOICE*/       
          case 5:return 0;
          default:printf("Enetred choice is Incorrect\n");
                  printf("So,Please check the choice which are given below\n");
                  goto ant;
           
    }
  }while(1);
  printf("Take your card\n");
  printf("Thank u for visiting our ATM\n");
  printf("You are welcome for any time\n");
  return 0;
}
void display_rec(int amt)/*TO PRINT ACO,ACOLDER AND AMOUNT PRESENT IN THE ACCOUNT AS IT AS AN RECIEPT*/
{
    printf("\t\tRECIEPT\n");
    printf("\t\t=======\n");
    printf("Account no    :XXXXXXXX2680\n");
    printf("Account holder:G.RAMANATH REDDY\n");
    printf("Ammount       :%d\n",amt);
    printf("\tXXXXXXXXXXXXXXXXXXXXXXX\n");
}
void display_notes(int N2K,int N5,int N2,int N1)/*IT IS USED TO DISPLAY THE NO.OF NOTES DISPENSED FROM THE ATM MACHINE*/
{
   printf("\tNOTES\n");
   printf("\t=====\n");
   if(N2K!=0)
     printf("2000 * %d = %d\n",N2K,N2K*2000);
   if(N5!=0)
     printf("500 * %d = %d\n",N5,N5*500);
   if(N2!=0)
     printf("200 * %d = %d\n",N2,N2*200);
   if(N1!=0)
	 printf("100 * %d = %d\n",N1,N1*100);
}
void pin(int a[4],int b[4],int i)/*CHECKING THE PIN IS CORRECT OR NOT IF NOT REQUEST TO ENTER AGAIN*/
{
	printf("Enter your pin  having 4 digits(with spaces):\n");  
	damu:for(i=0;i<4;i++) 
	 scanf("%d",&b[i]);
   for(i=0;i<4;i++)
      if(a[i]!=b[i])
      {
	      printf("Entered pin is incorrect\n");
	      printf("Enter correct pin\n");
	      goto damu;
      }
}
