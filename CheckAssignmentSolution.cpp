#include <iostream>
#include <iomanip>

using namespace std;

void getMatrix(int assignMatrix[5][5]);
void showMatrix(const int[5][5], int); //this will output the matrix the user enters
void findSolution(const int[5][5], int, int& VAL); //this will, by brute force method, find the optimal solution
void showCoordinates(const int[5][5], int, int& VAL);

int main()
{
	cout << "Enter the 5x5 assignment matrix you wish to solve: " << endl;

	int assignMatrix[5][5]; //creates the 5x5 matrix

	getMatrix(assignMatrix);

	showMatrix(assignMatrix, 5); //printing out our matrix

	int VAL = 100; //initializing VAL at a value such that VAL > sum
	               //this is so that findSolution can write sum into VAL

	findSolution(assignMatrix, 5, VAL); //solving the assignment matrix

	cout << "The optimal solution is " << VAL << endl;

	showCoordinates(assignMatrix, 5, VAL);

	system("pause");
	return 0;
}
//
//
//
//
void getMatrix(int assignMatrix[5][5])
{
	for (int i = 0; i < 5; i++) //these two for loops will assign values from left to right, top to bottom
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> assignMatrix[i][j];
		}
	}
}
//
//
//
//
void showMatrix(const int assignMatrix[5][5], int) //our function to print out the matrix
{
	for (int i = 0; i < 5; i++) //these for loops write out the values in our array from left to right, top to bottom, just as we entered them
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(3) << assignMatrix[i][j] << " "; //writing out values
		}

		cout << endl;
	}
}
//
//
//
//
void findSolution(const int assignMatrix[5][5], int, int& VAL) //the function which finds the solution
{
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	int sum;

	/*
	num 1-5 will hold the value of the supposed minimum value for each row, respectively.
	the nested loops contain a check to make sure neither of num 1-5 occupy the same column. when if(true), we skip and move to the next cell.
	at the end, the function checks to see if the previously calculated sum is greater than the most recent sum calculated.
	*/

	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 5; b++)
		{
			if (b == a)
				continue;
			for (int c = 0; c < 5; c++)
			{
				if (c == a || c == b)
					continue;
				for (int d = 0; d < 5; d++)
				{
					if (d == a || d == b || d == c)
						continue;
					for (int e = 0; e < 5; e++)
					{
						if (e == a || e == b || e == c || e == d)
							continue;

						num1 = assignMatrix[0][a];
						num2 = assignMatrix[1][b];
						num3 = assignMatrix[2][c];
						num4 = assignMatrix[3][d];
						num5 = assignMatrix[4][e];

						sum = num1 + num2 + num3 + num4 + num5;

						if (sum <= VAL)
						{
							VAL = sum;

						}
					}
				}
			}
		}
	}
}
//
//
//
//
void showCoordinates(const int assignMatrix[5][5], int, int& VAL)
{
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	int sum;

	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 5; b++)
		{
			if (b == a)
				continue;
			for (int c = 0; c < 5; c++)
			{
				if (c == a || c == b)
					continue;
				for (int d = 0; d < 5; d++)
				{
					if (d == a || d == b || d == c)
						continue;
					for (int e = 0; e < 5; e++)
					{
						if (e == a || e == b || e == c || e == d)
							continue;

						num1 = assignMatrix[0][a];
						num2 = assignMatrix[1][b];
						num3 = assignMatrix[2][c];
						num4 = assignMatrix[3][d];
						num5 = assignMatrix[4][e];

						sum = num1 + num2 + num3 + num4 + num5;

						if (sum == VAL)
						{
							cout << "(1, " << a + 1 << "), (2, " << b + 1 << "), (3, " << c + 1 << "), (4, " << d + 1 << "), (5, " << e + 1 << ")" << endl;
						}
					}
				}
			}
		}
	}
}
