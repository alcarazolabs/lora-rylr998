//String lora_band = "865000000"; //Banda de frecuencia en (Hz) de 865hz para Europa
String lora_band = "923000000"; //Banda de frecuencia en (Hz) de 915mhz para America. Pero se usa la 923mhz en Peru por que la empresa bitel tiene asignada la 915mhz por error de mtc.
String lora_networkid = "18";   //Identificación de la red Lora
String lora_address = "1";      //Dirección del módulo
String lora_RX_address = "2";   //Dirección del módulo receptor

//AT+SEND=2,2,ON

void setup(){
  
  Serial2.begin(115200,SERIAL_8N1, 16,17); //16 es el pin RX y 17 el pin TX del esp32 devkitc v1 y v4
   
  //Serial2.begin(115200,SERIAL_8N1, 40,41); //40 es el pin RX y 41 el pin TX del esp32 devkitc v4. 
  Serial.begin(115200);

  delay(1500);
  Serial2.println("AT+BAND=" + lora_band);
  delay(500);  
  Serial2.println("AT+ADDRESS=" + lora_address);
  delay(500);
  Serial2.println("AT+NETWORKID=" + lora_networkid);
  delay(1500);

  Serial.println("Configurado ok!");
}

void loop()
{
    delay(100);
   if (Serial.available()) {
    // Lee un caracter del serial
    int num = Serial.read();
    // Si el caracter es 1
    if (num == '1') {
      Serial2.println("AT+SEND="+ lora_RX_address +",2,ON");  
      delay(2000);
      Serial.println("Comando enviado");
    }
  }

}
