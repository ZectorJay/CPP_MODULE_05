/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:39:37 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/05 20:08:12 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string name, short int gradeToSign, short int gradeToExec ) :
_name(name), _sign(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
	if (_gradeToExec > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
	if (_gradeToExec < 0 || _gradeToSign < 0)
		throw GradeTooHighException();
}

Form::Form (Form const & src) : _name(src.getName()), _sign(src.getSignStatus()),
_gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) {}

std::string const	Form::getName() const {	return (_name); }

bool				Form::getSignStatus() const { return (_sign); }

short int const		Form::getGradeToSign() const { return (_gradeToSign); }

short int const		Form::getGradeToExec() const { return (_gradeToExec); }

Form &				Form::operator=( Form const & src ){
	if (this != & src ){
		_sign = src.getSignStatus();
	}
	return (*this);
}

char const * 		Form::GradeTooHighException::what() const throw(){
	return ("Form Grade is too high");
}

char const * 		Form::GradeTooLowException::what() const throw(){
	return ("Form Grade is too low");
}

std::ostream &		operator<<( std::ostream & o, Form const & src ){
	o << "Form <"<<src.getName()<<"> sign status - ";
	if (src.getSignStatus() == 0)
		o << RED << "NOT SIGNED" << RESET;
	else
		o << RED << "SIGNED" << RESET;
	o << ". Its require " << src.getGradeToSign() << "th grade to sign and ";
	o << src.getGradeToExec() << " grade to execute" << std::endl;
	return (o);
}
