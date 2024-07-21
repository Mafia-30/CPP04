/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 00:12:19 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/21 05:48:06 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {

public :

	Character( void );
	Character( std::string name );
	Character( const Character& ref );

	~Character();

	Character&	operator=( const Character& rhs );

	std::string const & getName() const;

	void	equip( AMateria* m );

	void	unequip( int idx );

	void	use( int idx, ICharacter& target );

private :

	AMateria*	_inventory[4];
	std::string	_name;
	AMateria*	_garbage_materias[4];
};

#endif