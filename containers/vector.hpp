/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:44:52 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/27 08:19:48 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BASE_HPP
#define VECTOR_BASE_HPP

#include <memory>

#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft {
	template <class T, class Alloc = std::allocator <T> > 
	class vector {
		
		public:
		/*
		**==========================
		**    DECLARATION
		**==========================
		*/
				//********** ***********//
				//**** MEMBER TYPES ****//
				//********** ***********//
				
				typedef T 															value_type;
				typedef Alloc														allocator_type;
				typedef typename allocator_type::reference							reference;
				typedef typename allocator_type::const_reference					const_reference;
				typedef typename allocator_type::pointer							pointer;
				typedef typename allocator_type::const_pointer						const_pointer;
				typedef typename ft::random_access_iterator<value_type>				iterator;
				typedef typename ft::random_access_iterator<const value_type>		const_iterator;
				typedef typename ft::reverse_iterator<value_type>					reverse_iterator;
				typedef typename ft::reverse_iterator<const value_type>				const_reverse_iterator;
				typedef typename std::ptrdiff_t										difference_type;
				typedef typename std::size_t										size_type;


				//********************** **********************//
				//*** CONSTRUCTORS - DESTRUCTOR - OPERATOR= ***//
				//********************** **********************//

				//default empty constructor
				explicit vector (const allocator_type& alloc = allocator_type());
				//fill constructor - Constructs a container with n elements. Each element is a copy of val.
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
				
				//TODO:template <class InputIterator>  vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
				
				vector (const vector& x);
				~vector ();
				vector& operator= (const vector& x);
				
				//****************** ******************//
				//************** CAPACITY *************//
				//****************** ******************//
				
				size_type size() const;
				size_type max_size() const;
				void resize (size_type n, value_type val = value_type());
				size_type capacity() const;
				bool empty() const;
				void reserve (size_type n);

				//****************** ******************//
				//*********** ELEMENT ACCESS **********//
				//****************** ******************//

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

				//****************** ******************//
				//************** MODIFIERS ************//
				//****************** ******************//

				void assign (size_type n, const value_type& val);
				//TODO: template <class InputIterator>  void assign (InputIterator first, InputIterator last);
				void push_back (const value_type& val);
				void pop_back();
				iterator insert( const_iterator pos, const T& value );
				void insert (iterator position, size_type n, const value_type& val);
				//TODO:template <class InputIterator>  void insert (iterator position, InputIterator first, InputIterator last);
				iterator erase (iterator position);
				iterator erase (iterator first, iterator last);
				void swap (vector& x);
				void clear();

				//****************** ******************//
				//************** ALLOCATOR ************//
				//****************** ******************//

				allocator_type get_allocator() const;

		private:
				pointer				_ptr; // Adress of the array - We are using a pointer to allow a dynamic allocation of the memory during runtime of the program
				size_type 			_size; // size of the array
				size_type 			_capacity; //size for the memory
				allocator_type		_alloc;


		/*
		**==========================
		**    DEFINITION
		**==========================
		*/
		
		//********************** **********************//
		//*** CONSTRUCTORS - DESTRUCTOR - OPERATOR= ***//
		//********************** **********************//

		//Default constructor. Constructs an empty container with a default-constructed allocator.
		vector(void): _size(0), _capacity(0), _ptr(NULL) { };

		//Constructs an empty container with the given allocator alloc.
		explicit vector(const allocator_type& alloc)
		{
			this->_size = 0;
			this->_capacity = 0;
			this->_alloc = alloc;
			this->_ptr = NULL;
		}
		
		//Constructs the container with count copies of elements with value value.
		explicit vector (size_type n, const value_type& val, const allocator_type& alloc)
		{
			this->_size = n;
			this->_capacity = n;
			this->_alloc = alloc;
			this->_ptr = _alloc.allocate(this->_capacity);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_ptr[i], val);
		}

		//Copy constructor. Constructs the container with the copy of the contents of x.
		vector (const vector& x)
		{
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_alloc = x._alloc;
			this->_ptr = _alloc.allocate(this->_capacity);
			for(size_t i = 0; i < this->_size; i++)
				_alloc.construct(&_ptr[i], x._ptr[i]);
		}

		//TODO: template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		~vector(void)
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_ptr[i]);
			this->_alloc.deallocate(this->_ptr, this->_capacity);
		}

		vector& operator= (const vector& x)
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_ptr[i]);
			this->_size = x._size;
			this->_capacity = x._capacity;
			for (size_type i = 0; i < n; i++)
				this->_ptr[i] = x.val;
			return (*this);
		}

		//****************** ******************//
		//************** ITERATORS ************//
		//****************** ******************//

		iterator begin (void)
		{
			return iterator(_ptr);
		}

		iterator begin (void) const
		{
			return const_iterator(_ptr);
		}

		iterator end (void)
		{
			return iterator(_ptr + _size);
		}

		iterator end (void) const
		{
			return const_iterator(_ptr + _size);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			const_reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		
		//****************** ******************//
		//************** CAPACITY *************//
		//****************** ******************//

		size_type size() const
		{
			return (this->_size);
		}

		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max());
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n < this->_size)
			{
				for (i = n; i < _size; i++)
					pop_back();
			}
			else
			{
				if (n > this->_capacity)
					_alloc.reserve(n * 2);
				for (i = _size; i < n; i++)
					_alloc.push_back(val);
			}
		}

		size_type capacity() const
		{
			return (this->_capacity);
		}

		bool empty() const
		{
			return (this->size() == 0);
		}

		void reserve (size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("Trying to reserve more space than max_size => vector::reserve");
			if (n > this->size())
			{
				pointer new_ptr = _alloc.allocate(n);
				for (int i = 0; i < this->size(); i++)
					this->_alloc.construct(&new_ptr[i], this->_ptr[i]);
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_ptr = new_ptr;
				this->_capacity= n;
			}
		}

		//****************** ******************//
		//*********** ELEMENT ACCESS **********//
		//****************** ******************//
		
		reference operator[] (size_type n)
		{
			return (&(this->_ptr[n]));
		}
		
		const_reference operator[] (size_type n) const
		{
			return (&(this->_ptr[n]));
		}

		reference at (size_type n)
		{
			if (n > this->size())
				throw std::out_of_range("Element trying to be accessed is out of range\n");
			return (&(this->_ptr[n]));
		}
		
		const_reference at (size_type n) const
		{
			if (n > this->size())
				throw std::out_of_range("Element trying to be accessed is out of range\n");
			return (&(this->_ptr[n]));
		}

		reference front()
		{
			return (&(this->_ptr[0]));
		}
		
		const_reference front() const
		{
			return (&(this->_ptr[0]));
		}

		reference back()
		{
			return (&(this->_ptr[this->size() - 1]));
		}

		const_reference back() const
		{
			return (&(this->_ptr[this->size() - 1]));
		}

		value_type* data()
		{
			return (*(this->_ptr));
		}

		const value_type* data() const
		{
			return (*(this->_ptr));
		}

		//****************** ******************//
		//************** MODIFIERS ************//
		//****************** ******************//

		//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		void assign (size_type n, const value_type& val)
		{
			for (int i = 0; i < _size; i++)
				_alloc.destroy(_ptr[i]);
			if (n > _capacity) 
			{
				_alloc.deallocate(_ptr, _capacity);
				_alloc.allocate(_ptr, n);
				this->_capacity = n;
				this->_size = n;
			}
			for (i = 0; i < _size; i++)
				_alloc.construct(_ptr[i], val);
		}

		//TODO: template <class InputIterator>  void assign (InputIterator first, InputIterator last);

		void push_back (const value_type& val)
		{
			if ((_size + 1) > _capacity) 
			{
				if (!this->_size)
					reserve(1);
				else
					this->reserve(this->_capacity * 2);
			}
			_alloc.construct(_ptr[_size], val);
			this->_size += 1;
		}

		void pop_back() 
		{
			_alloc.destroy(this->_ptr[_size - 1]);
			this->_size--;
		}

		//inserts one value before pos.
		iterator insert(const_iterator pos, const T& value)
		{
			size_type position = pos - _ptr;
			if (_size == _capacity)
			{
				if (!this->_size)
					reserve(1);
				else
				_alloc.reserve(this->_capacity * 2);
			}
			for (size_type i = _size; i > position; i--)
				_ptr[i] = _ptr[i - 1];
			this->_alloc.construct(this->_ptr[position], value);
			this->_size++;
			return (iterator(_ptr + position));
		}

		//inserts n copies of val before position
		void insert (iterator position, size_type n, const value_type& val);
		{
			size_type position = pos - _ptr;
			if (_size + n > _capacity)
			{
				if (!this->_size)
					reserve(1);
				else
				_alloc.reserve(this->_capacity * 2);
			}
			for (size_type i = _size; i > position; i--)
				_ptr[i + n - 1] = _ptr[i - 1];
			for (i = 0; i < n; i++)
				this->_alloc.construct(this->_ptr[i], val);
			this->_size += n;
		}

		//TODO:template <class InputIterator>  void insert (iterator position, InputIterator first, InputIterator last);

		//removes the value from position.
		iterator erase (iterator position)
		{
			size_type position = pos - _ptr;
			for (size_type i = _size; i > position; i--)
				_ptr[i] = _ptr[i + 1];
			this->_alloc.destroy(this->_ptr[position], value);
			this->_size--;
			return (iterator(_ptr + position));
		}

		//removes elements from the range[first, last]
		iterator erase (iterator first, iterator last)
		{
			while (first != last)
			{
				erase (first);
				last--;
			}
			return (first);
		}

		//Exchanges the content of the container by the content of x.
		void swap (vector& x)
		{
			size_type capacity_x;
			size_type size_x;
			pointer pointer_x;

			capacity_x = x._capacity;
			size_x = x._size;
			pointer_x = x._ptr;

			x._capacity = this->_capacity;
			x._size = this->_size;
			x._ptr = this->_ptr;
			
			this->_capacity = capacity_x;
			this->_size = size_x;
			this->_ptr = pointer_x;
		}

		void clear()
		{
			for (int i = 0; i < _size; i++)
				_alloc.destroy(_ptr[i]);
			this->_size = 0;
		}

		//****************** ******************//
		//************** ALLOCATOR ************//
		//****************** ******************//

		allocator_type get_allocator() const
		{
			return (_alloc);
		}

	};
		
	/*
	**==========================
	**    NON MEMBER FUNCTIONS
	**==========================
	*/

	//****************** ******************//
	//******** RELATIONAL OPERATORS *******//
	//****************** ******************//

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (int i = 0; i < lhs.size(); i++) {
				if (lhs._ptr[i] != rhs._ptr[i])
					return false;
			}
			return true;
		}
		return false;
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (int i = 0; i < lhs.size(); i++) {
				if (lhs._ptr[i] != rhs._ptr[i])
					return true;
			}
			return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (int i = 0; i < lhs.size(); i++) {
				if (lhs._ptr[i] < rhs._ptr[i])
					return true;
			}
			return false;
		}
		if (lhs.size() < rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (int i = 0; i < lhs.size(); i++) {
				if (lhs._ptr[i] <= rhs._ptr[i])
					return true;
			}
			return false;
		}
		if (lhs.size() <= rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (int i = 0; i < lhs.size(); i++) {
				if (lhs._ptr[i] > rhs._ptr[i])
					return true;
			}
			return false;
		}
		if (lhs.size() > rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (int i = 0; i < lhs.size(); i++) {
				if (lhs._ptr[i] >= rhs._ptr[i])
					return true;
			}
			return false;
		}
		if (lhs.size() >= rhs.size())
			return true;
		return false;
	}
}

#endif