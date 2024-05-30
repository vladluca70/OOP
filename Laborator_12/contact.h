#ifndef CONTACT_H
#define CONTACT_H

#include <bits/stdc++.h>


enum class ContactType
{
    FRIEND,
    ACQUAINTANCE,
    COLLEAGUE
};

class Contact
{
protected:
    std::string name;
public:
    Contact(const std::string& name) : name(name) {}
    virtual ~Contact() = default;

    std::string getName() const
    {
        return name;
    }
    virtual ContactType getType() const = 0;
};

class Friend : public Contact
{
    std::string dateOfBirth;
    std::string phoneNumber;
    std::string address;
public:
    Friend(const std::string& name, const std::string& dob, const std::string& phone, const std::string& addr)
        : Contact(name), dateOfBirth(dob), phoneNumber(phone), address(addr) {}

    ContactType getType() const override
    {
        return ContactType::FRIEND;
    }

    std::string getDateOfBirth() const
    {
        return dateOfBirth;
    }
    std::string getPhoneNumber() const
    {
        return phoneNumber;
    }
    std::string getAddress() const
    {
        return address;
    }
};

class Acquaintance : public Contact
{
    std::string phoneNumber;
public:
    Acquaintance(const std::string& name, const std::string& phone)
        : Contact(name), phoneNumber(phone) {}

    ContactType getType() const override
    {
        return ContactType::ACQUAINTANCE;
    }

    std::string getPhoneNumber() const
    {
        return phoneNumber;
    }
};

class Colleague : public Contact
{
    std::string phoneNumber;
    std::string company;
    std::string address;
public:
    Colleague(const std::string& name, const std::string& phone, const std::string& company, const std::string& addr)
        : Contact(name), phoneNumber(phone), company(company), address(addr) {}

    ContactType getType() const override
    {
        return ContactType::COLLEAGUE;
    }

    std::string getPhoneNumber() const
    {
        return phoneNumber;
    }
    std::string getCompany() const
    {
        return company;
    }
    std::string getAddress() const
    {
        return address;
    }
};

class AddressBook
{
    std::vector<Contact*> contacts;
public:
    ~AddressBook()
    {
        for (auto contact : contacts)
        {
            delete contact;
        }
    }

    void addContact(Contact* contact)
    {
        contacts.push_back(contact);
    }

    void deleteContact(const std::string& name)
    {
        contacts.erase(std::remove_if(contacts.begin(), contacts.end(),
                                      [&](Contact* contact)
        {
            return contact->getName() == name;
        }), contacts.end());
    }

    Contact* searchContact(const std::string& name) const
    {
        for (auto contact : contacts)
        {
            if (contact->getName() == name)
            {
                return contact;
            }
        }
        return nullptr;
    }

    std::vector<Friend*> getFriends() const
    {
        std::vector<Friend*> friends;
        for (auto contact : contacts)
        {
            if (contact->getType() == ContactType::FRIEND)
            {
                friends.push_back(static_cast<Friend*>(contact));
            }
        }
        return friends;
    }
};

#endif // CONTACT_H

