#include "bubbleSort.h"

float do_bubblesort(vector<int>& arr, int n)
{
	int i = 0, j = 0, temp = 0;
	float time = 0.0;
	chrono::time_point<std::chrono::system_clock> start, end;

	start = chrono::system_clock::now();

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	end = chrono::system_clock::now();
	
	chrono::duration<float> time_e = end - start;

	time = time_e.count();

	return time;
}

int getRandom()
{
	int num = 0;

	num = rand() % 11;

	return 0;
}

vector<int> create_vector()
{
	srand(time(0));
	int size = 0;

	cout << "Enter size: ";
	cin >> size;

	vector<int> data(size, 0);

	generate(data.begin(), data.end(), getRandom());

	return data;
}
