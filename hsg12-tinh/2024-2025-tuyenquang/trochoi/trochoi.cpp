#include <iostream>
#include <vector>
#include <map>

#define input_file "trochoi.inp"
#define output_file "trochoi.out"

using namespace std;

int n, k, q;

// Mảng lưu học sinh tham gia trò chơi
vector<int> students;

// Mảng chênh lệch (difference array) (dùng kiểu map để tránh trường hợp lớn)
map<int, int> diff;

// Mảng lưu tần số xuất hiện (dùng kiểu map để tránh trường hợp lớn)
map<int, int> join;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> k >> q;

    int l, r;
    for (int i = 1; i < k + 1; ++i)
    {
        cin >> l >> r;

        // Cộng 1 vào học sinh l
        diff[l]++;

        // Trừ 1 khỏi học sinh r + 1
        diff[r + 1]--;
    }

    // Đọc thông tin các học sinh cần kiểm tra
    students.resize(q + 1);

    for (int i = 1; i < q + 1; ++i)
    {
        cin >> students[i];
    }
}


// Áp dụng mảng chênh lệch và mảng cộng dồn
void process()
{
    // Khởi tạo giá trị cộng dồn hiện tại
    int current_count = 0;

    // Cập nhật giá trị cộng dồn
    int student_id, difference;   
    for (auto &d : diff)
    {
        student_id = d.first;
        difference = d.second;

        current_count += difference;
        join[student_id] = current_count;
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    for (int i = 1; i < q + 1; ++i)
    {
        // Tìm học sinh đầu tiên có mã số lớn hơn students[i]
        map<int, int>::iterator it = join.upper_bound(students[i]);

        // Nếu không tìm thấy học sinh students[i] thì in ra 0
        if (it == join.begin())
            cout << 0;
        else
            // Ngược lại, tìm thấy, thì in ra số trò chơi mà học sinh students[i] tham gia
            cout << prev(it)->second; 

        // Xuống dòng nếu không phải học sinh cuối cùng
        if (i != q) cout << '\n';
    }
}


int main()
{
    input();
    process();
    output();
    
    return 0;
}