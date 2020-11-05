
# Carpeta Board:

__edu_ciaa_nxp__
.................
-inc
.................

 - board.h --> define MACROS para ubicar cada  componente o funcionalidad en la placa 
 - board_api.h --> definicion de funciones basicas y de macros para el debug
.................

..*src
		..* board.c --> implementacion de las funciones de board_api.h
					configuracion de los pines, y funcionalidades
					Configuracion de entradas, leds, etc.
		---------- board_sysinit.c --> definicion de todos los pines
.................
---------lib
	---------flat.id
	---------libs.id
	---------link.id
	---------mem.id

---------lpc_chip_43xx
	---------inc -->definicion de funciones
		
	---------src --> implementacion de funciones

	---------usbd_rom -->macros de posiciones de memoria  		

---------lpc_startup/src
---------module.mk --> directorio de los archivos ejecutables y los includes.
