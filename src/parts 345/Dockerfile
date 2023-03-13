FROM nginx:stable
USER root

RUN apt update \
    && apt -y upgrade \
    && apt install -y gcc \
    spawn-fcgi \
    bash \
    libfcgi-dev \
    && rm -rf /var/lib/apt/lists \
    && /etc/init.d/nginx start \
    && chown -R nginx:nginx /var/cache/nginx \
    && chown -R nginx:nginx /var/log/nginx \
    && chown -R nginx:nginx /etc/nginx/conf.d \
    && touch /var/run/nginx.pid \
    && chown -R nginx:nginx /var/run/nginx.pid \
    && chmod u-s usr/bin/chsh \
    && chmod u-s usr/bin/gpasswd \
    && chmod u-s usr/bin/chfn \
    && chmod u-s usr/bin/newgrp \
    && chmod u-s bin/mount \
    && chmod u-s usr/bin/passwd \
    && chmod u-s bin/su \
    && chmod u-s bin/umount \
    && chmod 755 sbin/unix_chkpwd \
    && chmod 755 usr/bin/chage \
    && chmod 755 usr/bin/wall \
    && chmod 755 usr/bin/expiry \
    && usermod -G root nginx

COPY ./server.c ./server.c
COPY ./nginx/nginx.conf /etc/nginx
COPY ./main.sh .

RUN gcc -Wall -Wextra -Werror server.c -lfcgi -o server

USER nginx
HEALTHCHECK --timeout=10s CMD curl --silent --fail localhost:81/status

ENTRYPOINT [ "/main.sh", "chtoto" ]