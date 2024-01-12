/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:05:14 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/01/12 14:32:56 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP

# include "Phonebook.hpp"
# include "ClassContact.hpp"
# include <iomanip>

class Phonebook
{
  public:
  	Phonebook(void);
	  ~Phonebook(void);
    int  maxcontacts(std::string command);
    void	add(int i);
    void  search();
    void	display(int i);
    std::string	get_entry(std::string msg);
    std::string truncate(std::string string);

  private:
    Contact contacts[8];
};

#endif