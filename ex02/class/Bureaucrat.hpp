/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/03 14:03:13 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define DEFAULT_T "\033[0m"
# define RED_T "\033[31m"
# define GREEN_T "\033[32m"
# define YELLOW_T "\033[33m"

class AForm;

class Bureaucrat
{
	public:

		Bureaucrat( void );
		Bureaucrat( const std::string &name, int grade );
		Bureaucrat( const Bureaucrat &src );
		~Bureaucrat( void );

		Bureaucrat	&operator=( const Bureaucrat &src );

		const std::string	&getName( void ) const;
		int					getGrade( void ) const;

		void	incrementGrade( void );
		void	decrementGrade( void );
		void	signAForm( AForm &form );
		void	executeAForm( const AForm &form ) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};

	private:

		const std::string	_name;
		int		_grade;
};

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &src );

# include "AForm.hpp"

#endif
