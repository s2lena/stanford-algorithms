#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void LoadCheck(int a[]) {
	for (int i = 0; i < 200; i++) {
		a[i] = i + 1;
	}
}

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void ChangeIdx(int change, int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == change) {
			Swap(a[i], a[n]);
			return;
		}
	}
}

int main() {
	ifstream fin;srand(time(NULL));
	int a[200][50]; int b[200]; int check[200]; int sum = 0;
	for (int e = 0; e < 100; e++) {
		LoadCheck(check);
		int n = 200; 
		int k = 0; int i = 0; int j = 0; char c = 0;
		fin.open("C:/Users/Selena/Documents/kargerMinCut.txt");
		while (fin) {
			fin.get(c);
			if (c == '\n' && fin) {
				b[i] = j;
				i++;
				j = 0;
				if (i == 200)
					break;
			}
			else {
				if (isdigit(c)) {
					k = (c -'0') + k * 10;
				}
				else {
					a[i][j] = k;
					j++;
					k = 0;
				}
			}
		}
	fin.close(); 
		int idx_c = 0; int idx_r = 0;
		int random = 0; int change = 0;
		while (n > 2) {
			idx_r = rand() % n;
			random = check[idx_r];
			idx_c = rand() % b[random - 1];
			change = a[random - 1][idx_c];
			if (change == random)
				continue;
			for (int i = 0; i < 200; i++) {
				for (int j = 0; j < b[i]; j++) {
					if (a[i][j] == change) 
						a[i][j] = random;
				}
			}
			n--;
			ChangeIdx(change, check, n);
		};
		int cut = 0;
		for (int i = 0; i < 200; i++) {
			for (int j = 1; j < b[i]; j++) {
				if (a[i][0] != a[i][j]) {
					cut++;
				}
			}
		}
		if (cut / 2 == 17)
			sum++;
	}
	cout << sum << endl;
	return 0;
}