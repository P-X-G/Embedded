#define SCK 13
#define MISO 12
#define MOSI 11
#define SS 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  pinMode(SCK, INPUT);
  pinMode(MOSI,INPUT);
  pinMode(SS, INPUT_PULLUP);
}

void loop(){
  uint8_t sData = 0x00, i = 0;
  while(SS == 1);
  while(SCK == 0);
  while(i < 8){
    uint8_t SCK_temp = digitalRead(SCK);
    uint8_t MOSI_temp = digitalRead(MOSI);
    if(SCK_temp == 1){
      sData = sData << 1;
      sData = sData | MOSI_temp;
      i++;
      while(SCK_temp == 1){
        SCK_temp = digitalRead(SCK);
      }
    }
    if(i == 8){
      Serial.println(sData,DEC);
      i = 0;
      sData = 0;
      MOSI_temp = 0;
    }
  }
}
