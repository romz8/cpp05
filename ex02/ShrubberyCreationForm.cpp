/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:49:16 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/06 21:35:10 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/********************** Canonical Methods ***********************************/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 145, 137), _target("Unknown")
{
	std::cout << "ShrubberyForm Default Constructor Called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyForm Parametized (target) Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyForm Destructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src.getName(), 145, 137), _target(src._target) 
{
	std::cout << "ShrubberyForm Copy Constructor Called" << std::endl;
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << "ShrubberyForm Copy Assignment Called" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

/********************** Subclass File Error Handler **********************/

ShrubberyCreationForm::FileIssue::FileIssue(const std::string& msg) : std::logic_error(msg) {}

/********************* Member Functions *********************************/

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	CheckExec(executor);
	std::string file_name = this->_target;
	file_name.append("_shrubbery");
	
	std::ofstream file(file_name);
	if (!file.is_open())
		throw ShrubberyCreationForm::FileIssue("cannot create the target file");
	tree_art(file);
	file.close();
}

void tree_art(std::ofstream& os)
{
    os << "                                              ." << std::endl;
    os << "                                   .         ;" << std::endl;
    os << "      .              .              ;%     ;;" << std::endl;
    os << "        ,           ,                :;%  %;" << std::endl;
    os << "         :         ;                   :;%;'     .," << std::endl;
    os << ",.        %;     %;            ;        %;'    ,;" << std::endl;
    os << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    os << "   %;       %;%;      ,  ;       %;  ;%;   ,%;" << std::endl;
    os << "    ;%;      %;        ;%;        % ;%;  ,%;" << std::endl;
    os << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    os << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    os << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
    os << "           `@%:.  :;%.         ;@@%;'" << std::endl;
    os << "             `@%.  `;@%.      ;@@%;" << std::endl;
    os << "               `@%%. `@%%    ;@@%;" << std::endl;
    os << "                 ;@%. :@%%  %@@%;" << std::endl;
    os << "                   %@bd%%%bd%%:;" << std::endl;
    os << "                     #@%%%%%:;;" << std::endl;
    os << "                     %@@%%%::;" << std::endl;
    os << "                     %@@@%(o);  . '" << std::endl;
    os << "                     %@@@o%;:(.,'" << std::endl;
    os << "                 `.. %@@@o%::;" << std::endl;
    os << "                    `)@@@o%::;" << std::endl;
    os << "                     %@@(o)::;" << std::endl;
    os << "                    .%@@@@%::;" << std::endl;
    os << "                    ;%@@@@%::;." << std::endl;
    os << "               ...;%@@@@@%%:;;;;,..    Gilo97" << std::endl;
    os << "------------------------------------------------" << std::endl;
	return ;
}

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& src)
{
	os << "ShrubberyCreationForm is: " << std::endl;
	os << "\t name : " <<src.getName() << std::endl;
	os << "\t sign status : " << src.getSignStatus() << std::endl;
	os << "\t sign grade : " << src.getSignGrade() << std::endl;
	os << "\t exec grade : " << src.getExecGrade() << std::endl;
	os << "\t target : " << src.getTarget() << std::endl;
	return (os);
}
