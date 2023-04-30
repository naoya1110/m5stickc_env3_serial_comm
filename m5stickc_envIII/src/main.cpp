/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5StickC sample source code
*                          配套  M5StickC 示例源代码
* Visit for more information: https://docs.m5stack.com/en/unit/envIII
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/unit/envIII
*
* Product: ENVIII_SHT30_QMP6988.  环境传感器
* Date: 2022/7/20
*******************************************************************************
  Please connect to Port,Read temperature, humidity and atmospheric pressure and
  display them on the display screen
  请连接端口,读取温度、湿度和大气压强并在显示屏上显示
*/
#include <M5StickC.h>
#include "M5_ENV.h"

SHT3X sht30;
QMP6988 qmp6988;

float tmp      = 0.0;
float hum      = 0.0;
float pressure = 0.0;

void setup() {
    M5.begin();             // Init M5StickC.  初始化M5StickC
    Serial.begin(115200);
    M5.Lcd.setRotation(3);  // Rotate the screen.  旋转屏幕
    Wire.begin();  // Wire init, adding the I2C bus.  Wire初始化, 加入i2c总线
    qmp6988.init();
    M5.lcd.println(F("ENVIII Unit(SHT30 and QMP6988) test"));
}

void loop() {
    pressure = qmp6988.calcPressure();
    if (sht30.get() == 0) {  // Obtain the data of shT30.  获取sht30的数据
        tmp = sht30.cTemp;   // Store the temperature obtained from shT30.
                             // 将sht30获取到的温度存储
        hum = sht30.humidity;  // Store the humidity obtained from the SHT30.
                               // 将sht30获取到的湿度存储
    } else {
        tmp = 0, hum = 0;
    }
    M5.lcd.fillRect(0, 20, 100, 60, BLACK);  // Fill the screen with black
    M5.lcd.setCursor(0, 20);
    M5.Lcd.printf("Temp: %2.1f  \r\nHumi: %2.0f%%  \r\nPressure:%2.0fPa\r\n", tmp, hum, pressure);
    Serial.printf("Temp:%2.1f,  Humi:%2.0f%,  Pres:%2.0f\r\n", tmp, hum, pressure);
    delay(1000);
}
