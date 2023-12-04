/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:29:19 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/04 14:57:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

# define BLUE_T "\033[34m"
# define PURPLE_T "\033[35m"

class ShrubberyCreationForm: public AForm
{
	public:

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm &src );
		ShrubberyCreationForm( const std::string &target );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &src );

		const std::string	&getTarget( void ) const;

		void	execute(Bureaucrat const &executor) const;

		class FileNotOpenException: public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};

	private:

		std::string	_target;
};

std::ostream	&operator<<( std::ostream &o, const ShrubberyCreationForm &src );

#endif
