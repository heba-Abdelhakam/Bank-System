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
	 

	welcome_screen();
	//if choice == 3 return 0;
   
    getch();
	Client* ptr ;//= (Client*)malloc(sizeof(Client));
	ptr = create_new_account();
	//ptr = (Client*)malloc(sizeof(Client));
	//ptr->birth_year = 22;
	if (ptr != NULL)
	printf("\n%d this is the age",ptr->birth_year);



}
