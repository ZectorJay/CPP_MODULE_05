/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:41:32 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/08 18:57:41 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main(){
	try {
		Intern noob;
		Form *newForm = noob.makeForm("shrubbery request", "banana");
		Bureaucrat Hermes("Hermes Conrad", 5);
		Hermes.SignForm(*newForm);
		Hermes.executeForm(*newForm);
		
		delete newForm;
		newForm = noob.makeForm("robotomy request", "bender");
	
		Hermes.SignForm(*newForm);
		Hermes.executeForm(*newForm);
	
		delete newForm;
		newForm = noob.makeForm("random request", "haha");

		Hermes.SignForm(*newForm);
		Hermes.executeForm(*newForm);
		delete newForm;
	} catch (std::exception & e) {
		std::cout<<e.what()<<std::endl;
	}
}