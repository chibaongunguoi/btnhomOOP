#ifndef QLNV_HPP
#define QLNV_HPP

#include "linkedlist.hpp"
#include "NV.hpp"
#include <iostream>
#include <string>

using namespace std;

class QLNV
{
private:
  string tenCaNhan;
  LinkedList<NhanVien> danhSachNhanVien;
  int soLuongNhanVien;

public:
  QLNV(const string &tenCaNhan) : tenCaNhan(tenCaNhan), soLuongNhanVien(0)
  {
  }

  void
  themNhanVien(NhanVien *nv)
  {
    danhSachNhanVien.append(nv);
    soLuongNhanVien++;
  }

  void
  xoaNhanVien(const NhanVien &nv)
  {
    danhSachNhanVien.remove(nv);
    soLuongNhanVien--;
  }

  int getSoLuongNhanVien() const
  {
    return soLuongNhanVien;
  }

  NhanVien &
  operator[](int index)
  {
    return danhSachNhanVien.at(index);
  }

  QLNV &
  operator=(const QLNV &other)
  {
    if (this != &other)
    {
      tenCaNhan = other.tenCaNhan;
      danhSachNhanVien = other.danhSachNhanVien;
      soLuongNhanVien = other.soLuongNhanVien;
    }
    return *this;
  }

  friend ostream &
  operator<<(ostream &os, const QLNV &qlnv)
  {
    os << "Tên cá nhân: " << qlnv.tenCaNhan << endl;
    os << "Số lượng nhân viên: " << qlnv.soLuongNhanVien << endl;
    os << "Danh sách nhân viên: " << endl
       << qlnv.danhSachNhanVien << endl;
    return os;
  }

  friend istream &
  operator>>(istream &is, QLNV &qlnv)
  {
    cout << "Nhập tên cá nhân: ";
    is >> qlnv.tenCaNhan;
    return is;
  }
};

#endif
