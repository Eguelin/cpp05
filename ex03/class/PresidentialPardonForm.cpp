/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:31:11 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/04 14:57:07 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm( void ): AForm( "presidential pardon", 25, 5), _target("default")
{
	std::cout << BLUE_T << "PresidentialPardonForm default constructor called" << DEFAULT_T << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target ): AForm( "presidential pardon", 25, 5), _target(target)
{
	std::cout << BLUE_T << "PresidentialPardonForm constructor called" << DEFAULT_T << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ): AForm( "presidential pardon", 25, 5)
{
	std::cout << BLUE_T << "PresidentialPardonForm copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << PURPLE_T << "PresidentialPardonForm destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &src )
{
	std::cout << YELLOW_T << "PresidentialPardonForm assignation operator called" << DEFAULT_T << std::endl;

	if (this != &src)
		this->_target = src._target;

	return (*this);
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

const std::string	&PresidentialPardonForm::getTarget( void ) const {return (this->_target);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw (FormIsNotSigned());
	else if (executor.getGrade() > this->getGradeForExecute())
		throw (GradeTooLowException());

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &o, const PresidentialPardonForm &src)
{
	o << "Form name: " << src.getName();
	o << ", target: " << src.getTarget();
	o << ", grade required to sign: " << src.getGradeForSigned();
	o << ", grade required to execute: " << src.getGradeForExecute();
	o << ", signed: " << src.getSigned() << std::endl;

	return (o);
}
