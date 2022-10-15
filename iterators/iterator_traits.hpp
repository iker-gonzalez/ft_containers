/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:50:24 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/15 17:21:16 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS

# include <iostream>
# include <memory>
#include <iterator>

//?https://en.cppreference.com/w/cpp/iterator/iterator_traits

namespace ft {

	template<class Iter>
	class iterator_traits {
			public:
				typedef typename Iter::difference_type		difference_type;
				typedef typename Iter::value_type			value_type;
				typedef typename Iter::pointer				pointer;
				typedef typename Iter::reference			reference;
				typedef typename Iter::iterator_category	iterator_category;
	};

	//*************** ***************//
	//******* SPECIALIZATIONS *******//
	//*************** ***************//

	//T* specialization member types
	template <class T>
	class iterator_traits<T*> {
			public:
				typedef	std::ptrdiff_t						difference_type;
				typedef	T									value_type;
				typedef T*									pointer;
				typedef T&									reference;
				typedef	std::random_access_iterator_tag		iterator_category;
	};

	//const T* specialization member types
	template <class T>
	class iterator_traits<const T*> {
			public:
				typedef	std::ptrdiff_t						difference_type;
				typedef	T									value_type;
				typedef T*									pointer;
				typedef T&									reference;
				typedef	std::random_access_iterator_tag		iterator_category;
	};

}
#endif