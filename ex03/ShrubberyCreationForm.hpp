/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:57:59 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/07 14:38:53 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
	
	const std::string& getTarget() const;
	void execute(Bureaucrat const & executor) const;

	class FileIssue: public std::logic_error
	{
		public:
			FileIssue(const std::string& msg);
	};
};

void tree_art(std::ofstream& os);
std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& src);

#endif
