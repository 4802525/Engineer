問題と解法例
=====
- [Ki (ABC138D)][ABC138D]([解法][solveABC138D])
  - 
  <details><summary>問題概要</summary>

    - 大きさN，頂点番号1を根とする根付き木が与えられる．
    - 各頂点にはカウンターが設置されており，初期値は0である．  
    - 以下のような操作をQ回行う.  
      頂点pを根とする部分木に含まれる全ての頂点のカウンターの値にxを足す
    - 全ての操作の後の各頂点のカウンターの値を求めよ．
  </details>
  <details><summary>解法方針</summary>

    - 操作を2つに分ける  
      1. 「頂点pのカウンターにxを足す．」をQ回繰り返す．
      2. 根から葉に向かって次の操作を繰り返す．  
        見ている頂点vの親のカウンターの値をvのカウンターに足す．
  </details>

- [Powerful Discount Tickets (ABC141D)][ABC141D]([解法][solveABC141D])
  - 
  <details><summary>問題概要</summary>
  </details>
  <details><summary>解法方針</summary>
  </details>

- [Equal Weight (JSC2019FA)][JSC2019FA]([解法][solveJSC2019FA])
  - 
  <details><summary>問題概要</summary>
  </details>
  <details><summary>解法方針</summary>
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