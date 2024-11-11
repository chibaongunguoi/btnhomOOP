#ifndef NVHD_HPP
#define NVHD_HPP

#include "NV.hpp"
#include <ctime>
#include <iomanip>

using namespace std;

class NVHD : public NhanVien
{
private:
  double luongCongNhat;

  int daysInMonth(int month, int year) const
  {
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:
      return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29
                                                                     : 28;
    default:
      return 0;
    }
  }

public:
  NVHD(const string &maNV, const string &tenNV, const Date &ngayNV,
       bool gioiTinh, double luongCongNhat)
      : NhanVien(maNV, tenNV, ngayNV, gioiTinh), luongCongNhat(luongCongNhat)
  {
    time_t t = time(0);
    tm *now = localtime(&t);
    int currentMonth = now->tm_mon + 1;
    int currentYear = now->tm_year + 1900;

    int songaylamviec = 0;
    for (int day = 1; day <= daysInMonth(currentMonth, currentYear); ++day)
    {
      tm date = {0};
      date.tm_year = currentYear - 1900;
      date.tm_mon = currentMonth - 1;
      date.tm_mday = day;
      mktime(&date);

      if (date.tm_wday >= 1 && date.tm_wday <= 5)
        ++songaylamviec;
    }

    setLuong(luongCongNhat * songaylamviec);
  }

  bool
  operator==(const NVHD &other) const
  {
    return NhanVien::operator==(other) && luongCongNhat == other.luongCongNhat;
  }

  friend ostream &
  operator<<(ostream &os, const NVHD &nvhd)
  {
    os << "Mã NV: " << nvhd.getMaNhanVien()
       << ", Tên NV: " << nvhd.getTenNhanVien()
       << ", Ngày NV: " << nvhd.getNgayNhanViec()
       << ", Giới Tính: " << (nvhd.getGioiTinh() ? "Nu" : "Nam")
       << ", Lương Công Nhật: " << fixed << setprecision(2)
       << nvhd.luongCongNhat;
    return os;
  }
};

#endif
