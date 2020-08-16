# テストケース実行
oj d URL:サンプルのダウンロード    
oj g/i ./generate.py:テストケース生成（generate.pyを適宜変更）   
chmod 755 ./generate.py:実行の権限付与（上記で実行できない場合）    
oj g/o -c ./tle:テストケースに対する答え生成（予め正解となるプログラムtle.cppを作成する）    
oj t:テストケース実行(-e 1e-6を末尾につけると1e-6までの誤差を許容)  
複数の解が存在する場合は，プログラム中にassert(条件文);を書くことでその答えがあっているか確認できる（oj tは使わないが吉）    
# 提出
oj s URL filename.cpp:ソースコード提出
acc sでも提出可（AtCoderの場合）    
