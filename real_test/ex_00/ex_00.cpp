#include "iostream"

typedef struct s_s
{
	std::string arr_str[3];
	unsigned int arr_int[3];
}				t_s;

std::string skip_spaces_at_the_beginning(std::string &str)
{
	unsigned int i, len;
	std::string str1;

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

unsigned int find_space(const std::string &str)
{
	unsigned int i;

	i = 0;
	while (std::isgraph(str[i]))
		i++;
	return (i);
}

void save_three_clean_strings_in_a_structure(std::string &str, t_s &s)
{
	unsigned int i, len;
	std::string str1, str2, str3, str4;

	len = str.length();
	i = find_space(str);
	s.arr_str[0] = str.substr(0, i);
	str1 = str.substr(i, len);
	str2 = skip_spaces_at_the_beginning(str1);
	i = find_space(str2);
	s.arr_str[1] = str2.substr(0, i);
	str3 = str2.substr(i, len);
	str4 = skip_spaces_at_the_beginning(str3);
	i = find_space(str4);
	s.arr_str[2] = str4.substr(0, i);
	return ;
}

void check_strings_if_empty(t_s &s)
{
	unsigned int i;

	i = 0;
	while (!(s.arr_str[i].empty()))
		i++;
	if (i == 3)
		return ;
	else
		exit(EXIT_FAILURE);
}

void check_that_m_is_less_than_k_is_less_than_n(t_s &s)
{
	if (s.arr_int[2] > s.arr_int[1])
		exit(EXIT_FAILURE);
	else if (s.arr_int[1] > s.arr_int[0])
		exit(EXIT_FAILURE);
	else if (s.arr_int[0] == s.arr_int[1] && s.arr_int[1] == s.arr_int[2])
		exit(EXIT_FAILURE);
}

void check_int_range(unsigned int &i)
{
	if (i < 1 || i > 200)
		exit(EXIT_FAILURE);
}

void convert_string_to_int(t_s &s)
{
	try
	{
		s.arr_int[0] = std::stoi(s.arr_str[0]);
		s.arr_int[1] = std::stoi(s.arr_str[1]);
		s.arr_int[2] = std::stoi(s.arr_str[2]);
	}
	catch (std::invalid_argument)
	{
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	t_s s;
	unsigned int n, k, m, counter;
	std::string str, str1, str2;

	n = k = m = counter = 0;
	std::getline(std::cin, str);
	if (str.empty())
		exit(EXIT_FAILURE);
	else
	{
		str1 = skip_spaces_at_the_beginning(str);
		str2 = skip_spaces_at_the_end(str1);
		save_three_clean_strings_in_a_structure(str2, s);
		check_strings_if_empty(s);
		convert_string_to_int(s);
		for (unsigned int i = 0; i < 3; i++)
			check_int_range(s.arr_int[i]);
		check_that_m_is_less_than_k_is_less_than_n(s);
		n = s.arr_int[0];
		k = s.arr_int[1];
		m = s.arr_int[2];
		while (n >= k)
		{
			n = n - s.arr_int[1];
			while (k >= m)
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