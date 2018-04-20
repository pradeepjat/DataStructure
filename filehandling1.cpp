/*
   Objective:- To demostrate write and read values using variables in/from file and  usage of tellg() , tellp() , seekp() and seekg()  function.
   input parrameter : 
                  name-> char type variable
                  course-> char type variable
                  rollNo-> int type variable
                  file->fstream type variable;
	
	Defination :-
	    seekg() -> used to move the get pointer to a desired location with respect to a reference point.
		tellg() -> used to know where the get pointer is in a file			   
		seekp() -> used to move the put pointer to a desired location with respect to a reference point.
        tellp() -> used to know where the put pointer is in a file.
*/
#include <iostream>
#include <fstream>
#define FILE_NAME "student.txt"

using namespace std;

int main()
{
  int rollNo;
  char name[20];
  char course[20];	
  cout<<"ENTER STUDENT NAME :  "<<endl;
  cin.getline(name,20);	
  cout<<"ENTER STUDENT COURSE : "<<endl;
  cin.getline(course,20);
  cout<<"ENTER STUDENT ROLL NUMBER :   "<<endl;
  cin>>rollNo;
  fstream file;
  
  file.open(FILE_NAME,ios::out);
  file<<name<<rollNo<<course;
  cout<<"Current Position of file pointer is :"<<file.tellp()<<endl;   //to tell curent position of pointer
  file.seekp(-2,ios::cur);//to change a curent position to any position of pointer
  cout<<"after seekp Position of file pointer is :"<<file.tellp()<<endl;   //to tell curent position of pointer
  file.close();	
  
  file.open(FILE_NAME,ios::in);
  file>>name;
  cout<<"Current Position of file pointer is :"<<file.tellp()<<endl;   //to tell curent position of pointer
  file.seekp(2,ios::beg);//to change a curent position to any position of pointer
  cout<<"after seekp Position of file pointer is :"<<file.tellp()<<endl;   //to tell curent position of pointer
  cout<<"\t\t"<<name;
  file.close();
  return 0;
}

