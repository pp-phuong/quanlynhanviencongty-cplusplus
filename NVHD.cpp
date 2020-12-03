#include "NVHD.h"
NVHD::NVHD(double luong_ngay)
:NhanVien(),luong_ngay(luong_ngay)
{}
NVHD::~NVHD(){
}

istream &operator>>(istream &i, NVHD &nv)
{
  cout << "Ma nv:";
  i >> nv.ma_nv;
  cout << "Ten nv:";
  i.ignore();
  getline(i, nv.ten_nv);
  cout << "Ngay nhan viec:" << endl;
  bool valid = false;
  do
  {
    try
    {
      i >> nv.ngay_nhan_viec;
      valid = true;
    }
    catch (string err)
    {
      if (err == "month")
      {
        cout << " Khong co thang thich hop !" << endl;
      }
      if (err == "month2")
      {
        cout << " Khong co ngay thich hop trong thang 2 !" << endl;
      }
      if (err == "date")
      {
        cout << " Khong co ngay thich hop trong thang nay !" << endl;
      }
    }
  } while (valid == false);
  cout << "Gioi tinh:";
  i >> nv.gioi_tinh;
  cin.ignore();
  cout << "He so luong:";
  i >> nv.luong_ngay;
  nv.tinhLuong();
  return i;
};
ostream &operator<<(ostream &o, const NVHD &nv)
{
  o << "Ma nv" << setw(5) << " Ten NV " << setw(20) << "Ngay Nhan Viec " << setw(15) << " Gioi tinh " << setw(5) << "Luong " << setw(20) << "Luong ngay" << setw(3) <<  endl;
  o << nv.ma_nv << setw(5) << nv.ten_nv << setw(20) << nv.ngay_nhan_viec << setw(15) << nv.gioi_tinh << setw(5) << nv.luong << "0000" << setw(20) << nv.luong_ngay << setw(3) << endl;
  return o;
};
double NVHD::tinhLuong()
{
  double l = 1;
  // (Hệ số lương * 1.390.000) * (1 + Thâm niên làm việc)
  this->luong = l;
  return l;
}