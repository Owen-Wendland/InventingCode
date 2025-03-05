#include <EEPROM.h>

void erase(void)
{
  for (int i = 0 ; i < EEPROM.length() ; i++)
	EEPROM.write(i, 0);
}

void printMessage(byte* first, size_t len)
{
  for (int i = 0; i < len; i++)
  {
	Serial.print((char)first[i]);
  }
}

void writeMsg(byte* first, size_t len)
{
  for(int i = 0; i < len; i++)
  {
	EEPROM.write(i, first[i]);
  }
}

void readMsg(size_t len)
{
  byte res;
 
  Serial.print("Message: ");
  for(int i = 0; i < len; i++)
  {
	res = EEPROM.read(i);
	Serial.print((char)res);
  }
  Serial.println("");
}

void setup()
{
  char* string = "Hello World!";
 
  Serial.begin(9600);
 
  Serial.print("Serial connection opened!\n");
  Serial.print("EEPROM length: ");
  Serial.println(EEPROM.length());
 
  Serial.print("Attempting to erase EEPROM... ");
  erase();
  Serial.print("Done!\n");
 
  Serial.print("Message: ");
  printMessage(string, 12);
  Serial.print("\n");
 
  Serial.print("Attempting to write to EEPROM...\n");
  writeMsg(string, 12);
  Serial.print("Done!\n");
  Serial.print("Attempting to read from EEPROM...\n");
  readMsg(12);
  Serial.print("Done!\n");
}

void loop()
{ }
