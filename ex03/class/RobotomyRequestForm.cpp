/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:29:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/04 14:57:03 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm( void ): AForm( "robotomy request", 72, 45), _target("default")
{
	std::cout << BLUE_T << "RobotomyRequestForm default constructor called" << DEFAULT_T << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ): AForm( "robotomy request", 72, 45), _target(target)
{
	std::cout << BLUE_T << "RobotomyRequestForm constructor called" << DEFAULT_T << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ): AForm( "robotomy request", 72, 45)
{
	std::cout << BLUE_T << "RobotomyRequestForm copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << PURPLE_T << "RobotomyRequestForm destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &src )
{
	std::cout << YELLOW_T << "RobotomyRequestForm assignation operator called" << DEFAULT_T << std::endl;

	if (this != &src)
		this->_target = src._target;

	return (*this);
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

const std::string	&RobotomyRequestForm::getTarget( void ) const {return (this->_target);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw (FormIsNotSigned());
	else if (executor.getGrade() > this->getGradeForExecute())
		throw (GradeTooLowException());

	std::srand(std::time(NULL));
	if (std::rand() & 1)
	{
		std::cout << "Vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv, ";
		std::cout << "I am pleased to inform you that " << this->_target << " has been successfully robotized.";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv, ";
		std::cout << "I regret to inform you that " << this->_target << "'s robotomy has failed.";
		std::cout << std::endl;
	}
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &o, const RobotomyRequestForm &src)
{
	o << "Form name: " << src.getName();
	o << ", target: " << src.getTarget();
	o << ", grade required to sign: " << src.getGradeForSigned();
	o << ", grade required to execute: " << src.getGradeForExecute();
	o << ", signed: " << src.getSigned() << std::endl;

	return (o);
}
