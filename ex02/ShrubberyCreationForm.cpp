/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:53:34 by hmickey           #+#    #+#             */
/*   Updated: 2021/07/07 17:10:20 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::string const ShrubberyCreationForm::_tree = ""
            "              ,@@@@@@@,\n"
            "      ,,,.   ,@@@@@@@@@,  .oo8888o.\n"
            "   ,&&&&&&&&,@@@@@@@@@@@@,888888888o\n"
            "  ,&&&&&&&&&&,@@@@@@@@@@@88888888888'\n"
            "  &&&&&&&&&&&&@@@@@@@@@@@88888888888'\n"
            "  &&&&& &&&&&&@@@ @ @@@' `8888 `888'\n"
            "  `&&  `  &&'    |.|         |'|8'\n"
            "      |.|        |.|         |'|\n"
            "      |.|        |.|         |'|\n";

ShrubberyCreationForm::ShrubberyCreationForm() : Form( "wtf" ,"ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
Form( target ,"ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src) :
Form( src.getTarget() ,"ShrubberyCreationForm", 145, 137) {}

std::string const		ShrubberyCreationForm::getTree() const { return (_tree); }

int						ShrubberyCreationForm::executeAction() const {
	std::ofstream		output;
	std::string			filename = this->getTarget();

	filename.insert(filename.length(), "_shrubbery");
	output.exceptions ( std::ifstream::badbit );
	try {
		output.open(filename);
		if (output.is_open()){
			output << _tree;
			output.close();
		} else {
			std::cout<<"Can't open file"<<std::endl;
			return (0);
		}
	}
	catch ( const std::ifstream::failure &e) {
		std::cout<<"Error during open/writing to file"<<std::endl;
		std::cout<<e.what()<<std::endl;
	}
	return (1);	
}
