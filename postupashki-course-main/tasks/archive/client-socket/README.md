# Клиент.

Реализуйте класс Client со следующими методами: 

1) Конструктор принимает ip адрес и номер порта, подключается по этим данным, при неудаче кидайте исключение runtime_error
2) Метод Send который отправляет message на указанный адрес, в зависимости от результата отправки нужно вернуть соответствующий тип данных.

Все открытые дескрипторы должны быть закрыты.

# Доп. литература

1) https://en.cppreference.com/w/cpp/utility/variant
2) Изучите системные вызовы write/read/close, send/recv, socket, connection.