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
//	std::cout << "substr1 > "<< s.arr_str[0] << std::endl;
	str2 = str.substr(i, len);
	str3 = skip_spaces_at_the_beginning(str2);
	i = 0;
	while (std::isgraph(str3[i]))
		i++;
	s.arr_str[1] = str3.substr(0, i);
//	std::cout << "substr4 > "<< s.arr_str[1] << std::endl;
	str5 = str3.substr(i, len);
	str6 = skip_spaces_at_the_beginning(str5);
	i = 0;
	while (std::isgraph(str6[i]))
		i++;
	s.arr_str[2] = str6.substr(0, i);
//	std::cout << "substr7 > "<< s.arr_str[2] << std::endl;
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
//		std::cout << "m > k" << std::endl;
		exit(EXIT_FAILURE);
	}
	else if (s.arr_int[1] > s.arr_int[0])
	{
//		std::cout << "k > n" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void check_int_range(unsigned int &i)
{
	if (i < 1 || i > 200)
		exit(EXIT_FAILURE);
}

int main(void)
{
	t_s s;
	unsigned int i, j, n, k, m, counter, hold;
	std::string str, str1, str2, str3;
	int hold1;

	i = j = n = k = m = counter = 0;

	std::getline(std::cin, str);
	if (str.empty())
		exit(EXIT_FAILURE);
	else
	{
		str1 = skip_spaces_at_the_beginning(str);
		str2 = skip_spaces_at_the_end(str1);
		save_three_clean_strings_in_a_structure(str2, s);
		check_strings(s);
		s.arr_int[0] = std::stoi(s.arr_str[0]);
		s.arr_int[1] = std::stoi(s.arr_str[1]);
		s.arr_int[2] = std::stoi(s.arr_str[2]);
		for (unsigned int i = 0; i < 3; i++)
			check_int_range(s.arr_int[i]);
		check_that_m_is_less_than_k_is_less_than_n(s);
		std::cout << "n > " << s.arr_int[0] << std::endl;
		std::cout << "k > " << s.arr_int[1] << std::endl;
		std::cout << "m > " << s.arr_int[2] << std::endl;

		hold = s.arr_int[0] - s.arr_int[1];
		std::cout << hold << std::endl;
		hold1 = s.arr_int[1] - s.arr_int[2];
		std::cout << hold1<< std::endl;
		hold1 = hold1 - s.arr_int[2];
		std::cout << hold1<< std::endl;
		if (hold1 < (int)s.arr_int[2])
			hold += hold1;
		std::cout << hold << std::endl;

//		hold1 = s.arr_int[1];
//		while (1)
//		{
//			if (hold1 <= (int)s.arr_int[2])
//				break ;
//			else
//			{
//				hold1 = s.arr_int[1] - s.arr_int[2];
//				counter++;
//			}
//		}
//		std::cout << hold1<< std::endl;
//		std::cout << counter << std::endl;
	}
//	i = return_the_position_of_space(str);
//	str1 = str.substr(0, i);
//	i = return_the_position_of_space(str);
//	j = i;
//	str2 = str.substr(j, i);
//	i = return_the_position_of_space(str);
//	j += i;
//	str3 = str.substr(j, i);

//	n = std::stoi(str1);
//	k = std::stoi(str2);
//	m = std::stoi(str3);
//	if (!(str.empty()))
//		std::cout << "input string > "<< str << std::endl;
//	if (!(str1.empty()))
//		std::cout << "substr1 > " << str1 << std::endl;
//	if (!(str2.empty()))
//		std::cout << "substr2 > " << str2 << std::endl;
//	if (!(str3.empty()))
//		std::cout << "substr3 > " << str3 << std::endl;
//
//	if (m > k || k > n)
//	{
//		std::cout << "wrong" << std::endl;
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		hold = n - k;
//		std::cout << "hold >" << hold << std::endl;
//	}

	return (0);
}