#include<iostream> 
#include<map> 
#include<vector> 
#include<string> 
#include<fstream> 
using namespace std;
string b[100000];
vector <string> country;
void quickSort(int left, int right) {
	int i = left, j = right;
	string temp;
	string pivot = country[(left + right) / 2];
	while (i <= j) {
		while (country[i] < pivot)
			i++;
		while (country[j] > pivot)
			j--;
		if (i <= j) {
			temp = country[i];
			country[i] = country[j];
			country[j] = temp;
			i++;
			j--;
		}
	};
	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort(i, right);
}
int main() {
	ifstream fin("race.in");
	map<string, vector<string> > arr;
	int n;
	fin >> n;
	string s1, s2;
	for (int i = 0; i < n; i++) {
		fin >> s1;
		fin >> s2;
		arr[s1].push_back(s2);
		if (arr[s1].size() == 1) {
			country.push_back(s1);
		}
	}
	fin.close();
	quickSort(0, country.size() - 1);
	ofstream fout("race.out");
	for (int i = 0; i < country.size(); i++) {
		fout << "=== " << country[i] << " ===\n";
		for (int j = 0; j < arr[country[i]].size(); j++) {
			fout << arr[country[i]][j] << "\n";
		}
	}
	fout.close();
	return 0;
}