/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:29:18 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/04 15:51:28 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm( "shrubbery creation", 145, 137), _target("default")
{
	std::cout << BLUE_T << "ShrubberyCreationForm default constructor called" << DEFAULT_T << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ): AForm( "shrubbery creation", 145, 137), _target(target)
{
	std::cout << BLUE_T << "ShrubberyCreationForm constructor called" << DEFAULT_T << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ): AForm( "shrubbery creation", 145, 137)
{
	std::cout << BLUE_T << "ShrubberyCreationForm copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << PURPLE_T << "ShrubberyCreationForm destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src )
{
	std::cout << YELLOW_T << "ShrubberyCreationForm assignation operator called" << DEFAULT_T << std::endl;

	if (this != &src)
		this->_target = src._target;

	return (*this);
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

const std::string	&ShrubberyCreationForm::getTarget( void ) const {return (this->_target);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw (FormIsNotSigned());
	else if (executor.getGrade() > this->getGradeForExecute())
		throw (GradeTooLowException());

	std::ofstream	out_file((this->_target + "_shrubbery").c_str());

	if (!out_file.is_open())
		throw (FileNotOpenException());

	out_file << "            .        +          .      .          ." << std::endl;
	out_file << "     .            _        .                    ." << std::endl;
	out_file << "  ,              /;-._,-.____        ,-----.__" << std::endl;
	out_file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
	out_file << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
	out_file << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
	out_file << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
	out_file << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
	out_file << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
	out_file << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
	out_file << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
	out_file << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
	out_file << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
	out_file << "                    \\::.  :\\/:'  /              +" << std::endl;
	out_file << "   .                 `.:.  /:'  }      ." << std::endl;
	out_file << "           .           ):_(:;   \\           ." << std::endl;
	out_file << "                      /:. _/ ,  |" << std::endl;
	out_file << "                   . (|::.     ,`                  ." << std::endl;
	out_file << "     .                |::.    {\\" << std::endl;
	out_file << "                      |::.\\  \\ `." << std::endl;
	out_file << "                      |:::(\\    |" << std::endl;
	out_file << "              O       |:::/{ }  |                  (o" << std::endl;
	out_file << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
	out_file << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
	out_file << "      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;

	out_file.close();
}


/* ************************************************************************** */
/*                                 Exceptions                                 */
/* ************************************************************************** */

const char	*ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return ("file not open");
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &o, const ShrubberyCreationForm &src )
{
	o << "Form name: " << src.getName();
	o << ", target: " << src.getTarget();
	o << ", grade required to sign: " << src.getGradeForSigned();
	o << ", grade required to execute: " << src.getGradeForExecute();
	o << ", signed: " << src.getSigned() << std::endl;

	return (o);
}
