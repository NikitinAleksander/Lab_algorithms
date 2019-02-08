#include<iostream>
#include<cstdio>
#include<string>
#include<ctime>

using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;


	if (l < n && arr[l] < arr[largest])
		largest = l;


	if (r < n && arr[r] < arr[largest])
		largest = r;


	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void heap(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
}


int main() {                                  //n-размерность массива,a-массив с очередью,b-массив с местами чисел,x-новое число,k-номер строки ввода
	freopen("priorityqueue.in","r",stdin);
	freopen("priorityqueue.out", "w", stdout);
	int a[100000];
	int b[100000];
	int n, i,x,k,y;
	n = 0;
	string s;
	k = 0;
	while (cin>>s) {
		k++;
		
		if (s[0] == 'p') {
			cin >> x;
			a[n] = x;
			n++; 
			
			b[k] = x;
			
		}
		if (s[0] == 'e') {
			if (n > 0) {
				heap(a, n);
				cout << a[0] << endl;
				swap(a[0], a[n - 1]);
				n--;
				
			}
			else
				cout << "*"<<endl;
		}
		if (s[0] == 'd') {
			cin >> x;
			cin >> y;
			for (i = 0;i < n;i++) {
				if (a[i] == b[x]) {
					a[i] = y;
					b[x] = y;
					break;
				}
			}
				
		
			
		}
	}

}