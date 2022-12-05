#include "map_tests.hpp"

int	main(void)
{
	std::cout << "\033[1m\033[33mCLEAR MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		std::cout << "Before clear mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "\nCleaning map of size " << mymap.size() << std::endl;
		mymap.clear();
		std::cout << "Now map size is " << mymap.size() << std::endl;

		mymap['a']=1101;
		mymap['b']=2202;

		std::cout << "\nAfter clear mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		std::cout << "Before clear mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "\nCleaning map of size " << mymap.size() << std::endl;
		mymap.clear();
		std::cout << "Now map size is " << mymap.size() << std::endl;

		mymap['a']=1101;
		mymap['b']=2202;

		std::cout << "\nAfter clear mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	return (0);
}