1220_REMOTO
====
ベッドから出て照明を消しに行くのが面倒だったので、スマートフォンから部屋の照明を操作できるようにするために作成したスマートスイッチです。ESP8266にブラウザからアクセスし、サーボモーターでフルカラースイッチのON,OFFを切り替えることで部屋の照明の操作ができます。

## Dependency
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
1. 下線部を使用するWiFiのSSIDとパスワードに書き換えてからESP8266にプログラムを書きこむ。また、SPIFFS機能を使ってフラッシュメモリにHTMLファイルを格納する。
    <div align="center"><img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure1.jpg?raw=true" alt="figure1"  width="80%"></div>

2. 書き込みが終わったらPCに接続したままプログラムを実行させ、シリアルモニタからWiFiとの接続が成功した後に表示されるIPアドレスを確認する。
    <div align="center"><img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure2.jpg?raw=true" alt="figure2" width="70%"></div>

3. 下の図を参考に部品をESP8266に接続する。サーボの信号線はIO2ピンに接続、 タクトスイッチはIO14ピンに接続する。(※今回自分が使用したのは図にある"Adafruit HUZZAH ESP8266 breakout"ではない。)
   <div align="center"> <img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure3.jpg?raw=true" alt="figure3" width="60%"></div>

4. お好みの方法でフルカラースイッチ にサーボモーターなどを取り付ける。下の写真は取り付け方法の一例。
    <div align="center"><img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure4.jpg?raw=true" alt="figure4" width="60%"></div>

5. 電源をESP8266に接続する。電源から供給できる電流が少ないとサーボモーターのトルクが弱くなりフルカラースイッチを押せなくなるので注意。

## Usage
1. ブラウザからSetupの2.で確認したIPアドレスにアクセスする。
2. ボタンをタップ、またはクリックすると照明のON,OFFの切り替えができる。接続したタクトスイッチを押すことでも同様のことができる。下の図はスマートフォンの場合にブラウザに表示されるUI。
<div align="center"><img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure5.jpg?raw=true" alt="figure5" width="30%"></div>

- ボタンには現在の照明の状態に合わせて"ON","OFF"の文字が表示される。ボタンの表示と実際の照明の状態が合致していないときなどは、右下にあるUPDATEボタンを押すとESP8266で記憶している照明の状態にあわせて表示を修正できる。
- iOSの場合、safariで1220_REMOTEをホーム画面に追加してホーム画面から起動すると、フルスクリーンモードになりアプリのように扱うことができる。
## 動画
https://twitter.com/taniguchi36993/status/1048219162730946562?s=20
## Licence
[MIT](https://github.com/tcnksm/tool/blob/master/LICENCE)

## Author

[taniharu](https://github.com/Haruya-Taniguchi)
