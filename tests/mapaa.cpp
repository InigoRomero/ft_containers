
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

	first.insert(ft::make_pair(1,10));
	first.insert(ft::make_pair(2,40));
//	first.insert(ft::make_pair('b',20));
//	first.insert(ft::make_pair('c',30));
//	first.insert(ft::make_pair('e',50));
	ft::map<int,int>::const_iterator it = first.begin();
	std::cout << "key = "<< it->first << " | value = " << it->second << "  |\n";
//	ft::cout << "end = " << first[0] << "\n";
/*	for(ft::map<char,int>::const_iterator it = first.begin();
    it != first.end(); ++it)
	{
		ft::cout << "key = "<< it->first << " | value = " << it->second << "  |\n";
	}
  //	ft::map<char,int> second (first.begin(),first.end());
*/
	return (0);
}