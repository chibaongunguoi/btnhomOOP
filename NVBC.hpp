#ifndef NVBC_HPP
#define NVBC_HPP

#include "NV.hpp"
#include <algorithm>
#include <iomanip>

using namespace std;

class NVBC : public NhanVien
{
private:
  double heSoLuong;
  double thamNienLamViec;

public:
  NVBC(const string &maNV, const string &tenNV, const Date &ngayNV,
       bool gioiTinh, double heSoLuong, double thamNienLamViec)
      : NhanVien(maNV, tenNV, ngayNV, gioiTinh),
        heSoLuong(clamp(heSoLuong, 2.34, 10.0)),
        thamNienLamViec(thamNienLamViec)
  {
    double heSoPhuCap = (thamNienLamViec < 5) ? 0 : thamNienLamViec / 100;
    setLuong((heSoLuong * 1390000) * (1 + heSoPhuCap));
  }

  bool
  operator==(const NVBC &other) const
  {
    return NhanVien::operator==(other) && heSoLuong == other.heSoLuong && thamNienLamViec == other.thamNienLamViec;
  }

  friend ostream &
  operator<<(ostream &os, const NVBC &nvbc)
  {
    os << "Ma NV: " << nvbc.getMaNhanVien()
       << ", Ten NV: " << nvbc.getTenNhanVien()
       << ", Ngay NV: " << nvbc.getNgayNhanViec()
       << ", Gioi Tinh: " << (nvbc.getGioiTinh() ? "Nu" : "Nam")
       << ", He So Luong: " << fixed << setprecision(2) << nvbc.heSoLuong
       << ", Tham Nien Lam Viec: " << nvbc.thamNienLamViec;
    return os;
  }
};

#endif
