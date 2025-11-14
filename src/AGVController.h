#ifndef AGVCONTROLLER_H
#define AGVCONTROLLER_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>
#include <ESPmDNS.h>
#include <Preferences.h>
#include <DNSServer.h>

class AGVController {
public:
    AGVController();
    ~AGVController();

    void begin(const char* adminUser = "admin", const char* adminPass = "admin123");
    void loop();

    // Public methods for external use
    void sendWebSocketMessage(const String& message);
    bool isConnected();
    String getLocalIP();
    void restart();

private:
    // WiFi and server objects
    WebServer* server;
    WebSocketsServer* webSocket;
    DNSServer* dnsServer;
    Preferences preferences;

    // Configuration
    String admin_username;
    String admin_password;
    String stored_ssid;
    String stored_password;
    const char* ap_ssid;
    const char* ap_password;
    const char* mdnsName;

    // State variables
    bool isAPMode;
    bool isAuthenticated;
    String sessionToken;

    // Private methods
    void startAPMode();
    void startStationMode();
    String getSessionToken();
    
    // Web handlers
    void handleRoot();
    void handleLogin();
    void handleDashboard();
    void handleWiFiSetup();
    void handleScan();
    void handleSaveWiFi();
    void handleCaptivePortal();
    void webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t length);
};

// Global instance for easy access
extern AGVController AGV;

#endif