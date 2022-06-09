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
	out << st.rNo << ' ' /*<< left*/ << setw(10) << st.fName << ' ' << setw(10) << st.sName ;
	return out;
}
class Classroom{
public:
Student x;

	float cgpa;
 public:
  Classroom(){}
  Classroom(char fn[],  char sn[],  char r[], float cgpa){
      x.set(fn,sn,r);
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
	//char fName[COUNT][10]={"TALHA", "HASEEB ","Muhammad", "GULFAM","ABID","AHMAD","SAIF-UR","HAFIZ","ABDULLAH","ABDULLAH","ALI","FAHAD","HUZIFA","HURARA","USAMA","ABDUL","ASHHAD","NOFIL","MUHAMMAD","AHMAD","MUHAMMAD","ZARRAR","HASEEB","WALEED","ABDUL","LAIBA","Fatima","IBRAR","USAMA","AFAQ","AHMAD","UMAR","ROHSHAAN","UNAIZA","MUHAMMAD","ABDULLAH","MUHAMMAD","HASSAN","ABDUL","MUHAMMAD","ABDUALLAH","HAMZA","JUNAID","MUHAMMAD","FAROGH","MUHAMMAD","HADEED","ABDULLAH","ARSLAN","IMAN","ALI","ABU","MUHAMMAD"};
	//char sName[COUNT][10]={"EJAZ", "RASUl", "HASHIR", "ZAFAR","ALI","ALI","REHMAN","REHAN","ASLAM","KHAN","NAVEED","MUSTJAB","ABRAR","ISRAR","ADIL","WAHAB","HASEEN","QASIM","TANZEEL","MUKHTAR","ABUBAKAR","ALI","RAZA","BUTT","RAUF","AHMED","Noor","MUNAWAR","AHMED","AHMED","GHANI","ABDULLAH","PASHA","NASIR","SAIF","KALEEM","ABUBAKAR","ALI","MUQEET","OSAMA","NADEEM","SOHAIL","ALAM","AWAIS","ABIDI","FARHAN","BUTT","BUKHARI","AHMAD","ZAHRAA","KHAN","HURARA","MUBEEN"};
	//char rNo[COUNT][11]={"BCSF198518","BCSF18A547","BCSF18A503","BCSF19A501","BCSF19A502","BCSF19A503","BCSF19A504","BCSF19A505","BCSF19A506","BCSF19A507","BCSF19A508","BCSF19A509","BCSF19A510","BCSF19A511","BCSF19A512","BCSF19A513","BCSF19A514","BCSF19A515","BCSF19A516","BCSF19A517","BCSF19A518","BCSF19A519","BCSF19A520","BCSF19A521","BCSF19A523","BCSF19A524","BCSF19A526","BCSF19A528","BCSF19A529","BCSF19A530","BCSF19A531","BCSF19A532","BCSF19A533","BCSF19A534","BCSF19A535","BCSF19A536","BCSF19A537","BCSF19A538","BCSF19A539","BCSF19A540","BCSF19A541","BCSF19A542","BCSF19A543","BCSF19A544","BCSF19A545","BCSF19A546","BCSF19A547","BCSF19A548","BCSF19A549","BCSF19A550","BCSF19A553","BCSF19A556","BCSF19A559"};
	//float cgpas[COUNT]={3.15,3.2,2.86,3.34,3.78,3.23,3.45,2.7,2.34,1.8,4.00,2,3,4,4,2.33,3.33,2.22,3.23,2,2,3,2.3,4,2.33,1.8,3.44,3.21,3.33,2.33,2.44,2.44,3.22,3.44,3.55,1.99,3.5,3.22,3.66,3.44,4.00,2,3,4,4,2.33,3.33,2.22,3.23,2,2,3,2.3};
	int i, choice, count, n;
	char fn[10], sn[10], r[11];
	float cgpa;
	Classroom student, *newS;
	//for (i=0;i<COUNT;i++)
	//	s[i].set(fName[i], sName[i], rNo[i], cgpas[i]);
	fstream file("students.bin", ios::binary | ios::in | ios::out);
	if (file.fail()){//check if file successfully opened
		ofstream out("students.bin");//Otherwise create a new file
		out.close();				//close file
		file.open("students.bin", ios::binary | ios::in | ios::out);//Reopen in reading+writing mode
	}
	//file.write ( (char*) s, sizeof(Classroom) * COUNT );

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
				count = file.tellg() / sizeof(Classroom);//Counting number of objects
				file.seekg(0);
				newS = new Classroom [count];	
				file.read ( (char*) newS, sizeof(Classroom) * count );
				for (i=0;i<count;i++)
					
					cout << newS[i];
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
				if (n > count){	//Check file has n records?
					if (count == 0) cout << "Sorry no record in the file\n";
					else			cout << "Sorry, File has less than n records\n";
					break;
				}
				file.seekg(0);
				newS = new Classroom [count];	
				file.read ( (char*) newS, sizeof(Classroom) * count );		
				n--;
				file.close();
				remove ("students.bin");//delete complete file

				ofstream out ("students.bin",ios::binary);//file recreated
				out.write ( (char*) &newS[0], sizeof(Classroom)* n );	//store first n-1 records
				//Skip nth record and store next records
				out.write ( (char*) &newS[n+1], sizeof(Classroom)* (count-n-1) );							
				out.close();	//close file
				delete []newS;	//Delete array
				file.open("students.bin", ios::binary | ios::in | ios::out);//Reopen file
				break;
		}
	}while (choice!=QUIT);
	file.close();
	cout << "\n\n\t\tThanks for using this program\n";
    return 0;
}
