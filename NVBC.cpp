#include "NVBC.h"
NVBC::NVBC(string ma_nv, string ten_nv, Date ngay_nhan_viec, bool gioi_tinh, double luong,double he_so_luong, double tham_nien_lam_viec)
    : NhanVien(ma_nv,ten_nv,ngay_nhan_viec,gioi_tinh,luong), he_so_luong(he_so_luong){
      this->tham_nien_lam_viec = 0;
    }
NVBC::~NVBC()
{
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
  cout << "He so luong:";
  do {
  i >> nv.he_so_luong;
  if  (nv.he_so_luong >  10 || nv.he_so_luong <  2.4) cout << " He so luong nam trong khoang 2.4 -> 10 !" << endl;
  } while (nv.he_so_luong >  10 || nv.he_so_luong <  2.4);
  nv.tinhThamNienLamViec();
  nv.tinhLuong();
  return i;
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
  cout << year - d.year << endl;
  return this->tham_nien_lam_viec;
}
ostream &operator<<(ostream &o, const NVBC &nv)
{
  o << "Ma nv" << setw(5) << " Ten NV " << setw(20) << "Ngay Nhan Viec " << setw(15) << " Gioi tinh " << setw(5) << "Luong " << setw(20) << "He so luong" << setw(3) << "Tham nien lam viec" << endl;
  o << nv.ma_nv << setw(5) << nv.ten_nv << setw(20) << nv.ngay_nhan_viec << setw(15) << nv.gioi_tinh << setw(5) << nv.luong << "0000" << setw(20) << nv.he_so_luong << setw(3) << nv.tham_nien_lam_viec << endl;
  return o;
};
double NVBC::tinhLuong()
{
  double l = (this->he_so_luong * 139) * (1 + this->tham_nien_lam_viec);
  // (Hệ số lương * 1.390.000) * (1 + Thâm niên làm việc)
  this->luong = l;
  return l;
}
void NVBC::show(){
    cout << this->ma_nv << setw(5) << this->ten_nv << setw(20) << this->ngay_nhan_viec << setw(15) << this->gioi_tinh << setw(5) << this->luong << "0000" << this->he_so_luong << setw(3) << this->tham_nien_lam_viec << endl;
}