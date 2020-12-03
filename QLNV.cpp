#include "QLNV.h"
template <class Type>
QLNV<Type>::QLNV() : so_luong_nv(0), data(nullptr), so_truong(8)
{
}
template <class Type>
QLNV<Type>::QLNV(int length) : so_luong_nv(length)
{
  assert(this->so_luong_nv >= 0);
  if (length > 0)
    this->data = new int[this->so_luong_nv];
  else
  {
    this->data = nullptr;
  }
}
template <class Type>
QLNV<Type>::~QLNV()
{
  delete[] this->data;
}
// template <class Type>
// void QLNV<Type>::Erase()
// {
//   delete[] this->data;
//   this->data = nullptr;
//   this->so_luong_nv = 0;
// }
// template <class Type>
// int &QLNV<Type>::operator[](int index)
// {
//   assert(index >=0 && index < this->so_luong_nv);
//   return this->data[index];
// }
// template <class Type>
// int QLNV<Type>::GetLength() const
// {
//   return this->so_luong_nv;
// }
// template <class Type>
// void QLNV<Type>::Reallocate(int newLength)
// {
//   Erase();
//   if(newLength <=0)
//   return;
//   this->data = new int[newLength];
//   this->so_luong_nv = newLength;
// }
// template <class Type>
// void QLNV<Type>::Resize(int newLength)
// {
//   if(newLength == this->so_luong_nv)
//     return;
//   if(newLength <= 0)
//   {
//     Erase();
//     return;
//   }
//   int * data = new int[newLength];
//   if(this->so_luong_nv >0)
//   {
//     int maxLength = (newLength > this->so_luong_nv) ? this->so_luong_nv: newLength;
//     for(int i =0; i< maxLength; i++)
//     {
//       data[i] = (*this)[i];
//     }
//   }
//   delete[] this->data;
//   this->data = data;
//   this->so_luong_nv = newLength;
// }
template <class Type>
void QLNV<Type>::Insert(Type &nv, int index)
{
  cout << "Goi duoc ham insert" << endl;
  assert(index >= 0 && index <= this->so_luong_nv);
  if (this->so_luong_nv == 0)
  {
    this->data = new NhanVien*[this->so_luong_nv+1];
    this->data[this->so_luong_nv] = &nv;
    this->data[this->so_luong_nv]->show();
    cout << "insert roi !" << endl;
  }
  else
  {
    NhanVien **data;
    for (int i = 0; i <= index; i++)
    {
      data[i] = this->data[i];
      data[i]->show();
    }
    data[index] = &nv;
    data[index]->show();
    for (int j = index; j <= this->so_luong_nv; j++)
    {
      data[j + 1] = this->data[j];
    }
    delete[] this->data;
    this->data = data;
  }
  ++this->so_luong_nv;
  cout << "insert success";
}

template <class Type>
void QLNV<Type>::Xuat()
{
  cout << "Danh sach nhan vien :" << endl;
  for (int i = 0; i < this->so_luong_nv; i++)
  {
    this->data[i]->show(); 
  }
}