#include <Arduino.h>
#include <USBHost_t36.h>

#define APC_DEBUG 1

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <TimeLib.h>

#include <vector>

#define sclk 14 // SCLK can also use pin 14
#define mosi 11 // MOSI can also use pin 7
#define cs 10   // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define dc 9    //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define rst 8   // RST can use any pin

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, mosi, sclk, rst);

// Setup USBHost_t36 and as many HUB ports as needed.
USBHost myusb;
USBHub hub1(myusb);
USBHub hub2(myusb);
USBHub hub3(myusb);
USBHub hub4(myusb);

// Setup MSC for the number of USB Drives you are using. (Two for this example)
// Mutiple  USB drives can be used. Hot plugging is supported. There is a slight
// delay after a USB MSC device is plugged in. This is waiting for initialization
// but after it is initialized ther should be no delay.
USBDrive drive(myusb);
USBFilesystem partition(myusb);

bool driveConnected = false;

static constexpr const char* SupportedAudioFormats[] = { ".mp3", ".wav", ".flac" };

time_t getTeensyTime()
{
  return Teensy3Clock.get();
}

void init_core()
{
  Serial.begin(9600);

#if APC_DEBUG
  while (!Serial)
  {
    // wait for serial port to connect.
  }
#endif

  // set the Time library to use Teensy 3.0's RTC to keep time
  setSyncProvider(getTeensyTime);

  if (timeStatus() != timeSet)
  {
    Serial.println("Unable to sync with the RTC");
  }
  else
  {
    Serial.println("RTC has set the system time");
  }
}

void init_gui()
{
  tft.initR(INITR_GREENTAB);
  tft.setRotation(1);
  tft.setTextColor(ST7735_WHITE);
}

bool is_supported(File file) {
  const char *dot = strrchr(file.name(), '.');

  for (auto ext : SupportedAudioFormats) {
    if (strcmp(dot, ext) == 0) {
      return true;
    }
  }

  return false;
}

void update_gui()
{
  // gslc_Update(&m_gui);
  tft.fillScreen(ST7735_BLACK);

  tft.setCursor(0, 0);

  char s[9]; // Create an array to hold the formatted time string

  tmElements_t ts;
  breakTime(now(), ts);

  sprintf(s, "%02d:%02d:%02d", ts.Hour, ts.Minute, ts.Second);

  tft.print(s);

  if (partition)
  {
    tft.setCursor(0, 20);

    File dir = partition.open("/");

    tft.setTextColor(ST7735_RED);
    tft.printf("%16.16s", drive.msDriveInfo.inquiry.ProductID); 
    tft.setTextColor(ST7735_WHITE);

    for(;;)
    {
      File entry = dir.openNextFile();

      if (!entry) {
        break;
      }

      tft.setCursor(0, tft.getCursorY() + 10);

      if (entry.isDirectory())
      {
        tft.printf("%s", entry.name());
      }
      else
      {

        if (!is_supported(entry)) {
          continue;
        }

        tft.printf("%s (%.2f MB)", entry.name(), entry.size() / 1048576.0f);
      }
    }
  }

  delay(1000);
}

void init_usb_host()
{
  Serial.println("Initializing usb host...");
  myusb.begin();
}

void update_usb_host()
{
  myusb.Task();

  bool isDriveAvailable = partition;

  if (!driveConnected && isDriveAvailable)
  {
    driveConnected = true;
    Serial.printf("Device connected: %16.16s\n", drive.msDriveInfo.inquiry.ProductID);
  }
  else if (driveConnected && !isDriveAvailable)
  {
    driveConnected = false;
    Serial.println("Device disconnected");
  }
}

void setup()
{
  init_core();
  init_gui();
  init_usb_host();
}

void loop()
{
  update_gui();
  update_usb_host();
}
