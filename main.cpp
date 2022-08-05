#include <iostream>
#include <fstream>
#include<string>
#include <cctype> 

std::string userInput;

void GetUserInput(){
  std::cin >> userInput;
  tolower(userInput);
}

int main() {
  ifstream f_read;

  
  f_read.open("storage.txt");
  if(!(f_read.is_open())){
    std::cout << "File not found!" << std::endl;
    return 1;
  }

  std::cout << "Welcome! " << std::endl
       << "(A) Log In            (B) New User Sign Up " << std::endl;

  GetUserInput();

  if(userInput == "a"){
    std::cout << "Enter username: " << std::endl;
    std::string username;
    std::cin >> username;

    if(find(username, storage.txt) == std::string::npos){
      std::cout << "Error! Username does not exist" << std::endl;
    }
    
  }
  
  file.close()
  
}
