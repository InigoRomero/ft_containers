/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:13:17 by iromero-          #+#    #+#             */
/*   Updated: 2022/03/12 18:02:58 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "BSTree.hpp"
//#include "map_iterator.hpp"

//template <typename iterator> class map_iterator;

namespace ft {
template < class Key,                                               // map::key_type
           class T,                                                 // map::mapped_type
           class Compare = std::less<Key>,                          // map::key_compare
           class Alloc = std::allocator< ft::pair<const Key, T> >   // map::allocator_type
           > 
    class map {
        public:

            /* *** DEFINITIONS *** */
			typedef Key																	key_type;
			typedef T																	mapped_type;
			typedef ft::pair<const key_type,mapped_type>								value_type;
			typedef Compare																key_compare;
			typedef Alloc																allocator_type;
			typedef typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
		//	typedef ft::map_iterator<value_type, pointer, reference>					iterator;
		//	typedef ft::map_iterator<value_type, const_pointer, const_reference>		const_iterator;
        //  typedef ReverseIterator<iterator>											reverse_iterator;
        //  typedef ReverseIterator<const_iterator>										const_reverse_iterator;
			typedef std::ptrdiff_t														difference_type;
			typedef size_t																size_type;
			typedef																		BSTNode<value_type> map_node;
			typedef typename Alloc::template rebind<map_node>::other					alloc_node;

        private:
            map_node	*ft_root;
			map_node	*ft_begin;
			map_node	*ft_end;
			size_type	ft_size;
			key_compare ft_compare;
			alloc_node	ft_allocator;

            void init_tree()
			{
				ft_root = ft_allocator.allocate(2);
				ft_allocator.construct(ft_root, value_type());

				ft_begin = ft_allocator.allocate(2);
				ft_allocator.construct(ft_begin, value_type());

				ft_end = ft_allocator.allocate(2);
				ft_allocator.construct(ft_end, value_type());

				ft_begin->parent = ft_root;
				ft_end->parent = ft_root;
				ft_root->left = ft_begin;
				ft_root->right = ft_end;
			}

        public:

            /* *** CONSTRUCTORS *** */
            //  default
            explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()):
            ft_root(), ft_end(), ft_size(0), ft_compare(comp), ft_allocator(alloc) {
                init_tree();
            }
    };
}

#endif