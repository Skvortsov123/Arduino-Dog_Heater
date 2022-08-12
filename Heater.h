#ifndef  Heater_h
#define Heater_h

class Heater{
  public:
    Heater(int pin){
      _pin = pin;
      pinMode(pin,OUTPUT);
    }
  
    void heatOn(){
      if (_hardStop == false){
        digitalWrite(_pin, HIGH);
      }else{
        digitalWrite(_pin, LOW);
      }
    }
    void heatOff(){
      digitalWrite(_pin, LOW);
    }
    void hardStop(){
      _hardStop = 1;
    }
    
    
  private:
    int _pin;
    bool _hardStop = 0;
};

Heater heater(4);

#endif
