#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <SoftwareSerial.h>

const char *ssid = "Nom du réseau";
const char *password = "Mot de passe";

AsyncWebServer server(80);

// Configuration du module GPS
SoftwareSerial ss(4, 3);

void setup()
{
  //----------------------------------------------------Serial
  Serial.begin(115200);
  Serial.println("\n");

 

  //----------------------------------------------------SPIFFS
  if(!SPIFFS.begin())
  {
    Serial.println("Erreur SPIFFS...");
    return;
  }

  //----------------------------------------------------WIFI
  WiFi.begin(ssid, password);
	Serial.print("Tentative de connexion...");
	
	while(WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(100);
	}
	
	Serial.println("\n");
	Serial.println("Connexion établie!");
	Serial.print("Adresse IP: ");
	Serial.println(WiFi.localIP());

  //----------------------------------------------------SERVER
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/w3.css", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/w3.css", "text/css");
  });

  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/script.js", "text/javascript");
  });

  server.on("/lireGPS", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    // Lecture des données du module GPS
    String gpsData;
    while (ss.available() > 0) {
      gpsData += char(ss.read());
    }
    request->send(200, "text/plain", gpsData);
  });

  server.begin();
  Serial.println("Serveur actif!");

  //----------------------------------------------------GPS
  ss.begin(9600);
}

void loop()
{
  // Ajoutez ici d'autres fonctionnalités ou traitements si nécessaire
}
