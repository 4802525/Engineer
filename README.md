アルゴリズム(競プロ)
===
##  問題と解法
ここに挙げる問題は全てコンテスト中に自力で解いた問題になります．  
実行時間制限2sec/メモリ制限1024MB
- [Ki (ABC138D)][ABC138D]
  - 
  <details><summary>問題概要</summary>

    - 大きさN，頂点番号1を根とする根付き木が与えられる．  
      各頂点にはカウンターが設置されており，初期値は0である．  
    - 以下のような操作をQ回行う．  
      頂点pを根とする部分木に含まれる全ての頂点のカウンターの値にxを足す．
    - 全ての操作の後の各頂点のカウンターの値を求めよ．    
    - 制約
      - 2<=N<=2e5
      - 1<=Q<=2e5
  </details>
  <details><summary>解法方針</summary>

    - 愚直(O(NQ))にやっては間に合わないので操作を2つに分ける．  
      1. 「頂点pのカウンターにxを足す．」をQ回繰り返す． 
      2. 根から葉に向かって次の操作を繰り返す．    
        見ている頂点vの親のカウンターの値をvのカウンターに足す．  

      1はO(Q),2はO(N)なので全体の時間計算量はO(N+Q)で間に合う．
  </details>

  <details><summary>コード</summary>

  ```c++
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

  ```
  </details>

- [Powerful Discount Tickets (ABC141D)][ABC141D]
  - 
  <details><summary>問題概要</summary>

    - N個の品物を購入する．  
      品物iの値段はAi円．
    - M枚の半額券(小数点以下切り捨て)があり，同じ品物に複数枚適応することが可能．
    - 全ての品物を購入するために必要な最小の金額を求めよ．
    - 制約
      - 1<=N,M<=1e5
  </details>
  <details><summary>解法方針</summary>

    - 最も高価な品物に割引券を使用していくと最小になる．
    - 最も高価な品物を探して割引券を適応するのは愚直にやるとO(N)なのでM回探索するのはO(NM)で間に合わない．
    - priorioty_queueというデータ構造を使うことでその操作の計算量をO(logN)に抑えることができる．
      全体の計算量はO((M+N)logN)で間に合う．

  - priority_queue:ヒープを用いたデータ構造
    - 最大値の取得:O(1)
    - 最大値の取り出し:O(logN)
    - 値の追加:O(logN)  

    で行うことができる．
  </details>

  <details><summary>コード</summary>

  ```c++
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
  ```
  </details>

- [Equal Weight (JSC2019FA)][JSC2019FA]
  - 
  <details><summary>問題概要</summary>

    - N個のシャリとM個のネタがあり，シャリiの重さはAi，ネタjの重さはBjである．
    - シャリ同士の重さは全て異なり，ネタ同士の重さも全て異なる．
    - シャリとネタを組み合わせて握りを作る．2つの異なる握りの重さが等しくなるようにできるか．
    - 制約
      - 2<=N,M<=2e5
      - 1<=Ai,Bj<=1e6
  </details>
  <details><summary>解法方針</summary>

    - 愚直にやるとO(N^2M^2)で間に合わない．
    - 以下のやり方でO(NM)にできる．
      全てのシャリとネタの組み合わせの握りを一つずつ見ていき，その和wを計算する．  
      今までにwとなる握りが存在すれば，二つの異なる握りの重さが等しくなるようにできるといえる．
      しかし，O(NM)でも間に合わないように見える．
    - 実は鳩ノ巣原理により，握りの重さの最大値+1個の握りを見れば，必ず同じ重さのものが1組以上できるので間に合う．
  </details>
  <details><summary>コード</summary>

  ```c++
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

  ```
  </details>

