/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:31:17 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/05 19:23:02 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

	Form( std::string name, short int gradeToSign, short int _gradeToExec );
	Form (Form const & src );
	~Form(){}

	Form &		operator= (Form const & src );

	std::string const	getName() const;
	bool				getSignStatus() const;
	short int const		getGradeToSign() const;
	short int const		getGradeToExec() const;

	class	GradeTooHighException : public std::exception {

	public:

		GradeTooHighException(){};

		char const	*what() const throw();		

	};

	class	GradeTooLowException: public std::exception {

	public:

		GradeTooLowException(){}

		char const	*what() const throw();

	};

private:

	Form() : _name(NULL), _sign(0), _gradeToExec(0), _gradeToSign(0) {}

	std::string const 	_name;
	bool				_sign;
	short int const		_gradeToSign;
	short int const		_gradeToExec;

};

std::ostream	&	operator<<(std::ostream & o, Form const & src );

#endif