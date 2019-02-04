//============================================================================
// Name        : studentdsatution.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*write a C++ program to sore marks scored for first test of a subject for n students and calculate
 * 1] average score of class
 * 2] Highest score and lowest score of class
 * 3] marks scored by most of the students
 * 4] list of students absent for test
 */

#include <iostream>
using namespace std;
class stud {
	int roll;
	int marks;
	string att;

public:
	stud() {
		roll = 0;
		marks = -1;
		att = "A";
	}

	void takeuserinput(stud x[], int n);
	void display(stud x[], int n);
	void printavg(stud x[], int n);
	void minmax(stud x[], int n);
	void mostfreq(stud x[], int n);
	void attendence(stud x[], int n);

};
void stud::takeuserinput(stud x[], int n) {

	for (int i = 0; i < n; i++) {
		cout << "  enter roll no of student " << i + 1 << endl;
		cin >> x[i].roll;

		cout << "  Please enter attendence of student  "<< i + 1 <<" P or A "<< endl;
		cin >> x[i].att;
		if (x[i].att == "P") {
			cout << "  Please enter marks of student  " << i + 1 << endl;
			cin >> x[i].marks;
		}
	}
	cout << "#### YOUR DATA IS STORED OF" << n << "STUDENTS ####" << endl;
}
void stud::display(stud x[], int n) {

	for (int i = 0; i < n; i++) {
		cout << "   roll no of student " << i + 1 << endl;
		cout << x[i].roll;
		cout << "   marks of student  " << i + 1 << endl;
		cout << x[i].marks;
		cout << "   attendence of student  " << i + 1 << endl;
		cout << x[i].att;
	}
	cout << "#### YOUR DATA IS STORED OF" << n << "STUDENTS ####" << endl;
}
void stud::printavg(stud x[], int n) {
	int sum = 0, avg;
	for (int i = 0; i < n; i++) {
		if (x[i].marks != -1)

			sum += x[i].marks;
	}
	avg = sum / n;
	cout << "AVG IS" << avg;
}
void stud::minmax(stud x[], int n) {
	int max = 0, min = 101;

	for (int i = 0; i < n; i++) {
		if (x[i].marks != -1 && x[i].marks > max) {
			max = x[i].marks;

		}
	}
	for (int i = 0; i < n; i++) {
		if (x[i].marks != -1 && x[i].marks < min) {
			min = x[i].marks;

		}
	}

	cout << "max IS" << max << endl;
	cout << "min IS" << min << endl;
}
void stud::mostfreq(stud x[], int n) {
	int index = 0, times = 0;
	int arr[101];
	for (int i = 0; i < 101; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (x[i].marks != -1) {
			arr[x[i].marks]++;
		}
	}
	for (int i = 0; i < 101; i++) {
		if (arr[i] > times) {
			times = arr[i];
			index = i;
		}

	}
	if(times==1)
	{
		cout<<"NO MARKS HAVE BEEN SCORED MORE THAN ONE TIME "<<endl;
	}
	else
	cout << "FREQ MARKS" << index << "   " << "NO OF TIMES" << times << endl;
}
void stud::attendence(stud x[], int n)
{cout<<"ABSENT STUDENTS "<<endl;
	for (int i = 0; i <n; i++)
   {
	if (x[i].att == "A")
		cout<<x[i].roll<<"  ";
    }
}

int main() {
	int n;

	cout << "enter no of students" << endl;
	cin >> n;
	stud x[n];
	stud temp;
	temp.takeuserinput(x, n);
	temp.display(x, n);
	temp.printavg(x, n);
	temp.minmax(x, n);
	temp.mostfreq(x, n);
	temp.attendence(x,n);

	return 0;
}

