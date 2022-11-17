/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 08:31:08 by marvin            #+#    #+#             */
/*   Updated: 2022/11/17 08:59:11 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP

	//?https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
	//?https://www.programiz.com/dsa/binary-search-tree
	//?https://www.programiz.com/dsa/balanced-binary-tree
	//?https://www.programiz.com/dsa/avl-tree

	//*** binary search tree definition***//
	/*
		A binary Search Tree is a node-based binary tree data structure which has the following properties:  

		1) The left subtree of a node contains only nodes with keys lesser than the node’s key.
		2) The right subtree of a node contains only nodes with keys greater than the node’s key.
		3) The left and right subtree each must also be a binary search tree. 
		4) There must be no duplicate nodes.
	*/

	//*** balanced binary search tree***//
	/*
		1) difference between the left and the right subtree for any node is not more than one
		2) the left subtree is balanced
		3) the right subtree is balanced
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
	
	template <typename key_value_pair, typename Compare, typename Allocator> 
	class Bst {
			
		public:
				//********** ***********//
				//**** MEMBER TYPES ****//
				//********** ***********//

				typedef key_value_pair							value_type;
				typedef Compare									key_compare;
				typedef Allocator								allocator_type;
				typedef typename std::size_t					size_type;

				//*********** ********** ****//
				//**** MEMBER ATTRIBUTES ****//
				//********** *********** ****//
				
				value_type										data;
				Bst*											left;
				Bst*											right;
				Bst*											parent;
				//int											balance;

		private:

				key_compare										_comp;
				allocator_type									_alloc;

		public:
		
				//*********** ********** ****//
				//**** MEMBER FUNCTIONS *****//
				//********** *********** ****//

				//*constructor
				
				explicit Bst(value_type d = value_type, const key_compare& comp = key_compare,
						const allocator_type& alloc = allocator_type): data(p)
				{
					this->left = 0;
					this->right = 0;
					this->parent = 0;
					//this->balance = 0;
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
					//this->balance = other.balance;
					this->data = other->data;
					return(*this);
				}

				//*destructor
				~Bst () {};

				//*search
				Bst* search(Bst* root, value_type data)
				{
					if (!root || root->data.first = data.first)
						return (root);
					if (this->_comp(root->data.first, data.first))
						return (search(root->right, data));
					return (search(root->left, data));
				}

				// Insert new node
				Bst* insertNode(Bst* node, value_type data)
				{
					//! Return a new node if the current tree position is empty
					if (!node)
					{
						node = this->_alloc.allocate(1);
						this->_alloc.construct(node, Bst(data));
						return (node);
					}
				 	// Traverse to the left if data key is smaller than current node's key
					if (this->_comp(data.first, node->data.first))
					{
						node->left = insertNode(node->left, data);
						node->left->parent = node;
					}
					// Traverse to the right if data key is bigger than current node's key
					else if (this->_comp(node->data.first, data.first))
					{
						node->right = insertNode(node->right, data);
						node->right->parent = node;
					}
					return (node);
				}

				// Deleting a node
				Bst *deleteNode(Bst *node, value_type data) 
				{
					// Return if the tree is empty
					if (!node)
						return (node);
					//! find the node to be deleted //
					// Traverse to the left if data key is smaller than current node's key
					if (this->_comp(data.first, node->data.first))
						node->left = deleteNode(node->data, data);
					// Traverse to the right if data key is bigger than current node's key
					else if (this->_comp(node->data.first, data.first))
						node->right = deleteNode(node->right, data);
					else 
					{
						//! once the node has been found //
						// If the node is with //! only one child or no child //
						/*
							1) Replace that node with its child node.
							2) Remove the child node from its original position.
						*/
					
						if (node->left == NULL) 
						{
							Bst *temp = node->right;
							if (temp)
								temp->parent = node->parent;
							this->_alloc.destroy(node);
							this->_alloc.deallocate(node, 1);
							return (temp);
						} 
						else if (node->right == NULL) 
						{
							Bst *temp = root->left;
							if (temp)
								temp->parent = node->parent;
							this->_alloc.destroy(node);
							this->_alloc.deallocate(node, 1);
							return (temp);
						}

						//TODO: missing parent logic implementation
						// If the node has //! two children //
						
						// 1) Get the inorder successor of that node.
						Bst *temp = get_inorder_successor(root->right);

						// 2) Replace the node with the inorder successor.
						node->data = temp->data;

						// 3) Remove the inorder successor from its original position.
						this->_alloc.destroy(temp);
						this->_alloc.deallocate(temp, 1);
					}
					return (node);
				}

				// Find the inorder successor
				Bst *get_inorder_successor(Bst *node) 
				{
					Bst *current = node;
					// Find the leftmost leaf
					while (current && current->left != NULL)
						current = current->left;
					return current;
				}

				void		clean(Bst** root)
				{
					if (!(*root))
						return ;
					if ((*root)->left)
						clean(&((*root)->left));
					if ((*root)->right)
						clean(&((*root)->right));
					(*root)->left = 0;
					(*root)->right = 0;
					this->_alloc.destroy(*root);
					this->_alloc.deallocate(*root, 1);
					*root = 0;
					return ;
				}

				/** Allocator **/
				allocator_type	get_allocator(void) const
				{
					return (this->_alloc);
				}

				size_type	max_size(void) const
				{
					return (this->_alloc.max_size());
				}

				/*// Inorder Traversal
				void inorder(Bst *root) 
				{
					if (root != NULL) 
					{
						// Traverse left
						inorder(root->left);

						// Traverse root
						cout << root->data.first << ":" << root->data.second -> " -> ";

						// Traverse right
						inorder(root->right);
					}
				}*/

				


	};
}

#endif