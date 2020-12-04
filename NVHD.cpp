#include "NVHD.h"
NVHD::NVHD(double luong_ngay)
    : NhanVien(), luong_ngay(luong_ngay)
{
}
NVHD::~NVHD()
{
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
  do
  {
    i >> nv.gioi_tinh;
    if ((nv.gioi_tinh < 0 || nv.gioi_tinh > 1))
      cout << "Gioi tinh nam : 0, gioi tinh nu : 1 " << endl
           << "Xin moi nhap lai!" << endl;
  } while (nv.gioi_tinh < 0 || nv.gioi_tinh > 1);

  cout << "Luong ngay:";
  i >> nv.luong_ngay;
  nv.tinhLuong();
  return i;
};
ostream &operator<<(ostream &o, const NVHD &nv)
{
  o << "Ma nv" << setw(5) << " Ten NV " << setw(20) << "Ngay Nhan Viec " << setw(15) << " Gioi tinh " << setw(5) << "Luong " << setw(20) << "Luong ngay" << setw(3) << endl;
  o << nv.ma_nv << setw(5) << nv.ten_nv << setw(20) << nv.ngay_nhan_viec << setw(15) << nv.gioi_tinh << setw(5) << nv.luong << "0000" << setw(20) << nv.luong_ngay << setw(3) << endl;
  return o;
};
double NVHD::tinhLuong()
{
  cout << "thu hien tai :" << this->ngay_nhan_viec.getDayNow() << endl;
  cout << "Ngay cuoi tang : " << this->ngay_nhan_viec.getDaysOfMonth() << endl;
  int ngay_cuoi_thang = this->ngay_nhan_viec.getDaysOfMonth();
  int ngay_hien_tai = this->ngay_nhan_viec.getDateNow();
  int thu = this->ngay_nhan_viec.getDayNow();
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
  cout << thu_dang_xet << endl;
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
  cout << "so ngay lam viec: " << count << endl;
  cout << " luog: " << this->luong << endl;
  return this->luong;
}
void NVHD::show()
{
  cout << this->ma_nv << setw(5) << this->ten_nv << setw(20) << this->ngay_nhan_viec << setw(15);
  if (this->gioi_tinh == 1)
    cout << "nu";
  else
  {
    cout << "nam ";
  };
  cout << this->luong << "0000" << setw(3) << this->luong_ngay << endl;
}