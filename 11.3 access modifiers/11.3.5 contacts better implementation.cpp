#include <iostream>
#include <vector>
#include <fstream>

class Contact{

public:

  Contact(){

  }

  Contact(std::string fn, std::string ln, std::string em, std::string num) : firstName(fn), lastName(ln), email(em), number(num) {

  }

  std::string getFirstName() const {
    return firstName;
  }

  std::string getLastName() const {
    return lastName;
  }

  std::string to_str() const {
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

int searchContacts(const std::vector<Contact>& contacts, std::string fn, std::string ln){

  for (int i = 0; i<contacts.size(); i++){
    
    if (contacts[i].getFirstName() == fn && contacts[i].getLastName() == ln){
      return i;
    }
    
  }

  return -1;
  
}

int main(){

  std::ifstream infile;
  std::string fileName;
  std::cin >> fileName;

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

  int search = searchContacts(vin, "Alexander", "Fleming");
  std::cout << search;

  
}