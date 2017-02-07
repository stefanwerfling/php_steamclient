#ifndef PHP_STEAMCLIENT_H
#define PHP_STEAMCLIENT_H

#define PHP_STEAMCLIENT_VERSION "0.0.2"
#define PHP_STEAMCLIENT_NAME "steamclient"
#define PHP_STEAMCLIENT_EXTNAME "php_steamclient"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

extern "C" {
	#include "php.h"
	#include "php_ini.h"
	#include "ext/standard/info.h"
	#include "zend_smart_str.h"
}

extern zend_module_entry steamclient_module_entry;
#define phpext_steamclient_ptr &steamclient_module_entry

#if defined(PHP_WIN32)
#define PHP_STEAMCLIENT_API __declspec(dllexport)
#else
#define PHP_STEAMCLIENT_API PHPAPI
#endif


#ifdef ZTS
#include "TSRM.h"
#endif

PHP_STEAMCLIENT_API ZEND_EXTERN_MODULE_GLOBALS(steamclient)

#endif