
#include "../src/vector.hpp"

#include "common.hpp"
#include <time.h>
#include <limits>

using namespace std::chrono;

void ft_vector()
{
	ft::vector<int> vct(10);
	ft::vector<int> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;

	vct2.insert(vct2.end(), 42);
	printSize(vct2);
	vct2.insert(vct2.begin(), 2, 21);
	printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	printSize(vct2);
	vct2.insert(vct2.end(), 2, 84);
	printSize(vct2);
	vct2.resize(4);
	printSize(vct2);
	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	printSize(vct2);
	vct.clear();

	ft::vector<int> vct3(10000, 10);
	vct3.push_back(30);
	vct3.push_back(30);
	vct3.push_back(30);
//	printSize(vct3);
}

void og_vector()
{
	std::vector<int> vct(10);
	std::vector<int> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;

	vct2.insert(vct2.end(), 42);
	printSize(vct2);
	vct2.insert(vct2.begin(), 2, 21);
	printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	printSize(vct2);
	vct2.insert(vct2.end(), 2, 84);
	printSize(vct2);
	vct2.resize(4);
	printSize(vct2);
	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	printSize(vct2);
	vct.clear();

	std::vector<int> vct3(10000, 10);
	vct3.push_back(30);
	vct3.push_back(30);
	vct3.push_back(30);
//	printSize(vct3);
}

int		main(void)
{

	clock_t og_begin = clock();

	og_vector();
	
	clock_t og_end = clock();
	double og_time_spent = (double)(og_end - og_begin) / CLOCKS_PER_SEC;

	clock_t begin = clock();
	ft_vector();
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


	printf("---  TIME FT = %f ---\n", time_spent);
	printf("---  TIME OG = %f ---\n", og_time_spent);

}