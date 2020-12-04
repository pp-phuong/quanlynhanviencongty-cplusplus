#include "NVBC.h"
#include "NVHD.h"
// #include "NhanVien.h"
#include <iostream>
using namespace std;
#include <cassert>
template <class Type>

class QLNV {
  private:
    Type ** data;
    int so_luong_nv;
    int so_truong;
  public:
  QLNV();
  QLNV(int);
  void Erase();
  int GetLength() const;
  void Reallocate(int);
  void Resize(int);
  void Insert(Type *, int);
  void Remove(int);
  void InsertFirst(int);
  void InsertLast(int);
  // friend ostream &operator<<<Type>(ostream &, const QLNV<Type> &);
  Type* operator[](int);
  void Xuat();
  ~QLNV();
};