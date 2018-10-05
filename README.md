1220_REMOTO
====
このコードは自分の学生寮の部屋の照明をスマートフォン(PC)で操作するために作ったコードです。ESP8266にブラウザからアクセスし、接続されたサーボモーターを使ってフルカラースイッチ のON,OFFを切り替えることができます。

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
    1. ArduinoIDEを使って変数ssidに使用するWiFiのSSIDを、変数passにパスワードを代入し、ESP8266にプログラムを書き込む。
    <img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure1.jpg?raw=true" alt="figure1" >
    2. 書き込みが終わったらPCと接続したままプログラムを実行させ、シリアルモニタからWiFiとの接続が成功した後表示されるIPアドレスを確認する。
    <img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure2.jpg?raw=true" alt="figure2">
    3. 下の図を参考に部品をESP8266に接続する。（サーボの信号線はIO2ピンに接続、 タクトスイッチはIO14ピンに接続）
    <img src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure3.jpg?raw=true" alt="figure3">
    4. お好みの方法でフルカラースイッチ にサーボモーターなどを取り付ける。下の写真は取り付けの一例です。壁には両面テープで貼り付けています。
    <img style="transform: rotate(90deg);" src="https://github.com/Haruya-Taniguchi/1220_REMOTE/blob/images/images/figure4.jpg?raw=true" alt="figure4">
    5. 電源をESP8266に接続する。電源から供給できる電流が少ないとサーボモーターのトルクが弱くなりタクトスイッチを押せなくなるので注意。
    
## Usage
1. ブラウザから先ほど確認したIPアドレスにアクセスする。
2. 表示されたボタンをタップ、またはクリックするとフルカラースイッチ のON,OFFが切り替わる。タクトスイッチを接続している場合そちらを押してON,OFFの切り替えを行うこともできる。

## Licence
[MIT](https://github.com/tcnksm/tool/blob/master/LICENCE)

## Author

[taniharu](https://github.com/Haruya-Taniguchi)
