#ifndef STEAMCLIENT_STEAM_H
#define STEAMCLIENT_STEAM_H

extern "C" {
	#include "php.h"
	#include "php_ini.h"
	#include "ext/standard/info.h"
	#include "zend_smart_str.h"
}

#include "steam/steam_api.h"

class Steam {
public:
	Steam();
	
	// general stuff
	CSteamID getUserId();
	uint32 getAppId();
	
	
private:
	
	CSteamAPIContext m_ctx;
};

#endif