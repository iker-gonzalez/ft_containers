/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 08:31:08 by marvin            #+#    #+#             */
/*   Updated: 2022/11/10 09:11:04 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP

	//?https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
	//?https://www.programiz.com/dsa/binary-search-tree

	//*** binary search tree definition***//
	/*
		A binary Search Tree is a node-based binary tree data structure which has the following properties:  

		1) The left subtree of a node contains only nodes with keys lesser than the node’s key.
		2) The right subtree of a node contains only nodes with keys greater than the node’s key.
		3) The left and right subtree each must also be a binary search tree. 
		4) There must be no duplicate nodes.
	*/

	/*
	*   Key      Type of keys mapped to elements.
	*   T        Type of elements mapped to keys.
	*   Compare  Comparison object used to sort the binary tree.
	*   Alloc    Object used to manage BST storage.
	*/

#include <iostream>
#include "utility.hpp"

namespace ft {
	
	template<class Key, class T, class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key, T>>
	> class Bst {
			
		public:
				//********** ***********//
				//**** MEMBER TYPES ****//
				//********** ***********//

				typedef Key										key_type;
				typedef T										mapped_type;
				typedef ft::pair<const key_type, mapped_type>	value_type;
				typedef Compare									key_compare;
				typedef Allocator								allocator_type;
				typedef typename std::size_t					size_type;

				//*********** ********** ****//
				//**** MEMBER ATTRIBUTES ****//
				//********** *********** ****//
				
				value_type										pair;
				Bst*											left;
				Bst*											right;
				Bst*											parent;
				int												balance;

		private:

				key_compare										_comp;
				allocator_type									_alloc;

		public:
		
				//*********** ********** ****//
				//**** MEMBER FUNCTIONS *****//
				//********** *********** ****//

				//*constructor
				explicit Bst(value_type p = value_type, const key_compare& comp = key_compare,
						const allocator_type& alloc = allocator_type): pair(p)
				{
					this->left = 0;
					this->right = 0;
					this->parent = 0;
					this->balance = 0;
					this->_comp = comp;
					this->_alloc = alloc;
					return ;
				}

				//*assignment operator
				Bst& operator=(const Bst other)
				{
					this->left = other.left;
					this->right = other.right;
					this->parent = other.parent;
					this->balance = other.balance;
					this->pair = other->pair;
					return(*this);
				}

				//*destructor
				~Bst () {};

				//*search
				Bst* search(Bst *root, value_type pair)
				{
					if (!root || root->pair.first = pair.first)
						return (root);
					if (this->_comp(root->pair.first, pair.first))
						return (search(root->right, pair));
					return (search(root->left, pair));
				}
				
	};
}

#endif