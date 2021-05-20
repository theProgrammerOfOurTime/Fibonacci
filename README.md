Программа для вычисления числа Фибоначчи под любым индексом.
Для вычисления числа Фибоначчи применяется функция, основанная на принципах восходящей динамики, так как в данном случае не подходит использование нисходящей динамики, ведь это вносит определенные ограничения, при которых не должен переполниться стек вызовов и появляться ошибка Stack overflow. При начале роботы программе требуется узнать максимальный индекс, который мы планируем использовать, дальше можно вводить индексы чисел. Все вычисления сохраняются, это означает, что введя первоначально индекс 1000, в последующим все числа индекс, которых меньше или равен 1000, можно получать за O(1). Также эти значения способны помочь при вычислении чисел, чей индекс более 1000. 
Разумеется, числа Фибоначчи очень быстро растут, и не один встроенный тип данных не может полностью подходить для их обработки. Для этого был описан тип uli (unsigned long int).

	uli
Данный класс предназначен для хранения и обработки больших беззнаковых целых чисел. Основная операция необходимая для вычисления чисел Фибоначчи – это операция сложения, поэтому рассмотрим её. Операция сложения реализована с помощью перегрузки оператора сложения. Данная операция возвращает новый объект uli, который хранит результат сложения. Основная идея алгоритма:
1.	Найти минимально число (по количеству разрядов).
2.	Найти максимальное число (по тому же принципу).
3.	Итерируясь по разрядам меньшего числа, добавлять их к разрядам максимального (при необходимости перенося число в следующий разряд).
Данная операция требует O(N), где N – количество разрядов меньшего числа.