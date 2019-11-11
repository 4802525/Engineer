問題と解法例
=====
- [Ki (ABC138D)][ABC138D]([解法][solveABC138D])
  - 
  <details><summary>問題概要</summary>

    - 大きさN，頂点番号1を根とする根付き木が与えられる．  
      各頂点にはカウンターが設置されており，初期値は0である．  
    - 以下のような操作をQ回行う．  
      頂点pを根とする部分木に含まれる全ての頂点のカウンターの値にxを足す．
    - 全ての操作の後の各頂点のカウンターの値を求めよ．
  </details>
  <details><summary>解法方針</summary>

    - 愚直(O(NQ))にやっては間に合わないので操作を2つに分ける．  
      1. 「頂点pのカウンターにxを足す．」をQ回繰り返す． 
      2. 根から葉に向かって次の操作を繰り返す．    
        見ている頂点vの親のカウンターの値をvのカウンターに足す．  

      1はO(Q),2はO(N)なので全体の時間計算量はO(N+Q)で間に合う．
  </details>

- [Powerful Discount Tickets (ABC141D)][ABC141D]([解法][solveABC141D])
  - 
  <details><summary>問題概要</summary>

    - N個の品物を購入する．  
      品物iの値段はAi円．
    - M枚の半額券(小数点以下切り捨て)があり，同じ品物に複数枚適応することが可能．
    - 全ての品物を購入するために必要な最小の金額を求めよ．
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

- [Equal Weight (JSC2019FA)][JSC2019FA]([解法][solveJSC2019FA])
  - 
  <details><summary>問題概要</summary>

    - N個のシャリとM個のネタがあり，シャリiの重さはAi，ネタjの重さはBjである．
    - シャリ同士の重さは全て異なり，ネタ同士の重さも全て異なる．
    - シャリとネタを組み合わせて握りを作る．2つの異なる握りの重さが等しくなるようにできるか．
  </details>
  <details><summary>解法方針</summary>

    - 愚直にやるとO(N^2M^2)で間に合わない．
    - 以下のやり方でO(NM)にできる．
      全てのシャリとネタの組み合わせの握りを一つずつ見ていき，その和wを計算する．  
      今までにwとなる握りが存在すれば，二つの異なる握りの重さが等しくなるようにできるといえる．
      しかし，O(NM)でも間に合わないように見える．
    - 実は鳩ノ巣原理により，握りの重さの最大値+1個の握りを見れば，必ず同じ重さのものが1組以上できるので間に合う．
  </details>

- [Two Contests (AGC040B)][AGC040B]([解法][solveAGC040B])
  -
  <details><summary>問題概要</summary>

    - N個の閉区間が与えられる．
    - N要素の区間集合を要素数が0ではない二つの集合に分割する．  
      それぞれの区間集合について，共通部分の長さを求めて，その和の最大化を目指す．(最大値を求める)
  </details>
  <details><summary>解法方針</summary>

    - 半開区間の方が取り扱いやすいのでRに1を足して，半開区間にする．[L,R+1)  
      N個の区間をLの昇順にソートする．(Lが一致するときはRの昇順で比較)  
    - この時以下の二つの場合の中に最大値となる分け方が存在する．  
      1. 配列の前方i個と後方N-i個に分けた時
      2. 2つのコンテストを最大範囲のものとそれ以外に分けた時

      1は累積和を応用して，累積共通部分を前からと後ろから計算することによってO(N)で計算できる．  
      2は，最大範囲の長さと全ての共通部分の長さの和を取ると1と組み合わせて網羅できる．O(N)

    ボトルネックはソートの部分なのでO(NlogN)で間に合う．
  </details>

- [Gluttony(ABC144E)][ABC144E]([解法][solveABC144E])
  -
  <details><summary>問題概要</summary>

    - 正整数N要素の多重集合A,Fがある．
    - 2つの多重集合の要素同士を1対1対応させ，その積の最大値をコストと呼ぶ．  
      コストを計算する前に，Aの要素の値を0未満にならないように合計でK以下だけ減らすことができる．  
    - コストの最小値を求めよ．
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