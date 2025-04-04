#include <string>
#include <sstream>
using namespace std;
class MYGPIO {
  private:
  int number;
  string name,path;
  void write(string filename, string value);
  void write(string filename, int value);
  string read(string filename);
  stringstream stream;

  public:
  MYGPIO(int number);
  int getNumber();
  void setDirection(string dir);
  string getDirection();
  void setValue(int val);
  string getValue();
  void toggleOutput();
  void toggleOutputNumberOfTimes(int n, int delay);
  ~MYGPIO();
  public:
  };
