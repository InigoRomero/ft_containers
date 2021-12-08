/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:39:36 by iromero-          #+#    #+#             */
/*   Updated: 2021/12/08 15:59:29 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP 
#define PAIR_HPP

template <class T1, class T2>
struct Pair {
    typedef T1          a;
    typedef T2          b;

    a                   key;
    b                   value;
    //default constructor
    pair() : key(), value() {}
    //opy / move constructor (and implicit conversion)
    template<typename U, typename V> pair(const pair<U,V>& pr): key(pr.key), value(pr.value) {}
    //initialization constructor
    pair (const key_type& a, const value_type& b) : key(a), value(b) {}
    pair&   operator=(const pair& pr) {
        key = pr.key;
        value = pr.value;
        return *this;
    }
};


#endif