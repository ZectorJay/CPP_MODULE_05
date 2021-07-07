/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:41:32 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 16:55:56 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
	ShrubberyCreationForm orm("bomba");
	Bureaucrat Hermes("Hermes Conrad", 38);
	Hermes.SignForm(orm);
	Hermes.executeForm(orm);
}