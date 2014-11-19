CSCI1---Student-Grade-Report
============================

CSCI Assignment 5 - Student Grade report

Program statement *  
This program will get 4 test score and will get average from high three high score. 
* ************************ Analysis *****************************	  
1. Data needed 	

  *File Name(input/output)<br>
  *Name (Full name first and last)<br>
  *Four test scores<br>
  *Average<br>
  *Letter grade for each Aveage<br>
  *Verify input<br>

2. Constants given <br>
	90  <  Average         = A<br>
	80  <  Average <= 90   = B<br>
	67.5<  Average <= 80   = C<br>
	55  <  Average <= 67.5 = D<br>
	0   <  Average <= 55   = F<br>

3. Calculations 	
Average = (test1+test2+test3+test4 - lowest score) / 3


4. Print results<br>
	*Assigned part<br>
	Name<br>
	Four Test scores<br>
	Average<br>
	Letter Grade<br>

	*For Fun part<br>
	Name<br>
	Four Test scores<br>
	Lowest score<br>
	Average<br>
	Letter Grade<br>


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
