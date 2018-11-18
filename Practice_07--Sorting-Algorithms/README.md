# Упражнение 7
## Sorting Algorithms

* [animation of most sorting algorithms](https://visualgo.net/bn/sorting)


### Slow Sorting Algorithms O(n^2)

##### Selection Sort
* [read more](https://www.geeksforgeeks.org/selection-sort/)
##### Insertion Sort
* [read more](https://www.geeksforgeeks.org/insertion-sort/)
##### Bubble Sort
* [read more](https://www.geeksforgeeks.org/bubble-sort/)

### Fast Sorting Algorithms O(nlogn)

##### Merge Sort
* [read more](https://www.geeksforgeeks.org/merge-sort/)
##### Quick Sort
* [read more](https://www.geeksforgeeks.org/quick-sort/)
##### Heap Sort
* [read more](https://www.geeksforgeeks.org/heap-sort/)

### Special sorting algorithms O(n + k)

##### Counting Sort
* [read more](https://www.geeksforgeeks.org/counting-sort/)

#### Задача



Имате данни за изпити проведени във ФМИ, които са ви дадени като текстов файл,
във формат CSV. Всеки ред от файла съответства на един ред от таблицата. В него данните за
различните клетки се отделят помежду си със запетаи.

[Повече информация за формата CSV](https://frictionlessdata.io/docs/csv/)

Първият ред на CSV файла съответства на заглавния ред на таблицата. В него са
записани имената на колоните. Ще считаме, че таблицата има следните колони:
* name - имената на студента, явил се на изпита;
* age - възраст на студента;
* subject - дисциплина;
* grade - оценка от изпита по съответната дисциплина;
* date - дата на провеждане на изпита;

Следващите редове на файла съдържат данните на таблицата. На всеки ред има
точно толкова елементи, колкото са колоните на таблицата.
Програмата ви трябва, зареждайки тези данни, да може да ги представи сортирани, по
всяка една от колоните. Данните могат да се сортират във възходящ или низходящ
ред. Също така програмата ви трябва да може да използва няколко различни
алгоритъма за сортиране, спрямо колоните, по които сортирате.

На програмата ви ще се подават аргументи от командия ред (command-line arguments):
1. път до файла
2. колона, по която ще сортирате (name, age, subject, grade, date)
3. параметър за това в какъв ред ще са сортирани данните (asc, desc)
При решаването на задачата трябва сами да реализирате всички алгоритми и
структури от данни, които ще използвате – както сортировките, така и контейнера (или
контейнерите, ако са различни), в който ще пазите информация по време на работата
на програмата.

Примери за стартиране на програмата:

```
myprogram exams-data.csv name asc  #Сортира по имена във възходящ ред
myprogram exams-data.csv age desc  #Сортира по дата в низходящ ред
myprogram exams-data.csv grade asc #Сортира по оценка във възходящ ред
```
Пример за съдържанието на входен файл:
```
name, age, subject, grade, date
Pesho Petrov,22,DS,6,2017-03-01
Gosho Ivanov,20,LA,3,2016-09-15
Ivan Todorov,23,SDP,5,2007-10-30
Stamat Georgiev,29,LP,3,2020-02-29
Haralampi Kolev,23,KM,6,2017-12-30
Gosho Zdravkov,21,DAA,4,2016-09-15
```
Примери за изход при съответната команда:
```
>myprogram data.csv age asc
Gosho Ivanov,20,LA,3,2016-09-15
Gosho Zdravkov,21,DAA,4,2016-09-15
Pesho Petrov,22,DS,6,2017-03-01
Ivan Todorov,23,SDP,5,2007-10-30
Haralampi Kolev,23,KM,6,2017-12-30
Stamat Georgiev,29,LP,3,2020-02-29
````
```
> myprogram data.csv name desc
Stamat Georgiev,29,LP,3,2020-02-29
Pesho Petrov,22,DS,6,2017-03-01
Ivan Todorov,23,SDP,5,2007-10-30
Haralampi Kolev,23,KM,6,2017-12-30
Gosho Zdravkov,21,DAA,4,2016-09-15
Gosho Ivanov,20,LA,3,2016-09-15
```

