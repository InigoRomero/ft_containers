
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
	first.insert(ft::make_pair(55,40));
	first.insert(ft::make_pair(40,60));
	first.insert(ft::make_pair(65,10));
	first.insert(ft::make_pair(60,30));
	first.insert(ft::make_pair(75,5));
	first.insert(ft::make_pair(57,5));

	//ft::map<int,int>::const_iterator it_end = first.end();
	//std::cout << "key = "<< it_end->first << " | value = " << it_end->second << "  |\n";

	ft::map<int,int>::const_iterator it = first.begin();
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

		ft::map<int,int>::const_iterator it2 = first.begin();
	std::cout << "key = "<< it2->first << " | value = " << it2->second << "  |\n";
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