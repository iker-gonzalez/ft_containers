/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:19:26 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/11/12 13:32:49 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../utils/utility.hpp"
#include "BST.hpp"

	/*
	*   Key      Type of keys mapped to elements.
	*   T        Type of elements mapped to keys.
	*   Compare  Comparison object used to sort the binary tree.
	*   Alloc    Object used to manage map storage.
	*/

namespace ft {
	template<class Key, class T, class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key, T>>
	> class map {

		private:
		
			/** Member Type **/
			typedef Bst<ft::pair<Key, T>, Compare, Allocator>	BST;
		
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
				//!iterator
				//!const_iterator
				//!reverse_iterator
				//!const_reverse_iterator

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

				//************ ************//
				//*** MEMBER ATTRIBUTES ***//
				//************ ************//
				
				BST					_tree;
				BST*				_root;
				BST*				_end;
				size_type			_size;
				key_compare			_comp;
				allocator_type		_alloc;

				//************ ************//
				//*** MEMBER FUNCTIONS ****//
				//************ ************//

				//********************** **********************//
				//*** CONSTRUCTORS - DESTRUCTOR - OPERATOR= ***//
				//********************** **********************//

				//default empty constructor
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				{
					this->_root = 0;
					this->_end = 0;
					//creates an empty node (root) with no values
					this->_end = this->_Tree.insert(this->_root, value_type());
					this->_size = 0;
					this->_comp = comp;
					this->_alloc = alloc;
					return ;
				}

				//TODO: template <class InputIterator>map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())

				//TODO: map (const map& x);

				//destructor
				~map(void)
				{
					this->_tree.clean(&(this->_root));
				}

				//TODO: map& operator= (const map& x);

				//************ ************//
				//******* ITERATORS *******//
				//************ ************//

				//TODO: iterator functions

				//************ ************//
				//******* CAPACITY ********//
				//************ ************//

				bool empty() const
				{
					return (this->_size == 0);
				}

				size_type size() const
				{
					return (this->_size);
				}

				//Returns the maximum number of elements that the map container can hold.
				size_type max_size() const
				{
					return (this->_tree.max_size());
				}

				//*************** ***************//
				//******* ELEMENT ACCESS ********//
				//*************** ***************//

				//TODO: mapped_type& operator[] (const key_type& k)
				//TODO: mapped_type& at (const key_type& k);
				//TODO: const mapped_type& at (const key_type& k) const;

				//************* ************//
				//******* MODIFIERS ********//
				//************* ************//

				



	};

}

#endif