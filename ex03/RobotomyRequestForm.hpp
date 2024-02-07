/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:36:25 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/07 14:57:25 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
	
	const std::string& getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& src);

#endif
