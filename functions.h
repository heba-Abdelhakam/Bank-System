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
#define MAX_SIZE 20
#define MAX_SIZE_NAME 70





void gotoxy(int x, int y);
void welcome_screen(void);
void Admin();
void User();
void LoginAdmin(char* username, char* password);
void Generate_Pass(int N);
int Create_BankID(int bank_id);
int Calc_Age(int birth_year);
int Check_Age(int age);
void input_guardian_id(char* guardian_id);

//not yet implemented
//char* get_guardian_id(char* guardian_id);
//implemented
int choose_features_admin(void);
int check_valid_id(char* id);
//Client* create_new_account(void);
char* get_full_name(void); // to be edited
char* get_address(void);