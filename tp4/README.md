# Criptografia y Seguridad en Redes

## Trabajo Practico 4 - Sistemas embebidos

### Integrantes:
- Gil Cernich, Manuel
- Mayorga, Federica

---

## Objetivo

En esta práctica de laboratorio veremos el funcionamiento y como es la seguridad en sistemas embebidos.

---

## Sistemas embebidos

Los sistemas embebidos son sistemas computacionales diseñados para realizar tareas específicas dentro de un dispositivo más grande. A diferencia de las computadoras de propósito general, estos sistemas están integrados en dispositivos y se centran en funciones concretas, como el control de electrodomésticos, sistemas de navegación, o dispositivos médicos. Por ejemplo, un cajero automático utiliza un sistema embebido para gestionar transacciones bancarias, sin la capacidad de realizar tareas como navegar por Internet

La característica principal de los sistemas embebidos es que están diseñados para realizar tareas específicas, y no para ser versátiles. Por lo tanto, estos sistemas suelen tener un hardware y software especializado que les permite realizar sus funciones de manera eficiente energeticamente, a un bajo costo y con la confiabilidad de que se pueden operar durante largos periodos de tiempo.

### Seguridad en sistemas embebidos

Un aspecto crítico en los sistemas embebidos es la seguridad. Dado que estos sistemas a menudo se utilizan en dispositivos que manejan información sensible o controlan procesos críticos, es fundamental protegerlos contra amenazas de seguridad. Algunas de las amenazas comunes a los sistemas embebidos incluyen:

#### **Ataques a cajeros automáticos**

Los cajeros automáticos utilizan sistemas embebidos para gestionar transacciones bancarias. Los atacantes pueden intentar robar información de tarjetas de crédito o manipular el software del cajero automático para obtener efectivo de forma fraudulenta.

En 2023 se reporto el caso del **malware FiXS**, este malware fue diseñado específicamente para atacar cajeros automáticos, permitiendo a los ciberdelincuentes extraer efectivo de manera ilícita. El malware se introdujo en los cajeros automáticos mediante el acceso físico, utilizando teclados externos y memorias USB. Una vez instalado, el malware se configuró para ejecutarse automáticamente al iniciar el cajero.

Para prevenir este tipo de ataques, es esencial implementar medidas de seguridad física, como cámaras de vigilancia y alarmas, para detectar y disuadir a los atacantes. Además, se deben aplicar actualizaciones de seguridad regulares y utilizar soluciones de seguridad de red para proteger los sistemas embebidos contra malware y ataques remotos.

#### **Vulnerabilidades en dispositivos IoT**

Los dispositivos IoT (Internet de las cosas) utilizan sistemas embebidos para conectarse a Internet y recopilar datos. Los atacantes pueden explotar vulnerabilidades en estos dispositivos para acceder a información confidencial o controlarlos de forma remota.

La **botnet Mirai**, que se hizo famosa en 2016, utilizó dispositivos IoT vulnerables, como cámaras de seguridad y routers, para llevar a cabo ataques de denegación de servicio distribuido (DDoS) masivos.

Para prevenir este tipo de incidentes, es fundamental que los fabricantes de dispositivos IoT implementen protocolos de seguridad robustos desde el diseño, incluyendo cifrado de comunicaciones y actualizaciones de firmware automáticas. Los usuarios también deben ser educados sobre la importancia de cambiar las contraseñas predeterminadas y mantener sus dispositivos actualizados.

#### **Ataques a sistemas de control industrial**

Los sistemas embebidos se utilizan en sistemas de control industrial para gestionar procesos críticos, como la producción de energía o la fabricación de productos. Los atacantes pueden intentar manipular estos sistemas para causar daños físicos o interrumpir la producción.

Un ejemplo concreto de vulnerabilidad en sistemas embebidos en sistemas de control industrial es el ataque de Stuxnet, que se descubrió en 2010. Este malware fue diseñado específicamente para atacar los sistemas de control industrial, particularmente aquellos utilizados en la planta de enriquecimiento de uranio de Natanz en Irán.

