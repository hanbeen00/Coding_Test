#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[54][54];
vector<vector<int>>chickenList;  // 각각의 조합의 경우의수 저장
vector<pair<int, int>> _home, chicken; // vector에 각각의 좌표 저장
int result = 987654321;

void combi(int start, vector<int>v){
    if(v.size()==m){ // 총 치킨집 중 m개 골랐으면
        
        // v에는 고른 치킨집의 인덱스 저장되어 있음
        // 아래 출력문으로 선택된 치킨집의 좌표 확인 가능
        /*for(int i=0 ; i< m;i++){
            cout << chicken[v[i]].first << " " << chicken[v[i]].second ;
        }
        cout << endl;*/

        chickenList.push_back(v); // 고른 치킨집의 인덱스를 push 하기
        return;
    }

    // 인덱스 0부터 치킨집 최대 개수까지 돌면서 조합 구하기
    for(int i = start + 1; i < chicken.size(); i++){
        v.push_back(i);
        combi(i,v);
        // 조합 수행 하고 나서 제일 뒤 제거 후 다른 경우의 수 수행
        v.pop_back();
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];

            // 집, 치킨집 좌표 각각 저장해놓기
            if(a[i][j] == 1)_home.push_back({i, j}); 
            if(a[i][j] == 2)chicken.push_back({i, j});
        }
    }

    // 조합 이용하여 치킨집 m개 고르기
    vector<int> v;
    combi(-1,v);

    //chickenList에는 치킨집의 조합의 경우들이 인덱스 형태로 저장되어 있음
    // 각각의 경우들을 cList에 넣기
    for(vector<int> cList : chickenList){
        int ret = 0;
        for(pair<int, int> home : _home){
            int _min = 987654321;

            // cList에는 치킨집 경우의 인덱스들이 저장되어 있음
            for(int ch : cList){ 
                int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
                _min = min( _min, _dist);
            }

            //집과 각각의 치킨집과의 최소 거리를 구하고 ret에 저장
            ret += _min;
        }

        result = min(result, ret);
    }
    cout << result << "\n";
    return 0;
}