# Criptografia y Seguridad en Redes

## Trabajo Practico 7 - Wordpress

### Integrantes:

- Cabrera, Augusto Gabriel
- Gil Cernich, Manuel
- Mayorga, Federica

---
## Marco Teorico

### LAMP

LAMP es un acrónimo que se refiere a un conjunto de software utilizado comúnmente para desarrollar y ejecutar aplicaciones web dinámicas. Cada letra de "LAMP" representa un componente clave:

- **L**: **Linux** – Sistema operativo (puede ser cualquier distribución de Linux como Ubuntu, Debian, etc.).
- **A**: **Apache** – Servidor web que gestiona las solicitudes HTTP y las respuestas.
- **M**: **MySQL** (o en algunos casos **MariaDB**) – Sistema de gestión de bases de datos relacional utilizado para almacenar y gestionar los datos.
- **P**: **PHP**, **Perl** o **Python** – Lenguajes de programación usados para la lógica del lado del servidor.

Un servidor LAMP es una solución de software de código abierto que se usa ampliamente para crear sitios web dinámicos y aplicaciones basadas en la web. Es conocido por su flexibilidad, escalabilidad y facilidad de implementación.

--- 


## Desarrollo

#### Instalar un entorno LAMP en las computadoras


A continuación se detallan los pasos para instalar un entorno LAMP (Linux, Apache, MySQL/MariaDB, PHP) en Ubuntu.

##### Paso 1: Actualizar los paquetes
Primero, se debe actualizar el sistema para asegurarse de que todos los paquetes estén actualizados. Ejecute los siguientes comandos:

```bash
sudo apt update
sudo apt upgrade
```

##### Paso 2: Instalar Apache
Apache es el servidor web necesario para el entorno LAMP. Para instalarlo, use el siguiente comando:

```bash
sudo apt install apache2
```

Una vez instalado, puede verificar que Apache está funcionando accediendo a `http://localhost` en su navegador.

<p align="center">
  <a href="https://example.com/">
    <img src="img/image1.png" alt="bloques">
  </a>
  </p>

##### Paso 3: Instalar MySQL o MariaDB
A continuación, instalaremos MariaDB (una bifurcación de MySQL) como base de datos. Ejecute el siguiente comando:

```bash
sudo apt install mariadb-server mariadb-client
```

Para asegurar la instalación, es recomendable ejecutar el siguiente comando de seguridad:

```bash
sudo mysql_secure_installation
```

##### Paso 4: Instalar PHP
PHP es el lenguaje de programación necesario para el entorno LAMP. Instálelo utilizando el siguiente comando:

```bash
sudo apt install php libapache2-mod-php php-mysql
```

Para verificar que PHP está funcionando correctamente, cree un archivo de prueba en el directorio `/var/www/html/`:

```bash
sudo nano /var/www/html/info.php
```

Dentro del archivo, añada el siguiente contenido:

```bash
<?php
phpinfo();
?>
```

Luego, guarde el archivo y acceda a http://localhost/info.php en su navegador para verificar la instalación de PHP.

<p align="center">
  <a href="https://example.com/">
    <img src="img/image2.png" alt="bloques">
  </a>
  </p>


##### Paso 5: Reiniciar Apache
Después de instalar PHP, reinicie Apache para que los cambios surtan efecto:

```bash
sudo systemctl restart apache2
```



### Instalar WordPress y añadir plugins de seguridad

Ya que estás en Ubuntu con LAMP configurado, sigue estos pasos para instalar WordPress:

##### a. Descargar WordPress

```bash
cd /var/www/html
sudo wget https://wordpress.org/latest.tar.gz
sudo tar -xzvf latest.tar.gz
sudo mv wordpress/* .
sudo rm -rf wordpress latest.tar.gz
```

##### b. Asignar permisos

```bash
sudo chown -R www-data:www-data /var/www/html
sudo chmod -R 755 /var/www/html
```

<p align="center">
  <a href="https://example.com/">
    <img src="img/image3.png" alt="bloques">
  </a>
  </p>


##### c. Configurar la base de datos

Inicia sesión en MySQL:

```bash
mysql -u root -p
```

Crea una base de datos para WordPress:

```bash
CREATE DATABASE wordpress_db;
CREATE USER 'wordpress_user'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'wordpress_user'@'localhost';
FLUSH PRIVILEGES;
EXIT;
```


<p align="center">
  <a href="https://example.com/">
    <img src="img/image4.png" alt="bloques">
  </a>
  </p>




##### d. Configurar WordPress

Copia el archivo de configuración predeterminado:

```bash
cp wp-config-sample.php wp-config.php
```

Edita wp-config.php:

```bash
sudo nano wp-config.php
```

Rellena los datos de la base de datos:

```bash
define( 'DB_NAME', 'wordpress_db' );
define( 'DB_USER', 'wordpress_user' );
define( 'DB_PASSWORD', 'password' );
define( 'DB_HOST', 'localhost' );
```

##### e. Finalizar instalación a través del navegador

Visita http://localhost en tu navegador y sigue el asistente para completar la instalación.

<p align="center">
  <a href="https://example.com/">
    <img src="img/image5.png" alt="bloques">
  </a>
  </p>

<p align="center">
  <a href="https://example.com/">
    <img src="img/image6.png" alt="bloques">
  </a>
  </p>



##### a. Instalar Wordfence

<p align="center">
  <a href="https://example.com/">
    <img src="img/image7.png" alt="bloques">
  </a>
  </p>

<p align="center">
  <a href="https://example.com/">
    <img src="img/image8.png" alt="bloques">
  </a>
  </p>

- Inicia sesión en el panel de WordPress.
- Ve a `Plugins > Añadir nuevo`.
- Busca `Wordfence`.

<p align="center">
  <a href="https://example.com/">
    <img src="img/image9.png" alt="bloques">
  </a>
  </p>


- Haz clic en `Instalar ahora` y luego en `Activar`.

<p align="center">
  <a href="https://example.com/">
    <img src="img/image10.png" alt="bloques">
  </a>
  </p>

<p align="center">
  <a href="https://example.com/">
    <img src="img/image11.png" alt="bloques">
  </a>
  </p>




##### b. Revisar configuración predeterminada


  - Ve a `Wordfence > All Options`.
- Revisa las configuraciones importantes:
  - **Brute Force Protection:** Habilita bloqueo de intentos de inicio de sesión fallidos.
  - **Firewall:** Configura el firewall de Wordfence para que esté en `Extended Protection`.
  - **Live Traffic:** Decide si quieres monitorear el tráfico en vivo.
  - **Alerts:** Asegúrate de que las notificaciones importantes estén habilitadas para recibir alertas por correo.


Estos ajustes predeterminados ofrecen una buena protección básica, pero puedes personalizarlos según tus necesidades.




### Instalar uno o más de los siguientes plugins
- WooCommerce
- Yoast SEO
- Contact Form 7
- W3 Total Cache
- PublishPress Capabilities
- Smash Balloon Social Post Feed

<p align="center">
  <a href="https://example.com/">
    <img src="img/image12.png" alt="bloques">
  </a>
  </p>

<!-- DESDE ACA FALTA -->

### Exponer la instalación a internet y compartir la URL
- Abrir el puerto necesario.
- Instalar un cliente de DNS dinámico.
- Asignar una IP LAN fija a la máquina.
- Generar un dominio.

### Realizar un análisis de seguridad inicial de la instalación


