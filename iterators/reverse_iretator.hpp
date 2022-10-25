/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iretator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:18:34 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/25 09:24:56 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

//?https://en.cppreference.com/w/cpp/iterator/reverse_iterator

#include "iterator_traits.hpp"

namespace ft {
		template <class Iter>
		class reverse_iterator {
			
			public:

					//********** ***********//
					//**** MEMBER TYPES ****//
					//********** ***********//

					typedef Iter														iterator_type;
					typedef typename ft::iterator_traits<Iter>::iterator_category		iterator_category;
					typedef typename ft::iterator_traits<Iter>::value_type				value_type;
					typedef typename ft::iterator_traits<Iter>::difference_type			difference_type;
					typedef typename ft::iterator_traits<Iter>::pointer					pointer;
					typedef typename ft::iterator_traits<Iter>::reference				reference;


			protected:

					iterator_type														_it;

			public:

					//********** ***********//
					//**** CONSTRUCTORS ****//
					//********** ***********//

					//?https://cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/

					//default constructor
					reverse_iterator()														{ };
					//initialization constructor 
					explicit reverse_iterator (iterator_type it): _it(it)					{ };
					//copy constructor	
					template <class Iter>
					reverse_iterator (const reverse_iterator<Iter>& rev_it): _it(rev_it)	{ };
					//Base
					iterator_type base() const									{ return (_it);};


					//****************** ******************//
					//********* OPERATOR OVERLOADS ********//
					//****************** ******************//

					//?https://en.cppreference.com/w/cpp/iterator/reverse_iterator
		};
}

#endif