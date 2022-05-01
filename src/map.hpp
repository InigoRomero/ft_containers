/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:13:17 by iromero-          #+#    #+#             */
/*   Updated: 2022/05/01 19:22:36 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "reverse_iterator.hpp"
#include "bidirectionnal_iterator.hpp"
#include "BSTree.hpp"
#include <iostream>

namespace ft {
template < class Key,                                               // map::key_type
           class T,                                                 // map::mapped_type
           class Compare = std::less<Key>,                          // map::key_compare
           class Alloc = std::allocator< ft::pair<const Key, T> >   // map::allocator_type
           > 
    class map {
        public:

            /* *** DEFINITIONS *** */
			typedef Key				 														key_type;
			typedef T 																		mapped_type;
			typedef ft::pair<const key_type,mapped_type> 									value_type;
			typedef Compare 																key_compare;
			typedef Alloc 																	allocator_type;
			typedef typename allocator_type::reference 										reference;
			typedef typename allocator_type::const_reference 								const_reference;
			typedef typename allocator_type::pointer 										pointer;
			typedef typename allocator_type::const_pointer 									const_pointer;
			typedef BSTNode<value_type>														map_node;
			typedef ft::bidirectionnal_iterator<map_node, value_type>						iterator;
			typedef ft::const_bidirectionnal_iterator<map_node, const value_type, iterator>	const_iterator;
			typedef ft::ReverseIterator<iterator> 											reverse_iterator;
			typedef ft::ReverseIterator<const_iterator>										const_reverse_iterator;
			typedef std::ptrdiff_t 															difference_type;
			typedef size_t 																	size_type;
			typedef typename Alloc::template rebind<map_node>::other						alloc_node;

        private:
            map_node	*ft_root;
			map_node	*ft_begin;
			map_node	*ft_end;
			size_type	ft_size;
			key_compare ft_compare;
			alloc_node	ft_allocator;

            void init_tree(size_t toAllocate)
			{
				ft_root = ft_allocator.allocate(toAllocate);
				ft_allocator.construct(ft_root, map_node());

				ft_begin = ft_allocator.allocate(toAllocate);
				ft_allocator.construct(ft_begin, map_node());

				ft_end = ft_allocator.allocate(toAllocate);
				ft_allocator.construct(ft_end, map_node());

				ft_begin->parent = ft_root;
				ft_end->parent = ft_root;
				ft_root->left = ft_begin;
				ft_root->right = ft_end;
			}

			int retHeight(map_node *node)
			{
				if (node != NULL && node != ft_begin && node != ft_end)
					return (node->height);
				return (-1);
			}

			void setHeight(map_node *node)
			{
				int left = retHeight(node->left);
				int right = retHeight(node->right);
				node->height = std::max(left, right) + 1;
			}

        public:

            /* *** CONSTRUCTORS *** */
            //  default
            explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()):
            ft_root(), ft_end(), ft_size(0), ft_compare(comp), ft_allocator(alloc) {
                init_tree(1);
            }

			//range
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
			ft_root(), ft_end(), ft_size(0), ft_compare(comp), ft_allocator(alloc) {
				for (InputIterator it = first; it != last; it++)
					ft_size++;
				std::cout << "how much -->" << ft_size << std::endl;
				init_tree(ft_size);
				
			}

			~map()
			{
				ft_allocator.destroy(ft_end);
				ft_allocator.deallocate(ft_end, 1);
				ft_allocator.destroy(ft_begin);
				ft_allocator.deallocate(ft_begin, 1);
			}

			/* *** INSERT *** */
			//single
			pair<iterator,bool> insert (const value_type& val) {
				if (!ft_size)
				{
					ft_allocator.construct(ft_root, map_node(val));
					ft_root->left = ft_begin;
					ft_root->right = ft_end;
					ft_end->parent = ft_root;
					ft_begin->parent = ft_root;
					ft_begin = ft_root;
					ft_size++;

					return (ft::make_pair(iterator(ft_root), true));
				}
				if (ft_size < 3) {
					map_node *new_node = ft_allocator.allocate(1);
					ft_allocator.construct(new_node, map_node(val));
					new_node->parent = ft_root->parent;
					if (ft_size == 1) {
						new_node->right = ft_root->right;
						if (new_node->right)
							new_node->right->parent = new_node;
						new_node->left = NULL;
						ft_root->right = new_node;
					} else {
						new_node->left = ft_root->left;
						if (new_node->left)
							new_node->left->parent = new_node;
						new_node->right = NULL;
						ft_root->left = new_node;
					}
					this->setHeight(new_node);
					ft_size++;
					ft_end->parent = ft_root;
					ft_end = new_node;
				
					return (ft::make_pair(iterator(new_node), true));
				}
/*
				if (ft_size < 3) {
					map_node *new_node = ft_allocator.allocate(1);
					ft_allocator.construct(new_node, map_node(val));
					new_node->parent = ft_root->parent;
					new_node->right = ft_end;
					new_node->left = ft_root->left;

					this->setHeight(new_node);
					
					ft_root->right = new_node;
					ft_root->left = ft_root->prev();
					ft_size++;
					return (ft::make_pair(iterator(ft_root), true));
				}
				ft_size++;*/
				return (ft::make_pair(iterator(ft_root), true));
				//check if areldy exist
		/*		iterator it = find(val.first);
				if (it != this->end())
					return (ft::make_pair(it, false));
				std::cout << "hi3?|\n";*/
			}

			/* *** OPERATORS *** */

			//find
			iterator find (const key_type& k) {
				map_node *node = ft_root;

				while (node && node != ft_end) {
					if (ft_compare(node->value.first, k))
						return iterator(node);
					node = node->left;
				}

				return iterator(ft_end);
			}

			const_iterator find(const key_type &k) const {
				map_node *node = ft_root;

				while (node && node != ft_end) {
					if (ft_compare(node->value.first, k))
						return iterator(node);
					node = node->left;
				}

				return iterator(ft_end);
			}

			/* *** ITERATORS *** */

			iterator begin()	{ return iterator(ft_begin); }

			iterator end()	 	{ return iterator(ft_end); }

			size_type max_size() const { return (ft_allocator.max_size()); }
	};
}

#endif