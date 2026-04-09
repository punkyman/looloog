#pragma once

#include "control/control.h"
#include "pot/pot.h"
#include "button/button.h"
#include "mux/mux.h"

#define DECLARE_MUX_CONTROLS(name_, channel_) \
Control* name_[] = { \
  new Pot   (channel_,    0), \
  new Pot   (channel_,    1), \
  new Pot   (channel_,    2), \
  new Pot   (channel_,    3), \
  new Pot   (channel_,    4), \
  new Pot   (channel_,    5), \
  new Pot   (channel_,    6), \
  new Button(channel_,    7), \
  new Button(channel_,    8), \
  new Pot   (channel_,    9), \
  new Pot   (channel_,    10),\
  new Pot   (channel_,    11),\
  new Pot   (channel_,    12),\
  new Pot   (channel_,    13),\
  new Pot   (channel_,    14),\
  new Pot   (channel_,    15),\
};

#define DECLARE_MUX(name_, cspin_, sigpin_, midichannel_) \
DECLARE_MUX_CONTROLS(name_##Controls, midichannel_) \
Mux name_(name_##Controls, 16, cspin_, sigpin_);
