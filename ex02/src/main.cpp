/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:48:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/03 16:56:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		PresidentialPardonForm f1;
		Bureaucrat b1("b1", 150);

		b1.signAForm(f1);
	}
	std::cout << std::endl;
	{
		PresidentialPardonForm f1;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);

		b1.executeAForm(f1);
		b1.signAForm(f1);
		b1.executeAForm(f1);
		b2.executeAForm(f1);

		PresidentialPardonForm f2;

		f2 = f1;

		b1.signAForm(f2);
		b1.signAForm(f2);
	}
	std::cout << std::endl;
	{
		RobotomyRequestForm f1;
		Bureaucrat b1("b1", 150);

		b1.signAForm(f1);
	}
	std::cout << std::endl;
	{
		RobotomyRequestForm f1;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);

		b1.executeAForm(f1);
		b1.signAForm(f1);
		b1.executeAForm(f1);
		b2.executeAForm(f1);

		RobotomyRequestForm f2;

		f2 = f1;

		b1.signAForm(f2);
		b1.signAForm(f2);
	}
	std::cout << std::endl;
	{
		ShrubberyCreationForm f1;
		Bureaucrat b1("b1", 150);

		b1.signAForm(f1);
	}
	std::cout << std::endl;
	{
		ShrubberyCreationForm f1;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);

		b1.executeAForm(f1);
		b1.signAForm(f1);
		b1.executeAForm(f1);
		b2.executeAForm(f1);

		ShrubberyCreationForm f2;

		f2 = f1;

		b1.signAForm(f2);
		b1.signAForm(f2);
	}

	return (0);
}
