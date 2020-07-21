# CompetitiveProgramming
templete:  
競技プログラミングのときに使う自作関数（と見せかけてほとんどパクリ）のテンプレとか，BFSとか素数判定などの典型を集めたやつ（少ないので多分もっと増える）

Atcoder:  
->ABC過去問：自分がといた奴　基本的にACだったやつしかあげないので間違ってない（と信じたい）  
->その他ファイル：ABC参加時にいちいちテンプレからコピペしないで良いようにあらかじめ用意しておくやつ

ErrorSolution:  
自分が遭遇したErrorとその対処方法をまとめる（少ない）

その他ファイル郡：  
エラーリストとかシェルでデバッグする時のテキストファイルとか適当（あまり意味はない）

＜開発環境＞  
atom　1.48.0
環境構築については，  
https://tadtadya.com/transform-atom-into-ide/
の必要なパッケージをひたすらインストールする  
C++のデバッグにはgpp-compilerがいるのだが，g++のPathをC++ Compilerのところに渡してやる必要があるので注意  
`$brew install gcc`の後，`$vi .bashrc`で.bashrcの編集  
.bashrcの優先順位高めなところ（下に書けば書くほど優先順位が高い）に  
`export PATH=/usr/local/bin:$PATH`  
を記述しないと新しいg++が使えないっぽいので記述する  
`$source .bashrc`をして，
```
$ which g++
/usr/local/bin/g++
```
となればOK（このPathを C++ Compilerに渡す）    
#include<stdc++.h>を使う場合は以下も参照  
http://turanegaku.hateblo.jp/entry/2015/12/01/003850    

その他あった方が良いパッケージの使い方や設定などは  
https://qiita.com/prickle/items/2a8f87fba7f6e1d8f051  
https://teratail.com/questions/160946  
あたりを見ると良いかも  
＜使用言語＞
特に記載のない限りC++
