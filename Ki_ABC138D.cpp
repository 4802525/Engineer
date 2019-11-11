#include<bits/stdc++.h>
using namespace std;

//counterの値を親から子に伝搬させる
void dfs(int vertex, int parent, 
    vector<vector<int> >& Tree, vector<int>& counter){

  //親のカウンターの値を足し合わせる
  counter[vertex] += counter[parent];

  //子に伝播させる
  for(const int &nxtv : Tree[vertex]){
    if(nxtv == parent)continue;
    dfs(nxtv, vertex, Tree, counter);
  }
}

//方針：親から子にカウンターの値を伝播させていくことで実現
int main(void){
  //入力
  int N,Q;
  cin >> N >> Q;
  //木
  vector<vector<int> > Tree(N+1);
  //頂点のカウンター
  vector<int> counter(N+1,0);
  //木の構築
  for(int i = 0; i < N-1; ++i){
    int a,b;
    cin >> a >> b;
    Tree[a].push_back(b);
    Tree[b].push_back(a);
  }

  //カウンターの加算
  for(int j = 0; j < Q; ++j){
    int p,x;
    cin >> p >> x;
    counter[p] += x;
  }

  //カウンターの伝搬
  dfs(1,0,Tree,counter);

  //出力
  for(int i = 1; i <= N; ++i){
    cout << counter[i] << " ";
  }
  cout << endl;
  return 0;
}
