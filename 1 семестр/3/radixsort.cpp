#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

int key(string a, int i) {
	int k;
	k = (int)(a[i]);
	return k;
}

void radixsort(vector<string> &a, int n, int m, int k) {
	int i, d, j, count, tmp,r;
	for (i = m - 1;i >= m - k;i--) {
		vector <int> c(26);
		vector<string> b(n);
		for (j = 0;j < 26;j++) {
			c[j] = 0;
		}
		for (j = 0;j < n;j++) {
			d = key(a[j], i) - (int)('a');
			c[d]++;
		}
		count = 0;
		for (j = 0;j < 26;j++) {
			tmp = c[j];
			c[j] = count;
			count += tmp;
		}
		for (j = 0;j < n;j++) {
			d = key(a[j], i) - (int)('a');
			r = c[d];
			b[r] = a[j];
			c[d]++;
		}
		a = b;
	}

}
int main() {
	ifstream input("radixsort.in");
	ofstream output("radixsort.out");
	int i, n, k, m;
	n = 0;
	input >> n>>m>>k;
	vector<string> a(n);
	for (i = 0;i < n;i++) {
		input >> a[i];
	}
	radixsort(a, n,m,k);
	for (i = 0;i < n;i++) {
		output << a[i]<<"\n";
	}

}
