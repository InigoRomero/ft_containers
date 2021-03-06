/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:39:36 by iromero-          #+#    #+#             */
/*   Updated: 2022/06/24 18:46:59 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	/*
	**	Prototypes
	*/

	template <typename T1, typename T2>
	struct pair;

	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 x, T2 y);

	/*
	**	pair class template
	*/

	template <typename T1, typename T2>
	struct pair
	{

		/*
		**	Member types
		*/

		typedef	T1	first_type;
		typedef	T2	second_type;

		/*
		**	Member variables
		*/

		first_type	first;
		second_type	second;

		/*
		**	Public member functions
		*/

		pair() : first(first_type()), second(second_type()) {}
		template <class U, class V>
		pair (const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
		pair(const first_type& a, const second_type& b) : first(a), second(b) {}

		operator const pair<const T1, T2>() const { return (pair<const T1, T2>(first, second)); }

		pair& operator=(const pair& pr) { first = pr.first; second = pr.second; return *this; }
		pair& operator=(pair& pr) { first = pr.first; second = pr.second; return *this; }

		friend bool operator==(const pair& lhs, const pair& rhs) { return lhs.first == rhs.first && lhs.second == rhs.second; }
		friend bool operator!=(const pair& lhs, const pair& rhs) { return !(lhs == rhs); }
		friend bool operator<(const pair& lhs, const pair& rhs) { return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }
		friend bool operator<=(const pair& lhs, const pair& rhs) { return !(rhs < lhs); }
		friend bool operator>(const pair& lhs, const pair& rhs) { return rhs < lhs; }
		friend bool operator>=(const pair& lhs, const pair& rhs) { return !(lhs < rhs); }

	};

	/*
	**	make_pair function template
	*/

    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y) {
        return ( pair<T1,T2>(x,y) );
    }

}

#endif