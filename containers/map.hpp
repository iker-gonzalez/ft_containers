/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:19:26 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/11/17 09:09:45 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../utils/utility.hpp"
#include "BST.hpp"
#include "../iterators/map_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

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
			typedef Bst<ft::pair<Key, T>, Compare, Allocator>	Bst;
		
		public:
				//********** ***********//
				//**** MEMBER TYPES ****//
				//********** ***********//

				typedef Key													key_type;
				typedef T													mapped_type;
				typedef typename ft::pair<const Key, T>						value_type;
				typedef typename std::size_t								size_type;
				typedef typename std::ptrdiff_t								difference_type;
				typedef Compare												key_compare;
				typedef Allocator											allocator_type;
				typedef value_type&											reference;
				typedef typename Allocator::pointer							pointer;
				typedef typename Allocator::const_pointer					const_pointer;
				typedef ft::map_iterator<Bst*, value_type>					iterator;
				typedef ft::map_iterator<const Bst*, const value_type>		const_iterator;
				typedef ft::reverse_iterator<iterator>						reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

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
				
				Bst					_tree;
				Bst*				_root;
				Bst*				_end;
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

				iterator begin()
				{
					//TODO: If the container is empty, the returned iterator value shall not be dereferenced.
					return (iterator(this->_root));
				}
				
				const_iterator begin() const
				{
					//TODO: If the container is empty, the returned iterator value shall not be dereferenced.
					return (const_iterator(this->_root));
				}
				iterator end()
				{
					//TODO: If the container is empty, the returned iterator value shall not be dereferenced.
					return (iterator(this->_end));
				}
					
				const_iterator end() const
				{
					//TODO: If the container is empty, the returned iterator value shall not be dereferenced.
					return (const_iterator(this->_end));
				}

				reverse_iterator rbegin()
				{
					return (reverse_iterator(this->end()));
				}
				
				const_reverse_iterator rbegin() const
				{
					return (const_reverse_iterator(this->end()));
				}

				reverse_iterator rend()
				{
					return (reverse_iterator(this->begin()));
				}
				
				const_reverse_iterator rend() const
				{
					return (const_reverse_iterator(this->begin()));
				}

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
				
				//!Modifier INSERT needs to be implemented to attempt this 3 functions
				//TODO: mapped_type& operator[] (const key_type& k)
				//TODO: mapped_type& at (const key_type& k);
				//TODO: const mapped_type& at (const key_type& k) const;

				//************* ************//
				//******* MODIFIERS ********//
				//************* ************//

				//TODO: insert
				//TODO: erase

				void swap (map& x)
				{
					Bst*				tmp_root;
					Bst*				tmp_end;
					size_type			tmp_size;
					key_compare			tmp_comp;
					allocator_type		tmp_alloc;

					tmp_root = x._root;
					tmp_end = x._end;
					tmp_size = x._size;
					tmp_comp = x._comp;
					tmp_alloc = x._alloc;
					//-----------------//
					x._root = this->_root;
					x._end = this->_end;
					x._size = this->_size;
					x._comp = this->_comp;
					x._alloc = this->_alloc;
					//-------------------//
					this->_root = tmp_root;
					this->_end = tmp_end;
					this->_size = tmp_size;
					this->_comp = tmp_comp;
					this->_alloc = tmp_alloc;
				}

				void clear()
				{
					if (this->_size > 0)
						this->_tree.clean(&(this->_root));
					this->_size = 0;
					this->_root = 0;
					this->_end = 0;
				}

				//************* ************//
				//******* OBSERVERS ********//
				//************* ************//

				key_compare key_comp() const
				{
					return (this->_comp);
				}

				value_compare value_comp() const
				{
					return (value_compare(this->_comp));
				}

				//************* ************//
				//******* OPERATIONS *******//
				//************* ************//


	};

}

#endif