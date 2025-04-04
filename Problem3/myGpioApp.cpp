/* This application will create a object called gpio46 and gpio60
*These objects are of class MYGPIO and will be used to control 
*the gpio pins they correspond to
*These pins correspong to gpio46 = p8.16 and gpio60 = p9.12
*The functions used in this application and othe function in MYGPIO
*can be found in myGpio.h and implemented in myGpio.cpp
*/

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include  <thread>
#include  "myGpio.h"

using namespace std;

int main(int argc, char* argv[]){
  MYGPIO gpio46(46);
  gpio46.setDirection("in");
  MYGPIO gpio60(60);
  gpio60.setDirection("out");
  gpio60.setValue(1);
  this_thread::sleep_for(3000ms);
  gpio60.setValue(0);
  cout << "Value of p8.16 is: " << gpio46.getValue() << endl;

  


}
