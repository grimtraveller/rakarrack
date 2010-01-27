/*
  ZynAddSubFX - a software synthesizer
 
  Phaser.h - Phaser effect
  Copyright (C) 2002-2005 Nasca Octavian Paul
  Author: Nasca Octavian Paul

  Modified for rakarrack by Josep Andreu
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License 
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2) for more details.

  You should have received a copy of the GNU General Public License (version 2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

#ifndef PHASER_H
#define PHASER_H
#include "global.h"
#include "EffectLFO.h"

#define MAX_PHASER_STAGES 12
class Phaser
{
public:
  Phaser (REALTYPE * efxoutl_, REALTYPE * efxoutr_);
  ~Phaser ();
  void out (REALTYPE * smpsl, REALTYPE * smpsr);
  void setpreset (int npreset);
  void changepar (int npar, int value);
  int getpar (int npar);
  void cleanup ();
  void setdryonly ();
  int Ppreset;
  REALTYPE *efxoutl;
  REALTYPE *efxoutr;

  REALTYPE outvolume;
  REALTYPE volume;




private:
  //Parametrii Phaser
    EffectLFO lfo;		//lfo-ul Phaser
  int Pvolume;
  int Ppanning;
  int Pdepth;		//the depth of the Phaser
  int Pfb;		//feedback
  int Plrcross;	//feedback
  int Pstages;
  int Poutsub;	//if I wish to substract the output instead of the adding it
  int Pphase;

  //Control Parametrii
  void setvolume (int Pvolume);
  void setpanning (int Ppanning);
  void setdepth (int Pdepth);
  void setfb (int Pfb);
  void setlrcross (int Plrcross);
  void setstages (int Pstages);
  void setphase (int Pphase);

  //Valorile interne
  REALTYPE panning, fb, depth, lrcross, fbl, fbr, phase;
  REALTYPE *oldl, *oldr;
  REALTYPE oldlgain, oldrgain;
};

#endif