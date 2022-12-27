#include <application.h>
#include <memory>

std::unique_ptr<apc::application> app;

void setup() {
    app = std::make_unique<apc::application>();
}

void loop() { app->update(); }