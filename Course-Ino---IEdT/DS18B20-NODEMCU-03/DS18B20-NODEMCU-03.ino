/* Llegeix temperatura, la mostra pel port sèrie, 
es connecta al WiFi i envia les dades a la plataforma Thingspeak */

#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include "secret_credentials.h"
#include <ThingSpeak.h>

// Pin on es connecta al bus 1-Wire
const byte pinDadesDQ = D5; //D1;

// Instància a les classes OneWire i DallasTemperature
OneWire oneWireObjecte(pinDadesDQ);
DallasTemperature sensorDS18B20(&oneWireObjecte);

// Temporitzador
unsigned long ultimaTemp = 0;
unsigned long tempsTemp = 16000; // Cada 16 segons

// Credencials WiFi
//char ssid[] = "la_teva_ssid";
//char pass[] = "el_teu_password";

// Client WiFi per enviar informació
WiFiClient client;

// Configuració ThingSpeak
//unsigned long numeroCanal = numero_de_canal;
//const char * apiKey = "WriteAPIKey";

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
  
  // *** Configuració Thingspeak
  ThingSpeak.begin(client);
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

    float temperatura = sensorDS18B20.getTempCByIndex(0);

    // Llegim i mostrem les dades dels sensors DS18B20 pel port sèrie
    Serial.print("Temperatura sensor: ");
    Serial.print(temperatura);
    Serial.println(" ºC");

    // Enviar temperatura a ThingSpeak
    int resultat = ThingSpeak.writeField(numeroCanal, 1, temperatura, apiKey);
    if (resultat == 200) {
      Serial.println("Canal actualitzat.");
    } else {
      Serial.println("Problemes a l'actualizar el canal. Codi d'error HTTP " + String(resultat));
    }

  }
}
