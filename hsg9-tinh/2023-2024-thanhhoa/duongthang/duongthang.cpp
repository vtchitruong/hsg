#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "duongthang1.inp"
#define output_file "duongthang1.out"

using namespace std;

typedef long long int lli;

int n;

// mảng lưu hệ số góc a của các đường thẳng
vector<int> A;

// số cặp đường thẳng song song
lli parallel = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    int a, b;

    A.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i] >> b;
    }
}


void process()
{
    // Sắp xếp lại các hệ số góc a theo thứ tự tăng dần
    sort(A.begin(), A.end());

    // biến tạm dùng để lưu số lượng đường thẳng có cùng hệ số góc a
    lli tmp_count = 1;

    // Duyệt từng hệ số góc từ vị trí 1 trở đi
    for (int i = 1; i < n; ++i)
    {
        // Nếu hệ số góc vẫn như cũ
        if (A[i] == A[i - 1])
            // thì tăng số đường thẳng có cùng hệ số góc thêm 1
            tmp_count++;
        else
        {
            // Nếu có nhiều hơn 1 đường thẳng có cùng hệ số góc a
            if (tmp_count > 1)
                // thì tính số cặp song song
                parallel += tmp_count * (tmp_count - 1) / 2;
            
            // khởi tạo lại tmp_count để đếm lại cho hệ số góc mới
            tmp_count = 1;
        }
    }

    // Tính cho nhóm hệ số góc cuối cùng
    if (tmp_count > 1)
        parallel += tmp_count * (tmp_count - 1) / 2;
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << parallel;
}


int main()
{
    input();
    process();
    output();

    return 0;
}