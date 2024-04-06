# cpp-spreadsheet
Электронная таблица

## Описание
Программа реализована, используя динамический полиморфизм, интеграцию библиотеки ANTLR (java) для работы с абстрактно синтаксическим деревом, хэш-таблицу в качестве основной структуры данных для реализации интерфейса (Лист/sheet Excel). Данные хранятся в ячейках и защищены от циклических зависимостей. Абстрактное синтаксическое дерево применяется для решения формульных задач по аналогии MS Office Excel. В ячейках также можно размещать и текст.

*Реализованные исключения:*

- **#DIV0!** - деление на ноль
- **#VALUE!** - если операнд содержит текст, а не числовое значение.
- **#REF!** - если обращение идет к ячейке (ссылка) за пределами Листа (sheet)
- При обнаружении циклической ссылки будет выброшено исключение
  
*Пример:*
````
sheet->SetCell("A1"_pos, "1");
sheet->SetCell("A2"_pos, "=A1+1");
sheet->SetCell("A3"_pos, "=A1+A2");

auto* cell_A3_ptr = sheet->GetCell("A3"_pos);
ASSERT_EQUAL(std::get<double>(cell_A3_ptr->GetValue()), 3);
````

## Требования
C++17 и выше

[Java SE Runtime Environment 8](https://www.oracle.com/java/technologies/downloads/#java8)

[ANTLR](https://www.antlr.org/)

## Инструкция по сборке проекта
1. Установить [Java SE Runtime Environment 8.](https://www.oracle.com/java/technologies/javase-jre8-downloads.html)
2. Установить [ANTLR](https://www.antlr.org/) (ANother Tool for Language Recognition), выполнив все пункты в меню Quick Start
3. Проверить в файлах FindANTLR.cmake и CMakeLists.txt название файла antlr-X.X.X-complete.jar на корректность версии. Вместо "X.X.X" указать свою версию ANTLR
4. Создайть папку с названием "antlr4_runtime" без кавычек и скачайть в неё [файлы](https://github.com/antlr/antlr4/tree/master/runtime/Cpp)
5. Запустить cmake build с CMakeLists.txt
