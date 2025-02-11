#include <bits/stdc++.h>
using namespace std;

int n;
int ret = 1; // 최소가 1임

int a[101][101], visited[101][101]; // a는 깊이 정보, visited는 해당 칸 방문 여부

int dy[4] = {-1, 0, 1, 0}; //방문할 좌표 순서
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int d)
{
    visited[y][x] = 1; //일단 해당 좌표 방문 표시

    for (int i = 0; i < 4; i++) // 현재좌표에서 상하좌우 방문하기
    {
        int ny = y + dy[i]; // 방문할 y 좌표
        int nx = x + dx[i]; // 방문할 x 좌표
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) // 방문할 좌표가 경계값을 벗어나면 다음 좌표로로
        {
            continue;
        }
        if (!visited[ny][nx] && a[ny][nx] > d) // 방문할 좌표가 방문 표시가 안되어 있고 비 높이보다 높을경우
        {
            dfs(ny, nx, d); // 방문할 좌표에서 다시 dfs 실행
        }
    }
}

int main()
{
    cin >> n; // 총 크기 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //cin >> a[i][j];
            scanf("%d",&a[i][j]); // 좌표 하나씩 깊이 정보 입력
        }
    }

    for (int d = 1; d < 101; d++) // 비 높이가 1부터 100까지
    {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0); // visited 배열 0으로 초기화
        
        int cnt = 0; // 안잠긴 지역 카운트할 변수
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 각좌표를 돌면서
                if (a[i][j] > d && !visited[i][j]) // 비 높이보다 높고 해당 좌표를 방문하지 않았으면
                {
                    dfs(i, j, d); // dfs를 실행하여 인근영역까지 조사하기
                    cnt++; // 안잠긴 지역 카운트
                }
            }
        }
        ret = max(ret, cnt); // 비 높이로 인해 안잠긴 지역의 개수가 최대값인지 최신화
    }
    cout << ret << '\n'; // 최대 안잠긴 지역 갯수

    return 0;
}