
#include "NVBC.h"
#include "NVHD.h"
#include <iostream>
#include <exception>
using namespace std;
#include <cassert>
template <class Type>

class QLNV {
  private:
    Type ** data;
    int so_luong_nv;
  public:
  QLNV();
  QLNV(int);
  void Erase(); //
  int GetLength() const;
  void Insert(Type *, int);//
  void Remove(int);//
  void Update(int);
  void InsertFirst(Type *);//
  void InsertLast(Type *); //
  void Sort();
  // friend ostream &operator<< <Type>(ostream &, const QLNV<Type> &);
  Type* operator[](int);
  void Xuat();
  ~QLNV();
};