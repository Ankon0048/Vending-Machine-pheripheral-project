#include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);
// Define the GSM module pins
#define GSM_TX_PIN 10
#define GSM_RX_PIN 9

// Create a SoftwareSerial object for the GSM module
SoftwareSerial gsmSerial(GSM_TX_PIN, GSM_RX_PIN);

// Array to store the operator number
char operatorNumber[16];

// Array to store the message text
char messageText[16];

String chop = "bKash";
String cham = "12";

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Set up GSM module baud rate
  gsmSerial.begin(9600);
  
  // Initialize GSM module
  initGSM();
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Welcome, to buy");
  lcd.setCursor(4, 1);
  lcd.print("Send 11tk to");
  lcd.setCursor(4,3);
  lcd.print("01793425032");
}

void display(){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Welcome, to buy");
  lcd.setCursor(4, 1);
  lcd.print("Send 11tk to");
  lcd.setCursor(4,3);
  lcd.print("01793425032");  
}

void loop() {
  // Check if there is an incoming SMS
  if (gsmSerial.available()) {
    // Read the incoming message
    readSMS();
  }
}

void initGSM() {
  delay(2000);
  
  // Set GSM module to text mode
  gsmSerial.println("AT+CMGF=1");
  delay(1000);
  
  // Enable message notifications
  gsmSerial.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
  
  Serial.println("GSM initialized");
}

void readSMS() {
  // Read the GSM module response
  String response = gsmSerial.readString();
  
  // Check if the response contains "+CMT:"
  if (response.indexOf("+CMT:") != -1) {
    // Find the start and end positions of the operator number
    int start = response.indexOf("+CMT:") + 7;
    int end = start+5;
    
    // Extract the operator number
    response.substring(start, end).toCharArray(operatorNumber, sizeof(operatorNumber));
    
    // Find the start and end positions of the message text
    start = response.indexOf("You") + 21;
    end = response.indexOf("from")-4;
    
    // Extract the message text
    response.substring(start, end).toCharArray(messageText, sizeof(messageText));
   if(String(operatorNumber) == chop){
     if(String(messageText) == cham){
       lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Thank you");
        lcd.setCursor(6, 1);
        lcd.print("for");
        lcd.setCursor(0, 2);
        lcd.print("your purchase");                
        //Serial.println("Thank god");
        delay(4000);
        lcd.clear();
        display();
     }
     else{
       lcd.clear();
        lcd.setCursor(3,2);
        lcd.print("Too Poor XD");
        delay(4000);
        lcd.clear();
        display();
     }
   }
   else{
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Trying to scam :(");
   }
    Serial.println("Operator Number: " + String(operatorNumber));
    Serial.println("Message Text: " + String(messageText));
  }
}
