/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:24:27 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/11/18 08:09:36 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR
#define MAP_ITERATOR

#include "BST.hpp"
#include "map.hpp"

namespace ft {
	/*
	*   @param Node                 A pointer to a node in the BST.
	*   @param key_value_pair       
	*/

	template <typename Node, typename key_value_pair>
	class map_iterator
	{
		public:

				typedef typename ft::bidirectional_iterator_tag						iterator_category;
				typedef key_value_pair												value_type;
				typedef typename value_type*										pointer;
				typedef typename value_type&										reference;
				typedef typename std::ptrdiff_t										difference_type;
				typedef Node*														node_ptr;

		private:

				node_ptr															_node;
				node_ptr															_begin;
				node_ptr															_end;

		public:
		
				//********************** **********************//
				//*** CONSTRUCTORS - DESTRUCTOR - OPERATOR= ***//
				//********************** **********************//

				/** Constructor **/
				template < typename Node, typename key_value_pair >
				MapIterator(const MapIterator<Node, key_value_pair>& other)
				: _node(other.node()), _beg(other.begin()), _end(other.end())
				{
					return ;
				}

				/** Destructor **/
				~map_iterator(void) {}

				/** Assignation Operator **/
				map_iterator&	operator=(const map_iterator& other)
				{
					this->_node = other.node();
					this->_beg = other.begin();
					this->_end = other.end();
					return (*this);
				}

				//****************** ******************//
				//*************** GETTERS *************//
				//****************** ******************//

				node_ptr node(void) const
				{
					return (this->_node);
				}

				node_ptr begin(void) const
				{
					return (this->_begin);
				}

				node_ptr end(void) const
				{
					return (this->_end);
				}

				//****************** ******************//
				//******** OPERATOR OVERLOADS *********//
				//****************** ******************//

				reference operator*(void) const
				{
					return (this->_node->_data);
				}

				pointer operator->(void) const
				{
					return (&(this->_node->_data));
				}

				map_iterator& operator++(void)
				{
					nodePtr	output;

					output = this->_node;
					if (output && output->right)
					{
						output = output->right;
						while (output->left)
							output = output->left;
					}
					else if (output != this->_end)
					{
						while (output->parent && output != output->parent->left)
							output = output->parent;
						output = output->parent;
					}
					this->_node = output;
					return (*this);
				}

				map_iterator operator++(void)
				{
					map_iterator output(*this);

					++(*this);
					return (output);
				}

				map_iterator& operator--(void)
				{
					nodePtr	output;

					output = this->_node;
					if (output && output->left)
					{
						output = output->left;
						while (output->right)
							output = output->right;
					}
					else if (output != this->_begin)
					{
						while (output->parent && output != output->parent->right)
							output = output->parent;
						output = output->parent;
					}
					this->_node = output;
					return (*this);
				}

				map_iterator operator--(void)
				{
					map_iterator output(*this);

					--(*this);
					return (output);
				}
	};

	//****************** ******************//
	//******** RELATIONAL OPERATORS *******//
	//****************** ******************//

	/** Relational Operators **/
	template < typename Node, typename key_value_pair >
	bool	operator==(const map_iterator<Node, key_value_pair>& lhs, const map_iterator<Node, key_value_pair> rhs)
	{
		return (lhs.node() == rhs.node());
	}

	template < typename Node, typename key_value_pair, >
	bool	operator!=(const map_iterator<Node, key_value_pair>& lhs, const map_iterator<Node, key_value_pair> rhs)
	{
		return (lhs.node() != rhs.node());
	}

}

#endif