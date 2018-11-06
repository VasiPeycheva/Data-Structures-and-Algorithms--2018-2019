# Упражнение 5
## Stack, Queue, Deque

#### Стек

* Идея - First In Last Out (FILO same as LIFO - last in first out);
	* push
	* pop
	* peek
	* isEmpty
	
    
* Статична реализация
* Динамична реализация


* [more information](https://www.geeksforgeeks.org/stack-data-structure/)
* [What are the real life applications of stack data structure?](https://www.quora.com/What-are-the-real-life-applications-of-stack-data-structure)

##### Сложност на основните операции:
* добавяне на елемент : О(1)
* премахване на елемент : О(1)

##### Задача:

1. Напишете функция isCorrect, която по въведен символен низ от скоби, проверява дали е коректно зададен*.
	* *коректно зададен означава, че при добавяне на числа и аритметични знаци между скобите би могло да се получи валиден аритметичен израз.
```
Пример: Вход: "[()]"
	   Изход: true
       
       Пример: Вход: "([)]"
	   Изход: false
       
```

#### Опашка

* Идея - First In First Out (FIFO);
	* put/ enqueue
	* get/ dequeue
	* peek
	* isEmpty

* Циклична опашка
* [Приоритетна опашка](https://www.geeksforgeeks.org/priority-queue-set-1-introduction/)
* Дек (double ended queue)

##### Сложност на основните операции:
* добавяне на елемент : O(1)
* премахване на елемент : О(1)

* [more information](https://www.geeksforgeeks.org/queue-data-structure/)
* [What are the applications of queues?](https://www.quora.com/What-are-the-applications-of-queues)


##### Задача:
1. Имплементирайте опашка, използвайки само два стека. Ще ви се подаде брой на заявки q, последвано от q заявки, които може да са от следните 3 вида:
	* 1 - добавяне на елемент в края на опашката
	* 2 - премахване на елемент в началото на опашката
	* 3 - принтиране на елемента, който се намира в началото на опашката;

 
```
Пример:

Вход: 10 // q - брой заявки
      1 42 //добавяне на елемента 42 в края на опашката
      2		//премахване на елемента 42
      1 14  
      3    //принтира съществуващия в опашката елемент 14
      1 28
      3
      1 60
      1 78
      2
      2
      
Изход: 14
       14
```

#### Допълниетлни задачи :

1. Реализирайте базов [RPN](https://en.wikipedia.org/wiki/Reverse_Polish_notation) калкулатор.<br>
   Пример :<br>
   Вход : 15 7 1 1 + − ÷ 3 × 2 1 1 + + − // от израза ((15 ÷ (7 − (1 + 1))) × 3) − (2 + (1 + 1))<br>
   Изход   : 5<br>
   <br>
2. Имплементирайте [задачата за Ханойските кули](https://en.wikipedia.org/wiki/Tower_of_Hanoi)




