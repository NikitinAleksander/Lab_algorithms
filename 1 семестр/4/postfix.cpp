/*#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("postfix.in");
	ofstream out("postfix.out");
	int k = -1;
	int ar[100];
	char op;
	string ope;
	while (in >> op)
	{
		if ((op != '*') && (op != '-') && (op != '+'))
		{
			ope[0] = op;
			k++;
			ar[k] = atoi(&ope[0]);
		}
		if (op == '*')
		{
			ar[k - 1] = ar[k - 1] * ar[k];
			k--;
		}
		if (op == '-')
		{
			ar[k - 1] = ar[k - 1] - ar[k];
			k--;
		}
		if (op == '+')
		{
			ar[k - 1] = ar[k - 1] + ar[k];
			k--;
		}
	}
	out << ar[0];
}*/
