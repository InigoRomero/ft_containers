/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:41:31 by macbook           #+#    #+#             */
/*   Updated: 2022/02/06 19:01:54 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP


# include <iostream>
# include <string>
# include <memory>
# include "./vector.hpp"
# include "./reverse_iterator.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack{
		public:
			typedef T 				value_type;
			typedef Container 		container_type;
			typedef size_t			size_type;

			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {std::cout << "hi2\n";}

			bool empty()const{ 
                return ( c.empty() ); 
            }

			size_type size()const {
                return ( c.size() ); 
            }
			
			value_type& top(){
                return (c.back());
            }

			const value_type& top()const {
                return (c.back());
            }

			void push (const value_type& val) {
                return (c.push_back(val));
            }

			void pop() {
                return (c.pop_back());
            }
		
		protected:
			container_type	c;
		private:
			template<typename _T, typename C>
			friend bool operator==(const stack<_T, C>&, const stack<_T, C>&);

			template<typename _T, typename C>
			friend bool operator<(const stack<_T, C>&, const stack<_T, C>&);
	};
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs.c == rhs.c);};
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return !(lhs == rhs);};
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs.c < rhs.c);};
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return !(rhs < lhs);};
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (rhs < lhs); };
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return !(lhs < rhs);};
} 

#endif