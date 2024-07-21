/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 00:23:52 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/21 05:56:23 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character( void )
{
	this->_name = "Default character name";

	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_garbage_materias[i] = NULL;
	}

	std::cout << "Character default constructor has been called!" << std::endl;
}

Character::Character( std::string name )
{
	this->_name = name;

	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_garbage_materias[i] = NULL;
	}

	std::cout << "Character parametrized constructor has been called!" << std::endl;
}

Character::Character( const Character& ref )
{
	this->_name = ref._name;

	for (int i = 0; i < 4; i++)
	{
		if ((*(ref._inventory[i])).getType() == "ice")
			this->_inventory[i] = new Ice((const Ice&) (*(ref._inventory[i])));
		else if ((*(ref._inventory[i])).getType() == "cure")
			this->_inventory[i] = new Cure((const Cure&) (*(ref._inventory[i])));
		else
			this->_inventory[i] = NULL;

		//
		this->_garbage_materias[i] = NULL;
	}

	std::cout << "Character copy constructor has been called!" << std::endl;
}

Character::~Character()
{
	std::cout << "Charachter destructor has been called!" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
		if (this->_garbage_materias[i])
			delete (this->_garbage_materias[i]);
	}
}

Character&	Character::operator=( const Character& rhs )
{
	std::cout << "Character copy assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	this->_name = rhs._name;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);

		if ((*(rhs._inventory[i])).getType() == "ice")
			this->_inventory[i] = new Ice((const Ice&) (*(rhs._inventory[i])));
		else if ((*(rhs._inventory[i])).getType() == "cure")
			this->_inventory[i] = new Cure((const Cure&) (*(rhs._inventory[i])));
		else
			this->_inventory[i] = NULL;
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip( AMateria* m ) // NULL as parameter
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " has equiped a Materia successfully!" << std::endl;
			break ;
		}
	}

	if (i == 4)
	{
		std::cout << this->_name << "'s inventory is full! Try unequiping an item." << std::endl;
		delete (m);
	}

	// cleaning the garbage Materias
	for (int i = 0; i < 4; i++)
	{
		if (this->_garbage_materias[i])
		{
			delete (this->_garbage_materias[i]);
			this->_garbage_materias[i] = NULL;
		}
	}
}

void	Character::unequip( int idx )
{
	if ((idx < 0) || (idx > 3) || !this->_inventory[idx])
	{
		std::cout << "No Materia found in this index!" << std::endl;
		return ;
	}

	for (int i = 0; i < 4; i++)
	{
		if (!this->_garbage_materias[i])
		{
			this->_garbage_materias[i] = this->_inventory[idx];
			break ;
		}
	}

	this->_inventory[idx] = NULL;
}

void	Character::use( int idx, ICharacter& target )
{
	if ((idx < 0) || (idx > 3) || !this->_inventory[idx])
	{
		std::cout << "No Materia found in this index!" << std::endl;
		return ;
	}

	(*(this->_inventory[idx])).use(target);
}