/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_base.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:24:27 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/29 09:03:36 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>

namespace ft {
		template <class T, class Container = std::vector<T> >
		class Stack {

		protected:
				//member object
				Container																			_container;

		public:
				//member types
				typedef Container																	container_type;
				typedef typename Container::value_type												value_type;
				typedef typename Container::size_type												size_type;
	
				//member functions
				explicit stack (const container_type& ctnr = container_type())						{ _container = cont; };
				Stack(Stack const &other)															{ _container = other._container; };
				~Stack()																			{ };
				Stack& operator=(const Stack &other)												{ if (this == &other) return *this;
																									_container = other._container;
																									return *this; };
				bool empty() const																	{ return _container.empty(); };
				size_type size() const																{ return _container.size(); }

	};
}




#endif