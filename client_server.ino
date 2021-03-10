// server
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
// client libraries
#include <BLEScan.h>

#define id 1
char dtype = 's';

void setup() {
  // put your setup code here, to run once:
  if(dtype == 's'){
    setup_server();
  } else if(dtype == 'c'){
    setup_client();
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(dtype == 's'){
    loop_server();  
  }
  else if(dtype == 'c'){
    loop_client();
  }
}
