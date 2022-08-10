#include <iostream>
#include <fstream>
#include<string>

std::string userInput;
std::ifstream f_read;

std::string GetUserChoice(){
  std::cin >> userInput;
  userInput = tolower(userInput[0]);
  return userInput;
}

void Error(std::string error){
  std::cout << "Error. " << error << std::endl;
  std::cout << "Try again" << std::endl << std::endl;
  std::cin >> userInput;
}

bool Find(std::string s){
  std::string fileWord;
  while(!f_read.eof()){
    f_read >> fileWord;
    if(fileWord == s){
      return true;
    }
  }
  return false;
}

void WelcomePage(){
  if(userInput == "a"){
    SignIn();
  }

  else if(userInput == "b"){
    SignUp();
  }
}

void SignIn(){
    std::cout << "Enter username: " << std::endl;
    std::string username;
    std::cin >> username;

    bool foundUsername = Find(username);

    if(!foundUsername){
      Error("Username does not exist");
    }
}

void SignUp(){
  NewUsername();
  NewPassword();
}

void NewUsername(){
  std::cout << "Create username: ";
  std::string newUsername;
  std::cin >> newUsername;

  if(Find(newUsername)){
    Error("Username alreacy exists");
  }

}

void NewPassword(){

}

int main() {
  
  f_read.open("storage.txt");
  if(!(f_read.is_open())){
    std::cout << "File not found!" << std::endl;
    return 1;
  }

  std::cout << "            Welcome! " << std::endl
            << "(A) Log In            (B) New User Sign Up " << std::endl;

  GetUserChoice();

  WelcomePage();
    
  f_read.close();
  

}
