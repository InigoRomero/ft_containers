/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:13:17 by iromero-          #+#    #+#             */
/*   Updated: 2022/09/15 19:35:36 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include "reverse_iterator.hpp"
#include "bidirectionnal_iterator.hpp"
#include "RedBlackTree.hpp"

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
			typedef	ft::RedBlackTree<value_type>							map_node;
			typedef ft::bidirectionnal_iterator<map_node, value_type>						iterator;
			typedef ft::const_bidirectionnal_iterator<map_node, const value_type, iterator>	const_iterator;
			typedef ft::ReverseIterator<iterator> 											reverse_iterator;
			typedef ft::ReverseIterator<const_iterator>										const_reverse_iterator;
			typedef std::ptrdiff_t 															difference_type;
			typedef size_t 																	size_type;
			typedef typename Alloc::template rebind<map_node>::other						alloc_node;

        private:
		
            map_node	*ft_root;
			map_node	*ft_end;
			map_node	*ft_begin;
			size_type	ft_size;
			key_compare ft_compare;
			alloc_node	ft_allocator;


        public:


			class value_compare
			{
				friend class map;

				protected:

					Compare comp;

					value_compare(Compare c): comp(c)
					{

					}

				public:

					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					bool operator()(const value_type &x, const value_type &y) const
					{
						return (comp(x.first, y.first));
					}
			};

            /* *** CONSTRUCTORS *** */
            //  default
            explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()):
            ft_root(), ft_compare(comp), ft_allocator(alloc) {
				// root
				ft_root = ft_allocator.allocate(300);
				ft_allocator.construct(ft_root, map_node());
				//begin
				ft_begin = ft_allocator.allocate(300);
				ft_allocator.construct(ft_begin, map_node());
				// end
				ft_end = ft_allocator.allocate(300);
				ft_allocator.construct(ft_end, map_node());
				//ft_root->initializeNULLBSTNode(ft_root->_node);
            }

			//range
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
			ft_root(),ft_size(0),  ft_compare(comp), ft_allocator(alloc)  {
				for (InputIterator it = first; it != last; it++)
					ft_size++;
				ft_root = ft_allocator.allocate(ft_size * 300);
				ft_allocator.construct(ft_root, map_node());
				for (InputIterator it = first; it != last; it++) 
					ft_root->insert(ft::make_pair(it->first, it->second));
			}

			~map()
			{
			}

			map& operator=(const map& x)
			{
				ft_compare = x.ft_compare;
				ft_size = 0;
				ft_allocator = x.ft_allocator;
				insert(x.begin(), x.end());
				return (*this);
			}
			/* *** ELEMENT ACCESS *** */

			mapped_type& operator[](const key_type& k)
			{
				return (*(this->insert(value_type(k, mapped_type())).first)).second;
			}
			/* *** MODIFIERS *** */
			
			//single
			pair<iterator,bool> insert (const value_type& val) {
				ft_end->_node = ft_root->insert(val);
				//std::cout << "--------------------------------------\n";
				//ft_root->printTree();
				//std::cout << "--------------------------------------\n";
				ft_size++;
				return (ft::make_pair(iterator(*ft_end), true));
			}

			//with hint
			iterator			insert (iterator position, const value_type& val) {
				(void)position;
				ft_end->_node = ft_root->insert(val);
				//std::cout << "--------------------------------------\n";
				//ft_root->printTree();
				//std::cout << "--------------------------------------\n";
				ft_size++;
				return iterator(*ft_end);
			}

			//range
			template <class InputIterator>
  			void				insert (InputIterator first, InputIterator last) {
				while (first != last) {
					//map_node *node = ft_root->insert(first);
					first++;
				}
			}

			void erase (iterator position){
				(void)position;
			}

			size_type erase (const key_type& k){
				(void)k;
				return 1;
			}

			void erase (iterator first, iterator last){
				(void)first;
				(void)last;
			}

			void swap (map& x){
				(void)x;
			}

			void clear() {

			}

			/* *** OBSERVERS *** */
			key_compare key_comp() const
			{
				return (ft_compare);
			}

			value_compare value_comp() const
			{
				return (value_compare(ft_compare));
			}


			/* *** OPERATORS *** */

			//find
			iterator			find (const key_type& k) {
			/*	map_node *node = ft_root;

				while (node && node != ft_root->maximum(ft_root->_node)) {
					if (ft_compare(node->value.first, k))
						return iterator(node);
					node = node->left;
				}

				return iterator(*ft_root->maximum(ft_root->_node));*/
				(void)k;
				return iterator(*ft_end);
			}

			const_iterator		find(const key_type &k) const {
				/*map_node *node = ft_root;

				while (node && node != ft_root->maximum(ft_root->_node)) {
					if (ft_compare(node->value.first, k))
						return iterator(node);
					node = node->left;
				}

				return iterator(ft_root->maximum(ft_root->_node));*/
				(void)k;
				return const_iterator(*ft_end);
			}

			size_type count (const key_type& k) const
			{
				if (find(k) == end())
					return (0);
				return (1);
			}

			iterator lower_bound (const key_type& k)
			{
				(void)k;
				return iterator(*ft_begin);
			}

			const_iterator lower_bound (const key_type& k) const
			{
				(void)k;
				return const_iterator(*ft_begin);
			}

			iterator upper_bound (const key_type& k)
			{
				(void)k;
				return iterator(*ft_end);
			}

			const_iterator upper_bound (const key_type& k) const
			{
				(void)k;
				return const_iterator(*ft_end);
			}

			pair<iterator,iterator> equal_range (const key_type& k)
			{
				(void)k;
				return (ft::make_pair(iterator(*ft_end), iterator(*ft_end)));
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				(void)k;
				return (ft::make_pair(const_iterator(*ft_end), const_iterator(*ft_end)));
			}


			/* *** ITERATORS *** */

			iterator		begin() { 
				ft_root->_node = ft_root->minimum(ft_root->_node);
				return iterator(*ft_root); 
			}

			iterator 		end() {
				return iterator(*ft_end);
			}

			const_iterator	begin() const { 
				ft_root->_node = ft_root->minimum(ft_root->_node);
				return const_iterator(*ft_root); 
			}

			const_iterator 	end() const { 
				return const_iterator(*ft_end); 
			}

			reverse_iterator rbegin(){
				return reverse_iterator(*ft_end);
			}
			
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(*ft_end);
			}

			reverse_iterator rend() {
				return reverse_iterator(*ft_begin);
			}
			 
			const_reverse_iterator rend() const {
				return const_reverse_iterator(*ft_begin);
			}

			/* *** CAPACITY *** */
			
			bool		empty() const {	return ft_size ? false : true; }

            size_type	size() const { return ft_size; }

            size_type	max_size() const { return ft_allocator.max_size(); }
	};

}

#endif