/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:02:46 by iromero-          #+#    #+#             */
/*   Updated: 2021/12/11 20:13:09 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"

template <typename iterator> class ft_iterator;

#include <vector>
namespace ft {
    template < typename T, typename Alloc = std::allocator<T> > 
    class vector {
        public:

            /* *** DEFINITIONS *** */
            typedef T                                                   value_type;
            typedef Alloc                                               allocator_type;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;
            typedef ft_iterator<pointer>                            iterator;
            typedef ft_iterator<const_pointer>                      const_iterator;
            typedef ReverseIterator<iterator>                           reverse_iterator;
            typedef ReverseIterator<const_iterator>                     const_reverse_iterator;
            typedef ptrdiff_t                                           difference_type;
            typedef size_t                                              size_type;


        private:
            /* *** VARIABLES *** */
            pointer             ft_buff;
            size_type           ft_capacity;
            allocator_type      ft_allocator;

        public:

            /* *** CONSTRUCTORS *** */
            //  default
            explicit vector (const allocator_type& alloc = allocator_type()): 
            ft_buff(NULL), ft_capacity(0) { static_cast<void>(alloc); }
            //fill 
            explicit vector (size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type());
            //range 
            template <class InputIterator>
                    vector (InputIterator first, InputIterator last,
                            const allocator_type& alloc = allocator_type());
            //copy	
            vector (const vector& x);

            /* *** ITEATOR USE *** */
            iterator begin() {
                return iterator(ft_buff);
            }
            const_iterator  begin() const {
                return const_iterator(ft_buff);
            }
            iterator end() {
                return iterator(ft_buff + ft_capacity);
            }
            const_iterator  end() const {
                return const_iterator(ft_buff + ft_capacity);
            }
            reverse_iterator rbegin() {
                return reverse_iterator(end());
            }
            const_reverse_iterator rbegin() const {
                return const_reverse_iterator(end());
            }
            reverse_iterator rend() {
                return reverse_iterator(begin());
            }
            const_reverse_iterator rend() const {
                return const_reverse_iterator(begin());
            }

            /* *** Capacity *** */
            size_type size() const { return ft_capacity; }

            size_type max_size() const { return ft_allocator.max_size(); }

            void resize (size_type n, value_type val = value_type()) { //later

            }

            size_type capacity() const { return ft_capacity; }

            bool empty() const { ft_capacity == 0; }

            void reserve (size_type n) { //later
                if (n > capacity())
                {
                    allocator_type& __a = ft_allocator();
        
                }
            }

            void shrink_to_fit(){ //later

            }

            /* *** ELEMENT ACCESS *** */
            value_type&     operator[](size_type n) {
                return ft_buff[n];
            }
            
            const value_type&   operator[](size_type n) const {
                return ft_buff[n];
            }

            /* *** MODIFIERS *** */
            
            //Insert single lady
            void insert (iterator position, size_type n, const value_type& val) {
                size_t aux = ft_capacity;
                if (n > this->max_size())
                        throw (std::length_error("vector::insert (fill)"));
                ft_capacity = (ft_capacity + n > ft_capacity) ? ft_capacity + n : ft_capacity;
                pointer tmp = ft_allocator.allocate(ft_capacity);
                iterator it = begin();
                iterator ite = end();
                int i  = 0;
                while (it < position)
                    tmp[i++] = *it++;
                for (size_t i = 0; i < n; i++)
                    tmp[i++] = val;
                while (it < ite)
                    tmp[i++] = *it++;
                ft_allocator.deallocate(ft_buff, aux);
                ft_buff = tmp;

        }
    };
    /* *** RELATIONAL OPERATORS *** */

    template <class T, class Alloc>
    inline bool operator== (const ft::vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (lhs == rhs);
    }

    template <class T, class Alloc>
    inline bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    inline bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (lhs < rhs);
    }

    template <class T, class Alloc>
    inline bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (lhs <= rhs);
    }

    template <class T, class Alloc>
    inline bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (lhs > rhs);
    }

    template <class T, class Alloc>
    inline bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (lhs >= rhs);
    }

} 

template <typename iterator>
class ft_iterator {

public:

        typedef iterator                                                        iterator_type;
        typedef typename iterators_traits<iterator_type>::difference_type       difference_type;
        typedef typename iterators_traits<iterator_type>::value_type            value_type;
        typedef typename iterators_traits<iterator_type>::pointer               pointer;
        typedef typename iterators_traits<iterator_type>::reference             reference;
        typedef typename iterators_traits<iterator_type>::iterator_category     iterator_category;

private:

        iterator_type                                                           m_current;

public:

        ft_iterator(): m_current() {}
        explicit ft_iterator(iterator_type x): m_current(x) {}
        ft_iterator(const ft_iterator& x): m_current(x.m_current) {}
        template <typename iter>
        ft_iterator(const ft_iterator<iter>& i): m_current(i.base()) {}
        const iterator_type&    base() const {
            return m_current;
        }

        reference   operator*() const { 
            return *m_current;
        }
        pointer     operator->() const {
            return m_current;
        }
        ft_iterator&  operator++() {
            ++m_current;
            return *this;
        }
        ft_iterator    operator++(int) {
            return ft_iterator(m_current++);
        }
        ft_iterator&  operator--() {
            --m_current;
            return *this;
        }
        ft_iterator   operator--(int) {
            return ft_iterator(m_current--);
        }
        reference    operator[](difference_type n) const {
            return m_current[n];
        }
        ft_iterator&    operator+=(difference_type n) {
            m_current += n;
            return *this;
        }
        ft_iterator     operator+(difference_type n) {
            return ft_iterator(m_current + n);
        }
        ft_iterator&    operator-=(difference_type n) {
            m_current -= n;
            return *this;
        }
        ft_iterator   operator-(difference_type n) const {
            return ft_iterator(m_current - n);
        } 
};

template <typename iterator1, typename iterator2>
bool operator==(const ft_iterator<iterator1>& x, const ft_iterator<iterator2>& y) {
    return (x.base() == y.base());
}
template <typename iterator1, typename iterator2>
bool operator>(const ft_iterator<iterator1>& x, const ft_iterator<iterator2>& y) {
    return x.base() > y.base();
}
template <typename iterator1, typename iterator2>
bool operator<(const ft_iterator<iterator1>& x, const ft_iterator<iterator2>& y) {
    return x.base() < y.base();
}
template <typename iterator1, typename iterator2>
bool operator!=(const ft_iterator<iterator1>& x, const ft_iterator<iterator2>& y) {
    return !(x == y);
}
template <typename iterator1, typename iterator2>
bool operator>=(const ft_iterator<iterator1>& x, const ft_iterator<iterator2>& y) {
    return !(x < y);
}
template <typename iterator1, typename iterator2>
bool operator<=(const ft_iterator<iterator1>& x, const ft_iterator<iterator2>& y) {
    return !(x > y);
}
template <typename iterator1, typename iterator2>
typename ft_iterator<iterator1>::difference_type operator-(const ft_iterator<iterator1>& x, const ft_iterator<iterator2>& y) {
    return x.base() - y.base();
}
template<typename iterator>
ft_iterator<iterator>   operator+(typename ft_iterator<iterator>::difference_type n, const ft_iterator<iterator>& x) {
    return ft_iterator<iterator>(x.base() + n);
}

#endif