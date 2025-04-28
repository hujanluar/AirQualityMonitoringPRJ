CC=gcc
CFLAGS=-Iinc -Iunity

SRC=src/adc.c src/mq135.c src/pm25.c
MOCK=test/mock_adc.c test/mock_mq135.c test/mock_pm25.c
TEST_ADC=test/test_adc.c
TEST_MQ135=test/test_mq135.c
TEST_PM25=test/test_pm25.c
TEST_LED=test/test_led.c
TEST_UART=test/test_uart.c
TEST_LCD=test/test_lcd.c

UNITY_SRC=unity/unity.c

TARGET_ADC=test_adc.exe
TARGET_MQ135=test_mq135.exe
TARGET_PM25=test_pm25.exe
TARGET_LED=test_led.exe
TARGET_UART=test_uart.exe
TARGET_LCD=test_lcd.exe


all: test_adc test_mq135 test_pm25 test_led test_uart test_lcd

test_adc:
	$(CC) $(TEST_ADC) test/mock_adc.c src/adc.c unity/unity.c $(CFLAGS) -o $(TARGET_ADC)
	./$(TARGET_ADC)

test_mq135:
	$(CC) $(TEST_MQ135) test/mock_mq135.c src/mq135.c unity/unity.c $(CFLAGS) -o $(TARGET_MQ135)
	./$(TARGET_MQ135)

test_pm25:
	$(CC) $(TEST_PM25) test/mock_pm25.c src/pm25.c unity/unity.c $(CFLAGS) -o $(TARGET_PM25)
	./$(TARGET_PM25)

test_led:
	$(CC) $(TEST_LED) test/mock_led.c src/led.c unity/unity.c $(CFLAGS) -o $(TARGET_LED)
	./$(TARGET_LED)

test_uart:
	$(CC) $(TEST_UART) test/mock_uart.c src/uart.c unity/unity.c $(CFLAGS) -o $(TARGET_UART)
	./$(TARGET_UART)

test_lcd:
	$(CC) $(TEST_LCD) test/mock_lcd.c src/lcd.c unity/unity.c $(CFLAGS) -o $(TARGET_LCD)
	./$(TARGET_LCD)
clean:
	rm -f *.exe
