#include "Phonebook.hpp"

std::string Contact::get_first_name() const
{
	return (first_name);
}

void Contact::set_first_name(std::string str)
{
	first_name = str;
}

std::string Contact::get_last_name() const
{
	return (last_name);
}

void Contact::set_last_name(std::string str)
{
	last_name = str;
}

std::string Contact::get_nickname() const
{
	return (nickname);
}

void Contact::set_nickname(std::string str)
{
	nickname = str;
}

std::string Contact::get_phone_number() const
{
	return (phone_number);
}

void Contact::set_phone_number(std::string str)
{
	phone_number = str;
}

std::string Contact::get_dark_secret() const
{
	return (dark_secret);
}

void Contact::set_dark_secret(std::string str)
{
	dark_secret = str;
}

int Contact::get_index() const
{
	return (index);
}

void Contact::set_index(int i)
{
	index = i;
}

void Phonebook::add_contact()
{
	Contact new_contact;
	std::string input;

	while (input.empty()) // Tant que input est vide
	{
		std::cout << "Enter first name: " << std::endl;
		std::getline(std::cin, input); // Demande un input
		if (input.empty())
		{
			std::cout << "Field cannot be empty!" << std::endl;
		}
	}
	new_contact.set_first_name(input); // Assigne l'input a la class
	input = ""; // nettoyage
	while (input.empty()) // Meme principe pour chaque element
	{
		std::cout << "Enter last name: " <<  std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Field cannot be empty!" << std::endl;
		}
	}
	new_contact.set_last_name(input);
	input = "";
	while (input.empty())
	{
		std::cout << "Enter nickname: " <<  std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Field cannot be empty!" << std::endl;
		}
	}
	new_contact.set_nickname(input);
	input = "";
	while (input.empty())
	{
		std::cout << "Enter phone number: " <<  std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Field cannot be empty!" << std::endl;
		}
	}
	new_contact.set_phone_number(input);
	input = "";
	while (input.empty())
	{
		std::cout << "Enter dark secret: " <<  std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Field cannot be empty!" << std::endl;
		}
	}
	new_contact.set_dark_secret(input);
	// Stocker contact
	int index = size % 8;
	contacts[index] = new_contact;
	size++;
}

Phonebook::Phonebook()
{
	size = 0;
}

void Phonebook::search_contact()
{
	int max_contacts;
	
	if (size < 8)
		max_contacts = size;
	else
		max_contacts = 8;
	
	if (max_contacts == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}
	
	// Afficher l'en-tête du tableau
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
	
	// Afficher chaque contact
	for (int i = 0; i < max_contacts; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		
		// First name avec troncature
		std::string first = contacts[i].get_first_name();
		if (first.length() > 10)
			std::cout << std::setw(10) << std::right << first.substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << std::right << first << "|";
		
		// Last name avec troncature
		std::string last = contacts[i].get_last_name();
		if (last.length() > 10)
			std::cout << std::setw(10) << std::right << last.substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << std::right << last << "|";
		
		// Nickname avec troncature
		std::string nick = contacts[i].get_nickname();
		if (nick.length() > 10)
			std::cout << std::setw(10) << std::right << nick.substr(0, 9) + "." << std::endl;
		else
			std::cout << std::setw(10) << std::right << nick << std::endl;
	}
	
	// Demander l'index à afficher
	std::cout << "Enter index to display: ";
	std::string input;
	std::getline(std::cin, input);
	
	// Vérifier si l'input est un nombre valide
	std::stringstream ss(input);
	int index;
	if (!(ss >> index) || !(ss.eof()))
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	
	// Vérifier si l'index est dans la plage valide
	if (index < 0 || index >= max_contacts)
	{
		std::cout << "Index out of range!" << std::endl;
		return;
	}
	
	// Afficher toutes les informations du contact
	std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].get_dark_secret() << std::endl;
}
