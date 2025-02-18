#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "choncam1.inp"
#define output_file "choncam1.out"

using namespace std;

int n;
vector<vector<int>> trays;

// Mảng tần số f
vector<int> f(6, 0);

// Mảng continuous dùng để đánh dấu tính liên tiếp của loại cam
vector<bool> continuous(6, false);


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);
    
    cin >> n;

    trays.resize(n, vector<int>(2));

    for (int i = 0; i < n; ++i)
    {
        cin >> trays[i][0] >> trays[i][1];
    }
}


// Hàm dùng để đánh dấu tính liên tiếp của loại cam
void mark(int first, int second)
{
    // Đặt tất cả phần tử trong mảng continuous đều là false
    fill(continuous.begin(), continuous.end(), false);

    // Đánh dấu liên tiếp
    continuous[first] = true;
    continuous[second] = true;
}


void process()
{
    // Biến lưu hai loại cam trên một khay
    int first, second;

    // Duyệt từng khay
    for (int i = 0; i < n; ++i)
    {
        // Đọc hai loại cam trong khay i
        first = trays[i][0];
        second = trays[i][1];

        // Nếu là loại cam thứ nhất đang liên tục thì tăng tần số lên 1
        // Ngược lại, không liên tục, thì đếm lại từ đầu
        if (continuous[first])
            f[first] += 1;
        else
            f[first] = 1;

        // Nếu là loại cam thứ hai đang liên tục thì tăng tần số lên 1
        // Ngược lại, không liên tục, thì đếm lại từ đầu
        if (continuous[second])
            f[second] += 1;
        else
            f[second] = 1;
        
        // Đánh dấu lại tính liên tục cho từng loại cam
        mark(first, second);
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    // Tìm loại cam có tần số lớn nhất
    vector<int>::iterator max_f = max_element(f.begin(), f.end());

    // Tìm số lượng của loại cam có tần số lớn nhất
    int orange_type = max_f - f.begin();
    int orange_count = *max_f;
    cout << orange_count << ' ' << orange_type;
}


int main()
{
    input();
    process();
    output();

    return 0;
}