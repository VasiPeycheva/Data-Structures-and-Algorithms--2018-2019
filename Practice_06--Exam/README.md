# Упражнение 6


## Задача 1

В тази задача трябва да реализирате основата на специален уеб браузър. Градивните единици на този браузър са "прозорец" и "раздел". За тях в сила са следните правила:

Броят на "прозорците" не надвишава 255.
По време на изпълнението на програмата има единствен текущ "прозорец".
При създаване на нов "прозорец", той скрива предишния и става текущ.
При затваряне на "прозорец", предходният става текущ ( ако има такъв).
Всеки "прозорец" е съставен от динамичен брой "раздели".
Няма ограничение за броя на разделите.
Всеки раздел има времево клеймо, което указва кога е бил създаден. За да вземете текущото време можете да извикате функцията time() дефинирана в хедъра "ctime" (**).
Всеки "раздел" изглежда по следния начин:
```
struct Tab {
   std::string url; // адрес на отворената в раздела страница
   time_t timestamp; // времево клеймо - кога е създаден разделът
   Tab* pNext; // указател към следващия раздел
}
```
** Ако сте забравили как се ползва <ctime>, можете да внедрите ваша собствена логика с времената. Например генерирайте поредни цели числа. За това точки НЯМА да ви бъдат отнети.

Когато програмата ви се стартира, тя трябва да инициализира браузър с един начален "прозорец", съдържащ единствен "раздел" с URL – "http://exam_dsa". След това тя трябва да може да изпълнява следните команди:

1. WINDOW OPEN – отваря нов "прозорец", който се добавя точно след текущия. В него се добавя единствен "раздел" с URL – "http://exam_dsa". Накрая този нов прозорец трябва да стане текущ. Времевата сложност на командата е О(1).

2. WINDOW CLOSE – затваря текущия прозорец, като изчиства и всички "раздели" отворени в него. Предходният му "прозорец" става текущ. Ако такъв няма, следващият го става текущ. Ако няма и следващ (това е бил последният прозорец), браузърът остава без прозорци и няма текущ прозорец. Сложността на операцията е О(N) или по-добра, където N е броят на "разделите" в текущия прозорец.

3. UPTIME – показва на екрана колко време е прекарано в текущия "прозорец". Това време се получава като разлика между текущото време и времевото клеймо на най-стария му раздел. Сложността на тази команда е О(1).

4. TAB <url> – проверява дали <url> се съдържа в някои от "разделите" на текущия "прозорец". Ако той се съдържа, всички "раздели", започвайки от последното му срещане, се премахват от "прозореца" и командата извежда текст "Trim". Ако <url> не се съдържа, да се добави след последния "таб" и програмата да извежда текст "Append". Накрая командата извежда на екрана всички "раздели" в текущия "прозорец", форматирани по ваша преценка. Сложността на операцията е О(N), където N е броят на "разделите" в текущия прозорец.

5. EXIT – приключва програмата. Преди изхода се извежда статистика за използването на браузъра: брой на всички "раздели", които са отворени в момента и цялото време прекарано в браузъра.

Пример за работата на програмата:

```
Browser started. 
> TAB www.example.com
Append
{  http://exam_dsa”, 1541416638 },  { “www.example.com”, 1541416945 } 

> UPTIME
1307 ( ако приемем, че UPTIME се извиква точно 1 секунда след добавянето на “www.example.com” )

> TAB “abv.bg”
Append
…
> TAB “dir.bg”
Append
…
> TAB “abv.bg”
Trim
{“http://exam_dsa”, 1541416638 },  { “www.example.com”, 1541416945 }, { “abv.bg”, 1541417112 }

> WINDOW -O
New window opened!

> TAB “abv.bg”
Append
{“http://exam_dsa”, 1541416638 },  { “abv.bg”, 1541423241 }

> WINDOW -O
New window opened!

> WINDOW -C
Current window closed!

> TAB “www.example.com”
Append
{“http://exam_dsa”, 1541416638 },  { “abv.bg”, 1541423241 }, { “www.example.com”, 1541427325 }

> EXIT
Total closed “tabs” : 6. Total time of usage : 6603 ( ако EXIT е изпълнен моментално след последния append )
```


## Задача 2
В тази задача трябва да реализирате специален калкулатор. Той трябва да поддържа няколко паралелни калкулации. С всяка от тях трябва да може да се изпълняват определени операции. Трябва да може да се показва и текущото състояние на всички калкулации.

Всяка калкулация съдържа редица от реални числа – нейните аргументи. Максималната дължина на такава редица е 255. Няма ограничение на броя калкулации, които потребителят може да създава.

Вашата програма трябва да може да изпълнява следните команди:

1. CREATE – добавя нова калкулация в края на списъка от текущите.

2. PUSH <NUMBER> <CINDEX> – добавя реалното число <NUMBER> в калкулацията със индекс <CINDEX> (цяло неотрицателно число).

3. POP <CINDEX> – премахва последния аргумент от калкулацията с индекс <CINDEX>. Ако тя остане без аргументи, трябва да се премахне от списъка с калкулации. В такъв случай индексите на тези след нея се променят като намаляват с единица.
4. ADD – за всяка калкулация премахва последните ѝ 2 аргумента, събира ги и записва резултата обратно, като нов аргумент за калкулацията. Ако дадена калкулация има по-малко от два аргумента, тя не се променя.

5. SUBTRACT -- работи аналогично на ADD, но изважда предпоследния от последния аргумент, вместо да ги събира.

6. NEGATIVE – обръща знака на последния аргумент на всяка калкулация.

7. MAX – Извежда на екрана най-големия аргумент на всяка от калкулациите. Ако дадена калкулация няма елементи, за нея да се изведе текст "none"

8. PRINT – принтира индекса и аргументите на всяка сметка на отделен ред.

9. EXIT – изход от програмата.

Операциите CREATE и PUSH трябва да работят със сложност O(1). POP трябва да работи със сложност O(1), освен когато се наложи да премахне калкулация. В такъв случай тя може да работи със сложност O(N), където N е броят на калкулациите в програмата. ADD, SUBTRACT, NEGATIVE, MAX и PRINT трябва да работят със сложност O(N).

Трябва сами да реализирате всички алгоритми и структури от данни, които използвате в програмата. НЕ Е разрешено да се използват стандартни имплементации, като например тези в STL.

Ако искате, можете да използвате класа std::string.

Пример за работата на програмата:

```
> CREATE
> PRINT
0:[]
> CREATE
> PRINT
0:[]
1:[]
> MAX
0: none
1: none
> PUSH 1 0
> PUSH 3 0
> PUSH 7 1
> PRINT
0:[1,3]
1:[7]
> MAX
0: 3
1: 7
> ADD
> NEGATIVE
> PRINT
0:[-4]
1:[-7]
> CREATE
> PUSH 10 1
> SUBSTRACT
> PRINT
0:[-4]
1:[17]
> POP 0
> PRINT
0:[17]
> EXIT
```



