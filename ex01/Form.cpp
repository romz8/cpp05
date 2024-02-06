/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:42:01 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/06 17:28:58 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("unknown_form"), _signed(false), _sign_grade(Bureaucrat::lowest_rank), _exec_grade(Bureaucrat::lowest_rank) {}

Form::Form(const std::string& name, const int signatory, const int exec) : _name(name), _signed(false), _sign_grade(signatory), _exec_grade(exec) 
{
	if (_sign_grade < Bureaucrat::top_rank || _exec_grade < Bureaucrat::top_rank)
		throw Form::GradeTooHighException();
	if (_sign_grade > Bureaucrat::lowest_rank || _exec_grade > Bureaucrat::lowest_rank)
		throw Form::GradeTooLowException();
}

Form::~Form() 
{
	std::cout << "Form Destructor Called " << std::endl;
}

Form::Form (const Form& src) : _name(src._name), _signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade) 
{
	this->validDoc();
}

Form& Form::operator=(const Form& src) 
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

const std::string& Form::getName() const
{
	return (this->_name);
}

bool Form::getSignStatus() const
{
	return (this->_signed);
}

int Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int Form::getExecGrade() const
{
	return (this->_exec_grade);
}

void	Form::beSigned(const Bureaucrat& signatory)
{
	if (signatory.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

void	Form::validDoc()
{
	if (this->_sign_grade < Bureaucrat::top_rank)
		throw Form::GradeTooHighException();
	if (this->_sign_grade > Bureaucrat::lowest_rank)
		throw Form::GradeTooLowException();
	if (this->_exec_grade < Bureaucrat::top_rank)
		throw Form::GradeTooHighException();
	if (this->_exec_grade > Bureaucrat::lowest_rank)
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return (RED "Signatory too high level to sign" RESET);
}
	
const char* Form::GradeTooLowException::what() const throw()
{
	return (RED "Bureaucrat too low level to sign " RESET);
}

std::ostream& operator<<(std::ostream& os, const Form& src)
{
	os << "Form state is: " << std::endl;
	os << "\t name: " << src.getName() << std::endl;
	os << "\t Status: " << src.getSignStatus() << std::endl;
	os << "\t Signatory Grade min level: " << src.getSignGrade() << std::endl;
	os <<"\t Execution Grade min level: " << src.getExecGrade() << std::endl;
	return (os);
}
