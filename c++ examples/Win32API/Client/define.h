#pragma once

//#define SINGLE(type) static type* GetInst() {  static type core; return &core;}
// ΩÃ±€≈Ê ∏≈≈©∑Œ
#define SINGLE(type) public: \
                            static type* GetInst()\
                            {\
                                    static type mgr;\
                                    return &mgr;\
                            }\
                            private:\
                            type();\
                            ~type();

