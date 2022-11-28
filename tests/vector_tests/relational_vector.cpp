#include "vector_tests.hpp"

int	main(void)
{
	std::cout << "\033[1m\033[33mRELATIONAL VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (2,200);   // two ints with a value of 200

		std::cout << "foo contains: ";
		for (std::vector<int>::iterator beg = foo.begin(); beg != foo.end(); beg++)
			std::cout << *beg << ' ';
		std::cout << '\n';

		std::cout << "bar contains: ";
		for (std::vector<int>::iterator beg = bar.begin(); beg != bar.end(); beg++)
			std::cout << *beg << ' ';
		std::cout << '\n';

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (2,200);   // two ints with a value of 200

		std::cout << "foo contains: ";
		for (ft::vector<int>::iterator beg = foo.begin(); beg != foo.end(); beg++)
			std::cout << *beg << ' ';
		std::cout << '\n';

		std::cout << "bar contains: ";
		for (ft::vector<int>::iterator beg = bar.begin(); beg != bar.end(); beg++)
			std::cout << *beg << ' ';
		std::cout << '\n';

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	return (0);
}
