//HV...suspicious!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!,TSAL,additional SW,interlock,micro_sw,
int accnpedal1,accnpedal2,brakepedal,HV,accnav;

bool startcondn(){
  if(brakepedal>(0.2*1023)){//start button pressed or not
    return true;
    }
    else {
      return false;}
  }
  void buzzer(){
    digitalWrite(12,1);     
    }
    void buzzerstop(){
    digitalWrite(12,0); 
    }
  void precharge(){
    digitalWrite(10,1);
    }
    void mainrelon(){
      digitalWrite(10,0);
      digitalWrite(11,1);
      //turn off precharge and start mainrelay}
void start(){
  digitalWrite(14,1);
  buzzer();
  precharge();
  delay(3000);
  buzzerstop();
  delay(2000);
  mainrelon();
  }
 
bool plauscheck(){
  if((accnav>0.3*(1023))&&(brakepedal>0.15*1023)){
      return false;}
      else{ 
        return true;
        }
  }

  
bool check(){
  if ((accnpedal1<(0.9*1023)&&accnpedal1>(0.1*1023))&&(accnpedal2<(0.9*1023)&&accnpedal2>(0.1*1023))&&(brakepedal<(0.9*1023)&&brakepedal>(0.1*1023))){
    if(abs((accnpedal1-accnpedal2)/accnpedal1)<0.1){
      return true;
      }
    else{
      return false;}
    }
    else{
      return false;}
  }


void shtdown(){
  digitalWrite(14,0);    
  }
  void tmpshtdown(){
    digitalWrite(11,0);
    while(accnav>0.3*(1023){
//
      }
  digitalWrite(11,1);
    }

  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6,OUTPUT);//throtle interlock
  pinMode(7,OUTPUT);//throttle switch
  pinMode(8,OUTPUT);//accn
  pinMode(9,OUTPUT);//brake
  pinMode(10,OUTPUT);//prechareg
  pinMode(11,OUTPUT);//mainrelay
  pinMode(12,OUTPUT);//buzzz
  pinMode(13,OUTPUT);//TSAL_OK......!!!!!!!!!!!!
  pinMode(14,OUTPUT);//control relay
  pinMode(15,OUTPUT);//additional SW....!!!!!!!!!!!!!



digitalWrite(6,0);
digitalWrite(7,0);
digitalWrite(8,0);
digitalWrite(9,0);
digitalWrite(10,0);
digitalWrite(11,0);
digitalWrite(12,0);  
digitalWrite(13,0);
digitalWrite(14,0);
digitalWrite(15,0);

if(startcondn()&&check()){
    start();  
    }


}

void loop() {
  // put your main code here, to run repeatedly:
 accnpedal1=analogRead(22);
 accnpedal2=analogRead(21);
 brakepedal=analogRead(20);
 HV=analogRead(19);
 accnav=(accnpedal1+accnpedal2)/2;
 if(check()){
  if (plauscheck()){
    
    //runningsljdgf;lagjvas;a
    analogWrite(8,accnav*255/1023);
    analogWrite(9,brakepedal*255/1023);
    analogWrite(8,accnav*255/1023);
    }
    else{
      tmpshtdown();
      }
  }
  
  }
  else{
    shtdown();
    }
}
