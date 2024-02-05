/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:56:42 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/05 18:56:18 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "colors.h"

class Bureaucrat
{
private:
	const std::string _name;
	unsigned int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat& operator=(const Bureaucrat& src);
	
	const std::string& getName() const;
	int getGrade() const;
	void upGrade(int n);
	void upGrade();
	void downGrade(int n);
	void downGrade();
	
	class GradeTooHighException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
	static const int lowest_rank = 150;
	static const int top_rank = 1;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);

#endif
