#include "vector_tests.hpp"

int	main(void)
{
	std::cout << "\033[1m\033[33mBEGIN END VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> first;
		for (int i=1; i<=5; i++) first.push_back(i);
		std::cout << "first contains:";
		for (std::vector<int>::iterator it = first.begin() ; it != first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::vector<int> second(5, 5);
		for (int i=10; i<=15; i++) second.push_back(i);
		std::cout << "second contains:";
		for (std::vector<int>::iterator it = second.begin() ; it != second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::vector<int> third(second);
		third.resize(7);
		std::cout << "third contains:";
		for (std::vector<int>::iterator it = third.begin() ; it != third.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> first;
		for (int i=1; i<=5; i++) first.push_back(i);
		std::cout << "first contains:";
		for (ft::vector<int>::iterator it = first.begin() ; it != first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		ft::vector<int> second(5, 5);
		for (int i=10; i<=15; i++) second.push_back(i);
		std::cout << "second contains:";
		for (ft::vector<int>::iterator it = second.begin() ; it != second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		ft::vector<int> third(second);
		third.resize(7);
		std::cout << "third contains:";
		for (ft::vector<int>::iterator it = third.begin() ; it != third.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	return (0);
}
