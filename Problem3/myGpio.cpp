


#include "myGpio.h"
#include <string>
#include <sstream>
#include <fstream>
#define GPIO_PATH "/sys/class/gpio/gpio"

MYGPIO::MYGPIO(int num){
  stringstream ss;
  ss << GPIO_PATH << num;
  path =ss.str();
  number = num;
}

int MYGPIO::getNumber(){
  return number;
}

void MYGPIO::write(string filename, string value){
  fstream fs; 
  fs.open((path+"/"+filename).c_str(), std::fstream::out);
  fs << value << endl;
  fs.close();
}


void MYGPIO::write(string filename,int value){
  fstream fs;
  fs.open((path+"/"+filename).c_str(), std::fstream::out);
  fs << value <<endl;
  fs.close();
}

string MYGPIO::read(string filename){
  fstream ifs;
  ifs.open((path+"/"+filename).c_str(), std::ifstream::in);
  string line;
  while(getline(ifs,line)){
  stream << line << endl;
  }
  ifs.close();
  return stream.str();
}

void MYGPIO::setDirection(string dir){
  write("direction", dir);
}

string MYGPIO::getValue(){
  return read("value");
  
}

string MYGPIO::getDirection(){
  return read("direction");
  
}

void MYGPIO::setValue(int val){
  write("value",val);
}

void MYGPIO::toggleOutput(){
  if(read("value") == "1"){
    setValue(0);
  }
  else{
    setValue(1);
  }
}

void MYGPIO::toggleOutputNumberOfTimes(int n, int delay){
  int reset=delay;
  do{
  toggleOutput();
  n--;
  if(delay>0){
    delay--;
  }
  delay=reset;
}while(n>0);
}

MYGPIO::~MYGPIO(){
}
