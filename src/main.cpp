#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <bitset>

#include "types.h"
#include "loader.h"

using namespace std;

int main(int argc, char *argv[])
{

  Loader::Header header;
  
  Loader::loadRom("Super Mario Bros.nes", &header);
  Loader::loadRom("Mega Man (USA).nes");
  Loader::loadRom("Castlevania (USA).nes");

  cout << "=====" << endl;
  cout << (header.region ? "PAL" : "NTSC") << endl;
  
  return 0;
}
