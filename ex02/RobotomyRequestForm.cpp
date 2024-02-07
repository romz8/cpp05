/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:42:40 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/07 14:47:06 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/********************** Canonical Methods ***********************************/

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyForm", 72, 45), _target("Unknown")
{
	std::cout << "RobotomyForm Default Constructor Called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyForm", 72, 45), _target(target)
{
	std::cout << "RobotomyForm Parametized (target) Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyForm Destructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src.getName(), 72, 45), _target(src._target) 
{
	std::cout << "RobotomyForm Copy Constructor Called" << std::endl;
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "RobotomyForm Copy Assignment Called" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

/********************* Member Functions *********************************/

const std::string& RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	CheckExec(executor);
	std::cout << "Grrr.. Grrr.. making some wild and heavy Robotomy noise ..Grr .. Grr.. " << std::endl;
	int sed = rand();
	if (sed % 2)
		std::cout << this->getTarget() <<" has been Robotmized Succesfully" << std::endl;
	else
		std::cout << this->getTarget() << "Robotmy Failed on " << this->getTarget() << std::endl;
	return ;
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& src)
{
	os << "RobotomyRequestForm is: " << std::endl;
	os << "\t name : " <<src.getName() << std::endl;
	os << "\t sign status : " << src.getSignStatus() << std::endl;
	os << "\t sign grade : " << src.getSignGrade() << std::endl;
	os << "\t exec grade : " << src.getExecGrade() << std::endl;
	os << "\t target : " << src.getTarget() << std::endl;
	return (os);
}
