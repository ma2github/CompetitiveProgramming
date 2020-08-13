vector<vector<int>> g(n+1);
for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
}
//out(G);
// BFS のためのデータ構造
vector<int> dist(n+1, -1); // 全頂点を「未訪問」に初期化
queue<int> que;

// 初期条件 (頂点 1 を初期ノードとする)
dist[1] = 0;
que.push(1); // 1 を橙色頂点にする

// BFS 開始 (キューが空になるまで探索を行う)
while (!que.empty()) {
    int v = que.front(); // キューから先頭頂点を取り出す
    que.pop();

    // v から辿れる頂点をすべて調べる
    for (int nv : g[v]) {
        if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

        // 新たな白色頂点 nv について距離情報を更新してキューに追加する
        dist[nv] = dist[v]+1;
        que.push(nv);
    }
}
