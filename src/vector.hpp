/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:02:46 by iromero-          #+#    #+#             */
/*   Updated: 2021/12/19 20:58:15 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"
#include <cstdlib>

template <typename iterator> class ft_iterator;

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
            typedef ft_iterator<pointer>                                iterator;
            typedef ft_iterator<const_pointer>                          const_iterator;
            typedef ReverseIterator<iterator>                           reverse_iterator;
            typedef ReverseIterator<const_iterator>                     const_reverse_iterator;
            typedef ptrdiff_t                                           difference_type;
            typedef size_t                                              size_type;


        private:
            /* *** VARIABLES *** */
            pointer             ft_buff;
            size_type           ft_capacity;
            size_type           ft_size;
            allocator_type      ft_allocator;

            void replicate(size_t n) {
                value_type  *tmp = ft_allocator.allocate(n);

                for (size_type i = 0; i < ft_size; i++)
                    tmp[i] = ft_buff[i];
                ft_allocator.deallocate(ft_buff, ft_capacity);
                ft_buff = tmp;
            }

            void    newCapacity(void)
            {
                replicate((!ft_capacity) ? 1 : 2 * ft_capacity);
                ft_capacity = (!ft_capacity) ? 1 : 2 * ft_capacity;
            }

        public:

            /* *** CONSTRUCTORS *** */
            //  default
            explicit vector (const allocator_type& alloc = allocator_type()): 
            ft_buff(NULL), ft_capacity(0), ft_size(0) { static_cast<void>(alloc); }
            //fill 
            explicit vector (size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type()):
                            ft_buff(NULL), ft_capacity(n), ft_size(0){
                                ft_buff = ft_allocator.allocate(ft_capacity);
                                while (ft_size < ft_capacity)
                                    ft_buff[ft_size++] = val;
                                static_cast<void>(alloc);
                            };
            //range 
            template <class InputIterator>
                    vector (InputIterator first, InputIterator last,
                    typename enable_if<!std::is_integral<InputIterator>::value, bool>::type = true,
                            const allocator_type& alloc = allocator_type()):
                            ft_buff(NULL), ft_capacity(last - first), ft_size(0) {
                                ft_buff = ft_allocator.allocate(ft_capacity);
                                while (first < last)
                                    ft_buff[ft_size++] = *first++;
                                static_cast<void>(alloc);
                            };
            //copy	
            vector (const vector& x): ft_capacity(x.size()), ft_size(-1) {
                ft_buff = ft_allocator.allocate(ft_capacity);
                while (++ft_size < ft_capacity)
                    ft_buff[ft_size] = x[ft_size];
            };

            //destructor
            ~vector () {
                ft_allocator.destroy(ft_buff);
                ft_allocator.deallocate(ft_buff, ft_capacity);
            }

            vector& operator= (const vector& x) {
                if (ft_capacity < x.size()) {
                    ft_allocator.deallocate(ft_buff, ft_capacity);
                    ft_capacity = x.size();
                    ft_buff = ft_allocator.allocate(ft_capacity);
                }
                ft_size = 0;
                while (ft_size < x.size()) {
                    ft_buff[ft_size] = x[ft_size];
                    ++ft_size;
                }
                return *this;
            }
            /* *** ITEATOR *** */
            iterator begin() {
                return iterator(ft_buff);
            }
            const_iterator  begin() const {
                return const_iterator(ft_buff);
            }
            iterator end() {
                return iterator(ft_buff + ft_size);
            }
            const_iterator  end() const {
                return const_iterator(ft_buff + ft_size);
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
            size_type size() const { return ft_size; }

            size_type max_size() const { return ft_allocator.max_size(); }

            void resize (size_type n, value_type val = value_type()) {
                if (n < ft_size)
                    ft_size = n;
                else if(n > ft_size) {
                    value_type* tmp = ft_allocator.allocate(n);
                    for (size_type i = 0; i < ft_size; i++)
                        tmp[i] = ft_buff[i];
                    ft_allocator.deallocate(ft_buff, ft_capacity);
                    ft_size = n;
                    ft_buff = tmp;
                    for (; ft_size < n; ++ft_size)
                        ft_buff[ft_size] = val;
                }
            }

            size_type capacity() const { return ft_capacity; }

            bool empty() const { return (ft_size == 0); }

            void reserve (size_type n) {
                if (n > ft_capacity)
                {
                    value_type      *tmp = ft_allocator.allocate(n);
                    for (size_type i = 0; i < ft_size; i++)
                        tmp[i] = ft_buff[i];
                    ft_allocator.deallocate(ft_buff, ft_capacity);
                    ft_capacity = n;
                    ft_buff = tmp;
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

            value_type& at(size_type n) {
                if (n >= ft_size)
                    throw std::out_of_range("vector");
                return ft_buff[n];
            }

            const value_type&   at(size_type n) const {
                if (n >= ft_size)
                    throw std::out_of_range("vector");
                return ft_buff[n];
            }

            value_type& front() {
                return ft_buff[0];
            }

            const value_type&   front() const {
                return ft_buff[0];
            }

            value_type& back() {
                return ft_buff[ft_size - 1];
            }
            
            const value_type&   back() const {
                return ft_buff[ft_size - 1];
            }

            /* *** MODIFIERS *** */

            //push_back
            void push_back (const value_type& val) {
                if (ft_size + 1 > ft_capacity)
                    newCapacity();
                ft_buff[ft_size++] = val;
            }

            //pop_back
            void pop_back() {
                ft_size--;
            }

            //Insert single lady
            iterator insert (iterator position, const value_type& val) {
                if (ft_size + 1 > this->max_size())
                    throw (std::length_error("vector::insert (fill)"));
                if (ft_size + 1 > ft_capacity)
                    newCapacity();
                size_t i = -1; //save in aux the valuea after the new value
                value_type aux[ft_size];
                while (++i < ft_size)
                    aux[i] = ft_buff[i];
                iterator it = begin();
                i = 0;
                while (it < position)
                   ft_buff[i++] = *it++;
                ft_buff[i] = val;
                ft_size++;
                while (i++ < ft_size)
                    ft_buff[i] = aux[i - 1];
                return it;
            }

            //Insert multiple FILL
            void insert (iterator position, size_type n, const value_type& val) {
                iterator it = begin();
                iterator ite = end();
                
                if (ft_size + n > this->max_size())
                    throw (std::length_error("vector::insert (fill)"));
                if (ft_size + n > ft_capacity) {
                    ft_capacity = ft_size + n;
                    ft_capacity = (!ft_capacity) ? 1 : 2 * ft_capacity;
                    value_type  *tmp = ft_allocator.allocate(ft_capacity);
                    ft_size = 0;
                    while (it < position)
                        tmp[ft_size++] = *it++;
                    n += ft_size;
                    for (; ft_size < n; ft_size++)
                        tmp[ft_size] = val;
                    while (it < ite)
                        tmp[ft_size++] = *it++;
                    ft_allocator.deallocate(ft_buff, ft_capacity);
                    ft_buff = tmp;
                } else {
                    size_t i = -1; //save in aux the valuea after the new value
                    value_type aux[ft_size];
                    while (++i < ft_size)
                        aux[i] = ft_buff[i];
                    iterator it = begin();
                    i = 0;
                    ft_size += n;
                    while (it < position)
                        *it++ ?  i++ : i++;
                    n += i;
                    for (; i < n; i++)
                        ft_buff[i] = val;
                    while (i++ < ft_size)
                        ft_buff[i] = aux[i - n];
                }
            }

            //Insert range
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,
                    typename enable_if<!std::is_integral<InputIterator>::value, bool>::type = true) {
                        size_t n = last - first;
                        size_type i = 0;
                        iterator it = begin();
                        
                        if (ft_size + n > this->max_size())
                            throw (std::length_error("vector::insert (fill)"));
                        if (ft_size + n > ft_capacity) {
                            ft_capacity += n;
                            ft_capacity = (!ft_capacity) ? 1 : 2 * ft_capacity;
                            value_type  *tmp = ft_allocator.allocate(ft_capacity);
                            while (it < position)
                                tmp[i++] = *it++;
                            while (first != last)
                                tmp[i++] = *first++;
                            for (;i < ft_size + n; i++)
                                tmp[i] = ft_buff[i - n];
                            ft_allocator.deallocate(ft_buff, ft_capacity);
                            ft_buff = tmp;
                            ft_size+= n;
                        } else {
                            size_t i = -1; //save in aux the valuea after the new value
                            value_type aux[ft_size];
                            while (++i < ft_size)
                                aux[i] = ft_buff[i];
                            iterator it = begin();
                            i = 0;
                            ft_size += n;
                            while (it < position)
                                *it++ ?  i++ : i++;
                            while (first != last)
                                ft_buff[i++] = *first++;
                            for (;i < ft_size; i++)
                                ft_buff[i] = aux[i - n];
                        }
            };

            //erase single
            iterator erase (iterator position) {
                iterator it = position;
                iterator ite = end();
                while (it + 1 != ite) {
                    *it = *(it + 1);
                    it++;
                }
                ft_capacity -= 1;
                return position;
            };

            //erase range
            iterator erase (iterator first, iterator last){
                iterator ite = end();
                ft_capacity -= (last -first);
                iterator it = first;
                while (last != ite) {
                    *it++ = *last++; 
                }
                return first;
            };

            //clear all content of the vector
            void clear() {
                ft_allocator.destroy(ft_buff);
                ft_size = 0;
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

        iterator_type                                                           ft_current;

public:

        ft_iterator(): ft_current() {}
        explicit ft_iterator(iterator_type x): ft_current(x) {}
        ft_iterator(const ft_iterator& x): ft_current(x.ft_current) {}
        template <typename iter>
        ft_iterator(const ft_iterator<iter>& i): ft_current(i.base()) {}
        const iterator_type&    base() const {
            return ft_current;
        }

        reference   operator*() const { 
            return *ft_current;
        }
        pointer     operator->() const {
            return ft_current;
        }
        ft_iterator&  operator++() {
            ++ft_current;
            return *this;
        }
        ft_iterator    operator++(int) {
            return ft_iterator(ft_current++);
        }
        ft_iterator&  operator--() {
            --ft_current;
            return *this;
        }
        ft_iterator   operator--(int) {
            return ft_iterator(ft_current--);
        }
        reference    operator[](difference_type n) const {
            return ft_current[n];
        }
        ft_iterator&    operator+=(difference_type n) {
            ft_current += n;
            return *this;
        }
        ft_iterator     operator+(difference_type n) {
            return ft_iterator(ft_current + n);
        }
        ft_iterator&    operator-=(difference_type n) {
            ft_current -= n;
            return *this;
        }
        ft_iterator   operator-(difference_type n) const {
            return ft_iterator(ft_current - n);
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