/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:33:14 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/05 18:54:30 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

void	safe_promotion(Bureaucrat& src, bool dir)
{
	try
	{
		if (dir == true)
			src.upGrade();
		else
			src.downGrade();
	}
	catch(Bureaucrat::GradeTooHighException& h)
	{
		std::cerr << "issue during the promotion " << h.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& l)
	{
		std::cerr << "issue during the downgrade " << l.what() << std::endl;
	}
	
	
}

void canonical_test()
{
	std::cout << std::endl << GREEN "****************************************" << std::endl;
	std::cout << std::endl << "Testing Canonical Constructor Destructor" << std::endl;
	std::cout << std::endl << "****************************************" RESET<< std::endl;
	std::cout << YELLOW "Canonical test : Good value" RESET<< std::endl;
	Bureaucrat chief("boss", 1);
	Bureaucrat boring;
	boring = chief;
	Bureaucrat sbire("sbire", 150);
	Bureaucrat sbire2(sbire);
	std::cout << BLUE "Bureaucrat dream team is: " RESET << std::endl;
	std::cout << chief;
	std::cout << sbire;
	std::cout << BLUE "their copies are : " RESET  << std::endl;
	std::cout << boring;
	std::cout << sbire2;

	//bad construct test
	std::cout << YELLOW "Bad constructor test" RESET<< std::endl;
	std::cout << "trying for 0, 151, -10000, 100000 "<< std::endl;
	
	Bureaucrat toomuch = bureaucrat_factory("boss_too_ambitious", 0);
	Bureaucrat toolow = bureaucrat_factory("too_sbire", 151);
	Bureaucrat too_ambi = bureaucrat_factory("crazy boss", -10000);
	Bureaucrat not_ambi = bureaucrat_factory("lazy sbire", 10000);
	
	std::cout << YELLOW "Result from outsized test : should all be low rank bureaucrat" RESET<< std::endl;
	std::cout << toomuch;
	std::cout << toolow;
	std::cout << too_ambi;
	std::cout << not_ambi;
}

void promotion_test()
{
	std::cout << std::endl << GREEN "****************************************" << std::endl;
	std::cout << std::endl << "Testing Promotion" << std::endl;
	std::cout << std::endl << "****************************************" RESET<< std::endl;
	std::cout << std::endl << YELLOW "creating an entire administration" RESET<< std::endl;
	std::cout << YELLOW "creating an entire administration" RESET<< std::endl;
	Bureaucrat boss("boss", 1);
	Bureaucrat sbire("sous-fifre", 150);
	Bureaucrat mid("manager", 75);
	Bureaucrat top_mid("manager of manager", 115);
	Bureaucrat low_mid("managed by manager", 50);

	std::cout << YELLOW "Social Revolution" RESET<< std::endl;
	std::cout << YELLOW "up / downgrade test : promoting / declassing 149 the tops and bottoms" RESET<< std::endl;
	for (int i = 0; i < 149; ++i)
	{
		safe_promotion(sbire, true);
		safe_promotion(boss, false);
	}
	std::cout << "now we should have boss at lowest level and former lowest at the top" << std::endl;
	std::cout << boss;
	std::cout << sbire;
	std::cout << "one more (fatal) move" << std::endl;
	safe_promotion(sbire, true);
	safe_promotion(boss, false);
	std::cout << "their level are now OVER THE LIMITS !!!! " << std::endl;
	std::cout << boss;
	std::cout << sbire;
	
	// std::cout << "trying to promote chief copy and sbire copy" << std::endl;
	// sbire2.downGrade();
	// chief2.upGrade();
	// std::cout << chief2;
	// std::cout << sbire2;
}

int main(void)
{

	canonical_test();
	promotion_test();

	return (0);
}
