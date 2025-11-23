#include <iostream>
#include <vector>
#include <set>

#define input_file "tangqua2.inp"
#define output_file "tangqua2.out"

using namespace std;

int n;
vector<int> A;
vector<int> B;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        A.push_back(a);
    }
}


void process()
{
    // Khởi tạo mảng đánh dấu granted, dùng để đánh dấu những món quà đã phát
    vector<char> granted(1000001, 0);
    
    B.resize(n);

    // Khởi tạo món quá có giá trị nhỏ nhất là 1
    int least = 1;

    // Duyệt tất cả món quà
    for (int i = 0; i < n; ++i)
    {
        // Đánh dấu món quà A[i] đã phát
        granted[A[i]] = 1;

        // Nếu món quà có giá trị least đã được phát
        while (granted[least] == 1)
        {
            // thì tăng least thêm 1
            least += 1;
        }

        // Ghi nhận least là giá trị nhỏ nhất tại món quà A[i] đang xét
        B[i] = least;
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    for (int i = 0; i < n; ++i)
    {
        cout << B[i];
        if (i < n - 1) cout << ' ';
    }
}


int main()
{
    input();
    process();
    output();
    return 0;
}
