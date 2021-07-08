/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:19:28 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 19:58:38 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form {

public:

	PresidentialPardonForm( std::string target );
	virtual ~PresidentialPardonForm(){}

private:

	int		executeAction() const;

};

#endif