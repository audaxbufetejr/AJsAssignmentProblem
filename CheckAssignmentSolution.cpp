#include <iostream>
#include <iomanip>

using namespace std;

void showMatrix(const int[5][5], int);
void findSolution(const int[5][5], int, int& VAL);

int main()
{
	cout << "Enter the 5x5 assignment matrix you wish to solve: " << endl;

	int assignMatrix[5][5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> assignMatrix[i][j];
		}
	}

	showMatrix(assignMatrix, 5);

	int VAL = 100; //initializing VAL at a value such that VAL > sum
	               //this is so that findSolution can write sum into VAL

	findSolution(assignMatrix, 5, VAL);

	cout << "The solution is " << VAL << endl;

	system("pause");
	return 0;
}

void showMatrix(const int assignMatrix[5][5], int)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(3) << assignMatrix[i][j] << " ";
		}

		cout << endl;
	}
}

void findSolution(const int assignMatrix[5][5], int, int& VAL)
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

						if (sum < VAL)
							VAL = sum;
					}
				}
			}
		}
	}
}