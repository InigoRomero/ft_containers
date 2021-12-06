/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:56:14 by iromero-          #+#    #+#             */
/*   Updated: 2021/12/06 19:44:41 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ReverseIterator_HPP 
#define ReverseIterator_HPP

#include <iostream>
#include "iterators_traits.hpp"

template<typename iterator>
class ReverseIterator {
	protected:
		iterator 										current;
		typedef iterators_traits<iterator>              traits_type;
		
	public:
		
		typedef iterator                                	iterator_type;
		typedef typename traits_type::iterator_category		iterator_category;
		typedef typename traits_type::value_type   			value_type;
		typedef typename traits_type::difference_type   	difference_type;
		typedef typename traits_type::pointer           	pointer;
		typedef typename traits_type::reference         	reference;
		//default constructor
		ReverseIterator() { return; };
		//initalization constructor
		explicit ReverseIterator(iterator_type x): current(x) {}
		ReverseIterator(const ReverseIterator& x): current(x.current) {}
		//copy / type-cast constructor
		template<typename Iter>
    	ReverseIterator(const ReverseIterator<Iter>& x): current(x.base()) {}

		iterator_type base() const{
			return current;
		}

		reference	operator*() const {
			iterator tmp = current;
			return *--tmp;
    	}

		ReverseIterator	operator++(int) {
			ReverseIterator    tmp = *this;
			--current;
			return tmp;
    	}

};

template<typename _iterator>
bool operator==(const ReverseIterator<_iterator>& x, const ReverseIterator<_iterator>& y) {
	return x.base() == y.base();
}

template<typename _iterator>
bool operator!=(const ReverseIterator<_iterator>& x, const ReverseIterator<_iterator>& y) {
	return !(x == y);
}

template<typename iteratorL, typename iteratorR>
bool operator!=(const ReverseIterator<iteratorL>& x, const ReverseIterator<iteratorR>& y) {
	return !(x == y);
}

#endif