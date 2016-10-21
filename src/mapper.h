#pragma once

#include "types.h"

class Cart;

class Mapper
{
public:
  Mapper(Cart* c);

  virtual ubyte read(ushort address) = 0;
  virtual void write(ushort address, ubyte val) = 0;
  
protected:
  Cart* cart;
};

class Mapper2 : public Mapper
{

public:
  Mapper2(Cart* c) : Mapper(c){}
  ubyte read(ushort address);
  void write(ushort address, ubyte val);

private:
  ubyte bank;
  
};
