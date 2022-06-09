#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string.h>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>
#include<fstream>
using namespace std;


class Student{
public:

	char fName[10], sName[10], rNo[11];

public:
	Student(){}
	Student(const char fn[], const char sn[], const char r[]){
			set(fName, sName, rNo);
		}
	void set(const char fn[], const char sn[], const char r[]){
		strcpy(fName, fn);
		strcpy(sName, sn);
		strcpy(rNo, r);

	}
	friend ostream& operator << (ostream &,  Student &);

};
ostream& operator << (ostream &out,  Student &st){
	out << st.rNo << ' ' << setw(10) << st.fName << ' ' << setw(10) << st.sName ;
	return out;
}
class Classroom{
public:
Student x;

	float cgpa;
 public:
  Classroom(){}
  Classroom(char fn[],  char sn[],  char r[], float cgpa):x(fn,sn,r){
     // x.set(fn,sn,r);
	  this->cgpa = cgpa;
  }
  void set(char fn[],  char sn[],  char r[], float cgpa){
	x.set(fn,sn,r);
	  this->cgpa = cgpa;
  }
  void setfname(char fname[]){
	  strcpy(x.fName,fname);
  }
    void setsname(char sname[]){
	  strcpy(x.sName,sname);
  }
  void setrNo(char rno[]){
	  strcpy(x.rNo,rno);
  }
  void setcgpa(float cgpa){
	  this->cgpa=cgpa;
  }
char* getfName(){
	return x.fName;
}
char* getsName(){
	return x.sName;
}
char* getrNo(){
	return x.rNo;
}
float getcgpa(){
	return cgpa;
}

    
	friend ostream& operator << (ostream & ,  Classroom &);

};
 ostream& operator << (ostream &out,  Classroom &c){
	 out<<c.x;
	 out<<setw(10)<<fixed<< setprecision(2)<<c.cgpa<<"\n";
	 return out;
	 
 }
int main(){
	#define COUNT 53
    //int size=5;
	#define QUIT 5
    Classroom s[COUNT];
	int i, choice, count, n;
	char fn[10], sn[10], r[11];
	float cgpa;
	Classroom student, *newS;
	fstream file("students.bin", ios::binary | ios::in | ios::out);
	if (file.fail()){
		ofstre#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string.h>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>
#include<fstream>
using namespace std;

class Time 
{
private:
	int min;
	int sec;
	//int sub;
public:
	
	Time(int min=0, int sec=0)
	{
		this-> min = min;
		this-> sec = sec;
	}
	void settimemin(int min)
	{
		this->min = min;
	}
	void settimesec(int sec)
	{
		this->sec = sec;
	}
	int gettimemin()
	{
		return this-> min;
	}
	int gettimesec()
	{
		return this ->sec;
	}

	/*void result()
	{
		return ;
	}/**/
	Time operator - (Time a)
	{
		Time t2;
		t2.min = this->min - a.min;
		t2.sec = this->sec - a.sec;
		return t2;
		
	}
	friend ostream& operator << (ostream& out, Time st);
	

	


};
ostream& operator << (ostream& out, Time st)
{
	cout << st.gettimemin()<<" " ;
	cout << st.gettimesec()<< " \n";
	return out;
}
int main()
{
	int minutes1, seconds2,re,minutes2, seconds1;
	Time t,t1;

	cout << "Enter time for check in" << endl;
	cin >> minutes1;
	cin >> seconds1;
	t.settimemin(minutes1);
	t.settimesec(seconds1);
	cout << "Enter time for check out" << endl;
	cin >> minutes2;
	cin >> seconds2;
	t1.settimesec(seconds2);
	t1.settimemin(minutes2);
	cout << "Result " << t1 - t;
	


}
10:55 PM
￼￼￼￼
Type a message
am out("students.bin");
		out.close();				
		file.open("students.bin", ios::binary | ios::in | ios::out);
	}
	
	do{
		cout << "\t\t0.	Show all records\n";
		cout << "\t\t1.	Show nth record\n";
		cout << "\t\t2.	Add new record\n";
		cout << "\t\t3.	Modify nth record\n";
		cout << "\t\t4.	Delete nth record\n";
		cout << "\t\t5.	Quit\n";	
		cin >> choice;
		switch (choice){
			case 0://Show All Records
				file.seekg(0, ios::end);
				count = file.tellg() / sizeof(Classroom);
				cout<<"\t\tWelcome to the Computer science departmentment\t\t\n\n";
				cout<<"**Here is the list of the Students**\n ";
				cout<<"Total Numbers of students are: "<<"**"<<count<<"**"<<"\n";
				file.seekg(0);
				newS = new Classroom [count];	
				file.read ( (char*) newS, sizeof(Classroom) * count );
				for (i=0;i<count;i++){
					cout<<i+1<<" ";
					cout << newS[i];
				}
					
				delete []newS;
				break;
			case 1://Show Nth Record
				cout << "Enter Record No:";
				cin >> n;
				n--;
				file.seekg(sizeof (Classroom) * n);
				file.read ( (char*) &student, sizeof(Classroom) );
				cout << student;
				break;
            case 2://Add New Record
				cout << "Enter name of the student:";
				cin >> fn >> sn;
				cout << "Enter roll no of the student:";		
				cin >> r;
				cout << "Enter CGPA of the student:";
				cin >> cgpa;
				student.set (fn, sn, r, cgpa);
				file.seekp(0, ios::end);
				file.write ( (char*) &student, sizeof(Classroom) );
				break;
			case 3://Modify Nth Record
				cout << "Enter Record No:";
				cin >> n;
				n--;
				file.seekp(sizeof (Classroom) * n);
				cout << "Enter name of the student:";
				cin >> fn >> sn;
				cout << "Enter roll no of the student:";		
				cin >> r;
				cout << "Enter CGPA of the student:";
				cin >> cgpa;
				student.set (fn, sn, r, cgpa);
				file.write ( (char*) &student, sizeof(Classroom) );
				break;
			case 4://Delete nth record
				cout << "Enter Record No:";
				cin >> n;
				file.seekg(0, ios::end);
				count = file.tellg() / sizeof(Classroom);
				if (n > count){	
					if (count == 0) cout << "Sorry There are 0 record in the file\n";
					else			cout << "Sorry, File has less than n records\n";
					break;
				}
				file.seekg(0);
				newS = new Classroom [count];	
				file.read ( (char*) newS, sizeof(Classroom) * count );		
				n--;
				file.close();
				remove ("students.bin");

				ofstream out ("students.bin",ios::binary);
				out.write ( (char*) &newS[0], sizeof(Classroom)* n );	
				
				out.write ( (char*) &newS[n+1], sizeof(Classroom)* (count-n-1) );						
				out.close();
				delete []newS;	
				file.open("students.bin", ios::binary | ios::in | ios::out);
				break;
		}
	}while (choice!=QUIT);
	file.close();
	cout << "\n\n\t\tThanks for using this program\n";
    return 0;
}
