#include <iostream>
using namespace std;

class BankAccount{ //name of class
	protected:
		double accountnumber;
		string accountname;
		double balance; // variables of class
		
		public:
			//constructor:
			BankAccount(){
				balance = 0;
			}
			
			
		public:
			//method of get-data:
			void getdata(){
				cout<<endl;
				cout<<"Enter your name : ";
 	            cin>>accountname;
	            cout<<"Enter your accountnumber : ";
	            cin>>accountnumber;
	            cout<<endl;
			}
			//second method of bank class:
			void deposit(){
				double amount;
				cout<<"Enter amount for deposit";
				cin>>amount;
				if(amount>0){
				balance+=amount;
				cout<<"Your deposit successfull Rs:"<<amount<<"/-";
				cout<<endl;
				cout<<endl;
				}
				else{
					cout<<"plz enter valid amount";
					cout<<endl;
				}
			}
			
			//third methiod of bank class
			void withraw(){
				int amount;
				cout<<"Enter amount for withraw";
				cin>>amount;
				
				if(amount < balance){
					balance = balance - amount;
					cout<<"Your balance is Rs:"<<balance<<"/-";
					cout<<endl;
				}
				else{
					cout<<"----- your balance is low ------";
					cout<<endl;
				}
			}
			
			//four method of bank class:
			void getbalance(){
				cout<<"Your current balance is Rs:"<<balance<<"/-";
				cout<<endl;
			}
			
			//five method of bank class:
			void displayaccountinfo(){
				cout<<"Your AccountName : "<<accountname<<endl<<"your AccountNumber : "<<accountnumber;
				cout<<endl;
			}
};

//class of savingaccount to inherit bankaccount:

class Savingaccount : public BankAccount{
	public:
		//first method of class:
		void calculateinterest(double I_rate){
			double interest = balance * I_rate; //formula of savinginterest
			
			cout<<"your interest is Rs:"<<interest<<"/-";
			balance+=interest;
			cout<<endl;
			cout<<"Total Balance is Rs:"<<balance;
		}
};

//class of fixed deposit to inherited to bankaccount:

class Fixeddeposit : public BankAccount{
	public:
		//first method of class:polymorphism
	void calculateinterest(){
		double amount,rate=0.06,term;
		cout<<"Enter your amount for fixed deposit ";
		cin>>amount;
		if(amount>0){
		
		cout<<"Your amount deposit successfully Rs:"<<amount;
		cout<<endl;
		cout<<"\nEnter your Month for fixed deposit";
		cin>>term;
		
		double fd = amount * rate *(term/12);//formula of fixed deposit
		amount+=fd;
		cout<<"\nYour "<<term<<" Month fixed deposit interest Rs:"<<fd<<"/-";
		cout<<endl;
		cout<<"\nYour balance is Rs:"<<amount;
	}
	else{
		cout<<"Plz enter a valid amount";
	}
	}
};

int main(){
	cout<<"\t\t                   Welcome SBI Bank System";
	cout<<endl;
	int mainchoice;
	cout<<"\npress 1 for saving account\npress 2 for fixed deposit";
	//choice of account type:
	cin>>mainchoice;
	
	if(mainchoice==1){
	Savingaccount obj;
	cout<<endl;
	obj.getdata();
	int choice;
	do{
	//choice of service type:
	cout<<"Press 1 for deposit\npress 2 for withraw\npress 3 for getbalance\npress 4 for displayaccountinfo\npress 0 for EXIT";
    cin>>choice;
    cout<<endl;
    switch(choice){
    	case 1:
    		obj.deposit();
    		break;
    	case 2:
    		obj.withraw();
    		break;
    	case 3:
    		obj.getbalance();
    		break;
    	case 4:
    		obj.displayaccountinfo();
    		break;
    	case 0:
    		cout<<"EXIT";
    		break;
    	default:
    		cout<<"invalid choice";
	}
    }while(choice!=0);
    cout<<endl;
    obj.calculateinterest(0.04);
}else if(mainchoice == 2){
	Fixeddeposit obj1;
	obj1.getdata();
	obj1.calculateinterest();
}else{
	cout<<"invalid choice";
}
	
	return 0;
}


