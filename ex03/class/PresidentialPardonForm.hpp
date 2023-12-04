/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:31:11 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/04 14:57:19 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define BLUE_T "\033[34m"
# define PURPLE_T "\033[35m"

class PresidentialPardonForm: public AForm
{
	public:

		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm &src );
		PresidentialPardonForm( const std::string &target );
		~PresidentialPardonForm( void );

		PresidentialPardonForm	&operator=( const PresidentialPardonForm &src );

		const std::string	&getTarget( void ) const;

		void	execute(Bureaucrat const &executor) const;

	private:

		std::string	_target;
};

std::ostream	&operator<<( std::ostream &o, const PresidentialPardonForm &src );

#endif
