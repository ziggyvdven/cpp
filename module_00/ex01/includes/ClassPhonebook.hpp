/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:05:14 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/02/29 17:14:26 by zvan-de-         ###   ########.fr       */
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
    int  maxcontacts(std::string command) const;
    void	add(int i);
    void  search() const;
    void	display(int i) const;
    std::string	get_entry(std::string msg) const;
    std::string truncate(std::string string) const;

  private:
    Contact contacts[8];
};

#endif