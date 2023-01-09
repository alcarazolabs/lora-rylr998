//========================  RECEPTOR ===============================
//String lora_band = "865000000"; //Banda de frecuencia en (Hz) de 865hz para Europa
String lora_band = "923000000"; //Banda de frecuencia en (Hz) de 965mhz para America. En peru se usa la 923mhz por que bitel tiene la 915mhz por error del mtc: https://www.facebook.com/smelpro/posts/2547552988855874/?comment_id=2547592392185267
String lora_networkid = "18";   //Identificación de la red Lora
String lora_address = "2";      //Dirección de Lora
//String lora_RX_address = "1";   //Dirección del modulo receptor

int led = 19;

String textoEntrada;

void setup()
{

  pinMode(led,OUTPUT);
  Serial2.begin(115200,SERIAL_8N1, 16,17); //16 es el pin RX y 17 el pin TX del esp32 devkitc v1 y v4
  
  //Serial2.begin(115200,SERIAL_8N1, 40,41); //40 es el pin RX y 41 el pin TX del esp32 devkitc v4. 
  Serial.begin(115200);
  delay(1500);

  
  // * Nota: Se configuro la banda, networkid y address a travez de comandos AT usando el usb ttl conversor ftdi
  Serial2.println("AT+BAND=" + lora_band);
  delay(500);
  Serial2.println("AT+NETWORKID=" + lora_networkid);
  delay(500);
  Serial2.println("AT+ADDRESS=" + lora_address);
  
     //Test led:
    digitalWrite(led, HIGH);
    delay(5000);
    Serial.println("done");
    digitalWrite(led, LOW);
}

void loop(){ 
  if(Serial2.available()) {
     
    textoEntrada = Serial2.readString();
    Serial.println(textoEntrada);
  
    if(textoEntrada.indexOf("ON") > 0) {
      digitalWrite(led, HIGH);
      delay(3000);
      digitalWrite(led, LOW);
    }

    
  }
}
