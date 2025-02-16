#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

#define input_file "buatiec.inp"
#define output_file "buatiec.out"

using namespace std;

int n;
vector<int> H;

// Danh sách kề
map<int, vector<int>> adj;

// Mảng D dùng để lưu tổng độ vui vẻ
// D[l][0] là tổng độ vui vẻ lớn nhất nếu l không được chọn
// D[l][1] là tổng độ vui vẻ lớn nhất nếu l được chọn
vector<vector<int>> D;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    H.resize(n + 1);

    for (int i = 1; i < n + 1; ++i)
    {
        cin >> H[i];
    }

    int l, k;
    for (int i = 1; i < n; ++i)
    {
        cin >> l >> k;
        adj[k].push_back(l);
    }
}


// Hàm dùng để duyệt cây theo chiều sâu
void dfs(int k)
{
    // Khởi tạo khi chọn node k
    D[k][1] = H[k];

    // Duyệt từng con của node k
    for (int l : adj[k])
    {
        // Gọi đệ quy
        dfs(l);

        // Nếu chọn k thì không thể chọn con của k
        D[k][1] += D[l][0];

        // Nếu không chọn k thì có thể chọn hoặc không chọn con của k
        D[k][0] += max(D[l][0], D[l][1]);
    }
}


void process()
{
    // Khởi tạo D gồm n+1 hàng và 2 cột
    D.resize(n + 1, vector<int>(2, 0));

    // Gọi hàm dfs từ node 1 (giám đốc)
    dfs(1);

    // Tổng độ vui vẻ lớn nhất
    int result = D[1][1];

    // In kết quả
    freopen(output_file, "w", stdout);
    cout << result;
}


int main()
{
    input();
    process();

    return 0;
}