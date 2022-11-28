#include "vector_tests.hpp"

int	main(void)
{
	std::cout << "\033[1m\033[33mERASE VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		std::cout << "myvector front: " << myvector.front() << std::endl;
		// erase the 6th element
		myvector.erase (myvector.begin()+5);
		std::cout << "myvector front: " << myvector.front() << std::endl;

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);
		std::cout << "myvector front: " << myvector.front() << std::endl;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		std::cout << "myvector front: " << myvector.front() << std::endl;
		// erase the 6th element
		myvector.erase (myvector.begin()+5);
		std::cout << "myvector front: " << myvector.front() << std::endl;

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);
		std::cout << "myvector front: " << myvector.front() << std::endl;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	return (0);
}
