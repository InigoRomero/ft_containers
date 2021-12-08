/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:31:55 by iromero-          #+#    #+#             */
/*   Updated: 2021/12/08 15:34:48 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <iostream>

template<typename> struct is_integral: public std::false_type {};
template<> struct is_integral<bool>: public std::true_type {};
template<> struct is_integral<char>: public std::true_type {};
template<> struct is_integral<char32_t>: public std::true_type {};
template<> struct is_integral<char16_t>: public std::true_type {};
template<> struct is_integral<wchar_t>: public std::true_type {};
template<> struct is_integral<signed char>: public std::true_type {};
template<> struct is_integral<short int>: public std::true_type {};
template<> struct is_integral<int>: public std::true_type {};
template<> struct is_integral<long int>: public std::true_type {};
template<> struct is_integral<long long int>: public std::true_type {};
template<> struct is_integral<unsigned char>: public std::true_type {};
template<> struct is_integral<unsigned short int>: public std::true_type {};
template<> struct is_integral<unsigned int>: public std::true_type {};
template<> struct is_integral<unsigned long int>: public std::true_type {};
template<> struct is_integral<unsigned long long int>: public std::true_type {};


#endif