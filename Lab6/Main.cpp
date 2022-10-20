#include <iostream>

using namespace std;

/*Сравнить два  алгоритма поиска на одной последовательности*/

void interpolatingSearch(int* mas, int size, int val)
{
	int start = 0;
	int current = 0;
	int end = size - 1;

	bool found = false;

	while (mas[start] < val && mas[end]>val)
	{
		current = start + ((val - mas[start]) * (end - start)) / (mas[end] - mas[start]);

		if (mas[current] < val)
			start = current + 1;
		else if (mas[current] > val)
			end = current - 1;
		else
		{
			found = true;
			break;
		}
	}

	if (mas[start] == val)
		cout << val << " founded in element " << start + 1 << endl;
	else if (mas[end] == val)
		cout << val << " founded in element " << end + 1 << endl;
	else
		cout << "Not found element " << val << endl;
}

void binarySearch(int* mas, int size, int val)
{
	int left = 0;
	int current = 0;
	int right = size;

	int place = -1;

	while (true)
	{
		current = (left + right) / 2;

		if (val < mas[current])
			right = current - 1;
		else if (val > mas[current])
			left = current + 1;
		else
		{
			place = current;
			break;
		}

		if (left == right)
			break;
	}

	if (place != -1)
		cout << val << " founded in element " << place + 1 << endl;
	else
		cout << "Not found element " << val << endl;
}

void bubbleSort(int* mas, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool flag = true;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				swap(mas[j], mas[j + 1]);
				flag = false;
			}
		}
		if (flag)	break;
	}
}

void inputRandom(int* mas, int size)
{
	for (int i = 0; i < size; i++)
		mas[i] = rand() % 21 - 10;
}

void print(int* mas, int size)
{
	for (int i = 0; i < size; i++)
		cout << " " << mas[i] << " ";
	cout << endl << endl;
}

int main()
{
	srand(time(NULL));

	const int size = 6;
	int mas[size];// = { 1,3,5,9,12,18 };

	inputRandom(mas, size);
	print(mas, size);

	bubbleSort(mas, size);
	print(mas, size);

	//interpolatingSearch(mas, size, 9);
	binarySearch(mas, size, 9);
;

	return 0;
}