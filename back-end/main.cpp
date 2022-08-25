#include <iostream>
#include <fstream>
#include <string>

//how to get and put input from/into file
std::string userInput;
std::ifstream f_read;
std::ofstream f_write;
bool isError = true;

//list of functions

std::string GetUserChoice();
void Error();
bool Find();
void WelcomePage();
void LogIn();
void SignUp();
void NewUsername();
void NewPassword();
int main();


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
  std::cout << "            Welcome! " << std::endl
            << "(A) Log In            (B) New User Sign Up " << std::endl;

  GetUserChoice();
  
  //while(isError){   FIXME integrate error system
    if(userInput == "a"){
      LogIn();
    }

    else if(userInput == "b"){
      SignUp();
    }

    else{
      Error("Invalid input");
    }
  //}
}

void LogIn(){
  std::cout << "Enter username: " << std::endl;
  std::string username;
  std::string password;
  std::cin >> username;

  bool foundUsername = Find(username);

  if(!foundUsername){
    Error("Username does not exist");
  }
  else{
    std::cout << "Enter password: ";
    std::cin >> password;

    bool foundPasswordOfUsername = Find(password);

    if(!foundPasswordOfUsername){
      Error("Incorrect password");
    }
    else{
      std::cout << "Succefully logged in!" << std::endl;
    }
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
    Error("Username already exists");
  }

  else{
    //FIXME write new username into file
    f_write << newUsername;
    NewPassword();
  }

}
void NewPassword(){
  std::cout << "Create password: ";
  std::string newPassword;
  std::cin >> newPassword;
  //FIXME write new password into file
  f_write << newPassword;

  std::cout << "New account created!" << std::endl;

  main();

}

int main() {
  
  f_read.open("storage.txt");
  f_write.open("storage.txt");
  if(!(f_read.is_open())){
    std::cout << "File not found!" << std::endl;
    return 1;
  }

  WelcomePage();

  //how to make it return back here?
  //should return here
  //what format should the file be in?
  f_read.close();
  f_write.close();

}
