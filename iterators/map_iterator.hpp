/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:24:27 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/11/12 13:42:21 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR
#define MAP_ITERATOR

namespace ft {
	/*
	*   @param Key      Type of container's key elements.
	*   @param T        Type of container's mapped elements.
	*   @param Compare  The predicate used to sort the binary tree.
	*   @param Node     The structure used as nodes in the binary tree.
	*   @param B        Boolean to indicate if it's an iterator / a const iterator.
	*/

	template <class Key, class T, class Compare, typename Node, bool B>
	class map_iterator
	{
		public:

				typedef typename ft::bidirectional_iterator_tag						iterator_category;
				typedef Key															key_type;
				typedef T															mapped_type;
				typedef ft::pair<const key_type, mapped_type>						value_type;
				typedef Compare														key_compare;
				typedef typename std::ptrdiff_t										difference_type;
				typedef typename std::size_t										size_type;
				typedef typename value_type*										pointer;
				typedef typename value_type&										reference;
				typedef Node*														node_ptr;
	};
}

#endif