/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:32:07 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/07 16:31:03 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

/*
added the CheckExecutable to handle in the Abstract class the constraint on any concrete class
added the nested class CannotExec to handle the case with custom message built on std::logic_error constructor
*/

class AForm
{
private:
	const std::string _name;
	bool			_signed;
	const int	_sign_grade;
	const int	_exec_grade;

public:
	AForm();
	AForm(const std::string& name, const int signer, const int exec);
	virtual ~AForm();
	AForm (const AForm& src);
	AForm& operator=(const AForm& src);
	const std::string& getName() const;
	bool getSignStatus() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void	beSigned(const Bureaucrat& signer);

	void	validDoc();
	bool	CheckExec(const Bureaucrat& executor) const;
	
	virtual void execute(Bureaucrat const & executor) const = 0;
	virtual const std::string& getTarget() const = 0;

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
	
	class CannotExec: public std::logic_error
	{
		public:
			CannotExec(const std::string& msg);
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& src);

#endif
