#include <WiFi.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WiFiServer server(80);

int relayPin = 18;

String request;

void setup() {
  Serial.begin(115200);

  pinMode(relayPin, OUTPUT);

  // Initially OFF
  digitalWrite(relayPin, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();

  Serial.println("\nType 1 → Relay ON");
  Serial.println("Type 0 → Relay OFF");
}

void loop() {

  // Web server
  WiFiClient client = server.available();
  if (client) {
    request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/ON") != -1) {
      digitalWrite(relayPin, HIGH);   // ON
      Serial.println("Relay ON (Web)");
    }

    if (request.indexOf("/OFF") != -1) {
      digitalWrite(relayPin,LOW);  // OFF
      Serial.println("Relay OFF (Web)");
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html\n");

    client.println("<html><body style='text-align:center;'>");
    client.println("<h2>Relay Control</h2>");
    client.println("<a href=\"/ON\"><button>ON</button></a>");
    client.println("<a href=\"/OFF\"><button>OFF</button></a>");
    client.println("</body></html>");
  }

  // 🔹 SERIAL CONTROL (FIXED)
  if (Serial.available()) {
    char input = Serial.read();

    if (input == '1') {
      digitalWrite(relayPin, HIGH);   // ON
      Serial.println("Relay ON (Serial)");
    }

    if (input == '0') {
      digitalWrite(relayPin, LOW);  // OFF
      Serial.println("Relay OFF (Serial)");
    }
  }
}
