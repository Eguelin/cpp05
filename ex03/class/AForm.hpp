/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:17:38 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/04 14:57:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:

		AForm( void );
		AForm( const std::string &name, int gradeForSigned, int gradeForExecute);
		AForm( const AForm &src );
		virtual ~AForm( void );

		AForm	&operator=( const AForm &src );

		const std::string	&getName( void ) const;
		bool				getSigned( void ) const;
		int					getGradeForSigned( void ) const;
		int					getGradeForExecute( void ) const;

		void			beSigned( const Bureaucrat &bureaucrat );
		virtual void	execute( const Bureaucrat &executor ) const = 0;

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

		class FormIsSigned: public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		class FormIsNotSigned: public std::exception
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

std::ostream	&operator<<( std::ostream &o, const AForm &src );

#endif
