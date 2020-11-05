
# Carpeta Board:

__edu_ciaa_nxp__

<ul>
	<li><p>inc</p>
	<ul>
		<li><pre><code>board.h → define MACROS para ubicar cada  componente o funcionalidad en la placa</code></pre></li>
		<li><pre><code>board_api.h → definicion de funciones basicas y de macros para el debug </code></pre></li>
	</ul>
	<li><p>src</p>
	<ul>
		<li><pre><code>board.c → implementacion de las funciones de board_api.h configuracion de los pines, y funcionalidades. Configuracion de entradas, leds, etc.						</code></pre></li>
		<li><pre><code>board_sysinit.c → definicion de todos los pines </code></pre></li>
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
	<li><pre><code>inc → definicion de funciones</code></pre></li>
	<li><pre><code>src → implementacion de funciones</code></pre></li>
	<li><pre><code>usbd_rom → macros de posiciones de memoria</code></pre></li>
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
