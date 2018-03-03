# sort_c_asm
Sorting an array implementing user exchange and comparison functions (asm)
Постановка задачи:
Реализовать два метода сортировки массива чисел(метод «пузырька» и рекурсивную реализацию быстрой сортировки), провести их 
экспериментальное сравнение. 
Тип элементов массива – целые числа(int), числа упорядочиваются по невозрастанию. 
Для каждого из реализуемых методов необходимо предусмотреть возможность работы с массивами длиной от 1 до N (N ≥ 1). 
Значение N в зависимости от варианта задания либо фиксировано, либо память под массив следует выделять динамически.
При реализации каждого метода вычислить число сравнений элементов, число обменов элементов и 
провести замер времени работы метода в процессорных тактах. 
Сравнение методов сортировки необходимо проводить на одних и тех же исходных массивах, 
при этом следует рассмотреть массивы разной длины. 
Для вариантов с динамическим выделением памяти рассмотреть n = 10, 100, 1000, 10000. 
Генерация исходных массивов для сортировки реализуется отдельной функцией, создающей, 
в зависимости от заданного параметра и заданной длины конкретный массив, в котором:
-элементы уже упорядочены (1);
-элементы упорядочены в обратном порядке (2);
-расстановка элементов случайна (3, 4).
Результаты экспериментов оформить на основе нескольких запусков программы в виде таблицы.