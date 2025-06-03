/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:20:38 by wabolles          #+#    #+#             */
/*   Updated: 2025/03/03 01:14:24 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact		contacts[8];
	public:
		void	add_command(PhoneBook *Fb, int index);
		void	search_command(PhoneBook *Fb, int index, int check_replace);
		void	display_data(PhoneBook *Fb, int index);
		void	display_body(PhoneBook *Fb);
		void	display_contact_info(PhoneBook *Fb, int index);
		void	get_contact_by_index(PhoneBook *Fb, int index);
};