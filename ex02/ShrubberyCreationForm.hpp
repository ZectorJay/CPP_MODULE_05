/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:09:22 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 17:06:08 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class ShrubberyCreationForm : public Form {

public:

	ShrubberyCreationForm( std::string target );
	virtual ~ShrubberyCreationForm(){};
	ShrubberyCreationForm ( ShrubberyCreationForm const & src );

	std::string const	getTree() const;

private:

	ShrubberyCreationForm();

	int					executeAction() const;

	std::string					_target;
	static std::string const	_tree;

};

#endif