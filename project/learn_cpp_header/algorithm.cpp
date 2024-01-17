#include <algorithm>
#include <functional>  // std::greater<int>()
#include <iostream>
#include <string>

namespace cst {
    void print_array(int arr[], int n) {
        //* Để in một mảng ========================================================================
        for (int i{0}; i < n; ++i) {
            std::cout << arr[i] << '\t';
        }
        std::cout << std::endl;
    }

    namespace sort {
        void is_sorted(int arr[], int n, bool isGreater = false) {
            //* Kiểm tra xem mảng đã được sắp xếp hay chưa ========================================
            if (isGreater) {
                if (std::is_sorted(arr, arr + n, std::greater<int>())) {
                    std::cout << "Mang da duoc sap xep!\n";
                } else {
                    std::cout << "Mang chua duoc sap xep!\n";
                }
            } else {
                if (std::is_sorted(arr, arr + n)) {
                    std::cout << "Mang da duoc sap xep!\n";
                } else {
                    std::cout << "Mang chua duoc sap xep!\n";
                }
            }
        }
        void sort(int arr[], int n, bool isGreater = false) {
            //* Thuật toán sắp xếp này được sử dụng để sắp xếp một dãy số hoặc một mảng các phần tử của một container.
            //* Nó là thuật toán không ổn định nghĩa là nếu có 2 phần tử có giá trị bằng nhau, thì không đảm bảo rằng thứ tự tương đối giữa chúng sẽ được giữ nguyên sau khi sắp xếp.
            //* Có hiệu suất tốt hơn so với std::stable_sort, nhưng không đảm bảo tính ổn định.
            //* std::sort thường sử dụng thuật toán Quicksort hoặc Introsort, là các thuật toán sắp xếp không ổn định nhưng có độ phức tạp thời gian trung bình nhanh hơn.
            if (isGreater) {
                std::sort(arr, arr + n, std::greater<int>());
            } else {
                std::sort(arr, arr + n);
            }
        }
        void stable_sort(int arr[], int n, bool isGreater = false) {
            //* Tương tự như std::sort, nhưng là một thuật toán ổn định. Nghĩa là nếu có hai phần tử bằng nhau, thì thứ tự tương đối của chúng sẽ được giữ nguyên sau khi sắp xếp.
            //* Hiệu suất thường kém hơn so với std::sort, đặc biệt là khi sắp xếp các dãy số lớn.
            //* std::stable_sort thường sử dụng thuật toán Mergesort, là một thuật toán sắp xếp ổn định nhưng có độ phức tạp thời gian trung bình chậm hơn một chút.
            if (isGreater) {
                std::stable_sort(arr, arr + n, std::greater<int>());
            } else {
                std::stable_sort(arr, arr + n);
            }
        }
        void partial_sort(int arr[], int n, int value = 3, bool isGreater = false) {
            //* Chỉ sắp xếp một số lượng phần tử đầu tiên =========================================
            if (isGreater) {
                std::partial_sort(arr, arr + value, arr + n, std::greater<int>());
            } else {
                std::partial_sort(arr, arr + value, arr + n);
            }
        }
        void partial_sort_copy(int arr[], int n, int ans[], int value = 3, bool isGreater = false) {
            //* Chỉ sắp xếp một số lượng phần tử đầu tiên rồi copy sang mảng khác =================
            if (isGreater) {
                std::partial_sort_copy(arr, arr + value, arr + n, ans, std::greater<int>());
            } else {
                std::partial_sort_copy(arr, arr + value, arr + n, ans);
            }
        }
        void nth_element(int arr[], int n, int value = 3, bool isGreater = false) {
            //* Chỉ sắp xếp duy nhất 1 phần tử tại vị trí chỉ định ================================
            if (isGreater) {
                std::nth_element(arr, arr + value, arr + n, std::greater<int>());
            } else {
                std::nth_element(arr, arr + value, arr + n);
            }
        }
    }  // namespace sort

