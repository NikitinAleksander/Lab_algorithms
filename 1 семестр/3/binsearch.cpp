/*#include <iostream>
#include<conio.h>
#include<vector>
#include<fstream>
using namespace std;

void bin(vector<int> &a, int left, int right,int x) {
	int mid,k;
	mid = (left + right) / 2;
	if (left != right) {
		if (x > a[mid]) {
			left = mid;
		}
		if (x < a[mid]) {
			right = mid;
		}
		if (x == a[mid]) {
			
			if (a[mid - 1] == x) {
					right = mid;
				}
			else {
					k = mid;
			}
			
		}
	}*/


#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <fstream> 

using namespace std;

int binarySearch1(vector<int> &arr, int l, int r, int x) {
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x) {
			if (mid != 0) {
				if (arr[mid - 1] == arr[mid]) {
					return binarySearch1(arr, l, mid - 1, x);
				}
				else {
					return mid;
				}
			}
			return mid;
		}
		if (arr[mid] > x) {
			return binarySearch1(arr, l, mid - 1, x);
		}
		return binarySearch1(arr, mid + 1, r, x);
	}
	return -2;
}

int binarySearch2(vector<int> &arr, int l, int r, int x) {
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x) {
			if (mid != r) {
				if (arr[mid + 1] == arr[mid]) {
					return binarySearch2(arr, mid + 1, r, x);
				}
				else {
					return mid;
				}
			}
			return mid;
		}
		if (arr[mid] < x) {
			return binarySearch2(arr, mid + 1, r, x);
		}
		return binarySearch2(arr, l, mid - 1, x);
	}
	return -2;
}

int main() {
	ifstream input("binsearch.in");
	ofstream output("binsearch.out");

	int size; input >> size;
	vector<int> am(size);
	for (int i = 0; i < size; i++) {
		input >> am[i];
	}

	int recSize; input >> recSize;
	vector<int> rec(recSize);

	for (int i = 0; i < recSize; i++) {
		input >> rec[i];
	}

	for (int i = 0; i < recSize; i++) {
		output << binarySearch1(am, 0, size - 1, rec[i]) + 1 << ' ';
		output << binarySearch2(am, 0, size - 1, rec[i]) + 1 << endl;
	}

}
