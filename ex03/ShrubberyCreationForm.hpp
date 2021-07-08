/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:09:22 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 19:41:56 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form {

public:

	ShrubberyCreationForm( std::string target );
	virtual ~ShrubberyCreationForm(){};
	ShrubberyCreationForm ( ShrubberyCreationForm const & src );

	std::string const	getTree() const;

private:

	int					executeAction() const;

	static std::string const	_tree;

};

#endif