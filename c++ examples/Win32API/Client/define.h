#pragma once

//#define SINGLE(type) static type* GetInst() {  static type core; return &core;}
// ½Ì±ÛÅæ ¸ÅÅ©·Î
#define SINGLE(type) public: \
                            static type* GetInst()\
                            {\
                                    static type mgr;\
                                    return &mgr;\
                            }\
                            private:\
                            type();\
                            ~type();

#define fDT CTimeMgr::GetInst()->GetfDT()
#define DT CTimeMgr::GetInst()->GetDT()