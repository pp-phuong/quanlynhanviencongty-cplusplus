#include "NVHD.h"
NVHD::NVHD(string ma_nv, string ten_nv, Date ngay_nhan_viec, bool gioi_tinh, double luong, double luong_ngay)
    : NhanVien(ma_nv, ten_nv, ngay_nhan_viec, gioi_tinh, luong), luong_ngay(luong_ngay)
{
  this->luong = 0;
}
NVHD::~NVHD()
{
}
double NVHD::tinhLuong()
{
  int ngay_cuoi_thang = this->ngay_nhan_viec.getDaysOfMonth();
  int ngay_hien_tai = this->ngay_nhan_viec.getDateNow();
  int thu = this->ngay_nhan_viec.getDayNow();
  if (thu == 1)
    thu = 8;
  int thu_dang_xet = thu;
  int count = 0;
  for (int i = ngay_hien_tai; i <= ngay_cuoi_thang; i++)
  {
    if (thu_dang_xet <= 6 && thu_dang_xet >= 2)
    {
      count++;
      this->luong += this->luong_ngay;
      thu_dang_xet++;
    }
    else
    {
      thu_dang_xet++;
      if (thu_dang_xet == 9)
        thu_dang_xet = 2;
    }
  }
  thu_dang_xet = thu - 1;
  for (int i = ngay_hien_tai - 1; i >= 1; i--)
  {
    if (thu_dang_xet <= 6 && thu_dang_xet >= 2)
    {
      count++;
      this->luong += this->luong_ngay;
      thu_dang_xet--;
    }
    else
    {
      thu_dang_xet--;
      if (thu_dang_xet == 1)
        thu_dang_xet = 8;
    }
  }
  return this->luong;
}
void NVHD::update()
{
  cout << "Ten nv:";
  cin.ignore();
  getline(cin, this->ten_nv);
  cout << "Ngay nhan viec:" << endl;
  bool valid = false;
  do
  {
    try
    {
      cin >> this->ngay_nhan_viec;
      valid = true;
    }
    catch (string err)
    {
      if (err == "year ")
      {
        cout << "Nam khong hop le !" << endl;
      }
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
  bool valid_sex= false;
  do
  {
    cout << "Gioi tinh:";
    try
    {
      if (!(cin >> this->gioi_tinh))
      {
        valid_sex = true;
        throw true;
      }
      else valid_sex = true;
    }
    catch (bool e)
    {
      cin.clear();
      cout << "Gioi tinh nam : 0, gioi tinh nu : 1 " << endl
          << "Xin moi nhap lai!" << endl;
    }
  } while (!valid_sex);

  cout << "Luong ngay:";
  cin >> this->luong_ngay;
  this->tinhLuong();
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
      if (err == "year ")
      {
        cout << "Nam khong hop le !" << endl;
      }
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

  do
  {
    cout << "Gioi tinh:";
    try
    {
      if (!(i >> nv.gioi_tinh))
      {
        throw true;
      }
    }
    catch (bool e)
    {
      cin.clear();
      cout << "Gioi tinh nam : 0, gioi tinh nu : 1 " << endl
          << "Xin moi nhap lai!" << endl;
    }

  } while (!(i >> nv.gioi_tinh));
  cout << "Luong ngay:";
  cin.ignore();
  i >> nv.luong_ngay;
  nv.tinhLuong();
  return i;
};
ostream &operator<<(ostream &o, const NVHD &nv)
{
   o<< setw(6) << "Ma nv"  << setw(20) << " Ten NV "  << setw(17) << "Ngay Nhan Viec "  << setw(10)<< "Gioi tinh"  << setw(17) << "Luong"  << setw(15) << "Luong ngay" <<  endl;
  o  << setw(6) << nv.ma_nv  << setw(19) << nv.ten_nv  << setw(10) << nv.ngay_nhan_viec  << setw(11);
  if (nv.gioi_tinh == 1)
    cout << "nu";
  else
    cout << "nam ";
  cout << setw(17) << to_string(nv.luong) << setw(15) << nv.luong_ngay << endl;
  return o;
};
ostream &operator<<(ostream &o, const NVHD *nv)
{
   o<< setw(6) << "Ma nv"  << setw(20) << " Ten NV "  << setw(17) << "Ngay Nhan Viec "  << setw(10)<< "Gioi tinh"  << setw(17) << "Luong"  << setw(15) << "Luong ngay" <<  endl;
  o  << setw(6) << nv->ma_nv  << setw(19) << nv->ten_nv  << setw(10) << nv->ngay_nhan_viec  << setw(11);
  if (nv->gioi_tinh == 1)
    cout << "nu";
  else
    cout << "nam ";
  cout << setw(17) << to_string(nv->luong) << setw(15) << nv->luong_ngay << endl;
  return o;
};

void NVHD::show()
{
  cout << setw(6) << "Ma nv"  << setw(20) << " Ten NV "  << setw(17) << "Ngay Nhan Viec "  << setw(10)<< "Gioi tinh"  << setw(17) << "Luong"  << setw(15) << "Luong ngay" <<  endl;
  cout << setw(6) << this->ma_nv  << setw(19) << this->ten_nv  << setw(10) << this->ngay_nhan_viec  << setw(11);
  if (this->gioi_tinh == 1)
    cout << "nu";
  else
    cout << "nam ";
  cout << setw(17) << to_string(this->luong) << setw(15) << this->luong_ngay << endl;
}