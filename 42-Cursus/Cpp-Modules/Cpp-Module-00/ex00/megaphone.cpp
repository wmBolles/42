/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:30:23 by wabolles          #+#    #+#             */
/*   Updated: 2025/03/02 21:41:15 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace libC
{
	void	strToUpper(char *s)
	<%
		while (*s)
		{
			if (std::islower(*s))
					std::cout << (char)std::toupper(*s);
			else	std::cout << *s;
			s++;
		}
	%>
}

int		main(int ac, char *av[])
{
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *", EXIT_SUCCESS);
	for (int i = 1; i < ac; i++)
		libC::strToUpper(av[i]);
	return (EXIT_SUCCESS);
}


void	__attribute__ ((destructor)) _end(void)<% std::cout << std::endl; %>