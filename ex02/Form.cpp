/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:39:37 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 16:45:41 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string target, std::string name, short int gradeToSign, short int gradeToExec ) :
_target(target), _name(name), _sign(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
	if (_gradeToExec > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
	if (_gradeToExec <= 0 || _gradeToSign <= 0)
		throw GradeTooHighException();
}

Form::Form (Form const & src) : _target(src.getTarget()), _name(src.getName()),
_sign(src.getSignStatus()), _gradeToSign(src.getGradeToSign()),
_gradeToExec(src.getGradeToExec()) {}

std::string 		Form::getName() const {	return (_name); }

bool				Form::getSignStatus() const { return (_sign); }

short int 			Form::getGradeToSign() const { return (_gradeToSign); }

short int 			Form::getGradeToExec() const { return (_gradeToExec); }

std::string			Form::getTarget() const { return (_target); }

Form &				Form::operator=( Form const & src ){
	if (this != & src ){
		_sign = src.getSignStatus();
		_target = src.getTarget();
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

/**
**      @brief  Function that set sign status of form
**
**      @param  signer			take bureaucrat which will try to sign form
**      @return              	return 1 - success, 0 - form already signed, (-1) - bureaucrat grade is too low
*/
int					Form::beSigned( Bureaucrat const & signer ) {
	if ( signer.getGrade() <= _gradeToSign && _sign == 0){
		_sign = 1;
		return (1);
	}
	else if (_sign == 1)
		return (0);
	return (-1);
}

/**
**      @brief  Function launch execution of the form
**
**      @param  executor		take bureaucrat which will try to execute form
**      @return              	return 1 - success, 0 - not signed, (-1) - bureaucrat grade is too low, (-2) Error during execution
*/
int					Form::execute( Bureaucrat const & executor ) const {
	if ( executor.getGrade() <= _gradeToExec && _sign == 1){
		if (executeAction())
			return (1);
		return (-2);
	} else if (_sign == 0 && executor.getGrade() <= _gradeToExec )
		return (0);
	return (-1);
}