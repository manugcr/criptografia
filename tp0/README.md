# Criptografia y Seguridad en Redes

## Trabajo Practico 0A - Control de acceso en SSH
## Trabajo Practico 0B - Doble Factor de Autenticacion

### Integrantes:
- Gil Cernich, Manuel
- Mayorga, Federica

---
## Objetivo
En esta práctica de laboratorio se familiarizará con el protocolo ssh y el uso de claves públicas 
y privadas para el control de acceso. Opcionalmente podrán ampliar la práctica con libpam y con fail2ban.

## Control de acceso en SSH

### Generación de una nueva clave para SSH y adición al agente SSH
1. Abra Terminal.
   
2. Pega el texto siguiente, reemplazando el correo electrónico usado en el ejemplo por tu dirección de correo electrónico de GitHub.

```
ssh-keygen -t ed25519 -C "your_email@example.com"
```

Esto crea una llave SSH utilizando el correo electrónico proporcionado como
etiqueta.

3. Ten en cuenta que si ya creaste claves SSH anteriormente, ssh-keygen puede pedirte que vuelvas a escribir otra clave. En este caso, se recomienda crear una clave SSH con nombre personalizado. Para ello, escribe la ubicación de archivo predeterminada y reemplaza id_ssh_keyname por el nombre de clave personalizado.

4. Cuando se le pida, escriba una frase de contraseña segura.

5. Verifique que la clave se creó haciendo cat al archivo de la clave publica.
   
<p align="center">
    <img src="imgs/tp0_img1.JPG"><br>
    <em>Fig 1. Generacion de clave SSH</em>
</p>

¿Cuáles son los algoritmos que puede utilizar SSH? ¿RSA sigue vigente?
    - Los algoritmos criptográficos asimétricos más comunes en SSH son RSA (Rivest-Shamir-Adleman), DSA (Digital Signature Algorithm), ECDSA (Elliptic Curve Digital Signature Algorithm) y EdDSA (Edwards-curve Digital Signature Algorithm).
    - RSA sigue vigente, pero se recomienda considerar alternativas más modernas como ECDSA o EdDSA.

### Subir la clave pública ssh al servidor de entrada y al segundo servidor

No se puede avanzar mas (por el momento).
---

## Doble Factor de Autenticacion

### Paso 1: instalar PAM de Google
PAM es Pluggable Authentication Modules, es una infraestructura de
autenticación utilizada en sistemas Linux para autenticar a un usuario.

<p align="center">
    <img src="imgs/tp0B_img1.JPG"><br>
    <em>Fig 1. Generacion de clave SSH</em>
</p>

Con el PAM instalado, usaremos una aplicación auxiliar que viene con el PAM para generar una clave TOTP para el usuario que necesita un segundo factor.

<p align="center">
    <img src="imgs/tp0B_img2.JPG"><br>
    <em>Fig 1. Generacion de clave SSH</em>
</p>

Una vez finalizadas las preguntas de configuracion de google authenticator, hacemos el siguiente paso.

### Paso 2: Configurar OpenSSH para usar MFA/2FA
A partir de ahora, no puedo usar el cmd sudo.