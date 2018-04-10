/*
    Author @ Pradeep Kumar
    Objective : To Create Queue Using STL Link List  
    Function :- 
	   main()
                -> Creating Queue Using STL Link List 
                Parameter ->
                     choice ->character type variable use for switching
                     choice1 ->character type variable use for whether user continue the programe or exit
				     l -> list type variable
    
    Result: we get a Queue from a link list   
*/
// Approach : Take a Stl list and use a inbuilt function list.push_back(element) to Enqueue a value into Queue and use list.pop_front() to Dequeue a Queue 

#include<iostream>
#include<list>
#include<conio.h>

using namespace std;

int main()
{
	list <int> l;       
	list <int> temp;
	int choice,element;
	char choice1;
	
	cout<<"1) Enqueue a queue"<<endl;
	cout<<"2) Dequeue a queue"<<endl;
	cout<<"3) Print a Value Of queue"<<endl;
	
	do
	{
	    cout<<"Enter Your Choice"<<endl;
	    cin>>choice;
	    switch(choice)
	    {
	  	  case 1:
	  	  	cout<<"Enter Value to be Enqueue into Queue"<<endl;
	  	  	cin>>element;
			l.push_back(element) ;
			break;
		  case 2:
		     if(l.empty())
			 {
			    cout<<"Queue is empty !"<<endl;
			 }	
	  	     else
	  	     {
	  	        l.pop_front();	
		     }
		     break;
		  case 3:  
		      for (list<int>::iterator i = l.begin(); i != l.end(); ++i)
               cout << *i <<"   ";
              break;
           default :
		        cout<<"please enter right option !"<<endl;  
	    }
	    cout<<" Press y for continue......"<<endl;
	    cin>>choice1;
	     		
	}while(choice1 == 'y'||choice1 == 'Y');
}
