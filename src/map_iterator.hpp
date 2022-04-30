/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:40:30 by iromero-          #+#    #+#             */
/*   Updated: 2022/04/30 15:36:14 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "BSTree.hpp"
#include "iterators_traits.hpp"
    
namespace ft {
template< typename Iter, typename Pointer, typename Reference>
class map_iterator {

    public:
            typedef Iter                                                                iterator_type;
            typedef typename ft::iterators_traits<iterator_type>::difference_type       difference_type;
            typedef typename ft::iterators_traits<iterator_type>::value_type            value_type;
            typedef typename ft::iterators_traits<iterator_type>::pointer               pointer;
            typedef typename ft::iterators_traits<iterator_type>::reference             reference;
            typedef typename ft::iterators_traits<iterator_type>::iterator_category     iterator_category;
            typedef          BSTNode<value_type>                                        node_pointer;

    private:
            node_pointer                                                            ft_node;
            value_type                                                              ft_val;

    public:

            map_iterator(): ft_node(nullptr) {}
            
            map_iterator(const node_pointer p): ft_node(p), ft_val(p->value) {}

            map_iterator(const node_pointer &p): ft_node(p), ft_val(p->value) {}

            //template <typename iter>
            //map_iterator(const map_iterator<iter>& p): ft_node(p) {}

            const iterator_type&    base() const {
                return ft_node;
            }

            reference   operator*() const { 
                return *ft_node;
            }

            pointer     operator->() const {
                return this->ft_node;
            }

            map_iterator &operator=(map_iterator const &other) {
                this->ft_node = other.ft_node;
                return (*this);
            }

            map_iterator&  operator++() {
                ++ft_node;
                return *this;
            }

            map_iterator    operator++(int) {
                return map_iterator(ft_node++);
            }

            map_iterator&  operator--() {
                --ft_node;
                return *this;
            }

            map_iterator   operator--(int) {
                return map_iterator(ft_node--);
            }

            reference    operator[](difference_type n) const {
                return ft_node[n];
            }

            map_iterator&    operator+=(difference_type n) {
                ft_node += n;
                return *this;
            }

            map_iterator     operator+(difference_type n) {
                return map_iterator(ft_node + n);
            }

            map_iterator&    operator-=(difference_type n) {
                ft_node -= n;
                return *this;
            }
            
            map_iterator   operator-(difference_type n) const {
                return map_iterator(ft_node - n);
            } 
    };
/*
    template <typename iterator1, typename iterator2>
    bool operator==(const map_iterator<iterator1>& x, const map_iterator<iterator2>& y) {
        return (x.base() == y.base());
    }
    template <typename iterator1, typename iterator2>
    bool operator>(const map_iterator<iterator1>& x, const map_iterator<iterator2>& y) {
        return x.base() > y.base();
    }
    template <typename iterator1, typename iterator2>
    bool operator<(const map_iterator<iterator1>& x, const map_iterator<iterator2>& y) {
        return x.base() < y.base();
    }
    template <typename iterator1, typename iterator2>
    bool operator!=(const map_iterator<iterator1>& x, const map_iterator<iterator2>& y) {
        return !(x == y);
    }
    template <typename iterator1, typename iterator2>
    bool operator>=(const map_iterator<iterator1>& x, const map_iterator<iterator2>& y) {
        return !(x < y);
    }
    template <typename iterator1, typename iterator2>
    bool operator<=(const map_iterator<iterator1>& x, const map_iterator<iterator2>& y) {
        return !(x > y);
    }
    template <typename iterator1, typename iterator2>
    typename map_iterator<iterator1>::difference_type operator-(const map_iterator<iterator1>& x, const map_iterator<iterator2>& y) {
        return x.base() - y.base();
    }
    template<typename iterator>
    map_iterator<iterator>   operator+(typename map_iterator<iterator>::difference_type n, const map_iterator<iterator>& x) {
        return map_iterator<iterator>(x.base() + n);
    }*/

}
#endif