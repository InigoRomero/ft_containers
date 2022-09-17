
#include "../src/map.hpp"
#include <map>
#include <utility>      // ft::pair
#include <iostream>     // ft::cout
/*
single element (1)
	iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
*/


int		main(void)
{
	ft::map<int,int> first;
	first.insert(ft::make_pair(42,40));
	first.insert(ft::make_pair(42,60));
	first.insert(ft::make_pair(50,10));
	first.insert(ft::make_pair(35,30));
	first.insert(ft::make_pair(75,5));
	first.insert(ft::make_pair(57,5));

	// with for  ------------------------------------------------------------------------------------
	ft::map<int,int>::iterator ite = first.end();
	std::cout << "[END] key = "<< ite->first << " | value = " << ite->second << "  |\n\n";
	ft::map<int,int>::iterator beg = first.begin();
	std::cout << "[BEGIN] key = "<< beg->first << " | value = " << ite->second << "  |\n\n";
	for (; beg != ite; beg++) {
		std::cout << "key = "<< beg->first << " | value = " << beg->second << "  |\n";
	}
	std::cout << "--------------------------------\n";
	std::cout << "--------------------------------\n";

	// one by one ------------------------------------------------------------------------------------
	ft::map<int,int>::iterator it = first.begin();
	std::cout << "key = "<< it->first << " | value = " << it->second << "  |\n";

	it++;
	std::cout << "key = "<< it->first << " | value = " << it->second << "  |\n";
	it++;
	std::cout << "key = "<< it->first << " | value = " << it->second << "  |\n";
	it++;
	std::cout << "key = "<< it->first << " | value = " << it->second << "  |\n";
	it++;
	std::cout << "key = "<< it->first << " | value = " << it->second << "  |\n";
	it++;

	std::cout << "key = "<< it->first << " | value = " << it->second << "  |\n";
//	ft::map<int,int>::const_iterator it_end = first.begin();
//	std::cout << "key2 = "<< it_end->first << " | value = " << it_end->second << "  |\n";

//	ft::map<int,int> copy_map(first.begin(), first.end());
	//copy_map.insert(first.begin(), first.end());


/*	for(
    it_end != first.end(); it_end++)
	{
		std::cout << "key2 = "<< it_end->first << " | value = " << it_end->second << "  |\n";
	}
  //	ft::map<char,int> second (first.begin(),first.end());
*/
	return (0);
}