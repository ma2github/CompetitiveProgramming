# <もしかして：#include <bits/stdc++.h>を使っている場合>
1. Terminalで以下を叩く  
```
$ find /usr/ | grep cstdalign
```
1. 出てきたPathをautocomplete-clangのInclude Pathに渡す  

（参考）  
http://turanegaku.hateblo.jp/entry/2015/12/01/003850


# <Unable to start the Clangd language server.(2020/7/21版)>
1. llvmがインストールされていない場合，  
```
$brew install llvm  
```
でインストール→これで勝手にClangdも入る
1. vi .bashrcで以下を記述する  
```
function llvm (){  
    export PATH="/usr/local/opt/llvm/bin:$PATH"  
    export LDFLAGS="-L/usr/local/opt/llvm/lib"  
    export CPPFLAGS="-I/usr/local/opt/llvm/include"  
    unset -f llvm  
}  
```
1. source .bashrc後,  
```
$llvm  
$clang -v  
clang version 10.0.0  
Target: x86_64-apple-darwin19.5.0  
Thread model: posix  
InstalledDir: /usr/local/opt/llvm/bin  
$ clangd --version  
clangd version 10.0.0  
```
となることを確認する（とりあえずversionが合ってればOK）
1. terminalで  
```
$ atom --safe  
```
と叩いてatomをSafeMode（パッケージを一切使わないモードらしい）で起動する（もしかするとこれだけで良いかも？）

（参考）  
https://github.com/atom/atom/issues/17278  
https://students-tech.blog/post/install-clang.html#最新版のインストール方法  
https://clangd.llvm.org/installation.html

# <clang serverがなんちゃら（メモるの忘れた）(2020/7/22版)>  
どうやらclangにはstdc++.hがないらしい・・・  
だからclang系統のパッケージを全部disableにする（autocomplete-clangとかide-clangdとかide-cppとか）  
代わりにgcc系統のパッケージを用いる(linter,linter-gcc，あとは上記2つを入れていろいろ言われたのを使う)  
linter-gccのGCC Excutable Pathにg++のPathを渡す（/usr/local/bin/g++　`$which g++`でこれが出ない場合
https://qiita.com/ygumaanl/items/ca902e1746a0ffdc4327　あたりを参考にPathを通す（2020/7/22現在ではg++-10が入るので，シンボリックパスを通す際にg++-8→g++-10にする））
