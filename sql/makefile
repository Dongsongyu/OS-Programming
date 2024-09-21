target = sql
src=$(wildcard *.c ./src/*.c ./tables/*.c)
obj=$(patsubst %.c,%.o,$(src))
include=./include

$(target):$(obj)
	gcc $^ -o $@

%.o:%.c
	gcc $< -c -I $(include) -o $@

.PHONY:clean
clean:
	-rm $(obj) $(target) -f

