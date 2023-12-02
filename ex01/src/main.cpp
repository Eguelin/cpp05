/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:48:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/02 19:28:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Form f1("f1", 0, 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form f1("f1", 0, 1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form f1("f1", 151, 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form f1("f1", 1, 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	{
		Form f1("f1", 1, 1);
		Bureaucrat b1("b1", 150);

		b1.signForm(f1);
	}
	std::cout << std::endl;
	{
		Form f1("f1", 150, 150);
		Bureaucrat b1("b1", 1);

		b1.signForm(f1);
		b1.signForm(f1);
	}

	return (0);
}
