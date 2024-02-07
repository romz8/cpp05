/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:52:38 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/07 14:57:35 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& src);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
	
	const std::string& getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm& src);

#endif
