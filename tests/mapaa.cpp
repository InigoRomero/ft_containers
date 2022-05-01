
#include "../src/map.hpp"

#include "common.hpp"
#include <utility>      // std::pair
#include <iostream>     // std::cout
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
	ft::map<char,int> first;

	first.insert(ft::make_pair('a',20));

	for(ft::map<char,int>::const_iterator it = first.begin();
    it != first.end(); ++it)
	{
		std::cout << it->first << " " << it->second << "\n";
	}
  //	ft::map<char,int> second (first.begin(),first.end());

	return (0);
}