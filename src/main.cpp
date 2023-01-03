#include <application.h>
#include <debugger.h>

#include <memory>

std::unique_ptr<apc::application> app;

void setup() {
  apc::init_debugger();
  app = std::make_unique<apc::application>();
}

void loop() { app->update(); }