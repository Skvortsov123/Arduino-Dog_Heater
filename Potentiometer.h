

class Potentiometer{
  public:
    Potentiometer(int pin){
      _pin = pin;
      pinMode(pin,INPUT);
    }
    float getState(){
      return analogRead(_pin)/1023.0;
    }
    
  private:
    int _pin;
};
