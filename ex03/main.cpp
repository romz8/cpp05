/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:33:14 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/08 13:02:35 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void safe_form_exec(AForm& f, Bureaucrat &executor)
{
	try 
	{
        f.execute(executor);
    } 
	catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void safe_sign_form(AForm& f, Bureaucrat &signatory)
{
	try 
	{
        signatory.signForm(f);
    } 
	catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Shrubbery_test()
{
    std::cout << std::endl << GREEN "****************************************" << std::endl;
	std::cout << std::endl << "Testing Shrubbery" << std::endl;
	std::cout << std::endl << "****************************************" RESET<< std::endl;
	
	std::cout << std::endl << YELLOW "creating an entire administration" RESET<< std::endl;
	Bureaucrat boss("boss", 1);
	Bureaucrat sbire("sous-fifre", 150);
	Bureaucrat mid("manager", 75);
	Bureaucrat top_mid("manager of manager", 50);
	Bureaucrat low_mid("managed by manager", 145);
	std::cout <<  BLUE "Bureaucras are : " RESET<< std::endl;
	std::cout << boss << std::endl << sbire << std::endl << mid << std::endl;
	std::cout << top_mid << std::endl << low_mid << std::endl;
	
	std::cout << std::endl << YELLOW "creating some Shrubbery Forms / testing constructor" RESET<< std::endl;
	ShrubberyCreationForm f0, f2;
	ShrubberyCreationForm f1("home");
	ShrubberyCreationForm f3("garden party");
	ShrubberyCreationForm f4(f3);
	f2 = f1;
	std::cout <<  BLUE "Shrubbery Forms are : " RESET<< std::endl;
	std::cout << f0;
	std::cout << f1;
	std::cout << f2;
	std::cout << f3;
	std::cout << f4;
	std::cout << std::endl << YELLOW "We'll try to exec the unsigned forms" RESET<< std::endl;
	safe_form_exec(f0, boss);
	safe_form_exec(f1, boss);
	safe_form_exec(f2, boss);
	safe_form_exec(f3, boss);
	safe_form_exec(f4, boss);
	
	std::cout << std::endl << YELLOW "We'll try to sign with wrong Bureaucrat" RESET<< std::endl;
	safe_sign_form(f0, sbire);
	safe_sign_form(f1, sbire);
	safe_sign_form(f2, sbire);
	std::cout << std::endl << YELLOW "We'll try to sign with right Bureaucrat" RESET<< std::endl;
	safe_sign_form(f0, low_mid);
	safe_sign_form(f1, top_mid);
	safe_sign_form(f2, boss);
	std::cout << std::endl << YELLOW "We'll try to execute signed but with wrong Bureaucrat" RESET<< std::endl;
	safe_form_exec(f0, sbire);
	safe_form_exec(f1, low_mid);
	safe_form_exec(f2, sbire);
	std::cout << std::endl << YELLOW "ok - now we execute it like a good administration" RESET<< std::endl;
	safe_form_exec(f0, mid);
	safe_form_exec(f1, top_mid);
	safe_form_exec(f2, boss);
	
	std::cout << std::endl << GREEN "Test Passed - Cleaning Ressources" RESET<< std::endl << std::endl;
	std::cout <<  BLUE "Doing `cat  *_shrubbery` should show tw trees";
	std::cout << "(as f2 overwritte f1 because of copy Asignment) " RESET << std::endl << std::endl;
	return ;
}


void	bureaucrat_exec_test()
{
	std::cout << std::endl << GREEN "****************************************" << std::endl;
	std::cout << std::endl << "Testing Bureaucrat exec form method " << std::endl;
	std::cout << std::endl << "****************************************" RESET<< std::endl;
	
	std::cout << std::endl << YELLOW "creating an entire administration" RESET<< std::endl;
	Bureaucrat boss("boss", 1);
	Bureaucrat sbire("sous-fifre", 150);
	Bureaucrat mid("manager", 75);
	Bureaucrat top_mid("manager of manager", 50);
	Bureaucrat low_mid("managed by manager", 145);
	std::cout <<  BLUE "Bureaucras are : " RESET<< std::endl;
	std::cout << boss << std::endl << sbire << std::endl << mid << std::endl;
	std::cout << top_mid << std::endl << low_mid << std::endl;

	
	std::cout << std::endl << YELLOW "Testing on Shrubbery" RESET<< std::endl;
	ShrubberyCreationForm f1("home");
	RobotomyRequestForm f2("Joker");
	PresidentialPardonForm f3("Aaron");

	std::cout << std::endl << BLUE "Boss tries (but not signed)" RESET<< std::endl;
	boss.executeForm(f1);
	boss.executeForm(f2);
	boss.executeForm(f3);
	std::cout << std::endl << BLUE "Sbire tries to sign (but level too low)" RESET<< std::endl;
	safe_sign_form(f1, sbire);
	safe_sign_form(f2, sbire);
	safe_sign_form(f3, sbire);
	std::cout << std::endl << BLUE "manager sign but cannot execute (level to sign but too low to exec)" RESET<< std::endl;
	safe_sign_form(f1, mid);
	safe_sign_form(f2, top_mid);
	std::cout << std::endl << BLUE "manager cannot sign nor exec the presidential pardon : only big boss" RESET<< std::endl;
	safe_sign_form(f3, top_mid);
	low_mid.executeForm(f1);
	std::cout << std::endl << BLUE "let's now execute with higher manager and boss as well" RESET<< std::endl;
	mid.executeForm(f1);
	boss.executeForm(f1);
	mid.executeForm(f2);
	boss.executeForm(f2);
	std::cout << std::endl << BLUE "Now boss will sign then execute the presidential pardon" RESET<< std::endl;
	safe_sign_form(f3, boss);
	boss.executeForm(f3);

	std::cout << std::endl << GREEN "Test Passed - Cleaning Ressources" RESET<< std::endl << std::endl;
}

void	Intern_test()
{
	std::cout << std::endl << GREEN "****************************************" << std::endl;
	std::cout << std::endl << "Testing Inters " << std::endl;
	std::cout << std::endl << "****************************************" RESET<< std::endl;
	
	std::cout << std::endl << YELLOW "new administration : one intern and a boss" RESET<< std::endl;
	Intern	intern;
	Bureaucrat	boss("big boss",1);
	std::cout << std::endl << BLUE "let's try : shrubbery creation, robotomy request, presidential pardon and a crazy form" RESET<< std::endl;
	const std::string test [] = {"shrubbery creation", "robotomy request", "presidential pardon", "crazy form"};

	for (int i = 0; i < 4; ++i)
	{
		std::cout << std::endl << BLUE "Test " << i << " On : " << test[i] << RESET<< std::endl;
		AForm* newform = intern.makeForm(test[i], "intern_target");
		if (newform)
		{
			boss.executeForm(*newform);
			boss.signForm(*newform);
			boss.executeForm(*newform);
			delete newform;
		}
	}

	std::cout << std::endl << GREEN "Test Passed - Cleaning Ressources" RESET<< std::endl << std::endl;
}



int main(void)
{
	Shrubbery_test();
	bureaucrat_exec_test();
	Intern_test();
	return (0);
}
