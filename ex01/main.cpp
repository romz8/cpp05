/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:33:14 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/06 17:29:41 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const Bureaucrat bureaucrat_factory(const std::string& name, int grade)
{
	try
	{
		Bureaucrat safe(name, grade);
		std::cout << "Bureaucrat created safely and ready for admin life" << std::endl;
		return (safe);
	}
	catch (Bureaucrat::GradeTooHighException& h)
	{
		std::cerr << "issue creating bureaucrat : " << h.what() << std::endl;
		return (Bureaucrat(name, Bureaucrat::lowest_rank));
	}
	catch (Bureaucrat::GradeTooLowException& l)
	{
		std::cerr << "issue creating bureaucrat : " << l.what() << std::endl;
		return (Bureaucrat(name, Bureaucrat::lowest_rank));
	}
	std::cout << "Bureaucrat created safely and ready for admin life" << std::endl;
	
}

const Form form_factory(const std::string& name, int grade_sign, int grade_exec)
{
	try
	{
		Form safe(name, grade_sign, grade_exec);
		std::cout << "Form compliant with admin life" << std::endl;
		return (safe);
	}
	catch (Form::GradeTooHighException& h)
	{
		std::cerr << "issue creating the Form : " << h.what() << std::endl;
		return (Form(name, Bureaucrat::lowest_rank, Bureaucrat::lowest_rank));
	}
	catch (Form::GradeTooLowException& l)
	{
		std::cerr << "issue creating Form : " << l.what() << std::endl;
		return (Form(name, Bureaucrat::lowest_rank, Bureaucrat::lowest_rank));
	}
	std::cout << "Bureaucrat created safely and ready for admin life" << std::endl;
	
}


void canonical_test()
{
	std::cout << std::endl << GREEN "****************************************" << std::endl;
	std::cout << std::endl << "Testing Canonical Constructor Destructor" << std::endl;
	std::cout << std::endl << "****************************************" RESET<< std::endl;
	std::cout << YELLOW "Canonical test : Good value" RESET<< std::endl;
	Form f1, f2;
	Form f42("form_2", 42, 42);
	f2 = f42;
	Form f42_cpy(f42);
	std::cout << BLUE "Forms created are: " RESET << std::endl;
	std::cout << f1;
	std::cout << f42;
	std::cout << BLUE "their copies are : " RESET  << std::endl;
	std::cout << f2;
	std::cout << f42_cpy;

	//bad construct test
	std::cout << YELLOW "Bad constructor test" RESET<< std::endl;
	
	std::cout << "trying for grade sign, exec = 151, 151"<< std::endl;
	Form toolow = form_factory("too_sbire", 151, 151);
	std::cout << "trying for grade sign, exec = 0, 0"<< std::endl;
	Form toomuch = form_factory("boss_too_ambitious", 0, 0);
	std::cout << "trying for grade sign, exec = 1, 0"<< std::endl;
	Form too_much_onlyexec =form_factory("crazy boss", 1, 0);
	std::cout << "trying for grade sign, exec = 0, 1"<< std::endl;
	Form too_much_only_sign =form_factory("crazy boss", 0, 1);
	std::cout << "trying for grade sign, exec = 1, 151"<< std::endl;
	Form too_low_onlyexec =form_factory("crazy boss", 1, 151);
	std::cout << "trying for grade sign, exec = 151, 1"<< std::endl;
	Form too_low_only_sign =form_factory("crazy boss", 151, 1);
	
	std::cout << YELLOW "Result from outsized test : should all be Forms foor low rank bureaucrat" RESET<< std::endl;
	std::cout << toomuch;
	std::cout << toolow;
	std::cout << too_much_onlyexec;
	std::cout << too_low_onlyexec;
	std::cout << too_much_only_sign;
	std::cout << too_low_only_sign;
}

void sign_test()
{
	std::cout << std::endl << GREEN "****************************************" << std::endl;
	std::cout << std::endl << "Testing Signing Functions" << std::endl;
	std::cout << std::endl << "****************************************" RESET<< std::endl;
	
	std::cout << std::endl << YELLOW "FUNCTIONAL ADMINISTRATION" RESET<< std::endl;
	{
		std::cout << std::endl << YELLOW "creating an entire administration" RESET<< std::endl;
		Bureaucrat boss("boss", 1);
		Bureaucrat sbire("sous-fifre", 150);
		Bureaucrat mid("manager", 75);
		Bureaucrat top_mid("manager of manager", 50);
		Bureaucrat low_mid("managed by manager", 115);
		
		std::cout <<  BLUE "Bureaucras are : " RESET<< std::endl;
		std::cout << boss << std::endl << sbire << std::endl << mid << std::endl << top_mid << std::endl << low_mid << std::endl;	
		std::cout << std::endl << YELLOW "creating some funky forms" RESET<< std::endl;
		Form f1("top secret", 1, 1);
		Form f2("open bar", 150, 150);
		Form f3("f458972B - middle office nightmare", 75, 75);
		std::cout <<  BLUE "Forms are : " RESET<< std::endl;
		std::cout << f1;
		std::cout << f2;
		std::cout << f3;
		std::cout << std::endl << YELLOW "FUNCTIONAL ADMINISTRATION" RESET<< std::endl;
		std::cout << BLUE "the boss, sbire and manager sign their respective level files" RESET << std::endl;
		boss.signForm(f1);
		sbire.signForm(f2);
		top_mid.signForm(f3);
		std::cout << BLUE "middle management try to sign some of their level file but already signed" RESET << std::endl;
		low_mid.signForm(f3);
		top_mid.signForm(f2);
	}
	std::cout << std::endl << YELLOW "DISFUNCTIONAL ADMINISTRATION - HELL" RESET<< std::endl;
	{
		std::cout << std::endl << YELLOW "creating an entire administration" RESET<< std::endl;
		Bureaucrat boss("boss", 1);
		Bureaucrat sbire("sous-fifre", 150);
		Bureaucrat mid("manager", 75);
		Bureaucrat top_mid("manager of manager", 50);
		Bureaucrat low_mid("managed by manager", 115);
		
		std::cout <<  BLUE "Bureaucras are : " RESET<< std::endl;
		std::cout << boss << std::endl << sbire << std::endl << mid << std::endl << top_mid << std::endl << low_mid << std::endl;	
		std::cout << std::endl << YELLOW "creating some funky forms" RESET<< std::endl;
		Form f1("top secret", 1, 1);
		Form f2("high level", 45, 45);
		Form f3("f45C - low level authorization", 120, 120);
		std::cout <<  BLUE "Forms are : " RESET<< std::endl;
		std::cout << f1;
		std::cout << f2;
		std::cout << f3;
		std::cout << std::endl << YELLOW "FUNCTIONAL ADMINISTRATION" RESET<< std::endl;
		std::cout << BLUE "sbire and low manager sign files they could not acess" RESET << std::endl;
		sbire.signForm(f1);
		low_mid.signForm(f2);
		top_mid.signForm(f2);
		std::cout << BLUE "finally boss and top manager step in" RESET << std::endl;
		boss.signForm(f1);
		boss.signForm(f2);
		top_mid.signForm(f3);
		std::cout << BLUE "low management undestand what to sign but too late - they will be micro managed now" RESET << std::endl;
		low_mid.signForm(f3);
	}
}

int main(void)
{

	canonical_test();
	sign_test();

	return (0);
}
