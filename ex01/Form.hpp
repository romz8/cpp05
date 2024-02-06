/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:32:07 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/06 17:14:53 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool			_signed;
	const int	_sign_grade;
	const int	_exec_grade;

public:
	Form();
	Form(const std::string& name, const int signer, const int exec);
	~Form();
	Form (const Form& src);
	Form& operator=(const Form& src);
	const std::string& getName() const;
	bool getSignStatus() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void	beSigned(const Bureaucrat& signer);

	void	validDoc();

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what () const throw(); 		
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what () const throw(); 		
	};
};

std::ostream& operator<<(std::ostream& os, const Form& src);

#endif
