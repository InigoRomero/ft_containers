/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:49:48 by macbook           #+#    #+#             */
/*   Updated: 2021/12/29 12:49:50 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

template <class InputIterator1, class InputIterator2>
bool    lexicographical_compare(InputIterator1 first1,
                                InputIterator1 last1,
                                InputIterator2 first2,
                                InputIterator2 last2) {
    while (first1 != last1) {
        if(first2 == last2 || *first2 < *first1) {
            return false;
        }
        else if(*first1 < *first2) {
            return true;
        }
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool    lexicographical_compare(InputIterator1 first1,
                                InputIterator1 last1,
                                InputIterator2 first2,
                                InputIterator2 last2,
                                Compare comp) {
    while (first1 != last1) {
        if((!comp(*first2,*first1) && !comp(*first1,*first2)) || comp(*first2,*first1)) {
            return false;
        }
        else if(comp(*first1,*first2)) {
            return true;
        }
        ++first1;
        ++first2;
    }
    return (comp(*first2,*last2) || comp(*last2,*first2));
}

#endif // LEXICOGRAPHICAL_COMPARE_HPP