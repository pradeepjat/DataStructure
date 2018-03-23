#include <iostream>
#include <cstdlib>
#define MAXSIZE 100  // or const int MAXSIZE=100;

using namespace std;

template <class T>
class stack
	/*
	objective: Create a class for implementing Stack using array
	input parameters: 
	               top -> top index of stack
	               capacity-> size of stack
	               arr -> pointer to array  
	output -> templet of a stack of maximum size 100 
	
	Description: 
	        Stack is a data structure used to store a collection of objects in LIFO(last in first out) manner. 
	        Individual items can be added and stored in a stack using a PUSH operation And Remove using POP operation.
	approach: Class defines data member and member function of the stack class
	*/
{
	T *arr;					// for dynamic array 
	int top;
	int capacity;					// checks size defined by user
public:
	stack(T size = MAXSIZE) // constructor to create array dynamically
	{
		arr = new int [size];   //dynamicly allocate a size to array
		capacity=size;
		top=-1;
		
	}			
	~stack()     // destructor to delete dynamically created array
	{
		delete arr;
	}					
	void push(T &x)   //function to push a value into the stack
	{
		if(isFull()==true)    //checking whether stack is full or not!
		{
			cout<<"Stack Is Full!"<<endl;
		}
		else
		{
		  top=top+1;   //Inserting a value into the stack
		  arr[top]=x;
	    }
	}
	
	T pop()
	{
		  T x = arr[top--];    //Removing a value into the stack
		  return x;
	}
	T peek()         //Top of the the stack
	{
		return(arr[top]);
	}
	
	int size()     	// Current size of stack
	{
		return(top+1);
	}				
	bool isEmpty()    //checking whether stack is empty or not!
	{
		if(top==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()     //checking whether stack is full or not!
	{
	  if(top==capacity)
	  {
	  	return true;
	  }	
	  else
	  {
	  	return false;
	  }
	  
	}
	void show()    // To Display the stack
	{
		int temp;  // temprorily store the value of the stack
		temp=top;
		int i=0;
		if(isEmpty()==true)
		{
			cout<<"Stack is empty";
		}
		else
		{
			while(i<=temp)
			{
				cout<<arr[i]<<"\t";   //Displying element of the stack
				i=i+1;
			}
		}
	}
	
};

int main()
{
  char choice1='y';
  stack<int> s;     // Creating object of stack
  	
  cout<<"---Operation on Stack-----"<<endl;
  cout<<"1) Push a element to stack"<<endl;
  cout<<"2) Pop a element to stack"<<endl;
  cout<<"3) Peek element to stack"<<endl;
  cout<<"4) Size to stack"<<endl;
  cout<<"5) check whether stack is empty or not"<<endl;
  cout<<"6) check whether stack is full or not"<<endl;
  cout<<"7) print a stack"<<endl;
  int choice;
  do
  {
  	cout<<"Enter your choice"<<endl;
    cin>>choice;
     switch(choice)
     {
  	     case 1:
  		    int element;
  		    cout<<"Enter the element to be pushed into the stack "<<endl;
  		    cin>>element;
  		    s.push(element);
  		    break;
  	     case 2:
  	     	if(s.isEmpty()==true)
  	     	{
  	     		cout<<"stack is empty"<<endl;
		    }
		    else
			{
  		        cout<<s.pop()<<" poped from the stack"<<endl;
  		    }
	        break;	
	     case 3:
	     	element=s.peek();
	     	cout<<"top of the stack : "<<element<<endl;
  	    	break;
  	     case 4:
		    cout<<"size is : "<<s.size()<<endl;
			break;	
  	     case 5:
		   if(s.isEmpty()==true)
		   {
		   	cout<<"TRUE stack is empty"<<endl;
		   }
		   else
		   {
		   	cout<<"false stack is not empty"<<endl;
		   }
		   break;
		 case 6:
		   if(s.isFull()==true)
		   {
		   	cout<<"TRUE stack is full"<<endl;
		   }
		   else
		   {
		   	cout<<"false stack is not full"<<endl;
		   }
		   break;	
  	     case 7:
  	     	if(s.isEmpty()==true)
  	     	{
  	     	   cout<<"stack is empty!";	
		    }
		    else
		    {
		      cout<<"element in stack is"<<endl;
		      s.show();
		    }
		    break;	
	     default:			
            cout<<"enter the right choice";
     }
     cout<<"Press y for continue"<<endl;
     cin>>choice1;
  }while(choice1=='y'||choice1=='Y');
}
