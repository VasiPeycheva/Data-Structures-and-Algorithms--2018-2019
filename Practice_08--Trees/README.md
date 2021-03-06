# Упражнение 8
## Heap, Binary Search Tree, Self-balancing Tree

##### Приоритетна опашка
* какво преставлява и кога се ползва

##### Дърво
* Обща дефиниция - краен свързан ацикличен граф, а.k.а. свързан граф без цикли
* корен
* върхове
* листа
* степен - брой преки наследници (разклоненост на дървото)

##### Двоично дърво за претърсване - [BST](https://en.wikipedia.org/wiki/Binary_search_tree)
* обща концепция - комбинира преимуществата на динамичната реализация с ефективността на търсене при статичната.
* полета
	* ключ
	* данни
	* указатели към децата 
* основни операции и тяхната сложност (в най-добрия случай)
	* търсене на елемент:    O(logn)
	* добавяне на елемент:   O(logn)
	* премахване на елемент: O(logn)

* "изродено дърво" - обичайно имплементираното двойчно дърво често може да се "изроди" в свързан списък,
 	             като не е нужно цялото дърво да е "изродено", може само някое негово под-дърво 
	* при него всички операции са със сложност O(n) (в най-честия и най-лошия случай)

* видове обхождане
	* Ляво-Корен-Дясно
	* Корен-Ляво-Дясно
	* и всяка друга пермутация на буквите 'Л', 'К', 'Д'

##### Дървета с произволен брой деца
* префиксно дърво/синтактично дърво/[trie tree](https://en.wikipedia.org/wiki/Trie)

##### Балансирани дървета
* **балансирани дървета** - разликата във ВИСОЧИНИТЕ на лявото и дясното поддърво на всеки връх е най-много единица
* **идеално балансирани дървета** - разликата в БРОЯ НА ВЪРХОВЕТЕ на лявото и дясното поддърво на всеки връх е най-много единица

##### Самобалансиращи се дървета
* двоични
	* [Червено-черно дърво](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)
	* [AVL](https://en.wikipedia.org/wiki/AVL_tree)
	* [Splay](https://en.wikipedia.org/wiki/Splay_tree)
* с произволна разклоненост
	* [B-дърво](https://en.wikipedia.org/wiki/B-tree) 

##### Приложения
* когато най-често използваната операция е търсене
* когато има наредба между елементите

#### Задачи

1. Напишете програма, която ще получи като вход име на текстов файл, който съдържа много цели числа, разделени с празни символи (нов ред или интервал). Вие трябва да добавите тези числа в двоично наредено дърво. Изкарайте елементите в нарастващ и намаляващ ред.

2. Напишете програма, която ще получи като вход име на текстов файл, който съдържа много цели числа, разделени с празни символи (нов ред или интервал). Вие трябва да добавите тези числа в двоично наредено дърво, което не допуска повторения (т.е. при опит за добавяне на елемент, който вече съществува, дървото не се променя). След това трябва да предоставите информация при подадено число N колко поддървета в така полученото дърво съдържат точно N елемента. При приключване на програмата трябва да запишете елементите от дървото в същия файл, в такъв ред, че при повторно стартиране на програмата да получите същото дърво.

3. Task: construct two trees from input as described below,
         then check if they are [isomorphic](https://www.geeksforgeeks.org/tree-isomorphism-problem/) or not
	 
input fortmat:

tree: (root{child-list}), where</br>
child-list: {} or trees

positive examples (isomorphic ones):

- (5{(9{})(1{(4{})(12{})(42{})})})

  (7{(15{(7{})(10{})(8{})})(3{})})
-----------------------------------
- (1{(2{(3{})})(4{})})

  (1{(4{})(2{(3{})})})
-----------------------------------
- (1{(2{(5{})(6{})(7{})})(3{(8{})})(4{(9{})(10{})})})

  (1{(2{(8{})})(3{(9{})(10{})})(4{(5{})(6{})(7{})})})
-----------------------------------
- (1{(2{(4{(7{})(8{})})(5{(9{})})(6{(10{})(11{})(12{})})})(3{(13{})(14{(15{})})})})

  (1{(2{(14{(15{})})(13{})})(3{(5{(9{})})(6{(10{})(11{})(12{})})(4{(7{})(8{})})})})
-----------------------------------

Negative examples (non - isomorphic, but close to isomorphic):

-----------------------------------
- (5{(9{})(1{(4{})(12{})(42{})})})

  (7{(15{(7{})(10{})})(3{(8{})})})
-----------------------------------
- (1{(2{(3{})})(4{})})

  (1{(2{(3{})})(4{(3{})})})
-----------------------------------
- (1{(2{(5{})(6{})(7{})})(3{(8{})})(4{(9{})(10{})})})

  (1{(2{(8{})(5{})})(3{(9{})(10{})})(4{(6{})(7{})})})
-----------------------------------
- (1{(2{(4{(7{})(8{})})(5{(9{})})(6{(10{})(11{})(12{})})})(3{(13{})(14{(15{})})})})

  (1{(2{(14{(15{})})(13{})})(3{(5{(9{})(11{})})(6{(10{})(12{})})(4{(7{})(8{})})})})

4. Условието можете да намерите [тук](https://github.com/VasiPeycheva/Data-Structures-and-Algorithms--2018-2019/blob/master/Practice_08--Trees/solutions/task4_solution/task.pdf).
