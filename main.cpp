#include "NVBC.hpp"
#include "NVHD.hpp"
#include "QLNV.hpp"
#include "date.hpp"
#include <iostream>

int main()
{
  NhanVien *nv1, *nv2, *nv3;
  QLNV quanLy("Nguyễn Thành Bảo Việt");
  Date ngayNhanViec1(12, 5, 2007);
  nv1 = new NVHD("NV000001", "Nguyễn Chí Bảo", ngayNhanViec1, false, 150000);
  quanLy.themNhanVien(nv1);
  Date ngayNhanViec2(13, 6, 2016);
  nv2 = new NVBC("NV000002", "Nguyễn Chí Thành", ngayNhanViec2, false, 3.5, 8);
  quanLy.themNhanVien(nv2);
  Date ngayNhanViec3(9, 12, 2019);
  nv3 = new NVBC("NV000003", "Nguyễn Tạ Đình Việt", ngayNhanViec3, false, 5, 5);
  quanLy.themNhanVien(nv3);
  cout << fixed << setprecision(0);
  cout << quanLy << endl;
  quanLy.xoaNhanVien(*nv1);
  cout << "Sau khi xóa nhân viên 1:" << endl;
  cout << quanLy << endl;
  quanLy[0].setTenNhanVien("Nguyễn Trí Thành");
  cout << "Sau khi sửa tên của nhân viên đầu danh sách:" << endl;
  cout << quanLy << endl;
  return 0;
}
