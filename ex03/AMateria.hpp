/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:49:06 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/21 23:20:39 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{

public:

	AMateria( std::string const & type );

	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria* clone( void ) const = 0;

	virtual void use(ICharacter& target) = 0;

protected:

	std::string _type;

};



#endif