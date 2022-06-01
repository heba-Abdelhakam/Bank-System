#include "functions.h"
/*
typedef struct client{
    char FullName[MAX_SIZE_NAME];
    char Address[MAX_SIZE];
    char NationalID[MAX_SIZE];
	char guardian_id[MAX_SIZE];
    int Age;
    int CountID;
	char password[MAX_SIZE];
	

}Client;
*/
void gotoxy(int x, int y){
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

void welcome_screen(void){
	/* 
	INPUT : void
	OUTPUT: void 
	FUNCTION:  navigates you to admin or user screen
	NOTES:
	*/
	
    system("cls");
    
    gotoxy(40, 2);
    printf("... Welcome in Our Bank System ...");
    
    gotoxy(45, 3);
    printf("\n  \t\t\t\t\t\t 1. Admin Window \n \t\t\t\t\t\t 2. User Window \n \t\t\t\t\t\t 3. close the system");    


	char option;
    printf("\n \n Choose Window : ");
    option = getch();
    printf("%c \n",option);
    switch(option)
    {
        case '1':
            Admin();
            break;
			
        case '2':
            User();
			//if returned 0 then exit else : welcome screen again
            break;
			
		case '3':
			return ; // to exit the system
			
		 default : 
			printf("you must choose 1 or 2 or 3 ok?");
			getch();
			welcome_screen();
			
		
    }
	
	
}

void Admin(){
	char username[20]; 
    char password[20]; 
	
    system("cls");
    printf("\n");
    gotoxy(44, 3);
    printf("~~ Welcome in Admin Window ~~");
    gotoxy(44, 4);
    printf("-----------------------------");
	
	gotoxy(44, 7);
	printf(".Enter your username:\t"); 
	scanf("%s",&username); 
	
	gotoxy(44, 9);
	printf(".Enter your password:\t"); 
	scanf("%s",&password); // the same as password (without &) 
	
	//printf("*username = %c",*username);
	//printf("&username = %x",&username);
	//printf("username = %s",username);
	int success_login = LoginAdmin(username, password);
	
	
	// choose feature if successful login
	int flag = 0;
	while (flag == 0){
		int choice = admin_window();
		//return choice
		switch (choice){
			case 1 :
				//create_new_account();
				flag =1;
				break ;
			case 2 :
				//open_existing_account();
				flag = 1;
				break;
				
			case 3 :
				//return ; // exit the system
				welcome_screen();
				flag =1;
				//return 0
				
			default :
				printf("you must choose 1,2 or 3 ok?");
				getch();
				//system("cls");
				//no change in the flag (loop)
			}
	}
}

int admin_window(void){
	/*
	INPUT : void
	OUTPUT : 1 : create new account 
			 2 : open existing account
			 3 : exit the  system
			 else : to be handeled when calling the function (wrong input)
			 
	FUNCITON : to know whcich function the admin want to choose
	
	*/
	system("cls");
	printf("\n");
    gotoxy(44, 3);
    printf("~~ Welcome in Admin Window ~~");
    gotoxy(44, 4);
    printf("-----------------------------");
	printf("\nchoose the function: \n");
	printf("1. create new account\n");
	printf("2. open existing account\n");
	printf("3. exit the  system\n");
	int x = 0;
	printf("enter a number ");
	scanf("%d",&x);
	return x;
}


void User(){
    system("cls");
	printf("\n");
    gotoxy(44, 3);
    printf("~~ Welcome in Client Window ~~");
    gotoxy(44, 4);
    printf("-----------------------------");
	printf("\nenter account ID ");
	int account_id;
	char password[MAX_SIZE];
	scanf("%d",&account_id);
	printf("enter account password ");
	scanf("%s",password);
	//client_login();
	
	int flag = 0;
	while (flag ==0){
		int choice = client_window();
		switch (choice){
					case 1 :
						//make transaction ();
						flag = 1;
						break ;
					case 2 :
						//ochange account password();
						flag = 1;
						break;
						
					case 3 :
						//get cache
						flag = 1;
						break;
						
					case 4 :
						//deposite in account
						flag = 1;
						break;
						
					case 5 :
						// exit the system
						flag = 1;
						welcome_screen();
						//return;
						
						
					default :
						printf("you must choose 1,2,3,4 or 5 ok?");
						getch();
		
		}
	}

}

int client_window(void){
	/*
	INPUT : void
	OUTPUT : 1 : make transaction 
			 2 : change account password
			 3 : get cache
			 4 : deposite in account
			 5 : exit the system
			 else : to be handeled when calling the function (wrong input)
			 
	FUNCITON : to know whcich function the client want to choose
	NOTES : the function choice to be handled in the caller side
	
	*/
	system("cls");
	printf("\n");
    gotoxy(44, 3);
    printf("~~ Welcome in Admin Window ~~");
    gotoxy(44, 4);
    printf("-----------------------------");
	printf("\nchoose the function: \n");
	printf("1. make transaction\n");
	printf("2. change account password\n");
	printf("3. get cache\n");
	printf("4. deposite in account\n");
	printf("5. exit the system\n");

	int x = 0;
	printf("enter a number ");
	scanf("%d",&x);
	return x;
}


                    // LOGIN Function //
int LoginAdmin(char* username, char* password){ 
	/*
	INPUT : two strings (user name , passwrd)
	OUTPUT : 1 : successful login
			 0 : un successful login 
			 
	FUNCITON : to check on the user name and password given
				and let the user try again if they are wrong 
	
	*/

    if((strcmp(username,"Heba")==0) ) //check name if right 
    { 
        // check password
        if(strcmp(password,"123")==0)
        { 
	
        printf("\nWelcome.Login Success!\n");
		return 1 ;//valid		
        }
        else{ 
			int flag = 0;
			char answer = 'a';
			while (flag == 0){
				printf("\nwrong password Try again?y/n ");
				answer = getch();
				//scanf("%c",&answer); //scanf stores all the entered values till the enter button
				if (answer == 'y' || answer == 'Y') {
					flag = 1;
					printf("\nenter password again: ");
					scanf("%s",password);
					LoginAdmin(username,password);
				}
				else if (answer == 'n' || answer == 'N')
					return 0; // not valid
			
				else
					printf("\ninvalid answer \n");
			}
		}
	}
    // If name wasn't right
    else
    { 
		 
		int flag = 0;
		char answer = 'a';
		while (flag == 0){
			printf("\nUser doesn't exist Try again? y/n ");
			answer = getch();
			if (answer == 'y' || answer == 'Y') {
				flag = 1;
				printf("\nenter user name again: ");
				scanf("%s",username);
				LoginAdmin(username,password);
			}
			else if (answer == 'n' || answer == 'N')
				return 0; // not valid
		
			else
				printf("\ninvalid answer \n");
		}
			
        
    }
    
}


                // Generate Password //
void Generate_Pass(int N){
    
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


int Create_AccountID(void){
    //printf("%c",bank_id);
	static int bank_id =1000;
    return bank_id++;
}

int Calc_Age(int birth_year){
    int current_year = 2022;
    int age = current_year - birth_year;
    return age;
}

int Check_Age(int age){
	/*
	INPUT : age
	OUTPUT : 0 : not valid age 
			 1 : valid age
			 
	FUNCITON : check if age < or equal 21
	*/
    if (age <= 21)
    {
		return 0;
    }
    else{
		return 1;
    }
}

void input_guardian_id(char* guardian_id){
	// you can return a pointer (but allocate the string in heap (not efficient cuz you will want to remove it)
	// you can return a pointer (and make it static (you will the change the string each time you call the funciton))
	// you can pass a pointer to the funciton and then assign the string in this pointer 
	/*
	INPUT : a pointer to the string
	OUTPUT : the guardian ID as a string
	FUNCITON : takes the guardian ID as input from the user
	*/
	// char *guardian_id; // can not be static as it will be the same each time you call the funciton
	 printf("\nYou must have a guardian...");
     printf("\nPlease enter your guardian ID : ");
     scanf("%s",guardian_id);
	 //return guardian_id;
}

int check_valid_id(char* id){ 
	/* the input is a pointer to the string
		the output is 0 if id is not valid
		thr output is 1 if id is valid
	*/
	int flag2 = 0;
	int is_valid = 0;
	
	/* ******************************
	 **check the length of the id: ** 
	 ******************************** */
	int length = strlen(id);
	if ( length != 14){
		return 0;
	}
	/* **********************************
	 **check if all chars are integer: ** 
	 ************************************ */
	// get the size of the id
	for (int i=0;i<length; i++){
		char ch = id[i];
		if(!isdigit(ch)){
			return 0;
		}
	}
	
	//if you made it here then the id is valid
	return 1;
}
