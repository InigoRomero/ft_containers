#ifndef BSTNODE_HPP
#define BSTNODE_HPP

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
		int height;

		BSTNode(): parent(NULL), left(NULL), right(NULL), value(NULL), height(0)
		{

		}

		BSTNode(const Pair &data): parent(NULL), left(NULL), right(NULL), value(data), height(0)
		{

		}

		BSTNode(const BSTNode &x)
		{
			*this = x;
		}

		~BSTNode()
		{

		}

		BSTNode& operator=(const BSTNode& x)
		{
			if (this != &x)
			{
				height = x.height;
				value = x.value;
				left = x.left;
				right = x.right;
				parent= x.parent;
			}
			return (*this);
		}

		BSTNode* findMin(BSTNode* node)
		{
			if (!node)
				return (NULL);
			while (node->left)
				node = node->left;
			return (node);
		}

		BSTNode* findMax(BSTNode* node)
		{
			if (!node)
				return (NULL);
			while (node->right)
				node = node->right;
			return (node);
		}

		BSTNode* next()
		{
			BSTNode* tmp = this;
			if (tmp->right)
				return (tmp->right);
			BSTNode* pa = tmp->parent;
			while (pa != NULL && pa->left != tmp){
                tmp = pa;
                pa = tmp->parent;
            }
            return pa;
		}

		BSTNode* prev()
		{
			BSTNode* tmp = this;
			if (tmp->left)
				return (tmp->left);
			BSTNode* pa = tmp->parent;
			while (pa && tmp == pa->left){
                tmp = pa;
                pa = tmp->parent;
            }
            return pa;
		}
	};
}

#endif