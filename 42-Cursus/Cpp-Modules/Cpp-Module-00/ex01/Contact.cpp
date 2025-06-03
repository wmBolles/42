/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:50:11 by wabolles          #+#    #+#             */
/*   Updated: 2025/02/22 15:45:11 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_First_name(std::string first_name)
{	
	Contact::First_name = first_name;
}

std::string Contact::get_First_name()
{	
	return Contact::First_name;
}

void Contact::set_Last_name(std::string last_name)
{	
	Contact::Last_name = last_name;
}

std::string Contact::get_Last_name()
{	
	return Contact::Last_name;
}

void Contact::set_Nickname(std::string nickname)
{	
	Contact::Nickname = nickname;
}

std::string Contact::get_Nickname()
{	
	return Contact::Nickname;
}

void Contact::set_Phone_number(std::string phone_number)
{	
	Contact::Phone_number = phone_number;
}

std::string Contact::get_Phone_number()
{	
	return Contact::Phone_number;
}

void Contact::set_Darkest_secret(std::string darkest_secret)
{	
	Contact::Darkest_secret = darkest_secret;
}

std::string Contact::get_Darkest_secret()
{	
	return Contact::Darkest_secret;
}