#include "map_tests.hpp"

int	main(void)
{
	std::cout << "\033[1m\033[33mEMPTY MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		if (mymap.empty())
			std::cout << "mymap is empty - size: " << mymap.size() << std::endl;
		else
			std::cout << "mymap not empty - size: " << mymap.size() << std::endl;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}

		if (mymap.empty())
			std::cout << "mymap is empty - size: " << mymap.size() << std::endl;
		else
			std::cout << "mymap not empty - size: " << mymap.size() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		if (mymap.empty())
			std::cout << "mymap is empty - size: " << mymap.size() << std::endl;
		else
			std::cout << "mymap not empty - size: " << mymap.size() << std::endl;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}

		if (mymap.empty())
			std::cout << "mymap is empty - size: " << mymap.size() << std::endl;
		else
			std::cout << "mymap not empty - size: " << mymap.size() << std::endl;
	}
	return (0);
}
