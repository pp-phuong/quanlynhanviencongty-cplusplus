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
template <class Type>
void QLNV<Type>::Update(int index)
{
  assert(index >= 0 && index <= this->so_luong_nv);
  if (this->so_luong_nv == 0)
  {
    cout << "danh sach khong co nhan vien nao !" << endl;
  }
  else
  {
    if (index < 0 || index >= this->so_luong_nv)
    {
      cout << "Khong co nhan vien nao o vi tri do !" << endl;
    }
    else
    {
      for (int i = 0; i < this->so_luong_nv; i++)
      {
        if (i = index)
        {
          this->data[i]->update();
          return;
        }
      }
    }
  }
}
template <class Type>
void QLNV<Type>::Remove(int index)
{
    try
  {
    if (index < 0 || index >= this->so_luong_nv)
    {
      throw string("Khong co nhan vien nao o vi tri do !");
    }
    if (this->so_luong_nv == 0)
    {
      throw string("Khong co nhan vien nao trong danh sach !");
    }
    else
    {
      Type **temp = new Type *[this->so_luong_nv - 1];
      for(int i=0; i<index;i++)
      {
        temp[i] = this->data[i]; // *(this->data+ i)
      }
      for (int j = index+1; j < this->so_luong_nv; j++)
      {
        temp[j-1] = this->data[j];
      }
      delete[] this->data;
      this->data = temp;
    --this->so_luong_nv;
    }
    cout << "Xoa nhan vien thanh cong!" << endl;
  }
  catch (string e)
  {
    cout << e;
  }
}
template <class Type>
void QLNV<Type>::Insert(Type *nv, int index)
{
  try
  {
    cout << "insert" << endl;
    if (index < 0 || index > this->so_luong_nv)
    {
      throw string("Khong the chen vao vi tri do !");
    }
    if (this->so_luong_nv == 0)
    {
      this->data = new Type *[this->so_luong_nv + 1];
      *this->data = nv;
    }
    else
    {
      for(int i=0;i< this->so_luong_nv;i++)
      {
        if(this->data[i]->getMaNV() == nv->getMaNV()) 
        throw string("Ma nhan vien da ton tai trong danh sach !");
      }
      Type **temp = new Type *[this->so_luong_nv + 1];
      for(int i=0; i<index;i++)
      {
        temp[i] = this->data[i]; // *(this->data+ i)
      }
      temp[index] = nv;
      for (int j = index; j < this->so_luong_nv; j++)
      {
        temp[j+1] = this->data[j];
      }
      delete[] this->data;
      this->data = temp;
    }
    ++this->so_luong_nv;
    cout << "Them nhan vien thanh cong!" << endl;
  }
  catch (string e)
  {
    cout << e;
  }
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
void QLNV<Type>::Sort(bool (*Compare)(Date, Date))
{
  {
    for (int i = 0; i < this->so_luong_nv - 1; i++)
      for (int j = i; j < this->so_luong_nv; j++)
        if (Compare(this->data[i]->getNgayNhanViec(), this->data[j]->getNgayNhanViec()))
        {
          NhanVien *temp;
          temp = this->data[i];
          this->data[i] = this->data[j];
          this->data[j] = temp;
        }
  }
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
// ostream &operator<< (ostream & o, const QLNV<Type>& qlnv){
//   o << "Danh sach nhan vien :" << endl;
//   for (int i = 0; i < qlnv.so_luong_nv; i++)
//   {
//     qlnv[i]->show();
//     // o << qlnv[i];
//   }
//   return o;
// }
