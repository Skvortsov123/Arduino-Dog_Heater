#include "Protection.h"
#include "Heater.h"

class Manager{
  public:
    void manage(int tmp, float poten){
      _adjusted = poten * _step + _minTmp;
      if (_adjusted + _a >= tmp){
        heater.heatOn();
        protect.tick(tmp);
        _a = _threshold;
      }else{
        heater.heatOff();
        protect.reboot();
        _a = _threshold * -1;
      }
    }
  private:
    int _minTmp = 10;
    int _step = 30;
    int _threshold = 2;
    int _a = 0;
    int _adjusted;
};
