#include "NVBC.h"
#include "NVHD.h"
// #include "NhanVien.h"
#include <iostream>
using namespace std;
#include <cassert>
template <class Type>

class QLNV {
  private:
    NhanVien ** data;
    int so_luong_nv;
    int so_truong;
  public:
  QLNV();
  QLNV(int);
  void Erase();
  int &operator[](int);
  int GetLength() const;
  void Reallocate(int);
  void Resize(int);
  void Insert(Type &, int);
  void Remove(int);
  void InsertFirst(int);
  void InsertLast(int);
  // friend ostream &operator<<(ostream &, const QLNV &);
  void Xuat();
  ~QLNV();
};