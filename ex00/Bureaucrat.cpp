/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:54:13 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/05 18:55:04 by rjobert          ###   ########.fr       */
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
	this->_grade = Bureaucrat::lowest_rank;
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

const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}
	
int Bureaucrat::getGrade() const
{
	return (this->_grade);
}
	
void Bureaucrat::upGrade()
{
	try
	{
		if (this->_grade <= 1)
			throw GradeTooHighException();	
	}
	catch (GradeTooLowException& h)
	{
		std::cerr << "Impossible to downgrade this bureaucrat ! : " << h.what() << std::endl;
	}
	this->_grade--;
}

void Bureaucrat::downGrade(int n)
{
	try
	{
		if (this->_grade >= 150)
			throw GradeTooLowException();	
	}
	catch (GradeTooLowException& l)
	{
		std::cerr << "Impossible to downgrade this bureaucrat ! : " << l.what() << std::endl;
	}
	this->_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (os);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade to low for a bureaucrat - lowest grade is 150");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade to high for a bureaucrat - highest grade is 1");
}
