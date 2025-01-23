#include<bits/stdc++.h>
using namespace std;
const int max_n = 104;

int n,m;
int a[max_n][max_n]; // 입력 들어갈 배열
int visited[max_n][max_n]; // 해당 좌표에서의 최단거리배열
int y, x;
int dy[4] = {-1,0,1,0}; // 시계방향을 좌표 이동
int dx[4] = {0,1,0,-1};

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&a[i][j]); //숫자입력을 연속적으로 받을때 사용
        }
    }

    queue<pair<int, int>> q; // x,y 좌표 받을 queue
    visited[0][0] = 1; // 처음 위치는 방문처리
    q.push({0,0}); // 방문했으니 push

    while(q.size()){ // 좌표 갈곳 없으면 반복문 탈출
        tie(y,x) = q.front(); // 방문한 경우의 수 하나 꺼내기
        q.pop();

        for(int i=0; i<4; i++){ // 위,우,아래,좌 순서로 갈수 있는곳 확인
            int ny = y + dy[i]; 
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; // 범위 벗어나면
            if(a[ny][nx] == 0) continue; // 막혀 있는 곳이면
            if(visited[ny][nx]) continue;  // 이미 갔던 곳이면

            visited[ny][nx] = visited[y][x] + 1; //최단거리 하나 추가
            q.push({ny,nx});
        }
    }
    printf("%d",visited[n-1][m-1]); // 끝 지점에서의 최단거리 cost
    return 0;
}