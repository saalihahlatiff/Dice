#include <iostream>
#include <fstream>
#include<string>
#include <cctype> 

//using namespace std;

std::string userInput;
std::ifstream f_read;

void GetUserInput(){
  std::cin >> userInput;
  tolower(userInput);
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

int main() {
  
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

    bool foundUsername = Find(username);

    if(!foundUsername){
      std::cout << "Error! Username does not exist" << std::endl;
    }
    
  }
  
  f_read.close()
  
}
