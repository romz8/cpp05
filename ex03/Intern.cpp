/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:08:05 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/08 11:12:00 by romainjober      ###   ########.fr       */
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


/***************************** Member methods *********************************/

AForm* Intern::createShrubbery(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string form_name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm* (Intern::*form_func[3])(const std::string& t) const = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};

	for (int i = 0; i < 3; ++i)
	{
		if (form_name[i] == name)
		{
			AForm* new_form = (this->*form_func[i])(target);
			std::cout << "Intern creates " << new_form->getName() << std::endl;
			return (new_form);
		}
	}
	std::cerr << RED "Intern cannot create the form - unknown type" RESET << std::endl;
	return (NULL);
}
