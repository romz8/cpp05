/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:08:05 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/07 17:42:39 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/******************************* Canonical *********************************/
Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern& src)
{
	(void) src;
}
Intern& Intern::operator=(const Intern& src)
{
	if (this != &src)
		(void) src;
	return (*this);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	
}
