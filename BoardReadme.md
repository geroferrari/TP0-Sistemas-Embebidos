# Carpeta Board:

__edu_ciaa_nxp__

<ul>
	<li><p>inc</p>
	<ul>
		<li>board.h → define MACROS para ubicar cada  componente o funcionalidad en la placa</li>
		<li>board_api.h → definicion de funciones basicas y de macros para el debug </li>
	</ul>
	<li><p>src</p>
	<ul>
		<li>board.c → implementacion de las funciones de board_api.h configuracion de los pines, y funcionalidades. Configuracion de entradas, leds, etc.						</li>
		<li>board_sysinit.c → definicion de todos los pines </li>
	</ul>
</ul>

__lib__

<ul>
	<li><p>flat.id</p></li>
	<li><p>libs.id</p></li>
	<li><p>link.id</p></li>
	<li><p>mem.id</p></li>
</ul>

__lpc_chip_43xx__

<ul>
	<li>inc → definicion de funciones</li>
	<li>src → implementacion de funciones</li>
	<li>usbd_rom → macros de posiciones de memoria</li>
</ul>

__lpc_startup__
<ul>
	<li>src</li>
	<ul>
		<li>crp.c</li>
		<li>sysinit.c</li>
		<li>vendor_interrupt.c</li>
	</ul>
</ul>

__module.mk__
directorio de los archivos ejecutables y los includes.
