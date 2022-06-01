#ifndef ADMIN_FUNCTIONS_H_
#define ADMIN_FUNCTIONS_H_


#include"functions.h"
Client* create_new_account(void); //make a new node client in heap and return the pointer to it


int input_int(char* msg );
void input_string(char* msg , char* ptr);


#endif