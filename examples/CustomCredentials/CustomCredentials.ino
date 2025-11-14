#include <AGVController.h>

void setup() {
    // Single line setup with custom credentials
    AGV.begin("myuser", "mypassword");
}

void loop() {
    // Single line loop
    AGV.loop();
}