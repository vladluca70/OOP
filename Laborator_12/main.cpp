#include <iostream>
#include "contact.h"

int main()
{
    AddressBook addressBook;

    addressBook.addContact(new Friend("Matei", "1990-01-01", "1234567890", "Strada Ioan Cuza"));
    addressBook.addContact(new Acquaintance("Vlad", "0987654321"));
    addressBook.addContact(new Colleague("Andrei", "5555555555", "TechCorp", "Strada Libertatii"));

    Contact* contact = addressBook.searchContact("Matei");
    if (contact)
    {
        std::cout << "Found contact: " << contact->getName() << std::endl;
    }
    else
    {
        std::cout << "Contact not found" << std::endl;
    }

    std::vector<Friend*> friends = addressBook.getFriends();
    std::cout << "Friends in address book:" << std::endl;
    for (auto friendContact : friends)
    {
        std::cout << "Name: " << friendContact->getName() << ", Date of Birth: " << friendContact->getDateOfBirth()
                  << ", Phone: " << friendContact->getPhoneNumber() << ", Address: " << friendContact->getAddress() << std::endl;
    }

    addressBook.deleteContact("Vlad");

    contact = addressBook.searchContact("Vlad");
    if (contact)
    {
        std::cout << "Contact not deleted properly: " << contact->getName() << std::endl;
    }
    else
    {
        std::cout << "Contact deleted successfully" << std::endl;
    }

    return 0;
}
