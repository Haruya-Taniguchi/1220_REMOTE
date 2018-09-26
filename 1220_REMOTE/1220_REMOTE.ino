#include <Servo.h>
Servo servo;
bool servo_pow = false;
int bgn;
#define SERVO_POW 16

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>

const char *ssid = "";//SSID
const char *pass = "";//パスワード

ESP8266WebServer server(80);

bool light_pow = false;
void setup() {
  SPIFFS.begin(); //SPIFFSを開始
  Serial.begin(115200);
  WiFi.begin( ssid, pass);

  servo.attach(2);
  pinMode(SERVO_POW, OUTPUT);

  while ( WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP() );

  if ( MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.begin();

  server.on("/ON", []() {
    light_pow = true;
    servo_pow = true;
    bgn = millis();

    String tmp;
    //htmlファイルの読み込み
    File index = SPIFFS.open("/ON.html", "r");
    if (!index)
      Serial.println("file open failed");
    else {
      tmp = index.readString();//htmlファイルをstringで読み込み
      index.close();
    }

    server.send(200, "text/html", tmp);
  } );

  server.on("/OFF", []() {
    light_pow = false;
    servo_pow = true;
    bgn = millis();

    String tmp;

    File index = SPIFFS.open("/OFF.html", "r");
    if (!index)
      Serial.println("file open failed");
    else {
      tmp = index.readString();
      index.close();
    }

    server.send(200, "text/html", tmp);
  } );

  server.on("/", []() {
    String tmp;
    File index;
    if (light_pow) {
      index = SPIFFS.open("/ON.html", "r");
    } else {
      index = SPIFFS.open("/OFF.html", "r");
    }
    if (!index)
      Serial.println("file open failed");
    else {
      tmp = index.readString();//htmlファイルをstringで読み込み
      index.close();
    }

    server.send(200, "text/html", tmp);
  } );
}


void loop() {
  server.handleClient();

  if (servo_pow) {
    digitalWrite(SERVO_POW, HIGH);
  } else {
    digitalWrite(SERVO_POW, LOW);
  }
  if ((millis() - bgn) > 2000 && servo_pow) {
    servo_pow = false;
  }
  if (light_pow) {
    servo.write(50);
  } else {
    servo.write(90);
  }
}
