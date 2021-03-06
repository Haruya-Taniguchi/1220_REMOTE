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
    if(!light_pow)
      Turn_On();
     server.send(200, "text/html", "");
  } );

  server.on("/OFF", []() {
    if(light_pow)
      Turn_Off();
     server.send(200, "text/html", "");
  } );

  server.on("/", []() {
    String tmp;
    File index;
    if (light_pow) {
      index = SPIFFS.open("/ON.html", "r");
    }else{
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

  if ((millis() - bgn) > 1500) {
    servo.detach();
  }
}

void Turn_On() {
  light_pow = true;
  bgn = millis();
  servo.attach(SERVO_PIN);
  servo.write(50);
  Serial.println("Turn On!");
}

void Turn_Off() {
  light_pow = false;
  bgn = millis();
  servo.attach(SERVO_PIN);
  servo.write(85);
  Serial.println("Turn Off!");
}
