// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#ifdef _DEBUG          // console을 attach, 조건은 iostream include위에
#pragma comment(linker,"/entry:wWinMainCRTStartup /subsystem:console")
#endif

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <ctime>

//c++ 관련
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <mutex>
using namespace std;

// GDIPlus
#include <ole2.h>
#include <gdiplus.h>
using namespace Gdiplus;

#pragma comment(lib,"Gdiplus.lib")
#pragma comment(lib,"msimg32.lib")



#define  SAFE_DELETE(p)  { if(p) { delete (p); (p) =NULL;}

#define DCAST dynamic_cast

//사용자 정의
#include "Vector2.h"
#include "Base/Matrix4x4.h"
#include "System/GameTime.h"
#include "System/Mouse.h"
#include "System/Keyboard.h"

#include "Collider/Collider.h"
#include "Collider/Line.h"
#include "Collider/Collision.h"

#include "Base/GameObject.h"
#include "Base/ObjectManager.h"
#include "Render/Camera.h"

#include "MainWindow.h"
#include "Base/Scene.h"
#include "Base/SceneManager.h"
#include "Render/SRVMgr.h"
#include "Render/Sprite.h"


