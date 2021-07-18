//
//  wTF.cpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#include "wTF.hpp"

VOID wTF::Initialize() {
	GameHooker::Install();
	DirectXHooker::Install();
}

VOID wTF::ESCAPE() {

}