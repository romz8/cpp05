/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:42:01 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/06 13:30:22 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("unknown_form"), _signed(false), _sign_grade(Bureaucrat::lowest_rank), _exec_grade(Bureaucrat::lowest_rank) {}

Form::Form(const std::string& name, const int signatory, const int exec) : _name(name), _signed(false), _sign_grade(signer), _exec_grade(exec) 
{
	this->valid_doc();
}

Form::~Form() {}

Form::Form (const Form& src) : _name(src._name), _signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade) 
{
	this->valid_doc();
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

const bool Form::getSignStatus() const
{
	return (this->_signed);
}

const int Form::getSignGrade() const
{
	return (this->_sign_grade);
}

const int Form::getExecnGrade() const
{
	return (this->_exec_grade);
}

//void	Form::beSigned(Bureaucrat& signer) - TO IMPLEMENT

void	Form::valid_doc()
{
	if (this->_sign_grade < Bureaucrat::top_rank)
		throw Bureaucrat::GradeTooHighException();
	if (this->_sign_grade > Bureaucrat::lowest_rank)
		throw Bureaucrat::GradeTooLowException();
	if (this->_exec_grade < Bureaucrat::top_rank)
		throw Bureaucrat::GradeTooHighException();
	if (this->_exec_grade > Bureaucrat::lowest_rank)
		throw Bureaucrat::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
		return (RED "Signatory too high level to sign" RESET);
}
	
const char* Form::GradeTooLowException::what() const throw()
{
	return (RED "Bureaucrat too low level to sign " RESET);
}