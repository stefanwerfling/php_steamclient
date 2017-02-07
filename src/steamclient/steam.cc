#include "steam.h"

zend_object_handlers steam_object_handlers;

struct steam_object {
    zend_object std;
    Steam *steam;
};

Steam::Steam():
	m_ctx() 
{
	
}

CSteamID Steam::getUserId() {
	return k_steamIDNil;
}

uint32 Steam::getAppId() {
	return 0;
}