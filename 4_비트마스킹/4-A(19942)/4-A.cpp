#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;  // cost 최소를 구해야 하므로 최대값 설정
int n, mp, mf, ms, mv;
int b, c, d, e, ret = INF, sum;

struct A{
    int mp, mf, ms, mv, cost;   // 입력 데이터 구조체
}a[16];

map<int, vector<vector<int>>> ret_v;    
/*
결과 출력 map
같은 cost(키)값을 가진 벡터 존재가능 하므로 이중 벡터로 value 설정 
*/

int main(){
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i=0; i <n; i++){
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;  
    }

    for(int i = 1; i < (1<<n); i++){
        /* 
        n이 6일때
        i = 1 이면 000001
        i = 2 이면 000010
        ...
        i = 63 이면 111111
        n개의 식재료 고르는 조합구하기
        */
        b = c = d = e = sum = 0;
        vector<int> v;
        for(int j = 0; j < n; j++){

            /*
            해당 조합에서 선택되어있는 식재료 경우 구하기
            */
            if(i & (1 << j)){
                v.push_back(j + 1); 
                // v에 선택된 식재료 인덱스 저장
                b += a[j].mp;
                c += a[j].mf;
                d += a[j].ms;
                e += a[j].mv;
                sum += a[j].cost;
            }
        }

        if(b >= mp && c >=mf && d >= ms && e >= mv){
            if(ret >= sum){
                // 선택된 조합이 최소 cost일 경우
                ret = sum;
                ret_v[ret].push_back(v);
                // 최소가 되는 식재료 인덱스를 결과 벡터에 저장
            }
        }
    }
    if(ret == INF) cout << -1 << '\n';
    else{
        // 키값이 ret임 (총 cost)
        // 정렬하여 사전순으로 가장 빠른 것 출력
        sort(ret_v[ret].begin(), ret_v[ret].end());
        cout << ret << "\n";
        for(int a : ret_v[ret][0]){
            cout << a << " ";
        }
    }
    return 0;
} 