/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:20:35 by wabolles          #+#    #+#             */
/*   Updated: 2025/03/07 22:11:45 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int		check_If_Str_Is_Valid(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isprint(str[i]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		check_if_number_is_valid(std::string nb)
{
	size_t	i = 0;
	short	check_dup_symbol = 0;

	if (nb[0] == '+' && nb.length() > 1)
		i++;
	for (; i < nb.length(); i++)
	{
		if (!std::isdigit(nb[i]) && !std::isspace(nb[i]) && nb[i] != '-')
			return (EXIT_FAILURE);
		if (nb[i] == '-') check_dup_symbol++;
		if (nb[i] == '-' && (!std::isdigit(nb[i - 1]) || !std::isdigit(nb[i + 1])))
			return (EXIT_FAILURE);
	}
	if (nb[i - 1] == '-') return (EXIT_FAILURE);
	if (check_dup_symbol > 1) return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void PhoneBook::add_command(PhoneBook *Fb, int index)
{
	std::string	First_name;
	std::string	Last_name;
	std::string	Nickname;
	std::string	Phone_number;
	std::string	Darkest_secret;

	for (;;)
	<%
		std::cout << "Firstname: ";
		std::getline(std::cin, First_name);
		if (First_name == "\0" || check_If_Str_Is_Valid(First_name) == 2)
			std::cout << "The First_name Is Empty !\n";
		else if (check_If_Str_Is_Valid(First_name))
			std::cout << "The FirstName Is Not Valid !\n";
		else
		{
			Fb->contacts[index].set_First_name(First_name);
			break ;
		}
		if (std::cin.eof()) exit (EXIT_SUCCESS);
	%>

	for (;;)
	<%
		std::cout << "Last_name: ";
		std::getline(std::cin, Last_name);
		if (Last_name == "\0" || check_If_Str_Is_Valid(Last_name) == 2)
			std::cout << "The Last_name Is Empty !\n";
		else if (check_If_Str_Is_Valid(Last_name))
			std::cout << "The Last_name Is Not Valid !\n";
		else
		{
			Fb->contacts[index].set_Last_name(Last_name);
			break ;
		}
		if (std::cin.eof()) exit (EXIT_SUCCESS);
	%>

	for (;;)
	<%
		std::cout << "Nickname: ";
		std::getline(std::cin, Nickname);
		if (Nickname == "\0" || check_If_Str_Is_Valid(Nickname) == 2)
			std::cout << "The Nickname Is Empty !\n";
		else if (check_If_Str_Is_Valid(Nickname))
			std::cout << "The Nickname Is Not Valid !\n";
		else
		{
			Fb->contacts[index].set_Nickname(Nickname);
			break ;
		}
		if (std::cin.eof()) exit (EXIT_SUCCESS);
	%>
	for (;;)
	<%
		std::cout << "Phone_number: ";
		std::getline(std::cin, Phone_number);
		if (Phone_number == "\0" || check_If_Str_Is_Valid(Phone_number) == 2)
			std::cout << "The Phone_number Is Empty !\n";
		else if (check_If_Str_Is_Valid(Phone_number))
			std::cout << "The Phone_number Is Not Valid !\n";
		else if (check_if_number_is_valid(Phone_number))
			std::cout << "The Phone_number Is Not Valid !\n";
		else
		{
			Fb->contacts[index].set_Phone_number(Phone_number);
			break ;
		}
		if (std::cin.eof()) exit (EXIT_SUCCESS);
	%>

	for (;;)
	<%
		std::cout << "Darkest_secret: ";
		std::getline(std::cin, Darkest_secret);
		if (Darkest_secret == "\0")
			std::cout << "The Darkest_secret Is Empty !\n";
		else if (check_If_Str_Is_Valid(Darkest_secret))
			std::cout << "The Darkest_secret Is Not Valid !\n";
		else
		{
			Fb->contacts[index].set_Darkest_secret(Darkest_secret);
			break ;
		}
		if (std::cin.eof()) exit (EXIT_SUCCESS);
	%>
	return ;
}

void	display_header(void)
{
	std::cout << " ";
	for (int i = 0; i < 43; i++)<% std::cout << "_"; %>
	std::cout  << std::endl << "|" << "   Index  " << "|";
	std::cout  << " FirstName" << "|";
	std::cout  << " LastName " << "|";
	std::cout  << " NickName " << "|" << std::endl << "|";
	for (int i = 0; i < 43; i++)<% std::cout << "-"; %>
	std::cout << "|" << std::endl;
}

void	PhoneBook::display_contact_info(PhoneBook *Fb, int index)
{
	std::cout << "|";
	std::cout << "     " << index << "    |";
	
	std::cout << Fb->contacts[index].get_First_name().substr(0, 9);
	if (Fb->contacts[index].get_First_name().length() > 9) std::cout << ".";
	else
	{
		for (size_t i = 0; i < (10 - Fb->contacts[index].get_First_name().length()); i++)
			std::cout << " ";
	}
	std::cout << "|";
	std::cout << Fb->contacts[index].get_Last_name().substr(0, 9);
	if (Fb->contacts[index].get_Last_name().length() > 9) std::cout << ".";
	else
	{
		for (size_t i = 0; i < (10 - Fb->contacts[index].get_Last_name().length()); i++)
		std::cout << " ";
	}
	std::cout << "|";
	std::cout << Fb->contacts[index].get_Nickname().substr(0, 9);
	if (Fb->contacts[index].get_Nickname().length() > 9) std::cout << ".";
	else
	{
		for (size_t i = 0; i < (10 - Fb->contacts[index].get_Nickname().length()); i++)
			std::cout << " ";
	}
	std::cout << "|";
	std::cout << std::endl;
}

void	PhoneBook::display_body(PhoneBook *Fb)
{
	for (int index = 0; index < 8; index++)
		display_contact_info(Fb, index);
}

void	display_footer(void)
{
	std::cout << "|";
	for (int i = 0; i < 43; i++)<% std::cout << "_"; %>
	std::cout << "|" << std::endl;
}

void	PhoneBook::display_data(PhoneBook *Fb, int check_empty)
{
	display_header();
	display_body(Fb);
	if (check_empty == 0)
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|            No Contacts Found !            |" << std::endl;
	}
	display_footer();
}

void PhoneBook::get_contact_by_index(PhoneBook *Fb, int index)
{
	for (int i = 0; i < 45; i++)<% std::cout << "-"; %>
	std::cout << std::endl;
	std::cout << "\033[32mFirst_Name: \033[0m" << Fb->contacts[index].get_First_name() << std::endl;
	std::cout << "\033[32mLast_Name: \033[0m" << Fb->contacts[index].get_Last_name() << std::endl;
	std::cout << "\033[32mNickName: \033[0m" << Fb->contacts[index].get_Nickname() << std::endl;
	std::cout << "\033[32mPhone_Number: \033[0m" << Fb->contacts[index].get_Phone_number() << std::endl;
	std::cout << "\033[32mDark_secret: \033[0m" << Fb->contacts[index].get_Darkest_secret() << std::endl;
	for (int i = 0; i < 45; i++)<% std::cout << "-"; %>
	std::cout << std::endl;
}

void PhoneBook::search_command(PhoneBook *Fb, int index, int check_replace)
{
	std::string which_contact;
	int		contact_index = 0;
	
	display_data(Fb, index);
	if (index == 0)
		return ;
	for (;;)
	<%
		std::cout << "\nEnter The Contact index : ";
		std::getline(std::cin, which_contact);
		if (std::cin.eof())
			break ;
		if (which_contact.length() > 1 || !std::isdigit(which_contact[0]))
			std::cout << "Not A Valid Index !\n";
		else
		{
			contact_index = std::atoi(which_contact.c_str());
			if ((contact_index >= index && check_replace == 0) || contact_index > 7)
				std::cout << "Index out of range !\n";
			else
			{
				get_contact_by_index(Fb, contact_index);
				break ;
			}
		}
	%>
}