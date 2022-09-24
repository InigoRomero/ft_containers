
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
	ft::map<int, std::string> first;
	first.insert(ft::make_pair(42,"lol"));
	first.insert(ft::make_pair(42,"mdr"));
	first.insert(ft::make_pair(50,"mdr"));
	first.insert(ft::make_pair(35,"funny"));
	first.insert(ft::make_pair(45,"jaaj"));
	first.insert(ft::make_pair(57,"jaaj"));
	// with for  ------------------------------------------------------------------------------------
	ft::map<int, std::string>::iterator ite = first.end();
	std::cout << "[END] key = "<< ite->first << " | value = " << ite->second << "  |\n\n";
	ft::map<int, std::string>::iterator beg = first.begin();
	std::cout << "[BEGIN] key = "<< beg->first << " | value = " << ite->second << "  |\n\n";
	for (; beg != ite; beg++) {
		std::cout << "key = "<< beg->first << " | value = " << beg->second << "  |\n";
	}
	first[3] = "an element";
	std::cout << "--------------------------------\n";
	std::cout << "--------------------------------\n";
	std::cout << "--------------------------------\n";
	std::cout << "--------------------------------\n";

	// one by one ------------------------------------------------------------------------------------
	ft::map<int, std::string>::iterator it = first.begin();
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
//	ft::map<int, std::string>::const_iterator it_end = first.begin();
//	std::cout << "key2 = "<< it_end->first << " | value = " << it_end->second << "  |\n";

//	ft::map<int, std::string> copy_map(first.begin(), first.end());
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