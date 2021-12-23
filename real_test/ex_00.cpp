#include "iostream"

typedef struct s_s
{
	std::string arr_str[3];
	unsigned int arr_int[3];
}				t_s;

std::string skip_spaces_at_the_beginning(std::string &str)
{
	unsigned int i;
	std::string str1;
	unsigned int len;

	i = 0;
	while (std::isspace(str[i]))
		i++;
	len = str.length();
	str1 = str.substr(i, len - i);
	return (str1);
}

std::string skip_spaces_at_the_end(std::string &str)
{
	unsigned int i;
	std::string str1;

	i = str.length() - 1;
	while (std::isspace(str[i]))
		i--;
	str1 = str.substr(0, i + 1);
	return (str1);
}

void save_three_clean_strings_in_a_structure(std::string &str, t_s &s)
{
	unsigned int i, j;
	unsigned int len;
	std::string str2;
	std::string str3;
	std::string str5;
	std::string str6;

	i = j = 0;
	len = str.length();
	while (std::isgraph(str[i]))
		i++;
	s.arr_str[0] = str.substr(0, i);
	str2 = str.substr(i, len);
	str3 = skip_spaces_at_the_beginning(str2);
	i = 0;
	while (std::isgraph(str3[i]))
		i++;
	s.arr_str[1] = str3.substr(0, i);
	str5 = str3.substr(i, len);
	str6 = skip_spaces_at_the_beginning(str5);
	i = 0;
	while (std::isgraph(str6[i]))
		i++;
	s.arr_str[2] = str6.substr(0, i);
	return ;
}

unsigned int return_the_position_of_space(std::string &str)
{
	unsigned int i;

	i = 0;
	while (str[i] != ' ')
		i++;
	return (i);
}

void check_strings(t_s &s)
{
	unsigned int i;

	i = 0;
	while (!(s.arr_str[i].empty()))
		i++;
	if (i == 3)
		return ;
	else
	{
		std::cout << "one of the strings is empty" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void check_that_m_is_less_than_k_is_less_than_n(t_s &s)
{
	if (s.arr_int[2] > s.arr_int[1])
	{
		exit(EXIT_FAILURE);
	}
	else if (s.arr_int[1] > s.arr_int[0])
	{
		exit(EXIT_FAILURE);
	}
}

bool check_int_range(unsigned int &i)
{
	if (i < 1 || i > 200)
		exit(EXIT_FAILURE);
	return (1);
}
void	output_the_amount_of_coins_made(unsigned int &counter)
{
	std::cout << std::endl;
	if (counter == 1)
		std::cout << "there is " << counter << " coin made" << std::endl;
	else if (counter == 0)
		std::cout << "there are no coins made" << std::endl;
	else
		std::cout << "there are " << counter << " coins made" << std::endl;
}

int main(void)
{
	t_s s;
	unsigned int n, k, m, counter;
	std::string str, str1, str2, str3;

	n = k = m = counter = 0;

	std::getline(std::cin, str);
	if (str.empty())
		exit(EXIT_FAILURE);
	else
	{
		str1 = skip_spaces_at_the_beginning(str);
		str2 = skip_spaces_at_the_end(str1);
		save_three_clean_strings_in_a_structure(str2, s);
		check_strings(s);
		n = s.arr_int[0] = std::stoi(s.arr_str[0]);
		k = s.arr_int[1] = std::stoi(s.arr_str[1]);
		m = s.arr_int[2] = std::stoi(s.arr_str[2]);
		for (unsigned int i = 0; i < 3; i++)
			check_int_range(s.arr_int[i]);
		check_that_m_is_less_than_k_is_less_than_n(s);
		while (n >= k)
		{
			n = n - s.arr_int[1];
			while (k > m)
			{
				k -= m;
				counter++;
			}
			n += k;
			k = s.arr_int[1];
		}
		std::cout << counter << std::endl;
	}
	return (0);
}