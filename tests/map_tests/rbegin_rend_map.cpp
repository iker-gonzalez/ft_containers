#include "map_tests.hpp"

int	main(void)
{
	std::cout << "\033[1m\033[33mBEGIN END MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char,int> mymap;

		std::cout << "Inserting [b, 100]" << std::endl;
		mymap['b'] = 100;
		std::cout << "Inserting [a, 200]" << std::endl;
		mymap['a'] = 200;
		std::cout << "Inserting [c, 300]" << std::endl;
		mymap['c'] = 300;

		// show content:
		std::cout << std::endl << "Iter begin to end" << std::endl;
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		// show content:
		std::cout << std::endl << "Iter end to begin" << std::endl;
		std::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char,int> mymap;

		std::cout << "Inserting [b, 100]" << std::endl;
		mymap['b'] = 100;
		std::cout << "Inserting [a, 200]" << std::endl;
		mymap['a'] = 200;
		std::cout << "Inserting [c, 300]" << std::endl;
		mymap['c'] = 300;

		// show content:
		std::cout << std::endl << "Iter begin to end" << std::endl;
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		// show content:
		std::cout << std::endl << "Iter end to begin" << std::endl;
		ft::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
	}
	return (0);
}
