/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_balance.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:47:13 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/11/12 09:50:23 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checking if a binary tree is height balanced in C++

#include <iostream>
using namespace std;

#define bool int

class node {
	public:
	int item;
	node *left;
	node *right;
	};

// Create anew node
node *newNode(int item) {
	node *Node = new node();
	Node->item = item;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

// Check height balance
bool checkHeightBalance(node *root, int *height) {
	// Check for emptiness
	int leftHeight = 0, rightHeight = 0;

	int l = 0, r = 0;

	if (root == NULL) {
		*height = 0;
		return 1;
	}

	l = checkHeightBalance(root->left, &leftHeight);
	r = checkHeightBalance(root->right, &rightHeight);

	*height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

	if (std::abs(leftHeight - rightHeight >= 2))
		return 0;

	else
		return l && r;
}

int main() {
	int height = 0;

	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	if (checkHeightBalance(root, &height))
		cout << "The tree is balanced";
	else
		cout << "The tree is not balanced";
}