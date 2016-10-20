#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

typedef unsigned char ubyte;

vector<ubyte> readRom(const char* name)
{

  ifstream romfile(name, ios::binary);
  return vector<ubyte>(istreambuf_iterator<char>(romfile), istreambuf_iterator<char>());

}

int main(int argc, char *argv[])
{

  cout << "Hello World" << endl;

  //  auto rom = readRom("Mega Man (USA).nes");
  auto rom = readRom("Super Mario Bros.nes");

  for (int i = 0; i < 5; i++) {
    cout << rom.at(i);
  }
  cout << endl;
  cout << (int) rom.at(5) << endl;
  
  return 0;
}
