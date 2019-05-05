/*
        Tempo.cpp
        méthodes de créations des tempos
*/

#include "Arduino.h"
#include "Tempo.h"

Tempo::Tempo( int val, int mode )
{
        _mode = mode ;
        _val = val ;
        if (_mode == 2) { _status = 1 ; }			// si delay_off
        else          	{ _status = 0 ; }			// dans les autres cas
        _offset = millis() + val ;					// actuel = offset
}

boolean Tempo::ison()
{
        boolean m1 ;
        unsigned long valt ;
        valt = millis() ;
        switch ( _mode )
        {
			case 1:									// si delay_on:
				if ((unsigned long)(valt > _offset)) 				// et si temps écoulé
					{ _status = 1; return 1; } 		// status = 1
                else 							  
					{return 0; }					// si temps pas écoulé
                break;
            case 2:									// si delay_off:
                if ((unsigned long)(valt > _offset)) 				// et si temps écoulé 
					{ _status = 0; return 0; } 		// status = 0 
                else                              
					{return 1; }					// si temps pas écoulé
                break;
            case 3:									// si delay_pulse:
                if ((unsigned long)(valt > _offset)) 				// et si temps écoulé 
					{ _status = 0; return 0; } 		// status = 0 
                else                              
					{return 1; }					// si temps pas écoulé
                break;
            default:
                return -1;							// en cas d'erreur
        }
}

void Tempo::restart()								// méthode de redémarrage de la tempo
{
        if (_mode == 2) {_status = 1; }
        else            {_status = 0; }
        _offset = millis() + _val;					// recalcul nouvel offset
}

void Tempo::set(int newVal)							// réglage de la nouvelle valeur de Tempo
{
	_val = newVal;
}
