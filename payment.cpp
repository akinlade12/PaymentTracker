#include <iostream>
#include <vector>
#include <algorithm>
#include "user.h"
#include "user.cpp"
using namespace std;
//Functions used for sort function lines 64 and 65
bool sort_by_owed(User a,User b)
{ 
	return (a.get_amount_owed()>b.get_amount_owed());
}
bool sort_by_owes(User a,User b)
{ 
	return (a.get_amount_owes()>b.get_amount_owes());
}
int main()
{
	int users;
	vector<User> names;
	string username;
	double money_spent_i;
	double total_money=0;
	double total_money_per_person=0;
	cout<<"Enter amount of users"<<endl;
	cin>>users;
	cout<<"Enter users' names"<<endl;
  //Enter Names for all User objects. This is the User constructor.
	for(int i=0; i<users; i++)
	{
		cin>>username;
		User new_user(username);
		names.push_back(new_user);
	}
	cout<<"Enter amount each user spent"<<endl;
	for(int i=0; i<users; i++)
	{
		cout<<names[i].get_name();
		cin>>money_spent_i;
		names[i].add_amount_spent(money_spent_i);
	}
	for(int i=0; i<users; i++)
	{
		total_money+=names[i].get_amount_spent();
	}
	total_money_per_person=total_money/users;
  //Vectors organize Users into two groups. People who owe and people who are owed.
	vector<User> ppl_who_owe;
	vector<User> ppl_owed;
  //Loop places each user into respective group while updating the amount each user owes/ is owed.
	for(int i=0;i<users;i++)
	{
		if(total_money_per_person-names[i].get_amount_spent()>0)
		{
		cout<<names[i].get_name()<<" owes "<<total_money_per_person-names[i].get_amount_spent()<<endl;
		names[i].add_amount_owes(total_money_per_person-names[i].get_amount_spent());
		ppl_who_owe.push_back(names[i]);
		}
		if(total_money_per_person-names[i].get_amount_spent()<0)
		{
		cout<<names[i].get_name()<<" is owed "<<(total_money_per_person-names[i].get_amount_spent())*-1<<endl;		
		names[i].add_amount_owed(-1*(total_money_per_person-names[i].get_amount_spent()));
		ppl_owed.push_back(names[i]);
		}
	}
  //Sorts both the people who owe money and the people who are owed money by amount they 
  //owe and amount they are owed respectively in ascending order. 
	sort(ppl_who_owe.begin(),ppl_who_owe.end(),sort_by_owes);
	sort(ppl_owed.begin(),ppl_owed.end(),sort_by_owed);
  //Loops check to make sure each user is in correct vector and sorted in ascending order
	for(int i=0;i<ppl_owed.size();i++)
		cout<<"Is owed"<<ppl_owed[i].get_name()<<" "<<ppl_owed[i].get_amount_owed()<<endl;
	for(int i=0;i<ppl_who_owe.size();i++)
		cout<<"Owes"<<ppl_who_owe[i].get_name()<<" "<<ppl_who_owe[i].get_amount_owes()<<endl;

	int i=0;
	int j=0;
  //Loop takes first user (user 1) in ppl_who_owe vector and first user (user 2) in ppl_owed vector.
  // Next if statement checks to see which user is owed/owes more money.
  //If user 2 is owed more money than user 1 owes, then user 1 will pay all of money owed to user 1.
  //User 2's amound owed is then updated and the loop moves onto the next user in the ppl_who_owe vector.
  //If user 2 is owed les money than user 1 owes, then user 1 will pay the rest of what user 2 is owed.
  //User 1's amount owes is then updated and the loop continues onto the next user in the ppl_owed vector.
  //Loop is repeated until all users have paid/been paid.
	while(i<ppl_owed.size()||j<ppl_owed.size())
	{
	if(ppl_owed[i].get_amount_owed()-ppl_who_owe[j].get_amount_owes()>0)
	{
	cout<<ppl_who_owe[j].get_name()<<" owes"<<ppl_owed[i].get_name()\
		<<ppl_who_owe[j].get_amount_owes()<<endl;
		ppl_owed[i].add_amount_owed(ppl_owed[i].get_amount_owed()-ppl_who_owe[j].get_amount_owes());
		j++;
	}
	if(ppl_owed[i].get_amount_owed()-ppl_who_owe[j].get_amount_owes()<0)
	{
		cout<<ppl_who_owe[j].get_name()<<" owes"<<ppl_owed[i].get_name()\
		<<ppl_owed[i].get_amount_owed()<<endl;
		ppl_who_owe[j].add_amount_owes(ppl_who_owe[j].get_amount_owes()-ppl_owed[i].get_amount_owed());
		i++;
	}
	}
	return 0;
}
