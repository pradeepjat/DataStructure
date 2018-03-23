#include <iostream>
#include <cstdlib>
#define SIZE 10

using namespace std;

template <class T>
class circularqueue 
/*
	objective: Create a class for implementing circular queue using array
	input parameters: 
	               front -> front index of a circular queue
	               rear -> last or a top element of circular queue 
	               capacity-> size of circular queue
	               arr -> pointer to array  
	output -> templete of a circular queue of maximum size 100 
	
	Description: 
	        Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) 
			principle and the last position is connected back to the first position to make a circle. It is also called 'Ring Buffer
	approach: Class defines data member and member function of the queue class
	*/



{

	T *arr;			// array to store queue elements

	int capacity;			// maximum capacity of the circular Q

	int front;			// front points to front element in the circular Q

	int rear;			// rear points to last element in the circular Q

	int count;			// current size of the circular Q



public:

	circularqueue(T size = SIZE)		// constructor
	{
  	    arr = new int [size];   //dynamicly allocate a size to array
		capacity=size;
		front=-1;
		rear=-1;
	}
	~circularqueue()
	{
		delete arr;                 // deconstructor
	}	

	void dequeue()
	{
	   if(isEmpty()==true)
	   {
	      cout<<"Circular Queue is Empty!"; 	
	   }	
	   else if(front==rear)
	   {
	      front=-1;
		  rear=-1;
	   }
	   else
	   {
	   	 front=(front+1)%capacity;
	   }
	}

	void enqueue(T &x)
	{
		if(isFull()==true)    //checking whether circular Queue is full or not!
		{
			cout<<"Queue Is Full!"<<endl;
		}
		else
		{
		  if(front==-1 && rear ==-1)
		  {
		  	front = front+1;
		  	rear = rear+1;
		  	arr[rear]=x;
		  }
		  else
		  {
		  	rear = (rear+1)%capacity;
		  	arr[rear]=x;
		  }
		  
	    }
	}

	int peek()				// returns front element
    {
       return(arr[rear]);
	}
	int size()			// returns current size of circular Queue
	{
		return((rear+1)%capacity);
	}

	bool isEmpty()
	{
		if(front==-1 && rear==-1)
		{
			return true;
		}
		else
		{
		   return false;
	    }
	}

	bool isFull()     //checking whether circular Queue is full or not!
	{
	  if((rear+1)%capacity==front)
	  {
	  	return true;
	  }	
	  else
	  {
	  	return false;
	  }
	  
	}
	
	void show()    // To Display the circular queue
	{
		int temp;  // temprorily store the value of the circular queue
		temp=front;
		if(isEmpty()==true)
		{
			cout<<"Queue is empty";
		}
		else
		{
			while(rear!=temp)
			{
				cout<<arr[temp]<<"\t";   //Displying element of the circular Queue
				temp=temp+1;
			}
				cout<<arr[temp]<<endl;
		}
	}

};

int main()
{
  char choice1='y';
  circularqueue<int> s;     // Creating object of Queue
  	
  cout<<"---Operation on Stack-----"<<endl;
  cout<<"1) Enqueue"<<endl;
  cout<<"2) Dequeue"<<endl;
  cout<<"3) Peek element to Queue"<<endl;
  cout<<"4) Size to Queue"<<endl;
  cout<<"5) check whether Queue is empty or not"<<endl;
  cout<<"6) check whether Queue is full or not"<<endl;
  cout<<"7) print a Queue"<<endl;
  int choice;
  do
  {
  	cout<<"Enter your choice"<<endl;
    cin>>choice;
     switch(choice)
     {
  	     case 1:
  		    int element;
  		    cout<<"Enter the element to Enqueue a Queue "<<endl;
  		    cin>>element;
  		    s.enqueue(element);
  		    break;
  	     case 2:
  	     	if(s.isEmpty()==true)
  	     	{
  	     		cout<<"Queue is empty"<<endl;
		    }
		    else
			{
  		       s.dequeue();
  		    }
	        break;	
	     case 3:
	     	element=s.peek();
	     	cout<<"top of the Queue : "<<element<<endl;
  	    	break;
  	     case 4:
		    cout<<"size is : "<<s.size()<<endl;
			break;	
  	     case 5:
		   if(s.isEmpty()==true)
		   {
		   	cout<<"TRUE Queue is empty"<<endl;
		   }
		   else
		   {
		   	cout<<"false Queue is not empty"<<endl;
		   }
		   break;
		 case 6:
		   if(s.isFull()==true)
		   {
		   	cout<<"TRUE Queue is full"<<endl;
		   }
		   else
		   {
		   	cout<<"false Queue is not full"<<endl;
		   }
		   break;	
  	     case 7:
  	     	if(s.isEmpty()==true)
  	     	{
  	     	   cout<<"Queue is empty!";	
		    }
		    else
		    {
		      cout<<"element in Queue is"<<endl;
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
