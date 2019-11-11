#include<bits/stdc++.h>
using namespace std;

//方針：貪欲法(値段の高いものから割引券を適応していく
int main(void){
  //入力
  int N,M;
  cin >> N >> M;

  //高い金額から順に取り出すためのデータ構造
  priority_queue<long long> prices;

  //pricesに値段を記録していく．
  for(int i = 0; i < N; ++i){
    long long A;
    cin >> A;
    prices.push(A);
  }

  //割引券の使用(高いものから順に適応していく)
  while(M--){
    long long price = prices.top(); prices.pop();
    //割引券の利用
    price /= 2;

    //割引した後も割引券は使えるので割引後の値段を挿入
    prices.push(price);
  }

  //値段の合計
  long long sum = 0ll;
  while(!prices.empty()){
    sum += prices.top(); prices.pop();
  }

  //出力
  cout << sum << endl;
}
