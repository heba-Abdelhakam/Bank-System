#include"admin_functions.h"

Client* create_new_account(void){
	/* assert that the returned account is not null in the caller side
	 can't take the pointer (cuz it is a copy value of the pointer(sol : takes a pointer to pointer)
	INPUT : void
	OUTPUT: pointer to the created struct (account)
	*/
	
	Client* account_ptr ;
	account_ptr = (Client*)malloc(sizeof(Client));
	account_ptr -> birth_year = 19;
	return account_ptr;
}