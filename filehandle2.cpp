/*
   Objective:- To write and read object using read and write function.
   input parrameter : 
                  name-> char type variable
                  course-> char type variable
                  rollNo-> int type variable
                  dob->
                     ddb->int type variable
                     mmb->int type variable
                     yyb->int type variable
                  file->fstream type variable;
	
	function :-
	   	readStudent()->void type function used to take input from user
//	   	displayStudent()->void type function used to display
*/

#include <iostream>
#include <fstream>
#define FILE_NAME "student.txt"

using namespace std;

//class student declaration
class Student {
private : 
	int 	rollNo;
	char 	name[20] ;
	char 	course[20];
	int 	ddb,mmb,yyb;
public  :
	//function to read student details
	void readStudent(){
		cout<<"STUDENT DETAILS"<<endl;
		cout<<"ENTER STUDENT ROLL NO. : " ;
		cin>>rollNo;
		cin.ignore(1);
		cout<<"ENTER  NAME OF THE STUDENT : ";
		cin.getline(name,20);

		cout<<"ENTER COURSE : ";
		cin.getline(course,20);
		
		cout<<"ENTER DATE OF BIRTH:"<<endl;
		cout<<"DATE : "; cin>>ddb;
		cout<<"MONTH: "; cin>>mmb;
		cout<<"YEAR : "; cin>>yyb;
	}
	//function to write student details
	void displayStudent(){
		cout<<"EMPLOYEE ID: "<<rollNo<<endl
		 <<"EMPLOYEE NAME: "<<name<<endl
		 <<"DESIGNATION: "<<course<<endl
		 <<"DATE OF BIRTH: "<<ddb<<"/"<<mmb<<"/"<<yyb<<endl;
	}
};

int main(){
	
	//object of Student class
	Student stu;
	//read student details
	stu.readStudent();
	
	//write object into the file
	fstream file;
	file.open(FILE_NAME,ios::out);
	if(!file){
		cout<<"Error in creating file...\n";
		return -1;
	}
	
	file.write((char*)&stu,sizeof(stu));
	file.close();
	cout<<"Date saved into file the file.\n";
	
	//open file again 
	file.open(FILE_NAME,ios::in);
	if(!file){
		cout<<"Error in opening file...\n";
		return -1;
	}
	
	if(file.read((char*)&stu,sizeof(stu))){
			cout<<endl<<endl;
			cout<<"Data extracted from file..\n";
			//print the object
			stu.displayStudent();
	}
	else{
		cout<<"Error in reading data from file...\n";
		return -1;
	}
	
	file.close();	
	return 0;
}

