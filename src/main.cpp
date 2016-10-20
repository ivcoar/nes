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

  Loader::loadRom("Super Mario Bros.nes");
  Loader::loadRom("Mega Man (USA).nes");
  Loader::loadRom("Castlevania (USA).nes");
  
  return 0;
}
