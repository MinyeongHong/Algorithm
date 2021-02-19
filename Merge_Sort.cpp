#include <iostream>

using namespace std;

int Data[8] = {21,10,12,20,25,13,15,22 };
int number = 8;
int Sort[8];

void Merge(int* Data, int start, int end) {

	int middle = (start + end - 1) / 2;

	int i = start; 
	int j = middle + 1;
	int k = end; 
	int index = start;


	while (i <= middle && j <= end) {
		if (Data[i] >= Data[j]) {
			Sort[index] = Data[j];
			j++;
		}
		else {
			Sort[index] = Data[i];
			i++;
		}

		index++;
	}

	if (i > middle) {
		for (int l = j; l <= end; l++) 
		{
			Sort[index] = Data[l];
			index++;
		}
	}
	if (j > end) {
		for (int l = i; l <= middle; l++)
		{
			Sort[index] = Data[l];
			index++;
		}
	}

	for (int m = start; m <= end; m++) {
		Data[m] = Sort[m];
	}

}

void MergeSort(int* Data, int start, int end) {
	int middle = (start + end - 1) / 2;

	if (start == end) return;

	MergeSort(Data, start, middle);
	MergeSort(Data, middle + 1, end);
	Merge(Data, start, end);
	
}

int main(void){
	MergeSort(Data, 0, number - 1);
	for (int i = 0; i < number; i++)
		cout << Data[i] << " ";

	return 0;
}