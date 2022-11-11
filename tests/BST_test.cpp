/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:16:10 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/11/11 07:57:11 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Binary Search Tree operations in C++

#include <iostream>
#include "../containers/BST.hpp"
#include "../utils/utility.hpp"
using namespace std;

// Driver code
int main() {
  struct node *root = NULL;
  ft::make_pair(1, 2);
  std::less<int>

  ft::Bst tree();
  root = Bst.insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Inorder traversal: ";
  inorder(root);
/*
  cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);
  cout << "Inorder traversal: ";
  inorder(root);*/
}