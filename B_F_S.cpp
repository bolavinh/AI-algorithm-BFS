#include<bits/stdc++.h>
using namespace std;

const int N = 100;

vector<int> adj[N + 1], Path;

bool visited[N + 1];

int n, m, S, T, L[N + 1], trace[N + 1];

void bfs(int s) {
    memset(visited, false, sizeof (visited));
    // gán tất cả phần tử ở mảng visited = false tức là chưa có đỉnh nào được thăm
    queue<int> q;
    q.push(s);
    L[s] = 0;
    // đường đi từ s tới chính nó được cho là 0
    visited[s] = true;
    // đã thăm đỉnh s
    while (q.size()) {
        // trong khi q chưa rỗng
        int u = q.front();
        // u là phần tử ở đầu hàng đợi q
        q.pop();
        // xóa u
        for (auto v : adj[u]) {
            // for v kề u
            if (visited[v] == false) {
                // nếu v chưa thăm
                L[v] = L[u] + 1;
                trace[v] = u;
                // gán trace[v] = u do u là đỉnh được xét liền trước v
                q.push(v);
                // push v vào cuối hàng đợi q
                visited[v] = true;
                // đánh dấu v đã được thăm
            }
        } 
    }
}

void find_path(int t) {
    int x = t;
    while (true) {
        Path.push_back(x);
        if (x == S) {
            break;
        }
        x = trace[x];
    }
    for (int i = Path.size() - 1; i >= 0; i--) {
        cout << Path[i] << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> S >> T;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        // tức v kề u
        adj[v].push_back(u);
        // tức u kề v
    }
    memset(L, -1, sizeof (L));
    // gán mọi phần tử ở mảng L là -1 tức hiện tại chưa tồn tại đường đi
    bfs(S);
    cout << L[T] << '\n';
    if (L[T] == -1) {
        return 0;
    }
    find_path(T);
    return 0;
}