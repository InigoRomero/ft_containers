#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include "pair.hpp"
#include <iostream>
namespace ft
{
	template<class Pair>
	struct BSTNode
	{
		BSTNode* parent;
		BSTNode* left;
		BSTNode* right;
		Pair value;
		int color;

		BSTNode(): parent(NULL), left(NULL), right(NULL), value(), color(0)
		{

		}

		BSTNode(const Pair &data): parent(NULL), left(NULL), right(NULL), value(data), color(0)
		{

		}

		BSTNode(const BSTNode &x): parent(x.parent), left(x.left), right(x.right), value(x.value), color(x.color)
		{

		}

		~BSTNode()
		{

		}

		BSTNode& operator=(const BSTNode& x)
		{
			if (this != &x)
			{
				color = x.color;
				left   = x.left;
				right  = x.right;
				parent = x.parent;
				value  = x.value;
			}
			return (*this);
		}
	};
}

#endif