/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:41:32 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 19:12:43 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
	try {
		Form *newForm = new ShrubberyCreationForm("gtfo");
		Bureaucrat Hermes("Hermes Conrad", 38);
		Hermes.SignForm(*newForm);
		Hermes.executeForm(*newForm);
		delete newForm;
		newForm = new RobotomyRequestForm("Hola!");
		Hermes.SignForm(*newForm);
		Hermes.executeForm(*newForm);
		delete newForm;
	} catch (std::exception & e) {
		std::cout<<e.what()<<std::endl;
	}
}