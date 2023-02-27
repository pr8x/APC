#include <application.h>
#include <debug.h>

#include <memory>

namespace {

void setup_serial() {
  Serial.begin(9600);

#if APC_DEBUG
  while (!Serial) {
    // wait for serial port to connect.
  }
#endif
}

time_t get_teensy_time() { return Teensy3Clock.get(); }

void sync_with_RTC() {
  // set the Time library to use Teensy RTC to keep time
  setSyncProvider(get_teensy_time);

  if (timeStatus() != timeSet) {
    Serial.println("Unable to sync with the RTC");
  } else {
    Serial.println("RTC has set the system time");
  }
}

inline void init_debugger() { debug.begin(SerialUSB1); }

}  // namespace

std::unique_ptr<apc::application> app;

void setup() {
  setup_serial();
  sync_with_RTC();

#if APC_DEBUG
  if (CrashReport) {
    Serial.print(CrashReport);
  }
#endif

#if APC_ENABLE_GDB_STUB
  init_debugger();
#endif

  app = std::make_unique<apc::application>();
}

void loop() { app->update(); }