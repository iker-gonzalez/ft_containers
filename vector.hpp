/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:44:52 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/03 09:20:02 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BASE_HPP
#define VECTOR_BASE_HPP

#include <memory>

namespace ft {
	template <class T, class Alloc = std::allocator <T> > 
	class vector {
		
		public:
		/*
		**==========================
		**    DECLARATION
		**==========================
		*/
				//*** MEMBER TYPES ***//
				typedef T 											value_type;
				typedef Alloc										allocator_type;
				typedef typename allocator_type::size_type			size_type;
				typedef typename allocator_type::reference			reference;
				typedef typename allocator_type::const_reference	const_reference;
				typedef typename allocator_type::pointer			pointer;
				typedef typename allocator_type::const_pointer		const_pointer;

				//*** CONSTRUCTORS - DESTRUCTOR - OPERATOR= ***//
				explicit vector (const allocator_type& alloc = allocator_type());
				//!explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
				//!template <class InputIterator>
				//!vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
				//!vector (const vector& x);
				//!~vector ();
				//!vector& operator= (const vector& x);

				//*** CAPACITY ***//
				//!size_type size() const;
				//!size_type max_size() const;
				//!void resize (size_type n, value_type val = value_type());
				//!size_type capacity() const;
				//!bool empty() const;
				//!void reserve (size_type n);

		private:
				pointer				_array; // Adress of the array - We are using a pointer to allow a dynamic allocation of the memory during runtime of the program
				size_type 			_size; // size of the array
				size_type 			_capacity; //size for the memory
				allocator_type		_alloc;


		/*
		**==========================
		**    DEFINITION
		**==========================
		*/
		

		//***   CONSTRUCTORS - DESTRUCTOR - OPERATOR=   ***//

		template <typename T, typename Alloc>
		vector<T, Alloc>::vector(const allocator_type& alloc)
		{
			this->_size = 0;
			this->_capacity = 0;
			this->_alloc = alloc;
			this->_array = NULL;
		}


	};
}





#endif