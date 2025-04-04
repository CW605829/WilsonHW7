/* This code will turn on a LED connected to the transistor if the button is
 * pressed
* For example and executable purpose the transistor is connected to p9.12 and
* the button is connected to p8.16
* Example invocation of this code: ./LED_Button.cpp
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define FILE_PATH "/sys/class/gpio"

int main(int argc, char* argv[]){
  if(argc!=1){
      cout << endl;
      cout << "Usage is turning on a LED connected to a transistor " << endl;
      cout << " e.g. ./LED_Button.cpp" << endl;
      return 2;
    }
    fstream bfs; 
    string path(FILE_PATH);
    bfs.open((path+"/gpio46"+"/direction").c_str(), std::fstream::out);    
    bfs << "in" << endl;                  //This sets gpio pin 46 p8.16 to input
    bfs.close();
    ifstream ifs;
    string line;
    fstream lfs;
    ifs.open((path+"/gpio46"+"/value").c_str(),ifstream::in); 
    while(getline(ifs,line)) {
    cout << line << endl;   //Gets the direction of pin p8.16 and puts it into line
    fstream fs;
    fs.open((path+"/gpio60"+"/direction").c_str(), std::fstream::out);
    fs << "out" << endl;    //Sets pin p9.12 pin 60 as an output
    fs.close();
    lfs.open((path+"/gpio60"+"/value").c_str(), std::fstream::out);
    if(line=="0"){         //Reads the value from pin 46 (button) and then based
      lfs << "1" << endl;   //on the value of the button turn on or turn off LED
      cout << "LED has turned on" << endl;
    }
    else{
      lfs << "0" << endl;
      cout << "LED has turned off" << endl;
    }
    }
    lfs.close();
    ifs.close();
    
}
