#include "NVBC.h"
NVBC::NVBC(string ma_nv, string ten_nv, Date ngay_nhan_viec, bool gioi_tinh, double luong, double he_so_luong, double tham_nien_lam_viec, double he_so_phu_cap)
    : NhanVien(ma_nv, ten_nv, ngay_nhan_viec, gioi_tinh, luong), he_so_luong(he_so_luong),he_so_phu_cap(he_so_phu_cap)
{
  this->tham_nien_lam_viec = 0;
  this->he_so_phu_cap = 0;
}
NVBC::~NVBC()
{
}

double NVBC::tinhLuong()
{
  // (Hệ số lương * 1.390.000) * (1 + Thâm niên làm việc)
  double l = (this->he_so_luong * 1390000) * (1 + this->he_so_phu_cap);
  this->luong = l;
  return l;
}
void NVBC::update()
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
        valid_sex = false;
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

  cout << "He so luong:";
  do
  {
  cin.ignore();
    cin >> this->he_so_luong;
    if (this->he_so_luong > 10 || this->he_so_luong < 2.4)
      cout << " He so luong nam trong khoang 2.4 -> 10 " << endl
          << "Xin moi nhap lai!" << endl;
  } while (this->he_so_luong > 10 || this->he_so_luong < 2.4);
  this->tinhThamNienLamViec();
  this->tinhLuong();
}
double NVBC::tinhThamNienLamViec()
{
  Date d = this->ngay_nhan_viec;
  int day = d.getDateNow();
  int mon = d.getMonthNow();
  int year = d.getYearNow();
  if (d.day > day)
    mon--;
  if (d.month > mon)
    year--;
  this->tham_nien_lam_viec = year - d.year;
  if(this->tham_nien_lam_viec > 5) this->he_so_phu_cap = this->tham_nien_lam_viec/100;
  return this->tham_nien_lam_viec;
}
istream &operator>>(istream &i, NVBC &nv)
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

   bool valid_sex;
   do
  {
    cout << "Gioi tinh:";
    try
    {
      if (!(cin >> nv.gioi_tinh))
      {
        valid_sex = false;
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
  cout << "He so luong:";
  do
  {
    i.ignore();
    i >> nv.he_so_luong;
    if (nv.he_so_luong > 10 || nv.he_so_luong < 2.4)
      cout << " He so luong nam trong khoang 2.4 -> 10 " << endl
           << "Xin moi nhap lai!" << endl;
  } while (nv.he_so_luong > 10 || nv.he_so_luong < 2.4);
  nv.tinhThamNienLamViec();
  nv.tinhLuong();
  return i;
}
ostream &operator<<(ostream &o, const NVBC &nv)
{
  o<< setw(6) << "Ma nv"  << setw(20) << " Ten NV "  << setw(17) << "Ngay Nhan Viec "  << setw(10)<< "Gioi tinh"  << setw(17) << "Luong"  << setw(15) << "He so luong" << setw(17) << " Tham nien lam viec" << endl;
  o  << setw(6) << nv.ma_nv  << setw(19) << nv.ten_nv  << setw(10) << nv.ngay_nhan_viec  << setw(11);
  if (nv.gioi_tinh == 1)
    cout << "nu";
  else
    cout << "nam ";
  cout << setw(17) << long(nv.luong) << setw(15) << nv.he_so_luong << setw(15) << nv.tham_nien_lam_viec << endl;
  return o;
};
ostream &operator<<(ostream &o, const NVBC *nv)
{
  o<< setw(6) << "Ma nv"  << setw(20) << " Ten NV "  << setw(17) << "Ngay Nhan Viec "  << setw(10)<< "Gioi tinh"  << setw(17) << "Luong"  << setw(15) << "He so luong" << setw(17) << " Tham nien lam viec" << endl;
  o  << setw(6) << nv->ma_nv  << setw(19) << nv->ten_nv  << setw(10) << nv->ngay_nhan_viec  << setw(11);
  if (nv->gioi_tinh == 1)
    cout << "nu";
  else
    cout << "nam ";
  cout << setw(17) << long(nv->luong) << setw(15) << nv->he_so_luong << setw(15) << nv->tham_nien_lam_viec << endl;
  return o;
};

void NVBC::show()
{
 cout<< setw(6) << "Ma nv"  << setw(20) << " Ten NV "  << setw(17) << "Ngay Nhan Viec "  << setw(10)<< "Gioi tinh"  << setw(17) << "Luong"  << setw(15) << "He so luong" << setw(17) << " Tham nien lam viec" << endl;
  cout  << setw(6) << this->ma_nv  << setw(19) << this->ten_nv  << setw(10) << this->ngay_nhan_viec  << setw(11);
  if (this->gioi_tinh == 1)
    cout << "nu";
  else
    cout << "nam ";
  cout << setw(17) << int(this->luong) << setw(15) << this->he_so_luong << setw(15) << this->tham_nien_lam_viec << endl;

}