/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:00:41 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/07 17:09:22 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"

class AForm;

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern& src);
	Intern& operator=(const Intern& src);
	AForm* makeForm(const std::string& name, const std::string& target);
};

#endif
