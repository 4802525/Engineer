#include<bits/stdc++.h>
using namespace std;

//2重ループの計算量はO(NM):間に合わない
//しかし鳩ノ巣原理により2重ループは高々max(Ai) + max(Bi)しか回らない(重複したら終了)
int main(){
  //入力
  int N,M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> B(M);
  for(int i = 0; i < N; ++i){
    cin >> A[i];
  }
  for(int j = 0; j < M; ++j){
    cin >> B[j];
  }

  const int MaxWeight = 2e6;
  //indexが重さ，pairがその重さを作るためのiとj,存在しなければ-1
  vector<pair<int,int> > ids(MaxWeight+1,make_pair(-1,-1));
  //寿司とネタを全探索していく
  for(int i = 0; i < N; ++i){
    for( int j = 0; j < M; ++j){
      int Weight = A[i]+B[j];
      //既に同じ重さの別の組が存在するとき
      if(ids[Weight].first != -1){
        cout << ids[Weight].first << " "
          << ids[Weight].second << " " 
          << i << " "
          << j << endl;
        return 0;
      }
      //存在しないとき
      ids[Weight] = make_pair(i,j);
    }
  }

  //重さの等しい二つの握りが作れない
  cout << -1 << endl;
  return 0;
}
