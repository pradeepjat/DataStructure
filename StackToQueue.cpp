/*
    Author @ Pradeep Kumar
    Objective : To Create Queue Using STL stack  
    Function :- 
	   main()
                -> Creating Queue Using STL stack
                Parameter ->
                     choice ->character type variable use for switching
                     choice1 ->character type variable use for whether user continue the programe or exit
				     a -> stack type variable
				     b -> stack type variable
				     temp -> stack type variable to display a queue
    
    Result: we get a queue from a stack   
*/
// Approach : Take a two Stack for enqueue push a value into the first stack and for dequeue pop the stack 1st and store it into 2nd stack and pop 
//            the value from 2nd stack 
#include<iostream>
#include<stack>

using namespace std;

int main()
{
  int choice,enq;
  char choice1;
  stack <int> a;
  stack <int> b;	
  stack <int> temp; 
  
  cout<<"1) Enqueue the Queue"<<endl;
  cout<<"2) Dequeue the Queue"<<endl;
  cout<<"3) Print the Queue"<<endl;
  do
  {
      cout<<"Enter Your Choice"<<endl;
      cin>>choice;
      switch(choice)
      {
   	    case 1:
  	    	cout<<"Enter value to be enqueue"<<endl;            //enqueue
  	    	cin>>enq;
  	     	a.push(enq);
  	    	break;
    	case 2:
    		if(a.empty()) //checking weather queue is empty or not
    		{
    			cout<<"Queue is Empty!";
			}
    		else
    		{
  		       while(!a.empty())               //dequeue
  		       {
  		          b.push(a.top());
  		          a.pop();
	           }
	           b.pop();
	           while(!b.empty())
  		       {
  		         a.push(b.top());
  		         b.pop();
	           }
	        }
	        break;
	    case 3:
		    temp = a;
		    while(!temp.empty())               //dequeue
  		    {
  		      cout<<temp.top()<<"   ";
  		      temp.pop();
	        }
	        break;
	    default :
	         cout<<"Please Enter the right choice";	  	 	
      }
      cout<<"Press Y for continue"<<endl;
      cin>>choice1;
  }while(choice1=='y'||choice1=='Y');
}


