#ifndef NV
#define NV

#include "date.hpp"

#include <string>

using namespace std;

class NhanVien
{
private:
  string maNhanVien;
  string tenNhanVien;
  Date ngayNhanViec;
  bool gioiTinh;
  double luong;

public:
  NhanVien(const string &maNV, const string &tenNV, const Date &ngayNV,
           bool gioiTinh)
      : maNhanVien(maNV), tenNhanVien(tenNV), ngayNhanViec(ngayNV),
        gioiTinh(gioiTinh)
  {
    if (maNV.length() != 8)
      cout << "Lỗi: Mã nhân viên phải có đúng 8 ký tự" << endl;
  }

  string
  getMaNhanVien() const
  {
    return maNhanVien;
  }
  string
  getTenNhanVien() const
  {
    return tenNhanVien;
  }
  Date
  getNgayNhanViec() const
  {
    return ngayNhanViec;
  }
  bool
  getGioiTinh() const
  {
    return gioiTinh;
  }

  void
  setMaNhanVien(const string &maNV)
  {
    if (maNV.length() != 8)
      cout << "Lỗi: Mã nhân viên phải có đúng 8 ký tự" << endl;
    maNhanVien = maNV;
  }
  void
  setTenNhanVien(const string &tenNV)
  {
    tenNhanVien = tenNV;
  }
  void
  setNgayNhanViec(const Date &ngayNV)
  {
    ngayNhanViec = ngayNV;
  }
  void
  setGioiTinh(bool gioiTinh)
  {
    this->gioiTinh = gioiTinh;
  }
  void
  setLuong(double luong)
  {
    this->luong = luong;
  }
  double getLuong() const
  {
    return luong;
  };
  bool
  operator==(const NhanVien &other) const
  {
    return maNhanVien == other.maNhanVien && tenNhanVien == other.tenNhanVien && ngayNhanViec == other.ngayNhanViec && gioiTinh == other.gioiTinh;
  }

  friend ostream &
  operator<<(ostream &os, const NhanVien &nv)
  {
    os << "Mã nhân viên: " << nv.maNhanVien << ", Tên nhân viên: " << nv.tenNhanVien
       << ", Ngày nhận việc: " << nv.ngayNhanViec
       << ", Giới tính: " << (nv.gioiTinh ? "Nữ" : "Nam") << ", Lương: " << nv.luong << "đ" << endl;
    return os;
  }
};

#endif
