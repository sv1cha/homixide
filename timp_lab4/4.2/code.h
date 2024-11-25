/** @file
* @author Сверчков А.Д.
* @version 2.0
* @date 25.11.2024
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <stdexcept>
using namespace std;

/**
 * @brief Класс для шифрования и расшифрования текста с использованием числового ключа.
 */
class code {
    private:
        /**
         * @brief Ключ шифрования.
         */
        int key;
        
        /**
         * @brief Возвращает корректный ключ шифрования.
         * @param key Входной ключ.
         * @param Text Предоставленный текст.
         * @return Корректный ключ.
         * @throw cipher_error Если ключ некорректен.
         */
        inline int getValidKey(int key, const string & Text);
        
        /**
         * @brief Проверяет и возвращает корректный открытый текст.
         * @param s Открытый текст.
         * @return Корректный текст.
         * @throw cipher_error Если текст некорректен.
         */
        inline string getValidOpenText(string & s);
        
        /**
         * @brief Проверяет и возвращает корректный зашифрованный текст.
         * @param s Зашифрованный текст.
         * @param open_text Открытый текст.
         * @return Корректный зашифрованный текст.
         * @throw cipher_error Если текст некорректен.
         */
        inline string getValidCipherText(string & s, string & open_text);
    
    public:
        /**
         * @brief Конструктор по умолчанию удален.
         */
        code() = delete;
        
        /**
         * @brief Конструктор с параметрами ключа и текста.
         * @param skey Числовой ключ.
         * @param text Текст для шифрования.
         */
        code(int skey, string text);
        
        /**
         * @brief Метод для шифрования текста.
         * @param text Текст для шифрования.
         * @return Зашифрованный текст.
         * @throw cipher_error Если текст некорректен.
         */
        string encryption(string &text);
        
        /**
         * @brief Метод для расшифрования текста.
         * @param text Зашифрованный текст.
         * @param open_text Открытый текст.
         * @return Расшифрованный текст.
         * @throw cipher_error Если текст некорректен.
         */
        string transcript(string &text, string &open_text);
};

/**
 * @brief Класс исключений для обработки ошибок, связанных с шифрованием.
 */
class cipher_error: public invalid_argument {
    public:
        /**
         * @brief Конструктор, принимающий строку в качестве аргумента.
         * @param what_arg Описание ошибки.
         */
        explicit cipher_error (const string& what_arg):
        invalid_argument(what_arg) {}
        
        /**
         * @brief Конструктор, принимающий C-строку в качестве аргумента.
         * @param what_arg Описание ошибки.
         */
        explicit cipher_error (const char* what_arg):
        invalid_argument(what_arg) {}
};
