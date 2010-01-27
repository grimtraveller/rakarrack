
// Based in gate_1410.c LADSPA Swh-plugins

/*
  rakarrack - a guitar effects software

 Gate.h  -  Noise Gate Effect definitions
 Based on artscompressor.cc by Matthias Kretz <kretz@kde.org>
 Stefan Westerfeld <stefan@space.twc.de> 
 
  Copyright (C) 2008 Daniel Vidal & Josep Andreu
  Author: Daniel Vidal & Josep Andreu

 This program is free software; you can redistribute it and/or modify
 it under the terms of version 2 of the GNU General Public License
 as published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License (version 2) for more details.

 You should have received a copy of the GNU General Public License
 (version2)  along with this program; if not, write to the Free Software
 Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/


#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "global.h"
#include "AnalogFilter.h"

#define REALTYPE float
#define CLOSED  1
#define OPENING 2
#define OPEN    3
#define CLOSING 4
#define ENV_TR 0.0001f

class Gate
{

public:

  Gate (REALTYPE * efxoutl_, REALTYPE * efxoutr_);
  ~Gate ();

  void out (REALTYPE * smps_l, REALTYPE * smps_r);

  void Gate_Change (int np, int value);
  void Gate_Change_Preset (int npreset);
  void cleanup ();
  int getpar (int npar);

  REALTYPE *efxoutl;
  REALTYPE *efxoutr;



  // Compressor

  int Pthreshold;		// attack time  (ms)
  int Pattack;			// release time (ms)
  int Ohold;
  int Pdecay;
  int Prange;
  int Plpf;
  int Phpf;
  int Phold;

private:

  int hold_count;
  int state;
  float range;
  float cut;
  float t_level;
  float a_rate;
  float d_rate;
  float env;
  float gate;
  float fs;
  float hold;

  void setlpf (int Plpf);
  void sethpf (int Phpf);


  AnalogFilter *lpfl, *lpfr, *hpfl, *hpfr;


};

#endif