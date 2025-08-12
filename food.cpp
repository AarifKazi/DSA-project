#include <iostream>
using namespace std;

int main(){
	char order;
	double totalbill = 0;
	cout<<"\t\t      Welcome to Shahi Food Corner";
	cout<<endl;
	string name;
	cout<<"Enter your name";
	cin>>name;
	cout<<endl;
	cout<<"hello "<<name;
	cout<<endl;
	
	cout<<"What would you like to order\n";
	cout<<endl;
	do{
	int choice,quntity;
	const int pizzaprice = 100;
	const int burgerprice = 50;
	const int sandwichprice = 70;
	const int biryaniprice = 150;
	
	
	
	cout<<"\t\t -----------------Menu--------------\n";
	cout<<endl;
	cout<<"1) Pizza --- 100";
	cout<<endl;
	cout<<"2) Burger --- 50";
	cout<<endl;
	cout<<"3) Sandwich --- 70";
	cout<<endl;
	cout<<"4) Biryani --- 150";
	cout<<endl;
	
	cout<<"Enter your choice\n";
	cin>>choice;
	
	cout<<"Enter your quntity\n";
	cin>>quntity;
	
	double bill = 0;
	
	
	switch(choice){
		case 1:
			bill = pizzaprice * quntity;
			cout<<"Your pizza price is \n"<<bill;
			cout<<endl;
			cout<<"Your choice is pizza\n";
			break;
		case 2:
			bill = burgerprice * quntity;
			cout<<"Your burger price is \n"<<bill;
			cout<<endl;
			cout<<"Your choice is burger\n";
			break;
		case 3:
			bill = sandwichprice * quntity;
			cout<<"Your sandwich price is \n"<<bill;
			cout<<endl;
			cout<<"Your choice is Sandwich\n";
			break;
		case 4:
			bill = biryaniprice * quntity;
			cout<<"Your biryani price is \n"<<bill;
			cout<<endl;
			cout<<"Your choice is biryani\n";
			break;
			default:
				cout<<"invalid choice";
	}
	totalbill+=bill;
	cout<<endl;
	cout<<"do you want to order something else? \n\n";
	cin>>order;
}while(order == 'y' || order == 'Y');

cout<<"total bill is "<<totalbill;	
	
	return 0;
}
