/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:32:07 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/06 13:30:51 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool			_signed;
	const int	_sign_grade;
	const int	_exec_grade;

public:
	Form();
	Form(const std::string& name);
	Form(const std::string& name, const int signer, const int exec);
	~Form();
	Form (const Form& src);
	Form& operator=(const Form& src);
	const std::string& getName() const;
	const bool getSignStatus() const;
	const int getSignGrade() const;
	const int getExecnGrade() const;
	void	beSigned(Bureaucrat& signer);

	void	valid_doc();

	class GradeTooHighException : public std::exception
	{
		const char* what () const throw(); 		
	};
	
	class GradeTooLowException : public std::exception
	{
		const char* what () const throw(); 		
	};
};

#endif
