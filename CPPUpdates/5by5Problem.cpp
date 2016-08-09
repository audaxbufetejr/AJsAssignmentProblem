//this is no where near the final form. i just wanted to get started and write something down.
//this is the rough draft of all rough drafts.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

void showMatrix(const int [5][5], int); //this function will show you the matrix you input.
void minMatrix(const int [5][5], int, int& a, int& b, int& c, int& d, int& e);  //this function determines the minimum value of each row of your matrix.
void satMatrix(const int[5][5], int, int& z, int& y, int& x, int& w, int& v, int, int, int, int, int); //this function will determine which columns are saturated/unsaturated
void killRow(const int [5][5], int [5][5], int z, int y, int x, int w, int v);

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
			//cin >> assignMatrix[i][j]; // user input. to switch to user input, comment out the random input line and uncomment this line

			assignMatrix[i][j] = rand() % 10 + 1; //random input
		}
	}

	showMatrix(assignMatrix, 5); //calling our function to show the assignment matrix we've created

	int a, b, c, d, e;

	minMatrix(assignMatrix, 5, a, b, c, d, e); //searching for the minimum value in each row

	int matrixMins[5] = { a, b, c, d, e };
	
	cout << "The respective minimums for each row are as follows: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << setw(4) << matrixMins[i];
	}
	cout << endl;

	int z, y, x, w, v;

	satMatrix(assignMatrix, 5, z, y, x, w, v, a, b, c, d, e); //determining which columns are saturated

	int newTable[5][5] = { 0 };
	int min[5] = { 100, 100, 100, 100, 100 };

	killRow(assignMatrix, newTable, z, y, x, w, v);

	/*if (z != y && z != x && z != w && z != v) //killing the row of the optimally saturated column 1
	{
		int test = assignMatrix[0][0];

		for (int i = 0; i < 5; i++)
		{
			if (assignMatrix[i][0] < test)
			{
				test = assignMatrix[i][0];
				int killRow = i;

				for (int j = 0; j < 5; j++)
				{
					newTable[killRow][j] = 5555;
				}
			}

		}
	}

	if (y != z && y != x && y != w && y != v) //killing the row of the optimally saturated column 2
	{
		int test = assignMatrix[0][1];

		for (int i = 0; i < 5; i++)
		{
			if (assignMatrix[i][1] < test)
			{
				test = assignMatrix[i][1];
				int killRow = i;

				for (int j = 0; j < 5; j++)
				{
					newTable[killRow][j] = 5555;
				}
			}

		}
	}

	if (x != y && x != z && x != w && x != v) //killing the row of the optimally saturated column 3
	{
		int test = assignMatrix[0][2];

		for (int i = 0; i < 5; i++)
		{
			if (assignMatrix[i][2] < test)
			{
				test = assignMatrix[i][2];
				int killRow = i;

				for (int j = 0; j < 5; j++)
				{
					newTable[killRow][j] = 5555;
				}
			}

		}
	}

	if (w != y && w != x && w != z && w != v) //killing the row of the optimally saturated column 4
	{
		int test = assignMatrix[0][3];

		for (int i = 0; i < 5; i++)
		{
			if (assignMatrix[i][3] < test)
			{
				test = assignMatrix[i][3];
				int killRow = i;

				for (int j = 0; j < 5; j++)
				{
					newTable[killRow][j] = 5555;
				}
			}

		}
	}

	if (v != y && v != x && v != w && v != z) //killing the row of the optimally saturated column 5
	{
		int test = assignMatrix[0][4];

		for (int i = 0; i < 5; i++)
		{
			if (assignMatrix[i][4] < test)
			{
				test = assignMatrix[i][4];
				int killRow = i;

				for (int j = 0; j < 5; j++)
				{
					newTable[killRow][j] = 5555;
				}
			}

		}
	}*/

	if (z != 1 && y != 1 && x != 1 && w != 1 && v != 1)
	{
		cout << "Column 1 is unsaturated." << endl;

		for (int i = 0; i < 5; i++)
		{
			while (newTable[i][0] == 0)
			{
				newTable[i][0] = abs(matrixMins[i] - assignMatrix[i][0]);
			}

			if (newTable[i][0] < min[0])
				min[0] = newTable[i][0];
		}

		cout << min[0] << endl;
	}

	if (z != 2 && y != 2 && x != 2 && w != 2 && v != 2)
	{
		cout << "Column 2 is unsaturated." << endl;

		for (int i = 0; i < 5; i++)
		{
			while (newTable[i][1] == 0)
			{
				newTable[i][1] = abs(matrixMins[i] - assignMatrix[i][1]);
			}

			if (newTable[i][1] < min[1])
				min[1] = newTable[i][1];
		}

		cout << min[1] << endl;
	}

	if (z != 3 && y != 3 && x != 3 && w != 3 && v != 3)
	{
		cout << "Column 3 is unsaturated." << endl;

		for (int i = 0; i < 5; i++)
		{
			while (newTable[i][2] == 0)
			{
				newTable[i][2] = abs(matrixMins[i] - assignMatrix[i][2]);
			}

			if (newTable[i][2] < min[2])
				min[2] = newTable[i][2];
		}

		cout << min[2] << endl;
	}

	if (z != 4 && y != 4 && x != 4 && w != 4 && v != 4)
	{
		cout << "Column 4 is unsaturated." << endl;

		for (int i = 0; i < 5; i++)
		{
			while (newTable[i][3] == 0)
			{
				newTable[i][3] = abs(matrixMins[i] - assignMatrix[i][3]);
			}

			if (newTable[i][3] < min[3])
				min[3] = newTable[i][3];
		}

		cout << min[3] << endl;
	}

	if (z != 5 && y != 5 && x != 5 && w != 5 && v != 5)
	{
		cout << "Column 5 is unsaturated." << endl;

		for (int i = 0; i < 5; i++)
		{
			while (newTable[i][4] == 0)
			{
				newTable[i][4] = abs(matrixMins[i] - assignMatrix[i][4]);
			}

			if (newTable[i][4] < min[4])
				min[4] = newTable[i][4];
		}	

		cout << min[4] << endl;
	}
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(4) << newTable[i][j];
		}
		cout << endl;
	}

	cout << "These are the min differences: ";
	for (int i = 0; i < 5; i++)
		cout << " " << min[i];
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		if (min[i] == 100)
			continue;

		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (min[i] == newTable[j][k])
					cout << "row " << j + 1 << ", column " << k + 1 << endl;
			}
		}
	}

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
			for (int j = 5; j >= 0; j--)
			{
				if (a == assignMatrix[i][j])
					z = j + 1;
			}
		}

		if (i == 1)
		{
			for (int j = 5; j >= 0; j--)
			{
				if (b == assignMatrix[i][j])
					y = j + 1;
			}
		}

		if (i == 2)
		{
			for (int j = 5; j >= 0; j--)
			{
				if (c == assignMatrix[i][j])
					x = j + 1;
			}
		}

		if (i == 3)
		{
			for (int j = 5; j >= 0; j--)
			{
				if (d == assignMatrix[i][j])
					w = j + 1;
			}
		}

		if (i == 4)
		{
			for (int j = 5; j >= 0; j--)
			{
				if (e == assignMatrix[i][j])
					v = j + 1;
			}
		}
	}

	cout << "Your saturated columns are " << z;

	if (z != y)
		cout << ", " << y;

	if (z != x && y != x)
		cout << ", " << x;

	if (z != w && y != w && x != w)
		cout << ", " << w;

	if (z != v && y != v && x != v && w != v)
		cout << ", " << v;

	cout << "." << endl;

	if (z != y && z != x && z != w && z != v)
	{
		cout << "Column " << z << " is optimally saturated." << endl; //column z=1
	}

	if (y != z && y != x && y != w && y != v)
	{
		cout << "Column " << y << " is optimally saturated." << endl; //column y=2
	}

	if (x != y && x != z && x != w && x != v)
	{
		cout << "Column " << x << " is optimally saturated." << endl; //column x=3
	}

	if (w != y && w != x && w != z && w != v)
	{
		cout << "Column " << w << " is optimally saturated." << endl; //column w=4
	}

	if (v != y && v != x && v != w && v != z)
	{
		cout << "Column " << v << " is optimally saturated." << endl; //column v=5
	}
}

