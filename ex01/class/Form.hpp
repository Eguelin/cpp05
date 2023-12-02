/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:17:38 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/02 19:17:26 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

		Form( void );
		Form( const std::string &name, int gradeForSigned, int gradeForExecute);
		Form( const Form &src );
		~Form( void );

		Form	&operator=( const Form &src );

		const std::string	&getName( void ) const;
		bool				getSigned( void ) const;
		int					getGradeForSigned( void ) const;
		int					getGradeForExecute( void ) const;

		void	beSigned( const Bureaucrat &bureaucrat );

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
		bool				_signed;
		const int			_gradeForSigned;
		const int			_gradeForExecute;
};

std::ostream	&operator<<( std::ostream &o, const Form &src );

#endif
