/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:43:53 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/15 18:12:20 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

//?https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator

namespace ft {
		template<typename T>
		class random_access_iterator {
				public:
						typedef typename ft:random_access_iterator_tag		iterator_category;
						typedef T											value_type;
						typedef T*											pointer;
						typedef T&											reference;
						typedef	std::ptrdiff_t						difference_type;
						typedef random_access_iterator<T>					iterator;
	};
}





#endif