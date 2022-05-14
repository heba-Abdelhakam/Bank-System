

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
# include<malloc.h>
#include<windows.h>
#include<string.h>
#include <time.h>
#include"../project/functions.h"

// Execute Functions //
int main()
{


    // Test Random Generator of password //
    printf("\nTest of Random Generator Password \n ----------------------------------\n");
    int N =5;
    printf("PassWord: ");
    Generate_Pass(N);

    getch();

    //Test Generate Bank Id
    int bank_id = 1000;
    
    bank_id = Create_BankID(bank_id);
    printf("\nFirst Id : %d",bank_id);
    // printf("\nSecond Id :");
    // bank_id = Create_BankID(bank_id);
    

    getch();


	welcome_screen();
    // Test Calc. AGE //
    printf("\n Test Age Function \n");
    int birth_year, age;
    scanf("%d",&birth_year);
    age = Calc_Age(birth_year);
    printf("Age = %d",age);

    getch();

    //Test Check AGE //
    int is_valid_age = Check_Age(age);
	if (is_valid_age){
		printf("\nsuitable age");
		//char guardian_id[MAX_SIZE] = "";
	}
	else {
		char *guardian_id = input_guardian_id();
		//add it to the struct
	}
    getch();
	


    return 0;
}

