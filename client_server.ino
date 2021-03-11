// server
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
// client libraries
#include <BLEScan.h>

int id=1;

int sid=0;
char dtype;

char *SERVICE_UUIDS[] = {"4fafc201-1fb5-459e-8fcc-c5c9c331914b", "adbda632-8233-11eb-8dcd-0242ac130003", "0da307b6-8236-11eb-8dcd-0242ac130003"};
char *CHARACTERISTIC_UUIDS[] = {"beb5483e-36e1-4688-b7f5-ea07361b26a8","eff944d2-8235-11eb-8dcd-0242ac130003", "1665e260-8236-11eb-8dcd-0242ac130003"}; 

long t1, t2;
bool set_up = true;
char r = 'b'; 

void setup() {
  // put your setup code here, to run once:
  if(id == 0){
    dtype = 's';
  } else {
    dtype = 'c';
  }
  t1 = millis();
}

void loop() {
  t2 = millis();
  if(t2-t1<30000){
    if(dtype == 's'){
      if(r=='b'){
        setup_server();
      }
      loop_server();
    }
    else if(dtype == 'c'){
      if(r=='b'){
        setup_client();
      }
      loop_client();
    }
    r = 'a';
  } else {
    if(dtype == 's'){
      if(r == 'a'){
        setup_client();
      }
      loop_client();
    }
    else if(dtype == 'c'){
      if(r=='a'){
        setup_server();
      }
      loop_server();
    }
    r = 'b';
  }
  // put your main code here, to run repeatedly:
  
  
}
