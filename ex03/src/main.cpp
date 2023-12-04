/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:48:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/04 15:44:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		PresidentialPardonForm f1;
		Bureaucrat b1("b1", 150);

		b1.signAForm(f1);
	}
	std::cout << std::endl;
	{
		Intern i1;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);

		AForm *f1 = i1.makeForm("presidential pardon", "target");

		b1.executeAForm(*f1);
		b1.signAForm(*f1);
		b1.executeAForm(*f1);
		b2.executeAForm(*f1);

		delete f1;
	}
	std::cout << std::endl;
	{
		RobotomyRequestForm f1;
		Bureaucrat b1("b1", 150);

		b1.signAForm(f1);
	}
	std::cout << std::endl;
	{
		Intern i1;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);

		AForm *f1 = i1.makeForm("robotomy request", "target");

		b1.executeAForm(*f1);
		b1.signAForm(*f1);
		b1.executeAForm(*f1);
		b2.executeAForm(*f1);

		delete f1;
	}
	std::cout << std::endl;
	{
		ShrubberyCreationForm f1;
		Bureaucrat b1("b1", 150);

		b1.signAForm(f1);
	}
	std::cout << std::endl;
	{
		Intern i1;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);

		AForm *f1 = i1.makeForm("shrubbery creation", "target");

		b1.executeAForm(*f1);
		b1.signAForm(*f1);
		b1.executeAForm(*f1);
		b2.executeAForm(*f1);

		delete f1;
	}
	std::cout << std::endl;
	{
		Intern i1;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);

		AForm *f1 = i1.makeForm("test", "target");

		delete f1;
	}


	return (0);
}
