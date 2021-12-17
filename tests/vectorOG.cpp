
#include "../src/vector.hpp"

#include "common.hpp"

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
	std::vector<int> og(10);
	std::vector<int> vector2;

	for (unsigned long int i = 0; i < og.size(); ++i)
		og[i] = (og.size() - i) * 3;
	printSize(og);

	vector2.insert(vector2.end(), 42);
	
	vector2.insert(vector2.begin(), 2, 21);
	printSize(vector2);

	vector2.insert(vector2.end() - 2, 42);
	printSize(vector2);

	vector2.insert(vector2.end(), 2, 84);
	printSize(vector2);

	vector2.resize(4);
	printSize(vector2);

	vector2.insert(vector2.begin() + 2, og.begin(), og.end());
	og.clear();
	printSize(vector2);

	printSize(og);
	return (0);
}