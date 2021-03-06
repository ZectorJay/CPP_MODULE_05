/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:32:41 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 19:59:04 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
Form( target, "PresidentalPardonForm", 25, 5) {}

int			PresidentialPardonForm::executeAction() const {
	std::cout<<YELLOW<<this->getTarget();
	std::cout<<" has been pardoned by Zafod Beeblebrox";
	std::cout<<RESET<<std::endl;
	return (1);
}