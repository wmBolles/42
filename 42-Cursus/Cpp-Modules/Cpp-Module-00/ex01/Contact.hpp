/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:35:26 by wabolles          #+#    #+#             */
/*   Updated: 2025/02/23 09:48:24 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <unistd.h>

class	Contact
{
	private:
		std::string	First_name;
		std::string	Last_name;  
		std::string	Nickname;
		std::string	Phone_number;
		std::string	Darkest_secret;

	public:
		void set_First_name(std::string first_name);
		void set_Last_name(std::string Last_name);
		void set_Nickname(std::string Nickname);
		void set_Phone_number(std::string Phone_number);
		void set_Darkest_secret(std::string Darkest_secret);

		std::string get_First_name();
		std::string get_Last_name();
		std::string get_Nickname();
		std::string get_Phone_number();
		std::string get_Darkest_secret();
}; 