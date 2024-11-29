#include <iostream>
#include <vector>
#include<set>

#define input_file "kite1.inp"
#define output_file "kite1.out"

using namespace std;

int n;

// Tập hợp lưu các độ cao từ input 
set<int> heights;

// Mảng lưu thứ hạng
vector<int> result;


void input_process()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    // Đọc độ cao của diều đầu tiên
    int h;    
    cin >> h;
    heights.insert(h);

    // Diều đầu tiên được xếp hạng 1
    result.push_back(1);

    // Thứ hạng của mỗi diều
    int rank;

    // Duyệt từng dòng còn lại của dữ liệu đầu vào
    for (int i = 1; i < n; ++i)
    {
        // Đọc độ cao của một diều mới
        cin >> h;

        // Nạp vào set heights
        heights.insert(h);

        // Tính thứ hạng của h vừa nạp bằng cách so vị trí với phần tử cuối cùng trong set
        rank = distance(heights.find(h), heights.end()); 

        // Ghi nhận thứ hạng
        result.push_back(rank);
    }
}

void output()
{
    freopen(output_file, "w", stdout);
    
    for (int i = 0; i < n - 1; ++i)
    {
        cout << result[i] << '\n';
    }
    
    cout << result[n - 1];
}


int main()
{
    input_process();
    output();

    return 0;
}