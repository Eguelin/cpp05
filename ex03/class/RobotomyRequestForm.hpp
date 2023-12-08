/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:29:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/07 16:06:17 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <sys/time.h>

# define BLUE_T "\033[34m"
# define PURPLE_T "\033[35m"

class RobotomyRequestForm: public AForm
{
	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm &src );
		RobotomyRequestForm( const std::string &target );
		~RobotomyRequestForm( void );

		RobotomyRequestForm	&operator=( const RobotomyRequestForm &src );

		const std::string	&getTarget( void ) const;

		void	execute(Bureaucrat const &executor) const;

	private:

		std::string	_target;
};

std::ostream	&operator<<( std::ostream &o, const RobotomyRequestForm &src );

#endif