    namespace search {
        void adjacent_find(int arr[], int n) {
            //* Tìm xem có 2 phần tử liên tiếp nào mà trùng nhau không ============================
            std::cout << "std::adjacent_find(*begin, *end\'[\', [](int a, int b) { return a == b }\']\'); ======================================\n";
            //* không sort ========================================================================
            {
                int *it1{std::adjacent_find(arr, arr + n)};
                print_array(arr, n);
                if (it1 != (arr + n)) {
                    std::cout << "Co phan tu trung lap: " << *it1 << '\n';
                } else {
                    std::cout << "\nKhong co phan tu nao trung lap!\n";
                }
                std::cout << std::endl;
                // 2  4  3  12  7  [6  6]  9  10  18  12  11  8  3  2
                // Co phan tu trung lap: 6
            }
            //* sorted =================================================================
            {
                sort::sort(arr, n);
                print_array(arr, n);
                int *it2{std::adjacent_find(arr, arr + n)};
                while (it2 != (arr + n)) {
                    std::cout << "Co phan tu trung lap: " << *it2 << '\n';
                    it2 = std::adjacent_find(++it2, arr + n);
                }
                std::cout << std::endl;
                // [2  2]  [3  3]  4  [6  6]  7  8  9  10  11  [12  12]  18
                // Co phan tu trung lap: 2
                // Co phan tu trung lap: 3
                // Co phan tu trung lap: 6
                // Co phan tu trung lap: 12
            }
            //* adjacent_find thay doi dieu kien =======================================
            // tham so thu 3 bth la: return a == b; nhung neu khong thich thi co the doi
            {
                print_array(arr, n);
                int *it3{std::adjacent_find(arr, arr + n, ([](int temp1, int temp2) { return (temp1 >= 6) && (temp1 == temp2); }))};
                while (it3 != (arr + n)) {
                    std::cout << "Co phan tu trung lap: " << *it3 << '\n';
                    it3 = std::adjacent_find(++it3, arr + n, ([](int temp1, int temp2) { return (temp1 >= 6) && (temp1 == temp2); }));
                }
                std::cout << std::endl;
                // 2  2  3  3  4  [6  6]  7  8  9  10  11  [12  12]  18
                // Co phan tu trung lap: 6
                // Co phan tu trung lap: 12
            }
        }
        void binary_search(int arr[], int n) {
            //* 3 tham so mac dinh =====================================================
            std::cout << "std::binary_search(*begin, *end, value\'[\', std::greater<int>()\']\'); ==============================================\n";
            {
                sort::sort(arr, n);
                print_array(arr, n);
                int searchValue1{10};
                if (std::binary_search(arr, arr + n, searchValue1)) {
                    std::cout << "Co phan tu " << searchValue1 << " trong mang!\n";
                } else {
                    std::cout << "Khong co phan tu " << searchValue1 << " nao trong mang!\n";
                }
                std::cout << std::endl;
                // 2  2  3  3  4  6  6  7  8  9  [10]  11  12  12  18
                // Co phan tu 10 trong mang!
            }
            //* them tham so 4: std::greater<int>() ====================================
            // neu mang bi xep theo thu tu giam dan thi them tham so std::greater<int>()
            // noi chinh xac hon la std::sort() duoc sap xep theo dieu kien nao thi binary_search se duoc tim kiem dua tren dieu kien sap xep do
            {
                sort::sort(arr, n, true);
                print_array(arr, n);
                int searchValue2{10};
                if (std::binary_search(arr, arr + n, searchValue2, std::greater<int>())) {
                    std::cout << "Co phan tu " << searchValue2 << " trong mang!\n";
                } else {
                    std::cout << "Khong co phan tu " << searchValue2 << " nao trong mang!\n";
                }
                std::cout << std::endl;
                // 18  12  12  11  [10] 9  8  7  6  6  4  3  3  2  2
                // Co phan tu 10 trong mang!
            }
        }
        void lower_bound(int arr[], int n) {
            std::cout << "std::lower_bound(*begin, *end, value) ============================================================================\n";
            print_array(arr, n);
            std::cout << "lower_bound cua 12 la:  " << std::lower_bound(arr, arr + n, 12) << "  " << *(std::lower_bound(arr, arr + n, 12));
            std::cout << std::endl;
            std::cout << std::endl;
            // 2  2  3  3  4  6  6  7  8  9  10  11  12  12  18
            // lower_bound cua 12 la:  0x74ffbffc40  12
        }
        void upper_bound(int arr[], int n) {
            std::cout << "std::upper_bound(*begin, *end, value) ============================================================================\n";
            print_array(arr, n);
            std::cout << "upper_bound cua 12 la:  " << std::upper_bound(arr, arr + n, 12) << "  " << *(std::upper_bound(arr, arr + n, 12));
            std::cout << std::endl;
            std::cout << std::endl;
            // 2  2  3  3  4  6  6  7  8  9  10  11  12  12  18
            // upper_bound cua 12 la:  0x49a3dff898  18
        }
        void count(int arr[], int n) {
            std::cout << "std::count(*begin, *end, value) ==================================================================================\n";
            print_array(arr, n);
            std::cout << "Co " << std::count(arr, arr + n, 3) << " phan tu co gia tri bang 3 trong mang!\n";
            std::cout << std::endl;
            // 2  4  [3]  12  7  6  6  9  10  18  12  11  8  [3]  2
            // Co 2 phan tu co gia tri bang 3 trong mang!
        }
        void count_if(int arr[], int n) {
            std::cout << "std::count_if(*begin, *end, []() { }) ============================================================================\n";
            print_array(arr, n);
            std::cout << "Co " << std::count_if(arr, arr + n, [](int a) { return a % 2 == 0; }) << " phan tu chia het cho 2 trong mang!\n";
            std::cout << std::endl;
            // [2]  [4]  3  [12]  7  [6]  [6]  9  [10]  [18]  [12]  11  [8]  3  [2]
            // Co 10 phan tu chia het cho 2 trong mang!
        }
        void find(int arr[], int n) {
            std::cout << "std::find(*begin, *end, value) ===================================================================================\n";
            print_array(arr, n);
            int *it{std::find(arr, arr + n, 2)};
            while (it != arr + n) {
                std::cout << it << "\t";
                it = std::find(++it, arr + n, 2);
            }
            std::cout << std::endl;
            std::cout << std::endl;
            // 2  4  3  7  6  6  9  10  12  11  8  3  2
            // 0xb5593ff720  0xb5593ff740  0xb5593ff758
        }
        void find_if(int arr[], int n) {
            std::cout << "std::find_if(*begin, *end, []() { })  ============================================================================\n";
            print_array(arr, n);
            int *it{std::find_if(arr, arr + n, [](int element) { return element % 2 == 0; })};
            while (it != arr + n) {
                std::cout << *it << "\t";
                it = std::find_if(++it, arr + n, [](int element) { return element % 2 == 0; });
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }
        void find_if_not(int arr[], int n) {
            std::cout << "std::find_if_not(*begin, *end, []() { }) =========================================================================\n";
            print_array(arr, n);
            int *it{std::find_if_not(arr, arr + n, [](int element) { return element % 2 == 0; })};
            while (it != arr + n) {
                std::cout << *it << "\t";
                it = std::find_if_not(++it, arr + n, [](int element) { return element % 2 == 0; });
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }
        //! ============================================================================
        // void find_first_of(int arr1[], int n1, int arr2[], int n2) {}
        // void find_end(int arr1[], int n1, int arr2[], int n2) {}
        //! ============================================================================
        // void mismatch(int arr1[], int n1, int arr2[], int n2) {}
        void search() {
            std::cout << "std::search(*begin1, *end1, *begin2, *end2) ======================================================================\n";
            constexpr int n{15};
            int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
            int pattern[3] = {6, 9, 10};
            print_array(arr, n);
            print_array(pattern, 3);
            int *it = std::search(arr, arr + n, pattern, pattern + 3);
            if (it != arr + n) {
                std::cout << "Pattern found at index: " << it - arr << std::endl;
            } else {
                std::cout << "Pattern not found.\n";
            }
            std::cout << std::endl;
        }
        void search_n() {
            std::cout << "std::search_n(*begin, *end, range, value) ========================================================================\n";
            constexpr int n{15};
            int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
            print_array(arr, n);
            int value = 6;
            int count = 2;
            int *it = std::search_n(arr, arr + n, count, value);
            if (it != arr + n) {
                std::cout << "Sequence of " << count << " " << value << "'s found starting at index: " << it - arr << std::endl;
            } else {
                std::cout << "Sequence not found.\n";
            }
            std::cout << std::endl;
        }
    }  // namespace search

    namespace query {
        void all_of(int arr[], int n) {
            std::cout << "std::all_of(*begin, *end, [](int a) { return a; }); ==============================================================\n";
            print_array(arr, n);
            if (std::all_of(arr, arr + n, ([](int temp) { return (temp % 2) == 0; }))) {
                std::cout << "Tat ca phan tu trong mang deu chia het cho 2!\n";
            } else {
                std::cout << "Tat ca phan tu trong mang khong phai cai nao cung chia het cho 2!\n";
            }
            std::cout << std::endl;
            // 2  2  [3]  [3]  4  6  6  [7]  8  [9]  10  [11]  12  12  18
            // Tat ca phan tu trong mang khong phai cai nao cung chia het cho 2!
        }
        void any_of(int arr[], int n) {
            std::cout << "std::any_of(*begin, *end, [](int a) { return a; }); ==============================================================\n";
            print_array(arr, n);
            if (std::any_of(arr, arr + n, ([](int temp) { return (temp % 2) == 0; }))) {
                std::cout << "Co it nhat 1 phan tu trong mang chia het cho 2!\n";
            } else {
                std::cout << "Khong co phan tu nao trong mang chia het cho 2!\n";
            }
            std::cout << std::endl;
            // [2]  2  3  3  4  6  6  7  8  9  10  11  12  12  18
            // Co it nhat 1 phan tu trong mang chia het cho 2!
        }
        void none_of(int arr[], int n) {
            std::cout << "std::none_of(*begin, *end, [](int a) { return a; }); =============================================================\n";
            print_array(arr, n);
            if (std::none_of(arr, arr + n, ([](int temp) { return (temp % 20) == 0; }))) {
                std::cout << "Khong co phan tu nao trong mang chia het cho 20!\n";
            } else {
                std::cout << "Co it nhat 1 phan tu trong mang chia het cho 20!\n";
            }
            std::cout << std::endl;
            // 2  2  3  3  4  6  6  7  8  9  10  11  12  12  18
            // Khong co phan tu nao trong mang chia het cho 20!
        }
    }  // namespace query

    namespace copy {
        void copy(int copy1[], int cp1, int copy2[], int cp2, int result[]) {
            std::cout << "std::copy(*begin, *end, *result) =================================================================================\n";
            std::fill(result, result + cp1 + cp2, 0);
            //* copy 1 time ============================================================
            {
                std::cout << "copy1[]  = \t";
                print_array(copy1, cp1);
                std::copy(copy1, copy1 + 3, result);
                std::cout << "std::copy(copy1, copy1 + 3, result);\n";
                std::cout << "result[] = \t";
                print_array(result, cp1 + cp2);
                std::cout << std::endl;
                // copy1[]  =  [[5  2  9]  6  1]
                // std::copy(copy1, copy1 + 3, result);
                // result[] =  [5  2  9]  0  0  0  0  0  0  0
            }
            //* copy n times ===========================================================
            {
                std::cout << "copy1[]  = \t";
                print_array(copy1, cp1);
                std::cout << "copy2[]  = \t";
                print_array(copy2, cp2);
                std::copy(copy1, copy1 + cp1, result);
                std::copy(copy2, copy2 + cp2, result + cp1);
                std::cout << "std::copy(copy1, copy1 + cp1, result);  +  ";
                std::cout << "std::copy(copy2, copy2 + cp2, result + cp1);\n";
                std::cout << "result[] = \t";
                print_array(result, cp1 + cp2);
                std::cout << std::endl;
                // copy1[]  =  [5  2  9  6  1]
                // copy2[]  =  [4  3  2  1  7]
                // std::copy(copy1, copy1 + cp1, result);  +  std::copy(copy2, copy2 + cp2, result + cp1);
                // result[] =  [5  2  9  6  1]  [4  3  2  1  7]
            }
        }
        void copy_backward(int copy1[], int cp1, int copy2[], int cp2, int result[]) {
            std::cout << "std::copy_backward(*begin1, *end1, *end2) ========================================================================\n";
            std::fill(result, result + cp1 + cp2, 0);
            //* copy 1 time ============================================================
            {
                std::cout << "copy1[]  = \t";
                print_array(copy1, cp1);
                std::copy_backward(copy1, copy1 + 3, result + cp1 + cp2);
                std::cout << "std::copy_backward(copy1, copy1 + 3, result + cp1 + cp2);\n";
                std::cout << "result[] = \t";
                print_array(result, cp1 + cp2);
                std::cout << std::endl;
                // copy1[]  =  [[5  2  9]  6  1]
                // std::copy_backward(copy1, copy1 + 3, result + cp1 + cp2);
                // result[] =  0  0  0  0  0  0  0  [5  2  9]
            }
            //* copy n times ===========================================================
            {
                std::cout << "copy1[]  = \t";
                print_array(copy1, cp1);
                std::cout << "copy2[]  = \t";
                print_array(copy2, cp2);
                std::copy_backward(copy1, copy1 + cp1, result + cp1);
                std::copy_backward(copy2, copy2 + cp2, result + cp1 + cp2);
                std::cout << "std::copy_backward(copy1, copy1 + cp1, result + cp1);\n";
                std::cout << "std::copy_backward(copy2, copy2 + cp2, result + cp1 + cp2);\n";
                std::cout << "result[] = \t";
                print_array(result, cp1 + cp2);
                std::cout << std::endl;
                // copy1[]  =  [5  2  9  6  1]
                // copy2[]  =  [4  3  2  1  7]
                // std::copy_backward(copy1, copy1 + cp1, result + 1);
                // std::copy_backward(copy2, copy2 + cp2, result + cp1 + cp2);
                // result[] =  [5  2  9  6  1]  [4  3  2  1  7]
            }
        }
        void copy_if(int copy1[], int cp1, int copy2[], int cp2, int result[]) {
            std::cout << "std::copy_if(*begin, *end, *result, []() { }) ====================================================================\n";
            std::fill(result, result + cp1 + cp2, 0);
            //* copy 1 time ============================================================
            {
                std::cout << "copy1[]  = \t";
                print_array(copy1, cp1);
                std::copy_if(copy1, copy1 + 3, result, ([](int a) { return (a % 2) == 0; }));
                std::cout << "std::copy_if(copy1, copy1 + 3, result, ([](int a) { return (a % 2) == 0; }));\n";
                std::cout << "result[] = \t";
                print_array(result, cp1 + cp2);
                std::cout << std::endl;
                // copy1[]  =  [5  [2]  9]  6  1]
                // std::copy_if(copy1, copy1 + 3, result, ([](int a) { return (a % 2) == 0; }));
                // result[] =  [2]  0  0  0  0  0  0  0  0  0
            }
            //* copy n times ===========================================================
            {
                std::cout << "copy1[]  = \t";
                print_array(copy1, cp1);
                std::cout << "copy2[]  = \t";
                print_array(copy2, cp2);
                std::copy_if(copy1, copy1 + cp1, result, ([](int a) { return (a % 2) == 0; }));

                int *it{std::find(result, result + cp1 + cp2, 0)};

                std::copy_if(copy2, copy2 + cp2, it, ([](int a) { return (a % 2) == 0; }));
                std::cout << "std::copy_if(copy1, copy1 + cp1, result, ([](int a) { return (a % 2) == 0; }));\n";
                std::cout << "std::copy_if(copy2, copy2 + cp2, it, ([](int a) { return (a % 2) == 0; }));\n";
                std::cout << "result[] = \t";
                print_array(result, cp1 + cp2);
                std::cout << std::endl;
                // copy1[]  =  [5  [2]  9  [6]  1]
                // copy2[]  =  [[4]  3  [2]  1  7]
                // std::copy_if(copy1, copy1 + cp1, result, ([](int temp) { return (temp % 2) == 0; }));
                // std::copy_if(copy2, copy2 + cp2, it, ([](int temp) { return (temp % 2) == 0; }));
                // result[] =  [2]  [6]  [4]  [2]  0  0  0  0  0  0
            }
        }
        void copy_n() {
            std::cout << "std::copy_n(*begin1, range, *begin2) =============================================================================\n";
            //* thao tac voi 2 string ==================================================
            {
                std::string str1{"dandelion"};
                std::string str2{"badger"};
                std::cout << "str1 = \"" << str1 << "\"\n";
                std::cout << "str2 = \"" << str2 << "\"\n";
                // Copy the first 3 letters from s1
                // to the first 3 positions in s2
                std::cout << str1 << " + " << str2 << " = ";
                std::copy_n(str1.begin(), 3, str2.begin());
                std::cout << str2;
                std::cout << std::endl;
                std::cout << std::endl;
                // [dan]delion
                // [bad]ger
                // [dan][ger]
            }
            //* thao tac voi mang chan lam :< ==========================================
            {
                int source1[5] = {1, 2, 3, 4, 5};
                int source2[7] = {0, 0, 0, 4, 5, 6, 7};
                std::cout << "source1[5] = \t";
                print_array(source1, 5);
                std::cout << "source2[7] = \t";
                print_array(source2, 7);
                // sao chep 3 phan tu dau cua source1 sang 3 phan tu dau cua source2 con lai van duoc giu nguyen
                std::copy_n(source1, 3, source2);
                std::cout << "std::copy_n(source1, 3, source2);\n";
                std::cout << "source2[7] = \t";
                print_array(source2, 7);
                std::cout << std::endl;
                // source1[5] =    [1  2  3]  4  5
                // source2[7] =    [0  0  0]  4  5  6  7
                // std::copy_n(source1, 3, source2);
                // source2[7] =    [1  2  3]  4  5  6  7
            }
        }
    }  // namespace copy

    namespace compare {
        void equal(int arrN[], int n, int arrM[], int m) {
            std::cout << "std::equal(*begin1, *end1, *begin2\'[\', *end2\']\') =================================================================\n";
            //* không sort ================================================================
            {
                std::cout << "arrN[] = \t";
                print_array(arrN, n);
                std::cout << "arrM[] = \t";
                print_array(arrM, m);
                if (std::equal(arrN, arrN + n, arrM)) {
                    std::cout << "Bang nhau\n";
                } else {
                    std::cout << "Khong bang nhau\n";
                }
                std::cout << std::endl;
                // arrN[] =  2  4  3  7  6  6  9  10  12  11  8  3  2
                // arrM[] =  2  2  3  3  4  6  6  7  8  9  10  11  12
                // Khong bang nhau la cai chac=))
            }
            //* sorted =================================================================
            {
                std::sort(arrN, arrN + n);
                std::cout << "arrN[] = \t";
                std::sort(arrM, arrM + m);
                print_array(arrN, n);
                std::cout << "arrM[] = \t";
                print_array(arrM, m);
                if (std::equal(arrN, arrN + n, arrM)) {
                    std::cout << "Bang nhau\n";
                } else {
                    std::cout << "Khong bang nhau\n";
                }
                std::cout << std::endl;
                // arrN[] =  2  2  3  3  4  6  6  7  8  9  10  11  12
                // arrM[] =  2  2  3  3  4  6  6  7  8  9  10  11  12
                // Chac chan la bang nhau roi
            }
        }
        //! ============================================================================
        // void equal_range() {}
        // void lexicographical_compare() {}
    }  // namespace compare

    namespace loop {
        //! ============================================================================
        // void for_each() {}
        // void for_each_n() {}
    }

    namespace minmax {
        void max(int arr[], int n) {
            std::cout << "std::max(*begin, *end)============================================================================================\n";
            print_array(arr, n);
            int maximum_value = std::max(arr[0], arr[1]);
            std::cout << "Maximum value between " << arr[0] << " and " << arr[1] << " is: " << maximum_value << '\n';
            std::cout << std::endl;
        }
        void min(int arr[], int n) {
            std::cout << "std::min(*begin, *end)============================================================================================\n";
            print_array(arr, n);
            int minimum_value = std::min(arr[0], arr[1]);
            std::cout << "Minimum value between " << arr[0] << " and " << arr[1] << " is: " << minimum_value << '\n';
            std::cout << std::endl;
        }
        void minmax(int arr[], int n) {
            std::cout << "std::minmax(*begin, *end)=========================================================================================\n";
            print_array(arr, n);
            std::pair<int, int> minmax_values = std::minmax(arr[0], arr[1]);
            std::cout << "Minimum value: " << minmax_values.first << '\n';
            std::cout << "Maximum value: " << minmax_values.second << '\n';
            std::cout << std::endl;
        }
        void max_element(int arr[], int n) {
            std::cout << "std::max_element(*begin, *end)====================================================================================\n";
            print_array(arr, n);
            int *max_element = std::max_element(arr, arr + n);
            std::cout << "Maximum element in the array is: " << *max_element << '\n';
            std::cout << std::endl;
        }
        void min_element(int arr[], int n) {
            std::cout << "std::min_element(*begin, *end)====================================================================================\n";
            print_array(arr, n);
            int *min_element = std::min_element(arr, arr + n);
            std::cout << "Minimum element in the array is: " << *min_element << '\n';
            std::cout << std::endl;
        }
        void minmax_element(int arr[], int n) {
            std::cout << "std::minmax_element(*begin, *end)=================================================================================\n";
            print_array(arr, n);
            std::pair<int *, int *> minmax_element_pair = std::minmax_element(arr, arr + n);
            std::cout << "Minimum element in the array is: " << *minmax_element_pair.first << '\n';
            std::cout << "Maximum element in the array is: " << *minmax_element_pair.second << '\n';
            std::cout << std::endl;
        }
    }  // namespace minmax

    void move(int arr[], int n) {
        std::cout << "std::move(*begin1, *end1, *begin2) ===============================================================================\n";
        int moveArr[n] = {};
        std::cout << "Truoc khi std::move\n";
        print_array(arr, n);
        print_array(moveArr, n);
        std::cout << "Sau khi std::move\n";
        std::move(arr, arr + n, moveArr);
        print_array(arr, n);
        print_array(moveArr, n);
        std::cout << std::endl;
        // Truoc khi std::move
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
        // Sau khi std::move
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
    }
    void move_backward(int arr[], int n) {
        std::cout << "std::move_backward(*begin1, *end1, *end2) ========================================================================\n";
        int moveArr[n] = {};
        std::cout << "Truoc khi std::move_backward\n";
        print_array(arr, n);
        print_array(moveArr, n);
        std::cout << "Sau khi std::move_backward\n";
        std::move_backward(arr, arr + n, moveArr + n);
        print_array(arr, n);
        print_array(moveArr, n);
        std::cout << std::endl;
        // Truoc khi std::move_backward
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
        // Sau khi std::move_backward
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
    }

    void fill(int arr[], int n) {
        std::cout << "std::fill(*begin, *end, value) ===================================================================================\n";
        print_array(arr, n);
        std::fill(arr, arr + n, 0);
        print_array(arr, n);
        std::cout << std::endl;
    }
    void fill_n() {
        std::cout << "std::fill_n(*begin, range, value) ================================================================================\n";
        int arr[9] = {};
        print_array(arr, 9);
        // Fill the first 3 positions with a value of 1, saving position.
        int *it{std::fill_n(arr, 3, 1)};
        print_array(arr, 9);
        // Fill the next 3 positions with a value of 2, using last position.
        it = std::fill_n(it, 3, 2);
        print_array(arr, 9);
        // Fill the last 3 positions with a value of 3, using relative math.
        it = std::fill_n(it, 3, 3);
        print_array(arr, 9);
        std::cout << std::endl;
        // 0  0  0   0  0  0  0  0  0
        // [1  1  1]  0  0  0  0  0  0
        // 1  1  1  [2  2  2]  0  0  0
        // 1  1  1  2  2  2  [3  3  3]
    }

    void replace() {
        std::cout << "std::replace(*begin, *end, value1, value2) =======================================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        print_array(arr, n);
        std::replace(arr, arr + n, 2, 0);
        print_array(arr, n);
        std::replace(arr, arr + n, 6, 0);
        print_array(arr, n);
        std::replace(arr, arr + n, 12, 0);
        print_array(arr, n);
        std::cout << std::endl;
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // 0  4  3  12  7  6  6  9  10  18  12  11  8  3  0
        // 0  4  3  12  7  0  0  9  10  18  12  11  8  3  0
        // 0  4  3  0   7  0  0  9  10  18  0   11  8  3  0
    }
    void replace_if() {
        std::cout << "std::replace_if(*begin, *end, []() { }, value) ===================================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        print_array(arr, n);
        std::replace_if(
            arr, arr + n, [](int a) { return (a == 2) || (a == 6) || (a == 12); }, 0);
        print_array(arr, n);
        std::cout << std::endl;
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // 0  4  3  0   7  0  0  9  10  18  0   11  8  3  0
    }
    void replace_copy() {
        std::cout << "std::replace_copy(*begin, *end, *result, value1, value2) =========================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        int ans[n] = {};
        print_array(arr, n);
        print_array(ans, n);
        std::replace_copy(arr, arr + n, ans, 12, 0);
        print_array(ans, n);
        std::cout << std::endl;
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // 0  0  0  0   0  0  0  0  0   0   0   0   0  0  0
        // 2  4  3  0   7  6  6  9  10  18  0   11  8  3  2
    }
    void replace_copy_if() {
        std::cout << "std::replace_copy_if(*begin, *end, *result, []() { }, value]) ====================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        int ans[n] = {};
        print_array(arr, n);
        print_array(ans, n);
        std::replace_copy_if(
            arr, arr + n, ans, [](int a) { return a == 12; }, 0);
        print_array(ans, n);
        std::cout << std::endl;
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // 0  0  0  0   0  0  0  0  0   0   0   0   0  0  0
        // 2  4  3  0   7  6  6  9  10  18  0   11  8  3  2
    }

    void reverse() {
        std::cout << "std::reverse(*begin, *end) =======================================================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        print_array(arr, n);
        std::reverse(arr, arr + n);
        print_array(arr, n);
        std::cout << std::endl;
        // 2  4  3  12  7   6   6   9  10  18  12  11  8  3  2
        // 2  3  8  11  12  18  10  9  6   6   7   12  3  4  2
    }
    void reverse_copy() {
        std::cout << "std::reverse_copy(*begin, *end, *result) =========================================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        int ans[n] = {};
        print_array(arr, n);
        print_array(ans, n);
        std::reverse_copy(arr, arr + n, ans);
        print_array(arr, n);
        print_array(ans, n);
        std::cout << std::endl;
        // 2  4  3  12  7   6   6   9  10  18  12  11  8  3  2
        // 0  0  0  0   0   0   0   0  0   0   0   0   0  0  0
        // 2  4  3  12  7   6   6   9  10  18  12  11  8  3  2
        // 2  3  8  11  12  18  10  9  6   6   7   12  3  4  2
    }

    void rotate() {
        // =================
        // ||  3 *        ||
        // 9 8 7 6 5 4 3 2 1
        //   <==============
        // 6 5 4 3 2 1 9 8 7
        std::cout << "std::rotate(*begin, *begin + range, *end) ========================================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        print_array(arr, n);
        std::cout << "std::rotate(arr, arr + 5, arr + n);\n";
        std::rotate(arr, arr + 5, arr + n);
        print_array(arr, n);
        std::cout << std::endl;
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // std::rotate(arr, arr + 5, arr + n);
        // 6  6  9  10  18  12  11  8  3  2  2  4  3  12  7
    }
    void rotate_copy() {
        std::cout << "std::rotate_copy(*begin, *begin + range, *end, *result) ===========================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        int ans[n] = {};
        print_array(arr, n);
        print_array(ans, n);
        std::cout << "std::rotate_copy(arr, arr + 5, arr + n, ans);\n";
        std::rotate_copy(arr, arr + 5, arr + n, ans);
        print_array(arr, n);
        print_array(ans, n);
        std::cout << std::endl;
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
        // std::rotate_copy(arr, arr + 5, arr + n, ans);
        // 2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
        // 6  6  9  10  18  12  11  8  3  2  2  4  3  12  7
    }

    namespace permutation {
        //! ============================================================================
        // void is_permutation() {}
        // void next_permutation() {}
        // void prev_permutation() {}
    }

    namespace partition {
        //! ============================================================================
        // void is_partitioned() {}
        // void partition() {}
        // void partition_copy() {}
        // void partition_point() {}
        // void stable_partition() {}
    }

    namespace generate {
        //! ============================================================================
        // void generate() {}
        // void generate_n() {}
        // void shuffle() {}
        // void random_shuffle() {}
    }

    namespace heap {
        //! ============================================================================
        // void is_heap() {}
        // void push_heap() {}
        // void pop_heap() {}
        // void make_heap() {}
        // void sort_heap() {}
    }

    void remove() {
        std::cout << "std::remove(*begin, *end, value) =================================================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        print_array(arr, n);
        int *it{std::remove(arr, arr + n, 2)};
        for (int *i{arr}; i != it; ++i) {
            std::cout << *i << '\t';
        }
        std::cout << std::endl;
        it = std::remove(arr, it, 6);
        for (int *i{arr}; i != it; ++i) {
            std::cout << *i << '\t';
        }
        std::cout << std::endl;
        it = std::remove(arr, it, 12);
        for (int *i{arr}; i != it; ++i) {
            std::cout << *i << '\t';
        }
        std::cout << std::endl;
        std::cout << std::endl;
        // 2  4  3   12  7   6   6   9   10  18  12  11  8  3  2
        // 4  3  12  7   6   6   9   10  18  12  11  8   3
        // 4  3  12  7   9   10  18  12  11  8   3
        // 4  3  7   9   10  18  11  8   3
    }
    void remove_if() {
        std::cout << "std::remove_if(*begin, *end, []() { }]) ==========================================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        print_array(arr, n);
        int *it{std::remove_if(arr, arr + n, [](int a) { return (a == 2) || (a == 6) || (a == 12); })};
        for (int *i{arr}; i != it; ++i) {
            std::cout << *i << '\t';
        }
        std::cout << std::endl;
        std::cout << std::endl;
        // 2  4  3   12  7   6   6   9   10  18  12  11  8  3  2
        // 4  3  7   9   10  18  11  8   3
    }
    void remove_copy() {
        std::cout << "std::remove_copy(*begin, *end, *result, value) ===================================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        int ans[n] = {};
        print_array(arr, n);
        print_array(ans, n);
        std::remove_copy(arr, arr + n, ans, 12);
        print_array(ans, n);
        std::cout << std::endl;
        // 2  4  3  12  7  6  6  9   10  18  12  11  8  3  2
        // 0  0  0  0   0  0  0  0   0   0   0   0   0  0  0
        // 2  4  3  7   6  6  9  10  18  11  8   3   2  0  0
    }
    void remove_copy_if() {
        std::cout << "std::remove_copy_if(*begin, *end, *result, []() { }]) ============================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        int ans[n] = {};
        print_array(arr, n);
        print_array(ans, n);
        std::remove_copy_if(arr, arr + n, ans, [](int a) { return a == 12; });
        print_array(ans, n);
        std::cout << std::endl;
        // 2  4  3  12  7  6  6  9   10  18  12  11  8  3  2
        // 0  0  0  0   0  0  0  0   0   0   0   0   0  0  0
        // 2  4  3  7   6  6  9  10  18  11  8   3   2  0  0
    }

    void unique() {
        std::cout << "std::unique(*begin, *end) ===================================================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        print_array(arr, n);
        std::sort(arr, arr + n);
        print_array(arr, n);
        int *it{std::unique(arr, arr + n)};
        for (int *i{arr}; i != it; ++i) {
            std::cout << *i << '\t';
        }
        std::cout << std::endl;
        print_array(arr, n);
        std::cout << std::endl;
        // 2  4  3  12  7  6  6  9   10  18  12  11  8   3   2
        // 2  2  3  3   4  6  6  7   8   9   10  11  12  12  18
        // 2  3  4  6   7  8  9  10  11  12  18
        // 2  3  4  6   7  8  9  10  11  12  18  11  12  12  18
    }
    void unique_copy() {
        std::cout << "std::unique_copy(*begin, *end, *result) ==========================================================================\n";
        constexpr int n{15};
        int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
        int ans[n] = {};
        print_array(arr, n);
        print_array(ans, n);
        std::sort(arr, arr + n);
        print_array(arr, n);
        print_array(ans, n);
        int *it{std::unique_copy(arr, arr + n, ans)};
        for (int *i{ans}; i != it; ++i) {
            std::cout << *i << '\t';
        }
        std::cout << std::endl;
        std::cout << std::endl;
        // 2  4  3  12  7  6  6  9   10  18  12  11  8   3   2
        // 0  0  0  0   0  0  0  0   0   0   0   0   0   0   0
        // 2  2  3  3   4  6  6  7   8   9   10  11  12  12  18
        // 0  0  0  0   0  0  0  0   0   0   0   0   0   0   0
        // 2  3  4  6   7  8  9  10  11  12  18
    }

    namespace swap {
        void swap() {
            std::cout << "std::swap(x, y) ==================================================================================================\n";
            int x = 5, y = 10;
            std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
            std::swap(x, y);
            std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
            std::cout << std::endl;
        }
        void swap_ranges() {
            std::cout << "std::swap_ranges(*begin1, *end1, *begin2) =============================================================================\n";
            constexpr int n{10};
            int arr1[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int arr2[n] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
            print_array(arr1, n);
            print_array(arr2, n);
            std::swap_ranges(arr1, arr1 + n, arr2);
            print_array(arr1, n);
            print_array(arr2, n);
            std::cout << std::endl;
        }
        //! ================================================================================
        // void iter_swap() {}
    }  // namespace swap

    namespace merge {
        void includes(int copy1[], int cp1, int copy2[], int cp2) {
            std::cout << "std::includes(*begin1, *end1, *begin2, *end2) ====================================================================\n";
            //* không sort ================================================================
            {
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                if (std::includes(copy1, copy1 + cp1, copy2, copy2 + cp2)) {
                    std::cout << "copy1 chua copy2 (copy2 con copy1)\n";
                } else {
                    std::cout << "copy1 khong chua copy2\n";
                }
                std::cout << std::endl;
                // 1  2  3  4  5  6  7  8
                // 4  7  8  3
                // copy1 khong chua copy2
            }
            //* sorted =================================================================
            {
                std::sort(copy1, copy1 + cp1);
                std::sort(copy2, copy2 + cp2);
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                if (std::includes(copy1, copy1 + cp1, copy2, copy2 + cp2)) {
                    std::cout << "copy1 chua copy2 (copy2 con copy1)\n";
                } else {
                    std::cout << "copy1 khong chua copy2\n";
                }
                std::cout << std::endl;
                // 1  2  3  4  5  6  7  8
                // 4  7  8  3
                // copy1 chua copy2 (copy2 con copy1)
            }
        }
        void merge(int copy1[], int cp1, int copy2[], int cp2) {
            std::cout << "std::merge(*begin1, *end1, *begin2, *end2, *result) ==============================================================\n";
            //* không sort ================================================================
            {
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                int result[cp1 + cp2] = {};
                std::merge(copy1, copy1 + cp1, copy2, copy2 + cp2, result);
                print_array(result, cp1 + cp2);
                std::cout << std::endl;
                // 1  6  8  5  4  2  7  3
                // 4  7  8  3
                // 1  4  6  7  8  5  4  2  7  3  8  3
            }
            //* sorted =================================================================
            {
                std::sort(copy1, copy1 + cp1);
                std::sort(copy2, copy2 + cp2);
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                int result[cp1 + cp2] = {};
                std::merge(copy1, copy1 + cp1, copy2, copy2 + cp2, result);
                print_array(result, cp1 + cp2);
                std::cout << std::endl;
                // 1  2  3  4  5  6  7  8
                // 3  4  7  8
                // 1  2  3  3  4  4  5  6  7  7  8  8
            }
        }
        void inplace_merge(int copy1[], int cp1, int copy2[], int cp2) {
            std::cout << "std::inplace_merge(*begin, *middle, *end) ========================================================================\n";
            //* không sort ================================================================
            {
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                // Merge phần đầu của dãy copy1 với phần còn lại của dãy copy2
                std::inplace_merge(copy1, copy1 + cp1, copy2 + cp2);
                print_array(copy1, cp1 + cp2);
                std::cout << std::endl;
                // 1  6  8  5  4  2  7  3
                // 4  7  8  3
                // 1  4  6  7  8  3  4  5  2  7  8  3
            }
            //* sorted =================================================================
            {
                std::sort(copy1, copy1 + cp1);
                std::sort(copy2, copy2 + cp2);
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                // Merge phần đã sắp xếp của dãy copy1 với phần đã sắp xếp của dãy copy2
                std::inplace_merge(copy1, copy1 + cp1, copy2 + cp2);
                print_array(copy1, cp1 + cp2);
                std::cout << std::endl;
                // 1  2  3  4  5  6  7  8
                // 3  4  7  8
                // 1  2  3  3  4  4  5  6  7  7  8  8
            }
        }
        void set_difference() {
            std::cout << "std::set_difference(*begin1, *end1, *begin2, *end2, *result) =====================================================\n";
            //* không sort ================================================================
            {
                constexpr int cp1{10};
                constexpr int cp2{5};
                int copy1[cp1] = {1, 6, 8, 5, 4, 2, 7, 3, 2, 9};
                int copy2[cp2] = {4, 7, 8, 3, 5};
                int ans[cp1 + cp2] = {};
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                print_array(ans, cp1 + cp2);
                std::set_difference(copy1, copy1 + cp1, copy2, copy2 + cp2, ans);
                print_array(ans, cp1 + cp2);
                std::cout << std::endl;
            }
            //* sorted =================================================================
            {
                constexpr int cp1{10};
                constexpr int cp2{5};
                int copy1[cp1] = {1, 6, 8, 5, 4, 2, 7, 3, 2, 9};
                int copy2[cp2] = {4, 7, 8, 3, 5};
                int ans[cp1 + cp2] = {};
                std::sort(copy1, copy1 + cp1);
                std::sort(copy2, copy2 + cp2);
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                print_array(ans, cp1 + cp2);
                std::set_difference(copy1, copy1 + cp1, copy2, copy2 + cp2, ans);
                print_array(ans, cp1 + cp2);
                std::cout << std::endl;
            }
        }
        void set_intersection() {
            std::cout << "std::set_intersection(*begin1, *end1, *begin2, *end2, *result) ===================================================\n";
            //* không sort ================================================================
            {
                constexpr int cp1{10};
                constexpr int cp2{5};
                int copy1[cp1] = {1, 6, 8, 5, 4, 2, 7, 3, 2, 9};
                int copy2[cp2] = {4, 7, 8, 3, 5};
                int ans[cp1 + cp2] = {};
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                print_array(ans, cp1 + cp2);
                std::set_intersection(copy1, copy1 + cp1, copy2, copy2 + cp2, ans);
                print_array(ans, cp1 + cp2);
                std::cout << std::endl;
            }
            //* sorted =================================================================
            {
                constexpr int cp1{10};
                constexpr int cp2{5};
                int copy1[cp1] = {1, 6, 8, 5, 4, 2, 7, 3, 2, 9};
                int copy2[cp2] = {4, 7, 8, 3, 5};
                int ans[cp1 + cp2] = {};
                std::sort(copy1, copy1 + cp1);
                std::sort(copy2, copy2 + cp2);
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                print_array(ans, cp1 + cp2);
                std::set_intersection(copy1, copy1 + cp1, copy2, copy2 + cp2, ans);
                print_array(ans, cp1 + cp2);
                std::cout << std::endl;
            }
        }
        void set_union() {
            std::cout << "std::set_union(*begin1, *end1, *begin2, *end2, *result) ==========================================================\n";
            //* không sort ================================================================
            {
                constexpr int cp1{10};
                constexpr int cp2{5};
                int copy1[cp1] = {1, 6, 8, 5, 4, 2, 7, 3, 2, 9};
                int copy2[cp2] = {4, 7, 8, 3, 5};
                int ans[cp1 + cp2] = {};
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                print_array(ans, cp1 + cp2);
                std::set_union(copy1, copy1 + cp1, copy2, copy2 + cp2, ans);
                print_array(ans, cp1 + cp2);
                std::cout << std::endl;
            }
            //* sorted =================================================================
            {
                constexpr int cp1{10};
                constexpr int cp2{5};
                int copy1[cp1] = {1, 6, 8, 5, 4, 2, 7, 3, 2, 9};
                int copy2[cp2] = {4, 7, 8, 3, 5};
                int ans[cp1 + cp2] = {};
                std::sort(copy1, copy1 + cp1);
                std::sort(copy2, copy2 + cp2);
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                print_array(ans, cp1 + cp2);
                std::set_union(copy1, copy1 + cp1, copy2, copy2 + cp2, ans);
                print_array(ans, cp1 + cp2);
                std::cout << std::endl;
            }
        }
        void set_symmetric_difference() {
            std::cout << "std::set_symmetric_difference(*begin1, *end1, *begin2, *end2, *result) ===========================================\n";
            //* không sort ================================================================
            {
                constexpr int cp1{10};
                constexpr int cp2{5};
                int copy1[cp1] = {1, 6, 8, 5, 4, 2, 7, 3, 2, 9};
                int copy2[cp2] = {4, 7, 8, 3, 5};
                int ans[cp1 + cp2] = {};
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                print_array(ans, cp1 + cp2);
                std::set_symmetric_difference(copy1, copy1 + cp1, copy2, copy2 + cp2, ans);
                print_array(ans, cp1 + cp2);
                std::cout << std::endl;
            }
            //* sorted =================================================================
            {
                constexpr int cp1{10};
                constexpr int cp2{5};
                int copy1[cp1] = {1, 6, 8, 5, 4, 2, 7, 3, 2, 9};
                int copy2[cp2] = {4, 7, 8, 3, 5};
                int ans[cp1 + cp2] = {};
                std::sort(copy1, copy1 + cp1);
                std::sort(copy2, copy2 + cp2);
                print_array(copy1, cp1);
                print_array(copy2, cp2);
                print_array(ans, cp1 + cp2);
                std::set_symmetric_difference(copy1, copy1 + cp1, copy2, copy2 + cp2, ans);
                print_array(ans, cp1 + cp2);
                std::cout << std::endl;
            }
        }
    }  // namespace merge

    void transform() {
        std::cout << "transform(*begin1, *end1, *begin2, *result, []() { }) ============================================================\n";
        //* transform itself =======================================================
        {
            constexpr int n{15};
            int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
            print_array(arr, n);
            std::transform(arr, arr + n, arr, [](int &a) { return a * 2; });
            print_array(arr, n);
            std::cout << std::endl;
            // arr[] 2  4  3  12  7   6   6   9   10  18  12  11  8   3  2
            // arr[] 4  8  6  24  14  12  12  18  20  36  24  22  16  6  4
        }
        //* transform another ======================================================
        {
            constexpr int n{15};
            int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
            int ans[n] = {};
            print_array(arr, n);
            print_array(ans, n);
            std::transform(arr, arr + n, ans, [](int &a) { return a * 2; });
            print_array(arr, n);
            std::cout << std::endl;
            std::cout << std::endl;
            // arr[] 2  4  3  12  7   6   6   9   10  18  12  11  8   3  2
            // ans[] 0  0  0  0   0   0   0   0   0   0   0   0   0   0  0
            // arr[] 2  4  3  12  7   6   6   9   10  18  12  11  8   3  2
            // ans[] 4  8  6  24  14  12  12  18  20  36  24  22  16  6  4
        }
        //* transform itself 2 =====================================================
        {
            constexpr int n{15};
            int arr1[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
            int arr2[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
            std::sort(arr1, arr1 + n);
            std::sort(arr2, arr2 + n, [](int &a, int &b) { return a >= b; });
            print_array(arr1, n);
            print_array(arr2, n);
            std::transform(arr1, arr1 + n, arr2, arr2, [](int &a, int &b) { return a + b; });
            print_array(arr1, n);
            print_array(arr2, n);
            std::cout << std::endl;
            // arr1[] 2   2   3   3   4   6   6   7   8   9   10  11  12  12  18
            // arr2[] 18  12  12  11  10  9   8   7   6   6   4   3   3   2   2
            // arr1[] 2   2   3   3   4   6   6   7   8   9   10  11  12  12  18
            // arr2[] 20  14  15  14  14  15  14  14  14  15  14  14  15  14  20
        }
        //* transform 2 arrays and return 3th array ================================
        {
            constexpr int n{15};
            int arr1[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
            int arr2[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};
            std::sort(arr1, arr1 + n);
            std::sort(arr2, arr2 + n, [](int &a, int &b) { return a >= b; });
            int ans[n] = {};
            print_array(arr1, n);
            print_array(arr2, n);
            print_array(ans, n);
            std::transform(arr1, arr1 + n, arr2, ans, [](int &a, int &b) { return a + b; });
            print_array(arr1, n);
            print_array(arr2, n);
            print_array(ans, n);
            std::cout << std::endl;
            // arr1[] 2   2   3   3   4   6   6   7   8   9   10  11  12  12  18
            // arr2[] 18  12  12  11  10  9   8   7   6   6   4   3   3   2   2
            // ans[]  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
            // arr1[] 2   2   3   3   4   6   6   7   8   9   10  11  12  12  18
            // arr2[] 18  12  12  11  10  9   8   7   6   6   4   3   3   2   2
            // ans[]  20  14  15  14  14  15  14  14  14  15  14  14  15  14  20
        }
    }
}  // namespace cst

int main() {
    // https://learn.microsoft.com/en-us/cpp/standard-library/algorithm-functions
    std::cout << std::endl;
    std::cout << "// Day la tutorial ve toan bo cac ham trong thu vien <algorithm>\n";
    std::cout << "// De thuan tien cho viec theo doi.\n";
    std::cout << "// Cac ham se duoc phan theo nhom chuc nang cua chung.\n";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    {
        std::cout << "1. sort   #############################################################################################################\n";
        std::cout << std::endl;
        {
            constexpr int n{15};
            int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};

            std::cout << "std::is_sorted(*begin, *end) =============================================================================================\n";
            std::cout << "// std::is_sorted(arr, arr + n);\n";
            std::cout << "arr[]\t";
            cst::print_array(arr, n);
            cst::sort::is_sorted(arr, n);
            std::cout << std::endl;
            // arr[]   2  4  3  12  7  6  6  9  10  18  12  11  8  3  2
            // Mang chua duoc sap xep!

            std::cout << "std::sort(*begin, *end) ==================================================================================================\n";
            std::cout << "// std::sort(arr, arr + n);\n";
            std::cout << "Sau khi sap xep:\n";
            std::cout << "arr[]\t";
            cst::sort::sort(arr, n);
            cst::print_array(arr, n);
            std::cout << "Kiem tra bang std::is_sorted(): ";
            cst::sort::is_sorted(arr, n);
            std::cout << std::endl;
            // arr[]   2  2  3  3  4  6  6  7  8  9  10  11  12  12  18
            // Kiem tra bang std::is_sorted(): Mang da duoc sap xep!

            std::cout << "std::sort(*begin, *end, std::greater<int>()) <=> std::sort(*begin, *end, [](int a, int b) { return a >= b; }) ============\n";
            std::cout << "// std::sort(arr, arr + n, std::greater<int>());\n";
            std::cout << "Sau khi sap xep theo chieu nguoc lai:\n";
            std::cout << "arr[]\t";
            cst::sort::sort(arr, n, true);
            cst::print_array(arr, n);
            std::cout << "Kiem tra bang std::is_sorted( , , std::greater<int>()): ";
            cst::sort::is_sorted(arr, n, true);
            std::cout << std::endl;
            // arr[]   18  12  12  11  10  9  8  7  6  6  4  3  3  2  2
            // Kiem tra bang std::is_sorted( , , std::greater<int>()): Mang da duoc sap xep!
        }
        {
            constexpr int n{15};
            int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};

            std::cout << "std::stable_sort(*begin, *end) ===========================================================================================\n";
            std::cout << "// std::stable_sort(arr, arr + n);\n";
            std::cout << "// La thuan toan on dinh, nhung cham hon std::sort()\n";
            cst::sort::stable_sort(arr, n);
            std::cout << "arr[]\t";
            cst::print_array(arr, n);
            std::cout << std::endl;
            // arr[]   2  2  3  3  4  6  6  7  8  9  10  11  12  12  18

            std::cout << "std::stable_sort(*begin, *end, std::greater<int>()) <=> std::stable_sort(*begin, *end, [](int a, int b) { return a >= b; })\n";
            std::cout << "// std::stable_sort(arr, arr + n, std::greater<int>());\n";
            std::cout << "Sau khi sap xep theo chieu nguoc lai:\n";
            std::cout << "arr[]\t";
            cst::sort::stable_sort(arr, n, true);
            cst::print_array(arr, n);
            std::cout << std::endl;
            // arr[]   18  12  12  11  10  9  8  7  6  6  4  3  3  2  2
        }
        {
            constexpr int n{15};
            constexpr int range{5};
            int arr[n] = {2, 4, 3, 12, 7, 6, 6, 9, 10, 18, 12, 11, 8, 3, 2};

            std::cout << "std::partial_sort(*begin, *begin + range, *end) ==========================================================================\n";
            std::cout << "// std::partial_sort(arr, arr + " << range << ", arr + n);\n";
            std::cout << "// Chi sap xep cac phan tu dau tien, cu the la " << range << ".\n";
            cst::sort::partial_sort(arr, n, range);
            std::cout << "arr[]\t";
            cst::print_array(arr, n);
            std::cout << std::endl;
            // arr[]   [2  2  3  3  4]  12  7  9  10  18  12  11  8  6  6

            std::cout << "std::partial_sort(*begin, *begin + range, *end, std::greater<int>()) =====================================================\n<=> std::partial_sort(*begin, *begin + range, *end, [](int a, int b) { return a >= b; })\n";
            std::cout << "// std::partial_sort(arr, arr + " << range << ", arr + n, std::greater<int>());\n";
            std::cout << "Sau khi sap xep theo chieu nguoc lai:\n";
            std::cout << "arr[]\t";
            cst::sort::partial_sort(arr, n, range, true);
            cst::print_array(arr, n);
            std::cout << std::endl;
            // arr[]   [18  12  12  11  10]  2  2  3  3  4  7  9  8  6  6
        }
        std::cout << std::endl;
    }

    return 0;
}
