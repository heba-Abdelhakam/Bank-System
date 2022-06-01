#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_


// Define Functions //
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
# include<malloc.h>
#include<windows.h>
#include<string.h>
#include <time.h>
#include<ctype.h>


#define CURRENT_YEAR 2022
#define MAX_SIZE 70
#define MAX_SIZE_NAME 70

typedef struct client{
    char *FullName;//[MAX_SIZE_NAME];
    char *Address;//[MAX_SIZE];
    char *NationalID;//[MAX_SIZE];
	int birth_year;
	char *guardian_id;//[MAX_SIZE];
	char *guardian;//[MAX_SIZE];
    int AccountID;
	char *password;//[MAX_SIZE];
	char *status;//[MAX_SIZE];
	int balance;
	

}Client;



void gotoxy(int x, int y);
void welcome_screen(void);
void Admin();
void User();
int client_window(void);
int LoginAdmin(char* username, char* password);
void Generate_Pass(int N);
int Create_AccountID(void);
int Calc_Age(int birth_year);
int Check_Age(int age);
void input_guardian_id(char* guardian_id);

//not yet implemented
//char* get_guardian_id(char* guardian_id);
//implemented
int admin_window(void);
int check_valid_id(char* id);
//Client* create_new_account(void);
char* get_full_name(void); // to be edited
char* get_address(void);

#endif