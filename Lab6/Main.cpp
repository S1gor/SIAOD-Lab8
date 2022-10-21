#include <iostream>

using namespace std;

/*Ñðàâíèòü äâà  àëãîðèòìà ïîèñêà íà îäíîé ïîñëåäîâàòåëüíîñòè*/

void interpolatingSearch(int* mas, int size, int val)
{
	int steps = 0;

	int start = 0;
	int current = 0;
	int end = size - 1;

	while (mas[start] < val && mas[end]>val)
	{
		steps++;
		current = start + ((val - mas[start]) * (end - start)) / (mas[end] - mas[start]);

		if (mas[current] < val)
			start = current + 1;
		else if (mas[current] > val)
			end = current - 1;
		else
			break;
	}

	if (mas[start] == val)
		cout << val << " founded in element " << start + 1 << "\nSteps = " << steps << endl;
	else if (mas[end] == val)
		cout << val << " founded in element " << end + 1 << "\nSteps = " << steps << endl;
	else
		cout << "Not found element " << val << endl;
}

void binarySearch(int* mas, int size, int val)
{
	int steps = 0;

	int left = 0;
	int current = 0;
	int right = size;

	int place = -1;

	while (true)
	{
		steps++;
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

		if (left > right)
			break;
	}

	if (place != -1)
		cout << val << " founded in element " << place + 1 << "\nSteps = " << steps << endl;
	else
		cout << "Not found element " << val << endl;
}

int chooseValue()
{
	int choice;
	cout << "Enter the number you want to find\nChoice: ";
	cin >> choice;
	return choice;
}

void inputRandom(int* mas, int size)
{
	for (int i = 0; i < size; i++)
		mas[i] = rand() % 21 - 10;
}

void print(int* mas, int size)
{
	cout << "Array:";
	for (int i = 0; i < size; i++)
		cout << " " << mas[i] << " ";
	cout << endl << endl;
}

int main()
{
	srand(time(NULL));

	const int size = 10;
	int mas[size] = { 1,3,5,9,12,18,20,30,33,48 };

	print(mas, size);

	interpolatingSearch(mas, size, 33);
	binarySearch(mas, size, 33);

	return 0;
}
