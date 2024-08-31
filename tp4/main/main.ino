#include <MD5Builder.h>
#include <mbedtls/aes.h>
#include <mbedtls/sha256.h>
#include <string.h>

unsigned char message[16] = "Hello, ESP32!";        // Data to encrypt
unsigned char aesKey[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};  // AES key
unsigned char aesIV[16] = {0x00};                   // Initialization vector

void encryptMD5(const unsigned char *data, size_t length);
void encryptAES(const unsigned char *data);
void encryptSHA256(const unsigned char *data, size_t length);

void setup() 
{
    Serial.begin(115200);
    Serial.print("\033[2J\033[H");  // Clear the Serial Monitor using an escape sequence
}

void loop() 
{    
    // Print the message
    Serial.print("Message: ");
    Serial.println((char*)message);

    // Print the MD5 hash of the message
    encryptMD5(message, sizeof(message));

    // Print the SHA256 hash of the message
    encryptSHA256(message, sizeof(message));

    // Perform AES encryption and print the result
    encryptAES(message);

    // Wait before the next iteration
    delay(5000);
    Serial.println();
}

void encryptMD5(const unsigned char *data, size_t length) 
{
    MD5Builder md5;
    md5.begin();
    md5.add(data, length);
    md5.calculate();
    Serial.print("MD5 hash: ");
    Serial.println(md5.toString());
}

void encryptAES(const unsigned char *data)
{
    unsigned char encryptedData[16]; // AES block size
    mbedtls_aes_context aes;

    mbedtls_aes_init(&aes);
    mbedtls_aes_setkey_enc(&aes, aesKey, 128);
    mbedtls_aes_crypt_ecb(&aes, MBEDTLS_AES_ENCRYPT, data, encryptedData);
    mbedtls_aes_free(&aes);

    Serial.print("AES Encrypted Data: ");
    for (int i = 0; i < 16; i++) 
    {
        if (encryptedData[i] < 0x10) 
            Serial.print('0'); // Print leading zero for single-digit hex values
        Serial.print(encryptedData[i], HEX);
    }
    Serial.println();
}


void encryptSHA256(const unsigned char *data, size_t length)
{
    unsigned char output[32]; // SHA-256 produces a 256-bit (32-byte) hash
    mbedtls_sha256_context sha256;
    
    mbedtls_sha256_init(&sha256);
    mbedtls_sha256_starts(&sha256, 0); // 0 for SHA-256
    mbedtls_sha256_update(&sha256, data, length);
    mbedtls_sha256_finish(&sha256, output);
    mbedtls_sha256_free(&sha256);
    
    Serial.print("SHA-256 hash: ");
    for (int i = 0; i < 32; i++) 
    {
        if (output[i] < 0x10) 
            Serial.print('0'); // Print leading zero for single-digit hex values
        Serial.print(output[i], HEX);
    }
    Serial.println();
}
