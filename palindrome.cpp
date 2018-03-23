/*
    Author @ Pradeep Kumar
    Objective : To Check Whether a string enter by user is palindrome or not! By using STL Stack and STL Queue  
    Function :- 
	   main()
                -> Checking Whether a string enter by user is palindrome or not!
                Parameter ->
                     str-> string type variable store a string enter by user
                     reverse -> string type variable store a reverse of a string
				     len -> int type variable store size of string 
				     s -> stack type variable
				     q -> queue type variable
    
    Result: a conclusion whether a string is palindrome or not      
    palindrome -> if the reverse of that number is equal to the original number
*/
// Approach : Itrative
#include<iostream>
#include<string.h>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	string str,reverse ;
	cout<<"Enter the string : ";  
	getline(cin,str);
	int len= str.size();
	stack <char> s;   //Defining a stack
    queue <char> q;  //Defining a queue
	
	for(int i=0;i<len;i++)
	{
		s.push(str[i]);       //pushing a value into stack
	}
	
    for(int i=0;i<len;i++)
    {
    	
    	q.push(s.top());     //pop the value from stack and enque into the queue
    	s.pop();
	}
	
	for(int i=0;i<len;i++)
    {
       reverse=reverse+q.front();  //concatinating of string reverse with the front of queue
       q.pop();                    // dequeue
	}
	
	cout<<"\nenter string is "<<str;
	cout<<"\nreverse string is "<<reverse;
	cout<<endl;
	if(reverse==str)            //Checking weather queue is palindrome or not
	{
		cout<<"String is Palindrome";
	}
	else
	{
		cout<<"String is not Palindrome";
	}
	
}

