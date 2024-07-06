Проверка на простое число
1.Пользователь выбирает опцию "prime" в ComboBox.
2. Обработка выбора: слот on_comboBox_activated() вызывается при изменении выбора в ComboBox. Этот слот очищает текстовое поле resultTextEdit и скрывает/показывает нужные lineedit’ы, в зависимости от задачи.
3. Нажатие кнопки "Start": пользователь вводит число в textBrowser и нажимает кнопку "Выполнить". Слот on_pushButton_clicked() вызывается, определяет текущий выбранный индекс задачи (0 для проверки простого числа), и вызывает метод isPrime().
4. Выполнение проверки - метод checkPrime(): считывает введенное число и проверяет его корректность: если число некорректно, выводит сообщение об ошибке в resultTextEdit, а если число корректно, вызывает метод checkPrimary() из класса Functions. Если число простое, checkPrimary() выводит соответствующее сообщение. Если число составное, выводит его разложение на простые множители в resultTextEdit.
Вычисление синуса
1. Пользователь выбирает опцию "Taylor series for sinus" в ComboBox.
2. Обработка выбора: слот on_comboBox_activated() очищает текстовое поле textBrowser и делает видимыми нужные поля.
3. Нажатие кнопки "Start": пользователь вводит значение угла в радианах в lineedit и точность в lineedit_1, затем нажимает кнопку "Выполнить". Слот onExecuteButtonClicked() определяет текущий выбранный индекс задачи (1 для вычисления синуса), и вызывает метод calculateSin().
4. Выполнение вычисления - метод series() и происходит вычисление. После результаты выводятся в textBrowser
Решение квадратного уравнения
Работает аналогично первым двум. Для вычисления используется метод solve, результаты выводятся в textBrowser.