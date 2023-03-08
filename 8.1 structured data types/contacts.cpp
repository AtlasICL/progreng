#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

struct Contact{
  std::string fn;
  std::string ln;
  std::string email;
  std::string number;
};

void print_vector_Contact(const std::vector<Contact> vin){
  for (int i=0; i < vin.size(); i++){

    std::cout << "(" << vin[i].fn << " " << vin[i].ln << " " << vin[i].email << " " << vin[i].number << ")" << std::endl;
  }
}

int search_contact(const std::vector<Contact>& contacts, std::string first_name, std::string surname){

  int i = 0;
  while (i < contacts.size()){

    if (contacts[i].fn == first_name && contacts[i].ln == surname){
      return i;
    }
    i += 1; 
  }
  return -1;
}


int main(){

  std::ifstream infile;
  infile.open("Contacts.txt");
  
  if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

  std::vector<Contact> contacts_list;
  
  Contact tmp;
  while (infile >> tmp.fn >> tmp.ln >> tmp.email >> tmp.number){
    contacts_list.push_back(tmp);
  }

  infile.close();

  print_vector_Contact(contacts_list);

  int index = -2;
  index = search_contact(contacts_list, "Alfred", "Whitehead");
  std::cout << index;
  
}