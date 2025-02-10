#include <Arduino.h>
#include <FlexCAN_T4.h>

FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;

void setup()
{
  Serial.begin(115200);
  delay(100);
  can1.begin();
  delay(100);
  can1.setBaudRate(500000); // 500kbps baud rate
  delay(100);
  Serial.println("CAN1 Sender Initialized");
}

void loop()
{
  delay(100);
  CAN_message_t msg;
  delay(100);
  msg.id = 0x123; // Message ID
  delay(100);
  msg.len = 5; // Message length
  delay(100);
  msg.buf[0] = 'h';
  delay(100);
  msg.buf[1] = 'e';
  delay(100);
  msg.buf[2] = 'l';
  delay(100);
  msg.buf[3] = 'l';
  delay(100);
  msg.buf[4] = 'o';
  delay(100);
  msg.buf[5] = ' ';

  can1.write(msg); // Send message
  delay(100);
  Serial.print("Message Sent: ");
  for (int i = 0; i < msg.len; i++)
  {
    Serial.print((char)msg.buf[i]);
  }
  Serial.println();

  delay(1000); // Send message every second
}
