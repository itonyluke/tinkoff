#include <iostream>

void check_int(int &i)
{
	if (i < -32000 || i > 32000)
		exit(EXIT_FAILURE);
}

int main(void)
{
	int i, ii;

	i = ii = 0;
	std::cin >> i;
	check_int(i);
	std::cin >> ii;
	check_int(ii);
	std::cout << i + ii << std::endl;
	return (0);
}
