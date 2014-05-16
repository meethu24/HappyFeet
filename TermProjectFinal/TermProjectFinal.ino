
#include <Console.h>
#include<Bridge.h>
#include<YunServer.h>
#include<YunClient.h>

String name;
String command = "madplay /mnt/sda1/YunSoundboard-master/sounds/godzilla.mp3";
String song;

const int button = 2;
int buttonState = 0;

Process p;
//YunServer server;

void setup() {
  
  Bridge.begin();
  Console.begin(); 
  
  pinMode(button, INPUT);
  
  while (!Console); 
  
  Console.println("Choose a sound");
  Console.println("1. alarm");
  Console.println("2. cartoon_hop");
  Console.println("3. burp-1");
  Console.println("4. creak");
  Console.println("5. godzilla");
  Console.println("6. leaves");
  Console.println("7. mario");
  Console.println("8. kungfu");
  Console.println("9. heartbeat-04");
  Console.println("10. werewolf_vocalisation_1");
} 

void loop() {
  if (Console.available() > 0) {
    char c = Console.read();
    if (c == '\n') {
      song = "/mnt/sda1/YunSoundboard-master/sounds/"+name+".mp3";
      command = "madplay "+song;
    } 
    else {
        name = name + c;
    }
  }
  CheckButtonStatus();
}

void CheckButtonStatus(){
  buttonState = digitalRead(button);
  if (buttonState == HIGH){
    p.runShellCommand(command);
    while(p.running());
    name="";
  }
  else{
    //do nothing
  }
}
