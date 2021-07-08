/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:28:42 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 15:17:45 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade <= 0)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) { this->operator=(src); }

std::string		Bureaucrat::getName() const { return (_name); }

int				Bureaucrat::getGrade() const { return (_grade); }

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & src ) {
	if ( this != &src ){
		_name = src.getName();
		_grade = src.getGrade();
	}
	return (*this);
}

void			Bureaucrat::upGrade() {
	if (_grade - 1 <= 0)
		throw GradeTooHighException();
	_grade--;
}

void			Bureaucrat::downGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream &		operator<<( std::ostream & o, Bureaucrat const & src ){
	o << YELLOW << src.getName() << ", bureaucrat grade "<< src.getGrade() << RESET;
	return (o);
}


char const* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too high");
}

char const* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade is too low");
}

void				Bureaucrat::SignForm( Form & formToSign ){
	int i = formToSign.beSigned(*this);
	if (i == 0)
		std::cout<<"Form already signed";
	else if (i == (-1))
		std::cout<<"Bureaucrat grade is too low. Can't sign this form";
	else
		std::cout<<"Form <"<<formToSign.getName()<<"> successfully signed by "<<_name;
	std::cout<<std::endl;
}

void				Bureaucrat::executeForm( Form const & form ){
	int i = form.execute(*this);
	if (i == 1)
		std::cout<<BLUE<<_name<<" succesfully executed "<<form.getName();
	else if (i == -1)
		std::cout<<RED<<_name<<" grade is too low. Required grade is "<<form.getGradeToExec();
	else if (i == 0)
		std::cout<<YELLOW<<_name<<" can't execute form "<<form.getName()<<". Form is not signed yet";
	std::cout<<RESET<<std::endl;
}