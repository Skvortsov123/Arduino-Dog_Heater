#ifndef  Protection_h
#define Protection_h

class Protection{
  public:
    void tick(int tmp){
      if (_tick == true){
        if (_oneTick == true){
          _oneTick = false;
          _tmpTick = tmp;
          _timeTick = millis()/1000;
        }
        
        if (millis()/1000 - _timeTick >= 25 or tmp - _tmpTick >= 2){
          if (tmp - _tmpTick >= 2){
            _tick = false;
          }else{
            _tick = false;
            heater.hardStop();
          }
        }
      }
    }

    void reboot(){
      _tick = true;
      _oneTick = true;
    }
  private:
    bool _tick = true;
    bool _oneTick = true;
    int _tmpTick;
    int _timeTick;
};


Protection protect;

#endif
