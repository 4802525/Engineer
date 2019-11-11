#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//方針：K回の修行でかかる時間X以下にできるかの判定を考える
//ある時間を境にできるとできないが決まるので2分探索行う
int main(void){
  //入力
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<ll> F(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  for(int i = 0; i < N; ++i) cin >> F[i];

  //貪欲に割り当てるため
  //Aは降順，Fは昇順にソートする
  sort(A.begin(),A.end(),greater<ll>());
  sort(F.begin(),F.end());

  //X以下でできるかの判定
  auto f = [&](ll X){
    ll k = K;
    for(int i = 0; i<N; ++i){
      //A[i]*F[i]がX以下であるためにA[i]をQ以下にする必要がある
      ll Q = X/F[i];
      //Qになるまで修行．既にQ以下なら必要なし
      k -= max(0ll, A[i]-Q);
    }
    //修行回数がK以下ならtrue
    return k>=0;
  };

  // lは必ずできない，rは必ずできる状態にする
  ll l = -1, r = 1e12;
  //lとrが隣り合うまで続ける
  while(r-l>1){
    ll X = (l+r)/2;
    if(f(X)) r = X;
    else l = X;
  }

  //出力
  cout << r << endl;
}
