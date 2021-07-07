/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:36:26 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 16:27:54 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class RobotomyRequestForm : public Form {

public:

	RobotomyRequestForm( std::string target );
	~RobotomyRequestForm() {}
	
};

#endif