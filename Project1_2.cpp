// Project1.cpp 
// Nico Shober
// 10/26/2018

#include "stdafx.h"
#include <iostream>  
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include<iomanip>
using std::setw;

#include<stdio.h>
#include<stdlib.h>
using std::abs;

#include<array>
using std::size;

#include<algorithm>
using std::fill_n;

#include <string>
using std::getline;

#include<sstream>
using std::istringstream;


const int dayCol = 4;
const int dayRow = 13;

int Days[dayCol][dayRow] = { 0 };

const int weekCol = 4;
const int weekRow = 2;

int Weeks[weekCol][weekRow] = { 0 };

int main()
{
	string Next1 = "Next";
	string Next2 = "N";
	string Day1 = "Day";
	string Day2 = "D";
	string Week1 = "Week";
	string Week2 = "W";

	int data = 0;

	int max = 0;
	int Wmax1 = 0;
	int Wmax2 = 0;

	int min = INT_MAX;
	int Wmin1 = INT_MAX;
	int Wmin2 = INT_MAX;

	int sum = 0;
	int Wsum1 = 0;
	int Wsum2 = 0;

	int count = 0;
	int Wcount1 = 0;
	int Wcount2 = 0;

	int i = 0; // Day rows for later
	int j = 0; // Day columns

	string IString = "";
	istringstream buffer;



	// days		1	2	3	4	5	6	7	8	9	10	11	12	13	14
	// inc		0	1	2	3	4	5	6	7	8	9	10	11	12	13
	// max	
	// min
	// count
	// sum
	
	//week		1 2
	//inc		0 1
	//max
	//min
	//count
	//sum



	//testing initial values

	/*for (int in = 0; in < 14; in++)
	{
	for (int jn = 0; jn < 4; jn++)
	{
	cout << "in: " << in << " jn: " << jn << " value: " << Days[in][jn] << endl;

	}
	}

	for (int in = 0; in < 2; in++)
	{
	for (int jn = 0; jn < 4; jn++)
	{
	cout << "in: " << in << " jn: " << jn << " value: " << Weeks[in][jn] << endl;

	}
	}*/


	bool End = false;
	bool ValidInput = false;
	cout << endl << "Input blood sugar values:" << endl;
	cout << "N/Next = next day, W/Week = weekly summary, D/Day = daily summary" << endl;
	while (End == false)
	{
		while (ValidInput == false)
		{
			getline(cin, IString);

			if (IString == Next1 | IString == Next2 | IString == Day1 | IString == Day2 | IString == Week1 | IString == Week2) {
				if (IString == Next1 | IString == Next2) {
					data = -1;
					//__________ValidInput = false;
				}
				if (IString == Day1 | IString == Day2) {
					data = -2;
					//__________ValidInput = false;
				}
				if (IString == Week1 | IString == Week2) {
					data = -3;
					//__________ValidInput = false;
				}
			}
			else {
				buffer.str(IString);
				buffer >> data;		// Inputs Value to Data
				buffer.clear();

				//
				if (data <= 0) {
					//---   cout << endl << "Data not Valid" << endl;
					data = 0;		// Data is not valid, set to 0
									//__________ValidInput = false;
				}
				//---   ValidInput = true;
				IString = "XXX";	// Reset String
			}


			//data testing
			if (data > 0) {
				/*cout << endl << "Good Data" << endl;
				cout << "Data" << data << endl;*/
				//---   ValidInput = true;
				//---   cout << "\ni: " << i << endl;
				Days[i][1] = min;
				Days[i][0] = max;
				Weeks[0][0] = Wmax1;
				Weeks[0][1] = Wmin1;


				//max detect
				if (data > max)
				{
					max = data; //row 1
					Days[i][0] = max;
					//B8B8B8B8B888B88B8B8 cout << "" << endl;
				}

				//---   cout << "max: " << max << " data: " << data << " i: " << i << " j: " << j << " Days[i][0]: " << Days[i][0] << endl;
				if (i<7)
				{
					if (max > Wmax1)
					{
						Weeks[0][0] = max;
					}
				}
				if (i>6)
				{
					if (max > Wmax2)
					{
						Weeks[1][0] = max;
					}
				}
				//---   cout << "max: " << max << " data: " << data << " i: " << i << " j: " << j << " Days[i][0]: " << Days[i][0] << endl;


				//min detect
				if (data < min)
				{
					min = data; //row 2
					Days[i][1] = min;
				}

				if (i<7)
				{
					if (min<Wmin1)
					{
						Wmin1 = min;
						Weeks[0][1] = Wmin1;
					}
				}
				if (i>6)
				{
					if (min<Wmin2)
					{
						Wmin2 = min;
						Weeks[1][1] = Wmin2;
					}
				}


				//counter
				count++; //row 3
				Days[i][2] = count;

				if (i<7)
				{
					if (count>Wcount1)
					{
						Wcount1 = count;
						Weeks[0][2] = Wcount1;
					}
				}
				if (i>6)
				{
					if (count>Wcount2)
					{
						Wcount2 = count;
						Weeks[1][2] = Wcount2;
					}
				}


				//sums
				sum += data; //row 4
				Days[i][3] = sum;
				int temp = 0;

				if (i<7)
				{
					Weeks[0][3] += sum;
				}
				if (i>6)
				{
					Weeks[1][3] += sum;
				}

				/*testing values*/
				/*cout << "testing to see if it writes to the day array" << endl;
				for (int in = 0; in < 5; in++)
				{
				for (int jn = 0; jn < 4; jn++)
				{
				cout << "in: " << in << " jn: " << jn << " \t\tvalue: " << Days[in][jn] << endl;
				}
				cout << "\n" << endl;
				}*/

				/*cout << "\n\ntesting to see if it writes to the week array" << endl;
				for (int in = 0; in < 2; in++)
				{
				for (int jn = 0; jn < 4; jn++)
				{
				cout << "in: " << in << " jn: " << jn << " \t\tvalue: " << Weeks[in][jn] << endl;
				}
				cout << "\n" << endl;
				}*/
			}

			//next day
			else if (data == -1)
			{
				/*cout << endl << "Next Day" << endl;*/
				//__________ValidInput = false;
				if (i > 5)
				{
					j = 1;
				}
				if (i < 6)
				{
					j = 0;
				}
				i++; //incrementing the day and reseting all the values
				if (i == 14)
				{
					cout << "\n\nEnd of 2 weeks of recording" << endl;
					cout << "These are the final results for the Days array: " << endl;
					for (int in = 0; in < 14; in++)
					{
						for (int jn = 0; jn < 4; jn++)
						{
							cout << "i: " << in << " j: " << jn << " \tvalue: " << Days[in][jn] << endl;
						}
						cout << endl;
					}

					cout << "These are the final results for the Weeks array: " << endl;
					for (int in = 0; in < 2; in++)
					{
						for (int jn = 0; jn < 4; jn++)
						{
							cout << "i: " << in << " j: " << jn << " \tvalue: " << Weeks[in][jn] << endl;
						}
						cout << endl;
					}
					
					ValidInput = true;
				}

					 //---   cout << "i: " << i << endl;
				max = 0;
				min = INT_MAX;
				count = 0;
				sum = 0;
			}

			//day sumary
			else if (data == -2)
			{
				cout << endl << "Day " << i + 1 << " Summary:\n" << endl;
				cout << "maximum value: \t\t" << Days[i][0] << endl;
				cout << "minimum value: \t\t" << Days[i][1] << endl;
				cout << "count value: \t\t" << Days[i][2] << endl;
				cout << "sum value: \t\t" << Days[i][3] << endl;

				//__________ValidInput = false;
			}

			//week summary
			if (data == -3)
			{
				cout << endl << "Week " << j + 1 << " Summary" << endl;
				cout << "maximum value: \t\t" << Weeks[j][0] << endl;
				cout << "minimum value: \t\t" << Weeks[j][1] << endl;
				cout << "count value: \t\t" << Weeks[j][2] << endl;
				cout << "sum value: \t\t" << Weeks[j][3] << endl;

				//__________ValidInput = false;
			}
			data = 0;

		}
		
	}
	return 0;
}

