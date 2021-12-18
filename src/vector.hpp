/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:02:46 by iromero-          #+#    #+#             */
/*   Updated: 2021/12/18 16:20:39 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"

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
            allocator_type      ft_allocator;

        public:

            /* *** CONSTRUCTORS *** */
            //  default
            explicit vector (const allocator_type& alloc = allocator_type()): 
            ft_buff(NULL), ft_capacity(0) { static_cast<void>(alloc); }
            //fill 
            explicit vector (size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type()):
                            ft_buff(NULL), ft_capacity(n){
                                ft_buff = ft_allocator.allocate(ft_capacity);
                                size_t i = 0;
                                while (i < ft_capacity)
                                    ft_buff[i++] = val;
                                static_cast<void>(alloc);
                            };
            //range 
            template <class InputIterator>
                    vector (InputIterator first, InputIterator last,
                    typename enable_if<!std::is_integral<InputIterator>::value, bool>::type = true,
                            const allocator_type& alloc = allocator_type()):
                            ft_buff(NULL), ft_capacity(0) {
                                iterator position = begin();
                                this->insert(position, first, last);
                                static_cast<void>(alloc);
                            };
            //copy	
            vector (const vector& x){
                *this = x;
            };

            //destructor
            ~vector () {
                ft_allocator.destroy(ft_buff);
                ft_allocator.deallocate(ft_buff, ft_capacity);
            }
            /* *** ITEATOR *** */
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
                if (n < ft_capacity)
                    ft_capacity = n;
                else if(n > ft_capacity) {
                    value_type* ptr = ft_allocator.allocate(n);
                    for (size_type i = 0; i < ft_capacity; i++)
                        ptr[i] = ft_buff[i];
                    ft_allocator.deallocate(ft_buff, ft_capacity);
                    ft_capacity = n;
                    ft_buff = ptr;
                    for (; ft_capacity < n; ++ft_capacity)
                        ft_buff[ft_capacity] = val;
                }
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

            //push_back
            void push_back (const value_type& val) {
                iterator position = end();
                this->insert(position, val);
            }

            //pop_back
            void pop_back() {
                ft_capacity--;
                pointer tmp = ft_allocator.allocate(ft_capacity);
                iterator it = begin();
                size_t i  = 0;
                while (i < ft_capacity)
                    tmp[i++] = *it++;
                ft_allocator.deallocate(ft_buff, ft_capacity);
                ft_buff = tmp;
            }

            //Insert single lady
            iterator insert (iterator position, const value_type& val) {
                ft_capacity++;
                if (ft_capacity > this->max_size())
                    throw (std::length_error("vector::insert (fill)"));
                pointer tmp = ft_allocator.allocate(ft_capacity);
                iterator it = begin();
                size_t i  = 0;
                while (it < position)
                    tmp[i++] = *it++;
                iterator ret = iterator(tmp + i);
                tmp[i++] = val;
                while (i < ft_capacity)
                    tmp[i++] = *it++;
                ft_allocator.deallocate(ft_buff, ft_capacity);
                ft_buff = tmp;
                return ret;
            }

            //Insert multiple FILL
            void insert (iterator position, size_type n, const value_type& val) {
                size_t aux = ft_capacity;
                if (n > this->max_size())
                        throw (std::length_error("vector::insert (fill)"));
                ft_capacity += n;
                pointer tmp = ft_allocator.allocate(ft_capacity);
                iterator it = begin();
                size_t i  = 0;
                while (it < position)
                    tmp[i++] = *it++;
                n += i;
                for (; i < n; i++)
                    tmp[i] = val;
                while (i < ft_capacity)
                    tmp[i++] = *it++;
                ft_allocator.deallocate(ft_buff, aux);
                ft_buff = tmp;
            }

            //Insert range
            void insert (iterator position, iterator first, iterator last) {
                size_t aux = ft_capacity;
                size_t size = (last - first);
                if (size > this->max_size())
                    throw (std::length_error("vector::insert (fill)"));
                ft_capacity += size;
                pointer tmp = ft_allocator.allocate(ft_capacity);
                iterator it = begin();
                size_t i  = 0;
                while (it < position)
                    tmp[i++] = *it++;
                size += i;
                while (i < size)
                    tmp[i++] = *first++;
                while (i < ft_capacity)
                    tmp[i++] = *it++;
                ft_allocator.deallocate(ft_buff, aux);
                ft_buff = tmp;
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
                ft_capacity = 0;
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