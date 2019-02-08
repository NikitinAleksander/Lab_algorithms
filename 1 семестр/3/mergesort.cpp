#include <fstream>
#include <iostream>
using namespace std;
ofstream file;
void Merge(long int *A, long int first, long int last)
{
	long int middle, start, final, j;
	long int *mas = new long int[1000000];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}
	for (j = first; j <= last; j++) A[j] = mas[j];
	delete[]mas;
};
void MergeSort(long int *A, long int first, long int last)
{
	{
		if (first < last)
		{
			MergeSort(A, first, (first + last) / 2);
			MergeSort(A, (first + last) / 2 + 1, last);
			Merge(A, first, last);
		}
	}
};

void main()
{
	ifstream fin("sort.in");
	long int i, n;
	long int *A = new long int[1000000];
	fin >> n;
	for (i = 1; i <= n; i++)
	{
		fin >> A[i];
	}
	fin.close();
	MergeSort(A, 1, n);
	ofstream fout("sort.out");
	for (i = 1; i <= n; i++) fout << A[i] << " ";
	delete[]A;
	fout.close();
	system("pause>>void");
}
