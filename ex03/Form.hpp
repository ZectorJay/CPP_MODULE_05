/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:31:17 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 16:53:09 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class Form {

public:

	Form( std::string target, std::string name, short int gradeToSign, short int _gradeToExec );
	Form (Form const & src );
	virtual ~Form(){}

	Form &		operator= (Form const & src );

	std::string 		getName() const;
	std::string			getTarget() const;
	bool				getSignStatus() const;
	short int 			getGradeToSign() const;
	short int 			getGradeToExec() const;
	int					beSigned( Bureaucrat const & signer );
	int					execute ( Bureaucrat const & executor) const ;

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

protected:

	virtual int			executeAction() const = 0;

private:

	std::string			_target;
	std::string const 	_name;
	bool				_sign;
	short int const		_gradeToSign;
	short int const		_gradeToExec;

};

std::ostream	&	operator<<(std::ostream & o, Form const & src );

#endif