/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:34:56 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 21:41:34 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void f()
{
	system("leaks exec");
}

int main()
{
	// atexit(f);
	
	Animal *animal = new Dog();
	// Animal *animal = new Dog();

	delete animal;

	return 0;
}

