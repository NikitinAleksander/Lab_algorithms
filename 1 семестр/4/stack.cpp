#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
	ifstream input("stack.in");
	ofstream output("stack.out");
	int n,i;
	input >> n;
	int *a = new int [n];
	int key;

	for (i = 0;i < n;i++) {
		a[i] = 0;
	}

	key = 0;
	string act;
	int num;
	for (i = 0;i < n;i++) {
		input >> act;
		if (act == "+") {
			input >> num;
			a[key] = num;
			key++;
		}
		else {
			output << num << endl;
			key--;
		}
	}
}