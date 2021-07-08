/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:55:09 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/08 18:58:06 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

	typedef struct	s_Form {
		Form*		(*_foo)(std::string const &);
		std::string	_name;
	}				_t_Form;

class Intern {

public:

	Intern();
	virtual ~Intern();
	Intern ( Intern const & );

	Intern & operator= ( Intern const & ) { return (*this); };

	Form*	makeForm( std::string formName, std::string target );

private:

	_t_Form*					initForms();
	int							searchForm( std::string name);

	class	notFound : public std::exception {

	public:

		notFound(){}

		char const	*what() const throw();

	};



	_t_Form*		_newForm;

};

#endif