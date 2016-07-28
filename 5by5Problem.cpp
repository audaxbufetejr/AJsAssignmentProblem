//this is no where near the final form. i just wanted to get started and write something down.
//this is the rough draft of all rough drafts.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

void showMatrix(const int [5][5], int); //this function will show you the matrix you input.
void minMatrix(const int [5][5], int, int& a, int& b, int& c, int& d, int& e);  //this function determines the minimum value of each row of your matrix.
void satMatrix(const int[5][5], int, int& z, int& y, int& x, int& w, int& v, int, int, int, int, int); //this function will determine which columns are saturated/unsaturated

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
			//cin >> assignMatrix[i][j]; // user input

			assignMatrix[i][j] = rand() % 10 + 1; //random input
		}
	}

	showMatrix(assignMatrix, 5); //calling our function to show the assignment matrix we've created

	int a, b, c, d, e;

	minMatrix(assignMatrix, 5, a, b, c, d, e); //searching for the minimum value in each row

	cout << "These are the minima for each row, respectively: ";
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;

	int z, y, x, w, v;

	satMatrix(assignMatrix, 5, z, y, x, w, v, a, b, c, d, e); //determining which columns are saturated

	cout << "Your saturated columns are " << z << ", " << y << ", " << x << ", " << w << ", " << v << "." << endl;

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

void minMatrix(const int assignMatrix[5][5], int, int& a, int& b, int& c, int& d, int& e) //this function determines the minimum value of each row of your matrix, and passes a-e back to main
{

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

void satMatrix(const int assignMatrix[5][5], int, int& z, int& y, int& x, int& w, int& v, int a, int b, int c, int d, int e) //will determine saturated/unsaturated columns
{
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < 5; j++)
			{
				if (a == assignMatrix[i][j])
					z = j + 1;
			}
		}

		if (i == 1)
		{
			for (int j = 0; j < 5; j++)
			{
				if (b == assignMatrix[i][j])
					y = j + 1;
			}
		}

		if (i == 2)
		{
			for (int j = 0; j < 5; j++)
			{
				if (c == assignMatrix[i][j])
					x = j + 1;
			}
		}

		if (i == 3)
		{
			for (int j = 0; j < 5; j++)
			{
				if (d == assignMatrix[i][j])
					w = j + 1;
			}
		}

		if (i == 4)
		{
			for (int j = 0; j < 5; j++)
			{
				if (e == assignMatrix[i][j])
					v = j + 1;
			}
		}
	}

	//cout << "Your saturated columns are " << z << ", " << y << ", " << x << ", " << w << ", " << v << "." << endl;
}
