//
// Created by songji on 2020/12/17.
//
#include <vector>

using namespace std;

const int MAX_N = 100, MAX_M = 100;
// A와 B의 정점의 개수
int n, m;
// adj[i][j] = Ai와 Bj의 연결 여부
bool adj[MAX_N][MAX_M];
// 각 정점에 매칭된 상대 정점의 번호 저장
vector<int> aMatch, bMatch;
// dfs()의 방문 여부
vector<bool> visited;
// A의 정점인 a에서 B의 매칭되지 않은 정점으로 가는 경로 찾기
bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;
    for (int b=0; b<m; ++b) {
        // a에서 b로 가는 경로가 있을 때
        if (adj[a][b]) {
            // b가 아직 매칭되지 않았다면 바로 연결 || b가 이미 매칭되어 있다면 bMatch[b]에서부터 시작해 증가 경로 찾기
            if (bMatch[b] == -1 || dfs(bMatch[b])) {
                // 증가 경로 발견! a와 b 매칭
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

int bipartiteMatch() {
    aMatch = vector<int>(n, -1);
    bMatch = vector<int>(m, -1);
    int size = 0;
    for (int start=0; start<n; ++start) {
        visited = vector<bool>(n, false);
        if (dfs(start)) ++ size;
    }
    return size;
}
