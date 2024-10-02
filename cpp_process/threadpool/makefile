target=app
src=$(wildcard *.c ./src/*.c)
obj=$(patsubst %.c,%.o,$(src))
include=./include

$(target):$(obj)
	gcc $^ -o $@

%.o:%.c
	gcc $< -c -I $(include) -o $@ -lpthread

.PHONY:clean

clean:
	-rm $(obj) $(target) -f
