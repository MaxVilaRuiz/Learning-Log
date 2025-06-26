// Llegeix temperatura i es connecta al WiFi

#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include "secret_credentials.h"

// Pin on es connecta al bus 1-Wire
const byte pinDadesDQ = D5; //D1;

// Instància a les classes OneWire i DallasTemperature
OneWire oneWireObjecte(pinDadesDQ);
DallasTemperature sensorDS18B20(&oneWireObjecte);

// Temporitzador
unsigned long ultimaTemp = 0;
unsigned long tempsTemp = 5000; // Cada 5 segons

// Credencials WiFi
//char ssid[] = "la_teva_ssid";
//char pass[] = "el_teu_password";

void setup() {
  // Iniciem la comunicació sèrie
  Serial.begin(115200);
  // Iniciem el bus 1-Wire
  sensorDS18B20.begin();

  // Inici temporitzador
  ultimaTemp = millis();

  /******* Configuració connexió WiFi *******/
  // Establir mode estació
  WiFi.mode(WIFI_STA);
  // Establim la connexió
  WiFi.begin(wifi_user, wifi_password);  // WiFi.begin(ssid, pass);

  // Esperem fins que la connexió s'hagi establert
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  // Mostrem la informació de la xarxa a la qual s'ha connectat
  Serial.println("Connectat a la xarxa WiFi.");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  /******* Configuració connexió WiFi *******/
}

void loop() {

  // Protecció overflow
  if (ultimaTemp > millis()) {
    ultimaTemp = millis();
  }

  // Comprovar si ha passat el temps
  if (millis() - ultimaTemp > tempsTemp) {
    // Marca de temps
    ultimaTemp = millis();

    // Enviem comandes als sensors per a la presa de temperatura
    sensorDS18B20.requestTemperatures();

    // Llegim i mostrem les dades dels sensors DS18B20 pel port sèrie
    Serial.print("Temperatura sensor: ");
    Serial.print(sensorDS18B20.getTempCByIndex(0));
    Serial.println(" ºC");
  }
}
