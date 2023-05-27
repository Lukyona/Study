#pragma once

//#define SINGLE(type) static type* GetInst() {  static type core; return &core;}

#define SINGLE(type) static type* GetInst()\
                                         {\ 
                                            static type core;\
                                             return &core;\
                                         }

