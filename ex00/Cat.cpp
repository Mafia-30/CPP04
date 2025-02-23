/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:30:31 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 11:56:40 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat's default constructor has been called!" << std::endl;
}

Cat::Cat( const Cat& ref ) : Animal(ref)
{
	this->type = ref.type;

	std::cout << "Cat's copy constructor has been called!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat's destructor has been called!" << std::endl;
}

Cat&	Cat::operator=( const Cat& rhs )
{
	std::cout << "Cat's copy assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	this->type = rhs.type;

	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow!" << std::endl;
}