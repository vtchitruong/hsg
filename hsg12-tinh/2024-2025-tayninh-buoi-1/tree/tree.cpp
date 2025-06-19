#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "tree.inp"
#define output_file "tree.out"

using namespace std;

const int MAX = 100002; 

int number_of_queries;

// nhãn của khu nút mới
int n;

// parent[i] là cha của nút i
int parent[MAX];

// children[i] là vector lưu các con trực tiếp của i
vector<int> children[MAX];

// tree_size[i] là số lượng nút trong cây con có gốc là i, bao gồm cả i
int tree_size[MAX];


// Hàm thêm nút con của nút u
void add(int u)
{
    // Nút mới có nhãn là n
    int new_node = n;

    // Thiết lập liên kết cha và con đối với nút mới
    parent[new_node] = u;
    children[u].push_back(new_node);

    // Khởi tạo kích thước cho nút mới
    tree_size[new_node] = 1;

    // Cập nhật kích thước cây con của các nút tổ tiên
    // bằng cách duyệt ngược từ u về gốc
    int current = u;
    while (current != -1)
    {
        tree_size[current]++;
        current = parent[current];
    }

    // Tăng nhãn cho nút tiếp theo
    n++;
}


// Hàm xoá nút u và hệ thống con cuả u
void remove(int u)
{
    // nút cha của nút u
    int p = parent[u];
    
    // kích thước của hệ thống con của u
    int size_u = tree_size[u];

    if (p != -1)
    {
        // Khai báo tham chiếu đến vector children[p]
        vector<int>& ref = children[p];

        // Xoá nút u (là con của nút p)
        ref.erase(remove(ref.begin(), ref.end(), u), ref.end());
    }
    
    // Cập nhật kích thước cây con của các nút tổ tiên
    // bằng cách duyệt ngược từ p về gốc
    int current = p;
    while (current != -1)
    {
        tree_size[current] -= size_u;
        current = parent[current];
    }
}


// Hàm lấy kích thước hệ thống con của u, gồm cả u
int get_size(int u)
{
    return tree_size[u];
}


void input_process()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);
    freopen(output_file, "w", stdout);

    // Khởi tạo nút 0
    parent[0] = -1;
    tree_size[0] = 1;
    
    // nhãn của nút tiếp theo sẽ là 1
    n = 1;

    // Đọc số truy vấn
    cin >> number_of_queries;

    // Duyệt từng truy vấn q
    for (int q = 0; q < number_of_queries; ++q)
    {
        char task;
        int u;
        cin >> task >> u;
        
        if (task == '+')
            add(u);
        else if (task == '-')
            remove(u);
        else
            cout << get_size(u) << '\n';
    }
}


int main()
{
    input_process();
    
    return 0;
}