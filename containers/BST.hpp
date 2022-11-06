/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 08:31:08 by marvin            #+#    #+#             */
/*   Updated: 2022/11/06 08:31:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

//?https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

//*** binary search tree definition***//
/*
	A binary Search Tree is a node-based binary tree data structure which has the following properties:  

	1) The left subtree of a node contains only nodes with keys lesser than the node’s key.
	2) The right subtree of a node contains only nodes with keys greater than the node’s key.
	3) The left and right subtree each must also be a binary search tree. 
	4) There must be no duplicate nodes.
*/