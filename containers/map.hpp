/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:19:26 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/03 09:19:27 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../utils/utility.hpp"

namespace ft {
	template<class Key, class T, class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key, T>>
	> class map {
		
		public:
				//********** ***********//
				//**** MEMBER TYPES ****//
				//********** ***********//

				typedef Key										key_type;
				typedef T										mapped_type;
				typedef typename ft::pair<const Key, T>			value_type;
				typedef typename std::size_t					size_type;
				typedef typename std::ptrdiff_t					difference_type;
				typedef Compare									key_compare;
				typedef Allocator								allocator_type;
				typedef value_type&								reference;
				typedef typename Allocator::pointer				pointer;
				typedef typename Allocator::const_pointer		const_pointer;

				//********** ***********//
				//*** MEMBER CLASSES ***//
				//********** ***********//

				class value_compare {
		
					public:
								//***member types***//
								bool							result_type
								typedef value_type				first_argument_type;
								typedef value_type				second_argument_type;
								//***member functions***//
								bool operator()( const value_type& lhs, const value_type& rhs ) const {
									return (_comp(lhs.first, rhs.first));
								}


					protected:
								//***member objects***//
								key_compare						_comp;
								//***constructor***//
								value_compare( Compare c ):		_comp(c) {};
				};

	};

}


#endif