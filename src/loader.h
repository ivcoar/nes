#pragma once

#include "types.h"

namespace Loader
{

  struct Header
  {
    union
    {
      ubyte raw[16];               // Raw byte acces
      struct
      {
	ubyte b0;
	ubyte b1;
	ubyte b2;
	ubyte b3;
	ubyte romBanks;            // Number of 16kB ROM banks
	ubyte vromBanks;           // Number of 8kB VROM banks
	union
	{
	  ubyte flags6;
	  struct
	  {
	    ubyte mirroring:1,     // 1 for vertical mirroring, 0 for horizontal mirroring
	      battery:1,           // 1 for battery-backed RAM at $6000-$7FFF
	      trainer:1,           // 1 for a 512-byte trainer at $7000-$71FF
	      fourScreens:1,       // 1 for a four-screen VRAM layout
	      mapperLow:4;         // Four lower bits of ROM Mapper Type
	  };
	};
	union
	{
	  ubyte flags7;
	  struct
	  {
	    ubyte vs:1,            // 1 for VS-System cartridges
	      :3,                  // Reserved, must be zeroes!
	      mapperHigh:4;        // Four higher bits of ROM Mapper Type
	  };
	};
	ubyte ramBanks;
	ubyte region;              // 1 for PAL cartridges, otherwise assume NTSC
      };
    };
  };
 

  bool loadRom(const char* name);
  bool loadRom(const char* name, Header* header);
  
}
