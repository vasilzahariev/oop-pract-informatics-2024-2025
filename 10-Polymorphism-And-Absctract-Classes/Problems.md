# Задачи към [Полиморфизъм и абстрактни класове](./)

### Задача 1 :chair::bed:

Да се състави складова програма за мебелна къща. Мебелите, които произвежда, са маса, стол и легло. Мебелите имат следните характеристики:

 - маса - идентификатор, височина, широчина, дължина, количество, тип (холова, кухненска)
 - стол - идентификатор, височина, широчина, дължина, количество, тип (дървен, метален, пластмасов)
 - легло - идентификатор, височина, широчина, дължина, количество

 Идентификаторът трябва да бъде цяло число и да бъде уникален.

 Всяка мебел си има и определена цена, която се изчислява по следния начин:
 - маса - `широчина * дължина * 15`
 - стол - `височина * широчина * 9`
 - легло - `дължина * височина * 22` 

 Всяка мебел да има метод, даващ пълна информация за нейните характеристики.
 
 Нека програмата има опции за:
 - добавяне на нова мебел
 - премахване по идентификатор (намаляване на количеството, а ако стане = 0, премахване на артикула)
 - показване на характеристики на дадена мебел по идентификатор
 - показване на характеристики на най-скъпата мебел

Помислете за подходяща йерархия на вашето решение, като например ще имате ли базов клас, кои ще са неслидниците, кои методи ще имат различна имплементация, какви трябва да са деструкторите и т.н.

### Задача 2 :couch_and_lamp::house:
Даден е следният интерфейс:
```c++
template <class T, class ID>
class CrudRepository
{
public:
    virtual void create(const T& object) = 0;
    virtual const T& read(ID id) const = 0;
    virtual void update(ID id, const T& newObject) = 0;
    virtual void d_remove(ID id) = 0;
};
```

Реализирайте класове `FurnitureHouseInMemory` и `FurnitureHouseInFile`, имплементиращи интерфейса `CrudRepository<Furniture*, unsigned int>` по подходящ начин, пазейки информация за мебелите от задача 1. Първият клас трябва да пази информацията за мебелите в динамичната памет, а вторият трябва да поддържа базата данни в текстов файл.

### Задача 3 :mirror:
Реализирайте полиморфично клониране за класовете, които съдържат масиви от пойнтъри, сочещи към различен тип обекти, (хетерогенни контейнери) - `Menu` (предишния практикум) и `FurnitureHouseInMemory` (задача 2)
