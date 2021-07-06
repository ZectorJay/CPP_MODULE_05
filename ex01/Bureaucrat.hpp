/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:09:24 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/06 09:31:35 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# define RED	"\033[1;38;2;250;20;20m"
# define RESET	"\033[0m"
# define BLUE	"\033[1;38;2;130;250;220m"
# define YELLOW "\033[1;38;2;250;250;140m"

class Form;

class Bureaucrat {
	
public:

	Bureaucrat( std::string name, int grade);
	~Bureaucrat(){}
	Bureaucrat( Bureaucrat const & src );

	Bureaucrat &	operator= ( Bureaucrat const & src );

	std::string 	getName() const ;
	int				getGrade() const ;
	void			upGrade() ;
	void			downGrade() ;
	void			SignForm( Form & formToSign ) ;

	class GradeTooHighException : public std::exception {
	
	public:

		GradeTooHighException(){}

		char const	*what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
	
	public:

		GradeTooLowException(){}

		char const	*what() const throw();
	};

private:

	Bureaucrat();

	std::string		_name;
	int				_grade;
};

std::ostream &		operator<<( std::ostream & o, Bureaucrat const & src );

#endif