void killRow(const int assignMatrix[5][5], int newTable[5][5], int z, int y, int x, int w, int v)
{
	if (z != y && z != x && z != w && z != v) //killing the row of the optimally saturated column 1
	{
		int test = assignMatrix[0][0];

		for (int i = 0; i < 5; i++)
		{
			if (assignMatrix[i][0] < test)
			{
				test = assignMatrix[i][0];
				int killRow = i;

				for (int j = 0; j < 5; j++)
				{
					newTable[killRow][j] = 5555;
				}
			}

		}
	}

	if (y != z && y != x && y != w && y != v) //killing the row of the optimally saturated column 2
	{
		int test = assignMatrix[0][1];

		for (int i = 0; i < 5; i++)
		{
			if (assignMatrix[i][1] < test)
			{
				test = assignMatrix[i][1];
				int killRow = i;

				for (int j = 0; j < 5; j++)
				{
					newTable[killRow][j] = 5555;
				}
			}

		}
	}

	if (x != y && x != z && x != w && x != v) //killing the row of the optimally saturated column 3
	{
		int test = assignMatrix[0][2];

		for (int i = 0; i < 5; i++)
		{
			if (assignMatrix[i][2] < test)
			{
				test = assignMatrix[i][2];
				int killRow = i;

				for (int j = 0; j < 5; j++)
				{
					newTable[killRow][j] = 5555;
				}
			}

		}
	}

	if (w != y && w != x && w != z && w != v) //killing the row of the optimally saturated column 4
	{
		int test = assignMatrix[0][3];

		for (int i = 0; i < 5; i++)
		{
			if (assignMatrix[i][3] < test)
			{
				test = assignMatrix[i][3];
				int killRow = i;

				for (int j = 0; j < 5; j++)
				{
					newTable[killRow][j] = 5555;
				}
			}

		}
	}

	if (v != y && v != x && v != w && v != z) //killing the row of the optimally saturated column 5
	{
		int test = assignMatrix[0][4];

		for (int i = 0; i < 5; i++)
		{
			if (assignMatrix[i][4] < test)
			{
				test = assignMatrix[i][4];
				int killRow = i;

				for (int j = 0; j < 5; j++)
				{
					newTable[killRow][j] = 5555;
				}
			}

		}
	}
}