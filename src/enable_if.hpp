/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:30:01 by iromero-          #+#    #+#             */
/*   Updated: 2021/12/08 15:31:04 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

template<bool Cond, class T = void> struct enable_if {};

template<class T>
struct enable_if<true, T> {
    typedef T type;
};

#endif // ENABLE_IF_HPP