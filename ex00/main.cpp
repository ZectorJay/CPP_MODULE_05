/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:41:32 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/05 17:14:22 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
# define RED	"\033[1;38;2;250;20;20m"
# define RESET	"\033[0m"


void	test( std::string name, int grade ){
	std::cout<<RED<<"So we gonna try to create Bureaucrat with name ";
	std::cout<<name<<" and "<<grade<<" grade"<<RESET<<std::endl;
	try
	{
		Bureaucrat new_one(name, grade);
		std::cout<<new_one<<std::endl;
		new_one.downGrade();
		std::cout<<"After downGrade:\n"<<new_one<<std::endl;
	}
	catch (std::exception & e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

int main(){
	test("Hermes Conrad", 38);
	test("SubZero", -1);
	test("Retarded One", 150);
}