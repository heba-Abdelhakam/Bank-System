#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
# include<malloc.h>
#include<windows.h>
#include<string.h>
#include <time.h>
#include"functions.h"
#include"admin_functions.h"
#include "app.h"

void app(){
	 
	
	//welcome_screen();
	//if choice == 3 return 0;
   
    //getch();
	Client* ptr ;//= (Client*)malloc(sizeof(Client));
	ptr = create_new_account();
	//ptr -> balance = 22;
	char full_name[MAX_SIZE];
	char address [MAX_SIZE];
	char id [MAX_SIZE];
		//input_full_name(full_name);
		//printf("enter full name: ");
		//scanf("%s",full_name);
		//gets(full_name);
		//printf("enter the full name");
		//fflush(stdin);
		//fgets(full_name , MAX_SIZE , stdin); 
		//input_full_name(full_name);
		//ptr -> FullName = full_name;
		//printf("enter the full id");
		//fflush(stdin);
		//fgets(id , MAX_SIZE , stdin); 
		
		//input_NationalID(id);
		//ptr -> NationalID = id;
	//ptr = (Client*)malloc(sizeof(Client));
	//ptr->birth_year = 22;
	if (ptr != NULL)
	{	printf("\n%s this is the age",ptr->FullName);
		printf("\n%s this is the address",ptr->Address);
		printf("\n%s this is the national id",ptr->NationalID);
		printf("\n%d this is the year",ptr->birth_year);
		printf("\n%d this is the balance",ptr->balance);
		printf("\n%d this is the id account",ptr->AccountID);
	}


}