**Stuxnet** tenía como objetivo los controladores lógicos programables (PLC) de Siemens que controlaban las centrifugadoras en la planta. Su diseño permitió alterar el funcionamiento de las centrifugadoras, haciéndolas girar a velocidades inusuales, lo que provocó daños físicos en el equipo.

Para prevenir este tipo de ataques se deberia tener un buen monitoreo y deteccioón de intrusiones, ademas de implementar medidas de concientización y capacitación para el personal que opera los sistemas de control industrial.

---

## Ejemplos de criptografía en ESP32

A continuacion se presentan ejemplos de criptografía en una ESP32, para este caso veremos dos ejemplos de hasheos (MD5 y SHA-256) y un ejemplo de cifrado simétrico (AES).

Para todos los ejemplos se utilizara la libreria `mbedtls` que es una implementación de código abierto de las tecnologías criptográficas más comunes, como MD5, SHA-256 y AES.

```bash
Message: Hello, ESP32!
MD5 hash: 62ab049c0b54e388af7149dbe99b7485
SHA-256 hash: 5CE182FCD599491918C9F4C4DB437F3A75F6955F3170DA3AA36208B7BE326623
AES Encrypted Data: 57B6D9C40FC863AABCEC6E74B0A4E6E4
```

### Hash vs Cifrado

Los algoritmos de hash y cifrado son dos técnicas criptográficas fundamentales que se utilizan para proteger la integridad y confidencialidad de los datos. Aunque ambos procesos utilizan funciones matemáticas para transformar los datos, tienen propósitos y características diferentes.

En el caso de los **hashes**, se utilizan para generar una representación única y fija de un conjunto de datos, conocida como hash. Los hashes son útiles para verificar la integridad de los datos, ya que cualquier cambio en los datos originales producirá un hash diferente. Sin embargo, los hashes no son reversibles, lo que significa que no se pueden descifrar para recuperar los datos originales.

Por otro lado, los algoritmos de **cifrado** se utilizan para proteger la confidencialidad de los datos mediante la transformación de los datos originales en una forma cifrada, que solo puede ser descifrada con una clave secreta. A diferencia de los hashes, los algoritmos de cifrado son reversibles, lo que significa que los datos cifrados se pueden descifrar para recuperar los datos originales.


### MD5 y SHA-256

El algoritmo MD5 (Message Digest Algorithm 5) es un algoritmo de hash ampliamente utilizado que produce un hash de 128 bits. Aunque MD5 se considera obsoleto y no se recomienda para aplicaciones de seguridad críticas, sigue siendo útil para la verificación de integridad de datos y la generación de claves de hash rápidas.

Por otro lado, el algoritmo SHA-256 (Secure Hash Algorithm 256) es un algoritmo de hash más seguro que produce un hash de 256 bits. SHA-256 se utiliza comúnmente en aplicaciones de seguridad críticas, como la generación de firmas digitales y la verificación de integridad de datos.

### AES

El algoritmo AES (Advanced Encryption Standard) es un algoritmo de cifrado simétrico ampliamente utilizado que se utiliza para proteger la confidencialidad de los datos. Cuando se dice que un algoritmo es simétrico, significa que la misma clave se utiliza tanto para cifrar como para descifrar los datos, a diferencia de los algoritmos asimétricos que utilizan claves diferentes para cifrar y descifrar, como por ejemplo RSA.

---

## Anexo

- [Ataque a cajeros automáticos con malware FiXS](https://www.aurigaspa.com/es/noticias-y-medios-de-comunicacion/notas-de-prensa/el-malware-fixs-ataca-a-cajeros-automaticos-en-latinoamerica/)
- [Ataque en sistemas IoT botnet Mirai](https://www.cloudflare.com/learning/ddos/glossary/mirai-botnet/)
- [Ataque a sistemas de control industrial con Stuxnet](https://nordvpn.com/blog/stuxnet-virus/)
- [Libreria mbedtls](https://github.com/Mbed-TLS/mbedtls)
