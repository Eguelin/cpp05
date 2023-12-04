/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:19:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/04 15:46:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm	*makeRobotomyRequestForm( const std::string &target );
AForm	*makePresidentialPardonForm( const std::string &target );
AForm	*makeShrubberyCreationForm( const std::string &target );

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Intern::Intern( void )
{
	std::cout << GREEN_T << "Intern default constructor called" << DEFAULT_T << std::endl;
}

Intern::Intern( const Intern &src )
{
	std::cout << GREEN_T << "Intern copy constructor called" << DEFAULT_T << std::endl;

	(void)src;
}

Intern::~Intern( void )
{
	std::cout << RED_T << "Intern destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Intern	&Intern::operator=( const Intern &src )
{
	std::cout << YELLOW_T << "Intern assignation operator called" << DEFAULT_T << std::endl;

	(void)src;

	return (*this);
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

AForm	*Intern::makeForm( const std::string &name, const std::string &target ) const
{
	const std::string names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm	*(*forms[3])(const std::string &)= {&makeRobotomyRequestForm,
												&makePresidentialPardonForm,
												&makeShrubberyCreationForm};

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;

			return (forms[i](target));
		}
	}

	std::cerr << "Intern can't create " << name << std::endl;

	return (NULL);
}

/* ************************************************************************** */
/*                              Static functions                              */
/* ************************************************************************** */

AForm	*makeRobotomyRequestForm( const std::string &target )
{
	return (new RobotomyRequestForm(target));
}

AForm	*makePresidentialPardonForm( const std::string &target )
{
	return (new PresidentialPardonForm(target));
}

AForm	*makeShrubberyCreationForm( const std::string &target )
{
	return (new ShrubberyCreationForm(target));
}
