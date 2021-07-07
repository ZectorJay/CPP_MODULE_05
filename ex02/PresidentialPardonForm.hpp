/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:19:28 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 19:39:44 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP
# include "Form.hpp"

class Form;

class PresidentalPardonForm : public Form {

public:

	PresidentalPardonForm( std::string target );
	virtual ~PresidentalPardonForm(){}

private:

	int		executeAction() const;

};

#endif