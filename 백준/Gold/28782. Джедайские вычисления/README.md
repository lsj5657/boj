# [Gold IV] Джедайские вычисления - 28782 

[문제 링크](https://www.acmicpc.net/problem/28782) 

### 성능 요약

메모리: 3056 KB, 시간: 12 ms

### 분류

다이나믹 프로그래밍, 문자열, 브루트포스 알고리즘, 누적 합, 파싱

### 제출 일자

2025년 10월 12일 14:12:03

### 문제 설명

<p>Мало кто знает, но на самом деле обучение джедая слабо отличается от обучения в обычной школе. Например, у джедаев тоже есть математика, на которой нужно решать привычные всем арифметические упражнения. </p>

<p>Сегодня класс молодых джедаев получил задание посчитать значение выражения, состоящего из неотрицательных целых чисел и знаков <<<code>+</code>>> и <<<code>-</code>>>. Однако, просто вычислять значение выражения было бы скучно. Поэтому, магистр Йода сказал своим ученикам использовать Силу и удалить из выражения ровно один символ, чтобы значение получившегося выражения было максимальным возможным. В получившемся выражении разрешены числа с ведущими нулями. Гарантируется, что после удаления любого символа, выражение останется корректным.</p>

<p>Поскольку не все джедаи такие же умные, как современные программисты, вас просят помочь им определить максимальное возможное значение выражения, которое может получиться, если из выражения удалить ровно один символ.</p>

### 입력 

 <p>В единственной строке дана строка <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D460 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>s</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$s$</span></mjx-container>, состоящая из цифр и символов <<<code>+</code>>> и <<<code>-</code>>> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-texatom space="4" texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c7C"></mjx-c></mjx-mo></mjx-texatom><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D460 TEX-I"></mjx-c></mjx-mi><mjx-texatom texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c7C"></mjx-c></mjx-mo></mjx-texatom><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>≤</mo><mrow data-mjx-texclass="ORD"><mo stretchy="false">|</mo></mrow><mi>s</mi><mrow data-mjx-texclass="ORD"><mo stretchy="false">|</mo></mrow><mo>≤</mo><mn>100</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2 \le |s| \le 100\,000$</span></mjx-container>). Эта строка является корректным арифметическим выражением, не содержащим унарных знаков <<<code>+</code>>> и <<<code>-</code>>>. Иными словами, символы <<<code>+</code>>> и <<<code>-</code>>> всегда разделяют два числа. Все числа в выражении имеют длину от <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2$</span></mjx-container> до <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>9</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$9$</span></mjx-container> включительно и не содержат ведущих нулей.</p>

### 출력 

 <p>Выведите единственное число --- максимальное значение выражения, которое может получиться, если в исходном выражении удалить ровно один символ.</p>

