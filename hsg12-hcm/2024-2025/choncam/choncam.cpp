#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "choncam3.inp"
#define output_file "choncam3.out"

using namespace std;

int n;

// mảng tần số f lưu số lượng đang xét của các loại cam
vector<int> f(6, 0);

// mảng continuous dùng để đánh dấu tính liên tiếp của loại cam
vector<bool> continuous(6, false);

// output
int max_oranges = 0;
int best_type = 1;


// Hàm dùng để đánh dấu tính liên tiếp của loại cam
void mark(int first, int second)
{
    // Đặt lại cho tất cả đều là không liên tiếp
    fill(continuous.begin(), continuous.end(), false);

    // Đánh dấu liên tiếp cho hai loại đang xét
    continuous[first] = true;
    continuous[second] = true;
}


// Hàm dùng để xét nhiều nhất
void consider(int current_oranges, int current_type)
{
    if (current_oranges == max_oranges)
    {
        // Nếu loại đang xét bằng với giá trị lớn nhất
        // thì lấy loại có nhãn nhỏ nhất
        best_type = min(current_type, best_type);
    }
    else if (current_oranges > max_oranges)
    {
        // Nếu loại đang xét lớn hơn giá trị lớn nhất
        // thì cập nhật giá trị lớn nhất mới và loại mới
        max_oranges = current_oranges;
        best_type = current_type;
    }
}


void input_process()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);
    
    cin >> n;

    // hai loại cam trên một khay
    int first, second;
    
    // Duyệt từng khay
    for (int i = 0; i < n; ++i)
    {
        cin >> first >> second;
        
        // Nếu là loại thứ nhất đang liên tục thì tăng tần số lên 1
        // Ngược lại, không liên tục, thì đếm lại từ đầu, là 1
        if (continuous[first])
            f[first] += 1;
        else
            f[first] = 1;

        // Xét xem đã đạt được nhiều nhất hay chưa
        consider(f[first], first);

        // Nếu là loại cam thứ hai đang liên tục thì tăng tần số lên 1
        // Ngược lại, không liên tục, thì đếm lại từ đầu
        if (continuous[second])
            f[second] += 1;
        else
            f[second] = 1;

        // Xét xem đã đạt được nhiều nhất hay chưa
        consider(f[second], second);
        
        // Đánh dấu lại tính liên tục cho hai loại này
        mark(first, second);
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_oranges << ' ' << best_type;
}


int main()
{
    input_process();
    output();

    return 0;
}