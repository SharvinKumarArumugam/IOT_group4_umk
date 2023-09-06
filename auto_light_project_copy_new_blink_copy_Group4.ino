#include <UnoWiFiDevEd.h>

#include <BlynkSimpleEthernet.h>  // Include the Blynk library for Arduino

#define BLYNK_TEMPLATE_ID "TMPL6AqCmrMpc"
#define BLYNK_TEMPLATE_NAME "Smart living room"
#define BLYNK_AUTH_TOKEN "0v3zkr3H8mJ3pZ1P09i1ZUEHtURmQnqZ"
char ssid[] = "250102";
char pass[] = "1234567890";
char auth[] = "0v3zkr3H8mJ3pZ1P09i1ZUEHtURmQnqZ";  // Replace with your Blynk authentication token

int Bulb = 8;
int PIR = 3;
int val = 0;

void setup() {
  pinMode(Bulb, OUTPUT);
  pinMode(PIR, INPUT);
  Blynk.begin( BLYNK_AUTH_TOKEN, ssid, pass );
  
  //Blynk.begin(auth);  // Initialize Blynk with your authentication token
}

void loop() {
  Blynk.run();  // Run Blynk
  
  val = digitalRead(PIR);
  if (val == HIGH) {
    digitalWrite(Bulb, HIGH);
    Blynk.virtualWrite(V1, 255); 
     // Turn on a Blynk virtual LED widget (V1)
  } else {
    digitalWrite(Bulb, LOW);
    Blynk.virtualWrite(V1, 0);  // Turn off the Blynk virtual LED widget (V1)
    }
}