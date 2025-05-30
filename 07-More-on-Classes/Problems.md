# Задачи към [Oще за класове. Грешки](./)

## Управление на библиотека

## :green_book: Книга (Book)

Една книга ще съдържа следната информация:

| Член-данна | Стойност | Значение |
|---|---|---|
| title | динамичен низ | Заглавие на книгата |
| author | динамичен низ | Име на автора на книгата |
| id | цяло число | Уникален номер за всяка книга |
| isBorrowed | булева | Дали книгата е взета |
| remainingTime | цяло число | Оставащо време (намалява при изпълнение) |

Реализирайте нужните конструктори, деструктори, гетъри и сетъри. Освен тях един **Book** трябва да има реализиран следните методи:

- bool borrow() -> Заема книгата
- void returnBook() -> Връща книгата
- print -> принтира информация за книгата

По време на работата ви може да се наложи да реализирате допълнителни методи!

## :standing_man: Читател (Reader)

Един читател ще съдържа следната информация:

| Член-данна | Стойност | Значение |
|---|---|---|
| name | динамичен низ | Име на човека |
| borrowedBooks | масив от указатели към книги (**Book**) | Заети книги (максимум 5) |

Реализирайте нужните конструктори, деструктори, гетъри и сетъри. Освен тях един **Reader** трябва да има реализиран следните методи:

- void borrowBook(Book*) -> Добавя книга към заетите си книги. Да се хвърли грешка, ако книгата вече е заета (трябва да се обработи коректно извън класа).
- void returnBook(const char*) -> Премахва книга с определено заглавие от заетите си книги. Да се хвърли грешка, ако книгата не е от затетите (трябва да се обработи коректно извън класа).
- print -> принтира информация за читателя.

По време на работата ви може да се наложи да реализирате допълнителни методи!

## :classical_building: Библиотека (Library)

Една библиотека ще съдържа следната информация:

| Член-данна | Стойност | Значение |
|---|---|---|
| books | динамичен масив | Налични книги в библиотеката |
| readers | динамичен масив | Налични читатели |

Реализирайте нужните конструктори, деструктори, гетъри и сетъри. Освен тях един **Library** трябва да има реализиран следните методи:

- void addBook(const char*, const char*) -> Добавя книга в библитоеката. Не може да има 2 книги с еднакво заглавие.
- void registerReader(const char*) -> Регистрира читател.
- Book* findBook(const char*) -> Намира книга по заглавие.
- Book** findBooks(const char*) -> Намира книги по име на автор
- Reader* findReader(const char*) -> Намира читател по име на читател.

По време на работата ви може да се наложи да реализирате допълнителни методи!

## :teacher: Библиотекар (Librarian)

Един библиотекар ще трябва да може да извършва различни операции като:

- да заема книга на читател.
- да приема обратно книга от читател.
- да принтира информация за книга, книги и читатели.
- да проверява заетост на книга.
