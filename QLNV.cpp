#include "QLNV.h"
template <class Type>
QLNV<Type>::QLNV() : so_luong_nv(0), data(nullptr)
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
template <class Type>
void QLNV<Type>::Erase()
{
  delete[] this->data;
  this->data = nullptr;
  this->so_luong_nv = 0;
}
template <class Type>
int QLNV<Type>::GetLength() const
{
  return this->so_luong_nv;
}
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
void QLNV<Type>::Remove(int index)
{
  assert(index >= 0 && index <= this->so_luong_nv);
  if (this->so_luong_nv == 0)
  {
    cout << "Danh sach khong co nhan vien nao !" << endl;
  }
  else
  {
    if (index < 0 || index >= this->so_luong_nv)
    {
      cout << "Khong co nhan vien nao o vi tri do !" << endl;
    }
    else
    {
      for (int i = index; i < this->so_luong_nv - 1; ++i)
      {
        *(this->data + i) = *(this->data + i + 1);
      }
      --this->so_luong_nv;
      cout << "Xoa nhan vien thanh cong!" << endl;
    }
  }
}
template <class Type>
void QLNV<Type>::Insert(Type *nv, int index)
{
  assert(index >= 0 && index <= this->so_luong_nv);
  if (this->so_luong_nv == 0)
  {
    this->data = new Type *[this->so_luong_nv + 1];
    *this->data = nv;
  }
  else
  {
    Type **temp = new Type *[this->so_luong_nv + 1];
    for (int i = 0; i < index; i++)
    {
      *(temp + i) = *(this->data + i);
    }

    *(temp + index) = nv;
    for (int i = index; i <= this->so_luong_nv; i++)
    {
      *(temp + i + 1) = *(this->data + i);
    }
    this->data = temp;
  }
  ++this->so_luong_nv;
  cout << "Them nhan vien thanh cong!" << endl;
}
template <class Type>
void QLNV<Type>::InsertLast(Type *nv)
{
  Insert(nv, this->so_luong_nv);
}
template <class Type>
void QLNV<Type>::InsertFirst(Type *nv)
{
  Insert(nv, 0);
}
template <class Type>
void QLNV<Type>::Xuat()
{
  cout << endl
       << "Danh sach nhan vien :" << endl;
  for (int i = 0; i < this->so_luong_nv; i++)
  {
    cout << "STT:" << i << endl;
    this->data[i]->show();
    // cout << (this->data[i]);
    // cout << *(this->data[i]);
    // cout << &(this->data[i]);
  }
}
template <class Type>
Type *QLNV<Type>::operator[](int index)
{
  assert(index >= 0 && index <= this->so_luong_nv);
  return *(this->data + index);
}
// template <class Type>
// ostream &operator<< <> (ostream & o, const QLNV<Type>& qlnv){
//   o << "Danh sach nhan vien :" << endl;
//   for (int i = 0; i < qlnv.so_luong_nv; i++)
//   {
//     qlnv[i]->show();
//     // cout << qlnv[i];
//   }
//   return o;
// }
