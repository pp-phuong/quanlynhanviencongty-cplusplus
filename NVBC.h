#include "NhanVien.h"
class NVBC : public NhanVien
{
protected:
  double he_so_luong;
  double tham_nien_lam_viec;

public:
  NVBC(string = "0", string ="name", Date = Date(1,1,2020), bool = 1, double = 1000000,double = 2.34, double = 0);
  NVBC(const NhanVien &);
  ~NVBC();
  double getHeSoLuong();
  double tinhThamNienLamViec();
  double tinhLuong();
  void show();
  friend istream &operator>>(istream &, NVBC &);
  friend ostream &operator<<(ostream &, const NVBC &);
};