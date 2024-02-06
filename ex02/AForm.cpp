/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:42:01 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/06 20:37:17 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/************************ Canonical *****************************************/

AForm::AForm() : _name("unknown_AForm"), _signed(false), _sign_grade(Bureaucrat::lowest_rank), _exec_grade(Bureaucrat::lowest_rank) {}

AForm::AForm(const std::string& name, const int signatory, const int exec) : _name(name), _signed(false), _sign_grade(signatory), _exec_grade(exec) 
{
	if (_sign_grade < Bureaucrat::top_rank || _exec_grade < Bureaucrat::top_rank)
		throw AForm::GradeTooHighException();
	if (_sign_grade > Bureaucrat::lowest_rank || _exec_grade > Bureaucrat::lowest_rank)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() 
{
	std::cout << "AForm Destructor Called " << std::endl;
}

AForm::AForm (const AForm& src) : _name(src._name), _signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade) 
{
	this->validDoc();
}

AForm& AForm::operator=(const AForm& src) 
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

/*********************** Handler Message Class *****************************/

AForm::CannotExec::CannotExec(const std::string& msg) : std::logic_error(msg) {}

const std::string& AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSignStatus() const
{
	return (this->_signed);
}

int AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int AForm::getExecGrade() const
{
	return (this->_exec_grade);
}

void	AForm::beSigned(const Bureaucrat& signatory)
{
	if (signatory.getGrade() > this->_sign_grade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void	AForm::validDoc()
{
	if (this->_sign_grade < Bureaucrat::top_rank)
		throw AForm::GradeTooHighException();
	if (this->_sign_grade > Bureaucrat::lowest_rank)
		throw AForm::GradeTooLowException();
	if (this->_exec_grade < Bureaucrat::top_rank)
		throw AForm::GradeTooHighException();
	if (this->_exec_grade > Bureaucrat::lowest_rank)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return (RED "Signatory too high level to sign" RESET);
}
	
const char* AForm::GradeTooLowException::what() const throw()
{
	return (RED "Bureaucrat too low level to sign " RESET);
}

std::ostream& operator<<(std::ostream& os, const AForm& src)
{
	os << "AForm state is: " << std::endl;
	os << "\t name: " << src.getName() << std::endl;
	os << "\t Status: " << src.getSignStatus() << std::endl;
	os << "\t Signatory Grade min level: " << src.getSignGrade() << std::endl;
	os <<"\t Execution Grade min level: " << src.getExecGrade() << std::endl;
	return (os);
}

bool	AForm::CheckExec(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->_exec_grade)
		throw AForm::CannotExec("Cannot Exec - Bureaucrat's rank insufficient");
	if (!this->getSignStatus())
		throw AForm::CannotExec("Cannot Exec - Form not Signed");
	return (true);
}

