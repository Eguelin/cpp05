/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:19:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/04 14:24:28 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:

		Intern( void );
		Intern( const Intern &src );
		~Intern( void );

		Intern	&operator=( const Intern &src );

		AForm	*makeForm( const std::string &name, const std::string &target ) const;
};

#endif
