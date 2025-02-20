#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "tuongdong.inp"
#define output_file "tuongdong.out"

using namespace std;

int n, X;
vector<int> pictures;

// Số cách cần tìm
int number_of_ways = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> X;

    pictures.resize(n + 1, 0);

    for (int i = 1; i < n + 1; ++i)
    {
        cin >> pictures[i];
    }
}


void process()
{
    freopen(output_file, "w", stdout);

    // Sắp xếp mảng pictures theo thứ tự tăng dần
    sort(pictures.begin() + 1, pictures.end());

    // Giới hạn màu sắc tương đồng
    int limit;

    // Duyệt từng tranh từ 1 đến áp cuối
    for (int i = 1; i < n; ++i)
    {
        // Tính giới hạn màu sắc
        limit = pictures[i] + X;

        // Tìm vị trí đầu tiên mà màu sắc vượt quá giới hạn
        vector<int>::iterator it = upper_bound(pictures.begin() + i + 1, pictures.end(), limit);

        // Số cách chọn hai bức tranh chính là số lượng bức tranh thứ hai có thể chọn 
        number_of_ways += distance(pictures.begin() + i + 1, it);
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << number_of_ways;
}


int main()
{
    input();
    process();
    output();

    return 0;
}