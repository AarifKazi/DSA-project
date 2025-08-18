#include <iostream>
using namespace std;
#include <stack>  //headerfile of stack


int main(){
    stack <int> value;   //declare stack
    
    int size,i,choice,v;  //variable
    
    
    //For multiple method using do while
    do{
    cout<<"press 1 for push \npress 2 for pop\npress 3 for Display top the Element\npress 4 for empty\npress 5 for fullstack\npress 0 for exit";
    cin>>choice;
    switch(choice){
        case 1:
           //push method
           cout<<"How many enter value for stack";
           cin>>size;
           for(i = 0; i < size; i++){
               cout<<"Enter "<<i+1<<" value";
               cin>>v;
               
               value.push(v);
           }
           cout<<endl;
           
           break;
           
        case 2:
        //pop method
        if(!value.empty()){
            cout<<"Popped value from stack "<<value.top();
            value.pop();
        }
        else{
            cout<<"Stack is empty";
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        break;
        
        case 3:
        //for display top value
        if(!value.empty()){
            cout<<"top value from stack "<<value.top();
        }
        else{
            cout<<"Stack is empty";
        }
        cout<<endl;
        cout<<endl;
        break;
        
        case 4:
        //check empty stack
          if(value.empty()){
              cout<<"Stack is empty";
          }
          else{
              cout<<"Stack is not empty";
          }
          cout<<endl;
          cout<<endl;
          break;
          
        case 5:
        //check full stack
         if(!value.empty()){
             cout<<"Stack is Almost Full";
         }
         else{
             cout<<"Stack is not full";
         }
         cout<<endl;
         cout<<endl;
         break;
         
        case 0:
           cout<<"Exit";
           break;
           
         default:
         cout<<"invalid choice";
         cout<<endl;
         break;

         
    }
    }while(choice != 0);
    
    
    //print of stack value after uisng method
    while(!value.empty()){
        cout<<value.top()<<" ";
        value.pop();
    }
    
    
    return 0;
}