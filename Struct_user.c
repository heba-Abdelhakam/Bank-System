

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
# include<malloc.h>
#include<windows.h>
#include<string.h>
#include <time.h>


typedef struct client{
    char FullName[70];
    char Address;
    int NationalID;
    int Age;
    int CountID;

}Client;

void gotoxy(int x, int y)
{
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}



// Define Functions //
void Admin();
void User();
void LoginAdmin(char* username, char* password);
void Generate_Pass(int N);
int Create_BankID(int bank_id);
int Calc_Age(int birth_year);
void Check_Age(int age);


// Execute Functions //
int main()
{
    // Test of give value to name in struct //

    // Client c;
    // printf("Name:");
    // scanf("%s",&c.FullName);

    // Test Random Generator of password //
    printf("\nTest of Random Generator Password \n ----------------------------------\n");
    int N =5;
    printf("PassWord: ");
    Generate_Pass(N);

    getch();

    //Test Generate Bank Id
    int bank_id = 1000;
    
    bank_id = Create_BankID(bank_id);
    printf("\nFirst Id : %c",bank_id);
    // printf("\nSecond Id :");
    // bank_id = Create_BankID(bank_id);
    

    getch();

    // Test Calc. AGE //
    printf("\n Test Age Function \n");
    int birth_year, age;
    scanf("%d",&birth_year);
    age = Calc_Age(birth_year);
    printf("Age = %d",age);

    getch();

    //Test Check AGE //
    Check_Age(age);
    getch();

    char option; // to handle switch
    // to handle login page 
    char username[20]; 
    char password[20]; 

    system("cls");
    //SetConsoleCursorPosition(38,2);
    //clrscr();
    
    gotoxy(40, 2);
    printf("... Welcome in Our Bank System ...");
    
    gotoxy(45, 3);
    printf("\n  \t\t\t\t\t\t 1. Admin Window \n \t\t\t\t\t\t 2. User Window");    



    printf("\n \n Choose Window : ");
    option = getch();
    printf("%c \n",option);
    switch(option)
    {
        case '1':
            Admin();
            //system("cls");
            gotoxy(44, 7);
            printf(".Enter your username:\t"); 
            scanf("%s",&username); 
            
            gotoxy(44, 9);
            printf(".Enter your password:\t"); 
            scanf("%s",&password); 
            LoginAdmin(username, password);

            break;
        case '2':
            User();
            break;
    }


    return 0;
}

void Admin()
{
    system("cls");
    printf("\n");
    gotoxy(44, 3);
    printf("~~ Welcome in Admin Window ~~");
    gotoxy(44, 4);
    printf("-----------------------------");
}

void User()
{
    //system("cls");
    printf("\nWelcome in User Window\n");
}

                    // LOGIN Function //
void LoginAdmin(char* username, char* password)
{ 

    if(strcmp(username,"Heba")==0) //check name if right 
    { 
        // check password
        if(strcmp(password,"123")==0)
        { 
        printf("\nWelcome.Login Success!"); 
        }
        else{ 
        printf("\nwrong password");
        } 
    }
    // If name wasn't right
    else
    { 
        printf("\nUser doesn't exist"); 
    }
    
} 


                // Generate Password //
void Generate_Pass(int N)
{
    
    // int pass = rand();
    // printf("PassWord: %d",pass);
    // return pass;
     int i = 0;
  
    int randomizer = 0;
  
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((unsigned int)(time(NULL)));
  
    // Array of numbers
    char numbers[] = "0123456789";
    // Array of small alphabets
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
    // Array of capital alphabets
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    // Array of all the special symbols
    char symbols[] = "!@#$^&*?";
  
    // Stores the random password
    char password[N];
  
    // To select the randomizer
    // inside the loop
    randomizer = rand() % 4;
  
    // Iterate over the range [0, N]
    for (i = 0; i < N; i++) {
  
        if (randomizer == 1) {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 2) {
            password[i] = symbols[rand() % 8];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 3) {
            password[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else {
            password[i] = letter[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
    }
    //printf(password);
}


int Create_BankID(int bank_id)
{
    //printf("%c",bank_id);
    return bank_id++;
}

int Calc_Age(int birth_year)
{
    int current_year = 2022;
    int age = current_year - birth_year;
    return age;
}

void Check_Age(int age)
{
    if (age < 21)
    {
        int guardian_id;
        printf("\nYou must have a guardian...");
        printf("\nPlease enter your guardian ID : ");
        scanf("%d",&guardian_id);
    }
    else{
        printf("\nSuitable Age");
    }
}