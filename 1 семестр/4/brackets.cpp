/*#include <iostream>
#include <fstream>
#include<string>

using namespace std;

int main()
{
	ifstream in("brackets.in");
	ofstream out("brackets.out");
	string s;
	char *stack;
	while (in >> s)
	{
		int r = 0;
		int k = -1;
		stack = (char*) new char[s.length()];
		for (int i = 0; i < s.length(); i++)
		{
			if ((s[i] == '(') || (s[i] == '['))
			{
				k++;
				stack[k] = s[i];
			}
			else if (((s[i] == ')') || (s[i] == ']')) && k >= 0)
				{
					if (stack[k] == '(' && s[i] == ')')
					{
						k--;
					}
					else if (stack[k] == '[' && s[i] == ']')
					{
						k--;
					}
					else
					{
						r = 1;
						break;
					}
			}
			else
			{
				r = 1;
				break;
			}
		}
		if ((k == -1) && (r == 0))
			out << "YES\n";
		else
			out << "NO\n";
	}
	out.close();
	in.close();
	return 0;
}*/