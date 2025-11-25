#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cctype>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Contact
{
	private :
		int index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string dark_secret;
	public :
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phone_number() const;
		std::string get_dark_secret() const;
		int get_index() const;
		void set_index(int i);
		void set_first_name(std::string str);
		void set_last_name(std::string str);
		void set_nickname(std::string str);
		void set_phone_number(std::string str);
		void set_dark_secret(std::string str);
};

class Phonebook
{
	private :
		Contact contacts[8];
		int	size;
	public :
		Phonebook();
		void add_contact();
		void search_contact();
};

#endif