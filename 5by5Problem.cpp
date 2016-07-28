//this is no where near the final form. i just wanted to get started and write something down.
//this is the rough draft of all rough drafts.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

void showMatrix(const int [5][5], int); //this function will show you the matrix you input.
void minMatrix(const int [5][5], int);  //this function determines the minimum value of each row of your matrix.
					//will have to find a way to store these values as something other than a variable i'm assuming.

int main()
{
	cout << "AJ's Method for Assignment Problems" << endl << endl;
	cout << "This will be used for only a 5 by 5 assignment problem." << endl;
	cout << "Enter your 5 by 5 assignment matrix as your values appear from left to right, then top to bottom:" << endl;

	int assignMatrix[5][5]; 

	for (int i = 0; i < 5; i++) //loop to assign a value to each cell of the array
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> assignMatrix[i][j];
		}
	}

	showMatrix(assignMatrix, 5); //calling our function to show the assignment matrix we've created

	minMatrix(assignMatrix, 5); //searching for the minimum value in each row

	system("pause");
	return 0;
}

void showMatrix(const int assignMatrix[5][5], int) //this function will show you the matrix you input.
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(4) << assignMatrix[i][j] << " ";
		}

		cout << endl;
	}
}

void minMatrix(const int assignMatrix[5][5], int) //this function determines the minimum value of each row of your matrix.
{
	int a, b, c, d, e;

	for (int i = 0; i < 5; i++) 
	{
		if (i == 0)//min in row 1
		{
			a = assignMatrix[0][0];

			for (int j = 0; j < 5; j++)
			{
				if (assignMatrix[i][j] < a)
					a = assignMatrix[i][j];

			}
		}

		if (i == 1)//min in row 2
		{
			b = assignMatrix[1][0];

			for (int j = 0; j < 5; j++)
			{
				if (assignMatrix[i][j] < b)
					b = assignMatrix[i][j];
			}
		}

		if (i == 2)//min in row 3
		{
			c = assignMatrix[2][0];

			for (int j = 0; j < 5; j++)
			{
				if (assignMatrix[i][j] < c)
					c = assignMatrix[i][j];
			}
		}

		if (i == 3)//min in row 4
		{
			d = assignMatrix[3][0];

			for (int j = 0; j < 5; j++)
			{
				if (assignMatrix[i][j] < d)
					d = assignMatrix[i][j];
			}
		}

		if (i == 4)//min in row 5
		{
			e = assignMatrix[4][0];

			for (int j = 0; j < 5; j++)
			{
				if (assignMatrix[i][j] < e)
					e = assignMatrix[i][j];
			}
		}
	}
}
