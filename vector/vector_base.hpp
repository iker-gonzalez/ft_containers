/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_base.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:44:52 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/02 11:55:21 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BASE_HPP
#define VECTOR_BASE_HPP

#include <memory>

namespace ft {
	template <class T, class Allocator = std::allocator <T> > 
	class vector {
		
		public:
				//member types
				typedef T 											value_type;
				typedef Allocator									allocator_type;
				typedef typename allocator_type::size_type			size_type;
				typedef typename allocator_type::reference			reference;
				typedef typename allocator_type::const_reference	const_reference;
				typedef typename allocator_type::pointer			pointer;
				typedef typename allocator_type::const_pointer		const_pointer;

			//member functions
				//constructors - destructor - operator=
				explicit vector (const allocator_type& alloc = allocator_type());
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
				template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
				vector (const vector& x);
				~vector ();
				vector& operator= (const vector& x);

				//capacity
				size_type size() const;
				size_type max_size() const;
				void resize (size_type n, value_type val = value_type());
				size_type capacity() const;
				bool empty() const;
				void reserve (size_type n);
	};
}





#endif