- [Two Contests (AGC040B)][AGC040B]
  -
  <details><summary>問題概要</summary>

    - N個の閉区間が与えられる．
    - N要素の区間集合を要素数が0ではない二つの集合に分割する．  
      それぞれの区間集合について，共通部分の長さを求めて，その和の最大化を目指す．(最大値を求める)
    - 制約
      - 2<=N<=1e5
  </details>
  <details><summary>解法方針</summary>

    - 全ての組み合わせを全探索するのはO(2^N)で間に合わない．
    - 半開区間の方が取り扱いやすいのでRに1を足して，半開区間にする．[L,R+1)  
      N個の区間をLの昇順にソートする．(Lが一致するときはRの昇順で比較)  
    - この時以下の二つの場合の中に最大値となる分け方が存在する．  
      1. 配列の前方i個と後方N-i個に分けた時
      2. 2つのコンテストを最大範囲のものとそれ以外に分けた時

      1は累積和を応用して，累積共通部分を前からと後ろから計算することによってO(N)で計算できる．  
      2は，最大範囲の長さと全ての共通部分の長さの和を取ると1と組み合わせて網羅できる．O(N)

    ボトルネックはソートの部分なのでO(NlogN)で間に合う．
  </details>
  <details><summary>コード</summary>

  ```c++
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

  ```
  </details>

- [Gluttony(ABC144E)][ABC144E]
  -
  <details><summary>問題概要</summary>

    - 正整数N要素の多重集合A,Fがある．
    - 2つの多重集合の要素同士を1対1対応させ，その積の最大値をコストと呼ぶ．  
      コストを計算する前に，Aの要素の値を0未満にならないように合計でK以下だけ減らすことができる．  
    - コストの最小値を求めよ．
    - 制約
      - 1<=N<=2e5
      - 1<=Ai,Fi<=1e6
  </details>
  <details><summary>解法方針</summary>

    - Fの要素が小さいものにはAの要素が大きいものを割り当てるのが最適．  
      Fを昇順，Aを降順にソートする．
    - コストをX以下にできるかという判定問題を考える．  
      i番目の要素Ai，Fiがあり，Fi*Q<=Xとなる最大のQを求める．(int型ではQ = X/Fi)  
        - Q>=AiならAi*Fi<=Xなので次の要素に移る．  
        - Q < AiならQになるまでAiを減らして次の要素に移る．  

      全ての要素を見て減らした合計がK以下ならコストをX以下にすることが可能．Kを超えるなら不可能であることがわかる．
      この判定の計算量はO(N)．

    - コストをX以下にできるかという判定問題ができたので，コストの最小値は判定問題がtrueである最小のX．  
      このようなXを求めるには二分探索を行えば良いので，時間計算量はO(Nlog(Fmax*Amax))となり，間に合う．
  </details>
  <details><summary>コード</summary>

  ```c++
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

    //貪欲に割り当てるため，Aは降順，Fは昇順にソートする
    sort(A.begin(),A.end(),greater<ll>());
    sort(F.begin(),F.end());

    //X以下でできるかの判定
    auto f = [&](ll X){
      ll k = 0;
      for(int i = 0; i<N; ++i){
        //A[i]*F[i]がX以下であるためにA[i]をQ以下にする必要がある
        ll Q = X/F[i];
        //Qになるまで修行．既にQ以下なら必要なし
        k += max(0ll, A[i]-Q);
      }
      //修行回数がK以下ならtrue
      return k<=K;
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

  ```
  </details>


[ABC138D]:https://atcoder.jp/contests/abc138/tasks/abc138_d
[ABC141D]:https://atcoder.jp/contests/abc141/tasks/abc141_d
[JSC2019FA]:https://atcoder.jp/contests/jsc2019-final/tasks/jsc2019_final_a
[AGC040B]:https://atcoder.jp/contests/agc040/tasks/agc040_b
[ABC144E]:https://atcoder.jp/contests/abc144/tasks/abc144_e

[solveABC138D]:https://github.com/4802525/synapse/blob/master/Ki_ABC138D.cpp
[solveABC141D]:https://github.com/4802525/synapse/blob/master/PowerfulDiscountTickets_ABC141D.cpp
[solveJSC2019FA]:https://github.com/4802525/synapse/blob/master/EqualWeight_JSCF2019A.cpp
[solveAGC040B]:https://github.com/4802525/synapse/blob/master/TwoContests_AGC040B.cpp
[solveABC144E]:https://github.com/4802525/synapse/blob/master/Gluttony_ABC144E.cpp
