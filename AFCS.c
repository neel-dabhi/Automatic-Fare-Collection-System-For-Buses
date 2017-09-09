#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

int i,j,dest,source,dist,balance=100,Aadhar_Count=0,Flag=0;
unsigned char input[15],Aadhar_Record[10][500];
char Continue='y';
float a[5][5]={
					{0,0.6,1.2,1.7,2.3},
					{0.6,0,0.6,1.1,1.7},
					{1.2,.6,0,.5,1.1},
					{1.7,1.1,.5,0,.6},
					{2.3,1.7,1.1,.6,0}	
				};

void Show_Records()
{
	int i,j;
	for(i=0;i<=9;i++)
	{
		printf("\n i=%d , Aadhar no = ",i);
		
		for(j=0;j<=11;j++)
		{
		printf("%c",Aadhar_Record[i][j]);
			
			
		}
		printf("\n");
	}
	
	
}

void Display_Station_Choice()
{
	printf("\n\n----------------- Station No. --------------\n");		
	printf("\n1.Gondal Chowkdi\n2.Punit Nagar\n3.KKV Circle \n4.Indira Circle\n5.Gandhigram");	
	printf("\n\n--------------------------------------------\n");										
		
}
void Display_Source(int source)
{
		switch (source)
		{	
				case 1: 
					printf("\n========== Your Source Station is Gondal Chaukadi =========\n\n");
					break;
					
				case 2: 
					printf("\n========= Your Source Station is Punit Nagar =========\n\n");
					break;
		
				case 3: 
					printf("\n========= Your Source Station is KKV Circle ========= \n\n");
					break;
	
				case 4: 
					printf("\n========= Your Source Station is Indira Circle =========\n\n");
					break;
			
				case 5: 
					printf("\n========= Your Source Station is Gandhigram =========\n\n");
					break;
							
				default:
					break;				
			}
	
}
void Display_Destination(int destination)
{
		switch (destination)
		{	
				case 1: 
					printf("\n========== Your Destination Station is Gondal Chaukadi =========\n\n");
					break;
					
				case 2: 
					printf("\n========= Your Destination Station is Punit Nagar =========\n\n");
					break;
		
				case 3: 
					printf("\n========= Your Destination Station is KKV Circle ========= \n\n");
					break;
	
				case 4: 
					printf("\n========= Your Destination Station is Indira Circle =========\n\n");
					break;
			
				case 5: 
					printf("\n========= Your Destination Station is Gandhigram =========\n\n");
					break;
							
				default:
					break;				
			}
	
}
 
void Calculate_Fare(int source,int dest,int balance)
{
	printf("\n\n============================================================\n\n");
	printf("\n\n Distance Travelled is %10.2f KM\n",a[source][dest]);
	printf("\n\n Fare to be paid is %10.2f Rs.\n",a[source][dest]*4);
	printf("\n\n Remaining Balance in your BRTS Account is %10.2f Rs.",balance-a[source][dest]*4);
	printf("\n\n============================================================\n\n");			
}
int main()
{
							
	do
	{	
		
label:	
		
		printf(" Scan your aadhar card : ");
		
		
		scanf("%s",input);
		//gets(input);
		
		//printf(" \n length = %d \n",strlen(input));
		//getch();
		
		for(i=0;i<10;i++)
		{			
			if(strcmp(input,Aadhar_Record[i])==0)
			{
			
				Display_Station_Choice();
				
				printf("\n\n Enter your Destination : ");
				scanf("%d",&dest);
				
				Display_Destination(dest);
				
				Calculate_Fare(source,dest,balance);
				getch();
			//	goto label;
				
				Flag =1;	
				break;
			}

		}
		if(Flag ==0)
		{
				strcpy(Aadhar_Record[Aadhar_Count++],input);
		//		Show_Records();
		//		getch();
					
				Display_Station_Choice();
				
				printf("\n\n Enter your Source : ");
				scanf("%d",&source);
				
				Display_Source(source);	
				
				
			}
		goto label;
		
		printf("Do you want to scan next Aadhar Card ? (Y/N)");
		scanf("%c",&Continue);
									
	}while(Continue=='y' || Continue=='Y');
		return 0;									
										
}
