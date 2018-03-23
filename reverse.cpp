/*
    Author @ Pradeep Kumar
    Objective : To Reverse a string  By using STL Stack
    Function :- 
	   main()
                -> Reversing a string
                Parameter ->
                     str-> string type variable store a string enter by user
				     len -> int type variable store size of string 
				     s -> stack type variable
    
    Result: reverse string   
*/
// Approach : Itrative
#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

int main()
{
	string str;
	cout<<"Enter the string : "<<endl;  
	getline(cin,str);
	cout<<endl;
	int len= str.size();
	stack <char> s;   //Defining a stack
    cout<<"string before reverse : "<<str<<endl;
	for(int i=0;i<len;i++)
	{
		s.push(str[i]);       //pushing a value into stack
	}
	str.clear();   //clearing a string
    for(int i=0;i<len;i++)
    {
    	
    	str=str+s.top();     //pop the value from stack and enque into the queue
    	s.pop();
	}
	 cout<<"string after reverse : "<<str<<endl;

}

