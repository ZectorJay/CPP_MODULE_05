/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:21:12 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/08 18:58:23 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Form*		makePresidentialForm( std::string const & target ) {
	return (new PresidentialPardonForm( target ));
}

Form*		makeShrubberyForm( std::string const & target )  {
	return (new ShrubberyCreationForm( target ));
}

Form*		makeRobotomyForm( std::string const & target )  {
	return (new RobotomyRequestForm( target ));
}

Intern::Intern() : _newForm(initForms()) {}

Intern::~Intern() { delete [] _newForm; }

Intern::Intern( Intern const & ) : _newForm(initForms()) {}

_t_Form*		Intern::initForms() {
	_t_Form* init = new _t_Form[3];
	init[0]._foo = &makeRobotomyForm;
	init[1]._foo = &makeShrubberyForm;
	init[2]._foo = &makeRobotomyForm;
	init[0]._name = "presidential request";
	init[1]._name = "shrubbery request";
	init[2]._name = "robotomy request";
	return (init);
}

int			Intern::searchForm( std::string name){
	int i = 0;
	while (name.compare(_newForm[i]._name) != 0 && i < 3)
		i++;
	if (name.compare(_newForm[i]._name) != 0)
		throw notFound();
	return (i);
}

Form*		Intern::makeForm( std::string formName, std::string target){
	int i = searchForm(formName);
	return (_newForm[i]._foo(target));
}

char const *		Intern::notFound::what() const throw(){
	return ("form with that name not found");
}