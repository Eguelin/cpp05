/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:17:38 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/02 19:28:43 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Form::Form( void ): _name("default"), _signed(false), _gradeForSigned(1), _gradeForExecute(1)
{
	std::cout << GREEN_T << "Form default constructor called" << DEFAULT_T << std::endl;
}

Form::Form( const std::string &name, int gradeForSigned, int gradeForExecute): _name(name), _signed(false), _gradeForSigned(gradeForSigned), _gradeForExecute(gradeForExecute)
{
	std::cout << GREEN_T << "Form constructor called" << DEFAULT_T << std::endl;

	if (gradeForSigned < 1)
		throw (GradeTooHighException());
	else if (gradeForSigned > 150)
		throw (GradeTooLowException());

	if (gradeForExecute < 1)
		throw (GradeTooHighException());
	else if (gradeForExecute > 150)
		throw (GradeTooLowException());
}

Form::Form( const Form &src ): _name(src._name), _gradeForSigned(src._gradeForSigned), _gradeForExecute(src._gradeForExecute)
{
	std::cout << RED_T << "Form copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

Form::~Form( void )
{
	std::cout << RED_T << "Form destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Form	&Form::operator=( const Form &src )
{
	std::cout << YELLOW_T << "Form assignation operator called" << DEFAULT_T << std::endl;

	this->_signed = src._signed;

	return (*this);
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

const std::string	&Form::getName( void ) const {return(this->_name);}

bool	Form::getSigned( void ) const {return(this->_signed);}

int	Form::getGradeForSigned( void ) const {return(this->_gradeForSigned);}

int	Form::getGradeForExecute( void ) const {return(this->_gradeForExecute);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	Form::beSigned( const Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() > this->_gradeForSigned)
		throw (GradeTooLowException());

	this->_signed = true;
}

/* ************************************************************************** */
/*                                 Exceptions                                 */
/* ************************************************************************** */

const char	*Form::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low");
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const Form &src )
{
	o << "Form: " << src.getName();
	o << ", signed: " << src.getSigned();
	o << ", grade for signed: " << src.getGradeForSigned();
	o << ", grade for execute: " << src.getGradeForExecute() << std::endl;

	return (o);
}
