/* This code will set the gpio pin entered to HIGH
*
* Example invocation of this code: ./GPIO_HIGH gpio60
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define FILE_PATH "/sys/class/gpio"

int main(int argc, char* argv[]){
  if(argc!=2){
      cout << endl;
      cout << "Usage is Setting a GPIO pin to HIGH " << endl;
      cout << " e.g. ./GPIO_HIGH gpio60" << endl;
      return 2;
    }
    string cmd(argv[1]);  
    cout << "Setting pin " << argv[1] << " to HIGH" << endl;
    fstream fs;
    string path(FILE_PATH);
    fs.open((path+"/"+cmd+"/direction").c_str(), std::fstream::out);
    fs << "out" << endl;
    fs.close();
    fs.open((path+"/"+cmd+"/value").c_str(), std::fstream::out);
    fs << "1" << endl;
    fs.close();
    cout << "Pin is set to HIGH" << endl;
}
