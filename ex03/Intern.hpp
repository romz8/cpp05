/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:00:41 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/08 10:23:56 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern& src);
	Intern& operator=(const Intern& src);
	AForm* makeForm(const std::string& name, const std::string& target);

private:
	AForm* createShrubbery(const std::string& target) const;
    AForm* createRobotomy(const std::string& target) const;
    AForm* createPresidential(const std::string& target) const;


};

#endif
