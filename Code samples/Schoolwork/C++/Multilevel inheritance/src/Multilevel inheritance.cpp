//============================================================================
// Name        : Multilevel.cpp
// Author      : 15jz4
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// The output from the program compiled under gcc 3.4.4
// sizeof Base: 8
// sizeof Derived: 12
// sizeof AnotherBase: 8
// sizeof AnotherDerived: 20
// And you can run the program to get the log.txt to check its content
// =========================================================
//
// The inheritance relationship is as follow:
// class Base;
// class Derived : public Base;
// class AnotherBase;
// class AnotherDerived : public Base, public AnotherBase;
// class AnotherDerivedDerived : public AnotherDerived;
// =========================================================
//
// The following assembly code is the vtable layout for the AnotherDerived class:
// *******************
// _ZTV14AnotherDerived:
// ===== The following part is the vtable belongs to Base ===
// 	.long	0
// 	.long	_ZTI14AnotherDerived
// 	.long	_ZN14AnotherDerivedD1Ev
// 	.long	_ZN14AnotherDerivedD0Ev
// 	.long	_ZN4Base10MemberFuncEv
// ===== The following part is the vtable belongs to AnotherDerived ===
// 	.long	_ZN14AnotherDerived17AnotherMemberFuncEv
// 	.long	_ZN14AnotherDerived12MyMemberFuncEv
// ===== The following part is the vtable belongs to AnotherBase ===
// 	.long	-8
// 	.long	_ZTI14AnotherDerived
// 	.long	_ZThn8_N14AnotherDerivedD1Ev
// 	.long	_ZThn8_N14AnotherDerivedD0Ev
// 	.long	_ZThn8_N14AnotherDerived17AnotherMemberFuncEv
// 	.long	_ZN11AnotherBase18AnotherMemberFunc2Ev
// =========================================================
//
// The following assembly code is the vtable layout for the AnotherDerivedDerived class:
// *******************
// _ZTV21AnotherDerivedDerived:
// ===== The following part is the vtable belongs to Base ===
// 	.long	0
// 	.long	_ZTI21AnotherDerivedDerived
// 	.long	_ZN21AnotherDerivedDerivedD1Ev
// 	.long	_ZN21AnotherDerivedDerivedD0Ev
// 	.long	_ZN4Base10MemberFuncEv
// ===== The following part is the vtable belongs to AnotherDerived ===
// 	.long	_ZN21AnotherDerivedDerived17AnotherMemberFuncEv
// 	.long	_ZN14AnotherDerived12MyMemberFuncEv
// ===== The following part is the vtable belongs to AnotherDerivedDerived ===
// 	.long	_ZN21AnotherDerivedDerived18DerDerMyMemberFuncEv
// ===== The following part is the vtable belongs to AnotherBase ===
// 	.long	-8
// 	.long	_ZTI21AnotherDerivedDerived
// 	.long	_ZThn8_N21AnotherDerivedDerivedD1Ev
// 	.long	_ZThn8_N21AnotherDerivedDerivedD0Ev
// 	.long	_ZThn8_N21AnotherDerivedDerived17AnotherMemberFuncEv
// 	.long	_ZN11AnotherBase18AnotherMemberFunc2Ev


#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Base
{
public:
  Base()
    : data(1)
  {}

  virtual ~Base()
  {

  }

  virtual void MemberFunc()
  {
    cout << "hello" << endl;
  }

private:
  int data;
};

class Derived : public Base
{
public:
  Derived()
    : DerivedData(2)
  {}
  virtual ~Derived()
  {}

  virtual void DerivedMemberFunc()
  {

  }

private:
  int DerivedData;
};

class AnotherBase
{
public:
  AnotherBase()
    : AnotherData(2)
  {}

  virtual ~AnotherBase()
  {}


  virtual void AnotherMemberFunc()
  {
    int i = i;
    ++i;
  }

  virtual void AnotherMemberFunc2()
  {}

private:
  int AnotherData;
};

class AnotherDerived : public Base, public AnotherBase
{
public:
  AnotherDerived()
    : AnotherDerivedData(4)
  {}

  virtual ~AnotherDerived()
  {}

  virtual void AnotherMemberFunc()
  {
    int i = 2;
    i = 3;
  }

  virtual void MyMemberFunc()
  {}

private:
  int AnotherDerivedData;
};

class AnotherDerivedDerived : public AnotherDerived
{
public:
  AnotherDerivedDerived()
    : AnotherDerivedDerivedData(5)
  {}

  virtual ~AnotherDerivedDerived()
  {}

  virtual void AnotherMemberFunc()
  {
    int i = 4;
    i += 2;
  }

  virtual void DerDerMyMemberFunc()
  {}

private:
  int AnotherDerivedDerivedData;
};

typedef void (AnotherBase::*ABaseFuncPtr)();

int main(int argc, char *argv[])
{
  cout << "sizeof Base: " << Base << endl;
  cout << "sizeof Derived: " << sizeof(Derived) << endl;
  cout << "sizeof AnotherBase: " << sizeof(AnotherBase) << endl;
  cout << "sizeof AnotherDerived: " << sizeof(AnotherDerived) << endl;
  cout << "sizeof AnotherDerivedDerived: " << sizeof(AnotherDerivedDerived) << endl;

  char buffer[1024] = {0};

  Base b;
  memcpy(buffer, &b, sizeof(b));
  buffer[sizeof(b)] = '\0';

  ofstream out("log.txt", ofstream::binary);

  out.write("Base", 4);
  out.write(buffer, sizeof(b));

  Derived d;
  memcpy(buffer, &d, sizeof(d));
  out.write("Derived", 7);
  out.write(buffer, sizeof(d));

  AnotherDerived d2;
  memcpy(buffer, &d2, sizeof(d2));
  out.write("AnotherDerived", 14);
  out.write(buffer, sizeof(d2));

  out.close();

  ABaseFuncPtr ptr = &AnotherBase::AnotherMemberFunc;
  AnotherDerived d3;
  AnotherBase* b3 = &d3;
  (b3->*ptr)();

  AnotherDerivedDerived dd;

  return 0;
}
