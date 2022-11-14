/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:24:27 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/11/14 09:09:09 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR
#define MAP_ITERATOR

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

				node_ptr															_root;
				node_ptr															_begin;
				node_ptr															_end;

		public:
		
				

	};
}

#endif