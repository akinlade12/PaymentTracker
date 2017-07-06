#include "user.h"

User::User(std::string name1)
{
	name=name1;
	amount_owed=0;
	amount_owes=0;
	amount_spent=0;
}
User::~User()
{
	return;
}
double User::get_amount_owed()
{
	return amount_owed;
}
double User::get_amount_owes()
{
	return amount_owes;
}
double User::get_amount_spent()
{
	return amount_spent;
}
string User::get_name()
{
	return name;
}
void User::add_amount_spent(double mon)
{
	amount_spent=mon;
}
void User::add_amount_owed(double mon)
{
	amount_owed=mon;
}
void User::add_amount_owes(double mon)
{
	amount_owes=mon;
}

