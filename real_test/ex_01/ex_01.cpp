#include <iostream>

#define SIZE 10

void check_int(int &i)
{
	if (i >= 0 && i <= 100)
		exit(EXIT_FAILURE);
}

void initialize_array_variables_to_zero(unsigned int (&arr)[SIZE])
{
	for (unsigned int i = 0; i < SIZE; i++)
		arr[i] = 0;
}

void output_int_array(unsigned int (&arr)[SIZE])
{
	for (unsigned int i = 0; i < SIZE; i++)
		std::cout << arr[i] << std::endl;
}

unsigned int sum_up_int_array(unsigned int (&arr)[SIZE])
{
	unsigned int s = 0, res = 0;

	for (unsigned int i = 0; i < SIZE; i++)
		s += arr[i];
	res = s % (SIZE);
	if (res == 0)
		return (s);
	else
	{
		std::cout << "sum is not even,\ntry again" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void swap(unsigned int (&arr)[SIZE], unsigned int &i)
{
	unsigned int hold;

	hold = arr[i];
	arr[i] = arr[i + 1];
	arr[i + 1] = hold;
}

void bubble_sort(unsigned int (&arr)[SIZE])
{
	unsigned int i, n;

	n = sizeof(arr)/sizeof(arr[0]);
	while (n != 0)
	{
		i = 0;
		while (i < SIZE - 1)
		{
			if (arr[i] < arr[i + 1])
				swap(arr, i);
			i++;
		}
		n--;
	}
}

void equalize(unsigned int (&arr)[SIZE], unsigned int &average)
{
	unsigned int i = 0, j = 0, n = 0;

	n = sizeof(arr)/sizeof(arr[0]);
	while (n != 0)
	{
		i = 0;
		while (i < SIZE)
		{
			bubble_sort(arr);
			while (arr[i] < average && arr[0] > average)
			{
				arr[i]++;
				arr[j]--;
			}
			i++;
		}
		n--;
	}
}


int main(void)
{
	unsigned int arr[SIZE];
	unsigned int s = 0, average = 0, i = 0, counter = 0;

	initialize_array_variables_to_zero(arr);
	for (unsigned int i = 0; i < SIZE; i++)
		std::cin >> arr[i];
	std::cout << std::endl;
	s = sum_up_int_array(arr);
	std::cout << "sum\t" << s << std::endl;
	average = s/SIZE;
	std::cout << "average\t" << average << std::endl;
	while (i < SIZE)
	{
		if (arr[i] > average)
			counter++;
		i++;
	}
	std::cout << counter << std::endl;

//	bubble_sort(arr);
//	std::cout << std::endl;
//	equalize(arr, average);
//	output_int_array(arr);
	return (0);
}