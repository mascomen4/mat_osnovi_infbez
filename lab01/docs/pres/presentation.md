---
## Front matter
lang: ru-RU
title: Лабораторная работа №1
author: |
	Подмогильный Иван Александрович - студент группы НПМмд-02-22
date: 16.09.2022

## Formatting
toc: false
slide_level: 2
theme: metropolis
header-includes:
 - \metroset{progressbar=frametitle,sectionpage=progressbar,numbering=fraction}
 - '\makeatletter'
 - '\beamer@ignorenonframefalse'
 - '\makeatother'
aspectratio: 43
section-titles: true
---

# Шифры простой замены

## Прагматика выполнения

Умение пользоваться шифрами Цезаря и Атбаша

## Цель выполнения лабораторной работы

Освоить на практике использование шифров Цезаря и Атбаша

## Задачи выполнения работы

Написать функции, которые реализуют шифрование шифрами Цезаря и Атбаша

## Результаты выполнения лабораторной работы. Часть 1

![Caesar cipher](image/caesar_cipher.png){ #fig:001 width=70% }

## Написал код для дешивровки кодов шифром Цезаря

![Caesar decipher](image/caesar_decipher.png){ #fig:002 width=70% }

## Написал код для зашивровки кодов шифром Атбаша

![Atbash cipher](image/atbash_cipher.png){ #fig:003 width=70% }

## Написал код для дешивровки кодов шифром Атбаша

![Atbash decipher](image/atbash_decipher.png){ #fig:004 width=70% }

## Написал заголовочный файл для класса реализации CipherHelper

![Header file](image/header.png){ #fig:005 width=70% }

## Написал CMakeLists.txt файл, который создаёт библиотеку из класса CipherHelper и бинарник main

![CmakeLists.txt file](image/cmakefile.png){ #fig:006 width=70% }

## Написал main.cpp файл, в котором есть тесты реализованных функций. Часть шифра Цезаря:

![main.cpp](image/main_caesar.png){ #fig:007 width=70% }

## Часть шифра Атбаша:

![main.cpp](image/main_atbash.png){ #fig:008 width=70% }

## Особенности реализации
- Реализовано на C++, поэтому код быстрый
- Функции статические, поэтому экономятся ресурсы. Особенно это актуально если нам нужно шифровать примерно 1000 сообщений в секунду. Для этих 1000 сообщений не будут создаваться 1000 экземпляров классов
- Все собрано в проект CMake, поэтому код кросс-платформенный

## Выводы

Освоил на практике применение шифрования шифрами Цезаря и Атбаш.
