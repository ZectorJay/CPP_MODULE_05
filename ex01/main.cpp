/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:41:32 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/06 09:36:32 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test( std::string name, int grade, std::string FormName, short int toSignGrade,
		short int toExecGrade){

	std::cout<<RED<<"So we gonna try to create Bureaucrat with name ";
	std::cout<<name<<" and "<<grade<<" grade"<<RESET<<std::endl;

	std::cout<<BLUE<<"And he will try to sign form "<<FormName<<" which require grade to sign ";
	std::cout<<toSignGrade<<" and "<<toExecGrade<<" grade to execute"<<RESET<<std::endl;

	try
	{
		Bureaucrat new_one(name, grade);
		Form toSign(FormName, toSignGrade, toExecGrade);
		std::cout<<new_one<<std::endl;
		new_one.SignForm(toSign);
		new_one.upGrade();
		std::cout<<"After UpGrade:\n"<<new_one<<std::endl;
		new_one.SignForm(toSign);
		new_one.downGrade();
		std::cout<<"After downGrade:\n"<<new_one<<std::endl;
	}
	catch (std::exception & e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

int main(){
	test("Hermes Conrad", 38, "C22", 120, 50);
	std::cout<<"\n\n"<<std::endl;
	test("SubZero", -1, "C58", 100, 0);
	std::cout<<"\n\n"<<std::endl;
	test("Retarded One", 150, "B52", 160, -1);
	std::cout<<"\n\n"<<std::endl;
	test("Smart One", 1, "B52", 1, 1);
	std::cout<<"\n\n"<<std::endl;
	test("Noob", 5, "A1", 4, 6);
	std::cout<<"\n\n"<<std::endl;
}