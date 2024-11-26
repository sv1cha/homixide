/** @file
* @author Сверчков А.Д.
* @version 1.0
* @date 25.11.2024
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

/**
 * @brief Класс для реализации шифра на основе модифицированного алфавита.
 */
class modAlphaCipher {
    private:
        /**
         * @brief Строка, представляющая алфавит.
         */
        wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        
        /**
         * @brief Сопоставление символов алфавита с их порядковыми номерами.
         */
        map <char,int> alphaNum;
        
        /**
         * @brief Вектор, представляющий ключ.
         */
        vector <int> key;
        
        /**
         * @brief Преобразует строку в вектор целых чисел.
         * @param s Входная строка.
         * @return Вектор целых чисел.
         */
        vector<int> convert(const string& s);
        
        /**
         * @brief Преобразует вектор целых чисел в строку.
         * @param v Вектор целых чисел.
         * @return Строка.
         */
        string convert(const vector<int>& v);
        
        /**
         * @brief Проверяет и получает корректный ключ.
         * @param s Ключ в виде строки.
         * @return Корректная строка ключа.
         * @throw cipher_error Если ключ некорректен.
         */
        string getValidKey(const string & s);
        
        /**
         * @brief Проверяет и получает корректный открытый текст.
         * @param s Открытый текст.
         * @return Корректный открытый текст.
         * @throw cipher_error Если текст некорректен.
         */
        string getValidOpenText(const string & s);
        
        /**
         * @brief Проверяет и получает корректный зашифрованный текст.
         * @param s Зашифрованный текст.
         * @return Корректный зашифрованный текст.
         * @throw cipher_error Если текст некорректен.
         */
        string getValidCipherText(const string & s);
    
    public:
        /**
         * @brief Конструктор по умолчанию удален.
         */
        modAlphaCipher()=delete;
        
        /**
         * @brief Конструктор с параметром ключа.
         * @param skey Ключ в виде строки.
         */
        modAlphaCipher(const string& skey);
        
        /**
         * @brief Метод для шифрования текста.
         * @param open_text Открытый текст для шифрования.
         * @return Зашифрованный текст.
         * @throw cipher_error Если текст некорректен.
         */
        string encrypt(const string& open_text);
        
        /**
         * @brief Метод для расшифрования текста.
         * @param cipher_text Зашифрованный текст для расшифрования.
         * @return Расшифрованный текст.
         * @throw cipher_error Если текст некорректен.
         */
        string decrypt(const string& cipher_text);
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
