/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:17:38 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/03 17:03:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

AForm::AForm( void ): _name("default"), _signed(false), _gradeForSigned(1), _gradeForExecute(1)
{
	std::cout << GREEN_T << "AForm default constructor called" << DEFAULT_T << std::endl;
}

AForm::AForm( const std::string &name, int gradeForSigned, int gradeForExecute): _name(name), _signed(false), _gradeForSigned(gradeForSigned), _gradeForExecute(gradeForExecute)
{
	std::cout << GREEN_T << "AForm constructor called" << DEFAULT_T << std::endl;

	if (gradeForSigned < 1)
		throw (GradeTooHighException());
	else if (gradeForSigned > 150)
		throw (GradeTooLowException());

	if (gradeForExecute < 1)
		throw (GradeTooHighException());
	else if (gradeForExecute > 150)
		throw (GradeTooLowException());
}

AForm::AForm( const AForm &src ): _name(src._name), _gradeForSigned(src._gradeForSigned), _gradeForExecute(src._gradeForExecute)
{
	std::cout << RED_T << "AForm copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

AForm::~AForm( void )
{
	std::cout << RED_T << "AForm destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

AForm	&AForm::operator=( const AForm &src )
{
	std::cout << YELLOW_T << "AForm assignation operator called" << DEFAULT_T << std::endl;

	if (this != &src && this->_gradeForSigned >= src._gradeForSigned)
		this->_signed = src._signed;

	return (*this);
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

const std::string	&AForm::getName( void ) const {return(this->_name);}

bool	AForm::getSigned( void ) const {return(this->_signed);}

int	AForm::getGradeForSigned( void ) const {return(this->_gradeForSigned);}

int	AForm::getGradeForExecute( void ) const {return(this->_gradeForExecute);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	AForm::beSigned( const Bureaucrat &bureaucrat )
{
	if (this->_signed == true)
		throw (FormIsSigned());
	else if (bureaucrat.getGrade() > this->_gradeForSigned)
		throw (GradeTooLowException());

	this->_signed = true;
}

/* ************************************************************************** */
/*                                 Exceptions                                 */
/* ************************************************************************** */

const char	*AForm::GradeTooHighException::what( void ) const throw()
{
	return ("grade too high");
}

const char	*AForm::GradeTooLowException::what( void ) const throw()
{
	return ("grade too low");
}

const char	*AForm::FormIsSigned::what( void ) const throw()
{
	return("the form is already signed");
}

const char	*AForm::FormIsNotSigned::what( void ) const throw()
{
	return("the form is not signed");
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const AForm &src )
{
	o << "AForm: " << src.getName();
	o << ", signed: " << src.getSigned();
	o << ", grade for signed: " << src.getGradeForSigned();
	o << ", grade for execute: " << src.getGradeForExecute() << std::endl;

	return (o);
}
