#include "AGVControllerWrapper.h"

void setupAGVController(const char* adminUser, const char* adminPass) {
    AGV.begin(adminUser, adminPass);
}

