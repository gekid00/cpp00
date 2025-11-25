#include "Phonebook.hpp"

int main(void)
{
	Phonebook phonebook;
	std::string input;
	while (1)
	{
		std::cout << "Enter command: " << std::endl;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return (0);
		}
		if (input.empty())
			continue;
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid command! Please enter ADD, SEARCH, or EXIT." << std::endl;
	}
	return (0);
}