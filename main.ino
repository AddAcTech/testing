#include <WiFi.h>
#include <Espalexa.h>

// Configura tu red WiFi
const char *ssid = "IZZI-8D62";
const char *password = "VWAJYQZYQMMJ";
const int bombaPin = 25;  // Pin donde está conectada la bomba

// Crea una instancia de Espalexa
Espalexa espalexa;

// Función para controlar la bomba
void controlBomba(uint8_t state)
{
    if (state > 0) // Si Alexa recibe "encender"
    {
        Serial.println("Encendiendo bomba por 5 segundos...");
        digitalWrite(bombaPin, HIGH); // Enciende la bomba
        delay(5000); // Espera 5 segundos
        digitalWrite(bombaPin, LOW);  // Apaga la bomba
        Serial.println("Bomba apagada automáticamente.");
    }
}

void setup()
{
    Serial.begin(115200); // Inicializa la comunicación serial

    // Configura el pin de la bomba como salida
    pinMode(bombaPin, OUTPUT);
    digitalWrite(bombaPin, LOW);

    // Conéctate a la red WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConectado a WiFi");

    // Agrega el dispositivo a Espalexa
    espalexa.addDevice("Bomba de Agua", controlBomba);

    // Inicia Espalexa
    espalexa.begin();
}

void loop()
{
    // Mantén Espalexa en funcionamiento
    espalexa.loop();
}

//Comentario para probar webhook numero: 26