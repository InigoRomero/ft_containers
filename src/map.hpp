/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:13:17 by iromero-          #+#    #+#             */
/*   Updated: 2022/06/14 20:09:37 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "reverse_iterator.hpp"
#include "bidirectionnal_iterator.hpp"
#include "RedBlackTree.hpp"
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
			typedef	ft::RedBlackTree<key_type, mapped_type>									map_node;
			typedef ft::bidirectionnal_iterator<map_node, value_type>						iterator;
			typedef ft::const_bidirectionnal_iterator<map_node, const value_type, iterator>	const_iterator;
			typedef ft::ReverseIterator<iterator> 											reverse_iterator;
			typedef ft::ReverseIterator<const_iterator>										const_reverse_iterator;
			typedef std::ptrdiff_t 															difference_type;
			typedef size_t 																	size_type;
			typedef typename Alloc::template rebind<map_node>::other						alloc_node;

        private:
		
            map_node	*ft_root;
			size_type	ft_size;
			key_compare ft_compare;
			alloc_node	ft_allocator;


        public:

            /* *** CONSTRUCTORS *** */
            //  default
            explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()):
            ft_root(), ft_compare(comp), ft_allocator(alloc) {
				ft_root = ft_allocator.allocate(24);
				ft_allocator.construct(ft_root, map_node());
				ft_root->initializeNULLBSTNode(ft_root->_node , ft_root->_node->parent);
            }

			//range
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
			ft_root(), ft_compare(comp), ft_allocator(alloc) {
				for (InputIterator it = first; it != last; it++)
					ft_size++;
				std::cout << "how much -->" << ft_size << std::endl;
				
			}

			~map()
			{
			}

			/* *** INSERT *** */
			//single
			pair<iterator,bool> insert (const value_type& val) {
				
				return (ft::make_pair(iterator(ft_root), true));
			}

			/* *** OPERATORS *** */

			//find
			iterator find (const key_type& k) {
				map_node *node = ft_root;

				while (node && node != ft_root->maximum(ft_root->_node)) {
					if (ft_compare(node->value.first, k))
						return iterator(node);
					node = node->left;
				}

				return iterator(ft_root->maximum(ft_root->_node));
			}

			const_iterator find(const key_type &k) const {
				map_node *node = ft_root;

				while (node && node != ft_root->maximum(ft_root->_node)) {
					if (ft_compare(node->value.first, k))
						return iterator(node);
					node = node->left;
				}

				return iterator(ft_root->maximum(ft_root->_node));
			}

			/* *** ITERATORS *** */

			iterator begin() { 
				map_node *node = ft_root;
				node->_node = ft_root->minimum(ft_root->_node);
				return iterator(node); 
			}

			iterator end() { 
				map_node *node = ft_root;
				node->_node = ft_root->maximum(ft_root->_node);
				return iterator(node); 
			}

			size_type max_size() const { return (ft_allocator.max_size()); }
	};
}

#endif