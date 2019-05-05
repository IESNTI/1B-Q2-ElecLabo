/*
        Tempo.h
        librairie contenant le code pour la gestion des temporisations

*/
#ifndef Tempo_h
#define Tempo_h

#define DELAY_ON 1
#define DELAY_OFF 2
#define DELAY_PULSE 3

#include "Arduino.h"
/*
        classe Tempo
        val = valeur de la tempo
        mode = mode de fonctionnement de la tempo:
                DELAY_ON
                        la tempo passe à "1" une fois écoulée
                DELAY_OFF
                        la tempo passe à "0" une fois écoulée
                DELAY_PULSE
                        la tempo passe à "1" à l'activation, puis à "0" 
                        une fois écoulée

        restart() est la méthode de démarrage de la tempo
        ison() est la méthode qui lit le status de la tempo
        set() est la méthode qui met la tempo à une autre valeur
*/
class Tempo
{
        public:
                Tempo(int val, int mode);
                boolean ison();
                void restart();
                void set(int newVal);
        private: 
                int _mode;
                unsigned long _val;
                unsigned long _offset;
                boolean _status;
};

#endif
