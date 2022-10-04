/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:44:52 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/04 09:13:33 by ikgonzal         ###   ########.fr       */
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

				//default empty constructor
				explicit vector (const allocator_type& alloc = allocator_type());
				//fill constructor - Constructs a container with n elements. Each element is a copy of val.
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
				//!template <class InputIterator>
				//!vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
				vector (const vector& x);
				~vector ();
				vector& operator= (const vector& x);

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
		
		template <typename T, typename Alloc>
		vector<T, Alloc>::vector (size_type n, const value_type& val, const allocator_type& alloc)
		{
			this->_size = n;
			this->_capacity = n;
			this->_alloc = alloc;
			this->_array = _alloc.allocate(this->_capacity);
			for (size_type i = 0; i < n; i++)
				this->_array[i] = val;
		}

		template <typename T, typename Alloc>
		vector<T, Alloc>::vector (const vector& x)
		{
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_alloc = x._alloc;
			this->_array = _alloc.allocate(this->_capacity);
			for(size_t i = 0; i < this->_size; i++)
				_alloc.construct(&_array[i], x_array[i]);
		}

		//!template <class InputIterator>
		//!vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		template <typename T, typename Alloc>
		vector<T, Alloc>::~vector()
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_array[i]);
			this->_alloc.deallocate(this->_array, this->_capacity);
		}

		template <typename T, typename Alloc>
		vector<T, Alloc>::vector& operator= (const vector& x)
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_array[i]);
			this->_size = x._size;
			this->_capacity = x._capacity;
			for (size_type i = 0; i < n; i++)
				this->_array[i] = x.val;
			return (*this);
		}


	};
}





#endif