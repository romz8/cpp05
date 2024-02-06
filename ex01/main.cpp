/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:33:14 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/06 12:16:06 by rjobert          ###   ########.fr       */
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

void	safe_bulk_promotion(Bureaucrat& src, int n , bool dir)
{
	try
	{
		if (dir == true)
			src.upGrade(n);
		else
			src.downGrade(n);
	}
	catch(Bureaucrat::GradeTooHighException& h)
	{
		std::cerr << "issue during the promotion : " << h.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& l)
	{
		std::cerr << "issue during the downgrade : " << l.what() << std::endl;
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
	Bureaucrat boss("boss", 1);
	Bureaucrat sbire("sous-fifre", 150);
	Bureaucrat mid("manager", 75);
	Bureaucrat top_mid("manager of manager", 50);
	Bureaucrat low_mid("managed by manager", 115);
	
	std::cout <<  YELLOW "Bureaucras are : " RESET<< std::endl;
	std::cout << boss << std::endl << sbire << std::endl << mid << std::endl << top_mid << std::endl << low_mid << std::endl;

	std::cout << YELLOW "Social Revolution" RESET<< std::endl;
	std::cout << YELLOW "up / downgrade test : promoting / declassing 149 the tops and bottoms" RESET<< std::endl;
	for (int i = 0; i < 149; ++i)
	{
		safe_promotion(sbire, true);
		safe_promotion(boss, false);
	}
	std::cout << BLUE "now we should have boss at lowest level and former lowest at the top" RESET << std::endl;
	std::cout << boss;
	std::cout << sbire;
	std::cout << BLUE "one more (fatal) move" RESET << std::endl;
	safe_promotion(sbire, true);
	safe_promotion(boss, false);
	std::cout << boss;
	std::cout << sbire;
	
	std::cout << YELLOW "Now trying bulk promotions" RESET<< std::endl;
	std::cout << BLUE "trying to promote manager by 50 rank" RESET << std::endl;
	std::cout << "is rank should be : " << mid.getGrade() - 50 << std::endl;
	safe_bulk_promotion(mid, 50, true);
	std::cout << mid;
	std::cout << "now trying by 100" << std::endl;
	safe_bulk_promotion(mid, 100, true);
	std::cout << "now trying downgrade by 1000" << std::endl;
	safe_bulk_promotion(mid, 1000, false);
	std::cout << "is rank should stay the same (promotion cancelled)" << std::endl;
	std::cout << mid;
	std::cout << BLUE "let's invert the managers, now we have :" RESET << std::endl;
	std::cout << top_mid;
	std::cout << low_mid;
	safe_bulk_promotion(low_mid, 65, true);
	safe_bulk_promotion(top_mid, 65, false);
	std::cout << BLUE "post-promotion upside down :" RESET << std::endl;
	std::cout << top_mid;
	std::cout << low_mid;
	std::cout << YELLOW "trying negative promotions / downgrade" RESET<< std::endl;
	std::cout << BLUE "manager level is :" RESET << std::endl;
	std::cout << mid;
	std::cout << BLUE "promoting by -100 :" RESET << std::endl;
	safe_bulk_promotion(mid, -100, true);
	std::cout << mid;
	std::cout << BLUE "promoting by -200 :" RESET << std::endl;
	safe_bulk_promotion(mid, -200, true);
	std::cout << mid;
	std::cout << BLUE "downgrading by -20 :" RESET << std::endl;
	safe_bulk_promotion(mid, -20, false);
	std::cout << mid;
	std::cout << BLUE "downgrading by -200 :" RESET << std::endl;
	safe_bulk_promotion(mid, -200, false);
	std::cout << mid;
	
}

int main(void)
{

	canonical_test();
	promotion_test();

	return (0);
}
