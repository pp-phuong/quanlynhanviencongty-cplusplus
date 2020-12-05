#include "NhanVien.h"
class NVHD : public NhanVien
{
protected:
  double luong_ngay;

public:
  NVHD(string = "0", string ="name", Date = Date(1,1,2020), bool = 1, double = 1000000,double = 150000);
  ~NVHD();
  double tinhLuong();
  
  void show();
  friend istream &operator>>(istream &, NVHD &);
  friend ostream &operator<<(ostream &, const NVHD &);
    friend ostream &operator<<(ostream &, const NVHD *);
};