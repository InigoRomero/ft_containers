/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:30:01 by iromero-          #+#    #+#             */
/*   Updated: 2022/02/12 17:30:44 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft {
    template<bool Cond, class T = void> struct enable_if {};

    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };
}

#endif // ENABLE_IF_HPP