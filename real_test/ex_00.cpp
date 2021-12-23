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
	unsigned int i, j, n, k, m, counter, one, two, hold, hold1;
	std::string str, str1, str2, str3;

	i = j = n = k = m = counter = one = two = hold = hold1 = 0;

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

//		std::cout << std::endl;
//		std::cout << "n = " << s.arr_int[0] << std::endl;
//		std::cout << "k = " << s.arr_int[1] << std::endl;
//		std::cout << "m = " << s.arr_int[2] << std::endl;

		n = s.arr_int[0];
		k = s.arr_int[1];
		m = s.arr_int[2];

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

//		hold = n;
//		while (hold > k)
//		{
//			std::cout << "n = " << n << std::endl;
//			std::cout << "k = " << k << std::endl;
//			hold = n - k;
//			std::cout << "hold = " << hold << std::endl;
//
//			hold1 = k - m;
//			counter++;
//			while (hold1 > m)
//			{
//				hold1 = hold1 - m;
//				counter++;
//				output_the_amount_of_coins_made(counter);
//			}
//			if (hold1 < m)
//			{
//				hold = hold + hold1;
////				continue;
//			}
//		}

//		hold = n - k; //10 - 5 = 5; hold = 5;
//		while (1)
//		{
//			if (hold1 != 0)
//				hold += hold1;
//			if (hold > k) // if (5 > 5)
//			{
//				std::cout << "h = " << hold << std::endl;
//
//				hold1 = k - m; //hold1 = 5 - 2; hold1 = 3;
//				std::cout << "h1 = " << hold1 << std::endl;
//				counter++;
//				if (hold1 < m) // if (hold1 < 2); if (3 < 2)
//				{
//					output_the_amount_of_coins_made(counter);
//					std::cout << "the amount of silver billet left is less than needed for a new coin" << std::endl;
//					std::cout << "h1 = " << hold1 << std::endl;
//					continue ;
//				}
//				else if (hold1 > m) // if (hold1 > 2); if (3 > 2)
//				{
//					hold1 = hold1 - m; // hold1 = 3 - 2; hold1 = 1;
//					std::cout << "h1 = " << hold1 << std::endl;
//					counter++;
//					output_the_amount_of_coins_made(counter);
//				}
//			}
//			else if (hold < k) // if (5 < 5)
//			{
//				std::cout << "the amount of silver left is less than needed for a new billet" << std::endl;
//				std::cout << "h = " << hold << std::endl;
//				output_the_amount_of_coins_made(counter);
//				break ;
//			}
//		}

//		one = n - k;
//		std::cout << "\n" <<  n << " - " << k << " = " << one << std::endl;
//
//		two = k - m;
//		std::cout << k << " - " << m << " = " << two << std::endl;
//		counter++;
//
//		std::cout << two << " - " << m << " = ";
//		two = two - m;
//		std::cout << two << std::endl;
//		counter++;
//
//		std::cout << two << " < " << m << "\nso ";
//		std::cout << one << " += " << two;
//		if (two < m)
//			one += two;
//		std::cout << " = " << one << std::endl << std::endl;
//
//		std::cout << one << " - " << k << " = ";
//		one = one - k;
//		std::cout << one << std::endl;
//
//		two = k - m;
//		std::cout << k << " - " << m << " = " << two << std::endl;
//		counter++;
//
//		std::cout << two << " - " << m << " = ";
//		two = two - m;
//		std::cout << two << std::endl;
//		counter++;
//
//		std::cout << two << " < " << m << "\nso ";
//		std::cout << one << " += " << two;
//		if (two < m)
//			one += two;
//		std::cout << " = " << one << std::endl << std::endl;
//
//		std::cout << one << " < " << k << "\nso ";
//		if (one < k)
//		{
//			std::cout << "there are " << counter << " coins made" << std::endl;
//			return (0);
//		}









	return (0);
}