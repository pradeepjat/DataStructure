/*
    Author @ Pradeep Kumar
    Objective : To Create Stack Using STL Queue  
    Function :- 
	   main()
                -> Creating Stack Using STL Queue
                Parameter ->
                     choice ->character type variable use for switching
                     choice1 ->character type variable use for whether user continue the programe or exit
				     a -> Queue type variable
				     b -> Queue type variable
				     temp -> Queue type variable to display a queue
    
    Result: we get a Stack from a Queue   
*/
// Approach : Take a two Queue for push enqueue a value into the first queue and for pop dequeue the 1st Queue and store it into 2nd Queue except last one and dequeue 
//            the value from 1nd Queue 
#include<iostream>
#include<queue>

using namespace std;

int main()
{
  int choice,enq;
  char choice1;
  queue <int> a;
  queue <int> b;	
  queue <int> temp; 
  
  cout<<"1) Push element into the Stack"<<endl;
  cout<<"2) Pop element into the Stack"<<endl;
  cout<<"3) Print the stack"<<endl;
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
    		if(a.empty())
    		{
    			cout<<"Stack is Empty!";
			}
    		else
    		{
    			int size = a.size();
  		       for(int i=0;i<size-1;i++)               //dequeue
  		       {
  		          b.push(a.front());
  		          a.pop();
	           }
	           b.pop();
	           while(!b.empty())
  		       {
  		         a.push(b.front());
  		         b.pop();
	           }
	        }
	        break;
	    case 3:
		    temp = a;
		    while(!temp.empty())               //dequeue
  		    {
  		      cout<<temp.front()<<"   ";
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


