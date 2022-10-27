/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:45:52 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/27 09:19:53 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>

namespace ft {

	//****************** ******************//
	//************* IS_INTEGRAL ***********//
	//****************** ******************//

	template <class T>
	struct is_integral: public std::integral_constant <bool, false> {};
	template < >
	struct is_integral<char> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<char16_t> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<char32_t> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<wchar_t> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<signed char> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<short int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<long int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<long long int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<unsigned char> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<unsigned short int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<unsigned int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<unsigned long int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<unsigned long long int> : public std::integral_constant <bool, true> {};
	
	//****************** ******************//
	//************** ENABLE_IF ************//
	//****************** ******************//

	template <bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct  enable_if <true, T> { typedef T type; };
	

	
}









#endif