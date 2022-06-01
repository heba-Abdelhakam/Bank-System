#include "admin_functions.h"
#include "functions.h"
#define PASSWORD_SIZE 10

Client* create_new_account(void){
	/* 
	INPUT : void
	OUTPUT: pointer to the created struct (account)
	FUNCTION: create new account (struct) and return the pointer 
	NOTES:  assert that the returned ptr is not null in the caller side
			can't take the pointer (cuz it is a copy value of the pointer(sol : takes a pointer to pointer)
	*/
	
	Client* account_ptr ;
	account_ptr = (Client*)malloc(sizeof(Client));
	//account_ptr -> birth_year = 19;
	if (account_ptr == NULL) return account_ptr;
	else{
		//char full_name[MAX_SIZE];// you make a local variable so it is destroyed outside the funciton
		
		
		char* full_name = (char*) malloc(sizeof(char)*MAX_SIZE);
		char* national_id = (char*) malloc(sizeof(char)*MAX_SIZE);
		char* address = (char*) malloc(sizeof(char)*MAX_SIZE);
		int birth_year;
		int balance;
		int* birth_year_ptr = &birth_year;
		int* balance_ptr = &balance;
		
		input_string("full name" , full_name);
		input_string("address" , address);
		input_string("national id" , national_id);
		
		
		account_ptr -> FullName = full_name;
		account_ptr -> Address = address;
		account_ptr -> NationalID = national_id;
		account_ptr -> birth_year = input_int("birth year");
		account_ptr -> AccountID = Create_AccountID();
		account_ptr -> balance = input_int("balance");
		//account_ptr -> password = Generate_Pass(PASSWORD_SIZE);
		account_ptr -> status = "Active";

		
		return account_ptr;
	}
}

/*
void input_full_name(char* full_name){
	//char full_name[MAX_SIZE];
	printf("enter full name: ");
	fflush(stdin);
	fgets(full_name , MAX_SIZE , stdin);
	//return full_name;
}

void input_address(char* address){
	//char address[MAX_SIZE];
	printf("enter full address: ");
	fflush(stdin);
	fgets(address , MAX_SIZE , stdin);
	//return address;
}

void input_NationalID(char* id){
	//char id[MAX_SIZE];
	printf("enter full national id: ");
	fflush(stdin);
	fgets(id , MAX_SIZE , stdin);
	//return id;
	
}

*/

void input_string(char* msg , char* ptr){
	printf("enter %s: ", msg);
	fflush(stdin);
	fgets(ptr, MAX_SIZE , stdin);
	
}



int input_int(char* msg ){
	int x;
	printf("enter %s: ", msg);
	fflush(stdin);
	scanf("%d",&x);
	return x;
}

