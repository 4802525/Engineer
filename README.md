問題と解法例
=====
- [Ki (ABC138D)][ABC138D]([解法][solveABC138D])
  - 
  <details><summary>問題概要</summary>

    - 大きさN，頂点番号1を根とする根付き木が与えられる．
    - 各頂点にはカウンターが設置されており，初期値は0である．  
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
    - 品物iの値段はAi円．
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
    - 異なるシャリの重さは異なり，異なるネタの重さも異なる．
    - シャリとネタを組み合わせて握りを作る．2つの異なる握りの重さが等しくなるようにできるか．
  </details>
  <details><summary>解法方針</summary>

    - 愚直にやるとO($N^2M^2$)で間に合わない．
    - 一度記録した重さを
  </details>

- [Two Contests (AGC040B)][AGC040B]([解法][solveAGC040B])
  -
  <details><summary>問題概要</summary>
  </details>
  <details><summary>解法方針</summary>
  </details>

- [Gluttony(ABC144E)][ABC144E]([解法][solveABC144E])
  -
  <details><summary>問題概要</summary>
  </details>
  <details><summary>解法方針</summary>
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