#include<bits/stdc++.h>
using namespace std;

//正解者の範囲
struct Range{
  int L,R;

  //昇順ソートのための比較関数
  bool operator<(const Range &another) const{
    if(L == another.L) return R < another.R;
    return L < another.L;
  }

};

//範囲を昇順に並べ境界をずらしていく(境界の左が1回目のコンテスト問題，右が2回目のコンテスト問題)
//コーナーケースとして最大の範囲一つとそれ以外
int main(void){
  //入力
  int N;
  cin >> N;
  vector<Range> ranges(N);
  for(int i = 0; i < N; ++i){
    int L,R;
    cin >> L >> R;
    ++R;
    ranges[i] = {L,R};
  }
  sort(ranges.begin(),ranges.end());

  //前方累積共通部分
  vector<Range> fwd(N+1);
  fwd[0] = {1, (int)1e9+1};
  for(int i = 0; i < N; ++i){
    fwd[i+1] = {
      max( ranges[i].L, fwd[i].L),
      max( ranges[i].L, min( ranges[i].R, fwd[i].R ) )
    };
  }

  //後方累積共通部分
  vector<Range> bak(N+1);
  bak[N] = {1, (int)1e9+1};
  for(int i = N-1; i >= 0; --i){
    bak[i] = {
      max( ranges[i].L, bak[i+1].L),
      max( ranges[i].L, min( ranges[i].R, bak[i+1].R ) )
    };
  }

  //コーナーケースを初期値とする．
  int joy = 0;
  for(int i = 0; i < N; ++i){
    //最大の範囲を取る
    joy = max(joy,ranges[i].R-ranges[i].L);
  }
  joy += fwd[N].R-fwd[N].L;

  //境界を見ていく．
  for(int i = 1; i < N; ++i){
    joy = max(joy, 
        fwd[i].R-fwd[i].L + bak[i].R-bak[i].L);
  }

  //出力
  cout << joy << endl;
  return 0;
}
