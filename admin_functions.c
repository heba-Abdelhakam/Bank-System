#include"admin_functions.h"

Client* create_new_account(void){
	/* assert that the returned account is not null in the caller side
	
	*/
	
	Client* account_ptr ;
	account_ptr = (Client*)malloc(sizeof(Client));
	account_ptr -> Age = 19;
	return account_ptr;
	//if (account_ptr != NULL) return 1;
	//else return 0;


}