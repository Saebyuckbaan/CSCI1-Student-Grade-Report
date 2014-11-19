/*A complete program 
ID block  ---------------------------------------+ 
+ Programmer : 	Davis Yi  	           	+ 
+ Course     : 	Computer Science 1    	+ 
+ Assignment : 	Assignment 5	      	+ 
+ Due Date   : 	May 18 2009          	+
+----------------------------------------------------
Program statement *  
This program will get 4 test score and will get average from high three high score. 
* ************************ Analysis *****************************	  
1. Data needed 	
File Name(input/output)
Name (Full name first and last) 	
Four test scores
Average
Lettergrade for each Aveage
Verify input
2. Constants given 
	90  <  Average         = A
	80  <  Average <= 90   = B
	67.5<  Average <= 80   = C
	55  <  Average <= 67.5 = D
	0   <  Average <= 55   = F

3. Calculations 	

Average = (test1+test2+test3+test4 - lowest score) / 3


4. Print results
	*Assigned part	
	Name
	Four Test scores
	Average
	Letter Grade

	*For Fun part
	Name
	Four Test scores
	Lowest score
	Average
	Letter Grade


********* Algorithm *********	
Step 1
Input

	*Function - Read
	Prompt Datafile name
	Read Datafile from Textfile

	*Function - Loop
	*Get a name and a 4 scores from each students

	*Function - Verify input
	*print out Bad Data, when scores, Lettergrades are out of score range(0~100)
	*Return to the beginning when people missed spelling of their input text file


Step 2
Process

	*Function - Average
	*Take a average from three highest score
		{(Test score 1 + Test score 2 + Test score 3 + Test score 4 - Lowest) / 3}

	*Function - Letter Grade
	*Take a Average to this function and match it to letter grade for each average
	*print it out

Step 3

	Function  - Output(Print reports)
  *Assigned Part
	*Print Name
	*Print Score 1 ~ 4
	*Print Average
	*Print LetterGrade
		of each students

  *For Fun Part
	*Print Name
	*Print Score 1 ~ 4
	*Print Lowest Score
	*Print Average
	*Print LetterGrade
		of each students

  *Errors
	*Print error message when user gave wrong input text file
	*Print BadData when people put score that out of range

End of Algorithm
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;


void intro()
{
	cout<<left<<endl;
	cout<<setw(70)<<"*******************************************************************"<<endl;
	cout<<setw(20)<<"*"<<setw(20)<<"Welcome to Davis Yi's Program"<<setw(17)<<""<<"*"<<endl;
	cout<<setw(20)<<"*"<<setw(20)<<"This Program calculates"<<setw(23)<<""<<"*"<<endl;
	cout<<setw(20)<<"*"<<setw(20)<<"Average of four test score"<<setw(20)<<""<<"*"<<endl;
	cout<<setw(20)<<"*"<<setw(20)<<"I hope it helps you a lot"<<setw(21)<<""<<"*"<<endl;
	cout<<setw(20)<<"*"<<setw(20)<<"Thank you :)"<<setw(26)<<""<<"*"<<endl;
	cout<<setw(70)<<"*******************************************************************"<<endl;
	cout<<"\n\n\n"<<endl;
}
bool Get_input(string f_name, ifstream &f_input, ofstream &f_output, ofstream &f_forfun)
{
	cout<<"Please Enter Your Input txt file : ";
	cin>>f_name;
	f_input.open(f_name.c_str());
		if(f_input.fail())
		{
			cout<<"Your Textfile cannot be found, please try again."<<endl;
			return false;
		}

	cout<<"Please Enter Your output txt file : ";
	cin>>f_name;
	f_output.open(f_name.c_str());

	cout<<"Please Enter Your For Fun output txt file : ";
	cin>>f_name;
	f_forfun.open(f_name.c_str());

	return true;
}
string LetterGrading(float Average)
{
	string LetterGrade;
		if(Average>90 && Average<=100)
			LetterGrade="A";
		else if(Average>80 && Average<=90)
			LetterGrade="B";
		else if(Average>67.5 && Average<=80)
			LetterGrade="C";
		else if(Average>55 && Average<=67.5)
			LetterGrade="D";
		else if(Average>0 && Average<=55)
			LetterGrade="F";

	return LetterGrade;
}

void Verification(string FullName, ofstream &f_output)
{
	cout<<setw(20)<<FullName<<setw(20)<<"BadData"<<endl;
	f_output<<setw(20)<<FullName<<setw(20)<<"BadData"<<endl;
}

float AverageCalc(float test1,float test2,float test3,float test4, float LowestDrop)
{
	float Average;
		Average = (test1+test2+test3+test4-LowestDrop) / 3;
		return Average;
}

bool Print(ofstream &f_output, string FullName, float test1 , float test2 , float test3 , float test4, float Average, string LetterGrade)
{
	cout<<setw(20)<<FullName<<setprecision(0)<<setw(8)<<test1<<setw(8)<<test2<<setw(8)<<test3<<setw(8)<<test4<<setprecision(2)<<setw(13)<<Average<<setw(13)<<LetterGrade<<endl;
	f_output<<setw(20)<<FullName<<setprecision(0)<<setw(8)<<test1<<setw(8)<<test2<<setw(8)<<test3<<setw(8)<<test4<<setprecision(2)<<setw(13)<<Average<<setw(13)<<LetterGrade<<endl;
		return true;
}

void Print_Description(ofstream &f_output)
{
		cout<<setw(60)<<"**********************************RESULT**********************************"<<endl;
		cout<<setw(20)<<"Name"<<setw(8)<<"1"<<setw(8)<<"2"<<setw(8)<<"3"<<setw(8)<<"4"<<setw(15)<<"Average"<<setw(15)<<"LetterGrade"<<endl;	
		f_output<<setw(60)<<"**********************************RESULT**********************************"<<endl;
		f_output<<setw(20)<<"Name"<<setw(8)<<"1"<<setw(8)<<"2"<<setw(8)<<"3"<<setw(8)<<"4"<<setw(15)<<"Average"<<setw(15)<<"LetterGrade"<<endl;
}

void ForFun(ofstream &f_forfun, string FullName, float test1, float test2, float test3, float test4,float Average, string LetterGrade, float LowestDrop)
{
	f_forfun<<"\n"<<"*************************************************************"<<endl;
	f_forfun<<"Student Name : "<<FullName<<endl;
	f_forfun<<"Student's score "<<endl;
	f_forfun<<"Test 1 :  "<<test1<<endl;
	f_forfun<<"Test 2 :  "<<test2<<endl;
	f_forfun<<"Test 3 :  "<<test3<<endl;
	f_forfun<<"Test 4 :  "<<test4<<endl;
	f_forfun<<"Student's Lowest score : "<<LowestDrop<<endl;
	f_forfun<<"Student's Average score : "<<Average<<endl;
	f_forfun<<"Student's Letter Grade : "<<LetterGrade<<endl;
	f_forfun<<"*************************************************************"<<"\n"<<endl;

}
void ForFunIntro(ofstream &f_forfun)
{
	f_forfun<<"This data is more specific data for each student"<<endl;
	f_forfun<<"Bad Data will skip automatically"<<endl;
	f_forfun<<"Thank you for choosing my Program"<<endl;
}
float Drop_Lowest(float test1,float test2,float test3,float test4)
{	float lowest = 0; 

	if(test1 < test2 && test1 < test3 && test1 < test4)
	{
		lowest = test1;
	}
	else if(test2 < test1 && test2 < test3 && test2 < test4)
	{	
		lowest = test2;
	}
	else if(test3 < test2 && test3 < test1 && test3 < test4)
	{	
		lowest = test3;
	}
	else if(test4 < test2 && test4 < test3 && test4 < test1)
	{	
		lowest = test4;
	}
	else if(test1 == test4 || test1 == test3 || test1 == test2 || test2 == test3 || test2 == test1 || test2 == test4 || test3 == test1 || test3 == test2 || test3 == test4 || test4 == test1 || test4 == test2 || test4 == test3)
	{
		lowest = test1;
	}
	return lowest;
}
int main()
{		
		ifstream f_input;
		ofstream f_output, f_forfun;
		string f_name, FullName;
		float test1, test2, test3, test4, Average, LowestDrop;
		string LetterGrade;
		bool flag;

		cout<<setprecision(2)<<fixed<<left<<endl;
	intro();
	flag = Get_input(f_name, f_input, f_output, f_forfun);
	if(flag == 0)
	{
		return 0;
	}
	else if(flag == 1)
	{
	Print_Description(f_output);
	ForFunIntro(f_forfun);
	getline(f_input, FullName);
		while(!f_input.eof())
		{
			f_input>>test1>>test2>>test3>>test4;
				if(test1>100 || test1<0 || test2>100 || test2<0 || test3>100 || test3<0 || test4>100 || test4<0)
				{
					Verification(FullName, f_output);
				}
			else if(!(test1>100 || test1<0 || test2>100 || test2<0 || test3>100 || test3<0 || test4>100 || test4<0))
			{
				LowestDrop = Drop_Lowest(test1,test2,test3,test4);
				Average = AverageCalc(test1, test2, test3, test4, LowestDrop);
				LetterGrade = LetterGrading(Average);
					if(Average > 0 && Average <= 100)
						{
							Print(f_output, FullName, test1, test2, test3, test4, Average, LetterGrade);
							ForFun(f_forfun, FullName ,test1, test2, test3, test4, Average, LetterGrade, LowestDrop);
						}
					else if(Average < 0 && Average > 100)
						Verification(FullName, f_output);
			}
			f_input.ignore();
			getline(f_input, FullName);
		}
	}
	cout<<endl;
	f_output<<endl;
	f_input.close();
	f_output.close();
	f_forfun.close();
	return 0;
}
