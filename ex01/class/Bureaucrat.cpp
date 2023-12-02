/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:51 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/02 19:15:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Bureaucrat::Bureaucrat( void ): _name("default"), _grade(150)
{
	std::cout << GREEN_T << "Bureaucrat default constructor called" << DEFAULT_T << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name, int grade ): _name(name)
{
	std::cout << GREEN_T << "Bureaucrat constructor called" << DEFAULT_T << std::endl;

	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());

	this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ): _name(src._name)
{
	std::cout << GREEN_T << "Bureaucrat copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << RED_T << "Bureaucrat destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &src )
{
	std::cout << YELLOW_T << "Bureaucrat assignation operator called" << DEFAULT_T << std::endl;

	this->_grade = src._grade;

	return (*this);
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

const std::string	&Bureaucrat::getName( void ) const {return (this->_name);}

int	Bureaucrat::getGrade( void ) const {return (this->_grade);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	Bureaucrat::incrementGrade( void )
{
	if (this->_grade - 1 < 1)
		throw (GradeTooHighException());

	this->_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->_grade + 1 > 150)
		throw (GradeTooLowException());

	this->_grade++;
}

void	Bureaucrat::signForm( Form &form )
{
	if (form.getSigned())
	{
		std::cerr << this->_name << " cannot sign " << form.getName() << " because the form is already signed" << std::endl;

		return ;
	}

	try
	{
		form.beSigned(*this);

		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

/* ************************************************************************** */
/*                                 Exceptions                                 */
/* ************************************************************************** */

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low");
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &src )
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;

	return (o);
}
