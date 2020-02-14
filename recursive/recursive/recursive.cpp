#include <iostream>
#include <fstream>

using namespace std;

void Swap(int& a, int& b) {
	int temp = a;
	a = b; 
	b = temp;
}

void HeadQuickSort(int a[], int l, int r, int& count) {
	if ((r - l) == 0 || r < l) 
		return;
	for (int i = l; i <= r; i++) {
	cout << a[i] << " ";
	}
	cout << endl;
	int p = a[l];
	int i = l + 1;
	for (int j = l + 1; j <= r; j++) {
		if (a[j] < p)  {
			Swap(a[j], a[i]);
			i++;
		}
		count++;
	}
	Swap(a[i - 1], a[l]);
	if (i - 2 > 0) 
		HeadQuickSort(a, l, i - 2, count);
	HeadQuickSort(a, i, r, count);
}

void TailQuickSort(int a[], int l, int r, int& count) {
	if ((r - l) == 0 || r < l) 
		return;
	Swap(a[l], a[r]);
	int p = a[l];
	int i = l + 1;
	for (int j = l + 1; j <= r; j++) {
		if (a[j] < p)  {
			Swap(a[j], a[i]);
			i++;
		}
		count++;
	}
	Swap(a[i - 1], a[l]);
	if (i - 2 > 0) 
		TailQuickSort(a, l, i - 2, count);
	TailQuickSort(a, i, r, count);

}

int ChoosePivot(int b[]) {
	int first = 0;
	int middle = 0;
	for (int i = 0; i < 3; i++) {
		if (b[i] > first) {
			middle = first;
			first = b[i];
		}
		else if (b[i] < first && b[i] > middle) 
			middle = b[i];
	}
	return middle;
}

void MiddleQuickSort(int a[], int l, int r, int& count) {
	if ((r - l) == 0 || r < l)
		return;
	int k = 0;
	if ((r - l + 1) % 2 == 0)
		k = (r + l - 1) / 2;
	else 
		k = (r + l) / 2;
	int b[3] = {a[l], a[k], a[r]};
	int middle = ChoosePivot(b);
	for (int i = 0; i < 3; i++) {
		if (b[i] == middle) {
			if (i == 0)
				Swap(a[l], a[l]);
			else if ( i == 1)
				Swap(a[l], a[k]);
			else 
				Swap(a[l], a[r]);
		}
	}
	int p = a[l];
	int i = l + 1;
	for (int j = l + 1; j <= r; j++) {
		if (a[j] < p)  {
			Swap(a[j], a[i]);
			i++;
		}
		count++;
	}
	Swap(a[i - 1], a[l]);
	if (i - 2 > 0)
		MiddleQuickSort(a, l, i - 2, count);
	MiddleQuickSort(a, i, r, count);
}

int main() {
	/*ifstream fin;
	int a[10000];
	int count  = 0;
	fin.open("C:/Users/Selena/Documents/QuickSort.txt");
	for (int i = 0; i < 10000; i++) {
		fin >> a[i];
	}
	fin.close();
	MiddleQuickSort(a, 0, 9999, count);
	for (int i = 0; i < 10000; i++) {
		cout << a[i] << " ";
	}
	cout << endl << count << endl;*/
	int count = 0;
	int a[10] = {3, 1, 2, 4, 5, 8, 7, 6, 9};
	HeadQuickSort(a, 0, 8, count);
	return 0;
}