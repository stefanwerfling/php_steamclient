#include "steam/steam_api.h"
#include "php_steamclient.h"

static PHP_FUNCTION(steamclient_hello_world);
static PHP_FUNCTION(steamclient_init);
static PHP_FUNCTION(steamclient_shutdown);
static PHP_FUNCTION(steamclient_is_login);

PHP_STEAMCLIENT_API ZEND_DECLARE_MODULE_GLOBALS(steamclient)

/**
 * ArgInfos
 */
ZEND_BEGIN_ARG_INFO(arginfo_steamclient_hello_world, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_steamclient_init, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_steamclient_shutdown, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_steamclient_is_login, 0)
ZEND_END_ARG_INFO()

/**
 * Functions
 */		
static const zend_function_entry steamclient_functions[] = {
	PHP_FE(steamclient_hello_world, arginfo_steamclient_hello_world)
	PHP_FE(steamclient_init, arginfo_steamclient_init)
	PHP_FE(steamclient_shutdown, arginfo_steamclient_shutdown)
	PHP_FE(steamclient_is_login, arginfo_steamclient_is_login)
	PHP_FE_END
};

static PHP_MINIT_FUNCTION(steamclient)
{
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(steamclient)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "steamclient support", "enabled");
	php_info_print_table_row(2, "steamclient version", PHP_STEAMCLIENT_VERSION);
    php_info_print_table_end();
}

zend_module_entry steamclient_module_entry = {
    STANDARD_MODULE_HEADER,
	PHP_STEAMCLIENT_NAME,
    steamclient_functions,
	PHP_MINIT(steamclient),
    NULL,
	NULL,
	NULL,
	NULL,
	PHP_STEAMCLIENT_VERSION,
    STANDARD_MODULE_PROPERTIES
};

extern "C" {
	ZEND_GET_MODULE(steamclient)
}

static PHP_FUNCTION(steamclient_hello_world)
{
	RETURN_STRING("Hello World!");
}

/**
 * steamclient_init
 */
static PHP_FUNCTION(steamclient_init)
{
	RETURN_BOOL(SteamAPI_Init());
}

/**
 * steamclient_shutdown
 */
static PHP_FUNCTION(steamclient_shutdown)
{
	SteamAPI_Shutdown();
	RETURN_BOOL(true);
}

/**
 * steamclient_is_login
 */
static PHP_FUNCTION(steamclient_is_login)
{
	if( SteamUser() == nullptr ) {
		RETURN_BOOL(false);
	}
	
	RETURN_BOOL(true);
}