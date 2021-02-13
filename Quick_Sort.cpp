#include <iostream>

using namespace std;

int Data[8] = { 20, 18, 50, 40, 9, 19, 5, 25 };
int number = 8;

void Quick(int* data, int start, int end) {

	if (start < end)
	{
		int pivot = start;
		int tmp;
		int index;
		int i = start;
		int j = end;

		while (i <= j) {

			i = start;
			j = end;


			//큰 값 찾기
			do i++;
			while ((data[pivot] > data[i]) && (i <= end));

			//작은 값 찾기
			while ((data[pivot] < data[j]) && (j >= start)) {
				j--;
			}


			if ((i > j) || (i==end)) {
				index = j;
				tmp = data[j];
				data[j] = data[pivot];
				data[pivot] = tmp;

			}

			else {
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}


			Quick(data, start, j - 1);
			Quick(data, j + 1, end);
		}


	}

	else return;
}

	int main(void) {
		Quick(Data, 0, number - 1);
		for (int i = 0; i < number; i++)
			cout << Data[i] << " ";
		return 0;
	}