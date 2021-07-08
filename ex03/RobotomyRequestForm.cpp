/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:57:16 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 19:06:20 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) :
Form (target, "RobotomyRequestForm", 72, 45) {}

int		RobotomyRequestForm::executeAction() const {
	system("./noise.sh");
	std::cout<<YELLOW<<"<"<<this->getTarget();
	std::cout<<"> has been robotomized successfully 50% of the time. ";
	std::cout<<RESET<<std::endl;
	return (1);
}