/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:52:41 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/07 14:57:40 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/********************** Canonical Methods ***********************************/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), _target("Unknown")
{
	std::cout << "PresidentialPardon Default Constructor Called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardon Parametized (target) Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardon Destructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src.getName(), 25, 5), _target(src._target) 
{
	std::cout << "PresidentialPardon Copy Constructor Called" << std::endl;
}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << "PresidentialPardon Copy Assignment Called" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

/********************* Member Functions *********************************/

const std::string& PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	CheckExec(executor);
	std::cout << this->getTarget() <<" has been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm& src)
{
	os << "PresidentialPardonForm is: " << std::endl;
	os << "\t name : " <<src.getName() << std::endl;
	os << "\t sign status : " << src.getSignStatus() << std::endl;
	os << "\t sign grade : " << src.getSignGrade() << std::endl;
	os << "\t exec grade : " << src.getExecGrade() << std::endl;
	os << "\t target : " << src.getTarget() << std::endl;
	return (os);
}
