#include <Servo.h>
#define SERVO_PIN 2
#define BUTTON_PIN 14
Servo servo;

int bgn;
bool pbutton, button;

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

  pinMode(BUTTON_PIN, OUTPUT);
  servo.detach();

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
    Turn_On();
  } );

  server.on("/OFF", []() {
    Turn_Off();
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

  pbutton = button;
  button = digitalRead(BUTTON_PIN);

  if (!pbutton && button && !light_pow) {
    Turn_On();
  }else
  if(!pbutton && button && light_pow){
    Turn_Off();
  }

  if ((millis() - bgn) > 2000) {
    servo.detach();
  }

  if (light_pow) {
    servo.write(50);
  } else {
    servo.write(90);
  }
}

void Turn_On() {
  light_pow = true;
  bgn = millis();

  String tmp;

  File index = SPIFFS.open("/ON.html", "r");
  if (!index)
    Serial.println("file open failed");
  else {
    tmp = index.readString();
    index.close();
  }

  server.send(200, "text/html", tmp);
  servo.attach(SERVO_PIN);
  //Serial.println("Turn ON!");
}

void Turn_Off() {
  light_pow = false;
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
  servo.attach(SERVO_PIN);
  //Serial.println("Turn OFF!");
}

