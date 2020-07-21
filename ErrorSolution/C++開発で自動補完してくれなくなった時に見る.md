<もしかして：#include <bits/stdc++.h>を使っている場合>
1.Terminalで以下を叩く
$ find /usr/ | grep cstdalign

2.出てきたPathをautocomplete-clangのInclude Pathに渡す

（参考）
http://turanegaku.hateblo.jp/entry/2015/12/01/003850


<Unable to start the Clangd language server.(2020/7/21版)>
1.llvmがインストールされていない場合，
$brew install llvm
でインストール→これで勝手にClangdも入る

2.vi .bashrcで以下を記述する
function llvm (){
    export PATH="/usr/local/opt/llvm/bin:$PATH"
    export LDFLAGS="-L/usr/local/opt/llvm/lib"
    export CPPFLAGS="-I/usr/local/opt/llvm/include"
    unset -f llvm
}

3.source .bashrc後,
$llvm
$clang -v
clang version 10.0.0
Target: x86_64-apple-darwin19.5.0
Thread model: posix
InstalledDir: /usr/local/opt/llvm/bin
$ clangd --version
clangd version 10.0.0
となることを確認する（とりあえずversionが合ってればOK）

4.terminalで
$ atom --safe
と叩いてatomをSafeMode（パッケージを一切使わないモードらしい）で起動する（もしかするとこれだけで良いかも？）

（参考）
https://github.com/atom/atom/issues/17278
https://students-tech.blog/post/install-clang.html#最新版のインストール方法
https://clangd.llvm.org/installation.html
