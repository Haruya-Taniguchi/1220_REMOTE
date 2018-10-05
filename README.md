1220_REMOTO
====
このコードはベッドから出て照明を消すのが面倒だったので、スマートフォンで操作できるようにするために作成した。ESP8266にブラウザからアクセスし、サーボモーターでフルカラースイッチ のON,OFFを切り替えることで部屋の照明の操作ができる。

## Depandency
- 使用言語：
    - Arduino
    - HTML
    - CSS
    - JavaScript
- 実行環境
    - ESP8266搭載ボード
    - Google Chrome、Safari
- 開発環境：
    - Arduino IDE 1.8.5
    - Atom

## Setup
- 使うもの
    - ESP8266
    - タクトスイッチ
    - サーボモーター
    - 電源
    - それらを壁に固定するもの(特に決まっていない)

- セットアップ方法
1. 変数ssidに使用するWiFiのSSIDを、変数passにパスワードを代入し、ESP8266にプログラムを書き込む。
    <div align="center"><img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure1.jpg?raw=true" alt="figure1"  height="500px"></div>
    
2. 書き込みが終わったらPCと接続したままプログラムを実行させ、シリアルモニタからWiFiとの接続が成功した後に表示されるIPアドレスを確認する。
    <div align="center"><img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure2.jpg?raw=true" alt="figure2" height="300px"></div>
    
3. 下の図を参考に部品をESP8266に接続する。（サーボの信号線はIO2ピンに接続、 タクトスイッチはIO14ピンに接続）
   <div align="center"> <img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure3.jpg?raw=true" alt="figure3" height="500px"></div>
    
4. お好みの方法でフルカラースイッチ にサーボモーターなどを取り付ける。下の写真は取り付けの一例。
    <div align="center"><img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure4.jpg?raw=true" alt="figure4" height="500px"></div>
    
5. 電源をESP8266に接続する。電源から供給できる電流が少ないとサーボモーターのトルクが弱くなりフルカラースイッチを押せなくなるので注意。
    
## Usage
1. ブラウザから先ほど確認したIPアドレスにアクセスする。
2. ボタンをタップ、またはクリックすると照明のON,OFFの切り替えができる。接続したタクトスイッチを押すことでも同様のことができる。下の図はスマートフォンの場合にブラウザに表示されるUI。
<div align="center"><img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure5.jpg?raw=true" alt="figure5" height="500px"></div>

ボタンには現在の照明の状態に合わせて"ON","OFF"の文字が表示される。ボタンの表示と実際の照明の状態が合致していないときなどは、右下にあるUPDATEボタンを押すとESP8266で記憶している照明の状態にあわせて表示を修正できる。

## Licence
[MIT](https://github.com/tcnksm/tool/blob/master/LICENCE)

## Author

[taniharu](https://github.com/Haruya-Taniguchi)
