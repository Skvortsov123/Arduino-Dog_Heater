

class Heartbeat{
  public:
    Heartbeat(int pin){
      _pin = pin;
      pinMode(pin,OUTPUT);
    }
    void beat(){
      if (millis()/1000 >= _countbeat) {
        _countbeat = millis()/1000 + 1;
        if (_ifbeat == false){
          _ifbeat = true;
          digitalWrite(_pin, HIGH);
        }else{
          _ifbeat = false;
          digitalWrite(_pin, LOW);
        }
      }
      
    }

  private:
    int _countbeat;
    bool _ifbeat;
    int _pin;
};
