#include <iostream>
#include <array>
using namespace std;

void insertionSort(char* A, int n) {
	for(int i = 1; i < n; i++) {
		char cur = A[i];
		int j = i - 1;
		while ((j >= 0) && (A[j] > cur)) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = cur;
	}
}
int main() {
	char list[6] = {'L', 'O', 'Z', 'A', 'D', 'H'};
	insertionSort(list, 6);
	for (int i = 0; i < 6; i++)
		cout << list[i] << ' ';
	return 0; 
}