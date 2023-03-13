## Part 1. Готовый докер

##### Возьмем официальный докер образ с **nginx** и выкачаем его при помощи команды `docker pull nginx`

<img src="../src/screenshots/1.1.png" alt="pull nginx"/>

##### Проверим наличие докер образа через команду `docker images`

<img src="../src/screenshots/1.2.png" alt="docker images"/>

##### Запустим докер образ с помощью команды `docker run -d nginx`

<img src="../src/screenshots/1.3.png" alt="docker run"/>

##### Проверим, что образ запустился через `docker ps`

<img src="../src/screenshots/1.4.png" alt="docker ps"/>

##### Посмотрим информацию о контейнере через `docker inspect [container_id]`

<img src="../src/screenshots/1.5.png" alt="docker inspect"/>

##### По выводу команды определим и поместим в отчёт размер контейнера, список замапленных портов и ip контейнера

Информация о контейнере:

* Размер: 1.09kB (virtual 142MB)
* Порты: 80
* IP: 172.17.0.2

##### Остановим докер образ через `docker stop [container_name]`

<img src="../src/screenshots/1.6.png" alt="docker stop"/>

##### Проверим, что образ остановился через `docker ps`

<img src="../src/screenshots/1.7.png" alt="docker ps"/>

##### Запустим докер с замапленными портами 80 и 443 на локальную машину через команду *run*

<img src="../src/screenshots/1.8.png" alt="docker run"/>

##### Проверим, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**

<img src="../src/screenshots/1.9.png" alt="localhost"/>

##### Также проверим доступ к странице с помощью команды `curl`

<img src="../src/screenshots/1.10.png" alt="curl localhost"/>

##### Перезапустим докер образ через `docker restart [repository]`

<img src="../src/screenshots/1.11.png" alt="restart"/>

##### Проверим, что контейнер запустился командой `docker ps` 

<img src="../src/screenshots/1.12.png" alt="docker ps"/>

## Part 2. Операции с контейнером

**== Задание ==**

##### Прочитать конфигурационный файл *nginx.conf* внутри докер образа через команду *exec*

Для начала запустим оболочку `bash` в контейнере с помощью команды `docker exec -it [container_name]`, затем через команду `cat` выведем содержимое конфигурационного файла *nginx.conf*

<img src="../src/screenshots/2.1.png" alt="nginx.conf"/>

##### Создадим на локальной машине файл *nginx.conf* и настроим в нем по пути */status* отдачу страницы статуса сервера **nginx**

<img src="../src/screenshots/2.2.png" alt="nginx.conf"/>

##### Скопируем созданный файл *nginx.conf* внутрь докер образа через команду `docker cp`

<img src="../src/screenshots/2.3.png" alt="docker cp"/>

##### Перезапустим **nginx** внутри докер образа через команду *exec*

<img src="../src/screenshots/2.4.png" alt="docker exec"/>

##### Проверим, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**

<img src="../src/screenshots/2.5.png" alt="status"/>

##### Экспортируем контейнер в файл *container.tar* через команду *export*

<img src="../src/screenshots/2.6.png" alt="docker export"/>

##### Остановим контейнер

<img src="../src/screenshots/2.7.png" alt="docker stop"/>

##### Удалим образ через `docker rmi [repository]`, не удаляя перед этим контейнеры

<img src="../src/screenshots/2.8.png" alt="docker rmi"/>

##### Импортируем контейнер обратно через команду *import*

<img src="../src/screenshots/2.9.png" alt="docker import"/>

##### Запустим импортированный контейнер

<img src="../src/screenshots/2.10.png" alt="docker start"/>