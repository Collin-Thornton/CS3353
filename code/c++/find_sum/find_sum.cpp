#include <iostream>
#include <cmath>

#define SIZE 20
using namespace std;

bool find_sum(int* data, int sum, int* index1, int* index2, int i=0);
int binary_search(int* data, int key);
int recursive_binary_search(int* data, int key, int low, int high);


int main() {
	int arr[SIZE] = { -20, -15, -10, 0, 1, 5, 6, 7, 9, 10, 12, 15, 20, 27, 42, 44, 49, 50, 60, 100 };
	int index1 = -1, index2 = -1, sum;

	cout << "Enter the desired sum: ";
	cin >> sum;
	cout << endl;
	
	bool result = find_sum(arr, sum, &index1, &index2);

	cout << "Original data: ";
	for(int val : arr) {
		cout << val << ' ';
	} cout << endl;

	cout << "Desired sum: " << sum << endl;
	
	if(result) 	cout << "Found at indicies: " << index1 << ", " << index2 << endl;
	else		cout << "Indicies not found" << endl;

	return 1;
} 



bool find_sum(int* data, int sum, int* index1, int* index2, int i) {
	if(i == SIZE-1) return false;

	int key = sum - data[i];
	int result = binary_search(data, key);
	
	if(result >= 0 && result != data[i]) {
		*index1 = i;
		*index2 = result;
		return true;
	}

	find_sum(data, sum, index1, index2, ++i);
}

int binary_search(int* data, int key) {
	int index = recursive_binary_search(data, key, 0, SIZE);
	return index;
}

int recursive_binary_search(int* data, int key, int low, int high) {
	if(low > high) return -1;

	int mid = (low + high)/2;
	
	if(data[mid] == key) return mid;
	else if(data[mid] < key) return recursive_binary_search(data, key, mid + 1, high);
	else return recursive_binary_search(data, key, low, mid-1);
}
