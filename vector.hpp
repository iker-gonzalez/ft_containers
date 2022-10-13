/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:44:52 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/13 08:22:21 by ikgonzal         ###   ########.fr       */
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
				typedef typename ft::random_access_iterator<value_type> iterator;

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

				// *****TODO:     ITERATORS     ****** //
				

				//*** CAPACITY ***//
				
				size_type size() const;
				size_type max_size() const;
				//!void resize (size_type n, value_type val = value_type());
				size_type capacity() const;
				bool empty() const;
				void reserve (size_type n);

				//***   ELEMENT ACCESS   ***//
				reference operator[] (size_type n);
				const_reference operator[] (size_type n) const;
				reference at (size_type n);
				const_reference at (size_type n) const;
				reference front();
				const_reference front() const;
				reference back();
				const_reference back() const;
				value_type* data();
				const value_type* data() const;

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

		//TODO: template <class InputIterator>
		//TODO: vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

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

		// *****TODO:     ITERATORS     ****** //

		//***   CAPACITY   ***//

		template <typename T, typename Alloc>
		size_type vector<T, Alloc>::size() const
		{
			return (this->_size);
		}

		template <typename T, typename Alloc>
		size_type vector<T, Alloc>::max_size() const
		{
			return (std::numeric_limits<size_type>::max());
		}

		template <typename T, typename Alloc>
		void vector<T, Alloc>::resize(size_type n, value_type val = value_type())
		{
			//TODO: pop_back / push_back to be included here.
		}

		template <typename T, typename Alloc>
		size_type vector<T, Alloc>::capacity() const
		{
			return (this->_capacity);
		}

		template <typename T, typename Alloc>
		bool vector<T, Alloc>::empty() const
		{
			return (this->size() == 0);
		}

		template <typename T, typename Alloc>
		void vector<T, Alloc>::reserve (size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("Trying to reserve more space than max_size => vector::reserve");
			if (n > this->size())
			{
				pointer new_array = _alloc.allocate(n);
				for (int i = 0; i < this->size(); i++) {
					this->_alloc.construct(&new_array[i], this->_array[i]);
					this->_alloc.destroy(&this->array[i]);
				}
				this->_alloc.deallocate(this->_array, this->_capacity);
				//TODO: ?? set_array(n) ?? //
				this->_capacity= n;
			}
		
		}

		//***   ELEMENT ACCESS   ***//
		
		template <typename T, typename Alloc>
		reference vector<T, Alloc>::operator[] (size_type n)
		{
			return (&(this->_array[n]));
		}
		
		template <typename T, typename Alloc>
		const_reference vector<T, Alloc>::operator[] (size_type n) const
		{
			return (&(this->_array[n]));
		}

		template <typename T, typename Alloc>
		reference vector<T, Alloc>::at (size_type n)
		{
			if (n > this->size())
				throw std::out_of_range("Elemnt trying to be accessed is out of range\n");
			return (&(this->_array[n]));

		}
		
		template <typename T, typename Alloc>
		const_reference vector<T, Alloc>::at (size_type n) const
		{
			if (n > this->size())
				throw std::out_of_range("Elemnt trying to be accessed is out of range\n");
			return (&(this->_array[n]));
		}

		template <typename T, typename Alloc>
		reference vector<T, Alloc>::front()
		{
			return (&(this->_array[0]));
		}
		
		template <typename T, typename Alloc>
		const_reference vector<T, Alloc>::front() const
		{
			return (&(this->_array[0]));
		}

		template <typename T, typename Alloc>
		reference vector<T, Alloc>::back()
		{
			return (&(this->_array[this->size() - 1]));
		}

		template <typename T, typename Alloc>		
		const_reference vector<T, Alloc>::back() const
		{
			return (&(this->_array[this->size() - 1]));
		}

		template <typename T, typename Alloc>		
		value_type* vector<T, Alloc>::data()
		{
			return (*(this->_array));
		}

		template <typename T, typename Alloc>		
		const value_type* vector<T, Alloc>::data() const
		{
			return (*(this->_array));
		}

	};
}





#endif