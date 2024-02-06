/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:54:13 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/06 12:23:20 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/************************** Canonical Suite **********************************/

Bureaucrat::Bureaucrat() : _name("Nameless Bureaucrat"), _grade(Bureaucrat::lowest_rank)
{ 
	std::cout << "Default constructor for Bureaucrat of lowest rank" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < Bureaucrat::top_rank)
			throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::lowest_rank)
			throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << "Parametized Bureaucrat created safely" << std::endl;
}

Bureaucrat::~Bureaucrat() {}


Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name) 
{
	this->_grade =  src.getGrade();
	std::cout << "Copy Bureaucrat constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "Copy Assignment" << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

/************************** Member methods **********************************/

const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}
	
int Bureaucrat::getGrade() const
{
	return (this->_grade);
}
	
void Bureaucrat::upGrade(int n)
{
	if (this->_grade - n < Bureaucrat::top_rank || this->_grade - n > Bureaucrat::lowest_rank)
		throw GradeTooHighException();
	this->_grade -= n;
}

void Bureaucrat::downGrade(int n)
{
	if (this->_grade + n > Bureaucrat::lowest_rank || this->_grade + n < Bureaucrat::top_rank)
		throw GradeTooLowException();
	this->_grade += n;
}

void Bureaucrat::upGrade()
{
	Bureaucrat::upGrade(1);
}	

void Bureaucrat::downGrade()
{
	Bureaucrat::downGrade(1);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (os);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "Grade too low for a bureaucrat - lowest grade is 150" RESET);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "Grade too high for a bureaucrat - highest grade is 1" RESET);
}
