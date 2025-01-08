#include "BleConnectionStatus.h"
#include "NimBLEDevice.h"

BleConnectionStatus::BleConnectionStatus(void)
{
}

void BleConnectionStatus::onConnect(NimBLEServer *pServer, NimBLEConnInfo& connInfo)
{
    //pServer->updateConnParams(connInfo.getConnHandle(), 6, 7, 0, 600);
    pServer->updateConnParams(connInfo.getConnHandle(), 24, 48, 0, 18);
    NimBLEDevice::startSecurity(connInfo.getConnHandle());
    this->connected = true;
}

void BleConnectionStatus::onDisconnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo, int reason)
{
    this->connected = false;
    NimBLEDevice::startAdvertising();
}

bool BleConnectionStatus::isConnected(){
    return this->connected;
}
