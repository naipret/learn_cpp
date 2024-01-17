#include <algorithm>
#include <fstream>
#include <iostream>

// using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_doanThamQuan{}, m_soXeKhach{};

    std::ifstream input{};
    input.open("INPUT.INP");
    input >> n_doanThamQuan >> m_soXeKhach;
    int d_soKM[n_doanThamQuan] = {};
    int v_giaTien[m_soXeKhach] = {};
    for (int i{0}; i < n_doanThamQuan; ++i) {
        input >> d_soKM[i];
    }
    for (int i{0}; i < m_soXeKhach; ++i) {
        input >> v_giaTien[i];
    }
    input.close();

    std::sort(d_soKM, d_soKM + n_doanThamQuan, [](int a, int b) { return a >= b; });

    int tongTien{0};
    int *itr{d_soKM};
    while (itr != (d_soKM + n_doanThamQuan)) {
        int tienThapNhat{(*itr) * v_giaTien[0]};
        int *itrGiaThapNhat{&v_giaTien[0]};
        for (int i{1}; i < m_soXeKhach; ++i) {
            if (((*itr) * v_giaTien[i]) < tienThapNhat) {
                tienThapNhat = (*itr) * v_giaTien[i];
                itrGiaThapNhat = &(v_giaTien[i]);
            }
        }
        *itrGiaThapNhat = 10000;
        tongTien += tienThapNhat;
        itr++;
    }

    std::ofstream output{};
    output.open("OUTPUT.OUT");
    output << tongTien;
    output.close();

    return 0;
}
