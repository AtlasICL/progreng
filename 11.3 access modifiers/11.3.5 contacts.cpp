#include <iostream>
#include <vector>
#include <fstream>

class Contact{

public:

    Contact(){

    }

    Contact(std::string fn, std::string ln, std::string em, std::string num) : firstName(fn), lastName(ln), email(em), number(num) {

    }

    static std::vector<Contact> getContactsFromFile(std::string fileName){
        std::ifstream infile;
        infile.open(fileName);
        if (!infile.is_open()){
            std::cout << "failed to open file";
            EXIT_FAILURE;
        }

        std::string fn;
        std::string ln;
        std::string e;
        std::string num;

        std::vector<Contact> vin;

        while (infile >> fn >> ln >> e >> num){
        Contact tmp(fn, ln, e, num);
        vin.push_back(tmp);
        }

        for (int i = 0; i<vin.size(); i++){
        vin[i].print();
        }

        return vin;
    }

    std::string getFirstName() const {
        return firstName;
    }

    std::string getLastName() const {
        return lastName;
    }

    std::string getEmail() const {
        return email;
    }

    std::string getNumber() const {
        return number;
    }

    std::string setFirstName(std::string newFirstName){
        firstName = newFirstName;
    }

    std::string setLastName(std::string newLastName){
        lastName = newLastName;
    }

    std::string setEmail(std::string newEmail){
        email = newEmail;
    }

    std::string setNumber(std::string newNum){
        number = newNum;
    }

    void print() const {
        std::cout << "{ " << "First Name: " << firstName << std::endl;
        std::cout << "Last Name: " << lastName << std::endl;
        std::cout << "email: " << email << std::endl;
        std::cout << "number: " << number << " }" << std::endl;
    }

private:

    std::string firstName;
    std::string lastName;
    std::string email;
    std::string number;

};

int main(){

    std::vector<Contact> vout;

    vout = Contact::getContactsFromFile("D://Programming//Spring term//11.7 access modifiers//contacts_list.txt");
}