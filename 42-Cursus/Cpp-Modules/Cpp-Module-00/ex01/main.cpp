/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:36:32 by wabolles          #+#    #+#             */
/*   Updated: 2025/03/03 01:42:46 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		main(int ac, char __attribute__ ((unused)) *av[])
{
	std::string	command;
	PhoneBook	Fb;
	int			contact_index = 0, check_replace = 0;

	if (ac > 1)
	<%
		std::string error_msg = "\033[31mPLEASE RUN THE EXECUTABLE WITHOUT ARGUMENTS !\033[0m";
		for (int i = 0; i < 57;i++)
		{
			write(1, &error_msg[i], 1);
			usleep(10000);
		}
		sleep(3);
		return (EXIT_FAILURE);
	%>
	for (;;)
	<%
		std::cout << "\033[30mNB\033[34m-2.1\033[32m$\033[0m ";
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
			return (EXIT_SUCCESS);
		else if (command == "ADD")
		{
			if (contact_index == 8)
			<%
				check_replace = 1;
				contact_index = 0;
			%>
			Fb.add_command(&Fb, contact_index);
			contact_index++;
		}
		else if (command == "SEARCH")
			Fb.search_command(&Fb, contact_index, check_replace);
		else std::cout << "NB: " << command << ": command not found\n";
	%>
}

void	__attribute__ ((constructor)) _begin(void)
{
	system("clear");
	for (int i = 0; i < 50; i++)
	{
		write(1, ".", 1);
		usleep(8000);
	}
	system("clear");
	std::cout << " ___________________________________________";
	std::cout << "\n/                                           \\\n";
	std::cout << "\\ ! Welcome To The 📞 NumberBook Software ! /\n";
	std::cout << " \\_________________________________________/\n\n";
	std::cout << "\033[30mDeveloped by \033[34mwabolles\033[0m\t\t \n\n";
	
}

void	__attribute__ ((destructor)) _end(void)
{
	system("clear");
	std::string output = "                                                 ";
	
	for (int i = 50; i >= 0; i--)
	{
		output[i] = '.';
		for (int i = 0; i < 50; i++) write(1, &output[i], 1);
		usleep(8000);
		system("clear");
	}
	
	system("clear");
	usleep(50000);
	std::cout << "GoodBye 👋\n";
}