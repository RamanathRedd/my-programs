#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int count=0;
/*int number_10(int num)
{
	
}
int number_4(int num)
{
	
}*/
void cash_dispensor(int cash)
{
	printf("----------------------------NOTES-------------------------------\n");
	printf("\t\t\t    =====\n");
	while(cash>0)
	{
		if(cash>=2000)
		{
		   printf("2000 * %d = %d\n",cash/2000,(cash/2000)*2000);
		   cash%=2000;
		}
		if(cash>=500)
		{
		   printf("500 * %d = %d\n",cash/500,(cash/500)*500);
		   cash%=500;
		}
		if(cash>=200)
		{
		   printf("200 * %d = %d\n",cash/200,(cash/200)*200);
		   cash%=200;
		}
		if(cash>=100)
		{
		   printf("100 * %d = %d\n",cash/100,(cash/100)*100);
		   cash%=100;
		}
	}
}
int otp_generate()
{
	int lower=1000,upper=9999,otp;
	srand(time(NULL));
	otp=(rand()%(upper-lower+1))+lower;
	return otp;
}
int pin_check(int pin[4])
{
	int i,temp_pin;
	ram:if(count>=3)
	{
	   printf("------YOUR CARD IS BLOCKED BECAUSE YOU ENTERED INCORRECT PIN FOR 3 TIMES!!!!!-----\n");
	   printf("----SO,PLEASE TRY IT AFTER 24 HOURS-------\n");
	   printf("\t\t  OR\n");
	   printf("----CONSULT YOUR BANK BRANCH TO SOLVE THE PROBLEM-----\n");
	   return count;
	}
	printf("Enter your pin(4-digit number): ");
	scanf("%d",&temp_pin);
	/*i=3;
	while(temp_pin>0)
	{
		temp_pin_arr[i]=temp_pin%10;
		i--;
		temp_pin/=10;
	}*/
	for(i=3;i>=0;i--)
	{
	  if(pin[i]!=temp_pin%10)
	  {
		  printf("Entered pin is incorrect\n");
		  count++;
		  if(count!=3)
		  printf("So,please re-");
		  goto ram;
	  }
	  temp_pin/=10;  
    }
	return count;
}
int withdraw_enter(int amount,int pin[4])
{
	int count;
	count=pin_check(pin);
	if(count>=3)
	 return-1;
	int amt;
	ram:printf("Enter the amount to withdraw: ");
	scanf("%d",&amt);
	if(amt>25000)
	{
		printf("Entered amount is more than the limit \n");
		printf("Your limit is upto Rs.25000/- only\n");
		printf("So,please re-");
		goto ram; 
	}
	if(amount<amt)
	{
	 printf("-------/*Entered amount is more than the amount in your account*/----------\n");
	 printf("So,please re-");
	 goto ram;
    }
	if(amt%100!=0)
	{
	 printf("-------/*Entered amount is incorrect*/----------\n");
	 printf("-------/*This ATM will give 100,200,500,2000 notes only*/----------\n");
	 printf("So,please re-");
	 goto ram;
	}
	cash_dispensor(amt);
    return amount-amt;
}
int deposit_enter(int amount,int pin[4])
{
	int count;
	count=pin_check(pin);
	if(count>=3)
	 return -1;
	int amt;
	ram:printf("Enter the amount to deposit: ");
	scanf("%d",&amt);
	if(amt%100!=0)
	{
	 printf("-------/*Entered amount is incorrect*/----------\n");
	 printf("-------/*This ATM will accept only 100,200,500,2000*/----------\n");
	 printf("So,please re-");
	 goto ram;
	}
    return amount+amt;
}
int receipt(int amount,int pin[4])
{
	int count;
	count=pin_check(pin);
	if(count>0)
	 return -1;
	printf("-------------------------------RECEIPT----------------------------\n");
	printf("                                =======\n");
	printf("Account number:*********0557\n");
	printf("Account holder:G.Ramanath Reddy\n");
	printf("     Amount   =%d",amount);
	return 0;
}
void pin_change()
{
	int ph_num[10]={9,3,9,1,2,3,3,9,6,9},/*temp_ph_num[10],*/i,otp,temp_otp/*,otp[4],temp_otp[4],temp*/;
	long long int temp_ph;
	/*for(i=0;i<10;i++)
	printf("%d ",ph_num[i]);*/
	ram_ph_num:printf("Enter your phone number(10 digit number): ");
	scanf("%lld",&temp_ph);
	/*i=9;
	while(temp_ph>0)
	{
		temp_ph_num[i]=temp_ph%10;
		i--;
		temp_ph/=10;
	}*/
	for(i=9;i>=0;i--)
	{
	  if(ph_num[i]!=temp_ph%10)
	  {
		  printf("--------ENTERED NUMBER IS INCORRECT------------\n");
		  printf("So,please re-");
		  goto ram_ph_num;
	  }
	   temp_ph/=10;  
    }
	ram_otp:otp=otp_generate();
	/*i=3;
	temp=num;
	while(num>0)
    {	
	    otp[i]=num%10;
	    i--;
	    num=num/10;
	}
	num=temp;*/
	printf("Enter OTP which is sent to your mobile which is linked with bank account(4-digit number:\n");
	printf("/*Your OTP is:%d*/\n",otp);
	scanf("%d",&temp_otp);
	/*i=3;
	while(temp_num>0)
	{
		temp_otp[i]=temp_num%10;
		i--;
		temp_num/=10;
	}
	for(i=0;i<4;i++)
	  if(otp[i]!=temp_otp[i])
	  {
		  printf("You entered an incorrect OTP\n");
		  goto ram_otp;
	  }*/
	 while(otp>0)
	 {
		 if(otp%10!=temp_otp%10)
		 {
			printf("You entered an incorrect OTP\n");
		    goto ram_otp; 
		 }
		 otp/=10;
		 temp_otp/=10;
	 }
	  
}
void front_display()
{
	printf("\t\t\t\t\tWELCOME TO RAM ATM SERVICE\n");
	printf("\t\t\t\t\t======= == === === =======\n\n\n");
	time_t t;
	time(&t);
	printf("%s",ctime(&t));
	printf("--------------/*please insert your card*/----------------\n");
	printf("you can do the following operations in this AIM: \n");
}
int choice_print()
{
	int choice;
	printf("\nThe choices are:\n");
	printf("=== ======= ===\n");
	printf("1.Withdraw\n");
	printf("2.Deposit\n");
	printf("3.Receipt\n");
	printf("4.Balance Enquiry\n");
	printf("5.Pin change\n");
	printf("6.Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
int main()
{
	int choice,amount=50000,pin[4]={1,4,3,2},count,i,temp_pin;
	front_display();
	while(1)
	{
	   choice=choice_print();
	   switch(choice)
	   {
		   case 1:count=withdraw_enter(amount,pin);
		          if(count==-1)
		            return 0;
		          else
		            amount=count;
			      break;
           case 2:count=deposit_enter(amount,pin);
                  if(count==-1)
                    return 0;
                  else
		            amount=count;		            
                  break;
           case 3:count=receipt(amount,pin);
			      if(count==-1)
                    return 0;
			      break;
	       case 4:count=pin_check(pin);
				  if(count>=3)
                    return 0;
				  printf("The amount in your account is:%d",amount);
	              break;
	       case 5:pin_change();
				  printf("Enter your new pin(4-digit number): ");
				  scanf("%d",&temp_pin);
				  i=3;
				  while(temp_pin>0)
				  {
				    pin[i]=temp_pin%10;
				    i--;
				    temp_pin/=10;
				  }
				  break;
	       case 6:return 0;
				  break;
	       default:printf("Entered incorrect choice\n");
				   printf("So,please enter correct choices \n");
				   
	
               
	}
   }
	
	 
} 
