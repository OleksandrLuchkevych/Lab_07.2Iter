#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Change(int** a, const int row1, const int  row2, const int  n, int l);
int Min(int** a, const int k, const int n, int& minmin, int j0);



void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void MinMax(int** a, const int k, const int n, int& min, int& max, int& l)
{

	int j0 = 0;
	int q0 = 0;
	 l = 0;
	
	for (l ; l < k; l++)
	{
		min = a[l][0];
		max = a[l][0];

		for (int j = 0; j < n; j++)
		{
			if (a[l][j] < min)
			{
				min = a[l][j];
				j0 = j;

			}
		}
		for (int q = 0; q < n; q++)
		{
			if (a[l][q] > max)
			{
				max = a[l][q];
				q0 = q;
			}
		}

		Change(a, j0, q0, n, l);

	}
}
void Change(int** a, int row1, int row2, const int k, int l)
{
	
	int j = 0 + l ;
	if ( j < k)
	{
	
	int tmp = a[j][row1];
	a[j][row1] = a[j][row2];
	a[j][row2] = tmp;

	}
}
int Min(int** a, const int k, const int n, int& minmin, int j0)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < minmin)
			{
				minmin = a[i][j];
				j0 = j;

			}
		}
	}
	return minmin;
		
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = -50;
	int High = 50;
	int n, k;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Create(a, k, n, Low, High);
	Print(a, k, n);
	
	int minmin = a[0][0];
	int l = 0;
	int min = a[l][0];
	int max = a[l][0];
	MinMax(a, k, n, min, max, l);
	Print(a, k, n);

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}


